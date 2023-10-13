class Solution {
public:
    vector<int> cost;
    unordered_map<int,int> memo;

    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        return minCost(cost.size());
    }

    int minCost(int i) {
        if (i <= 1) return 0;
        if (this->memo.contains(i)) return this->memo[i];

        int first = this->cost[i - 1] + minCost(i - 1);
        int second = this->cost[i - 2] + minCost(i - 2);

        return this->memo[i] = min(first, second);
    }
};