#ifdef head1
#pragma region
// *INDENT-OFF*
#ifndef M207
#pragma GCC target("popcnt")
#endif
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define il inline
#define fi first
#define se second
#define mp make_pair
#define gcd __gcd
#define pb emplace_back
#define solid const auto &
#define gm int mid((l+r)/2)
#define space putchar(' ')
#define enter putchar('\n')
#define rd() ({int t;in(t);t;})
#define Size(x) ((int)x.size())
#define mem(x,y) memset(x,y,sizeof(x))
// #define ri register int
typedef long long LL;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
template<class T, class = typename enable_if<is_integral<T>::value>::type>il void in(T& x) {
    x = 0; char c = getchar(); bool f = 0;
    while (!isdigit(c)) f |= (c == '-'), c = getchar();
    while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
    f ? x = -x : 0;
}
template<class T, class = typename enable_if<is_integral<T>::value>::type>il void out(T x, const char c = '\n') {
    static short st[40]; short m = 0;
    if (x < 0) putchar('-'), x = -x;
    do st[++m] = x % 10, x /= 10; while (x);
    while (m) putchar(st[m--] | '0');
    putchar(c);
}
template<class T>il void err(const T& x, const char c = '\n') { cerr << x << c; }
template<class T, class ...Args>il void in(T& x, Args &...args) { in(x); in(args...); }
template<class T, class ...Args>il void out(const T& x, const Args &...args) { out(x, ' '); out(args...); }
template<class T, class ...Args>il void err(const T& x, const Args &...args) { err(x, ' '); err(args...); }
template<class T>il void prt(T a, int n) { --n; for (int i = 0; i < n; ++i) out(a[i], ' '); out(a[n], '\n'); }
template<class T>il void errprt(T a, int n) { --n; for (int i = 0; i < n; ++i) err(a[i], ' '); err(a[n], '\n'); }
template<class T>il void clr(T a[], int n) { memset(a, 0, sizeof(T) * n); }
template<class T>il void clr(T* a, T* b) { memset(a, 0, sizeof(T) * (b - a)); }
template<class T>il bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>il bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
namespace MOD_CALC
{
    const int md = 1e9 + 7, inv2 = (md + 1) / 2;
    il int add(const int a, const int b) { return a + b >= md ? a + b - md : a + b; }
    il int sub(const int a, const int b) { return a - b < 0 ? a - b + md : a - b; }
    il int mul(const int a, const int b) { return (LL)a * b % md; }
    il void inc(int& a, const int b) { (a += b) >= md ? a -= md : 0; }
    il void dec(int& a, const int b) { (a -= b) < 0 ? a += md : 0; }
    il int qpow(int a, int b) { int r = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a); return r; }
    il int qpow(int a, int b, const int p) { int r = 1; for (; b; b >>= 1, a = (LL)a * a % p) if (b & 1) r = (LL)r * a % p; return r; }
    il int mdinv(const int a) { return qpow(a, md - 2); }
    template<class ...Args>il int add(const int a, const int b, const Args &...args) { return add(add(a, b), args...); }
    template<class ...Args>il int mul(const int a, const int b, const Args &...args) { return mul(mul(a, b), args...); }
} //using namespace MOD_CALC;
// namespace i207M
// {
//     // *INDENT-ON*
// #pragma endregion

