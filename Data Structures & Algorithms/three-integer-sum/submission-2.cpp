class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // [-4,-1,-1,0,1,2]

        /*
        check if the length is below 3, if so return empty
        loop thru the list from first element till 2nd to last element

        */

        if(nums.size() < 3){
            return vector<vector<int>>{};
        }
        vector<vector<int>> res{};
        for(int i = 0; i < nums.size() -2; i++){
            if (nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int total = nums[i] + nums[j] + nums[k];
                if(total == 0){
                    res.push_back(vector<int>{nums[i] , nums[j] , nums[k]});
                    while(total == 0 && j<k){
                        total -= nums[j];
                        j++;
                        total += nums[j]; 
                    }
                    continue;
                }
                else if(total > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};
