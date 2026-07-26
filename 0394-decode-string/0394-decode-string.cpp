class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> st;
        string cur = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '[') {
                cnt.push(num);
                st.push(cur);
                num = 0;
                cur = "";
            } 
            else if (c == ']') {
                string temp = cur;
                cur = st.top();
                st.pop();

                int k = cnt.top();
                cnt.pop();

                while (k--)
                    cur += temp;
            } 
            else {
                cur += c;
            }
        }

        return cur;
    }
};