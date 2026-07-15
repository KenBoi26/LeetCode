class Solution {
public:

    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int og_color){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;

        if(image[sr][sc] != og_color) return;
        image[sr][sc] = color;

        dfs(image, sr - 1, sc, color, og_color);
        dfs(image, sr + 1, sc, color, og_color);
        dfs(image, sr, sc - 1, color, og_color);
        dfs(image, sr, sc + 1, color, og_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_color = image[sr][sc];

        if(og_color == color) return image;

        dfs(image, sr, sc, color, og_color);

        return image;
    }
};