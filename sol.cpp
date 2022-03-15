#include <bits/stdc++.h>

#define N_MAX 100000

using namespace std;

ifstream fin("sumcifcmp.in");
ofstream fout("sumcifcmp.out");

int N;
int A[N_MAX + 5];
int freq[100];

int dig_sum(int x) {
    int ret = 0;
    while(x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main()
{
    fin >> N;
    for(int i = 1; i <= N; i++) {
        fin >> A[i];
    }

    sort(A + 1, A + N + 1);
    long long ans = 0;
    int cnt_eq = 0;
    for(int i = 1; i <= N; i++) {
        int sum = dig_sum(A[i]);
        if(A[i] == A[i - 1]) {
            cnt_eq++;
        }
        else {
            cnt_eq = 0;
        }
        for(int j = sum; j <= 81; j++) {
            ans += freq[j];
            if(j == sum) {
                ans -= cnt_eq;
            }
        }
        freq[sum]++;
    }

    fout << ans << "\n";
    return 0;
}
