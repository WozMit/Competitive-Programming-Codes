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
const int MAX = (int)2e6+5;
vector<int> st, tm;

bool Can(int k){
	int actual = 0;
	for(int i=0; i<st.size(); i++)
		if(st[i] > actual + k) return false;
		else actual += tm[i] + k;
	return true;
}

class OvercookedDiv2 {
    public:
    int minStale(vector <int> start, vector <int> time) {
        #ifdef WozMit
            clock_t _start = clock();
        #endif
        //Do you believe in magic?
        st = start;
		tm = time;
		int i = -1, j = MAX;
		while(j - i > 1){
			int m = i + (j - i)/2;
			if(Can(m)) j = m;
			else i = m;
		}
        #ifdef WozMit
            printf("%30c Executed in %.3f s.\n", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
        #endif
		return j;
    }
};








// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int start[]               = {1,5,10};
			int time[]                = {3,6,1};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int start[]               = {3,10};
			int time[]                = {1,10};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int start[]               = {1,10,100,1000,10000,100000};
			int time[]                = {50,50,50,50,50,50};
			int expected__            = 16625;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int start[]               = {10,30,50,60,70,80,90,100,110,120};
			int time[]                = {5,4,3,2,1,5,4,3,2,1};
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int start[]               = {1000};
			int time[]                = {1000000};
			int expected__            = 1000;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int start[]               = ;
			int time[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int start[]               = ;
			int time[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int start[]               = ;
			int time[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OvercookedDiv2().minStale(vector <int>(start, start + (sizeof start / sizeof start[0])), vector <int>(time, time + (sizeof time / sizeof time[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
