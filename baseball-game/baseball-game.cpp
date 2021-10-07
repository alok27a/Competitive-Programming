class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for(auto c:ops){
            if(c == "+")
                record.push_back(record.back() + record[record.size()-2]);
            else if(c == "D")
                record.push_back(2*record.back());
            else if(c == "C")
                record.pop_back();
            else{
                record.push_back(stoi(c));
            }
        }
        return accumulate(record.begin(),record.end(),0);
    }
};