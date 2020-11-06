#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n;
int a[MAXN];    
int b[4*MAXN];

void build(int i, int l, int r){
    if(l == r){
        b[i] = l;
    }
    else{
        int mid = (l+r)/2;

        build(2*i, l, mid);
        build(2*i+1, mid+1, r);

        if(a[b[2*i]] > a[b[2*i+1]]) b[i] = b[2*i+1];
        else b[i] = b[2*i];
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(l > qr || ql > r) return MAXN;
    else if(l <= ql && r <= qr) return b[i];
    else{
        int mid = (l+r)/2;

        int lf = query(2*i, l, mid, ql, qr);
        int rg = query(2*i+1, mid+1, r, ql, qr);

        if(a[lf] > a[rg]) return rg;
        else return lf;
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];


}