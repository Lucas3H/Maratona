// https://www.spoj.com/problems/SWAPS/
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

#define MAXN 250010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1

int n, len;
int a[MAXN];
int bitINV[50010];

int bit[501][50001];
int m;

void update(int i, int val, int t){
    while(i <= n){
        bit[t][i] += val;
        i += i & (-i);
    }
}

int query(int i, int t){
    int sum = 0;

    while(i > 0){
        sum += bit[t][i];
        i -= i & (-i);
    }

    return sum;
}



void updateINV(int i, int val){
    while(i <= n){
        bitINV[i] += val;
        i += i & (-i);
    }
}

int queryINV(int i){
    int sum = 0;

    while(i > 0){
        sum += bitINV[i];
        i -= i & (-i);
    }

    return sum;
}

ll count_inv(){
	ll ans = 0;
	fr(i, n){
		ans += (ll)(i - queryINV(a[i]))
		updateINV(a[i], 1);
	}

	return ans;
}



void build(){
	cin >> n;
	len = (int)sqrt(n + .0) + 1;
	mem(fr, 0);
	fr(i, n) cin >> a[i];

    fr(i, n+1) bit[i] = 0;
    fr(i, n) update(a[i], 1, i/len);

}

int querySQRT(int l, int r, int val){
	int sum = 0;
	for(int i = l; i <= r;){
		if(i%len == 0 && i + len - 1 <= r){
			sum += query(val, i/len);
			i+=len;
		}
		else{
			if(a[i] <= val) sum++;
		}
	}

	return sum;
}

void updateSQRT(int i, int val){
	update(a[i], -1, i/len);
	update(val, 1, i/len);
	a[i] = val;
}

int main(){
	ios::sync_with_stdio(false);
	build();
	cin >> m;

	ll ans = count_inv();

	fr(i, m){
		int pos, val;
		cin >> pos >> val;
		pos--;

		ans -= (pos - querySQRT(0, pos, a[pos]);
		ans -= querySQRT(pos + 1, n-1, a[pos] - 1);

		

		updateSQRT(pos, val);
	}
}
