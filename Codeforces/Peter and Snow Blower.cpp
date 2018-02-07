//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;

struct Point{
    double x, y;
    Point(double px = 0, double py = 0): x(px), y(py){}
    void Read(){ scanf("%lf %lf", &x, &y); }
    Point operator -(const Point &b) const{ return Point(x-b.x, y-b.y); }
    double Dist() const{ return sqrt(x*x + y*y); }
};

const double PI = 2*acos(0), EPS = 1e-9;
const int MAX = 100003;
Point O, P[MAX];
int n;

int Sgn(const double &x){ return x < -EPS ? -1:x>EPS; }

double Dot(const Point &a, const Point &b){ return a.x*b.x + a.y*b.y; }

double Det(const Point &a, const Point &b){ return a.x*b.y - a.y*b.x; }

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
    while(scanf("%d", &n) == 1){
        O.Read();
        for(int i=0; i<n; i++) P[i].Read();
        P[n] = P[0];
        double mins = 1e100, maxs = 0;
        for(int i=0; i<n; i++){
            mins = min(mins, (P[i]-O).Dist());
            maxs = max(maxs, (P[i]-O).Dist());
            if(Sgn(Dot(O - P[i], P[i + 1] - P[i])) >=0 && Sgn(Dot(O - P[i + 1], P[i] - P[i + 1])) >= 0)
                mins = min(mins, fabs(Det(P[i + 1] - P[i], O - P[i]) / (P[i] - P[i + 1]).Dist()));
        }
        printf("%.15f\n", PI*(maxs*maxs - mins*mins));
    }
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}