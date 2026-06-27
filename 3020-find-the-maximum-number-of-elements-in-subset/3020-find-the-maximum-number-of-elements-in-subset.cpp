class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(int x : nums) mp[x]++;
        int ans = 1;
        if(mp.count(1)) {
            int c = mp[1];
            ans = max(ans, (c % 2 == 0) ? c - 1 : c);
        }
        for(auto &[x, cnt] : mp) {
            if(x == 1) continue;
            long long cur = x;
            int len = 0;
            while(true) {
                if(mp[cur] < 2) {
                    if(mp[cur] >= 1) len++;
                    else len--;
                    break;
                }
                if(cur > 1000000000LL / cur) {
                    len++;
                    break;
                }
                long long nxt = cur * cur;
                if(!mp.count(nxt)) {
                    len++;
                    break;
                }
                len += 2;
                cur = nxt;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};