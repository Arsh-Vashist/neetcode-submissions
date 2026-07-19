class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater = 0;
        int l=0, r=heights.size()-1;

        while(l<r){
            int width = r - l;
            int ht = min(heights[l], heights[r]);
            int currwater = width * ht;

            maxwater = max(currwater, maxwater);

            heights[l] < heights[r] ? l++: r--;
        }
        return maxwater;
    }
};
