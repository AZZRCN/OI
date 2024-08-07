static unsigned long long JC(unsigned long long n) {
	unsigned long long ret = 1;
	for (unsigned long long i = 2; i <= n; i++)ret *= i;
	return ret;
}
static unsigned long long JC(unsigned long long from, unsigned long long to) {
	unsigned long long ret = 1;
	for (unsigned long long i = from; i <= to; i++) ret *= i;
	return ret;
}
static unsigned long long int C(unsigned long long UP, unsigned long long DOWN) {
	return JC(UP + 1, DOWN);
}
static unsigned long long int A(unsigned long long UP, unsigned long long DOWN) {
	return A(UP, DOWN)/JC(1,UP);
}