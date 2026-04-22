class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
            make two pointers, one to the beginning of list and one to the end
            get the min of the two pointers and multiple that by the difference between the index
            set a new max area if larger than last
            update the point that is small ( i think )
        */

        int start = 0;
        int end= heights.size() -1;
        int max_area = 0;
        while(start < end){
            int height = min(heights[start], heights[end]);
            int width = end - start;
            int area = height * width;
            if(area > max_area){
                max_area = area;
            }
            if(heights[start] > heights[end]){
                end--;
            }
            else{
                start++;
            }
        }
        return max_area;
    }
};
