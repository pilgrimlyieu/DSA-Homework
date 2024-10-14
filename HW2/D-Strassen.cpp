#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    static const int SIZE_TO_MUTLIPLY = 32;
    int n;
    vector<vector<int>> data;
    Matrix simple_multiply(const Matrix& other) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
public:
    Matrix(int n) : n(n), data(n, vector<int>(n)) {}
    void input() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
        }
    }
    void output() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << data[i][j] << ' ';
            }
            cout << endl;
        }
    }
    Matrix operator+(const Matrix& other) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) {
        if (n <= SIZE_TO_MUTLIPLY) {
            return simple_multiply(other);
        }
        int hn = n / 2;
        Matrix A(hn), B(hn), C(hn), D(hn), E(hn), F(hn), G(hn), H(hn);
        for (int i = 0; i < hn; i++) {
            for (int j = 0; j < hn; j++) {
                A.data[i][j] = data[i][j];
                B.data[i][j] = data[i][j + hn];
                C.data[i][j] = data[i + hn][j];
                D.data[i][j] = data[i + hn][j + hn];
                E.data[i][j] = other.data[i][j];
                F.data[i][j] = other.data[i][j + hn];
                G.data[i][j] = other.data[i + hn][j];
                H.data[i][j] = other.data[i + hn][j + hn];
            }
        }
        Matrix P1(hn), P2(hn), P3(hn), P4(hn), P5(hn), P6(hn), P7(hn);
        P1 = A * (F - H);
        P2 = (A + B) * H;
        P3 = (C + D) * E;
        P4 = D * (G - E);
        P5 = (A + D) * (E + H);
        P6 = (B - D) * (G + H);
        P7 = (A - C) * (E + F);
        Matrix result(n);
        for (int i = 0; i < hn; i++) {
            for (int j = 0; j < hn; j++) {
                result.data[i][j] = P5.data[i][j] + P4.data[i][j] - P2.data[i][j] + P6.data[i][j];
                result.data[i][j + hn] = P1.data[i][j] + P2.data[i][j];
                result.data[i + hn][j] = P3.data[i][j] + P4.data[i][j];
                result.data[i + hn][j + hn] = P1.data[i][j] + P5.data[i][j] - P3.data[i][j] - P7.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int N;
    cin >> N;
    Matrix A(N), B(N), C(N);
    A.input();
    B.input();
    C = A * B;
    C.output();
    return 0;
}