class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        loop starting at the front
        keep a stack of value and index pairs
        add the current val / index pair to the stack if 
        stack is empty or if the top of the stack is > the current value
        while the stack is not empty and the top of the stack is < the current value
        get the top element and index into output and += output + current_index - val_index
        then .pop the stack to remove the top and keep doing this until you find a bigger value or empty stack
        then push the current element into the stack with its index
        return output
        element = 38 > 30
        index = 1
        [30,38,30,36,35,40,28] 
        [0 ,0 ,0 ,0 ,0 ,0 ,0 ]
        [(30, 0), ]
        
        */

        stack<pair<int, int>> running{};
        vector<int> output(temperatures.size(), 0);
        

        for(int i =0; i < temperatures.size(); i++){
            int val = temperatures[i];
            if(running.empty() || running.top().first > val){
                running.push(std::pair(val, i));
                continue;
            }
        
            while(!running.empty() && running.top().first < val){
                output[running.top().second] += i - running.top().second;
                running.pop();
            }
            running.push(std::pair(val, i));
        }

        return output;
    }
};
