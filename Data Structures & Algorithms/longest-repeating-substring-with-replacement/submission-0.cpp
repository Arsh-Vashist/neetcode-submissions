class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int res = 0;

        int l=0, maxf=0;

        for(int r=0; r<s.size(); r++){
            m[s[r]]++;
            maxf = max(maxf, m[s[r]]);

            while((r-l+1)-maxf > k){
                m[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
