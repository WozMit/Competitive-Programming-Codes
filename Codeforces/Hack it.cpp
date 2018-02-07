#include <iostream>
#include <cmath>
using namespace std;
int astijan(int k)
{
	int a=1;
	while(k!=0)
	{
		a=a*2;
		k--;
	}
	return a;
}
int main()
{
	int a[30],i,k,j,m,n;
	cin>>n;
	for(i=1;i<20;i++)
		a[i]=(astijan(i)-1)*astijan(i-1);
	for(i=19;i>=1;i--)
		if(n%a[i]==0)
		{
			cout<<a[i]<<endl;
			return 0;
		}
		return 0;
}