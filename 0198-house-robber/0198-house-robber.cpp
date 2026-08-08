#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int prev2 = 0; // Max money robbed up to 2 houses back
        int prev1 = 0; // Max money robbed up to 1 house back

        for (int num : nums) {
            // Choice: Skip this house (prev1) OR Rob this house (prev2 + num)
            int current = std::max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
      }
};