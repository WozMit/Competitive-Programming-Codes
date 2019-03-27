from math import gcd;

num, den = 2, 1;
l = [];
it = 10010;
for k in range(it):
	coef = 1 if k == it -1 else 2;
	num, den = (num * coef + den) * den, den * num;
	g = gcd(num, den);
	num //= g;
	den //= g;
	num1, den1 = (num + den) * den, den * num
	g = gcd(num1, den1);
	if(len(str(num1//g)) > len(str(den1//g))):
		l.append(k + 2);
print(len(l));
print(l);