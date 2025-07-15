class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag = false;
        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord);

        for(auto i:wordList){
            if(i == endWord) flag = true;
            for(int j=0; j<i.length(); j++){
                string pattern = i.substr(0,j) + "*" + i.substr(j+1);
                mp[pattern].push_back(i);
            }
        }

        if(!flag){
            return 0;
        }

        set<string> s;
        deque<string> dq;
        int res = 1;

        s.insert(beginWord);
        dq.push_back(beginWord);
        string word = "";
        while(!dq.empty()){
            int n = dq.size();
            for(int i=0; i<n; i++){
                word = dq.front();
                dq.pop_front();
                if(word == endWord){
                    return res;
                }

                for(int j=0; j<word.length(); j++){
                    string pattern = word.substr(0,j) + "*" + word.substr(j+1);
                    for(auto k : mp[pattern]){
                        if(s.find(k) == s.end()){
                            dq.push_back(k);
                            s.insert(k);
                        }
                    }
                }
            }

            res += 1;
        }

        return 0;
    }
};