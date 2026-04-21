class Solution {
public:

    bool isPalindrome(string s) {
        /*
        get the length of the string -1 called end
        create a int = 0 called start
        while (start < end)
        check if they equal, if they dont return false
        end return true
        */
        int right = s.size()-1;
        int left = 0;
        while(left < right){
            
            while(left < right && !std::isalnum(s[left])){
                left++;
            }
            while(left < right && !std::isalnum(s[right])){
                right--;
            }
            
            if(std::tolower(s[left]) != std::tolower(s[right])){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
