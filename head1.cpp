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