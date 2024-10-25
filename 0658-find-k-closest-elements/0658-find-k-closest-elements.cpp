struct Compare {
    bool operator()(const tuple<int, int>& a, const tuple<int, int>& b) {
        if (get<1>(a) != get<1>(b) ) {
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) > get<0>(b);
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<tuple<int, int>> diff_arr;
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare> minHeap;

    // Populate the diff_arr and minHeap
        for (int i = 0; i < arr.size(); i++) {
            auto element = make_tuple(arr[i], abs(arr[i] - x));
            diff_arr.push_back(element);
            minHeap.push(element);
        }
        
        vector<int> result;
        
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare> mh_c = minHeap;
        
        for(int i=0;i<k;i++)
        {
            auto a = get<0>(minHeap.top());
            minHeap.pop();
            result.push_back(a);
        }
        
//         while(!mh_c.empty())
//         {
//             cout<<get<0>(mh_c.top())<<" "<<get<1>(mh_c.top())<<endl;
//             mh_c.pop();
//         }
        
        sort(result.begin(),result.end());
        return result;
    }
};