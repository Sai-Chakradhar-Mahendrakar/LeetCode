class Solution {
public:
    void primeSieve(int sieve[], int N) {
        // Mark 1 and 0 as not prime
        sieve[0] = 0;
        sieve[1] = 0;
        sieve[2] = 1;

        // Initially mark all numbers as prime
        for (int i = 3; i <= N; i += 2) {
            sieve[i] = 1;
        }

        // Start from 2 and mark all multiples of given i (prime) as not prime
        for (long long i = 2; i * i <= N; i++) {
            if (sieve[i]) {
                for (long long j = i * i; j <= N; j += i) {
                    // Marking j as not prime
                    sieve[j] = 0;
                }
            }
        }
    }

    int countPrimes(int n) {
        // Handle the case where n is less than 2
        if (n < 2) {
            return 0;
        }

        int sieve[n + 1]; // Create sieve array
        primeSieve(sieve, n);

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (sieve[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
