class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        two iterations thru 

        iteration 1:
        first make a copy vec
        loop thru size of vec
        set the new vec index equal to the multiple of the before elements in nums
        do this by keeping a running count k 

        iteration 2:
        loop from size down to 0 (loop backwards)
        multiply the new vecs current index, starting from back, by the multiple of all elements after
        do this by keepig a running count k
        return new vec
        */
        int k = 1;
        vector<int> sums(nums.size());
        for(int i = 0; i < nums.size(); i++){
            sums[i] = k;
            k *= nums[i];
        }

        k = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            sums[i] *= k;
            k *= nums[i];
        }
        return sums;
    }
};
