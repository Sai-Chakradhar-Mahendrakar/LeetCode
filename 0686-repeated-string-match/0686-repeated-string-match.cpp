class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (A == B) {
            return 1;
        }

        int cnt = 1;
        string source = A;

        // Repeat A until the length of source is at least as long as B
        while (source.size() < B.size()) {
            cnt++;
            source += A;
        }

        // Check if B is a substring of source
        if (contains(source, B)) {
            return cnt;
        }

        // Check if B is a substring of source + A
        if (contains(source + A, B)) {
            return cnt + 1;
        }

        return -1; // B cannot be obtained by repeating A
    }

private:
    const int mod = 1e9 + 7;
    const int p = 31;

    long long polyHash(const string& s) {
        long long pPow = 1;
        long long hash = 0;

        for (char ch : s) {
            hash = (hash + (ch - 'a' + 1) * pPow) % mod;
            pPow = (pPow * p) % mod;
        }

        return hash;
    }

    long long pow(long long a, int b) {
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    long long inv(long long x) {
        return pow(x, mod - 2);
    }

    bool contains(const string& s, const string& t) {
        long long tHash = polyHash(t);
        int n = s.size();
        int m = t.size();

        if (n < m) return false;

        long long sHash = polyHash(s.substr(0, m));

        if (sHash == tHash) {
            return true;
        }

        long long pPow = pow(p, m - 1);

        for (int i = 1; i + m <= n; i++) {
            sHash = (sHash - (s[i - 1] - 'a' + 1) + mod) % mod;
            sHash = (sHash * inv(p)) % mod;
            sHash = (sHash + (s[i + m - 1] - 'a' + 1) * pPow) % mod;

            if (sHash == tHash) {
                return true;
            }
        }

        return false;
    }
};
