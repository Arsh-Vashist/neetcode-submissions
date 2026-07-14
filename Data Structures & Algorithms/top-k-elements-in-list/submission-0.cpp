class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);

        for(auto [num,count] : m){
            bucket[count].push_back(num);
        }

        for(int i=n; i>=0 && ans.size()<k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};
