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
        int N, vmax;
        fin >> N >> vmax;
        ofstream fout("aux/" + itoa(t) + ".in");
        fout << N << "\n";
        for(int i = 1; i <= N; i++) {
            fout << rand() % vmax << " ";
        }
        fout << "\n";
        fout.close();
    }
    return 0;
}