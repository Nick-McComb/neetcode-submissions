class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*
        set the first value to be val2
        create a val2 variable uninitalized
        loop thru the list and check if the value is either '+', '-', '*', and '/'
        realistically the first value should be the second int cause we're looping thru starting at the second
        so set second value to the first value if it is not a operator
        if it is a operator do that operator, switch statement of val2 and val2 and store that into val2
        continue till end 
        return val2
        */

        stack<int> cube{};

        for(const auto & c: tokens){
            
            if(c == "+"){
                int val1 = cube.top();
                cube.pop();
                int val2 = cube.top();
                cube.pop();
                cube.push(val2+val1);
            }
            else if(c == "-"){
                int val1 = cube.top();
                cube.pop();
                int val2 = cube.top();
                cube.pop();
                cube.push(val2-val1);
            }
            else if(c == "*"){
                int val1 = cube.top();
                cube.pop();
                int val2 = cube.top();
                cube.pop();
                cube.push(val2*val1);
            }
            else if(c == "/"){
                int val1 = cube.top();
                cube.pop();
                int val2 = cube.top();
                cube.pop();
                cube.push(val2/val1);
            }
            else{
                cube.push(stoi(c));
            }
        }
        return cube.top();
    }
             
};
