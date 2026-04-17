class Solution {
public:
    bool hasDuplicate(const std::vector<int> & nums){
        if(nums.size() < 2){
            return false;
        }

        std::unordered_map<int, int> seen{};

        for(const auto & n : nums){
            if(seen.contains(n)){
                return true;
            }
            seen[n] = 1;
        }
        return false;
    }
};