class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //int i = digits.size()-1;
        //vector<int> s{};
        for(int i = digits.size()-1; i>=0; i--){
            int val = (digits[i] + 1) % 10;
            digits[i] = val;
            if(val){
                //digits[i] = val;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
