class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        int count = 0, bcount = 0;
        for(char c : s){
            if(c == 'b'){
                st.push(c);
                bcount++;
            } else {
                // c == a
                if(!st.empty() && st.top() == 'b'){
                    // violation: b before a
                    count = min(count+1, bcount);
                } else {
                    st.push(c);
                }
            }
        }
        return count;
    }
};