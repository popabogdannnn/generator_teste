#include <bits/stdc++.h>
#include <stdlib.h>
/*

Generator de teste
Ruleaza fisierul sursa pentru toate testele si genereaza outputul corespunzator lui de genul
test-x.in
test-x.ok

Se foloseste programul sursa oficiala

Primul argument este numarul testului
al doilea argument este numele executabilului sursei oficiale
al treilea argument este numele fisierului de intrare/iesire din sursa oficiala

*/

using namespace std;

char command[105];

void fromStringToCharPtr(string s)
{
    for(int i = 0; i < s.size(); i++) {
        command[i] = s[i];
    }
}

int main(int argc, char *argv[])
{
    if(argc != 4) {
        cout << "Numar invalid de argumente";
        return 0;
    }

    string testNumber = string(argv[1]);
    string solExecutable = string(argv[2]);
    string fileName = string(argv[3]);


    ofstream fileIn(fileName + ".in");
    ofstream testFileIn(fileName + "-" + testNumber + ".in");
    fileIn << cin.rdbuf();
 
    fileIn.close();
    fromStringToCharPtr("./" + solExecutable);
    system(command);

    ifstream fileOut(fileName + ".out");
    ofstream testFileOK(fileName + "-" + testNumber + ".ok");
    ifstream fin(fileName + ".in");

    testFileIn << fin.rdbuf();
    testFileOK << fileOut.rdbuf();


    return 0;
}