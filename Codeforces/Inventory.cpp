#include <iostream>
#include <queue>
using namespace std;

int main() {
	int max = 100003, n, A[max], x;
	bool V[max];
	while(cin >> n){
		queue<int> Ava;
		for(int i=0; i<=n; i++) V[i] = false;
		for(int i=1; i<=n; i++){
			cin >> x;
			A[i] = x;
			if(x > n || V[x]) Ava.push(i);
			else V[x] = true;
		}
		for(int i=1; i<=n; i++){
			if(!V[i]){
				A[Ava.front()] = i;
				Ava.pop();
			}
		}
		for(int i=1; i<=n; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}