import java.util.*;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new ArrayList<>();
        solve(s, 0, 0, '(', ')', ans);
        return ans;
    }

    void solve(String s, int last_i, int last_j, char open, char close,
               List<String> ans) {

        int balance = 0;

        for (int i = last_i; i < s.length(); i++) {
            if (s.charAt(i) == open)
                balance++;
            else if (s.charAt(i) == close)
                balance--;

            if (balance < 0) {
                for (int j = last_j; j <= i; j++) {
                    if (s.charAt(j) == close &&
                        (j == last_j || s.charAt(j - 1) != close)) {

                        solve(
                            s.substring(0, j) + s.substring(j + 1),
                            i,
                            j,
                            open,
                            close,
                            ans
                        );
                    }
                }
                return;
            }
        }

        String reversed = new StringBuilder(s).reverse().toString();

        if (open == '(') {
            solve(reversed, 0, 0, ')', '(', ans);
        } else {
            ans.add(reversed);
        }
    }
}