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

class HillClimber {
    public:
    int longest(vector <int> height) {
        #ifdef WozMit
            clock_t _start = clock();
        #endif
        //Do you believe in magic?
		int gg = 0, max_cons = 0;
		for(int i=1; i<height.size(); i++){
			if(height[i] <= height[i-1]) max_cons = 0;
			else max_cons++;
			gg = max(gg, max_cons);
		}
        #ifdef WozMit
            printf("%30c Executed in %.3f s.\n", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
        #endif
		return gg;
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
			int height[]              = { 1, 2, 3, 2, 2 };
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int height[]              = { 1, 2, 2, 3 };
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int height[]              = { 1, 8, 9, 12 };
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int height[]              = { 10, 4, 4, 2 };
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int height[]              = { 10, 8, 4, 9, 11, 14, 15, 3, 7, 8, 10, 6 };
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int height[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int height[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int height[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HillClimber().longest(vector <int>(height, height + (sizeof height / sizeof height[0])));
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
