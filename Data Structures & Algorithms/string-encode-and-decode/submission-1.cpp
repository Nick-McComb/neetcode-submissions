class Solution {
public:

    /*
    encode
    input = ["hello", "world"]
    create empty string str = ""
    loop thru the list
    add str + #len#curr

    decode
    input = #5#hello#5#world
    
    make a solution vec
    while loop thru the string
    make j = index
    while the char at the current index doesn't equal '#' add to j
    then substr(i, j-i) and convert that to an int and set it to length
    then make i = j + 1
    and subsctring from i for size length
    then set i = i + length
    */

    string encode(vector<string>& strs) {
        std::string solution;
        for(const auto & s : strs){
            solution += std::to_string(s.size()) + "#" + s;
        }
        cout<<solution<<endl;
        return solution;
    }

    vector<string> decode(string s) {
        std::vector<string> solution;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = std::stoi(s.substr(i, j-i));
            i = j + 1;
            solution.push_back(s.substr(i, length));
            i += length;
        }
        return solution;
    }
};
