//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int n; scanf("%d", &n);
		if(n%7 == 0 || (n-2)%7 == 0) puts("Bob");
		else puts("Maggie");
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*INPUT:
100
6
9
83719
35717
5765
43356
66358
78364
27221
62212
94332
53482
36812
4857
43788
7640
27426
65280
48736
45318
96741
90537
88179
71106
65484
69818
17130
10782
4114
18198
71947
38337
23493
31042
94701
67301
14540
69287
26763
3414
23931
44921
25386
20997
96499
44326
88912
17358
8394
25709
57017
47884
86309
20911
45253
52772
97430
83067
31703
93149
43895
79030
55772
44161
4815
31680
3041
95677
3150
34006
70460
34178
84158
98407
77074
68071
19429
23896
9983
64769
40639
85966
27489
97868
13150
56125
19465
26253
69522
33129
2067
11043
10739
42429
3379
98331
756
87355
55027
6245

*/

/*OUTPUT:
Maggie
Bob
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Bob
Bob
Maggie
Maggie
Maggie
Maggie
Bob
Maggie
Bob
Bob
Maggie
Maggie
Bob
Bob
Maggie
Bob
Maggie
Bob
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Bob
Maggie
Maggie
Bob
Maggie
Maggie
Maggie
Bob
Maggie
Maggie
Maggie
Maggie
Bob
Maggie
Maggie
Bob
Maggie
Maggie
Maggie
Maggie
Bob
Bob
Maggie
Bob
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Bob
Bob
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Bob
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Maggie
Bob
Maggie
Maggie
Bob
Maggie
Bob
Bob
Bob
Bob
Maggie

*/