/*
* [1,5]
* |	   \____
* [1,3]     [4,5]
* |   \     |   \
* [1,2][2,3][4,4][4,5]
* |   \
* [1,1][2,2]
* * * * * * * * * * * * * * * * * *
* ���ǻ���������ֻ����һ�Σ�
* build(int l,int r,int p)
* eg:
* build(1,5,1)
* ����1,5��ʼ�ݹ�,��ǰ�ڵ���Ϊp
* ��ǰ�ڵ��Ų�ֻ��Ҷ�ӣ�Ҳ����������
* ���Ǳ���Ҫ��l,r,p����һ������
* build(l,r,p)
* if(l == r)
*   d[p]=a[l or r]
*   return;
* build(l,mid,ls(p))
* build(mid+1,r,rs(p))
* d[p] = sum(d[ls(p)],d[rs(p)])
* * * * * * * * * * * * * * * * * *
* make_b_mark(p,l,r)
* p�Ǳ��ڵ���,l�Ǳ��ڵ�������,r�Ǳ��ڵ�������
* (�Լ�д��)
* m = (l+r)/2;
* d[ls(p)] += b[p] * (m-l+1);����lsֵ
* d[rs(p)] += b[p] * (r-m);  ����rsֵ
* b[ls(p)] += b[p];����ls������
* b[rs(p)] += b[p];����rs������
* b[p] = 0;release(�ͷ�p������)
* * * * * * * * * * * * * * * * * *
* update(l,r,c,s,t,p)(��Ҳ���Ե���change)
* ţħ�������ǣ�
* =====* * * * * * * * * * * * * *
* =====* ��ν������
* =====* ���Ǵ��ǣ��޸ı��ڵ�
* =====* ���������޸ĸýڵ���Ӷ��ӵ���ֵ
* =====* �����ˣ�����
* =====* �ҵ������
* =====* ����ѯ����ڵ�ʱ
* =====* �����������
* =====* �·ű��(���޸ģ�ֱ�Ӵ�)
* =====* �޸ĺ��ӵ�ֵ
* =====* ��ձ��ڵ���
* =====* ����ֵ
* =====* ע:���ڴ��ϵ��²�ѯ�����Ա�֤һ�������������
* =====* Խ��Խ����ȫ�ݹ���(bushi
* =====* * * * * * * * * * * * * *
* l,r���޸�����
* c�Ǳ仯��
* s,t�ǵ�ǰ�ڵ㸺������
* p�ǽڵ���
*
* ��ס����ѯ������һ��Ҫд�����ǵĴ���
*
* �����ǰ�ڵ���ȫ��lr��
* ���Ǻ�,�޸ı��ڵ�,�˳�
* �����������
* update(l,r,c,s,t,p)
* if(l <= s && t <= r)
*   d[p]+=(t-s+1)*c
*   b[p] += c
*   return;
* m = (s+t)/2;
* make_b_mark(p,s,t);
* if(l<=m)update(l,r,c,s,m,ls(p));
* if(r>m) update(l,r,c,m+1,t,rs(p));
* dp[p] = dp[ls(p)]+dp[rs(p)];
* * * * * * * * * * * * * * * * * *
* sum(l,r,s,t,p)
* l,rΪ��ѯ����
* s,tΪ��ǰ�ڵ�����
* pΪ��ǰ�ڵ���
* eg:sum(1,3,1,5,1)//��Ҳ��֪����ô�뵽���߼�������OIWIKI
* //�����ǹ���
* �������������·��ڿ�����
* ��X���·ű���Ͻ��Ҫ��
* ����Ⱥ���ڿ�
* �������������������Ҫȫ���ڿ�,����d[p]
* ������������,������ϸ��,��"����"ֵ
* if(l<=s&&t<=r)return d[p];
* int m = (s+t)/2;
* make_b_mark(p,s,t);
* int ret = 0;
* if(l<=m) ret += sum(l,r,s,m,ls(p));
* if(m<r)  ret += sum(l,r,m+1,t,rs(p));
* return ret;
*/
template<int MAXN>
class lineTree {
public:
    long long a[MAXN + 1];
    long long d[MAXN + 1];//��ֵ
    long long b[MAXN + 1];//������
    inline long long ls(long long n) {
        return (n << 1);
    }
    inline long long rs(long long n) {
        return ((n << 1) | 1);
    }
    void build(long long l, long long r, long long p) {//�����䣬�����䣬��ǰ�ڵ���
        if (l == r) {
            d[p] = a[l];
            return;
        }
        long long mid = (l + r) >> 1;
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    void make_b_mark(long long p, long long l, long long r) {
        long long m = (l + r) / 2;
        d[ls(p)] += b[p] * (m - l + 1);
        d[rs(p)] += b[p] * (r - m);
        b[ls(p)] += b[p];
        b[rs(p)] += b[p];
        b[p] = 0;
    }
    void update(long long l, long long r, long long c, long long s, long long t, long long p) {
        if (l <= s && t <= r) {
            d[p] += (t - s + 1) * c;
            b[p] += c;
            return;
        }
        long long m = (s + t) >> 1;
        make_b_mark(p, s, t);
        if (l <= m) update(l, r, c, s, m, ls(p));
        if (r > m) update(l, r, c, m + 1, t, rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    long long sum(long long l, long long r, long long s, long long t, long long p) {
        if (l <= s && t <= r)return d[p];
        long long m = (s + t) >> 1;
        make_b_mark(p, s, t);
        long long ret = 0;
        if (l <= m) ret += sum(l, r, s, m, ls(p));
        if (m < r)  ret += sum(l, r, m + 1, t, rs(p));
        return ret;
    }
    void operator()(long long n) {//�Ͻ�
        build(1, n, 1);
    }
    lineTree() { ; };
};
//���չ������Ⱥ�һ�����(����)
//����P3373,�������ҵ�˼·
//����������k,b,����㲻֪������Ļ�,�����ʽ��:y=kx+b
// ����/���k���:
//  k[now]*=k;
//  b[now]*=k;
//  d[now]*=k;
// ����/���b���
//  b[now]+=b;
//  d[now]+=(len*b)(�������д�ˣ������İ���)
// ����ʱ�ȴ���k�ٴ���b
//P3372
/*
#include <bits/stdc++.h>
using namespace std;
constexpr long long MAXN = 400000;
class lineTree{
    public:
    long long a[MAXN+1],d[MAXN+1],b[MAXN+1],mid,ret;
    inline long long ls(long long n){return  (n<<1)   ;}
    inline long long rs(long long n){return ((n<<1)|1);}
    void build(long long l,long long r,long long p){
        mid = (l+r)>>1;
        if(l==r){d[p]=a[l];return;}
        build(l,  mid,ls(p));
        build(mid+1,r,rs(p));
        d[p]=d[ls(p)]+d[rs(p)];
    }
    void make_b_mark(long long p,long long l,long long r){
        mid = (l + r)/2;
        d[ls(p)] += b[p] * (mid-l+1);
        d[rs(p)] += b[p] * (r-mid);
        b[ls(p)] += b[p];
        b[rs(p)] += b[p];
        b[p] = 0;
    }
    void update(long long l,long long r,long long c,long long s,long long t,long long p){
        if(l <= s && t <= r){d[p] += (t - s + 1) * c;b[p] += c;return;}
        mid = (s + t) >> 1;
        make_b_mark(p,s,t);
        if(l <= mid) update(l,r,c,s,  mid,ls(p));
        if(r > mid)  update(l,r,c,mid+1,t,rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    long long sum(long long l,long long r,long long s,long long t,long long p){
        if(l <= s && t<=r)return d[p];
        mid = ((s + t) >> 1),ret=0;
        make_b_mark(p,s,t);
        if(l <= mid) ret += sum(l,r,s,mid,ls(p));
        if(mid < r)  ret += sum(l,r,mid+1,t,rs(p));
        return ret;
    }
    void operator()(long long n){build(1,n,1);}
    lineTree(){;};
};
lineTree t;
int main(){
    long long n,m,opt,a,b,c,i;
    cin >> n >> m;
    for(i = 1; i <= n; i++){cin >> t.a[i];}
    t(n);
    for(i = 1; i <=m ;i++){
        cin >> opt;
        if(opt == 1){cin >> a >> b >> c;t.update(a,b,c,1,n,1);}
        else{cin >> a >> b;cout << t.sum(a,b,1,n,1) << endl;}
    }
}
*/