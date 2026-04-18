class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        loop thru the list
        create a key using a list of 26, 0's then store the string in a map with that key
        then loop thru the map and push_back into a new vec and return
        O(n+m)
        */

        std::unordered_map<std::string, std::vector<std::string>> lib{};
        for(const auto & str: strs){
            std::vector count(26,0);
            for(const auto & s: str){
                count[s - 'a']++;
            }
            std::string key;
            for(const auto & c: count){
                key += "#"+ std::to_string(c);
            }

            if(lib.contains(key)){
                lib[key].push_back(str);
            }
            else{
                lib[key] = std::vector<std::string>{str};
            }
        }
        std::vector<std::vector<std::string>> group{};
        for(const auto & [_, value] : lib){
            group.push_back(value);
        }
        return group;


        /*
        possibly
        loop thru the list
        make a copy of each string
        sort it 
        store it in a map : [copy]
        then loop thru the map and store it into vector
        pitfalls lots of storing
        O(n+mlog(m))

        */
        // std::unordered_map<std::string, std::vector<std::string>> lib{};
        // for(const auto & str: strs){
        //     std::string copy = str;
        //     sort(copy.begin(), copy.end());
        //     if(lib.contains(copy)){
        //         lib[copy].push_back(str);
        //     }
        //     else{
        //         lib[copy] = std::vector<std::string>{str};
        //     }
        // }
        // std::vector<std::vector<std::string>> groups{};
        // for(const auto & [key, value]: lib){
        //     groups.push_back(value);
        // }
        // return groups;

        /*
        possibly
        loop thru the list
        create a holder list of index's
        get the first string and add its index to the list
        anagram compare first string to all other strings of same length (nested loops + anagram compare) 
        if they match store index in index holder 
        after inner loop now remove those indexes from the list and add that index element to the new list of lists
        do this by switching with back element (strs.size()) and pop_backing
        then continue first loop till strs is empty
        */

        //needless to say implementation was too complex 

        /*
        int i = 0;
        std::vector<std::vector<std::string>> groups{};
        while(!strs.empty()){
            std::vector<int> index{};
            index.push_back(i);
            std::string first = strs[i];
            for(int j = i+1; j < strs.size(); j++){
                std::string second = strs[j];
                if(first.size() != second.size()){
                    continue; // obv not a anagram
                }
                std::vector<int> alp{26,0};
                for(int k = 0; k < first.size(); k++){
                    alp[first[k] - 'a'] ++;
                    alp[second[k] - 'a'] --;
                }
                index.push_back(j);
                for(const int & c : alp){
                    if(c != 0){
                        index.pop_back();
                        break;
                    }
                }
            }
            // while still indexes pop the index by swapping the values to the back of strs
            // then store that value in new vector in vector of vectors
            std::vector<std::string> na {};
            while(!index.empty()){
                
                std::swap(strs.back(), strs[index.back()]);
                std::string ana = strs[-1];
                strs.pop_back();
                na.push_back(ana);
            }
            groups.push_back(na);
        }
        return groups; 
        */
    }
};
