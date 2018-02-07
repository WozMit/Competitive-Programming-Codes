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

class FiveRooksDiv2 {
    public:
    int findMax(vector <string> board) {
        #ifdef WozMit
            clock_t _start = clock();
        #endif
        //Do you believe in magic?
		int gg = 0;
		for(int i=0; i<8; i++){
			int count_c = 0, count_r = 0;
			for(int j=0; j<8; j++){
				if(board[i][j] == 'R') count_c++;
				if(board[j][i] == 'R') count_r++;
			}
			gg = max(gg, count_c);
			gg = max(gg, count_r);
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
			string board[]            = {
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR",
"RRRRRRRR"
};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {
"R......R",
".R....R.",
"..R..R..",
"...RR...",
"...RR...",
"..R..R..",
".R....R.",
"R......R"
}
;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {
"R.R.R.RR",
"........",
"R.R.R.RR",
"........",
"........",
"........",
"R.R.R.RR",
"........"
}

;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {
"R.R.R.RR",
"........",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"R.R.R.RR",
"........"
};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {
"........",
"........",
"........",
"........",
"........",
"........",
"........",
"........"
}
;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FiveRooksDiv2().findMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
