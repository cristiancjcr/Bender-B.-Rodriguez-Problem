#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Function to check if there's a change in direction
bool change(char cur, char c1, char c2) {
    if (cur == 'x' && c1 == '-') return true;
    if (cur == 'y' && c2 == 'y' && c1 == '+') return true;
    if (cur == 'z' && c2 == 'z' && c1 == '+') return true;
    return false;
}

int main() {
    int L;
    char s[3];

    while (true) {
        cin >> L;  // Read the number of steps
        if (L == 0) break;  // Exit if no more steps

        --L;  // Decrement steps since we're starting from 0
        int sign = 1;  // Initialize the sign
        char c = 'x';  // Initialize the current direction

        for (int i = 0; i < L; ++i) {
            cin >> s;  // Read the direction change
            if (s[0] == 'N') continue;  // Skip if no change

            // Check for direction change and update sign and direction
            if (change(c, s[0], s[1])) sign = -sign;
            if (c == 'x') c = s[1];
            else if (c == 'y' && s[1] == 'y') c = 'x';
            else if (c == 'z' && s[1] == 'z') c = 'x';
        }

        // Output the final direction and sign
        cout << (sign == 1 ? '+' : '-') << c << endl;
    }

    return 0;
}
