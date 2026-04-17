class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case, no need to sort if lengths are different return false

        // is there a way to sort the string in alphabetical? 
        // is there a way to sort the string by ascii? 
        // sort by ascii then compare and return the compasion
        // O(nlog(n))
        if(s.size() != t.size()){
            return false;
        }

        /* sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;  
        */ 

        //similarly storing a list of 26 0's then incrementing and decrementing them depending on which appears.

        std::vector<int>count (26, 0);
        for(int i =0; i < s.size(); i++){
            count[s[i] - 'a'] ++;
            count[t[i] - 'a'] --;
        }

        for(const int & c: count){
            if(c != 0){
                return false;
            }
        }
        return true;
    }

};
