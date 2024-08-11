#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1e5;
const int siz = 8;
const long long MOD = 1e8;//1e sizѹλ��Ҫȡ��ģ��

char ch1[MAXN], ch2[MAXN];
bool f1, f2, f;
long long n;
long long a[MAXN >> 2], b[MAXN >> 2], s[MAXN >> 2];
long long cp[MAXN >> 2], lt[MAXN >> 2], wsd[MAXN >> 2];

void write(long long num[]);//�������
void clear(long long num[]);//���ú���
void ry(long long num[]);//>>����������
void ly(long long num[]);//<<����������
void cpy(long long num1[], long long num2[]);//���ƺ���
int cmp(long long num1[], long long num2[]);//�ȽϺ���
void pls(long long a[], long long b[]);//plus�ӷ�����
void mnu(long long a[], long long b[]);//minus��������
void mul(long long a[], long long b[]);//multiply�˷�����
void div(long long a[], long long b[]);//divided��������

void write(long long num[])
{
	if (f) putchar('-'), f = 0;
	printf("%lld", num[num[0]]);
	for (int i = num[0] - 1; i; --i) printf("%08lld", num[i]);
	puts("");
}

void clear(long long num[])
{
	for (int i = num[0]; i; --i) num[i] = 0;
	num[0] = 1;
}

void ry(long long num[])
{
	for (int i = num[0]; i; --i) {
		if ((num[i] & 1) && i > 1) num[i - 1] += MOD;
		num[i] >>= 1;
	}if (!num[num[0]] && num[0] > 1) --num[0];
}

void ly(long long num[])
{
	++num[0];
	for (int i = 1; i <= num[0]; ++i) {
		num[i] <<= 1;
		if (num[i - 1] >= MOD) num[i - 1] -= MOD, ++num[i];
	}if (!num[num[0]] && num[0] > 1) --num[0];
	return;
}

void cpy(long long num1[], long long num2[])
{
	for (int i = num1[0]; i > num2[0]; --i) num1[i] = 0;
	for (int i = 0; i <= num2[0]; ++i) num1[i] = num2[i];
}

int cmp(long long num1[], long long num2[])
{
	if (num1[0] > num2[0]) return 1;
	if (num1[0] < num2[0]) return -1;
	for (int i = num1[0]; i; --i) {
		if (num1[i] > num2[i]) return 1;
		if (num1[i] < num2[i]) return -1;
	}return 0;
}

void init()
{
	scanf("%s%s", ch1, ch2);
	if (ch1[0] == '-') ch1[0] = '0', f1 = 1;
	if (ch2[0] == '-') ch2[0] = '0', f2 = 1;//�Է��ŵĴ���
	int l1 = strlen(ch1), l2 = strlen(ch2);
	for (int i = l1 - 1; i >= 0; i -= siz) {
		long long pw = 1; ++a[0];
		for (int j = i; j > i - siz && j >= 0; --j) {
			a[a[0]] += (ch1[j] ^ 48) * pw;
			pw = (pw << 3) + (pw << 1);
		}
	}for (int i = l2 - 1; i >= 0; i -= siz) {
		long long pw = 1; ++b[0];
		for (int j = i; j > i - siz && j >= 0; --j) {
			b[b[0]] += (ch2[j] ^ 48) * pw;
			pw = (pw << 3) + (pw << 1);
		}
	}return;
}

void pls(long long a[], long long b[])
{
	if (f1 ^ f2) {
		if (f1) f1 ^= 1, mnu(b, a), f1 ^= 1;
		if (f2) f2 ^= 1, mnu(a, b), f2 ^= 1;//�Ӹ�����Ч�ڼ�����
		return;
	}if (f1 & f2) {
		f1 = f2 = 0, f ^= 1, pls(a, b);
		f1 = f2 = 1; return;
	}clear(s); s[0] = max(a[0], b[0]) + 1;
	for (int i = 1; i <= s[0]; ++i) {
		s[i] += a[i] + b[i];
		if (s[i] >= MOD) s[i] -= MOD, ++s[i + 1];
	}if (!s[s[0]] && s[0] > 1) --s[0];
	return;
}

void mnu(long long a[], long long b[])
{
	if (f1 ^ f2) {
		if (f1) f1 ^= 1, f ^= 1, pls(a, b), f1 ^= 1;
		if (f2) f2 ^= 1, pls(a, b), f2 ^= 1;//��������Ч�ڼ�����
		return;
	}if (f1 & f2) {
		f1 = f2 = 0, mnu(b, a);
		f1 = f2 = 1; return;
	}if (cmp(a, b) == -1) {
		f ^= 1; mnu(b, a); return;
	}clear(s); s[0] = max(a[0], b[0]);
	for (int i = 1; i <= s[0]; ++i) {
		s[i] += a[i] - b[i];
		if (s[i] < 0) s[i] += MOD, --s[i + 1];
	}while (!s[s[0]] && s[0] > 1) --s[0];
	return;
}

void mul(long long a[], long long b[])//ģ����ʽ�˷�
{
	if (f1 ^ f2) f ^= 1;
	clear(s); s[0] = a[0] + b[0];
	for (int i = 1; i <= a[0]; ++i) {
		for (int j = 1; j <= b[0]; ++j) {
			s[i + j - 1] += a[i] * b[j];
			if (s[i + j - 1] >= MOD) s[i + j] += s[i + j - 1] / MOD, s[i + j - 1] %= MOD;
		}
	}if (!s[s[0]] && s[0] > 1) --s[0];
	return;
}

void div(long long a[], long long b[])
{
	if (f1 ^ f2) {
		if (f1) f1 ^= 1, f ^= 1, div(a, b), f1 ^= 1;
		if (f2) f2 ^= 1, f ^= 1, div(a, b), f2 ^= 1;
		return;
	}clear(s);
	clear(cp), cp[1] = 1; clear(lt);
	while (cmp(a, b) != -1) ly(b), ly(cp);//������̽�̵Ķ��������λ
	while (cp[0] > 1 || cp[1]) {
		if (cmp(a, b) != -1) {
			mnu(a, b), cpy(a, s);
			pls(lt, cp), cpy(lt, s);//�����������㷨����
		}ry(b), ry(cp);
	}cpy(s, lt), cpy(lt, a);//sΪ�̣�ltΪ����
	return;
}

/*P2005
int main()
{
	init();
	clear(s);div(a, b); write(s);
	return 0;
}
*/