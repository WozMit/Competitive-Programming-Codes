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
		int n, a, p; scanf("%d %d %d", &n, &a, &p);
		printf("%d\n", (a + p - 2)%n + 1);
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*INPUT:
1000
8 6 10
3 2 4
60616 80947 18571
89400 8081 18097
41504 44024 32762
81913 36895 74858
94447 24454 15601
28244 88042 31759
24724 80227 14399
12468 3087 6968
25341 60869 81499
39271 80955 71304
24553 87542 96594
58040 70954 67171
29591 30814 5020
5680 76365 28242
99950 27398 17748
70265 11649 49360
98506 32922 31895
33417 90579 26533
76375 88998 23092
37806 65321 11780
9506 58701 2183
44147 44471 24648
74310 31670 97371
22424 75526 99875
10379 60918 73822
77978 65539 95578
72109 60879 51901
84055 25892 27317
78370 70328 97095
39838 74643 31060
49791 60777 206
51822 41360 42017
75328 71445 94673
45060 19496 35337
56984 54115 68150
64488 74888 23299
18201 79458 68640
55345 16304 76440
35899 31275 65380
73654 79692 33001
73833 95755 49130
79367 47942 47718
26085 6865 71883
12662 5352 6745
51219 66362 74432
47069 22414 41951
21687 45562 610
63478 31530 95209
22321 11599 52383
47276 81790 81959
33025 49042 36017
97183 41160 63
74955 49506 94887
5773 83025 48329
70665 26198 84084
59277 65553 65557
13255 31288 89464
50940 61825 10104
30808 38100 67669
71512 18365 79885
13230 90769 3533
97163 81800 54292
38547 39927 11780
63048 82203 25440
19462 65639 45600
77869 56654 93040
74907 84441 84695
46477 37118 1851
98191 24528 8281
85478 77578 92334
99345 71418 89650
40950 44617 60782
79939 64805 63886
89723 36797 65374
97992 3183 12701
23297 779 56691
3689 52779 20513
58714 32 40601
31382 85190 83568
4749 2946 83541
72414 97813 25293
86182 39212 52402
23936 81966 57509
40497 73761 1302
70180 42295 77541
46575 43588 63548
66189 93655 93598
71676 13365 34800
38279 17569 79525
56283 2850 97861
20921 7054 2619
11261 33477 87709
1273 36327 13339
7190 34874 73994
65678 24864 38067
91727 31214 96986
56691 158 93871
19057 63250 65760
45576 80593 83622
44039 75882 87855
59886 65170 13751
95506 90531 60845
43328 3397 92964
34412 60010 48443
77819 68287 27074
13063 69507 36089
21344 75487 53809
1826 54151 21300
56691 44306 54874
46788 55876 89785
14750 47256 6734
25688 16431 5184
77018 94455 28163
42685 58303 68070
84449 78936 53819
52890 81923 46776
87776 70165 95563
50635 15840 65964
98577 14076 97256
30166 93801 62553
18183 57972 85452
24901 11249 46010
28578 80920 23175
45632 52290 87155
33480 47916 51206
43973 32883 52848
29931 85166 30379
91888 40994 5778
16569 56548 5746
67590 88544 93278
34883 87736 86046
73920 98901 69852
30386 86292 7259
54425 22065 7868
62045 26228 3891
35037 61757 15992
65080 45979 2934
78363 52016 62515
35803 96817 2180
92058 75157 52910
3365 36661 62786
86075 88929 9926
45403 29779 81939
97420 79336 38176
71845 40768 18070
5418 75248 20498
77173 7248 69096
71463 35405 96348
79921 1088 80589
5284 91426 17422
25937 94324 58634
9076 3397 9458
87827 57990 62919
66159 29782 38578
72970 91775 89374
51024 22317 7404
45917 1096 701
76180 90147 29080
74048 58965 86418
93858 47161 95538
63544 1943 69513
42138 90336 452
68557 78782 22078
10663 10342 33022
10559 17197 86644
2964 70451 45179
85497 85370 67496
6537 33444 4029
10064 32159 78291
19254 60704 44628
28546 88515 12916
64219 76473 53774
28190 61498 7483
60773 99175 82918
15018 39293 62061
45183 87787 89597
2965 49352 86034
51923 39322 23790
79769 41123 15998
99936 27859 52170
33511 53424 72552
34629 16410 33588
87550 37869 42437
40668 7227 66878
83212 3315 73793
42157 21102 38115
27604 53625 35665
70698 7736 17452
38837 6962 60162
34139 18051 5949
9947 7695 85485
34925 97721 50185
93245 75707 5717
31320 35420 16188
97807 71447 23063
14658 19587 18429
14029 56860 28654
9798 96919 75676
93398 32357 5376
78643 25453 38540
66492 58565 89857
74883 84777 26953
82002 50188 7678
21976 42827 7890
41050 57966 18296
6985 54874 71813
47854 18406 61344
63425 74093 92671
34506 37929 85731
35247 52474 55030
18243 36867 51168
58203 37977 9417
23366 22509 21238
21957 61503 23690
88419 86024 56390
67929 23175 36197
25155 75215 25975
28589 83543 6680
20770 35985 26617
38899 3903 23890
83828 12707 21245
82283 87363 80063
38873 85329 1767
8048 64837 72124
69539 91409 21314
71095 60603 25325
26246 31691 97857
20006 42447 13570
46608 50217 29718
54179 33586 72983
44457 42945 30077
81528 35947 78194
77173 16108 8496
16596 90857 74388
97157 67219 36654
65968 85429 81037
58041 41032 13345
95972 78169 56799
55265 17094 99943
90941 72329 43003
47485 23093 90660
73615 43965 10616
63011 46565 96970
17523 80637 97696
23614 90065 49824
30951 1749 33408
19118 34701 53664
42232 89564 25116
15507 56009 44326
31847 57214 81402
21385 98426 76891
3886 25965 57587
15239 796 37204
12882 39853 90160
11396 90911 1545
56321 63021 94513
60716 23174 68431
85293 81477 83047
19694 40037 11545
557 72272 60176
33869 8353 58818
83634 4122 47629
25669 97183 80744
59795 9886 36978
20648 75186 4948
34132 93837 6299
37427 94569 53518
30326 36683 70172
32706 55022 6313
90428 11408 80555
87996 39135 98179
93429 91618 81062
81694 40725 5907
11510 63767 31363
94183 31329 2759
39199 14206 5376
84500 28897 11023
72292 49032 97064
66155 88895 3506
58726 25713 95135
31174 23130 29951
18893 68855 15200
10677 72488 71228
59900 16463 12315
45217 59276 21972
52569 23050 71205
89814 84722 12494
53311 53998 13573
84856 24486 16218
69599 2258 60895
71855 67401 49843
74674 34879 44030
39142 85353 53520
39834 15278 51215
83723 91508 938
42097 44763 496
21307 12024 87536
31069 25286 46567
80093 88249 62422
97595 14121 7473
86947 11604 2199
92906 2694 94858
67270 17028 91776
99530 53938 33849
77888 82173 6995
93977 68948 15215
26437 76559 71432
57399 62012 31539
8975 51606 81251
69155 95461 68498
5316 95861 79079
35658 45194 66479
40271 10593 6098
23646 79115 80256
58172 29397 66273
3248 33738 12687
55162 22641 99800
44679 730 85228
44104 65106 10988
636 6859 6220
1115 30065 27657
18104 46737 89176
21938 38733 18289
83988 36755 1926
62926 6450 86804
30841 60139 30276
30701 57964 85935
15431 66551 38293
57544 18374 4941
15664 17410 22922
55549 23218 90887
44797 7949 64736
88381 97803 88860
1444 86826 37929
80751 31834 73336
66217 92258 3482
33123 48391 2439
90289 38164 58378
49985 32660 7391
74994 17224 50538
89169 33235 57691
95676 96306 1529
90274 40451 69097
85667 99472 15319
54463 30078 80927
21481 87408 54405
39113 94116 44620
84628 70337 42668
6358 29617 37204
72584 59079 19436
13112 57813 87112
46950 70673 9978
35311 96792 36851
66381 74043 84264
75342 58760 87951
81756 42980 30521
68619 10597 38734
1032 586 31673
25286 4374 23222
38451 53090 90914
48143 84998 48955
38365 33177 11373
83157 37049 14367
64661 21970 68553
32942 94272 52653
33266 8443 80723
57943 53309 65075
80681 30136 9593
50942 78905 42838
34297 61765 85728
48190 44918 71344
31217 79193 26344
34707 66322 32735
89259 96383 5732
34802 46951 41222
91911 6012 21672
52796 14275 16473
42701 59278 75409
85608 55846 52403
61349 22560 5517
73022 38911 2535
93658 47562 89203
46399 96084 48977
59229 24825 51822
70140 6506 22448
81886 63842 43741
81443 46964 25796
64071 97739 61308
92433 65103 4568
86263 27150 73958
48606 60429 59916
84967 46253 1479
68922 56050 19353
6197 69083 7087
68028 48695 62656
3706 36916 98420
40123 23034 38168
19298 72168 20667
29824 58798 46318
83117 61280 7473
11741 91124 4070
30387 68994 27315
42109 34907 67834
49325 88508 25304
29299 35512 64319
29923 51750 40139
24326 49191 95824
25755 55727 44603
59076 79275 76216
14912 45227 47254
13536 84038 66166
12012 84118 75689
61058 66913 32832
56776 81981 86926
17315 22306 65511
20311 79729 41109
22292 99445 32978
9229 83613 35635
54076 82108 49929
38128 30392 3253
57864 26295 36553
3018 13374 62611
43942 95353 20122
69518 55304 97079
88943 47361 51234
78529 83893 99044
6213 35458 71351
467 74016 26011
15827 25899 68708
33353 64860 77889
33812 45737 8181
79938 68079 58945
88802 18934 77871
97728 60535 61081
10981 2114 49448
14665 28297 8542
14693 67747 15302
37586 64726 25274
43042 27390 92706
65681 66316 66973
83898 84992 8272
81739 40189 65305
93002 7961 11327
10597 75365 53453
50875 18718 11580
20029 97540 20235
1771 63266 49731
19893 94051 99604
69547 36251 80418
82841 92075 5685
52898 57895 55836
50795 53665 28096
65119 6778 56513
62353 48822 72645
1084 72088 65128
27203 92261 77132
86594 78917 47739
12651 27052 12076
51496 51725 89511
65059 35837 82477
85580 78344 36654
93599 21237 18006
45832 99329 16952
367 1979 36045
25718 75293 85370
10298 20574 70006
51792 30737 88165
83758 84708 97533
27559 97555 12743
71780 14528 84880
18340 86697 15389
85362 67622 61466
25561 96064 87854
13364 106 51708
84669 23129 30973
47155 26107 43233
81675 85114 56196
92137 80901 26989
5166 51066 89231
21986 18276 83604
28751 22902 39103
60322 36180 47599
46962 61694 12793
6066 23155 75729
73214 57725 14205
31892 85795 18204
3379 79924 83315
72884 77075 30855
44929 66463 93051
90882 83830 29461
34478 1144 88966
95780 19745 66197
40776 12172 32555
32523 46699 85924
87548 55907 74185
59449 3116 30140
85678 63717 10645
74687 66072 12236
46900 13928 65516
39292 50591 49718
14622 98633 97594
66109 25380 77656
38626 73645 17478
37624 15255 58018
28273 85421 19501
94829 10408 33703
42901 21749 82930
60385 11753 81538
22837 81489 44530
43743 48640 38488
59608 79008 99032
73777 26197 3475
38125 18037 8081
22106 92743 68014
36624 39994 91634
42167 60445 21530
78130 99057 90593
13746 73301 42856
53264 11365 60554
61018 78589 73921
8813 28938 65642
78184 10396 7228
68171 5735 17943
34626 1754 43431
46288 91053 57397
65126 61110 51464
63402 48682 6076
93659 21038 70123
24187 69629 24848
19817 29362 26013
51442 45756 68534
54992 36272 24021
44430 56887 14744
88264 3829 81618
41283 30958 53828
25219 42167 77853
67857 71162 25077
99502 19735 6215
4456 91799 95645
9340 37912 21378
91885 51377 44220
18943 33429 28469
61913 79806 62779
48326 6551 40172
64071 70854 79767
43382 33247 80422
77184 99720 56688
21293 55504 59865
94121 91761 78224
71597 48859 1078
53821 51777 9829
57408 47906 48537
54104 38364 94766
7251 38373 65785
57277 64869 92505
47364 8597 79621
23331 71566 26667
29110 53051 77694
57045 9416 4292
69719 64568 26838
75283 53741 43473
77704 62847 41300
442 67416 51085
32287 64203 94582
75280 65259 67135
4253 74203 33381
70323 91950 79213
64054 63144 45556
17861 27219 89862
36610 47981 95475
23537 67807 66903
94678 89619 77200
58198 39878 96580
91548 82863 52058
6181 15981 93359
56402 4125 72187
96409 16417 35500
1679 25536 93553
38224 19868 65119
68691 6833 46852
3706 78186 55227
26174 53498 35166
92396 28195 98055
21896 82161 83133
19035 91733 87658
78716 27557 43830
10828 46735 50293
17103 64279 62453
81560 91057 30131
82320 31793 56946
77482 86047 57737
13916 32858 49762
43635 86928 27173
9377 7045 21466
23513 11917 76699
96076 81638 28185
20236 98493 21089
38413 27663 77248
11002 3873 86186
74445 93951 362
91860 56953 68538
16632 51324 22432
32104 35426 9174
85868 73173 63354
81778 91494 50845
64246 36337 52050
17844 87551 6770
66601 58534 6515
70190 90318 62576
56238 40478 2884
63564 47804 95813
38297 96462 50838
11551 76118 81323
88185 1472 17617
33159 81668 23814
59384 57146 67909
37192 11825 88287
96147 25232 56876
99643 87344 78267
32716 53853 4998
19995 43124 95388
31531 40931 14885
13010 91243 79001
29816 81300 35674
53374 5990 2789
48690 35578 43721
69656 17680 89886
95736 92432 17671
43066 9483 46347
29937 91764 18843
41733 47812 24951
31955 55128 56934
69021 63039 85359
61355 23045 18281
86796 84829 8086
81641 8717 35077
97183 29157 97723
18393 47932 21050
25819 38705 41483
62447 70235 2945
91179 74834 59864
82306 52648 68061
56020 13684 56134
89128 85804 22710
73719 46765 7117
65482 52391 84074
87868 37419 98374
78288 69087 47482
83356 40627 54221
40951 37674 21406
20792 14519 30257
4202 83652 92194
59841 45065 77865
75190 13427 45571
70389 4103 31333
30765 17006 92032
1957 35811 75150
95029 62464 68243
16692 61988 49045
99036 7978 25015
25280 58098 82891
69213 90175 68002
21605 84351 43509
45309 82534 51673
26164 60329 1984
25162 54446 3052
14918 61728 78368
5803 84409 84551
5457 42628 39004
32002 82945 63011
94050 14647 83469
45968 6580 91397
62104 32473 4234
3521 86881 98090
34086 92448 79356
14048 49624 38885
27965 44520 79811
71413 7068 12307
52949 3974 66267
57772 59218 44806
7889 40682 31084
48360 3170 66253
76190 10969 56523
23810 21351 15736
12134 7343 42857
54489 53119 32489
6947 43717 82921
71585 7095 29308
61088 4232 5937
7708 57915 75193
79718 1851 7327
5089 66005 6394
35698 23722 79783
49910 52584 59704
43823 96287 42069
50384 22264 47048
42630 48732 3615
43202 79991 269
56615 89872 92035
90065 69230 80057
33280 81977 24225
13250 73647 97221
77801 1797 78500
36187 38196 35748
47051 8844 71638
94340 21852 1905
59009 49904 99884
90334 61405 13767
51028 91491 41319
82916 66224 98179
47543 48260 53396
78747 4896 35137
61095 2598 46341
92764 72960 9758
11622 52130 48099
61678 82745 92516
64905 19472 77287
93165 72326 82321
18204 3529 22438
26579 60095 43823
20319 8375 16564
3999 58175 89616
13502 30769 33982
63744 68510 54912
97794 20897 96735
74787 49900 33917
79136 11873 50507
7201 16090 24006
81435 56154 80784
41507 26923 22979
19299 16155 56260
51439 93158 70248
50276 98816 73389
79198 65540 21320
31945 89933 23646
49629 40512 69533
29946 36483 60355
3536 93174 77583
75785 37476 13293
57150 75000 83522
1335 78898 27138
56605 62189 21608
80533 18858 32385
94934 68755 96998
87256 30781 702
32022 58442 14761
37909 83409 22108
88645 29524 45110
44231 49059 90502
70943 3105 75086
51843 49684 57458
14603 53158 67554
88111 18749 177
75881 51803 24744
56920 21499 81952
74497 29357 30365
49415 49204 85971
77026 64861 17498
34439 39964 39422
10106 3838 48539
52520 96421 57955
99363 38372 86217
430 6750 94157
13067 14043 13426
35653 52988 76899
39794 41255 49023
57490 78400 34436
86669 90185 54160
973 67360 35875
41023 39510 89590
90790 29296 97524
74445 20398 75977
59312 36731 76950
49580 65284 25027
73682 82033 12197
63463 11188 7901
6707 79852 38605
30607 65250 86775
7054 84259 32943
60327 72062 87276
96689 34711 5533
74867 30702 14321
45170 8608 33973
51649 79794 6172
54846 92390 85489
99867 67779 79294
5508 45874 29688
72313 13124 85409
12888 73827 38576
35436 21131 41622
66808 36050 39297
27536 9952 88756
65685 76780 6416
6991 58052 84275
3870 96223 48928
50591 97016 26539
43726 68689 22401
50231 17000 42430
64326 16294 76020
90163 95912 20829
50721 49449 39799
10254 4704 93443
7703 85459 31720
60539 83567 9358
73317 86833 32321
8737 33440 2534
51671 50693 37443
57923 95813 5204
32774 35726 93901
44375 70252 54559
34110 54488 78172
18700 57478 54564
56459 59010 9031
2672 44245 13619
1006 7307 1840
65608 95356 29345
99913 71983 86878
58380 67296 75146
84966 80918 44901
41330 85151 44880
53230 29746 42051
22255 55309 90608
14712 25282 21722
49738 68402 98959
59838 20347 63127
88723 608 96048
61771 20238 5493
76340 18488 72272
40594 87384 83769
89345 93091 21060
85327 34565 23441
18966 39003 69910
98443 15973 84
76685 55945 46715
21342 91608 24666
46674 39299 4731
41383 3728 12664
33526 60728 11572
40206 66255 22736
3239 10281 54957
21374 60528 12717
43924 71038 67433
47373 60359 59468
78965 64164 67736
35053 77404 60904
33312 60167 50151
93647 48374 3234
40400 77630 84981
26146 22944 23302
82897 8454 75659
91120 35258 49043
2246 59585 61917
26199 35332 17024
26010 27377 91724
34758 93262 82967
22712 57247 82030
31945 28371 78965
7481 62517 58941
55293 42358 35064
19708 59255 2318
60971 47170 91491
3600 33193 14288
76497 82080 59961
78123 12849 3316
58915 49000 97964
77316 87403 23190
73994 86962 6337
99296 71210 41559
39723 15689 10259
91797 96155 19581
18061 5582 16626
17443 89134 25689
29719 19936 8924
38449 81821 21738
20602 90165 43849
65417 53344 3015
2482 31435 89512
19793 26690 74090
12970 7945 49695
2211 24904 63920
94333 76665 81785
76622 8080 52740
20774 82623 96573
70345 33407 74001
81403 82727 51001
77644 56687 10064
17993 46145 81805
85502 44900 20302
39498 63008 60691
1245 10848 28441
12544 15161 46145
81212 61680 64841
37760 49681 64296
8009 73893 63650
55638 79448 35766
51617 89801 49166
13035 85349 6934
4814 70073 82269
16912 7578 55484
89769 64967 43005
46107 37647 41949
26110 90565 55056
61798 9289 18629
20761 48271 20755
65080 94128 87353
77696 9471 85275
2082 97106 97711
76179 13972 39357
19251 98430 97537
18649 34078 76659
11221 77501 17013
31575 76249 2934
55019 68497 44717
61688 7857 46231
74396 54077 94297
65287 88607 93437
20626 59883 5894
13459 69504 73227
43005 60450 68782
54264 55834 34327
16057 46079 67486
50175 60324 97365
31562 77564 49592
68857 61531 93758
3750 995 60485
61626 4762 54520
33474 4074 6444
89255 54109 34860
95287 67333 73932
7403 38130 42078
34063 19293 5670
40255 79760 85560
27187 46025 56044
2683 88405 19409
12229 9709 87301
52898 23644 28089
94455 61083 16167
69098 76171 48756
89868 99390 39908
35071 25000 67179
30268 9040 74149
64485 95282 20177
60850 34439 99385
9843 88230 1021
67203 86931 13863
48191 99614 49629
79155 40135 89522
22957 14120 48444
63609 52545 36774
4047 18491 22875
87821 39342 70577
68948 99604 50394
49824 49253 61558
36852 24446 76848
72376 17915 70601
35670 8226 18055
42819 5222 77725
11244 60508 69110
70005 71903 38102
63649 55680 65267
16445 60761 46171
86919 73073 76753
44150 9198 42748
17066 88867 48468
63580 2740 18079
35987 69136 28904
93333 16266 56671
96814 33794 50918
6309 65110 81587
44258 37697 20358
13448 51769 66979
26915 8952 67469
35480 52278 5879
73986 13617 43430
62856 20858 84938
98940 12233 59974
8133 98330 22571
10203 69846 2143
30039 39839 73855
94422 18869 28500
758 58762 1595
93010 7829 40916
25751 51767 32183
97833 27175 98806
51093 35151 42279
84064 74231 37713
14626 74807 10132
42625 50175 78762
77867 37685 99814
47358 6356 60461
8554 66281 29757
66765 30409 67713
71437 20622 14456
83353 99882 21986
42040 13914 37889
50932 460 43132
74260 9042 71371
47776 66881 51413

