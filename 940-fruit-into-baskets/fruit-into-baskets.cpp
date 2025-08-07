class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int start = 0;
        int max_count = 0;

        for(int end = 0; end < fruits.size(); end++){
            mp[fruits[end]]++;
            while (mp.size() > 2) {
                mp[fruits[start]]--;
                if (mp[fruits[start]] == 0)
                    mp.erase(fruits[start]);
                start++;
            }

            max_count = max(max_count, end-start+1);
        }

        return max_count;
    }
};