//     signed main()
//     {
// #ifdef M207
//         // freopen("in.in", "r", stdin);
//         // freopen("ot.out","w",stdout);
// #endif
//         int a;
//         in(a);
//         return 0;
//     }
// #pragma region
// }
// signed main()
// {
//     i207M::main();
//     return 0;
// }
// #pragma endregion
#endif
#ifdef head2
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
const int md = 1e9 + 7;
#define _CRT_SECURE_NO_WARNINGS
#define re register int
#define ce constexpr
#define il inline
#define gm int mid((l+r)/2)
#define Size(x) ((int)x.size())
#define mem(x,y) memset(x,y,sizeof(x))
#define cls system("cls")
#define pau system("pause")
#define stop system("pause")
#define exi exit(0)
#define co continue
#define Lgo(x,y) x<<=y
#define Rgo(x,y) x>>=y;
#define even(X) (!(X&1))
#define odd(X) (X&1)
template<typename L, typename R> constexpr bool same() { return is_same<L, R>::value; }
typedef long long LL; typedef unsigned int ui; typedef unsigned long long ull;
ull gcd(ull L, ull R) { ull lgo = 0; while (L != R && L != 0 && R != 0) { if (!((odd(L)) | (odd(R)))) { Lgo(L, 1); Lgo(R, 1); lgo++; co; }if (even(L)) { Rgo(L, 1); co; }if (even(R)) { Rgo(R, 1); co; }if (L < R) { swap(L, R); }L -= R; }if (L < R) { swap(L, R); }return L << lgo; }
#define read(name,T) T name;in(name)
template<typename L, typename R>using p = pair<L, R>;
template<typename L, typename R>p<L, R> il mp(L l, R r) { return make_pair(l, r); };
static void il read_u(unsigned long long& n) { n = 0; unsigned char ch = getchar(); while ((ch ^ '0') > 9) { ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); } }
static void il read_s(long long& n) { n = 0; unsigned char ch = getchar(), w = 0; while ((ch ^ '0') > 9) { if (!(ch ^ '-')) { w = 1; } ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); }if (w) { n = -n; } }
static long long il read_s() { long long n = 0; unsigned char ch = getchar(), w = 0; while ((ch ^ '0') > 9) { if (!(ch ^ '-')) w = 1; ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); }if (w) { return -n; }return n; }
static unsigned long long il read_u() { unsigned long long n = 0; unsigned char ch = getchar(); while ((ch ^ '0') > 9) { ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); }return n; }
template<class T, class = typename enable_if<is_integral<T>::value>::type>il void out(T x, const char c = '\n') { static short st[40]; short m = 0; if (x < 0) { putchar('-'), x = -x; }do { st[++m] = x % 10, x /= 10; } while (x); while (m) { putchar(st[m--] | '0'); }putchar(c); }
template<class T, class = typename enable_if<is_integral<T>::value>::type>il void in_o(T& x) { x = 0; char c = getchar(); bool f = 0; while (!isdigit(c)) { f |= (c == '-'), c = getchar(); }while (isdigit(c)) { x = x * 10 + (c ^ '0'), c = getchar(); }f ? x = -x : 0; }
template<class T>void in(T& n) { if (is_unsigned<T>::value) { n = read_u(); } else { n = read_s(); } }
template<class T, class ...Args>il void in(T& x, Args &...args) { in(x); in(args...); }
template<class T, class ...Args>il static void in_o(T& x, Args &...args) { in_o(x); in_o(args...); }
template<class T, class ...Args>il static void out(const T& x, const Args &...args) { out(x, ' '); out(args...); }
template<class T>il void static prt(T a, int n) { --n; for (int i = 0; i < n; ++i) out(a[i], ' '); out(a[n], '\n'); }
template<class T>il void static clr(T a[], int n) { memset(a, 0, sizeof(T) * n); }
template<class T>il void static clr(T* a, T* b) { memset(a, 0, sizeof(T) * (b - a)); }
template<class T>il bool static ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>il bool static ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
il int static add(const int a, const int b) { return a + b >= md ? a + b - md : a + b; }
il int static sub(const int a, const int b) { return a - b < 0 ? a - b + md : a - b; }
il int static mul(const int a, const int b) { return (LL)a * b % md; }
il void static inc(int& a, const int b) { (a += b) >= md ? a -= md : 0; }
il void static dec(int& a, const int b) { (a -= b) < 0 ? a += md : 0; }
il int static qpow(int a, int b) { int r = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a); return r; }
il int static qpow(int a, int b, const int p) { int r = 1; for (; b; b >>= 1, a = (LL)a * a % p) if (b & 1) r = (LL)r * a % p; return r; }
il int static mdinv(const int a) { return qpow(a, md - 2); }
template<class ...Args>il int static add(const int a, const int b, const Args &...args) { return add(add(a, b), args...); }
template<class ...Args>il int static mul(const int a, const int b, const Args &...args) { return mul(mul(a, b), args...); }
namespace BN {
#define LL long long
#define Re register int
	using namespace std;
	const int base = 1e8;
	const int N = 1e4 + 10;
	int aux[80080];
	class Int {
	public:
		int s[N], l;
		inline void CL() { l = 0; memset(s, 0, sizeof(s)); };
		inline void pr() { printf("%d", s[l]); for (Re i = l - 1; i; i--) { printf("%08d", s[i]); } };
		inline void re_l() { Re i, x = 0, k = 1, L = 0, fl, o; char c = getchar(); for (; c < '0' || c>'9'; c = getchar()); for (; c >= '0' && c <= '9'; c = getchar()) { if (!(L - 1) && !aux[L])L--; aux[++L] = c - '0'; }; CL(); l = L / 8 + ((o = L % 8) > 0); for (i = 1; i <= o; i++) { x = x * 10 + aux[i]; }; if (o) { s[l] = x; fl = !o ? l + 1 : l; }for (i = o + 1, x = 0; i <= L; i++, k++) { x = x * 10 + aux[i]; if (!(k ^ 8)) { s[--fl] = x, x = k = 0; }; }; if (!l) { l = 1; }; };
		inline LL toint() { LL x = 0; for (Re i = l; i; i--) { x = x * base + s[i]; }; return x; };


