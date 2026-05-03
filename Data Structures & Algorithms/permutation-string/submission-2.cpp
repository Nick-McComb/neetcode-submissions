class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s = s1.size();
        if(s > s2.size()){
            return false;
        }
        
        int left = 0;
        int right = s - 1;
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        int matches = 0;
        for(const auto & c: s1){
            hash1[c-'a']++;
        }
        for(int i = 0; i < s; i++){
            hash2[s2[i]-'a']++;
        }
        for(int i = 0; i < hash1.size(); i++){
            if(hash1[i] == hash2[i]){
                matches++;
            }
        }
        
        for(int right = s; right < s2.size(); right++){
            
            if(matches == 26){
                return true;
            }
            int idx = s2[right] -'a';
            hash2[idx]++;
            if(hash1[idx] == hash2[idx]){
                matches++;
            }
            else if(hash1[idx] == hash2[idx] -1){
                matches--;
            }

            
            idx = s2[left] -'a';
            hash2[idx]--;
            if(hash1[idx] == hash2[idx]){
                matches++;
            }
            else if(hash1[idx] == hash2[idx] +1){
                matches--;
            }

            left++;
            
        }
        return matches == 26;
    }
};
