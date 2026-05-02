class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        unordered_map<char, int> seen{};
        int max_size = 0;
        int right = 0;
        int left = 0;
        while(right < s.size()){
            char c = s[right];
            if(seen.contains(c) && seen[c] >= left){
                left = seen[c] + 1;
                seen[c]  = right;
            }
            else{
                seen[c] = right;
            }
            max_size = max(max_size, right-left +1);
            right++;
        }
        return max_size;
    }
};
