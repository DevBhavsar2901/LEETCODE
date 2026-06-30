class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> f(3, 0);
        int l = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            f[s[i]-'a']++;
            while(f[0] && f[1] && f[2]) {
                ans += (n - i);
                f[s[l] - 'a']--;
                l++;
            }
        }
        return ans;
    }
};