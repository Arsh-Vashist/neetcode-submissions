class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        vector<int> freqs(256, 0);
        vector<int> freqt(256, 0);

        for(unsigned char xs : s){
            freqs[xs]++;
        }
        for(unsigned char xt : t){
            freqt[xt]++;
        }

        if(freqs != freqt){
            return false;
        }else{
            return true;
        }
    }
};
