#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2")

inline char readchar(){
	const int S = 1<<16;
	static char buf[S], *p = buf, *q = buf;
	return p == q and (q = (p = buf) + fread(buf, 1, S, stdin)) == buf ? EOF : *p++;
}

using namespace std;

const int MAX = 1e5 + 10;

vector<pair<int, int>> g[MAX];
int cnt[MAX] = {};

inline int R(int &a){
	static char c;
	while(((c = readchar()) < '0' or c > '9') and c != '-' and c != EOF);
	if(c == '-'){
		a = 0;
		while((c = readchar()) >= '0' and c <= '9') a *= 10, a -= c ^ '0';
	} else {
		a = c ^ '0';
		while((c = readchar()) >= '0' and c <= '9') a *= 10, a += c ^ '0';
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K, a, b, c;
    R(N);R(M);R(K);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        R(a);R(b);R(c);
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < K; i++)
    {
        cin >> a;
        pq.push({0, a});
        cnt[a] = 1;
    }

    int ans = 0;
    while (1)
    {
        pair<int, int> tmp = pq.top();
        pq.pop();
        if (cnt[tmp.second] == 0)
        {
            cnt[tmp.second] = 1;
        }
        else if (cnt[tmp.second] == 1)
        {
            // cout << tmp.second << ' ' << tmp.first << '\n';
            cnt[tmp.second] = -1;
            if (tmp.second == 0)
            {
                ans = tmp.first;
                break;
            }
            for (auto &v: g[tmp.second])
            {
                if (cnt[v.second] == -1)
                    continue;
                pq.push({v.first + tmp.first, v.second});
            }
        }
    }
    cout << ans << '\n';

    return 0;
}