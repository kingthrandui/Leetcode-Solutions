#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int dp[60][40];

    // Precompute min digits needed for 'a' twos and 'b' threes
    void precompute_dp() {
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 40; ++j) {
                if (dp[i][j] == 1e9) continue;
                // Digits: 2 (+1 two), 3 (+1 three), 4 (+2 twos), 6 (+1 two, +1 three), 8 (+3 twos), 9 (+2 threes)
                dp[min(59, i + 1)][j] = min(dp[min(59, i + 1)][j], dp[i][j] + 1);
                dp[i][min(39, j + 1)] = min(dp[i][min(39, j + 1)], dp[i][j] + 1);
                dp[min(59, i + 2)][j] = min(dp[min(59, i + 2)][j], dp[i][j] + 1);
                dp[min(59, i + 1)][min(39, j + 1)] = min(dp[min(59, i + 1)][min(39, j + 1)], dp[i][j] + 1);
                dp[min(59, i + 3)][j] = min(dp[min(59, i + 3)][j], dp[i][j] + 1);
                dp[i][min(39, j + 2)] = min(dp[i][min(39, j + 2)], dp[i][j] + 1);
            }
        }
        // Ensure monotonicity
        for (int i = 58; i >= 0; --i) {
            for (int j = 39; j >= 0; --j) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            }
        }
        for (int i = 59; i >= 0; --i) {
            for (int j = 38; j >= 0; --j) {
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }
    }

    bool can_fill(int rem_len, long long a, long long b, long long c, long long d) {
        if (rem_len < 0) return false;
        long long req_a = max(0LL, a);
        long long req_b = max(0LL, b);
        long long req_c = max(0LL, c);
        long long req_d = max(0LL, d);
        if (req_a >= 60 || req_b >= 40) return false;
        return req_c + req_d + dp[req_a][req_b] <= rem_len;
    }

    void get_factors(int digit, int& f2, int& f3, int& f5, int& f7) {
        f2 = f3 = f5 = f7 = 0;
        if (digit == 2) f2 = 1;
        else if (digit == 3) f3 = 1;
        else if (digit == 4) f2 = 2;
        else if (digit == 5) f5 = 1;
        else if (digit == 6) { f2 = 1; f3 = 1; }
        else if (digit == 7) f7 = 1;
        else if (digit == 8) f2 = 3;
        else if (digit == 9) f3 = 2;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Prime factorize t
        long long temp_t = t;
        long long req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp_t % 2 == 0) { req2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req7++; temp_t /= 7; }
        if (temp_t > 1) return "-1"; // Invalid prime factor

        precompute_dp();

        int n = num.length();
        int first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // Check if num itself works
        if (first_zero == n) {
            long long cur2 = 0, cur3 = 0, cur5 = 0, cur7 = 0;
            for (char ch : num) {
                int f2, f3, f5, f7;
                get_factors(ch - '0', f2, f3, f5, f7);
                cur2 += f2; cur3 += f3; cur5 += f5; cur7 += f7;
            }
            if (cur2 >= req2 && cur3 >= req3 && cur5 >= req5 && cur7 >= req7) {
                return num;
            }
        }

        // Prefix factors
        vector<long long> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        for (int i = 0; i < first_zero; ++i) {
            int f2, f3, f5, f7;
            get_factors(num[i] - '0', f2, f3, f5, f7);
            p2[i + 1] = p2[i] + f2;
            p3[i + 1] = p3[i] + f3;
            p5[i + 1] = p5[i] + f5;
            p7[i + 1] = p7[i] + f7;
        }

        // Try same length with different prefix matches
        for (int i = min(n - 1, first_zero); i >= 0; --i) {
            int start_d = (i == first_zero) ? 1 : (num[i] - '0' + 1);
            for (int d = start_d; d <= 9; ++d) {
                int f2, f3, f5, f7;
                get_factors(d, f2, f3, f5, f7);
                long long rem2 = req2 - (p2[i] + f2);
                long long rem3 = req3 - (p3[i] + f3);
                long long rem5 = req5 - (p5[i] + f5);
                long long rem7 = req7 - (p7[i] + f7);

                int rem_len = n - 1 - i;
                if (can_fill(rem_len, rem2, rem3, rem5, rem7)) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);

                    // Greedily fill remaining digits
                    for (int pos = 0; pos < rem_len; ++pos) {
                        for (int next_d = 1; next_d <= 9; ++next_d) {
                            int nf2, nf3, nf5, nf7;
                            get_factors(next_d, nf2, nf3, nf5, nf7);
                            if (can_fill(rem_len - 1 - pos, rem2 - nf2, rem3 - nf3, rem5 - nf5, rem7 - nf7)) {
                                ans += to_string(next_d);
                                rem2 -= nf2; rem3 -= nf3; rem5 -= nf5; rem7 -= nf7;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
        }

        // Case 2: Greater length
        int min_len = req5 + req7 + dp[max(0LL, req2)][max(0LL, req3)];
        int target_len = max(n + 1, min_len);

        string ans = "";
        long long rem2 = req2, rem3 = req3, rem5 = req5, rem7 = req7;
        for (int pos = 0; pos < target_len; ++pos) {
            for (int d = 1; d <= 9; ++d) {
                int f2, f3, f5, f7;
                get_factors(d, f2, f3, f5, f7);
                if (can_fill(target_len - 1 - pos, rem2 - f2, rem3 - f3, rem5 - f5, rem7 - f7)) {
                    ans += to_string(d);
                    rem2 -= f2; rem3 -= f3; rem5 -= f5; rem7 -= f7;
                    break;
                }
            }
        }

        return ans;
    }
};