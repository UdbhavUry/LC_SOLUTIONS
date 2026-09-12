class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& in) {
        int n = in.size(), INF = 1e9;
        using T = pair<long long, array<int,4>>;
        
        vector<array<int,4>> a;
        for (int i = 0; i < n; i++)
            a.push_back({in[i][0], in[i][1], in[i][2], i});

        // *** FIX: sort by START time (x[0]), not end time ***
        sort(a.begin(), a.end(), [](auto &x, auto &y){ return x[0] < y[0]; });

        vector<int> nxt(n, n);
        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1;
            while (l <= r) {
                int m = (l+r)/2;
                if (a[m][0] > a[i][1]) nxt[i] = m, r = m-1;
                else l = m+1;
            }
        }

        auto better = [&](T x, T y) -> T {
            if (x.first != y.first) 
                return x.first > y.first ? x : y;
            for (int i = 0; i < 4; i++) {
                if (x.second[i] != y.second[i])
                    return x.second[i] < y.second[i] ? x : y;
            }
            return x;
        };

        vector<vector<T>> dp(n+1, vector<T>(5, {0,{INF,INF,INF,INF}}));

        for (int i = n-1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                T skip = dp[i+1][k];

                T take = {a[i][2], {a[i][3], INF, INF, INF}};

                if (nxt[i] < n) {
                    auto &nx = dp[nxt[i]][k-1];
                    take.first += nx.first;

                    int p = 1;
                    for (int x : nx.second)
                        if (x < INF) take.second[p++] = x;
                }

                sort(take.second.begin(), take.second.end());

                dp[i][k] = better(skip, take);
            }
        }

        vector<int> res;
        for (int x : dp[0][4].second)
            if (x < INF) res.push_back(x);

        sort(res.begin(), res.end());
        return res;
    }
};