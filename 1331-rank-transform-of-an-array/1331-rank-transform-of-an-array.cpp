class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(), v.end());

        v.erase(unique(v.begin(), v.end()), v.end());

        map<int, int> mp;
        for (int i = 0; i < v.size(); i++) {
            mp[v[i]] = i + 1;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};