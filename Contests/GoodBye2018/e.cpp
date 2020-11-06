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

#define MAXN 500010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int n;
vector<int> d;
ll r[MAXN]; // r[k] é o maior l tal que a[l] >= k
ll s[MAXN]; // s[k] = a[1] + a[2] + ... + a[k]
ll a[MAXN];

int v[MAXN], bit[MAXN];
int n;
/*------------BIT----------------*/
void update(int i, int val){
    while(i <= n){
        bit[i] += val;
        i += i & (-i);
    }
}

int query(int i){
    int sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= i & (-i);
    }

    return sum;
}


/*--------------ERDOS-GALLAI---------------*/

bool cmp(int a, int b){
	return a > b;
}

void set_r_s(){
    ll sum = 0;

    fr(i, n+2) r[i] = 0;

    a[0] = MAXN;
    frr(i, n){
        sum += a[i];
        s[i] = sum;

        r[a[i]] = i;
    }

    for(int i = n; i >= 1; i--){
        if(r[i] == 0){
            r[i] = r[i+1];
        }
    }

    return;
}

bool Erdos_Gallai(){
    // First Condition: Sum of all number is even
    if(s[n]%2 == 1) return 0;

    //Second Condition:
    /*
        a[1] + ... + a[k] <= k*(k-1) + min(k, a[k+1]) + ... + min(k, a[n])
    */

    frr(i, n){
        ll sum_mins;
        if(r[i] >= i+1) sum_mins = (r[i] - i)*i + s[n] - s[r[i]];
        else sum_mins = s[n] - s[i];

		if(s[i] == sum_mins + i*(i-1)) update(i, 1);

        if(s[i] > sum_mins +  i*(i-1)) return 0;
    }

    return 1;
}


int main(){
	ios::sync_with_stdio(false);

	cin >> n;
	frr(i, n){
		int aux;
		cin >> aux;

		if(aux > 0) d.pb(aux);
	}

	n = d.size();
	sort(d.begin(), d.end(), cmp);
	frr(i, n) a[i] = d[i-1];

	set_r_s();

}
