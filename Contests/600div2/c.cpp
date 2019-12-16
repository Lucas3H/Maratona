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

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll a[2*MAXN];
    
    fr(i, n) cin >> a[i];

    sort(a, a + n);

    for(int i = 1; i*m < n; i++){
        for(int j = 0; j + i*m < n && j < m; j++){
            a[j+i*m]+=a[j+(i-1)*m];
        }
    }


    ll sum = 0;
    fr(i, n){
        sum+=a[i];

        cout << sum << " ";
    }

    cout << endl;
}
