f = [0]*1001
f[0] = 1
for i in range(1, 1001): f[i] = i*f[i-1];

for _ in range(int(input())):
	n = int(input());
	gg, fn = 0, f[n];
	while(fn > 0):
		gg += fn%10;
		fn //= 10;
	print(gg);