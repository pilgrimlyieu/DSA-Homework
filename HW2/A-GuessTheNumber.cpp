#include <iostream>

using namespace std;

int main() {
    unsigned long long last_low_guess = 0, last_high_guess = 18446744073709551615u, guess;
    string result;
    while (true) {
        guess = last_low_guess + (last_high_guess - last_low_guess) / 2;
        cout << guess << endl;
        cin >> result;
        if (result == "TooBig") {
            last_high_guess = guess - 1;
        } else if (result == "TooSmall") {
            last_low_guess = guess + 1;
        } else {
            return 0;
        }
    }
}