class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open_count, int closed_count, int n){
        if(current.length() == 2*n){
            result.push_back(current);
            return;
        }

        if(open_count < n){
            backtrack(current+"(", open_count+1, closed_count, n);
        }

        if(closed_count < open_count){
            backtrack(current+")", open_count, closed_count+1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return result;
    }
};