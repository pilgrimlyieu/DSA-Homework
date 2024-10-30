#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Leader {
public:
    string name;
    Leader* sub;
    Leader* next;

    Leader(string name) : name(name) {
        sub = nullptr;
        next = nullptr;
    }

    string encodeTree() {
        string middle = "";
        Leader* current = this->sub;
        while (current != nullptr) {
            middle += current->encodeTree();
            current = current->next;
        }
        return "0" + middle + "1";
    }

    void printTree() {
        cout << this->name << endl;
        Leader* current = this->sub;
        while (current != nullptr) {
            current->printTree();
            current = current->next;
        }
    }

    void printLeader() {
        if (this->sub == nullptr) {
            return;
        }
        cout << this->name << ": ";
        Leader* current = this->sub;
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
        current = this->sub;
        while (current != nullptr) {
            current->printLeader();
            current = current->next;
        }
    }
};

void encode() {
    unordered_map<string, Leader*> leaders;
    string line;
    Leader* ceo = nullptr;
    while (getline(cin, line) && !line.empty()) {
        int colon = line.find(':');
        string leaderName = line.substr(0, colon);
        Leader* leader;
        if (leaders.find(leaderName) == leaders.end()) {
            leader = new Leader(leaderName);
            leaders[leaderName] = leader;
            ceo = leader;
        } else {
            leader = leaders[leaderName];
        }
        string subNames = line.substr(colon + 2);
        int start = 0;
        Leader* pastSub = nullptr;
        while (start < subNames.size()) {
            int space = subNames.find(' ', start);
            string subName = subNames.substr(start, space - start);
            Leader* sub = new Leader(subName);
            leaders[subName] = sub;
            if (pastSub == nullptr) {
                leader->sub = sub;
            } else {
                pastSub->next = sub;
            }
            pastSub = sub;
            // 唉，灵感来了快到饭点 7 分钟（从打开 VSCode 11:45 到提交 11:53）就能找到错误；灵感没来，一个晚上都只能磕得头破血流
            // 当然实际上还是不喜欢测试，就是测试也只用题目给的很简单的样例，即使自己编的也不够好
            // 反而是这 7 分钟编了个稍微复杂一点的样例，就一眼发现了输出的异常，从而通过调试定位了错误
            // 错误就是 pastSub 在 else 这里没有更新，因此其实只要多于两个叶子就能看出问题
            // 所以说，还是要多写测试，而且是稍微复杂一点的测试
            if (space == -1) {
                break;
            }
            start = space + 1;
        }
    }
    ceo->printTree();
    cout << ceo->encodeTree() << endl;
}

Leader* decodeTree(vector<string>& names, string& code) {
    stack<Leader*> s;
    Leader* ceo = nullptr;
    int index = 0;
    int nameIndex = 0;
    while (index < code.size()) {
        if (code[index] == '0') {
            Leader* leader = new Leader(names[nameIndex++]);
            if (ceo == nullptr) {
                ceo = leader;
            } else {
                Leader* top = s.top();
                if (top->sub == nullptr) {
                    top->sub = leader;
                } else {
                    Leader* current = top->sub;
                    while (current->next != nullptr) {
                        current = current->next;
                    }
                    current->next = leader;
                }
            }
            s.push(leader);
            index++;
        } else if (code[index] == '1') {
            s.pop();
            index++;
        }
    }
    return ceo;
}

void decode() {
    vector<string> input;
    string line;
    while (getline(cin, line) && !line.empty()) {
        input.push_back(line);
    }
    string code = input[input.size() - 1];
    input.pop_back();
    Leader *ceo = decodeTree(input, code);
    ceo->printLeader();
}

int main() {
    string command;
    getline(cin, command);
    if (command == "ENCODE") {
        encode();
    } else if (command == "DECODE") {
        decode();
    }
    return 0;
}