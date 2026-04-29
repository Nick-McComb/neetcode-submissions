class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        /*
            becuase nums is between [1,n] we know the max value we see is n
            so if we loop thru the list
            and do n-1, this is a valid index associated with the number we just saw
            we can then check if the value at this index (abs(num) -1) is below zero (negative)
            if not set it to negative
            if it is return the absolute value of the number
            
        */
        //nums=[3,-2,-5,14,5,5,19,18,11,10,1,4,5,5,5,5,12,5,17,5]
        for (int num : nums) {
            int idx = abs(num) - 1; //2, 1
            if (nums[idx] < 0) { // 5<0 nope, 2<0 nope
                return abs(num);
            }
            nums[idx] *= -1; 
        }
        return -1;
        }
    };
