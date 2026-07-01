class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st_s;
        stack<char> st_t;

        for(auto i:s){
            if(i == '#' && !st_s.empty()) st_s.pop();
            else if(i == '#' && st_s.empty()) continue;
            else st_s.push(i);
        }

        for(auto i:t){
            if(i == '#' && !st_t.empty()) st_t.pop();
            else if(i == '#' && st_t.empty()) continue;
            else st_t.push(i);
        }

        return st_s == st_t;
    }
};