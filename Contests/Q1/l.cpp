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
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;
 
#define mem(v, k) memset(v, k, sizeof(v));
 
#define db cout << "Debug" << endl;
 
#define mp make_pair
#define pq priority_queue
 
#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;
 
#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321
 
int da[MAXN];
int a[110], ans[110];
int n;
 
map<int, int> m;
set<int> s;
 
void read(){
	cin >> n;
	frr(i, n){
		cin >> a[i];
		m[a[i]] = i;
		s.insert(-a[i]);
	}
}
 
void buildDa(){
	int t = s.size();
 
	da[0] = 1;
	fr(i, 1000000){
		if(da[i] == 0) continue;
		
		for(auto x: s){
			if(-x + i >= MAXN) continue;
			da[-x + i] = 1;
		}
	}
}
 
map<int, int> qtt;
 
void buildQtt(int x){
	
	set<int> aux = s, er;
	while(x > 0){
	    for(auto y: aux){
	    	if(x + y < 0){ 
				er.insert(y);
				continue;
			}
	    	
	    	if(da[x+y]){
	    		qtt[-y]++;
	    		x = x + y;
				break;
	    	}
	    }
		for(auto y: er){
			aux.erase(y);
		}
		er.clear();
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	string s;
 
	read();
	buildDa();
 
	vector<int> pos;
	pos.pb(0);
	frr(i, 1000000){
		if(da[i]) pos.pb(i);
	}
 
	int l = 0, r = pos.size(), mid;
 
	pos.pb(MAXN);
 
	for(int ts = 1; ts <= 30 && l < r - 1; ts++){
		mid = (l + r)/2;
		qtt.clear();
 
		buildQtt(pos[mid]);
 
		frr(i, n) ans[i] = 0;
		for(auto x: qtt){
			ans[m[x.f]] = x.s;
		}
 
		cout << 1 << endl;
		frr(i, n){
			cout << ans[i] << " ";
		}
		cout << endl;
 
		cin >> s;
 
		if(s == "yellow"){
			cout << 2 << endl;
			cout << pos[mid] << endl;
			return 0;
		}
		else if(s == "green")
			l = mid;
		else
			r = mid;
	}

	if(pos[r] - pos[l] == 2){
		cout << 2 << endl;
		cout << pos[l] + 1 << endl;
		return 0;
	}
	else
	{
		cout << 2 << endl;
		cout << -1 << endl;
	}
	
	
}