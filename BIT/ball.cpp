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

int n;
int aux[3][MAXN];
pair<int, pii> v[MAXN];

int bit[2][MAXN];

void update(int i, int val, int t){
    if(t == 0){
        while(i <= n){
            bit[t][i] = max(val, bit[t][i]);
            i+=i&(-i);
        }
    }
    else{
        while(i <= n){
            bit[t][i]+=val;
            i+=i&(-i);
        }
    }
}

int query(int i, int t){
    int ans = 0;

    if(t == 0){
        while(i > 0){
            ans = max(ans, bit[t][i]);
            i-=i&(-i);
        }
    }
    else{
        while(i > 0){
            ans+=bit[t][i];
            i-=i&(-i);
        }
    }

    return ans;
}

int main(){
	ios::sync_with_stdio(false);

    cin >> n;

    for(int j = 0; j < 3; j++){
        frr(i, n){
            cin >> aux[j][i]
        }
    }
    frr(i, n){
        v[i] = mp(aux[0][i], mp(aux[1][i], aux[2][i]));
    }

    sort(v + 1, v + n + 1);

    frr(i, n){

    }
}
