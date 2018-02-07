#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
using namespace std;
struct vertex{
	double x, y;
	vertex(){}
	vertex(double px, double py){
		x = px;
		y = py;
	}
	bool operator ==(vertex v) const{ return x == v.x && y == v.y; }
	bool operator !=(vertex v) const{ return !(vertex(x, y) == v); }
	bool operator <(vertex v) const{ return x < v.x; }
};
struct edge{
	vertex start, end;
	double w;
	edge(){}
	edge(vertex a, vertex b){
		start = a;
		end = b;
		w = hypot(abs(a.x-b.x), abs(a.y-b.y));
	}
	bool operator ==(edge e) const{ return start == e.start && end == e.end; }
	bool operator !=(edge e) const{ return !(edge(start, end) == e); }
	bool operator <(edge e) const{ return w < e.w; }
	bool operator >(edge e) const{ return w > e.w; }
	bool operator <=(edge e) const{
		edge a = edge(start, end);
		return a < e || a == e;
	}
	bool operator >=(edge e) const{
		edge a = edge(start, end);
		return a > e || a == e;
	}
};
set<edge> E;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
	}
	vertex a = vertex(0, 0), b = vertex(1, 0), c = vertex(0, 1);
	edge e = edge(a, b), f = edge(a, c), g = edge(c, b);
	E.insert(e);
	E.insert(f);
	E.insert(g);
	cout << (a == c) << endl;
	cout << "# elementos: " << E.size() << endl;
	return 0;
}