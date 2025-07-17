class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = -1;
        int l = 0;
        int r = height.size()-1;

        while(l<r){
            int current_area = (r-l) * min(height[l], height[r]);
            max_area = max(max_area, current_area);

            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }

        return max_area;
    }
};