class Solution {
public:
    int minimumDeletions(string s) {
        int count = 0, bcount = 0;
        for(char c : s){
            if(c == 'b'){
                bcount++;
            } else {
                // c== 'a'
                // either delete this 'a' or delete all previous 'b's
                count = min(count+1, bcount);
            }
        }
        return count;
    }
};