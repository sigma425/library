---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1614
  bundledCode: "#line 1 \"geom/geom.cpp\"\nusing D = double;\nusing P = complex<D>;\n\
    using L = pair<P,P>;\nusing Pol = vector<P>;\nstruct C{P p;D r;};\nD inf=1e50,eps=1e-10,PI=acos(0.0)*2;\n\
    bool eq(D a, D b) { return abs(a-b)<eps;}\nbool eq(P a, P b) { return abs(a-b)<eps;}\n\
    int sig(D a) { return eq(a,0) ? 0 : (a>0 ? 1 : -1);}\nint large(D a,D b){return\
    \ eq(a,b)?0:(a>b?1:-1);}\nbool compxy (const P& l, const P& r){\n\treturn eq(l.real(),r.real())\
    \ ? l.imag()<r.imag() : l.real() < r.real();\n}\nbool compyx (const P& l, const\
    \ P& r){\n\treturn eq(l.imag(),r.imag()) ? l.real()<r.real() : l.imag() < r.imag();\n\
    }\ninline D dot(P a, P b) { return real(conj(a)*b);}\ninline D cro(P a, P b) {\
    \ return imag(conj(a)*b);}\n//enum ENCCW{CCW(left)=1, CW(right)=-1, FRONT=-2,\
    \ BACK=2, ON=0};\n//ON\u512A\u5148(including endpoint)\ninline int ccw (P a, P\
    \ b, P c){\n\tif(sig(cro(b-a,c-a))==1) return 1;\n\tif(sig(cro(b-a,c-a))==-1)\
    \ return -1;\n\tif(eq(abs(a-c)+abs(c-b),abs(a-b))) return 0;\n\tif(eq(abs(a-b)+abs(b-c),abs(a-c)))\
    \ return -2;\n\tif(eq(abs(c-a)+abs(a-b),abs(c-b))) return 2;\n\tassert(false);\n\
    }\ninline int ccw(L a,P p){return ccw(a.fs,a.sc,p);}\ninline P proj(P a, P b){\t\
    \t//\u30D9\u30AF\u30C8\u30EBa\u306Eb\u3078\u306E\u5C04\u5F71\n\treturn (dot(a,b)/norm(b))*b;\n\
    }\ninline D verlen(L l,P p){\t//\u5782\u7DDA\u306E\u9577\u3055(\u7B26\u53F7\u4ED8\
    \u304D ccw(\u5DE6)\u304C\u6B63)\n\treturn cro(l.sc-l.fs,p-l.fs)/abs(l.sc-l.fs);\n\
    }\ninline P perp(L l, P p){\t\t//\u5782\u7DDA\u306E\u8DB3\n\tD t=dot(p-l.fs,l.fs-l.sc)/norm(l.fs-l.sc);\n\
    \treturn l.fs+t*(l.fs-l.sc);\n}\ninline P refl(L l, P p){\n\treturn p+2.0*(perp(l,p)-p);\n\
    }\ninline bool ispal(L a, L b){\n\treturn sig(cro(a.fs-a.sc,b.fs-b.sc))==0;\n\
    }\ninline bool ovLL(L a, L b){\n\treturn ispal(a,b) && sig(cro(a.fs-a.sc,b.fs-a.sc))==0;\n\
    }\ninline bool iLL(L a, L b){\t\t//intersect or overload\n\treturn !ispal(a,b)\
    \ || ovLL(a,b);\n}\ninline bool iLS(L l, L s){\t\t//intersect(including endpoint)\
    \ or overload\n\treturn cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<eps;\n\
    }\ninline bool iLSex(L l, L s){\t\t//intersect(excluding endpoint)\n\treturn cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<-eps;\n\
    }\ninline bool iLP(L l, P p){\t\t//on line\n\treturn abs(sig(cro(l.sc-p,l.fs-p)))!=1;\n\
    }\ninline bool iSS(L a, L b){\t\t//intersect(including endpoint) or overload\n\
    \treturn ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0 && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0;\n\
    }\ninline bool iSSex(L a, L b){\t\t//intersect(excluding endpoint)\n\treturn ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<0\
    \ && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<0;\n}\ninline bool iSP(L s, P p){\t\
    \t//intersect(including endpoint) or overload\n\treturn ccw(s.fs,s.sc,p)==0;\n\
    }\ninline D dPP(P a, P b) { return abs(a-b);}\ninline D dLP(L l, P p) { return\
    \ abs(perp(l,p)-p);}\ninline D dLL(L a, L b) { return iLL(a,b) ? 0 : dLP(a,b.fs);}\n\
    inline D dLS(L l, L s) { return iLS(l,s) ? 0 : min(dLP(l,s.fs),dLP(l,s.sc));}\n\
    inline D dSP(L s, P p) {\n\tP q=perp(s,p);\n\treturn iSP(s,q) ? abs(p-q) : min(abs(p-s.fs),abs(p-s.sc));\n\
    }\ninline D dSS(L a, L b) {\n\tif(iSS(a,b)) return 0;\n\treturn min(min(dSP(a,b.fs),dSP(a,b.sc)),min(dSP(b,a.fs),dSP(b,a.sc)));\n\
    }\ninline P intLL(L a, L b) {\t//intersection\n\tassert(!ispal(a,b));\n\tD t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);\n\
    \treturn b.fs+t*(b.sc-b.fs);\n}\n//\ninline int iCL(C c, L l){\t\t//num of intersection(s)\n\
    \tD d=dLP(l,c.p);\n\treturn eq(d,c.r) ? 1 : (d<c.r ? 2 : 0);\n}\nbool containCC(C\
    \ a,C b){\t//a contain b? (edge case is true)\n\treturn abs(a.p-b.p)+b.r<a.r+eps;\n\
    }\nbool containCCex(C a,C b){\t//a contain b? (edge case is false)\n\treturn abs(a.p-b.p)+b.r<a.r-eps;\n\
    }\n// \u4EA4\u70B9\u304C2\u500B\u306E\u3068\u304D\u3001a\u3092b\u304C\u524A\u308B\
    \u3068\u601D\u3046\u3068\u3001\u524A\u308C\u305F\u90E8\u5206\u306Fret[0] -> res[1]\
    \ (ccw) \u306E\u90E8\u5206\nvector<P> intCC(C a,C b){\n\tif(abs(a.p-b.p) > a.r+b.r\
    \ + eps) return {};\n\tif(containCCex(a,b) || containCCex(b,a)) return {};\n\t\
    D d = abs(a.p-b.p);\n\tD tmp = (a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d);\n\tif(tmp <\
    \ -1) tmp = -1;\n\tif(tmp > 1) tmp = 1;\n\tD theta = acos(tmp);\n\tP p1 = a.p+(b.p-a.p)/d*polar(a.r,-theta);\n\
    \tP p2 = a.p+(b.p-a.p)/d*polar(a.r,theta);\n\tif(eq(p1,p2)) return {p1};\n\treturn\
    \ {p1,p2};\n}\ninline vector<L> tanCP(C c,P p){\n\tint x=large(c.r,abs(p-c.p));\n\
    \tvector<L> ret;\n\tif(x==1) return ret;\n\tif(x==0){\n\t\tret.pb(L(p,p+(c.p-p)*P(0,1)));\n\
    \t\treturn ret;\n\t}\n\tD theta=acos(c.r/abs(p-c.p));\n\tret.pb(L(p,c.p+(p-c.p)/abs(p-c.p)*polar(c.r,theta)));\n\
    \tret.pb(L(p,c.p+(p-c.p)/abs(p-c.p)*polar(c.r,-theta)));\n\treturn ret;\n}\ninline\
    \ Pol intCL(C c,L l){\n\tint x=large(dLP(l,c.p),c.r);\n\tPol ret;\n\tif(x==1)\
    \ return ret;\n\tif(x==0){\n\t\tret.pb(perp(l,c.p));\n\t\treturn ret;\n\t}\n\t\
    D d=dLP(l,c.p);\n\tif(d<eps){\n\t\tret.pb(c.p+(l.fs-l.sc)/abs(l.fs-l.sc)*c.r);\n\
    \t\tret.pb(c.p-(l.fs-l.sc)/abs(l.fs-l.sc)*c.r);\n\t\treturn ret;\n\t}\n\tD theta=acos(d/c.r);\n\
    \tP p=perp(l,c.p);\n\tret.pb(c.p+(p-c.p)/d*polar(c.r,theta));\n\tret.pb(c.p+(p-c.p)/d*polar(c.r,-theta));\n\
    \treturn ret;\n}\ninline vector<L> intan(C a,C b){\n\tP p=(a.r*b.p+b.r*a.p)/(a.r+b.r);\n\
    \treturn tanCP(a,p);\n}\ninline vector<L> outtan(C a,C b){\n\tif(a.r==b.r){\n\t\
    \tvector<L> ret;\n\t\tP p=(a.p-b.p)/abs(a.p-b.p)*polar(a.r,PI/2);\n\t\tret.pb(L(a.p+p,b.p+p));\n\
    \t\tret.pb(L(a.p-p,b.p-p));\n\t\treturn ret;\n\t}\n\tP p=(a.r*b.p-b.r*a.p)/(a.r-b.r);\n\
    \treturn tanCP(a,p);\n}\nD aTri(P a, P b, P c){ return cro(b-a,c-a)/2;}\nD aPol(Pol\
    \ p){\t\t\t//\u70B9\u96C6\u5408\u306FCCW\u306B\u4E0E\u3048\u308B\n\tint n=p.size();\n\
    \tD ret=0;\n\trep(i,n) ret+=cro(p[i],p[(i+1)%n])/2;\n\treturn ret;\n}\nP gPol(Pol\
    \ p){\t\t\t//\u591A\u89D2\u5F62\u5185\u90E8\u304C\u4E00\u69D8\u306A\u91CD\u3055\
    \u3092\u6301\u3064\u3068\u304D\u306E\u91CD\u5FC3\n\tint n=p.size();\n\tP g;\n\t\
    D s=aPol(p);\n\tassert(s>eps);\n\trep(i,n){\n\t\tD ds=cro(p[i],p[(i+1)%n])/2;\n\
    \t\tg+=ds/3*(p[i]+p[(i+1)%n]);\n\t}\n\treturn g/s;\n}\n//enum ENCONT{INP=1,ONP=0,OUTP=-1};\n\
    int contain(Pol pol, P p){\n\tbool in=false;\n\trep(i,pol.size()){\n\t\tP a=pol[i]-p,b=pol[(i+1)%pol.size()]-p;\n\
    \t\tif(ccw(a,b,P(0,0))==0) return 0;\n\t\tif(imag(a)>imag(b)) swap(a,b);\n\t\t\
    if(sig(imag(a))<=0 && 0<sig(imag(b)) && ccw(P(0,0),a,b)==1) in=!in;\n\t}\n\treturn\
    \ in ? 1 : -1;\n}\nL BL;\nbool compBL(const P& a,const P& b){\t\t\t//BL\u4E0A\u306E\
    \u70B9\u3092\u30BD\u30FC\u30C8(BL.fs\u5074\u304C\u5C0F\u3055\u3044)\n\treturn\
    \ dot(BL.sc-BL.fs,a-BL.fs)<dot(BL.sc-BL.fs,b-BL.fs);\n}\nbool containE(Pol pol,L\
    \ l){\t\t\t//pol\u306F\u9589\u96C6\u5408\u3060\u3068\u601D\u3063\u3066.\n\tvector<P>\
    \ ps;\n\tps.pb(l.fs);\n\tps.pb(l.sc);\n\tint N=pol.size();\n\trep(i,N){\n\t\t\
    L a(pol[i],pol[(i+1)%N]);\n\t\tif(ispal(a,l)) continue;\n\t\tif(!ispal(a,l)&&iSS(a,l))\
    \ ps.pb(intLL(a,l));\n\t}\n\tBL=l;\n\tsort(all(ps),compBL);\n\tint K=ps.size();\n\
    \trep(i,K-1) ps.pb((ps[i]+ps[i+1])/2.0);\n\tfor(P p:ps) if(!contain(pol,p)) return\
    \ 0;\n\treturn 1;\n}\ninline D heron(D a, D b, D c){\n\tdouble s=(a+b+c)/2;\n\t\
    if(s-a<eps || s-b<eps || s-c<eps) return 0;\t\t//S=0 || \u4E09\u89D2\u5F62\u3067\
    \u304D\u306A\u3044\n\treturn sqrt(s*(s-a)*(s-b)*(s-c));\n}\ninline Pol conv(Pol\
    \ p){\t\t//convex\n\tint n=p.size(),k=0;\n\tsort(all(p),compxy);\n\tPol ret(2*n);\n\
    \trep(i,n){\n\t\twhile(k>=2 && ccw(ret[k-2],ret[k-1],p[i])<=0) --k;\n\t\tret[k++]=p[i];\n\
    \t}\n\tfor(int i=n-2,t=k+1;i>=0;i--){\n\t\twhile(k>=t && ccw(ret[k-2],ret[k-1],p[i])<=0)\
    \ --k;\n\t\tret[k++]=p[i];\n\t}\n\tret.resize(k-1);\n\treturn ret;\n}\ninline\
    \ Pol convall(Pol p){\t\t//conv\u4E0A\u306E\u70B9\u5168\u90E8\t\t//\u70B9\u304C\
    2\u56DE\u4EE5\u4E0A\u51FA\u3066\u304F\u308B\n\tint n=p.size(),k=0;\n\tsort(all(p),compxy);\n\
    \tPol ret(2*n);\n\trep(i,n){\n\t\twhile(k>=2 && ccw(ret[k-2],ret[k-1],p[i])==-1)\
    \ --k;\n\t\tret[k++]=p[i];\n\t}\n\tfor(int i=n-2,t=k+1;i>=0;i--){\n\t\twhile(k>=t\
    \ && ccw(ret[k-2],ret[k-1],p[i])==-1) --k;\n\t\tret[k++]=p[i];\n\t}\n\tret.resize(k-1);\n\
    \tret.erase(unique(all(ret)),ret.end());\n\treturn ret;\n}\ninline Pol convexcut(Pol\
    \ p,L l){\t//ccw,left\u304C\u6B8B\u308B\n\tPol ret;\n\trep(i,p.size()){\n\t\t\
    if(ccw(l.fs,l.sc,p[i])!=-1) ret.pb(p[i]);\n\t\tL s=L(p[i],p[(i+1)%p.size()]);\n\
    \t\tif(iLSex(l,s)) ret.pb(intLL(l,s));\n\t}\n\treturn ret;\n}\ninline Pol interpol(Pol\
    \ a,Pol b){\t//ccw,ccw\n\trep(j,b.size()){\n\t\ta=convexcut(a,L(b[j],b[(j+1)%b.size()]));\n\
    \t}\n\treturn a;\n}\ninline vector<Pol> makevoronoi(Pol vp,Pol pol){\t//left\n\
    \tvector<Pol> ret;\n\tPol polc=pol;\n\trep(i,vp.size()){\n\t\tpol=polc;\n\t\t\
    rep(j,vp.size()){\n\t\t\tif(i==j) continue;\n\t\t\tP p=(vp[i]+vp[j])/2.0,q=p+(vp[j]-vp[i])*P(0,1);\n\
    \t\t\tpol=convexcut(pol,L(p,q));\n\t\t}\n\t\tret.pb(pol);\n\t}\n\treturn ret;\n\
    }\ninline D pol_diameter(Pol p){\n\tp=conv(p);\n\tint n=p.size();\n\tassert(n>=2);\n\
    \tif(n==2) return abs(p[0]-p[1]);\n\tint i=0,j=0;\n\trep(k,n){\n\t\tif(!compxy(p[i],p[k]))\
    \ i=k;\n\t\tif(compxy(p[j],p[k])) j=k;\n\t}\n\tD ret=0;\n\tint si=i,sj=j;\n\t\
    while(i!=sj || j!=si){\n\t\tret=max(ret,abs(p[i]-p[j]));\n\t\tif(cro(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0)\
    \ i=(i+1)%n;\n\t\telse j=(j+1)%n;\n\t}\n\treturn ret;\n}\ninline D closest_pair(P\
    \ *a, int n){\n\tif(n<=1) return inf;\n\tint m=n/2;\n\tD x=a[m].real();\n\tD d=min(closest_pair(a,m),closest_pair(a+m,n-m));\n\
    \tinplace_merge(a,a+m,a+n,compyx);\n\tvector<P> b;\n\trep(i,n){\n\t\tif(abs(x-a[i].real())>=d)\
    \ continue;\n\t\trep(j,b.size()){\n\t\t\tP dp=a[i]-b[b.size()-1-j];\n\t\t\tif(dp.imag()>=d)\
    \ break;\n\t\t\td=min(d,abs(dp));\n\t\t}\n\t\tb.pb(a[i]);\n\t}\n\treturn d;\n\
    }\ninline D compute_shortest(P *a,int n){\n\tsort(a,a+n,compxy);\n\treturn closest_pair(a,n);\n\
    }\n\n// return {p \\cap halfplane}\n// size = O(N^2)\n// time complexity: O(N^3)\
    \ slow\n// bit\u8868\u73FE\u3067\u6301\u3063\u3066\u308B\u306E\u3067\u5927\u304D\
    \u3044\u6642\u306Fvector\u306B\u5909\u3048\u3088\u3046\u306D\uFF01\n// \u7121\u99C4\
    \u306A\u306E\u304C\u542B\u307E\u308C\u3066\u308B\u304B\u3082\u3057\u308C\u306D\
    \u3048\u3000\u81EA\u4FE1\u306A\u3057\n// verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1614\n\
    V<ll> enumeratePlaneDivision(V<P> p){\n\tint N = si(p);\n\tV<ll> divs;\n//\trep(i,1<<N)\
    \ divs.pb(i);\n\tdivs.pb(0); divs.pb((1LL<<N)-1);\n\trep(i,N) rep(j,N) if(i !=\
    \ j){\n\t\tP mid = (p[j]+p[i])/2.0;\n\t\tP vec = (p[j]-p[i]) * polar(1.0,1e-8);\n\
    \t\tll s=0, t=0;\n\t\trep(k,N){\n\t\t\tif(cro(vec,p[k]-mid) < 0) s |= 1LL<<k;\n\
    \t\t\telse t |= 1LL<<k;\n\t\t}\n\t\tdivs.pb(s); divs.pb(t);\n\t}\n\tmkuni(divs);\n\
    \treturn divs;\n}\n\n// return { {i s.t. p \\in c[i]} | p: point }\n// \u5186\u306E\
    \u96C6\u5408\u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067\u3001\u3069\u306E\
    \u3088\u3046\u306A\u9818\u57DF\u306B\u5206\u3051\u3089\u308C\u308B\u304B\u3000\
    \u3068\u3044\u3046\u306E\u3092\u3001\u5186\u306B\u542B\u307E\u308C\u308B\u304B\
    \u542B\u307E\u308C\u306A\u3044\u304B\u306E\u96C6\u5408\u3067\u7279\u5FB4\u3065\
    \u3051\u3066\u8A08\u7B97\u3059\u308B\n// max: N^2-N+2\n// \u3068\u304B\u8A00\u3063\
    \u305F\u3051\u3069\u3084\u3084\u5618\u3067\u3001\u6B63\u306E\u9762\u7A4D\u3092\
    \u3082\u3064\u9818\u57DF\u3057\u304B\u5217\u6319\u3057\u3066\u306A\u3044\u6C17\
    \u3082\u3059\u308B\u3057\u3001\u3042\u3068\u7121\u99C4\u306A\u306E\u3082\u542B\
    \u307E\u308C\u3066\u308B\u6C17\u3082\u3059\u308B\n// \u30ED\u30D0\u30B9\u30C8\u306B\
    \u3084\u308A\u305F\u304F\u306D\uFF5E \u3053\u308C\u3067\u8A31\u3057\u3066\u304F\
    \u308C\n// \u5404\u9818\u57DF\u306B\u5BFE\u3057\u3066\u3001\u5883\u754C\u306B\u4EA4\
    \u70B9\u3092\u542B\u307E\u306A\u3044\u5834\u5408\u2192\u5883\u754C\u306F\u5186\
    \u306A\u306E\u3067\u5185\u3068\u5916\u3092\u305F\u3081\u3059\n// \u542B\u3080\u5834\
    \u5408\u3001\u4EA4\u70B9\u30682\u3064\u306E\u5186\u5F27\u306B\u631F\u307E\u308C\
    \u305F\u90E8\u5206\u3092\u5217\u6319\u3059\u308C\u3070\u3088\u3044\n// \u3068\u601D\
    \u3046\u3058\u3083\u3093\u3001b\u304Ca\u306B\u5185\u63A5\u3057\u3066\u305F\u3089\
    \u3001a-b\u306E\u90E8\u5206\u306F\u3001\u4EA4\u70B9\u306E\u8FD1\u508D\u304B\u3089\
    \u306F\u5F97\u3089\u308C\u306A\u3044\u3093\u3060\u3088\u306D\n// \u3088\u304F\u8003\
    \u3048\u308B\u3068\u3001\u3053\u306E\u3088\u3046\u306B\u5185\u63A5\u3057\u3066\
    \u308B\u3084\u3064\u3092\u907F\u3051\u308B\u306B\u306F\u3001\uFF08\u4ED6\u306E\
    \u4EA4\u70B9\u304B\u3089\u3082\u5F97\u3089\u308C\u306A\u3044 i.e. \u3069\u3053\
    \u3067\u3082\u5185\u63A5 \u3068\u3044\u3046\u3053\u3068\u3092\u8003\u616E\u3059\
    \u308B\u3068\u3001)\n// \u2191\u3067\u8A00\u3063\u305F\u5186\u306E\u5185\u5074\
    \u3092\u8A66\u3059\u3068\u304D\u306B\u30E9\u30F3\u30C0\u30E0\u306A\u56DE\u8EE2\
    \u3092\u3057\u3066\u4E00\u70B9\u53D6\u308C\u3070\u826F\u3044\u3053\u3068\u304C\
    \u793A\u305B\u308B\n// \u304B\u3057\u3053\u3044\u306D\uFF5E\uFF5E\uFF5E \u3082\
    \u3046\u4E00\u5207\u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u4E8B\u4FE1\
    \u7528\u3057\u3066\u3044\u307E\u305B\u3093\n// verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1614\n\
    \n\nV<ll> enumerateCircleInclusion(V<C> c){\n\tint N = si(c);\n\tV<ll> inclusions;\n\
    //\trep(i,1<<N) inclusions.pb(i);\n\tV<P> cands;\n\tD eps_here = 1e-8;\n\trep(i,N){\n\
    \t\tcands.pb(c[i].p + polar(c[i].r-eps_here, 1.0));\n\t\tcands.pb(c[i].p + polar(c[i].r+eps_here,\
    \ 1.0));\n\t}\n\trep(i,N) rep(j,N) if(i!=j){\n\t\tV<P> f = intCC(c[i],c[j]);\n\
    \t\tfor(P p: f){\n\t\t\tP d1 = (p-c[i].p); d1 /= abs(d1);\n\t\t\tP d2 = (p-c[j].p);\
    \ d2 /= abs(d2);\n\t\t\tP dir = (d1+d2); dir /= abs(dir);\n\t\t\trep(_,4){\n\t\
    \t\t\tcands.pb(p + dir * eps_here);\n\t\t\t\tdir *= P(0,1);\n\t\t\t}\n\t\t}\n\t\
    }\n\tfor(P p: cands){\n\t\tll s = 0;\n\t\trep(i,N) if(abs(p-c[i].p) < c[i].r)\
    \ s |= 1LL<<i;\n\t\tinclusions.pb(s);\n\t}\n\tmkuni(inclusions);\n\treturn inclusions;\n\
    }\n"
  code: "using D = double;\nusing P = complex<D>;\nusing L = pair<P,P>;\nusing Pol\
    \ = vector<P>;\nstruct C{P p;D r;};\nD inf=1e50,eps=1e-10,PI=acos(0.0)*2;\nbool\
    \ eq(D a, D b) { return abs(a-b)<eps;}\nbool eq(P a, P b) { return abs(a-b)<eps;}\n\
    int sig(D a) { return eq(a,0) ? 0 : (a>0 ? 1 : -1);}\nint large(D a,D b){return\
    \ eq(a,b)?0:(a>b?1:-1);}\nbool compxy (const P& l, const P& r){\n\treturn eq(l.real(),r.real())\
    \ ? l.imag()<r.imag() : l.real() < r.real();\n}\nbool compyx (const P& l, const\
    \ P& r){\n\treturn eq(l.imag(),r.imag()) ? l.real()<r.real() : l.imag() < r.imag();\n\
    }\ninline D dot(P a, P b) { return real(conj(a)*b);}\ninline D cro(P a, P b) {\
    \ return imag(conj(a)*b);}\n//enum ENCCW{CCW(left)=1, CW(right)=-1, FRONT=-2,\
    \ BACK=2, ON=0};\n//ON\u512A\u5148(including endpoint)\ninline int ccw (P a, P\
    \ b, P c){\n\tif(sig(cro(b-a,c-a))==1) return 1;\n\tif(sig(cro(b-a,c-a))==-1)\
    \ return -1;\n\tif(eq(abs(a-c)+abs(c-b),abs(a-b))) return 0;\n\tif(eq(abs(a-b)+abs(b-c),abs(a-c)))\
    \ return -2;\n\tif(eq(abs(c-a)+abs(a-b),abs(c-b))) return 2;\n\tassert(false);\n\
    }\ninline int ccw(L a,P p){return ccw(a.fs,a.sc,p);}\ninline P proj(P a, P b){\t\
    \t//\u30D9\u30AF\u30C8\u30EBa\u306Eb\u3078\u306E\u5C04\u5F71\n\treturn (dot(a,b)/norm(b))*b;\n\
    }\ninline D verlen(L l,P p){\t//\u5782\u7DDA\u306E\u9577\u3055(\u7B26\u53F7\u4ED8\
    \u304D ccw(\u5DE6)\u304C\u6B63)\n\treturn cro(l.sc-l.fs,p-l.fs)/abs(l.sc-l.fs);\n\
    }\ninline P perp(L l, P p){\t\t//\u5782\u7DDA\u306E\u8DB3\n\tD t=dot(p-l.fs,l.fs-l.sc)/norm(l.fs-l.sc);\n\
    \treturn l.fs+t*(l.fs-l.sc);\n}\ninline P refl(L l, P p){\n\treturn p+2.0*(perp(l,p)-p);\n\
    }\ninline bool ispal(L a, L b){\n\treturn sig(cro(a.fs-a.sc,b.fs-b.sc))==0;\n\
    }\ninline bool ovLL(L a, L b){\n\treturn ispal(a,b) && sig(cro(a.fs-a.sc,b.fs-a.sc))==0;\n\
    }\ninline bool iLL(L a, L b){\t\t//intersect or overload\n\treturn !ispal(a,b)\
    \ || ovLL(a,b);\n}\ninline bool iLS(L l, L s){\t\t//intersect(including endpoint)\
    \ or overload\n\treturn cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<eps;\n\
    }\ninline bool iLSex(L l, L s){\t\t//intersect(excluding endpoint)\n\treturn cro(l.sc-l.fs,s.fs-l.fs)*cro(l.sc-l.fs,s.sc-l.fs)<-eps;\n\
    }\ninline bool iLP(L l, P p){\t\t//on line\n\treturn abs(sig(cro(l.sc-p,l.fs-p)))!=1;\n\
    }\ninline bool iSS(L a, L b){\t\t//intersect(including endpoint) or overload\n\
    \treturn ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0 && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<=0;\n\
    }\ninline bool iSSex(L a, L b){\t\t//intersect(excluding endpoint)\n\treturn ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<0\
    \ && ccw(b.fs,b.sc,a.fs)*ccw(b.fs,b.sc,a.sc)<0;\n}\ninline bool iSP(L s, P p){\t\
    \t//intersect(including endpoint) or overload\n\treturn ccw(s.fs,s.sc,p)==0;\n\
    }\ninline D dPP(P a, P b) { return abs(a-b);}\ninline D dLP(L l, P p) { return\
    \ abs(perp(l,p)-p);}\ninline D dLL(L a, L b) { return iLL(a,b) ? 0 : dLP(a,b.fs);}\n\
    inline D dLS(L l, L s) { return iLS(l,s) ? 0 : min(dLP(l,s.fs),dLP(l,s.sc));}\n\
    inline D dSP(L s, P p) {\n\tP q=perp(s,p);\n\treturn iSP(s,q) ? abs(p-q) : min(abs(p-s.fs),abs(p-s.sc));\n\
    }\ninline D dSS(L a, L b) {\n\tif(iSS(a,b)) return 0;\n\treturn min(min(dSP(a,b.fs),dSP(a,b.sc)),min(dSP(b,a.fs),dSP(b,a.sc)));\n\
    }\ninline P intLL(L a, L b) {\t//intersection\n\tassert(!ispal(a,b));\n\tD t=cro(a.sc-a.fs,a.sc-b.fs)/cro(a.sc-a.fs,b.sc-b.fs);\n\
    \treturn b.fs+t*(b.sc-b.fs);\n}\n//\ninline int iCL(C c, L l){\t\t//num of intersection(s)\n\
    \tD d=dLP(l,c.p);\n\treturn eq(d,c.r) ? 1 : (d<c.r ? 2 : 0);\n}\nbool containCC(C\
    \ a,C b){\t//a contain b? (edge case is true)\n\treturn abs(a.p-b.p)+b.r<a.r+eps;\n\
    }\nbool containCCex(C a,C b){\t//a contain b? (edge case is false)\n\treturn abs(a.p-b.p)+b.r<a.r-eps;\n\
    }\n// \u4EA4\u70B9\u304C2\u500B\u306E\u3068\u304D\u3001a\u3092b\u304C\u524A\u308B\
    \u3068\u601D\u3046\u3068\u3001\u524A\u308C\u305F\u90E8\u5206\u306Fret[0] -> res[1]\
    \ (ccw) \u306E\u90E8\u5206\nvector<P> intCC(C a,C b){\n\tif(abs(a.p-b.p) > a.r+b.r\
    \ + eps) return {};\n\tif(containCCex(a,b) || containCCex(b,a)) return {};\n\t\
    D d = abs(a.p-b.p);\n\tD tmp = (a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d);\n\tif(tmp <\
    \ -1) tmp = -1;\n\tif(tmp > 1) tmp = 1;\n\tD theta = acos(tmp);\n\tP p1 = a.p+(b.p-a.p)/d*polar(a.r,-theta);\n\
    \tP p2 = a.p+(b.p-a.p)/d*polar(a.r,theta);\n\tif(eq(p1,p2)) return {p1};\n\treturn\
    \ {p1,p2};\n}\ninline vector<L> tanCP(C c,P p){\n\tint x=large(c.r,abs(p-c.p));\n\
    \tvector<L> ret;\n\tif(x==1) return ret;\n\tif(x==0){\n\t\tret.pb(L(p,p+(c.p-p)*P(0,1)));\n\
    \t\treturn ret;\n\t}\n\tD theta=acos(c.r/abs(p-c.p));\n\tret.pb(L(p,c.p+(p-c.p)/abs(p-c.p)*polar(c.r,theta)));\n\
    \tret.pb(L(p,c.p+(p-c.p)/abs(p-c.p)*polar(c.r,-theta)));\n\treturn ret;\n}\ninline\
    \ Pol intCL(C c,L l){\n\tint x=large(dLP(l,c.p),c.r);\n\tPol ret;\n\tif(x==1)\
    \ return ret;\n\tif(x==0){\n\t\tret.pb(perp(l,c.p));\n\t\treturn ret;\n\t}\n\t\
    D d=dLP(l,c.p);\n\tif(d<eps){\n\t\tret.pb(c.p+(l.fs-l.sc)/abs(l.fs-l.sc)*c.r);\n\
    \t\tret.pb(c.p-(l.fs-l.sc)/abs(l.fs-l.sc)*c.r);\n\t\treturn ret;\n\t}\n\tD theta=acos(d/c.r);\n\
    \tP p=perp(l,c.p);\n\tret.pb(c.p+(p-c.p)/d*polar(c.r,theta));\n\tret.pb(c.p+(p-c.p)/d*polar(c.r,-theta));\n\
    \treturn ret;\n}\ninline vector<L> intan(C a,C b){\n\tP p=(a.r*b.p+b.r*a.p)/(a.r+b.r);\n\
    \treturn tanCP(a,p);\n}\ninline vector<L> outtan(C a,C b){\n\tif(a.r==b.r){\n\t\
    \tvector<L> ret;\n\t\tP p=(a.p-b.p)/abs(a.p-b.p)*polar(a.r,PI/2);\n\t\tret.pb(L(a.p+p,b.p+p));\n\
    \t\tret.pb(L(a.p-p,b.p-p));\n\t\treturn ret;\n\t}\n\tP p=(a.r*b.p-b.r*a.p)/(a.r-b.r);\n\
    \treturn tanCP(a,p);\n}\nD aTri(P a, P b, P c){ return cro(b-a,c-a)/2;}\nD aPol(Pol\
    \ p){\t\t\t//\u70B9\u96C6\u5408\u306FCCW\u306B\u4E0E\u3048\u308B\n\tint n=p.size();\n\
    \tD ret=0;\n\trep(i,n) ret+=cro(p[i],p[(i+1)%n])/2;\n\treturn ret;\n}\nP gPol(Pol\
    \ p){\t\t\t//\u591A\u89D2\u5F62\u5185\u90E8\u304C\u4E00\u69D8\u306A\u91CD\u3055\
    \u3092\u6301\u3064\u3068\u304D\u306E\u91CD\u5FC3\n\tint n=p.size();\n\tP g;\n\t\
    D s=aPol(p);\n\tassert(s>eps);\n\trep(i,n){\n\t\tD ds=cro(p[i],p[(i+1)%n])/2;\n\
    \t\tg+=ds/3*(p[i]+p[(i+1)%n]);\n\t}\n\treturn g/s;\n}\n//enum ENCONT{INP=1,ONP=0,OUTP=-1};\n\
    int contain(Pol pol, P p){\n\tbool in=false;\n\trep(i,pol.size()){\n\t\tP a=pol[i]-p,b=pol[(i+1)%pol.size()]-p;\n\
    \t\tif(ccw(a,b,P(0,0))==0) return 0;\n\t\tif(imag(a)>imag(b)) swap(a,b);\n\t\t\
    if(sig(imag(a))<=0 && 0<sig(imag(b)) && ccw(P(0,0),a,b)==1) in=!in;\n\t}\n\treturn\
    \ in ? 1 : -1;\n}\nL BL;\nbool compBL(const P& a,const P& b){\t\t\t//BL\u4E0A\u306E\
    \u70B9\u3092\u30BD\u30FC\u30C8(BL.fs\u5074\u304C\u5C0F\u3055\u3044)\n\treturn\
    \ dot(BL.sc-BL.fs,a-BL.fs)<dot(BL.sc-BL.fs,b-BL.fs);\n}\nbool containE(Pol pol,L\
    \ l){\t\t\t//pol\u306F\u9589\u96C6\u5408\u3060\u3068\u601D\u3063\u3066.\n\tvector<P>\
    \ ps;\n\tps.pb(l.fs);\n\tps.pb(l.sc);\n\tint N=pol.size();\n\trep(i,N){\n\t\t\
    L a(pol[i],pol[(i+1)%N]);\n\t\tif(ispal(a,l)) continue;\n\t\tif(!ispal(a,l)&&iSS(a,l))\
    \ ps.pb(intLL(a,l));\n\t}\n\tBL=l;\n\tsort(all(ps),compBL);\n\tint K=ps.size();\n\
    \trep(i,K-1) ps.pb((ps[i]+ps[i+1])/2.0);\n\tfor(P p:ps) if(!contain(pol,p)) return\
    \ 0;\n\treturn 1;\n}\ninline D heron(D a, D b, D c){\n\tdouble s=(a+b+c)/2;\n\t\
    if(s-a<eps || s-b<eps || s-c<eps) return 0;\t\t//S=0 || \u4E09\u89D2\u5F62\u3067\
    \u304D\u306A\u3044\n\treturn sqrt(s*(s-a)*(s-b)*(s-c));\n}\ninline Pol conv(Pol\
    \ p){\t\t//convex\n\tint n=p.size(),k=0;\n\tsort(all(p),compxy);\n\tPol ret(2*n);\n\
    \trep(i,n){\n\t\twhile(k>=2 && ccw(ret[k-2],ret[k-1],p[i])<=0) --k;\n\t\tret[k++]=p[i];\n\
    \t}\n\tfor(int i=n-2,t=k+1;i>=0;i--){\n\t\twhile(k>=t && ccw(ret[k-2],ret[k-1],p[i])<=0)\
    \ --k;\n\t\tret[k++]=p[i];\n\t}\n\tret.resize(k-1);\n\treturn ret;\n}\ninline\
    \ Pol convall(Pol p){\t\t//conv\u4E0A\u306E\u70B9\u5168\u90E8\t\t//\u70B9\u304C\
    2\u56DE\u4EE5\u4E0A\u51FA\u3066\u304F\u308B\n\tint n=p.size(),k=0;\n\tsort(all(p),compxy);\n\
    \tPol ret(2*n);\n\trep(i,n){\n\t\twhile(k>=2 && ccw(ret[k-2],ret[k-1],p[i])==-1)\
    \ --k;\n\t\tret[k++]=p[i];\n\t}\n\tfor(int i=n-2,t=k+1;i>=0;i--){\n\t\twhile(k>=t\
    \ && ccw(ret[k-2],ret[k-1],p[i])==-1) --k;\n\t\tret[k++]=p[i];\n\t}\n\tret.resize(k-1);\n\
    \tret.erase(unique(all(ret)),ret.end());\n\treturn ret;\n}\ninline Pol convexcut(Pol\
    \ p,L l){\t//ccw,left\u304C\u6B8B\u308B\n\tPol ret;\n\trep(i,p.size()){\n\t\t\
    if(ccw(l.fs,l.sc,p[i])!=-1) ret.pb(p[i]);\n\t\tL s=L(p[i],p[(i+1)%p.size()]);\n\
    \t\tif(iLSex(l,s)) ret.pb(intLL(l,s));\n\t}\n\treturn ret;\n}\ninline Pol interpol(Pol\
    \ a,Pol b){\t//ccw,ccw\n\trep(j,b.size()){\n\t\ta=convexcut(a,L(b[j],b[(j+1)%b.size()]));\n\
    \t}\n\treturn a;\n}\ninline vector<Pol> makevoronoi(Pol vp,Pol pol){\t//left\n\
    \tvector<Pol> ret;\n\tPol polc=pol;\n\trep(i,vp.size()){\n\t\tpol=polc;\n\t\t\
    rep(j,vp.size()){\n\t\t\tif(i==j) continue;\n\t\t\tP p=(vp[i]+vp[j])/2.0,q=p+(vp[j]-vp[i])*P(0,1);\n\
    \t\t\tpol=convexcut(pol,L(p,q));\n\t\t}\n\t\tret.pb(pol);\n\t}\n\treturn ret;\n\
    }\ninline D pol_diameter(Pol p){\n\tp=conv(p);\n\tint n=p.size();\n\tassert(n>=2);\n\
    \tif(n==2) return abs(p[0]-p[1]);\n\tint i=0,j=0;\n\trep(k,n){\n\t\tif(!compxy(p[i],p[k]))\
    \ i=k;\n\t\tif(compxy(p[j],p[k])) j=k;\n\t}\n\tD ret=0;\n\tint si=i,sj=j;\n\t\
    while(i!=sj || j!=si){\n\t\tret=max(ret,abs(p[i]-p[j]));\n\t\tif(cro(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j])<0)\
    \ i=(i+1)%n;\n\t\telse j=(j+1)%n;\n\t}\n\treturn ret;\n}\ninline D closest_pair(P\
    \ *a, int n){\n\tif(n<=1) return inf;\n\tint m=n/2;\n\tD x=a[m].real();\n\tD d=min(closest_pair(a,m),closest_pair(a+m,n-m));\n\
    \tinplace_merge(a,a+m,a+n,compyx);\n\tvector<P> b;\n\trep(i,n){\n\t\tif(abs(x-a[i].real())>=d)\
    \ continue;\n\t\trep(j,b.size()){\n\t\t\tP dp=a[i]-b[b.size()-1-j];\n\t\t\tif(dp.imag()>=d)\
    \ break;\n\t\t\td=min(d,abs(dp));\n\t\t}\n\t\tb.pb(a[i]);\n\t}\n\treturn d;\n\
    }\ninline D compute_shortest(P *a,int n){\n\tsort(a,a+n,compxy);\n\treturn closest_pair(a,n);\n\
    }\n\n// return {p \\cap halfplane}\n// size = O(N^2)\n// time complexity: O(N^3)\
    \ slow\n// bit\u8868\u73FE\u3067\u6301\u3063\u3066\u308B\u306E\u3067\u5927\u304D\
    \u3044\u6642\u306Fvector\u306B\u5909\u3048\u3088\u3046\u306D\uFF01\n// \u7121\u99C4\
    \u306A\u306E\u304C\u542B\u307E\u308C\u3066\u308B\u304B\u3082\u3057\u308C\u306D\
    \u3048\u3000\u81EA\u4FE1\u306A\u3057\n// verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1614\n\
    V<ll> enumeratePlaneDivision(V<P> p){\n\tint N = si(p);\n\tV<ll> divs;\n//\trep(i,1<<N)\
    \ divs.pb(i);\n\tdivs.pb(0); divs.pb((1LL<<N)-1);\n\trep(i,N) rep(j,N) if(i !=\
    \ j){\n\t\tP mid = (p[j]+p[i])/2.0;\n\t\tP vec = (p[j]-p[i]) * polar(1.0,1e-8);\n\
    \t\tll s=0, t=0;\n\t\trep(k,N){\n\t\t\tif(cro(vec,p[k]-mid) < 0) s |= 1LL<<k;\n\
    \t\t\telse t |= 1LL<<k;\n\t\t}\n\t\tdivs.pb(s); divs.pb(t);\n\t}\n\tmkuni(divs);\n\
    \treturn divs;\n}\n\n// return { {i s.t. p \\in c[i]} | p: point }\n// \u5186\u306E\
    \u96C6\u5408\u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067\u3001\u3069\u306E\
    \u3088\u3046\u306A\u9818\u57DF\u306B\u5206\u3051\u3089\u308C\u308B\u304B\u3000\
    \u3068\u3044\u3046\u306E\u3092\u3001\u5186\u306B\u542B\u307E\u308C\u308B\u304B\
    \u542B\u307E\u308C\u306A\u3044\u304B\u306E\u96C6\u5408\u3067\u7279\u5FB4\u3065\
    \u3051\u3066\u8A08\u7B97\u3059\u308B\n// max: N^2-N+2\n// \u3068\u304B\u8A00\u3063\
    \u305F\u3051\u3069\u3084\u3084\u5618\u3067\u3001\u6B63\u306E\u9762\u7A4D\u3092\
    \u3082\u3064\u9818\u57DF\u3057\u304B\u5217\u6319\u3057\u3066\u306A\u3044\u6C17\
    \u3082\u3059\u308B\u3057\u3001\u3042\u3068\u7121\u99C4\u306A\u306E\u3082\u542B\
    \u307E\u308C\u3066\u308B\u6C17\u3082\u3059\u308B\n// \u30ED\u30D0\u30B9\u30C8\u306B\
    \u3084\u308A\u305F\u304F\u306D\uFF5E \u3053\u308C\u3067\u8A31\u3057\u3066\u304F\
    \u308C\n// \u5404\u9818\u57DF\u306B\u5BFE\u3057\u3066\u3001\u5883\u754C\u306B\u4EA4\
    \u70B9\u3092\u542B\u307E\u306A\u3044\u5834\u5408\u2192\u5883\u754C\u306F\u5186\
    \u306A\u306E\u3067\u5185\u3068\u5916\u3092\u305F\u3081\u3059\n// \u542B\u3080\u5834\
    \u5408\u3001\u4EA4\u70B9\u30682\u3064\u306E\u5186\u5F27\u306B\u631F\u307E\u308C\
    \u305F\u90E8\u5206\u3092\u5217\u6319\u3059\u308C\u3070\u3088\u3044\n// \u3068\u601D\
    \u3046\u3058\u3083\u3093\u3001b\u304Ca\u306B\u5185\u63A5\u3057\u3066\u305F\u3089\
    \u3001a-b\u306E\u90E8\u5206\u306F\u3001\u4EA4\u70B9\u306E\u8FD1\u508D\u304B\u3089\
    \u306F\u5F97\u3089\u308C\u306A\u3044\u3093\u3060\u3088\u306D\n// \u3088\u304F\u8003\
    \u3048\u308B\u3068\u3001\u3053\u306E\u3088\u3046\u306B\u5185\u63A5\u3057\u3066\
    \u308B\u3084\u3064\u3092\u907F\u3051\u308B\u306B\u306F\u3001\uFF08\u4ED6\u306E\
    \u4EA4\u70B9\u304B\u3089\u3082\u5F97\u3089\u308C\u306A\u3044 i.e. \u3069\u3053\
    \u3067\u3082\u5185\u63A5 \u3068\u3044\u3046\u3053\u3068\u3092\u8003\u616E\u3059\
    \u308B\u3068\u3001)\n// \u2191\u3067\u8A00\u3063\u305F\u5186\u306E\u5185\u5074\
    \u3092\u8A66\u3059\u3068\u304D\u306B\u30E9\u30F3\u30C0\u30E0\u306A\u56DE\u8EE2\
    \u3092\u3057\u3066\u4E00\u70B9\u53D6\u308C\u3070\u826F\u3044\u3053\u3068\u304C\
    \u793A\u305B\u308B\n// \u304B\u3057\u3053\u3044\u306D\uFF5E\uFF5E\uFF5E \u3082\
    \u3046\u4E00\u5207\u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u4E8B\u4FE1\
    \u7528\u3057\u3066\u3044\u307E\u305B\u3093\n// verify: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1614\n\
    \n\nV<ll> enumerateCircleInclusion(V<C> c){\n\tint N = si(c);\n\tV<ll> inclusions;\n\
    //\trep(i,1<<N) inclusions.pb(i);\n\tV<P> cands;\n\tD eps_here = 1e-8;\n\trep(i,N){\n\
    \t\tcands.pb(c[i].p + polar(c[i].r-eps_here, 1.0));\n\t\tcands.pb(c[i].p + polar(c[i].r+eps_here,\
    \ 1.0));\n\t}\n\trep(i,N) rep(j,N) if(i!=j){\n\t\tV<P> f = intCC(c[i],c[j]);\n\
    \t\tfor(P p: f){\n\t\t\tP d1 = (p-c[i].p); d1 /= abs(d1);\n\t\t\tP d2 = (p-c[j].p);\
    \ d2 /= abs(d2);\n\t\t\tP dir = (d1+d2); dir /= abs(dir);\n\t\t\trep(_,4){\n\t\
    \t\t\tcands.pb(p + dir * eps_here);\n\t\t\t\tdir *= P(0,1);\n\t\t\t}\n\t\t}\n\t\
    }\n\tfor(P p: cands){\n\t\tll s = 0;\n\t\trep(i,N) if(abs(p-c[i].p) < c[i].r)\
    \ s |= 1LL<<i;\n\t\tinclusions.pb(s);\n\t}\n\tmkuni(inclusions);\n\treturn inclusions;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: geom/geom.cpp
  requiredBy: []
  timestamp: '2023-11-13 23:55:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geom/geom.cpp
layout: document
redirect_from:
- /library/geom/geom.cpp
- /library/geom/geom.cpp.html
title: geom/geom.cpp
---
