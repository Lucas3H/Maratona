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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin  >> n;

        int a[MAXN], b[MAXN];

        fr(i, n) cin >> a[i];
        fr(i, n) cin >> b[i];

        int deu = 1;

        int l = -1, r = n-1;

        fr(i, n){
            if(b[i] < a[i]){
                deu = 0;
                break;
            }
            else if(b[i] > a[i]){
                if(l == -1) l = i;
                r = i;
            }
        }

        //cout << l << " " << r << endl;

        if(l != -1){
            for(int i = l; i <= r; i++){
                if(b[i] - a[i] != (b[l] - a[l])) deu = 0;;
            }
        }

        if(deu == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
