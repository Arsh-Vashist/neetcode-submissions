class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> car(n);

        for(int i=0; i<n; i++){
            car[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        sort(car.begin(), car.end());

        stack<double> st;
        for(int i=n-1; i>=0; i--){
            if(st.empty() || st.top() < car[i].second){
                st.push(car[i].second);
            }
        }
        return st.size();
    }
};
