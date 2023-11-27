// Elliot Nightlight
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1000+10;
int t;
int n, m;
char a[N][N];

enum {
    FIRST = 1,
    SECOND = 2,
    THIRD = 3
};
int matrix_type;
int anti_answer;
int answer;

struct Point { int x, y; };
struct Element { Point source; int distance; };
Element constexpr NONE = { { -1, -1}, INT32_MAX };

inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
inline bool operator!=(Point a, Point b) { return !(a == b); }
inline bool operator==(Element a, Element b) { return a.source == b.source && a.distance == b.distance; }
inline bool operator!=(Element a, Element b) { return !(a == b); }

Point Vova;
Element vova_distance[N][N];
Element primary_distance[N][N];
Element secondary_distance[N][N];

queue<pair<Element,Point>> Queue;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            for(int j = 1; j <= m; ++j)
                a[i][j] = s[j-1];
        }

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j) {
                vova_distance[i][j] = NONE;
                primary_distance[i][j] = NONE;
                secondary_distance[i][j] = NONE;
                if(a[i][j] == 'V') {
                    Vova = { -i, -j };
                    Queue.push({{Vova, 0}, {i, j}});
                }
                if(i == 1 || i == n || j == 1 || j == m) {
                    Queue.push({{{i, j}, 0}, {i, j}});
                }
            }

        while(Queue.size() > 0) {
            Element what = Queue.front().first;
            Point u = Queue.front().second;
            Queue.pop();
            if(u.x < 1 || u.x > n || u.y < 1 || u.y > m) continue;
            if(a[u.x][u.y] == '#') continue;

            if(what.source == Vova) {
                if(vova_distance[u.x][u.y] == NONE) {
                    vova_distance[u.x][u.y] = what;
                    Queue.push({{Vova, what.distance + 1}, {u.x + 1, u.y}});
                    Queue.push({{Vova, what.distance + 1}, {u.x - 1, u.y}});
                    Queue.push({{Vova, what.distance + 1}, {u.x, u.y + 1}});
                    Queue.push({{Vova, what.distance + 1}, {u.x, u.y - 1}});
                }
            } else if(primary_distance[u.x][u.y].source != what.source
                   && secondary_distance[u.x][u.y].source != what.source) {
                bool ok = true;
                if(primary_distance[u.x][u.y] == NONE) primary_distance[u.x][u.y] = what;
                else if(secondary_distance[u.x][u.y] == NONE) secondary_distance[u.x][u.y] = what;
                else ok = false;

                if(ok) {
                    Queue.push({{what.source, what.distance + 1}, {u.x + 1, u.y}});
                    Queue.push({{what.source, what.distance + 1}, {u.x - 1, u.y}});
                    Queue.push({{what.source, what.distance + 1}, {u.x, u.y + 1}});
                    Queue.push({{what.source, what.distance + 1}, {u.x, u.y - 1}});
                }
            }
        }

        /*for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                cout << a[i][j] << ' ';
            cout << '\n';
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                cout << "(" << vova_distance[i][j].distance << ", " << primary_distance[i][j].distance << ", " << secondary_distance[i][j].distance << ") ";
            cout << "\n";
        }
        cout << "\n";*/

        matrix_type = (int)FIRST;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j) {
                if(vova_distance[i][j] == NONE) continue;
                if(primary_distance[i][j] != NONE) matrix_type = max(matrix_type, (int)SECOND);
                else continue;
                if(secondary_distance[i][j] != NONE) matrix_type = max(matrix_type, (int)THIRD);
                else continue;
            }

        if(matrix_type == FIRST) anti_answer = 1;
        else if(matrix_type == SECOND) {
            anti_answer = INT32_MAX;
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= m; ++j) {
                    if(vova_distance[i][j] == NONE) continue;
                    if(primary_distance[i][j] == NONE) continue;
                    anti_answer = min(anti_answer, 1 + vova_distance[i][j].distance + primary_distance[i][j].distance);
                }
        } else if(matrix_type == THIRD) {
            anti_answer = INT32_MAX;
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= m; ++j) {
                    if(vova_distance[i][j] == NONE) continue;
                    if(primary_distance[i][j] == NONE) continue;
                    if(secondary_distance[i][j] == NONE) continue;
                    anti_answer = min(anti_answer, 1 + vova_distance[i][j].distance + primary_distance[i][j].distance + secondary_distance[i][j].distance);
                }
        }

        answer = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] != '#')
                    answer++;
            }
        answer -= anti_answer;

        cout << answer << '\n';
    }

    return 0;
}
