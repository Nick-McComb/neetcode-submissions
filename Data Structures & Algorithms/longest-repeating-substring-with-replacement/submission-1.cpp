class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> count(26,0);
        int left = 0;
        int right = 0;
        int mx = 0;
        pair<char, int> mfw{'A', 0};
        while(right < s.size()){ //s="AABABBA" //k=1
            count[s[right] - 'A']++; // {A: 2 , B:2}
            if(count[s[right]- 'A'] > mfw.second){
                mfw = {s[right], count[s[right]- 'A']};
            }
            int size = right - left + 1; // 4
            while(k < (size - mfw.second)){ //  1 >= 2
                count[s[left]- 'A']--;
                left++;
                //mfw--;
                size--;
            }
            mx = max(mx, size); 
            right++;  
        }
        return mx;
    }
};
