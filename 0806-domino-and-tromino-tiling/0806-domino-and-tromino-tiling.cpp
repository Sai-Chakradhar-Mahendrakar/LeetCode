class Solution {
public:
    int numTilings(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        const int MOD = 1e9 + 7;

        int f[n + 1];
        int g[n + 1];
        f[0] = g[0] = 0;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        for (int i = 3; i <= n; i++) {
            f[i] = ((f[i-1] + f[i-2]) % MOD + 2*g[i-2] % MOD) % MOD;
            g[i] = (g[i-1] + f[i-1]) % MOD;
        }
        return f[n];
    }
};