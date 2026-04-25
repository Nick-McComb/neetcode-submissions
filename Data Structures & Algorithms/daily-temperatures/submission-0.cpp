class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        loop starting at the back
        keep adding to min stack until element is larger
        if element is larger pop until top is larger
        every pop store at the current index - correspond index 
        element = 38 > 30
        index = 1
        [30,38,30,36,35,40,28] 
        [0 ,0 ,0 ,0 ,0 ,0 ,0 ]
        [(30, 0), ]
        if less than take top + 1
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
