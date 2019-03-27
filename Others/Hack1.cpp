#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long t, ans, b[999999], sum;
vector<long long> su;
int binarySearch(long long arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}
struct bla {
	int a, b;
}a[999999];
bool cmp(const bla &a, const bla &b) {
	if (a.a == b.a)
		return a.b < b.b;
	return a.a < b.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a[i].a;
		sum += a[i].a;
		a[i].b = i;
		b[i] = a[i].a;
	}
	sort(a, a + t, cmp);
	sort(b, b + t);
	for (int i = 0; i < t; i++) {
		if ((sum - a[i].a) % 2)
			continue;
		else {
		    int labush = b[i];
			b[i] = NULL;
			int laba = binarySearch(b, 0, t - 1, (sum - a[i].a) / 2);
			if (laba != -1) {
				ans++;
				su.push_back(a[i].b + 1);
			}
			b[i] = labush;
		}

	}
	cout << ans << endl;
	for (int i = 0; i < su.size(); i++) {
		printf("%lld%s", su[i], " ");
	}
	return 0;
}