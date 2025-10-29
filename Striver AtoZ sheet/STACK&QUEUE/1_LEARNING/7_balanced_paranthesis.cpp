#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {   // ✅ use int here
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    string input;
    cout << "Enter a string in brackets: ";
    cin >> input;   // ✅ waits for input if run from terminal / Ctrl+F5

    if (sol.isValid(input)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
