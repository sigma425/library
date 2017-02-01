/*
  http://d.hatena.ne.jp/sune2/20140310/1394440369からコピーしただけ かなり使いやすいと思う
  verifyはしてない

  書いてあると思うけど,ax+bを追加するときにa*b<=1e18じゃないとまずいっぽい
  Cって何だろう
  まあ外からは隠蔽されているのでわからなくても良い?(最悪)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF=LLONG_MAX;
struct CHT2 {  
  CHT2() {
    // 番兵
    S.insert({L(INF,0), L(-INF,0)});
    C.insert(cp(L(INF,0),L(-INF,0)));
  }
  // for debug
  void print() {
    cout << "S : "; for (auto it : S) printf("(%lld,%lld)", it.a, it.b); puts("");
    cout << "C : "; for (auto it : C) printf("(%lld,%lld)", it.n, it.d); puts("");
  }
  // |ab| < LLONG_MAX/4 ???
  void add(ll a, ll b) {
    const L p(a,b);
    It pos = S.insert(p).first;
    if (check(*it_m1(pos), p, *it_p1(pos))) {
      // 直線(a,b)が不要
      S.erase(pos);
      return;
    }
    C.erase(cp(*it_m1(pos), *it_p1(pos)));
    {
      // 右方向の削除
      It it = it_m1(pos);
      while(it!=S.begin() && check(*it_m1(it), *it, p)) --it;
      C_erase(it, it_m1(pos));
      S.erase(++it,pos);
      pos = S.find(p);
    }
    {
      // 左方向の削除
      It it = it_p1(pos);
      while(it_p1(it)!=S.end() && check(p,*it, *it_p1(it))) ++it;
      C_erase(++pos, it);
      S.erase(pos, it);
      pos = S.find(p);
    }
    C.insert(cp(*it_m1(pos), *pos));
    C.insert(cp(*pos, *it_p1(pos)));
  }
  ll query(ll x) {
    const L &p = (--C.lower_bound(CP(x,1,L(0,0))))->p;
    return p.a*x + p.b;
  }
  
private:
  
  template<class T> T it_p1(T a) { return ++a; }
  template<class T> T it_m1(T a) { return --a; }  
  struct L {
    ll a, b;
    L(ll a, ll b) : a(a),b(b) {}
    bool operator<(const L &rhs) const {
      return a != rhs.a ? a > rhs.a : b < rhs.b;
    }
  };
  struct CP {
    ll n,d;
    L p;
    CP(ll _n, ll _d, const L &p) : n(_n),d(_d),p(p) {
      if (d < 0) { n *= -1; d *= -1; }
    };
    bool operator<(const CP &rhs) const {
      if (n == INF || rhs.n == -INF) return 0;
      if (n == -INF || rhs.n == INF) return 1;      
      return n * rhs.d < rhs.n * d;
    }
  };
  set<L> S;
  set<CP> C;

  typedef set<L>::iterator It;
  
  void C_erase(It a, It b) {
    for (It it=a; it!=b; ++it)
      C.erase(cp(*it, *it_p1(it)));
  }
  CP cp(const L &p1, const L &p2) {
    if (p1.a == INF) return CP(-INF,1,p2);
    if (p2.a == -INF) return CP(INF,1,p2);
    return CP(p1.b-p2.b, p2.a-p1.a, p2);
  }
  bool check(const L &p1, const L &p2, const L &p3) {
    if (p1.a==p2.a && p1.b <= p2.b) return 1;
    if (p1.a == INF || p3.a == -INF) return 0;
    return (p2.a-p1.a)*(p3.b-p2.b) >= (p2.b-p1.b)*(p3.a-p2.a);
  }
};

int main() {
  CHT2 cht;
  cht.add(2,2);
  cht.add(-1,4);
  cht.add(3,4);
  cout << cht.query(-1) << endl; // 0
  cht.print();
}