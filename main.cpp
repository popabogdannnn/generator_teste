#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
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
    memset(command, 0, sizeof(command));
    for(int i = 0; i < s.size(); i++) {
        command[i] = s[i];
    }
}

int main(int argc, char *argv[])
{
    if(argc != 5) {
        cout << "Numar invalid de argumente";
        return 0;
    }

    string testNumber = string(argv[1]);
    string solExecutable = string(argv[2]);
    string solFast = string(argv[3]);
    string fileName = string(argv[4]);


    ofstream fileIn(fileName + ".in");
    
    fileIn << cin.rdbuf();
 
    fileIn.close();
    fromStringToCharPtr("./" + solExecutable);
    system(command);
    fromStringToCharPtr("./" + solFast);
    system(command);

    ifstream fileOut(fileName + ".out");
    
    ifstream fin(fileName + ".in");
    
    //system("mkdir tests");
    chdir("tests");
    ofstream testFileIn(testNumber + "-" + fileName +  + ".in");
    ofstream testFileOK(testNumber + "-" + fileName +  + ".ok");
    testFileIn << fin.rdbuf();
    testFileOK << fileOut.rdbuf();
    
    chdir("../");
    int res = system((string("diff ") + fileName + ".out " +  fileName + "_fast.out").c_str());
    cout << testNumber << " ";
    if(res == 0) {
        cout << "PASSED\n";
    }
    else {
        cout << "WRONG ANSWER\n";
    }

    return 0;
}