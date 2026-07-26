class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            while (!st.empty() && st.back() > 0 && a < 0 &&
                   st.back() < -a) {
                st.pop_back();
            }

            if (!st.empty() && st.back() > 0 && a < 0) {
                if (st.back() == -a)
                    st.pop_back();
            } else {
                st.push_back(a);
            }
        }

        return st;
    }
};