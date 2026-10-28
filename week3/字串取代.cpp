
#include<bits/stdc++.h>
using namespace std;

int main(){

    string str, repl, tar;

    getline(cin, str);
    getline(cin, repl);
    getline(cin, tar);

    int pos = 0;

    while((pos = str.find(repl, pos)) != string::npos){

        str.replace(pos, repl.length(), tar);

        pos += tar.length();
    }

    cout << str << endl;

    return 0;
}