		inline Int operator=(Re b) { CL(); do { s[++l] = b % base, b /= base; } while (b > 0); return *this; };
		inline Int operator=(LL b) { CL(); do { s[++l] = b % base, b /= base; } while (b > 0); return *this; };


		inline Int operator+(const Re& b) { Int c = *this; LL x = b; for (Re i = 1; i <= l && x; i++) { x = x + c.s[i], c.s[i] = x % base, x /= base; }; if (x) { c.s[++c.l] = x; }; return c; };
		inline Int operator-(const Re& b) { Int c; return *this - (c = b); };
		inline Int operator*(const Re& b) { Int c; LL x = 0; c.CL(); for (Re i = 1; i <= l; i++) { x = x + 1LL * s[i] * b, c.s[i] = x % base, x /= base; }; for (c.l = l; x; x /= base) { c.s[++c.l] = x % base; }; return c; };
		inline Int operator/(const Re& b) { Int c; LL x = 0; c.CL(); for (Re i = l; i; i--) { c.s[i] = (x * base + s[i]) / b, x = (x * base + s[i]) % b; }; for (c.l = l; !c.s[c.l] && c.l > 1; c.l--); return c; };
		inline Int operator%(const Re& b) { Int c; LL x = 0; c.CL(); for (Re i = l; i; i--) { x = (x * base + s[i]) % b; }return c = x; };
		inline Int operator+(const LL& b) { Int c = *this; LL x = b; for (Re i = 1; i <= l && x; i++) { x = x + c.s[i], c.s[i] = x % base, x /= base; }; if (x) { c.s[++c.l] = x; }; return c; };
		inline Int operator-(const LL& b) { Int c; return *this - (c = b); }
		inline Int operator*(const LL& b) { Int c; if (b > 2e9) { c = b; return *this * c; }LL x = 0; c.CL(); for (Re i = 1; i <= l; i++) { x = x + b * s[i], c.s[i] = x % base, x /= base; }for (c.l = l; x; x /= base) { c.s[++c.l] = x % base; }return c; };
		inline Int operator/(const LL& b) { Int c; LL x = 0; c.CL(); for (Re i = l; i; i--) { c.s[i] = (x * base + s[i]) / b, x = (x * base + s[i]) % b; }; for (c.l = l; !c.s[c.l] && c.l > 1; c.l--); return c; };
		inline Int operator%(const LL& b) { Int c; LL x = 0; c.CL(); for (Re i = l; i; i--) { x = (x * base + s[i]) % b; }return c = x; };
		inline Int operator+(Int& b) { if (b.l < 3) { return *this + b.toint(); }; Int c; LL x = 0; Re k = l < b.l ? b.l : l; c.CL(), c.l = k; for (Re i = 1; i <= k; i++) { x = x + s[i] + b.s[i], c.s[i] = x % base, x /= base; }; if (x) { c.s[++c.l] = x; }; return c; };
		inline Int operator-(const Int& b) { Int c, d = *this; LL x = 0; c.CL(); for (Re i = 1; i <= l; i++) { if ((x = d.s[i]) < b.s[i]) { d.s[i + 1]--, x += base; }c.s[i] = x - b.s[i]; }c.l = l; for (; !c.s[c.l] && c.l > 1; c.l--); return c; }
		inline Int operator*(Int& b) { if (b.l < 2) { return *this * b.toint(); }Int c; LL x; Re i, j, k; c.CL(); for (i = 1; i <= l; i++) { x = 0; for (j = 1; j <= b.l; j++) { x = x + 1LL * s[i] * b.s[j] + c.s[k = i + j - 1], c.s[k] = x % base, x /= base; }; if (x) { c.s[i + b.l] = x; }; }for (c.l = l + b.l; !c.s[c.l] && c.l > 1; c.l--); return c; };
		inline Int operator/(Int& b) { if (b.l < 2) { return *this / b.toint(); }; Int c, d; Re i, j, le, r, mid, k; c.CL(); d.CL(); for (i = l; i; i--) { for (j = ++d.l; j > 1; j--) { d.s[j] = d.s[j - 1]; }; d.s[1] = s[i]; if (d < b) { continue; }; le = k = 0; r = base - 1; while (le <= r) { mid = (le + r) >> 1; if (b * mid <= d) { le = mid + 1, k = mid; } else { r = mid - 1; } }; c.s[i] = k, d = d - b * k; }; for (c.l = l; !c.s[c.l] && c.l > 1; c.l--); return c; };
		inline Int operator%(Int& b) { if (b.l < 2) { return *this % b.toint(); }Int c; Re i, j, le, r, mid, k; c.CL(); for (i = l; i; i--) { for (j = ++c.l; j > 1; j--) { c.s[j] = c.s[j - 1]; }c.s[1] = s[i]; if (c < b) { continue; }le = k = 0, r = base - 1; while (le <= r) { mid = (le + r) >> 1; if (b * mid <= c) { le = mid + 1, k = mid; } else { r = mid - 1; } }c = c - b * k; }for (; !c.s[c.l] && c.l > 1; c.l--); return c; }


