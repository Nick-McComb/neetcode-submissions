class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a unordered map
        // loop through the list by index
        // check if target - current int is in the map
        // if it is then return map[target-current] and current index
        // if not store the current in the map at its corresponding index

        std::unordered_map<int, int> seen{};

        for(int i=0; i < nums.size(); i++ ){
            int value = nums[i];
            int difference = target - value;
            if(seen.contains(difference)){
                return std::vector<int> {seen[difference], i};
            }
            seen[value] = i;
        }
    }
};
