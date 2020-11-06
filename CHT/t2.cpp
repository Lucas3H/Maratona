/*
 *  Created by Andrei Arhire 03/08/2020
 *  Copyright © 2020 Andrei Arhire. All rights reserved.
 */
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lll long long
#define llf __float128
#define lld long double
using namespace std;
const int NR = 2e5 + 10  ,oo = 1e9 + 10, MOD = 1e9 + 7 ;
const long double pi = 2*acos(0.0);


template<typename V> struct ConvexHull {
    deque<pair<V,V>> Q;
    int cmptype=1; // 0-min 1-max
    V calc(pair<V,V> p, V x) {
        return p.first*x+p.second;
    }
    int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
        return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
    }
    void add(V a, V b) { // add ax+b
        Q.push_back({a,b});
        int v;
        while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
            Q[v-2]=Q[v-1], Q.pop_back();
    }

    V query(V x) {
        int L=-1,R=Q.size()-1;
        while(R-L>1) {
            int M=(L+R)/2;
            ((calc(Q[M],x)<=calc(Q[M+1],x))?L:R)=M;
        }
        return calc(Q[R],x);
    }
};


ConvexHull < lll > cht ;
lll tot , sp [ NR ] , a [ NR ] , n , best ;


signed main () {
    lll x , y , i ;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0) ;

    cin >> n ;
    for ( i = 1 ; i <= n ; ++ i )   {
        cin >> a [ i ] ;
        sp [ i ] = a [ i ] + sp [ i - 1 ] ;
        tot += a [ i ] * i ;
    }
    best = tot ;
    for ( i = 1 ; i <= n ; ++ i )   {
        if ( i == 1 )   {
            cht.add( i , - sp [ i - 1 ] ) ;
        }   else    {
            best = max ( best , tot + sp [ i - 1 ] - a [ i ] * i + cht.query( a [ i ] ) ) ;
            cht.add( i , - sp [ i - 1 ] ) ;
        }
    }
    cht.Q.clear() ;
    cht.cmptype = 0 ;
    for ( i = n ; i ; -- i )   {
        if ( i == n )   {
            cht.add( i , - sp [ i ] ) ;
        }   else    {
            best = max ( best , tot + sp [ i ] - a [ i ] * i + cht.query( a [ i ] ) ) ;
            cht.add( i , - sp [ i ] ) ;
        }
    }
    cout << best << '\n' ;
    return 0 ;
}