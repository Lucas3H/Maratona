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

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int f(int x){
    int fr[10];
    fr(i, 10) fr[i] = 0;

    while(x > 0){
        fr[x%10]++;
        if(fr[x%10] > 1) return 0;
        x/=10;
    }

    return 1;
}

int main(){
	ios::sync_with_stdio(false);

    int l, r;
    cin >> l >> r;

    for(int i = l; i <= r; i++){
        if(f(i)){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    

}
