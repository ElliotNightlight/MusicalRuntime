// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 222'222;
int constexpr M = 1'000'000'007;
int t, n;
vector<int> adj[N];

int root;
int parent[N];
int degree[N];
queue<int> Queue;
bool visited[N];

int height[N];
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int u = 1; u <= n; ++u)
            adj[u].clear();
        for(int i = 1; i <= n-1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        root = 1;
        Queue.push(root);
        for(int u = 1; u <= n; ++u) {
            visited[u] = false;
            degree[u] = 0;
        }
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            visited[u] = true;
            for(int v : adj[u]) {
                if(visited[v]) parent[u] = v;
                else {
                    degree[u]++;
                    Queue.push(v);
                }
            }
        }

        for(int u = 1; u <= n; ++u) {
            if(degree[u] == 0)
                Queue.push(u);
            height[u] = 1;
        }
        answer = 0;
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            answer = (answer + height[u]) % M;
            if(u == root) continue;
            height[parent[u]] = max(height[parent[u]], height[u] + 1);
            degree[parent[u]]--;
            if(degree[parent[u]] == 0)
                Queue.push(parent[u]);
        }

        for(int i = 1; i <= n-1; ++i)
            answer = (answer * 2) % M;

        cout << answer << "\n";
    }

    return 0;
}
