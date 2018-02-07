#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll V1(string s, int n){
	ll gg = 0ll;
	for(int i=0; i<s.size(); i++) gg += (ll)s[i]-64ll;
	return gg*(ll)n;
}

int main() {
	set<string> Sor;
	char s[46447];
	string st;
	getline(cin, st);
	strcpy(s, st.c_str());
	char *tok = strtok(s, ",\"");
	while(tok != NULL){
		Sor.insert(tok);
		tok = strtok(NULL, ",\"");
	}
	vector<string> V(Sor.begin(), Sor.end());
	ll gg = 0ll;
	for(int i=0; i<V.size(); i++) gg += V1(V[i], i+1);
	printf("%I64d\n", gg);
	return 0;
}
