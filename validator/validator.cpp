#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

int MINN = 3;
int MAXN = 20;
int MAXM = 10000;
int32_t main(int32_t argc, char* argv[]) {
    registerValidation(argc, argv);
    
    if (validator.group() == "s1") {
        MAXN = 8;
    }
    if (validator.group() == "s2") {
        MAXN = 15;
    }
    /// start input ///
    
    int n = inf.readInt(MINN, MAXN, "n"); 
    inf.readSpace();
    int m = inf.readInt(1, MAXM, "m"); 
    inf.readEoln();
    for (int i = 0; i < m; i++){
    	string s = inf.readWord(format("[a-z]{%d}", 3));
    	for (int j = 0; j < 3; j++){
    	    assert(s[j] - 'a' < n);
    	    assert(s[0] != s[1] and s[1] != s[2] and s[0] != s[2]);
    	}
    	inf.readEoln();
    }
    
    inf.readEof();
    
    return 0;
}
