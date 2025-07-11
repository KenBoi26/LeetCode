#include<bits/stdc++.h>
using namespace std;
#define int long long


class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto i:strs){
            s += to_string(i.size()) + "#" + i;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i=0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);
            strs.push_back(word);

            i = j + 1 + len;
        }

        return strs;
    }
};
