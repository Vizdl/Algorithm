# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

class Solution {
public:
    # define limit 1e-6
    # define aim 24.0
    bool judgePoint24(vector<int>& nums) {
        vector<double> in;
        for (int i : nums){
            in.push_back(i);
        }
        return dfs(in);
    }


    bool dfs (const vector<double>& nums){
        if (nums.size() <= 0) return false;
        if (nums.size() == 1) return abs(nums[0]-aim) < limit;
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                vector<double> in(nums.size() - 1);
                for (int k = 0, idx = 1; k < nums.size(); k++){
                    if (k != i && k != j){
                        in[idx] = nums[k];
                        idx++;
                    }
                }
                in[0] = nums[i] + nums[j];
                if (dfs(in)) return true;
                in[0] = nums[i] * nums[j];
                if (dfs(in)) return true;
                in[0] = nums[i] - nums[j];
                if (dfs(in)) return true;
                in[0] = nums[j] - nums[i];
                if (dfs(in)) return true;
                in[0] = nums[i] / nums[j];
                if (dfs(in)) return true;
                in[0] = nums[j] / nums[i];
                if (dfs(in)) return true;
            }
        }return false;
    }
};



int main (){
    Solution s;
    vector<int> nums = {1,2,3,4};
    s.judgePoint24(nums);
    return 0;
}


