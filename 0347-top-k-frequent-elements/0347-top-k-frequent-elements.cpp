class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:mp)
        {
            int n = it.first;
            int freq = it.second;
            // cout<<n<<" "<<freq<<endl;
            pq.push({freq,n});
        }
        vector<int> ans;
        while(k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};