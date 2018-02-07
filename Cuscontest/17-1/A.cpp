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
const int MAX = 1005, MAX2 = (int)5e3+5, oo = 1<<30;
int W[MAX], V[MAX], dp[MAX][MAX2];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	dp[0][0] = 0;
	for(int i=1; i<MAX2; i++) dp[0][i] = oo;
	int te; scanf("%d", &te);
	while(te--){
		int n, capacity; scanf("%d %d", &n, &capacity);
		int sum_val = 0;
		for(int i=1; i<=n; i++){
			scanf("%d %d", &W[i], &V[i]);
			sum_val += V[i];
		}
		int gg = 0;
		for(int s_val=0; s_val<=sum_val; s_val++){
			for(int i=1; i<=n; i++){
				dp[i][s_val] = dp[i-1][s_val];
				if(V[i] <= s_val) dp[i][s_val] = min(dp[i][s_val], dp[i-1][s_val - V[i]] + W[i]);
			}
			if(dp[n][s_val] <= capacity) gg = s_val;
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*INPUT:
14
5 12
10 8
2 3
4 10
6 1
12 12
2 4
4 3
5 1
180 936852
8944 4
4149 5
19975 1
532 1
19194 2
5134 2
8392 3
4491 2
6663 4
14813 3
9271 1
14385 4
7144 1
13121 3
10031 1
7877 5
375 1
3859 3
16335 5
15001 5
17119 3
19153 2
8919 4
4339 5
19473 5
357 1
2932 5
2936 4
14029 2
17756 1
8439 2
7077 1
12849 4
2403 3
19236 2
15344 4
7825 4
9626 2
10275 5
15881 4
9506 1
11802 5
16929 2
7526 2
4217 4
10713 2
4378 3
4788 5
8265 1
2366 5
17156 3
5067 3
5709 4
17363 3
1303 5
19054 1
9980 2
572 4
161 1
8645 4
16620 3
14036 3
6100 4
10476 1
2897 1
10215 2
2659 1
3833 2
14217 3
10633 1
19643 1
11450 1
7044 5
8593 5
18384 5
3677 2
3319 4
18304 1
12736 4
2926 5
2465 3
3589 4
2739 1
1384 2
16378 4
592 3
2920 3
17162 3
19573 5
6704 5
18668 1
13916 5
7701 5
19978 2
4130 3
15836 3
698 2
15081 5
19834 1
316 3
3040 4
1299 5
2238 5
18818 2
8457 1
14761 2
15504 1
17342 2
11306 4
9286 5
1955 4
17813 4
13148 4
8513 3
12369 5
4552 5
1429 5
7424 1
19088 1
5487 1
18980 2
6499 5
4298 4
6629 3
16536 4
5567 1
2846 4
7773 4
4586 1
7657 4
17952 2
13394 4
6091 2
5422 3
16599 3
8024 2
18137 1
18864 3
6850 5
3198 4
18326 2
19226 1
5286 4
11465 1
8216 4
12986 4
8341 3
18019 5
13936 1
16789 4
16432 4
4088 2
4786 3
1598 4
13134 3
11399 1
8323 3
9997 1
2354 2
6913 3
14473 4
10772 4
19729 2
10553 3
11145 5
4075 5
588 3
14846 5
4206 4
11692 3
6026 3
3997 5
14003 1
11561 2
10381 4
7593 3
14347 4
15989 1
16837 5
13923 3
252 821
6136 3
15813 5
14934 5
13878 1
5750 1
10014 3
14684 4
4752 1
15815 2
16801 4
7042 5
17051 2
8214 1
14352 4
13105 4
12455 4
17336 5
3697 5
2382 4
12235 4
13325 4
15140 3
7432 2
14128 3
3870 5
10415 5
4616 4
4081 5
12455 1
805 1
7975 1
14923 5
4483 2
14397 4
5068 3
504 3
18681 5
19106 3
573 3
12129 5
13354 2
17683 3
1284 5
3325 2
12667 1
5495 5
19389 1
6390 2
16753 5
7200 3
16208 1
12568 2
6526 5
18694 3
19206 3
3229 3
4933 5
11394 1
969 1
18360 1
6691 4
587 5
9145 5
12917 3
2756 1
10183 3
17147 4
17437 4
14761 3
19276 2
15174 5
16188 1
3790 5
3595 2
7257 3
16016 5
334 4
2791 3
4151 5
456 5
18846 4
14018 1
3441 1
3322 4
6255 3
18622 3
3940 1
8101 3
17082 3
15237 2
51 2
12390 4
11841 1
4753 3
1111 4
6005 5
5921 2
1337 5
14242 4
18330 2
17303 5
14062 1
1646 3
16425 5
5239 4
14704 3
1640 3
17774 4
3177 3
18555 3
6995 1
17047 5
10621 5
859 5
1861 2
15326 4
5055 3
10658 1
7140 3
15419 1
1933 5
12002 1
5884 3
9212 4
18367 1
6367 3
11167 4
1942 5
17681 5
7863 3
7841 2
10732 1
18022 4
12819 3
3652 1
18600 3
5950 1
9229 4
11211 2
7633 3
18436 1
15052 1
5328 3
8853 3
15525 5
10406 5
10844 2
1977 3
4315 5
15485 4
5716 3
8530 2
8334 5
1672 2
8961 3
48 2
511 3
9508 4
7180 5
12532 3
19074 2
17864 2
15688 4
522 3
11364 3
9165 4
6296 5
16127 5
12842 2
15294 2
13543 5
5017 1
4861 4
7972 2
5322 4
2809 5
6812 1
11292 1
15177 1
7206 4
19737 5
17954 1
2208 1
5970 2
6357 3
18243 2
16364 2
12130 5
17506 5
11271 3
5196 2
145 5
14940 3
14954 5
10659 4
7234 4
1172 2
13067 5
4007 2
19427 2
4779 2
13369 2
6405 3
18435 5
9361 4
9820 3
19016 2
18306 1
2481 4
16733 3
9685 5
16337 5
7835 1
17677 4
18038 2
13725 3
10365 2
17124 1
3922 1
1540 4
17296 1
15146 2
3479 2
17806 5
15665 4
17266 1
14588 5
19530 3
19101 4
9164 5
13535 1
10187 1
19200 2
17255 4
12819 4
4860 3
17326 1
12682 5
3556 3
17991 5
8688 5
15741 4
6812 1
1279 1
9273 4
3659 5
12728 1
18183 3
13697 2
16959 3
15095 3
4350 1
304 123653
8522 5
11770 4
6995 3
9073 1
4739 3
3460 3
3989 2
6146 5
8350 2
19341 3
15269 3
12284 4
13575 2
5816 1
10767 2
17646 5
7481 3
18113 2
3914 1
14875 5
4231 4
18132 1
15948 1
4805 4
2016 5
1490 5
2333 3
19535 5
19042 1
3004 2
4691 4
3121 2
12506 5
5900 1
15985 1
13723 4
13372 2
1000 4
11858 5
15295 1
15704 4
5378 4
14590 4
1504 1
6254 4
6152 2
1672 4
13655 4
12837 5
1069 5
8596 3
18712 3
18425 4
2153 4
14771 1
863 1
19664 2
13276 3
6651 2
2586 2
15360 5
3595 4
3618 4
9135 1
17002 4
18886 2
4898 5
18139 2
15873 2
6215 4
17699 5
555 2
19316 4
9202 1
337 4
7192 2
19580 4
18060 4
10228 4
12394 5
13815 3
7186 5
793 2
5842 5
19748 5
3715 5
13401 2
4527 1
5899 1
17467 4
16594 1
17372 5
19468 5
2346 3
11475 5
2082 3
11161 3
642 5
4623 5
2745 5
10370 2
18241 2
15032 1
4464 5
9700 3
4390 1
1250 2
11027 5
19121 5
15621 1
4434 1
9564 3
10312 3
4645 4
6765 5
12826 2
9451 1
952 4
6631 2
18870 4
13881 5
11978 1
1057 4
12310 5
1468 4
18258 4
13716 4
4092 4
6982 2
17122 1
5005 1
5888 3
2905 4
16276 3
13915 1
4786 3
16266 3
6651 4
3517 1
2420 4
19747 4
18383 4
1384 5
13277 4
3482 5
10221 1
12376 1
11430 2
14157 3
2400 5
4947 2
10381 3
8458 2
7926 5
947 1
7651 3
16237 2
14552 4
15311 5
156 3
8255 1
12051 1
1743 2
18885 1
12588 3
18644 4
7885 3
15056 5
6454 5
3285 4
13203 4
3674 1
7878 3
13704 2
16692 4
15643 1
5878 1
2730 3
18088 2
8341 5
17302 1
17357 3
12748 1
19104 3
12771 4
1008 2
11662 1
2586 2
18749 1
3749 3
12943 1
11675 2
13672 3
3292 3
18556 2
1742 2
6404 2
5536 1
9436 5
7602 1
10279 4
5843 2
5022 1
150 3
15726 3
8770 3
19065 2
9569 1
19360 4
13941 3
16194 4
16438 5
5192 3
7581 3
1115 4
9452 1
9094 5
6250 2
19493 2
7831 1
9913 1
11033 3
3566 1
1377 3
774 4
11497 4
3316 3
14709 1
10067 4
2451 4
9651 3
6448 2
17946 1
13162 3
18426 1
8576 3
838 3
1980 4
19360 5
18655 1
8757 5
10724 3
19402 3
10594 1
15319 2
8567 4
7057 1
2217 5
18128 5
17991 5
3807 2
15230 2
5771 5
10217 5
16849 2
6540 1
3451 2
14267 3
15553 5
12608 4
854 2
9810 4
550 3
19502 4
7619 3
14515 3
5201 2
19047 3
18027 3
17910 5
17651 2
1926 1
10532 2
784 2
11975 5
18304 3
14957 2
148 4
464 3
2954 4
5106 4
8691 1
2258 3
6922 1
4114 5
5595 5
6044 4
8488 4
1975 3
7966 4
11532 5
18380 5
4394 2
9943 2
2693 4
7358 2
9811 2
10139 1
5994 2
390 2
3521 1
9228 2
11072 2
11663 5
208 175919
18105 1
15844 1
16351 2
287 2
2763 1
1727 3
12402 3
19322 5
10992 4
10928 1
905 1
150 3
8539 1
5826 5
5 1
5154 3
13274 5
16722 2
16374 1
12509 1
2439 4
11834 3
13568 5
5930 4
11209 2
18264 2
8960 1
10312 5
15426 4
14212 2
460 3
5674 2
12039 1
3631 4
4410 4
15641 4
16984 4
6641 2
13412 5
1941 4
6086 1
10672 3
10819 5
13455 4
19710 3
18040 4
7780 5
14483 1
11879 3
10883 3
8862 3
5734 1
4319 5
3692 5
19170 5
8247 4
12137 1
543 2
3341 5
19654 4
5258 3
13923 1
622 4
15611 1
5682 2
4953 3
14219 4
6332 2
10649 5
6844 4
19887 3
8147 4
1959 1
2463 5
5897 5
9617 3
1523 3
19284 1
5732 5
10337 5
18087 3
16672 4
15225 5
4150 1
11827 5
370 3
19746 3
11501 2
189 5
11981 1
9324 4
7637 1
1687 5
16173 3
1129 3
17226 3
4680 1
14621 1
15933 5
10401 5
6790 1
1453 1
1323 4
825 4
17451 4
9410 4
6668 2
6113 2
6217 1
8748 2
957 4
11412 5
2124 2
13711 5
16025 2
10497 2
2110 3
13539 4
5875 2
7161 5
19249 4
14059 4
10238 2
5310 4
18167 5
11462 4
5853 4
13086 4
16437 5
4361 5
1146 1
11573 5
18246 2
8572 2
16007 4
18632 2
12849 2
4014 5
18216 1
5722 4
8783 5
13202 2
7127 1
17991 5
12960 2
1555 3
12280 1
18084 1
6916 5
2264 2
5873 2
9082 3
96 5
14166 3
11095 5
12071 2
8093 1
14152 2
2755 2
10133 5
16258 5
11015 1
8732 5
11489 2
12950 5
9141 1
12430 3
8307 1
2851 5
9672 4
140 4
7792 1
14566 3
17904 4
19181 4
18199 1
7612 4
15901 3
98 4
14615 3
2347 1
13917 2
14490 4
17883 2
6261 4
12650 1
17671 5
2804 4
1273 2
12771 4
19329 1
16158 4
6748 3
13110 3
197 3
15480 2
17380 5
18742 3
18523 3
4172 5
11146 5
3461 1
17439 5
12806 2
8998 4
19903 4
6900 3
2727 1
22 919226
5981 4
10815 2
6513 2
10830 3
60 4
8811 5
8884 3
17996 5
15925 1
16448 5
8723 4
5726 1
12870 4
5377 3
11197 3
15802 2
9973 4
13548 5
17847 5
18547 4
2628 2
13395 3
202 541011
10524 5
13787 4
5404 4
7605 2
16302 5
1943 4
9767 3
616 5
11939 1
7543 3
3130 3
16189 2
1215 3
12598 2
6062 4
18040 3
2912 2
14559 1
15804 4
4021 4
17158 4
14441 5
16589 1
7433 5
12845 5
12815 2
5232 5
10831 4
3775 2
13836 1
5782 2
17230 5
12644 3
2520 4
13926 1
16439 4
16434 2
19495 4
10910 5
7192 3
801 4
7184 1
15712 5
1433 5
3299 2
1966 1
4436 5
17390 2
4954 3
6632 4
13811 2
12688 2
16250 3
11945 1
16051 2
19409 4
2830 1
2797 2
12988 2
9397 5
433 3
2236 4
17770 2
3963 2
3853 3
828 3
6393 3
3286 1
7657 4
6484 4
8481 5
14079 3
2951 2
4588 4
92 5
18030 2
6228 5
9274 3
17602 3
17752 5
12520 2
9220 2
10418 1
16140 3
19480 1
14681 2
13095 4
9216 3
9403 4
5463 1
13384 2
1557 5
4811 5
7966 2
3985 4
10580 4
153 4
18234 1
5822 5
6882 1
5011 3
2053 1
2300 5
7345 4
5994 1
7779 2
19572 3
782 3
3225 1
19835 2
18472 3
12776 4
1031 5
16274 2
17641 5
13735 5
10348 2
19060 4
16893 5
12172 1
7890 4
13668 1
7203 3
10538 2
15368 2
12868 3
8990 2
15133 1
558 1
7838 1
7840 3
9761 4
4536 2
15477 2
4971 5
17457 5
16968 5
19421 3
3859 1
13728 2
13430 5
11284 1
18219 1
19841 5
13791 2
13230 2
1593 3
7779 2
15898 3
572 1
14900 1
15205 4
11053 4
14014 2
19866 1
15503 3
16554 5
6335 3
6590 5
19143 2
3332 5
13141 5
4418 5
15822 1
6258 2
4432 1
7507 1
2459 3
6542 1
9882 2
14063 1
12373 1
12292 2
17121 3
13433 5
7651 2
14056 3
6563 4
5835 5
17066 4
885 5
3536 5
8061 1
17997 4
2533 3
2375 2
8438 3
11960 3
9631 2
5398 4
7048 2
15582 5
8752 4
1178 1
3096 5
4857 1
14770 4
660 5
17342 4
574 5
3082 4
3343 5
146 182682
17906 3
13143 3
18703 1
3741 1
15359 2
9292 5
8875 1
1209 3
6264 4
3203 1
13270 2
13898 2
6879 3
2260 4
15506 2
6024 2
43 2
19206 3
13041 5
1660 2
4775 4
4451 2
6419 4
1318 4
7963 5
16350 5
3762 5
6945 4
18518 2
14162 1
14310 4
14020 3
13646 3
8395 2
13771 2
17544 1
9812 2
2304 2
17057 2
9840 2
16191 4
11643 4
10576 2
1956 3
8865 4
4512 5
14823 2
5826 1
6398 4
7484 3
6605 4
10293 1
18686 4
197 2
9027 1
2757 2
11487 5
6508 3
9654 4
15058 5
18875 2
8380 1
18439 2
6463 5
12617 4
10035 2
5725 4
10216 5
18942 1
2711 3
3011 4
3636 3
13971 4
728 5
9744 4
1971 2
14649 2
12913 4
3023 4
11455 5
17329 5
181 4
10702 1
8150 5
4673 1
8170 1
1599 4
13817 3
12244 4
18542 4
14854 1
209 3
14517 4
4779 4
5426 2
19268 4
18410 2
4904 4
11882 4
4048 2
4223 1
5788 5
10812 5
8095 1
16343 2
16067 2
10285 4
8821 5
13986 1
5922 1
7425 1
15733 3
8513 2
5582 3
10884 1
11386 3
4013 2
12988 5
15108 3
4326 5
2873 1
11822 3
11783 2
7770 4
2948 4
15455 2
15285 1
8405 2
1493 2
10220 4
17026 3
17743 3
7131 5
7774 5
18285 2
16970 1
363 3
7196 4
14867 1
13476 5
3213 3
13275 5
9169 5
1275 3
12117 3
16611 1
18 153577
17048 2
2651 13
11611 23
2137 12
12812 14
10491 7
16449 8
14124 5
15757 11
16033 12
5707 11
7409 9
16324 3
14405 23
3410 11
3283 11
15075 15
16974 25
20 508344
198863 41
94680 49
108480 4
8593 85
189079 6
31947 89
147734 50
142119 3
96226 45
63678 59
72206 12
191498 38
67315 75
21928 91
143427 2
109359 19
82348 30
169129 75
109564 100
144837 77
500 332091
1424 2
796 1
326 2
1209 4
934 4
336 3
879 4
810 1
1833 4
130 4
1317 1
1976 3
660 3
123 1
1899 2
1027 3
959 4
430 2
740 3
476 4
1850 3
1062 1
1624 3
1779 4
665 4
693 2
1799 1
658 3
700 2
1968 2
1381 1
295 1
291 2
1666 2
338 4
171 4
119 3
928 1
59 1
1722 2
1011 2
359 2
734 3
1819 3
21 1
973 2
1410 2
1285 4
602 3
410 4
1783 3
1020 4
1896 3
1314 2
267 2
1565 1
1489 3
590 3
454 1
1040 1
1036 2
663 1
1986 4
237 1
846 3
1216 4
550 2
1770 3
1399 1
516 1
892 2
1833 2
653 2
1383 2
1758 3
1476 4
45 3
771 4
293 4
98 2
157 1
719 3
290 3
1960 1
1815 2
1539 1
1205 3
1841 3
929 2
139 4
15 1
1219 2
1643 3
499 4
1202 3
1653 3
1099 2
696 4
863 2
417 1
1138 3
881 4
1383 4
1168 1
1704 2
597 4
1435 2
703 2
1580 1
930 4
256 2
808 1
638 2
329 3
131 3
1848 2
1675 3
1598 3
297 4
1775 3
569 1
343 1
1378 3
1399 1
1642 4
1136 2
45 1
139 4
777 2
284 4
1889 3
939 3
856 1
608 3
1852 3
1504 1
1050 3
33 3
416 4
1916 3
1886 4
931 3
1920 4
732 3
101 3
560 3
1667 2
76 2
158 4
227 4
1454 3
889 2
373 4
1640 1
970 3
743 1
833 1
977 2
800 3
1809 4
476 1
1052 2
460 1
48 2
795 2
831 1
1160 3
1374 3
40 3
489 4
935 2
1806 3
1466 3
319 4
1117 1
1803 4
1799 2
931 1
208 3
1007 4
1191 1
458 2
1720 2
105 2
1239 3
1918 2
1846 3
1116 1
781 2
1473 4
1630 2
572 2
903 3
1496 2
312 2
1878 2
1759 1
256 4
1093 1
490 3
802 1
1135 1
40 2
695 4
1535 2
525 4
925 2
793 1
1249 4
353 1
1542 2
1907 1
1381 3
911 3
580 1
1620 2
1934 2
1540 2
259 3
1030 2
746 2
531 3
1443 3
508 3
1856 1
1600 3
573 3
1246 1
1435 4
1222 4
643 4
1038 3
529 2
841 3
607 4
1911 3
583 3
1513 1
614 1
489 4
1858 4
861 1
123 1
1136 4
747 2
274 2
1638 3
1148 1
478 2
1341 3
798 4
460 4
1027 3
481 3
1500 4
611 1
1001 2
1425 3
920 2
530 3
299 1
524 1
561 1
323 4
379 2
323 4
519 4
1203 2
1145 3
741 1
1952 3
929 3
1482 2
1668 4
1830 4
221 2
700 4
113 3
1619 3
149 1
492 1
404 2
693 1
1257 1
238 2
217 4
93 2
697 2
1710 2
1542 3
1574 4
1733 3
598 2
622 2
716 3
1839 3
456 2
1011 4
779 3
921 1
1111 2
1841 3
1692 2
506 1
691 3
497 4
611 2
1625 2
577 2
1068 4
1752 1
1151 4
323 4
1012 2
1936 2
1431 3
1509 3
1440 3
1189 4
1031 4
906 3
1632 4
26 1
1344 1
661 2
1716 2
584 3
144 4
783 1
1238 2
572 1
623 4
4 1
899 3
117 3
1891 2
600 4
212 4
913 2
1141 2
468 2
1361 2
973 3
1926 2
473 1
1229 1
1647 4
1617 3
829 2
869 1
1638 4
692 3
1070 4
690 2
500 2
1505 2
134 4
1203 3
599 1
1690 3
1245 2
1593 3
630 4
674 2
1677 4
1761 1
453 3
1846 4
1298 1
438 3
104 1
1522 1
1338 2
1051 4
529 2
291 1
1319 4
1115 2
1577 3
558 2
1487 4
1580 3
1802 4
696 3
1256 3
28 3
1292 1
1170 1
1888 2
1638 1
1766 4
475 1
431 2
629 2
794 1
366 4
1758 4
210 1
418 4
1846 4
1918 2
326 1
668 3
1513 2
520 1
431 4
602 1
252 2
1445 1
1369 2
603 4
1602 1
899 1
1353 3
1231 2
1294 2
1225 1
1308 3
91 2
198 3
464 4
1676 2
46 2
243 3
656 1
446 1
1945 3
1430 4
1776 3
1381 2
265 2
938 2
27 3
958 4
443 3
966 2
1861 2
1347 4
948 1
21 1
1383 2
1281 4
1522 4
1067 3
1198 3
1211 2
968 3
1013 4
1385 2
743 3
1950 2
30 2
1788 2
968 4
1934 3
1258 4
943 2
1190 2
1649 3
448 3
131 3
1569 1
1500 2
51 4
1270 3
1205 4
716 4
1217 2
1449 4
1050 2
1362 4
513 1
407 1
750 3
747 4
1110 3
1735 1
558 3
578 2
1133 4
1008 1
409 1
1285 4
1715 1
723 2
562 1
1817 4
529 2
1876 1
1292 2
1727 2
1219 2
1375 1
582 3
1399 3
648 3
1609 3
333 1
275 3
305 1
1000 272415
1586 5
262 5
706 1
1206 6
1566 3
879 6
1449 5
295 1
1622 5
704 3
53 5
1170 5
879 1
1029 6
821 5
1701 5
1478 4
1898 5
914 5
952 1
405 1
1420 1
1427 6
1939 4
497 4
1416 4
1439 4
104 2
1563 1
676 5
173 5
1947 2
261 3
502 1
1999 5
280 4
442 5
1113 2
613 6
5 6
792 5
512 5
783 2
1824 4
427 4
287 2
978 3
1006 1
1217 6
1492 1
977 4
177 4
6 6
1575 4
567 2
195 3
713 5
1684 4
1423 5
1891 1
1895 4
1319 3
1637 5
1435 4
325 2
1858 4
1508 2
368 2
976 3
161 4
1545 6
1537 4
1217 6
1995 5
959 2
1775 3
1909 5
1245 4
1190 6
687 4
1967 2
871 1
1076 3
1218 6
776 5
1955 3
266 1
904 1
1069 2
1904 6
1023 1
1492 6
827 6
1118 6
1924 4
65 5
727 5
1470 3
199 4
1325 2
1520 5
703 6
774 3
1180 2
1755 1
814 2
1509 3
17 3
648 1
1089 5
780 6
526 5
40 3
1367 6
195 4
1530 5
1759 5
15 6
296 5
595 2
1627 6
1083 1
1298 4
1677 4
513 5
989 1
166 4
1861 2
1888 6
1514 4
1903 5
1792 6
719 5
1806 3
503 3
847 5
466 3
692 4
1629 4
1908 3
1652 3
291 5
169 2
1320 3
1507 3
655 5
1752 6
815 2
608 6
1012 1
882 4
1831 2
536 5
1910 1
1303 6
1657 3
1347 5
1021 3
1116 4
1347 2
500 1
683 3
900 4
596 3
1330 2
462 2
1695 6
1045 5
225 4
697 6
19 6
1316 4
1536 2
1495 5
10 1
90 5
511 3
1706 2
1523 4
1660 1
1944 1
1052 6
713 1
824 5
756 1
131 5
1747 5
406 1
728 2
1860 4
1512 1
691 5
884 2
1264 5
692 6
651 3
463 3
1011 4
692 1
109 6
1819 6
1877 5
524 1
964 2
886 6
1790 2
309 2
489 5
1783 4
1574 6
1250 5
575 3
849 5
885 2
1694 2
1538 5
600 6
1994 5
1410 6
407 5
1729 1
589 6
1048 1
239 4
1612 1
1184 4
1810 1
56 6
1185 1
1361 1
1790 2
213 5
1408 4
81 3
90 5
1767 6
1365 4
1663 2
1676 6
1540 3
861 4
151 1
1802 1
793 3
1255 1
528 1
168 6
832 1
1376 3
108 4
1067 1
1201 4
124 3
1819 5
1605 1
1520 4
803 5
582 6
1901 4
1309 6
1478 2
1856 3
508 6
400 6
214 5
1536 1
1500 6
1789 5
1907 2
725 2
803 6
870 5
142 6
886 3
1552 2
626 5
187 4
57 1
8 6
1596 1
227 5
1287 2
461 4
1836 6
391 3
1981 6
1578 3
1663 4
431 3
600 3
262 4
648 2
689 6
1630 3
1218 5
1797 3
30 3
68 1
1474 3
1844 6
210 5
137 4
524 4
995 3
528 3
1879 5
215 5
509 4
78 2
529 2
1949 2
1856 2
424 6
130 1
1249 4
1911 4
273 3
1079 3
646 5
1860 2
56 3
457 5
1427 6
1418 5
1421 4
234 3
1303 5
1458 4
1875 2
1478 2
1429 2
95 1
302 1
464 3
858 2
45 5
1915 6
1459 3
1445 6
721 3
1512 1
758 4
1300 6
654 4
1977 3
1384 4
182 3
1378 1
1074 1
656 2
321 6
902 6
745 5
588 1
1983 1
488 4
341 5
1617 3
1702 2
1344 5
1484 2
1602 2
152 6
134 6
503 6
664 6
1191 1
536 4
1515 1
1597 6
247 5
922 2
1715 3
115 1
1015 1
1254 5
1724 1
234 3
84 4
1677 6
813 3
954 3
586 3
733 2
360 2
552 4
1418 3
784 3
943 1
1277 2
1308 4
1356 2
35 2
536 1
572 1
404 2
1769 5
320 2
1803 3
1279 3
1143 4
1200 4
1817 6
1335 1
991 1
429 3
1363 6
418 1
1076 2
467 5
1917 3
681 5
836 3
1025 3
1766 2
1243 2
926 3
229 4
1594 3
1104 1
1716 2
977 2
1457 4
233 4
1680 1
541 4
1703 1
371 5
974 1
677 2
725 2
1936 4
904 2
1444 3
1264 3
29 2
430 6
1748 4
663 4
208 6
1015 2
134 3
998 2
1813 3
1249 4
70 4
1903 2
225 1
1893 1
561 2
1755 2
367 5
1547 5
1946 3
263 2
204 1
1448 6
110 6
1130 3
93 3
71 1
1543 3
934 5
982 1
852 5
688 1
1478 4
1909 5
561 6
1308 4
1138 2
958 1
292 3
500 1
1223 2
995 2
748 5
735 4
1928 1
873 4
737 3
1736 6
1990 4
1159 2
29 3
170 4
1230 1
334 5
247 2
1976 1
1719 3
36 2
1215 2
371 2
1091 6
214 1
1814 6
1733 1
1825 3
1934 1
638 6
1943 6
1665 1
288 6
429 6
270 5
1145 3
1838 6
1760 2
819 1
1671 5
1615 6
63 1
1479 6
485 4
1963 3
1545 6
1198 4
1732 6
970 1
377 1
7 1
1318 2
1322 2
949 4
830 4
1120 1
1108 4
1553 3
489 6
1887 4
1391 5
63 3
1495 4
1023 6
1954 1
679 2
1138 3
1599 1
283 1
550 4
489 6
216 6
673 4
1728 6
1937 2
389 4
749 6
735 3
916 4
1070 3
1663 4
601 1
67 5
773 2
1971 5
713 6
16 5
29 2
1530 2
641 6
698 5
1885 1
1051 3
1421 4
787 6
1061 4
1659 5
567 6
47 6
1587 2
681 3
1882 6
1382 2
1053 3
326 1
748 1
1928 5
293 5
913 1
195 6
1965 2
792 3
843 4
561 4
922 6
1544 2
1171 4
188 5
895 3
25 4
540 2
1351 1
98 2
1135 2
644 6
969 3
326 3
141 2
1393 3
58 6
166 3
1099 5
1154 2
1932 3
236 3
256 5
1389 2
553 1
128 3
1363 2
336 5
1440 5
253 6
1311 4
107 6
1047 1
239 6
1954 4
16 3
1447 1
563 1
1961 1
720 6
1247 5
110 1
1173 6
737 1
65 4
351 6
1183 4
1364 2
313 4
979 6
1809 5
1788 5
204 3
1776 3
1626 2
77 2
53 6
532 4
1056 6
1416 2
1762 3
1983 6
461 4
1335 2
617 1
1862 5
1185 2
1494 4
1786 1
1626 4
1644 6
1598 3
943 3
548 4
609 1
1741 1
1004 5
221 6
212 2
874 1
1942 5
1287 2
863 3
1201 1
1744 2
1614 2
1735 2
711 1
753 5
759 1
517 4
1216 6
979 1
1507 5
1876 6
720 5
646 1
672 1
1270 3
1655 2
301 2
177 1
1348 4
283 2
1225 3
322 2
213 4
465 4
1638 2
1672 1
1290 2
1166 3
739 5
1267 5
49 1
332 6
1590 2
810 2
1611 4
1814 4
1706 5
574 4
1 6
100 6
1858 6
1086 5
1932 5
1099 3
81 2
614 1
882 4
1713 1
31 3
876 3
30 3
591 6
1344 4
395 3
1838 5
609 6
1934 2
1327 4
545 6
73 1
860 5
1607 5
228 6
1348 3
802 1
191 3
1910 3
987 5
362 2
433 4
835 2
1850 4
647 5
1493 2
807 5
1777 6
1865 5
1788 3
1884 1
1032 6
1072 2
798 3
767 6
977 5
1618 1
1585 3
811 4
559 6
1294 4
94 3
1359 1
315 3
1595 3
533 4
1219 4
1821 4
1269 4
490 3
1275 2
26 6
1460 4
1765 5
1983 3
1414 3
1588 3
491 4
1451 3
219 2
533 3
836 4
639 4
566 3
288 2
1882 1
1498 4
196 1
1304 2
889 5
970 1
1546 3
1843 4
73 1
347 1
474 3
1316 6
541 3
1506 3
1400 1
1217 6
1148 2
1814 6
221 1
1841 5
1749 5
429 3
755 1
1716 4
1433 5
690 2
302 3
1032 4
1018 3
1102 4
238 2
1303 6
487 5
1002 6
635 4
64 1
1900 4
1137 5
485 1
528 5
1334 6
1093 2
1030 6
1244 3
564 5
1312 5
272 5
1888 3
1147 3
1489 2
1769 1
975 3
1429 5
186 5
202 5
695 2
1802 2
718 5
657 4
1492 1
1065 5
174 1
1757 6
1720 2
1834 4
1968 4
1068 1
268 5
100 2
1501 3
1717 3
724 2
645 5
767 6
588 4
1513 4
952 1
343 3
86 3
1742 4
1784 2
1384 5
1705 3
539 2
1907 4
304 3
1918 4
326 5
857 1
690 2
1087 2
1676 6
1398 4
215 1
1603 5
1138 5
1675 5
35 2
1737 2
539 3
642 2
1988 1
1631 3
1197 1
1122 3
1009 4
1942 4
1627 1
1999 5
1518 4
1123 2
1352 2
582 4
350 1
1312 3
426 1
1358 3
1796 2
68 3
1143 3
1969 2
38 4
956 1
1818 5
1315 1
818 1
1254 6
1417 3
1468 2
884 3
1435 2
623 4
1361 5
263 2
974 2
920 2
1109 5
1426 4
408 4
1453 2
1644 1
722 6
293 5
1783 4
553 1
961 6
1271 1
884 6
1884 4
69 5
1035 1
1582 6
1602 6
188 5
1759 4
1048 6
144 2
249 1
1657 2
1266 4
1550 5
637 4
92 6
1002 3
981 5
1553 5
17 5
1654 4
1110 3
202 5
669 4
1852 5
1382 6
392 3
1001 2
206 3
1624 5
600 3
1539 4
836 4
243 5
588 2
837 2
1331 3
1904 4
788 3
1740 5
1998 5
413 5
1793 2
1409 6
1441 5
755 5
894 2
1547 6
751 3
1108 6
1541 6
1168 6
1236 6
438 3
869 5
722 6
1304 2
1699 4
1162 1
1829 2
1976 1
1414 5
1505 3
868 4
801 4
1169 6
1774 5
1178 2
1861 1
1187 6
496 3
311 4
1000 1000000
767 5
1976 6
1301 6
83 4
443 4
1904 1
1757 1
1716 3
1302 5
592 5
327 3
1391 3
428 4
899 1
287 1
787 3
1904 2
1665 1
669 1
1034 4
1728 3
53 5
1089 6
492 3
1436 6
1569 5
1669 6
1588 6
1237 4
514 4
534 1
625 4
338 5
1327 2
733 6
796 4
887 6
1350 5
484 6
165 2
937 6
1593 6
131 2
1072 4
908 6
804 3
763 2
315 6
1255 6
1598 1
1932 5
614 2
1995 2
698 1
441 4
576 1
264 1
841 2
227 6
105 2
1404 5
7 1
545 3
1474 2
377 2
1319 3
1459 3
1868 5
694 1
405 4
652 6
327 4
1275 4
1989 5
1144 3
826 4
1938 1
872 6
1356 3
183 1
1485 3
1891 5
857 4
349 5
869 6
846 2
1571 4
1413 1
296 1
820 1
1866 4
1050 1
1283 1
636 6
979 2
1571 2
793 5
1760 4
662 1
388 5
1159 6
1268 5
1376 4
669 5
1021 2
8 1
1853 4
1356 5
138 5
1285 1
661 3
676 1
1537 2
1701 2
197 4
337 1
488 4
745 2
915 5
1679 5
661 5
1145 1
947 5
1699 2
1539 4
462 5
855 2
405 1
1701 4
1383 6
600 6
1939 5
1644 1
1323 2
163 5
399 1
1065 5
1531 1
883 3
96 6
752 4
53 4
957 6
703 6
607 3
1984 2
1674 3
1089 3
193 2
425 6
1615 4
582 3
918 6
286 1
1453 4
1187 1
1945 5
849 4
952 3
1367 6
29 4
807 5
1558 2
1448 2
1888 5
1279 3
435 2
36 6
922 3
1549 5
1552 3
1046 1
730 1
1734 4
1619 1
860 1
653 4
51 6
1493 2
1366 6
123 3
756 6
455 4
908 2
80 5
1292 1
814 2
1615 5
778 1
452 2
499 3
322 4
631 1
1619 3
781 5
1872 4
623 5
1398 6
139 4
978 3
783 6
170 3
1401 6
55 1
1275 4
400 1
1862 4
309 5
1796 4
178 5
1247 5
1972 3
1335 3
326 4
1536 3
386 3
1760 4
397 5
395 6
756 4
1498 2
1246 3
1769 3
1178 4
1492 5
1560 2
609 1
1638 5
606 6
363 3
410 2
1313 3
841 3
1381 6
262 6
1255 3
451 4
947 6
45 4
1383 6
1618 5
503 3
814 5
1714 5
1908 5
311 5
902 3
1566 2
1758 6
466 3
1980 2
555 1
998 6
1304 6
664 1
1298 1
862 3
177 3
795 4
520 4
821 6
1270 4
1117 3
766 6
370 2
603 3
1399 3
300 4
1271 5
707 5
149 1
1577 2
944 4
1255 5
1436 1
1744 2
1193 2
1283 3
1091 2
1585 3
508 1
1333 2
1148 2
226 5
836 2
594 5
107 6
541 2
1746 6
1424 3
396 2
1611 2
1623 3
809 2
1278 4
167 2
1782 4
1609 2
56 4
751 5
1430 5
1773 3
427 1
1310 1
1853 4
1941 4
1958 1
1928 3
1605 2
333 3
1852 3
1082 3
297 5
1326 3
199 3
944 5
344 3
1661 4
674 3
1596 2
389 5
505 4
1506 2
400 1
1868 5
559 6
1417 3
380 6
1578 3
1590 2
1356 1
1579 5
62 5
1866 5
797 4
1597 6
909 3
149 4
57 3
653 1
1485 1
1628 2
427 4
1701 2
1919 4
693 4
1006 4
1505 6
204 4
1141 1
775 1
1646 6
1919 4
1374 2
974 4
1241 6
909 2
314 2
1864 2
1916 4
1628 5
1089 4
470 5
123 1
35 5
1558 2
805 4
609 6
1305 2
544 2
1616 1
587 4
1809 5
415 4
1133 4
641 1
613 5
50 5
934 6
1775 1
1867 6
1184 6
271 5
195 4
1394 1
99 4
1133 5
1752 2
1222 6
137 5
727 3
371 5
634 3
701 5
199 2
643 5
1436 1
1211 3
1554 5
33 6
1979 5
1756 4
731 6
1852 1
613 6
1399 4
1577 2
1445 4
1109 3
1929 4
139 6
562 3
1324 6
1689 1
1801 4
68 2
369 2
1474 6
587 3
291 2
1171 4
672 6
475 4
715 5
523 6
492 2
1784 1
383 5
1085 6
579 5
968 3
1191 3
311 6
1144 5
482 6
484 3
593 3
778 3
1978 5
675 6
1705 6
1876 5
237 2
1874 3
384 3
1355 1
50 2
1868 3
1366 5
819 1
723 3
68 3
1381 2
351 5
1972 2
1007 3
235 1
1852 5
493 5
215 4
700 1
1523 1
735 3
707 4
1615 5
136 2
642 3
1927 6
974 3
551 4
15 5
1304 6
703 5
908 3
539 2
926 5
1888 1
1438 1
1885 2
605 3
66 4
1357 1
1936 3
571 2
24 2
415 1
1030 1
1616 1
138 6
1646 2
523 6
91 1
610 5
216 2
444 2
1517 1
1569 4
1479 6
1295 4
218 6
328 1
382 6
1500 5
374 5
1267 1
695 4
589 5
6 4
122 4
984 6
1806 2
1335 5
1925 6
1668 3
1231 5
757 4
1656 2
180 1
948 2
286 6
647 4
147 2
631 5
49 3
1200 3
956 3
1130 5
593 1
1278 6
709 1
1635 5
689 5
624 1
124 3
630 5
1286 6
1261 6
1044 2
403 2
246 3
757 3
16 3
1394 3
423 5
664 3
1991 3
461 6
134 6
514 3
1511 4
747 4
1700 3
1527 2
10 5
744 4
1447 3
1784 2
1237 3
944 6
1530 6
1353 3
463 1
415 6
1314 5
772 5
1434 3
1402 1
38 1
431 1
1746 2
491 2
349 2
768 4
1350 1
1145 6
775 6
795 1
147 1
516 4
134 1
789 1
779 2
460 3
338 3
255 6
143 3
617 5
1101 5
538 1
473 3
1120 4
711 1
192 1
1893 4
787 1
406 1
189 2
494 5
555 5
1582 5
1791 4
262 3
1510 3
1347 4
842 1
1284 6
720 5
1599 2
1579 3
108 1
1618 4
1291 5
507 2
966 5
1382 6
1273 1
1763 2
898 2
473 1
531 4
1561 2
519 2
708 4
657 3
739 5
626 4
956 4
258 3
1813 1
1927 6
1309 3
388 5
518 4
1991 4
1408 4
1545 2
1813 5
1630 6
330 5
1284 5
1625 1
1109 6
1231 3
1049 1
1241 2
843 6
747 5
1354 3
520 4
1914 3
713 2
1076 6
841 2
1220 5
1350 4
1195 3
525 4
1066 2
721 4
337 3
156 4
265 1
667 1
1505 6
1107 3
234 3
1428 1
339 6
978 5
1819 4
923 1
103 4
21 5
1453 2
985 3
1325 4
1844 5
1534 6
355 3
1496 5
395 3
960 1
628 2
521 6
474 1
899 4
1940 4
998 3
4 3
371 1
787 3
19 1
1686 3
1359 1
733 5
1606 5
986 5
746 3
122 4
1257 5
1072 5
700 4
506 3
801 5
1478 1
482 3
1326 5
951 1
1369 5
233 4
1655 6
1379 2
1554 4
1808 6
143 1
106 2
677 4
1562 6
827 3
267 6
1985 2
41 4
1935 1
1477 3
13 3
539 2
1980 1
1479 4
1994 1
894 6
888 4
1204 2
689 5
1911 2
1263 2
720 6
1786 5
1135 3
1018 1
1010 3
1031 4
640 3
867 2
901 3
751 2
743 6
1874 4
1864 5
722 1
583 3
1262 6
749 5
988 4
560 3
1409 4
1586 4
1682 3
385 1
32 1
749 2
1764 1
322 6
1193 5
342 3
1593 4
684 2
1792 5
1695 6
1194 4
415 6
35 1
171 2
975 1
581 3
906 3
11 2
1602 3
1996 6
1627 3
25 4
198 2
1979 2
1584 2
1165 4
337 4
638 2
1326 1
1422 5
851 4
326 1
1374 6
722 6
1182 1
1177 2
49 6
924 4
1790 4
128 1
1026 3
699 6
1224 6
202 2
699 2
551 1
1585 4
966 6
477 4
1338 1
1129 3
803 6
1453 4
1505 5
1507 3
523 5
1254 2
994 4
811 3
1890 1
846 4
551 1
1173 6
975 2
1449 6
1776 2
773 6
945 4
1696 5
520 5
1567 4
434 1
758 6
1413 6
316 6
45 6
1631 5
1336 3
887 6
1723 1
998 1
217 5
1116 4
1886 5
1109 5
1089 2
78 6
1632 4
1892 4
919 1
1870 5
1691 6
1165 3
764 5
673 3
29 6
946 2
320 3
731 6
1256 4
1990 2
1048 2
1051 6
1237 3
1373 3
262 2
504 5
628 1
1193 1
998 6
1016 5
412 5
1928 1
120 3
229 3
1233 5
1950 2
561 2
1674 6
631 6
138 5
1478 5
1670 3
1146 6
658 5
1541 4
145 5
1911 2
1014 2
1682 1
1000 3
1112 3
1838 2
221 1
91 2
1187 2
1341 3
1270 3
591 6
1773 4
1084 4
849 3
1686 5
1654 3
869 4
90 3
1369 4
1842 6
840 5
1619 4
978 1
1995 6
885 4
293 3
1621 4
859 1
53 5
467 6
46 5
44 2
1894 5
84 6
1730 1
1645 2
298 6
1359 4
1626 5
1115 3
302 6
1281 6
364 4
667 4
65 4
1233 6
1824 1
805 5
880 6
497 5
1778 3
101 6
97 4
1577 2
834 5
1655 1
53 4
405 5
1736 4
1880 4
731 1
482 3
428 4
1263 4
901 4
998 6
1067 6
861 3
1747 3
646 3
317 2
1371 5
484 2
282 5
1030 3
1583 6
839 6
573 4
1708 6
268 1
904 6
1307 3
1721 5
1288 1
388 4
1738 4
1535 1
831 4
682 1
944 1
655 3
1205 2
1306 6
620 5
502 4
145 4
575 3
1738 6
759 6
891 5
1155 4
1800 5
793 6
797 6
1436 6
1521 3
1307 2
206 6
1507 5
43 6
470 4
498 6
918 4
1265 5

*/

/*OUTPUT:
14
3
450
14
220
212
74
364
170
202
593
1085
2017
3562

*/