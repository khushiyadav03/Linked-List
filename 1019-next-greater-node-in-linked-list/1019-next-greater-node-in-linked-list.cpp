class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        vector<int> ans;

        // convert linked list to array
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        ans.assign(n, 0);   // default answer is 0
        stack<int> st;      // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
