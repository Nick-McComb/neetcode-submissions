class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0;
        int right = matrix[0].size()-1; //2
        int left = 0;
        int bottom = matrix.size()-1;//2 
        //int mid = (matrix.size() + 2 -1) /2;
        while(left < right){
            int j = 0;
            for(int i= left; i < right; i++){
            //matrix[top][i] //first
                //int j = 0;
                int second = matrix[i][right]; // 1
                matrix[i][right] = matrix[top][i]; //second //(1,2) = (1,1) //sets top left to first
                int third = matrix[bottom][right -j]; // 
                matrix[bottom][right- j] = second; // third //(2,1)
                int forth = matrix[bottom-j][left]; //forth
                matrix[bottom-j][left] = third;
                matrix[top][i] = forth;
                j++;
            }
            left++; // 1
            top++; // 1
            right--; // 2
            bottom--; // 2
        }
    }
};
