class Solution {
public:
    int search(vector<int>& nums, int target) {
        

        int left = 0;
        int right = nums.size()-1;
        //int middle = (right + left) / 2;
        while(left <= right){
            //Input: nums = [-1,0,2,4,6,8], target = 3
            //left = , right = 
            //middle = 
            int middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] < target){
                left = middle + 1;
            }
            else{
                right = middle -1;
            }
        }
        return -1;
    }
};
