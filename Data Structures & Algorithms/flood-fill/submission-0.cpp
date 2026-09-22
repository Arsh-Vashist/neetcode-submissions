class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor, int orgcolor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != orgcolor || image[i][j] == newcolor){
            return;
        }
        image[i][j] = newcolor;

        dfs(image, i-1, j, newcolor, orgcolor); //top
        dfs(image, i+1, j, newcolor, orgcolor); //bottom
        dfs(image, i, j+1, newcolor, orgcolor); //right
        dfs(image, i, j-1, newcolor, orgcolor); //left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};