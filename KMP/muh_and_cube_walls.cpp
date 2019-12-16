// https://codeforces.com/problemset/problem/471/D
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

vector<ll> build(ll *s, ll w){
	ll i = 1, j = 0, dif;
	vector<ll> lps(w);
	
	lps[0] = 0;
	while(i < w){
		if(j == 0) dif = s[i] - s[j];
		
		if(s[i] - s[j] == dif){
			lps[i++] = ++j;
		}
		else if(j == 0) lps[i++] = 1;
		else {
			j = lps[j-1];
			if(j > 0) dif = s[i-1] - s[j-1];
		}
	}

	return lps;
}

ll check(ll *t, ll tt, ll *p, ll tp){
	ll i = 0, j = 0, ans = 0, dif;
	vector<ll> lps = build(p, tp);

	while(i < tt){
		if(j == 0) dif = t[i] - p[j];
		
		if((t[i] - p[j]) == dif){
			i++;
			j++;

		//	cout << i << " " << j << endl;
		}
		if(j == tp){
			ans++;
			j = lps[j-1];
			if(j > 0) dif = t[i-1] - p[j-1];
		}
		else if(i < tt && (t[i] - p[j]) != dif){
			if(j == 0) i++;
			else {
				j = lps[j-1];
				if(j > 0)dif = t[i-1] - p[j-1];
			}
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	ll n, w;
	cin >> n >> w;
	ll a[2*MAXN], b[2*MAXN];

	fr(i, n) cin >> a[i];
	fr(i, w) cin >> b[i];

	cout << check(a, n, b, w) << endl;

}
