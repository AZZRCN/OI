#include <iostream>
#include <string>
using namespace std;
/*
void write(unsigned long long x) {
	static unsigned char sta[35];
	short top = 0;
	do {sta[top++] = x % 10, x /= 10;} while (x);
	while (top) putchar(sta[--top] ^ 0x30);  // 48 是 '0'
}
*/
void write(long long x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	static short sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
//template<typename T>
//void print(T O) {
//	printf("[");
//	for (auto K : O) { std::cout << K << ','; }
//	printf("IS_END]\n");
//}
//void print(bool _Val) {
//	if (_Val)printf("True");
//	else printf("False");
//}
//static void print(const bool& _Val) {
//	printf(_Val ? "True" : "False");
//}
void print(int n) {
	printf("%d", n);
};
static void print(const std::string& str) {
	printf("%s", str.c_str());
};
//SCANF
//C version
/*
static int read() {
	signed char w = 0;
	int n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 9) {
		if (!(ch ^ '-')) w = 1;
		ch = getchar();
	}
	while ((ch ^ '0') < 0xA) {
		//n = n * 10 + (ch ^ '0');
		n = n * 0xA + ch - 0x30;
		ch = getchar();
	}
	if (w) {
		//n--;
		//n ^= 0xFFFFFFFF;
		n = -n;
	}
	return n;
}
C ULL version
static unsigned long long read() {
	unsigned long long n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 9) {
		ch = getchar();
	}
	while ((ch ^ '0') < 0xA) {
		n = n * 0xA + ch - 0x30;
		ch = getchar();
	}
	return n;
}
C UI version
static unsigned int read() {
	unsigned int n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 0x9) {ch = getchar();}
	while ((ch ^ '0') < 0xA) {n = n * 0xA + ch - 0x30;ch = getchar();}return n;
}
*/
static void read(int& n) {
	signed char w = 0;
	n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 9) {
		if (not (ch ^ '-')) w = 1;
		ch = getchar();
	}
	while ((ch ^ '0') <= 0x9) {
		//n = n * 10 + (ch ^ '0');
		n = n * 0xA + ch - 0x30;
		ch = getchar();
	}
	if (w) {
		//n--;
		//n ^= 0xFFFFFFFF;
		n = -n;
	}
}
//inline void scanf(int& n) {
//	printf("\nPLEASE INPUT A NUMBER(abs <= 2147483647):");
//#ifdef color
//	SetConsoleTextAttribute(STDOUTHANDLE, 0x60);
//	scanf_s("%d", &n);//Positive and negative
//	SetConsoleTextAttribute(STDOUTHANDLE, 7);
//#else
//	scanf_s("%d", &n);//Positive and negative
//#endif
//};