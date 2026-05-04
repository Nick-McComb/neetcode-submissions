class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0; // 3
        int right = matrix[0].size(); //3 
        int top = 0;
        int bottom = matrix.size();
        //cout<<bottom<<endl;
        vector<int> s{};
        int c = 0;
        int r = 0;
        while(left < right && top < bottom){
            for(c; c < right; c++){
                s.push_back(matrix[r][c]);
            }
            c--;
            r++;
            top++;
            for(r; r< bottom; r++){
                s.push_back(matrix[r][c]);
            }
            r--;
            c--;
            right--;
            if(!(left < right && top < bottom)) {
                break;
            }
            for(c; c>=left; c--){
                s.push_back(matrix[r][c]);
            }
            c++;
            r--;
            bottom--;
            //cout<<c<<r<<top<<endl;
            for(r; r>= top; r--){
                s.push_back(matrix[r][c]);
            }
            c++;
            r++;
            left++;
    }
    return s;
    }
};
