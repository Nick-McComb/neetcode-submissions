class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> items{};
        vector<pair<int, int>> ps{}; //{pos,speed}
        
        for(int i = 0; i< position.size(); i++){
            ps.push_back(pair<int,int>{position[i], speed[i]});
        }
        std::sort(ps.begin(),ps.end(), [](pair<int,int> a, pair<int,int> b){ return a.first > b.first;});

        for(int i = 0; i < ps.size(); i++){
            double elm = static_cast<double>(target-ps[i].first)/static_cast<double>(ps[i].second);
            cout<<elm<<endl;
            if(items.empty()){
                items.push(elm);
                continue;
            }
            double prev = items.top();
            items.push(elm);
            if(elm <= prev) {
                items.pop();
            }
        }
        return items.size();
    }
};
