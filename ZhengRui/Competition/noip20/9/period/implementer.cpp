#include "period.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

static int N, Q, used = 0;
static std::vector<int> Z;

int query(int i) {
    if (i < 0 || i >= N) {
        std::fprintf(stderr, "invalid query index %d\n", i);
        std::exit(1);
    }
    if (++used > Q) {
        std::fprintf(stderr, "too many queries: %d > %d\n", used, Q);
        std::exit(1);
    }
    return Z[i];
}

int solve(int n, int q);

int main() {
    if (std::scanf("%d %d", &N, &Q) != 2) return 1;
    static char buf[1000006];
    if (std::scanf("%s", buf) != 1) return 1;
    std::string s = buf;

    Z.assign(N, 0);
    if (N) Z[0] = N;
    for (int i = 1, l = 0, r = 0; i < N; ++i) {
        if (i <= r) Z[i] = std::min(Z[i - l], r - i + 1);
        while (i + Z[i] < N && s[Z[i]] == s[i + Z[i]]) ++Z[i];
        if (i + Z[i] - 1 > r) { l = i; r = i + Z[i] - 1; }
    }

    int k = solve(N, Q);

    std::fprintf(stderr, "used %d/%d queries\n", used, Q);
    std::printf("%d\n", k);
    return 0;
}
