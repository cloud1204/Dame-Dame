#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int MINN = 2;
int MAXN = 20;
int MINM = 1;
int MAXM = 10000;
int SAVEK = 0;
int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    if (has_opt("minn")) MINN = opt<int>("minn");
    if (has_opt("maxn")) MAXN = opt<int>("maxn");
    if (has_opt("minm")) MINM = opt<int>("minm");
    if (has_opt("maxm")) MAXM = opt<int>("maxm");
    if (has_opt("savek")) SAVEK = opt<int>("savek");
    int n = rnd.wnext(MINN, MAXN, 10);
    string S;
    
    string type = opt("type");
    
    map<string, bool> saved;
    for (int i = 0; i < SAVEK; i++){
    	int x = rnd.next(0, n - 1);
	int y = rnd.next(0, n - 1);
	while (x == y) y = rnd.next(0, n - 1);
	int z = rnd.next(0, n - 1);
	while (x == z or y == z) z = rnd.next(0, n - 1);
	string s = "aaa";
	s[0] = char('a' + x);
	s[1] = char('a' + y);
	s[2] = char('a' + z);
	saved[s] = 1;
    }
    
    /// types ///
    
    if (type == "random") {
    	int m = rnd.next(MINM, MAXM);
    	cout << n << ' ' << m << '\n';
        for (int i = 0; i < m; i++){
            while (1){
            	int x = rnd.next(0, n - 1);
		int y = rnd.next(0, n - 1);
		while (x == y) y = rnd.next(0, n - 1);
		int z = rnd.next(0, n - 1);
		while (x == z or y == z) z = rnd.next(0, n - 1);
		string s = "aaa";
		s[0] = char('a' + x);
		s[1] = char('a' + y);
		s[2] = char('a' + z);
		if (saved[s]) continue;
		cout << s << '\n';
		break;
            }
        }
    }
    
    
    return 0;
}
