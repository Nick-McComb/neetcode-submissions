class KthLargest {
public:
    int kth;
    vector<int> s;

    KthLargest(int k, vector<int>& nums) : kth(k), s(nums) {
        
    }
    
    int add(int val) {
        s.push_back(val);
        sort(s.begin(), s.end());
        return s[s.size()-kth];
    }
};
