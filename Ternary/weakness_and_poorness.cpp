// https://codeforces.com/problemset/problem/578/C

#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b)
#define mn(a, b) a = min(a, b)
#define mod(a, b) a = a%b

#define MAXN 100010
#define MOD 1000000007

double a[2*MAXN];
double n;

double maximo(double x){
    double ans = a[0] - x, ant = a[0] - x;

    frr(i, n-1){
        if(ant < 0) ant = a[i] - x;
        else ant = ant + a[i] - x;
        
        mx(ans, ant);
    }

    return ans;
}

double minimo(double x){
    double ans = a[0] - x, ant = a[0] - x;

    frr(i, n-1){
        if(ant > 0) ant = a[i] - x;
        else ant = ant + a[i] - x;
        
        mn(ans, ant);
    }

    return ans;    
}

int main(){

    cin >> n;
    fr(i, n) cin >> a[i];

    double l = -10000, r = 10000;


    while(abs(r - l) > 0.00000000001){
        double t1 = l + (r - l)/3;
        double t2 = r - (r - l)/3;
    

        if( max( abs(maximo(t1)) , abs(minimo(t1)) ) > max( abs(maximo(t2)), abs(minimo(t2)) ))l = t1;
        else r = t2;
    
    }

   // cout << max( abs(maximo(0)) , abs(minimo(0)) ) << endl;

    printf("%.10lf\n", max( abs(maximo((l+r)/2)) , abs(minimo((l+r)/2)) ));
}
