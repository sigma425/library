/*
    x \in [L,R] に対して N/x = v なる区間 [l,r] を列挙
    v の値が大きい順 (区間を左から順)
    !!! 全部閉区間 !!!
    {3,3,3,}
    {2,4,5,}
    {1,6,10,}
    {0,11,20,}
    O(種類数) = O(N/L - N/R)
*/
vector<array<ll,3>> get_vlr(ll L,ll R,ll N){     //[L,R]
    assert(1 <= L && L <= R);
    vector<array<ll,3>> res;
    for(ll i=L,j;i<=R;i=j+1){
        ll v = N/i;
        j = v == 0 ? R : N/v; chmin(j,R);
        res.emplace_back(array<ll,3>{v,i,j});
    }
    return res;
}
