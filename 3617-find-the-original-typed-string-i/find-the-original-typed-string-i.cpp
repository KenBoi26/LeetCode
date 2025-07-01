class Solution {
public:
    int possibleStringCount(std::string word) {
        int n = word.length();
        if (n == 0) {
            return 0; 
        }
        int count = 1; 
        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int j = i; 

            
            while (j < n && word[j] == currentChar) {
                j++;
            }
            
            
            int blockLength = j - i; 

            if (blockLength > 1) {
                count += (blockLength - 1);
            }
            
            i = j; 
        }

        return count;
    }
};