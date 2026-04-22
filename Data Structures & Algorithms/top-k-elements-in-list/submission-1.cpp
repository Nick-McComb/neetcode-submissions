class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        bucket sort
        create a map
        loop thru each element of nums
        keep a running count of each num in map

        make a vec of vec ints that is of size nums.size() + 1
        this will place each num in a bucket depending on the count
        the max the count could possibly be is nums.size(),
        but the bucket holder needs to be one larger because it's index based
        then loop thru the map and place each key in its appropriate bucket, indexing bucket holder based off count
        then loop thru the bucket holder starting at the back 
        nested loop looping thru the actual bucket
        add each element to a new vector 
        check if the size() of new vec is equal to k
        then return new vec if so
        then at the end returm new vec
        */
        //[7,7]
        std::unordered_map<int, int> count {};
        for(const auto & num: nums){
            count[num]++; //7 : 2
        }
        // index based, need one extra bucket incase every element the same
        std::vector<std::vector<int>> bucket_holder(nums.size() + 1); 
        for(const auto & [key, value] : count){
            bucket_holder[value].push_back(key);
        }

        std::vector<int> solution{};
        for(int i = bucket_holder.size() - 1; i >= 0; i--){
            for(const auto & v : bucket_holder[i]){
                solution.push_back(v);
                if(solution.size() == k){
                    return solution;
                }
            }
        }
        return solution;
        /*
        create a map
        loop thru the entire list
        keep a running count in of each num in the map
        if its possible to get the max value from the values from the values side of the dicitonary
        
        get the max 
        loop thru while k != 0
        del the max from dic
        add the max elemnt to a vector
        k --
        get new max
        */


        /*
        std::unordered_map<int, int> count{};
        for(const auto & num : nums){
            count[num]++;
        }

        std::vector<int> ans{};

        while(k > 0){
            int max = 0;
            int most_freq;
            for(const auto & [key, value] : count){
                if(value > max){ 
                    max = value;
                    most_freq = key;
                }
            }
            ans.push_back(most_freq);
            count.erase(most_freq);
            k--;
        }
        return ans;
        */
    }
};
