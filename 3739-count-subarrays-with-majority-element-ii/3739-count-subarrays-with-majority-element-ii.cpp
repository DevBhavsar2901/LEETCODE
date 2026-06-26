class Solution {
public:
    struct BIT {
        int n;
        vector<int> bit;
        BIT(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }
        void add(int idx, int val) {
            while(idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }
        int sum(int idx) {
            int res = 0;
            while(idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int off = n + 2;
        BIT ft(2 * n + 5);
        long long ans = 0;
        int pre = 0;
        ft.add(off, 1);
        for(int x : nums) {
            if (x == target) pre++;
            else pre--;
            ans += ft.sum(pre + off - 1); 
            ft.add(pre + off, 1);
        }
        return ans;
    }
};