#include <bits/stdc++.h>

#define N_MAX 250000

using namespace std;

ifstream fin("date.in");
ofstream fout("date_fast.out");

int N, M, Q;
int t_conn[N_MAX + 5], t_crit[N_MAX + 5], t[N_MAX + 5], lev[N_MAX + 5];
vector <int> G[N_MAX + 5];
int size_conn[N_MAX + 5];
int viz[N_MAX + 5];
int iter = 0;

int find(int t[], int node) {
    if(t[node] == node) {
        return node;
    }
    return t[node] = find(t, t[node]);
}

void DFS(int node, int parent, int h, int k) {
    viz[node] = k;
    lev[find(t_crit, node)] = h;
    if(find(t_crit, node) != find(t_crit, parent)) {
        t[find(t_crit, node) ] = find(t_crit, parent);
    }

    for(auto it : G[node]) {
        if(viz[it] != k) {
            if(find(t_crit, it) != find(t_crit, node)) {
                DFS(it, node, h + 1, k);
            }
            else {
                DFS(it, node, h, k);
            }
        }
    }
}

int count_visit;

void unite_conn(int a, int b) {
    int root_a = find(t_conn, a);
    int root_b = find(t_conn, b);
    a = find(t_crit, a);
    b = find(t_crit, b);
    count_visit++;
    if(size_conn[root_a] < size_conn[root_b]) {
        DFS(a, b, lev[b] + 1, count_visit);
        t_conn[root_a] = root_b;
        size_conn[root_b] += size_conn[root_a] + 1;
    }
    else {
        DFS(b, a, lev[a] + 1, count_visit);
        t_conn[root_b] = root_a;
        size_conn[root_a] += size_conn[root_b] + 1;
    }

}

void unite_crit(int a, int b) {
    a = find(t_crit, a);
    b = find(t_crit, b);
    t_crit[a] = b;
}

void unite_crit(int a, int b, int &cnt) {
    a = find(t_crit, a);
    b = find(t_crit, b);
    while(a != b) {
        cnt--;
        if(lev[a] < lev[b]) {
            unite_crit(b, t[b]);
            b = t[b];
        }
        else {
            unite_crit(a, t[a]);
            a = t[a];
        }
        a = find(t_crit, a);
        b = find(t_crit, b);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fin >> N >> M >> Q;
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        t_conn[i] = i;
        t_crit[i] = i;
        size_conn[i] = 1;
        lev[i] = 1;
    }

    for(int i = 1; i <= M; i++) {
        int x, y;
        fin >> x >> y;
        if(find(t_conn, x) != find(t_conn, y)) {
            cnt++;
            unite_conn(x, y);
        }
        else {
            size_conn[find(t_conn, x)]++;
            unite_crit(x, y, cnt);
        }
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for(int i = 1; i <= Q; i++) {
        int x, y;
        fin >> x >> y;
        if(find(t_conn, x) != find(t_conn, y)) {
            cnt++;
            unite_conn(x, y);

        }
        else {
            size_conn[find(t_conn, x)]++;
            unite_crit(x, y, cnt);
        }
        G[x].push_back(y);
        G[y].push_back(x);
        fout << cnt << "\n";
    }

    return 0;
}
