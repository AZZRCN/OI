#include <iostream>
#define ull unsigned long long
ull _gcd(ull L, ull R) {
    ull lgo = 0;
    while (L != R) {
        if (!((L & 1) | (R & 1))) {
            L >>= 1;
            R >>= 1;
            lgo++;
            continue;
        }
        if (!(L & 1)) {
            L >>= 1;
            continue;
        }
        if (!(R & 1)) {
            R >>= 1;
            continue;
        }
        if (L < R) { std::swap(L, R); }
        L -= R;
    }
    if (L < R) { std::swap(L, R); }
    return L << lgo;
}
//fixed
/*
#define ull unsigned long long
ull gcd(ull L, ull R){
    ull lgo = 0;
    while(L!=R && L != 0 && R != 0){
        if(!((L&1)|(R&1))){
            L >>=1;
            R>>=1;
            lgo++;
            continue;
        }
        if(!(L&1)){
            L>>=1;
            continue;
        }
        if(!(R&1)){
            R>>=1;
            continue;
        }
        if(L<R){swap(L,R);}
        L-=R;
    }
    if(L<R){swap(L,R);}
    return L<<lgo;
}
*/
//Ñ¹ÐÐ&&fixed
/*
#define ull unsigned long long
ull gcd(ull L,ull R){ull lgo=0;while(L!=R&&L!=0&&R!=0){if\
(!((L&1)|(R&1))){L>>=1;R>>=1;lgo++;continue;}if(!(L&1)){L\
>>=1;continue;}if(!(R&1)){R>>=1;continue;}if(L<R){swap(\
L,R);}L-=R;}if(L<R){swap(L,R);}return L<<lgo;}
*/
//ÀýÌâ:P4057
/*
int main(int argc, char const* argv[])
{
    ull a, b, c, lab;
    cin >> a >> b >> c;
    lab = a * b / _gcd(a, b);
    cout << lab * c / _gcd(lab, c);
    return 0;
}
*/