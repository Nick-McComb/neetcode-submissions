class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> row(9), col(9), box(9);
        /*
        [ index = row
            []
            []
            []
            ...
        ]
        
        */
        for(int r = 0; r < 9; r++){
            for(int c = 0; c<9; c++){

                int box_index = (r/3) * 3 + (c/3);
                char str = board[r][c];
                if(str == '.'){
                    continue;
                }

                if(row[r].count(str) || col[c].count(str) || box[box_index].count(str) ){
                    return false;
                }

                row[r].insert(str);
                col[c].insert(str);
                box[box_index].insert(str);
            }
        }
        return true;
    }
};

    /* 
    /*
    compartmentalize problem
    seperate into: 
    valid rows check
    valid colum check
    valid sub box check
    

    bool hasValidRows(vector<vector<char>>& board){
        /*
        loop thru the 2x2 array
        loop thru the first row
        check if the str value is a '.' if it is skip
        if not check if its in the dictionary
        if it is return false
        else add it and continue
        do this for every row
        is there a better way? idk I think we need to loop thru the 2x2 as for the check, possibly
        
        for(const auto & row: board){
            std::unordered_set<char> row_validator{};
            for(const auto & str : row){
                if(str == '.'){
                    continue;
                }
                if(row_validator.count(str)){
                    return false;
                }
                row_validator.insert(str);
            }
        }
        return true;
    }

    bool hasValidColumns(vector<vector<char>>& board){
        /*
        loop via index via the length of the first element in the list ( this will loop the columns)
        loop via index via the length of the list -1 (this will loop thru the specific column)
        same as valid row from here
        

        //assuming the board has something [0], might need to fix this
        for(int column=0; column < board[0].size(); column++){
            std::unordered_set<char> column_validator{};
            for(int row=0; row < board.size(); row++){
                char str = board[row][column];
                if(str == '.'){
                    continue;
                }
                if(column_validator.count(str)){
                    return false;
                }
                column_validator.insert(str);
            }
        }
        return true;
    }

    bool hasValidSubBox(vector<vector<char>>& board){
        
        for(int c = 0; c < board[0].size(); c+= 3){
            for(int r = 0; r < board.size(); r+=3){
                if (!isValidThree(board, c, r)){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidThree(vector<vector<char>>& board, int startc, int startr){

        std::unordered_set<char> sub_validator{};
        for(int c = startc; c < startc + 3; c++){
            for(int r = startr; r < startr+3; r++){
                char str = board[r][c];
                if(str == '.'){
                    continue;
                }
                if(sub_validator.count(str)){
                    return false;
                }
                sub_validator.insert(str);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return hasValidRows(board) && hasValidColumns(board) && hasValidSubBox(board);
    }
*/
    
