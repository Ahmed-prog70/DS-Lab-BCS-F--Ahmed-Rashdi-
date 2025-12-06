#include <iostream>
#include <string>
using namespace std;
void computeLPS(string pattern, int lps[]) {
    int m = pattern.length();
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    computeLPS(pattern, lps);
    cout << "LPS Array: [";
    for (int i = 0; i < m; i++) {
        cout << lps[i];
        if (i != m - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Matches at indices: [";
    bool first = true;
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            if (!first) cout << ", ";
            cout << (i - j);
            first = false;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    cout << "]" << endl;
}
int main() {
    string text = "ababababc";
    string pattern = "abab";
    KMPSearch(text, pattern);
    return 0;
}
