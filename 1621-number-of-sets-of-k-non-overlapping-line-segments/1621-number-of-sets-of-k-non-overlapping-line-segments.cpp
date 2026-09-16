class Solution {
public:

    const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long result = 1;

        while(b > 0) {
            if(b % 2 == 1) {
                result = result * a % MOD;
            }

            a = a * a % MOD;
            b /= 2;
        }

        return result;
    }

    int numberOfSets(int n, int k) {

        long long N = n + k - 1;
        long long R = 2 * k;

        long long ans = 1;

        for(int i = 1; i <= R; i++) {

            ans = ans * (N - R + i) % MOD;

            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }
};