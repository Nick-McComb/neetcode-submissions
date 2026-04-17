class Solution {
public:
    bool isAnagram(string s, string t) {
        // is there a way to sort the string in alphabetical? 
        // is there a way to sort the string by ascii? 
        // sort by ascii then compare and return the compasion
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};
