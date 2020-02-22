class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int cnt[tree.size()];
        memset(cnt, 0, sizeof(cnt));
        
        set<int> st;
        st.clear();
        
        int i, j;
        i = 0; j = 0;
        
        int ans = 0;
        
        for (i = 0 ; i < tree.size() ; i ++) {
            cnt[tree[i]] ++;
            if (cnt[tree[i]] == 1) {
                st.insert(tree[i]);
                if (st.size() > 2) {
                    while (st.size() > 2 && j <= i) {
                        cnt[tree[j]] --;
                        if (cnt[tree[j]] == 0) {
                            st.erase(tree[j]);
                        }
                        j ++;
                    }
                }
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};
