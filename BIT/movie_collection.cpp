// https://www.spoj.com/problems/NWERC11C/

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

int n, q;
int bit[2*MAXN];
int ant[MAXN];

void update(int i, int val){
    while(i < 2*MAXN){
        bit[i]+=val;
        i+=i&(-i);

        //cout << i << endl;
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum+=bit[i];
        //cout << "s " << sum <<" i " << i << endl;
        i-=i&(-i);
    }

    return sum;
}

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> q;

        fr(i, 2*MAXN) bit[i] = 0;
        frr(i, n) ant[i] = i + MAXN;

        int aux;
        fr(i, q){
            cin >> aux;
            //cout << "aux " << aux << " ant " << ant[aux] << " q " << query(ant[aux]) << endl;
            cout << ant[aux] + query(ant[aux]) - MAXN - 1 << " ";

            update(1, 1);

            update(ant[aux], -1);

            ant[aux] = MAXN - i;

        }

        cout << endl;
    }
}
