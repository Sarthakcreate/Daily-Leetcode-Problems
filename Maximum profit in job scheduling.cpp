class Solution {
public:
    int jobScheduling(vector<int>& starttime, vector<int>& endtime, vector<int>& profit) {     
        int n = starttime.size(); 
        vector<pair<int, int>> st(n);
        for(int i = 0; i < n; i++) st[i] = {starttime[i], i};
        sort(st.begin(), st.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i > -1; i--)
            dp[i] += max(dp[i+1], profit[st[i].second] + dp[lower_bound(st.begin() + i, st.end(), make_pair(endtime[st[i].second], 0)) - st.begin()]);
        return dp[0];
    }
};
