class Solution {
public:
    bool isValid(string s) {
        /*
        Make a set
        loop thru string by char
        check if char is a beginning char, if so add it to set
        if not pop from set and compare the back of the set to the current char
        if the appropriate match continue
        if not return false
        at the end if set is empty return true else false, basically return set.empty()
        */

        stack<char> seen{};
        unordered_map<char, char> dict {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        for(const auto & c : s){
            if(c == '(' || c == '{' || c== '['){
                seen.push(c);
                continue;
            }
            if(seen.empty()){
                return false;
            }
            if(seen.top() != dict[c]){
                return false;
            }
            seen.pop();
        }
        return seen.empty();
    }
};
