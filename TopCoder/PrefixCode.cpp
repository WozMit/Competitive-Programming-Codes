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
const int oo = 1<<30;

bool pref(string a, string b){
	if(a.size() > b.size()) return false;
	return a == b.substr(0, a.size());
}

class PrefixCode {
    public:
    string isOne(vector <string> words) {
        //std::ios_base::sync_with_stdio(false);
        //cin.tie(NULL);
		int gg = oo;
		for(int i=0; i<words.size(); i++)
			for(int j=i+1; j<words.size(); j++){
				if(pref(words[i], words[j])) gg = min(gg, i);
				if(pref(words[j], words[i])) gg = min(gg, j);
			}
		char ans[15];
		if(gg == oo) sprintf(ans, "Yes");
		else sprintf(ans, "No, %d", gg);
		return ans;
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string words[]            = {"trivial"};
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"10001", "011", "100", "001", "10"};
			string expected__         = "No, 2";

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"no", "nosy", "neighbors", "needed"};
			string expected__         = "No, 0";

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"1010", "11", "100", "0", "1011"};
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"No", "not"};
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PrefixCode().isOne(vector <string>(words, words + (sizeof words / sizeof words[0])));
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
