#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int N, S;

int main()
{
    fin >> N;
    for(int i = 1; i <= N; i++) {
        int x;
        fin >> x;
        S += x;
    }

    fout << S << "\n";

    return 0;
}