*/

/*OUTPUT:
7
2
38901
26177
35281
29839
40054
6824
20453
10054
15662
34445
12264
22044
6242
2366
45145
61008
64816
16860
35714
1488
3847
24971
54730
18432
10191
5160
40670
53208
10682
26026
11191
31554
15461
9772
8296
33698
2489
37398
24856
39038
71051
16292
492
12096
38355
17295
2797
63260
19339
21920
19008
41222
69437
4347
39616
12555
1456
20988
13344
26737
1691
38928
13159
44594
13928
71824
19321
38968
32808
84433
61722
23498
48751
12447
15883
10875
3200
40632
11847
1004
50691
5431
19794
34565
49655
13985
54874
48164
20535
44427
9672
8575
18
1017
62930
36472
37337
14667
27486
31619
19034
55869
9704
5216
17541
1091
1231
584
42488
5296
9739
21614
45599
41002
48305
22918
77951
31168
12754
5523
16142
7456
18360
2548
32161
41757
25751
46771
12586
46641
34249
20912
2392
29932
30118
7674
48912
36167
27390
36008
1861
12779
20911
20091
58837
3639
76343
60289
1755
3167
23272
3778
33081
2200
35208
29720
1796
43046
71334
48840
7911
6511
32302
711
8809
33
67368
4787
9809
9061
15792
1808
12600
60546
11245
41834
1960
11188
57120
80028
25442
15368
80305
33436
77107
17059
6477
25187
28286
23999
3656
8205
81423
20287
94509
8699
1339
6028
37732
63992
15437
36846
57865
6764
35211
956
31895
39913
20141
1762
15062
47393
20380
19321
53994
59371
569
4455
291
27792
33951
2859
9349
144
43183
14832
24563
16004
33326
52389
28564
32612
24603
15880
6715
34529
54376
38995
6506
24390
18782
54580
17512
3102
21818
4205
11892
30215
7292
11227
4236
1945
7521
1192
1287
44891
30888
79230
12193
438
33301
51750
23912
46863
18189
31871
35805
15876
28628
1534
49317
79250
46631
3049
34087
19581
39919
1511
26245
3395
21906
8482
4914
28777
36030
41685
7401
14259
40703
63152
45388
4234
21446
26658
8722
3161
14331
9714
70577
21593
13802
4645
41533
87786
11279
84162
15805
36151
7206
25648
4827
4698
16690
17494
37497
952
12116
41278
31989
358
856
9184
13145
38680
30327
28732
21094
12257
23314
9003
3006
27887
9900
570
24418
29522
17706
6252
40050
67761
1756
2158
19273
29123
2078
12926
21396
28376
3240
5930
692
33700
27709
25544
71368
73500
49330
266
2309
28650
37666
6184
51415
25861
15156
22633
2497
39728
19858
10304
19881
11885
29642
12855
18568
27683
30747
6583
22640
28076
41445
43106
5863
17417
28953
25696
72759
30904
69670
14844
23132
47731
6480
1805
43322
1919
21078
15642
15643
68752
1265
5147
18522
15161
11933
2119
23384
23064
37338
3008
1307
3650
38686
55354
1241
19282
20962
8499
23884
33644
4983
534
27590
13346
9651
25878
1187
88
15471
9336
20105
47085
8002
23887
7637
7508
9583
14827
34011
1926
9365
23754
19287
1653
30297
17629
1423
14617
47121
14918
7934
30965
63290
59113
631
6174
40061
1174
38243
53254
29417
39242
24616
222
6354
8195
15317
14724
61
27627
10385
43725
4990
11721
54101
22184
59634
15752
814
13935
4502
23456
27524
1827
71929
8322
1046
35045
24726
22408
21153
85941
3950
2530
42543
33255
74361
3620
32543
21724
6140
36926
13870
35648
20102
44110
18876
32905
11833
43384
58823
29671
26117
6014
21755
39807
33389
6188
18654
30473
6449
17623
23677
10558
9585
47447
54757
91160
21915
15740
11405
5300
27200
85446
2219
19143
28381
25949
291
3249
3711
5068
18758
46722
22478
26904
2039
8903
75863
49936
7784
39034
24921
2643
42819
40853
4908
14304
13707
21686
21930
26442
44
29636
57113
1258
30516
44645
9914
33625
17024
72140
20061
43372
4262
19909
51916
1558
8538
53684
3702
10141
33853
12021
8075
71386
10403
7010
39627
6418
66301
13039
26830
379
18076
13746
18401
28084
2042
19867
33630
7227
12495
50658
60560
24140
5100
65048
12513
43361
16488
32408
7277
19088
6004
6286
25727
82107
65967
26134
18541
24284
1113
27525
8778
30608
37909
14366
12763
20795
31029
16196
10355
41325
6118
43793
29696
13802
2730
10732
43518
38402
13797
19385
53881
5500
47924
38280
11491
18128
3191
3563
3247
58997
35435
16742
1368
35677
10880
32992
14588
19750
19834
43588
9984
7173
5833
672
5233
17947
4065
6040
36706
1878
1373
4220
12470
19374
17291
46251
764
21062
67491
13276
1663
31118
1591
36402
10168
2071
9177
1152
32108
12467
6886
18927
9716
37057
12061
59221
6361
11867
2495
1569
33430
23756
31769
75171
30753
81486
6569
40032
48938
82717
7252
51904
31853
61481
7762
24180
4619
3826
10742
59677
19837
9029
62379
4090
55502
8394
14517
9088
21376
7661
17743
10786
6999
1028
50768
44221
570
27191
51242
70818
31482
9158
29698
74633
6867
7247
3455
3887
18925
665
46530
59721
36344
5332
10507
1846
49335
25225
286
1334
22927
10689
55345
57675
96
6030
36029
21929
54368
40730
20547
19088
4437
29596
4337
38683
40243
45022
42580
34316
13340
47205
3957
26219
9298
27316
8538
16099
17510
2506
1960
22372
3637
9198
27987
26577
38526
5860
1633
32385
45836
1025
36464
43093
31304
36060
30329
18541
11581
1751
92
59092
58947
25681
40852
6040
18566
12386
2867
18146
23635
7932
25730
14419
8776
24805
58005
14082
16056
25974
9563
44029
16391
5247
8578
457
9122
6698
25080
52934
33148
10381
51607
1010
20099
1215
84300
217
26156
15060
2438
3004
11500
1761
22128
2448
16718
680
65543
16164
29133
33276
19304
13472
25947
23938
4146
10164
28859
26660
10401
56358
1810
1814
5759
383
64116
60819
13003
37062
52324
66750
1998
65201
5204
693
11129
45308
696
1389
3937
35732
1037
3107
12325
18202
33488
15070
27917
6742
51320
17049
1190
53328
3456
17491
4745
16032
3175
54087
73977
51469
3898
8140
216
35896
1165
7163
907
17574
1479
59281
10517
88968
45977
6177
24962
4299
20507
493
11406
51732
77249
55828
49429
22036
22652
50973
12123
663
33590
4669
50501
16649
25709
895
22097
12101
11162
27589
16139
26280
40127
5933
39999
57297
8261
62906
7795
806
20818
26065
72936
84711
1589
13796
11163
22590
22676
57046
42939
72206
7038
567
23576
47368
474
48744
6696
28147
26336
27879
11808
1061
59631
19458
1943
31356
35077
38514
9762
43591
6152
22741

*/