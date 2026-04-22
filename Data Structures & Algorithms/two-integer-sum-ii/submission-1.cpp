class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        /*
        get two indexs starting at the front and starting at the back
        make loop that lowkey could loop infinitely 
        check if the the numbers at the two indicies add up to the values

         | |  | |
        [1,2,3,4]
        */

        int start = 0;
        int end = numbers.size()-1;
        //infinite loop (which is kinda bad, but in some optimization scenarios it is fine)
        for(;;){
            int total = numbers[start] + numbers[end];
            if(total == target){
                return std::vector<int> {start+1,end+1};
            }
            if(total < target){
                start++;
            }
            else{
                end--;
            }
        }
    }
};
