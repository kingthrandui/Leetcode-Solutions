class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        long long start = 1000;   // First number containing a comma
        long long commas = 1;

        while (start <= n) {

            long long end = start * 1000 - 1;

            if (end > n)
                end = n;

            long long count = end - start + 1;

            ans += count * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};