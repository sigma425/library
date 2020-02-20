/*
    F2 ^ Dの基底持つ / 更新するやつ
    add が O(D)
    merge は add を D回、 O(D^2)


    (normalize)
        部分空間を状態として持ちたいときはBを正規化する必要がある
        上の桁から見て辞書順最小にする
        O(D^2)
    
    subspace の数は {1, 2, 5, 16, 67, 374, 2825, 29212, 417199, 8283458}
    そもそも個数が少ないのでN回dpを更新する代わりに同じsubspaceになるやつはまとめて、とかもありうる
        https://codeforces.com/contest/1299/problem/D

    D <= 6 なら貼る空間を 2^D bit で持った方が楽か? 計算量悪くなるが

    とにかく状態が少なくて計算する回数が多いなら、はじめに全部生成してから演算表(merge,add)を作りましょう
    1299/D.cpp 参照
*/

const int D = 64;
V<ull> B(D);

void add(ull x){
    for(int i=D-1;i>=0;i--){
        if(B[i] == 0 && x&1ULL<<i){ // add to base
            B[i] = x;
            return;
        }else if(x&1ULL<<i){
            x ^= B[i];
        }
    }
    // don't add to base
    // (dependent)
}

void normalize(){
    for(int i=D-1;i>=0;i--) if(B[i]){
        for(int j=i-1;j>=0;j--) chmin(B[i],B[i]^B[j]);
    }
}