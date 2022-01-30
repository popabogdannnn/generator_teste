#include <bits/stdc++.h>

using namespace std;

ifstream fin("values.in");

set <pair <int, int> > S;

string itoa(int x) {
    string ret;
    do {
        ret.push_back('0' + x % 10);
        x /= 10;
    }while(x != 0);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc, char *argv[])
{

    srand(time(NULL));
    if(argc != 2) {
        cout << "Numar invalid argumente gen_tester\n";
        return 0;
    }

    for(int t = 1; t <= 20; t++) {
        int N = 250000, M, Q;
        //fin >> N >> M >> Q;
        M = 249999;
        Q = 249999;
        ofstream fout(itoa(t) + ".in");
        fout << N << " " << M << " " << Q << "\n";
        int arr[N + 2];
        for(int i = 1; i <= N; i++) {
            arr[i] = i;
        }
        
        for(int i = 2; i <= N; i++) {
            fout << arr[1] << " " << arr[i] << "\n";
        }

        for(int i = 2; i < N; i++) {
            fout << arr[i] << " " << arr[i + 1] << "\n";
        }
        fout << arr[2] << " " << arr[N] << "\n"; 
        fout.close();
    }
    return 0;
}