## Paint Houses 1
There are N houses, each can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no 2 adjacent houses have the same colors
Note: All the costs are > 0

**Approach**



**CODE**
```cpp
class Solution{
    public:
    int minCost2(vector<vector<int>>& costs){
        int m = costs.size();
        int n = costs[0].size();
        for(int i=1 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int prevMinCost = INT_MAX;
                for(int k=0 ; k<n ; k++){
                    if(k!=j){
                        prevMinCost = min(prevMinCost, costs[i-1][k]);

                    }
                    costs[i][j] += prevMinCost;
                }
            }
            return *min_element(costs.back().begin() , costs.back().end());
        }
    }
};
```
