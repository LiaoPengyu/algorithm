#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
const int N = 5e3 + 2, mod = 1e9 + 7;
typedef long long ll;
int t, n, q, k;
uint pre;
int ans[N], c[N][N], cnt[N], rnk[N << 1], trnk[N << 1], pos[N << 1], sum[N], sa[N], tsa[N], p;
string s;
void sorting(int j) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
        sum[pos[i + j]]++;
    for (int i = 1; i <= p; i++) sum[i] += sum[i - 1];
    for (int i = n; i > 0; i--)
        tsa[sum[pos[i + j]]--] = i;
 
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) sum[rnk[i]]++;
    for (int i = 1; i <= p; i++) sum[i] += sum[i - 1];
    for (int i = n; i > 0; i--)
        sa[sum[rnk[tsa[i]]]--] = tsa[i]; 
}
int main() {
    cin >> t;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            c[i][j] = j == 0 ? 1 : ((c[i - 1][j - 1] + c[i - 1][j]) % mod);
    while (t--) {
        cin >> n >> q;
        cin >> s;
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        memset(pos, 0, sizeof(pos));
        for (int i = 1; i <= n; i++) sum[trnk[i] = s[i - 1] - 'a']++;
        for (int i = 1; i <= 26; i++) sum[i] += sum[i - 1];
        for (int i = n; i > 0; i--) sa[sum[trnk[i]]--] = i;
        rnk[sa[1]] = p = 1; 
        for (int i = 2; i <= n; i++) {
            if (trnk[sa[i]] != trnk[sa[i - 1]]) p++;
            rnk[sa[i]] = p;
        }
        for (int i = 1, j; i <= n; i = j) {
            for (j = i; j <= n && rnk[sa[j]] == rnk[sa[i]]; j++);
            cnt[j - i]++;
        }
        for (int i = 1; i <= n; i++) pos[i] = rnk[i];
        for (int i = 1; i < n; i++) {
            sorting(i);
            trnk[sa[1]] = p = 1; 
            for (int j = 2; j <= n; j++) {
                if ((rnk[sa[j]] != rnk[sa[j - 1]]) || (pos[sa[j] + i] != pos[sa[j - 1] + i])) p++;
                trnk[sa[j]] = p;
            }
            for (int i = 1; i <= n; i++) rnk[i] = trnk[i];
            for (int j = 1, k; j <= n; j = k) {
                while (j <= n && sa[j] > n - i) j++;
                for (k = j; k <= n && rnk[sa[k]] == rnk[sa[j]]; k++);
                cnt[k - j]++;
            }
        }
        ans[1] = (1 + n) * n / 2;
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= i; ++j) {
                ans[j] += (ll(cnt[i]) * c[i][j]) % mod;
                ans[j] %= mod;
            }
        }
        for (int i = 0; i < q; i++) {
            scanf("%d", &k);
            printf("%d\n", k >= N ? 0 : ans[k]);
        }
    }
    return 0;
}