		inline Int operator+=(Re& b) { return *this = *this + b; };
		inline Int operator-=(Re& b) { return *this = *this - b; };
		inline Int operator*=(Re& b) { return *this = *this * b; };
		inline Int operator/=(Re& b) { return *this = *this / b; };
		inline Int operator%=(Re& b) { return *this = *this % b; };
		inline Int operator+=(LL& b) { return *this = *this + b; };
		inline Int operator-=(LL& b) { return *this = *this - b; };
		inline Int operator*=(LL& b) { return *this = *this * b; };
		inline Int operator/=(LL& b) { return *this = *this / b; };
		inline Int operator%=(LL& b) { return *this = *this % b; };
		inline Int operator+=(Int& b) { return *this = *this + b; };
		inline Int operator-=(Int& b) { return *this = *this - b; };
		inline Int operator*=(Int& b) { return *this = *this * b; };
		inline Int operator/=(Int& b) { return *this = *this / b; };
		inline Int operator%=(Int& b) { return *this = *this % b; };


		inline bool operator<=(const Int& b)const { if (l ^ b.l) { return l < b.l; }; for (Re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] < b.s[i]; } }; return 1; };
		inline bool operator>=(const Int& b)const { if (l ^ b.l) { return l > b.l; }; for (Re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] > b.s[i]; } }; return 1; };
		inline bool operator<(const Int& b)const { if (l ^ b.l) { return l < b.l; }; for (Re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] < b.s[i]; } }; return 0; };
		inline bool operator>(const Int& b)const { if (l ^ b.l) { return l > b.l; }; for (Re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] > b.s[i]; } }; return 0; };
		inline bool operator==(const Int& b)const { if (l ^ b.l) { return 0; }; for (Re i = l; i; i--) { if (s[i] ^ b.s[i]) { return 0; } }; return 1; };
		inline bool operator!=(const Int& b)const { if (l ^ b.l) { return 1; }; for (Re i = l; i; i--) { if (s[i] ^ b.s[i]) { return 1; } }; return 0; };
		inline bool operator<(LL b)const { Int c; return *this < (c = b); };
		inline bool operator>(LL b)const { Int c; return *this > (c = b); };
		inline bool operator<=(LL b)const { Int c; return *this <= (c = b); };
		inline bool operator>=(LL b)const { Int c; return *this >= (c = b); };
		inline bool operator==(LL b)const { Int c; return *this == (c = b); };
		inline bool operator!=(LL b)const { Int c; return *this != (c = b); };
		inline bool operator<(Re b)const { Int c; return *this < (c = b); };
		inline bool operator>(Re b)const { Int c; return *this > (c = b); };
		inline bool operator<=(Re b)const { Int c; return *this <= (c = b); };
		inline bool operator>=(Re b)const { Int c; return *this >= (c = b); };
		inline bool operator==(Re b)const { Int c; return *this == (c = b); };
		inline bool operator!=(Re b)const { Int c; return *this != (c = b); };
	};
}
#ifdef new_getchar
#define getchar() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?EOF:*S++)
#endif
#endif