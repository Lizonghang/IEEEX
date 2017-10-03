# Enter your code here. Read input from STDIN. Print output to STDOUT
T = input()
for t in xrange(T):
	N, K = map(int, raw_input().strip().split())
	w = []
	for i in xrange(N):
		w.append(int(input()))
	w.sort()
	d = []
	for i in xrange(1, N):
		d.append(w[i] - w[i - 1])
	d.sort()
	print sum(d[:N-K])