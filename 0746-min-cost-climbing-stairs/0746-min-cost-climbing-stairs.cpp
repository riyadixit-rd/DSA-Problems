#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int first = cost[0];
        int second = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            int current = cost[i] + std::min(first, second);
            first = second;
            second = current;
        }
        
        return std::min(first, second);
    }
};