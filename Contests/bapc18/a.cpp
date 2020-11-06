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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

int v[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int get_num(string s){
	int m = 0, d = 0;
	m += (s[0] - '0')*10;
	m += (s[1] - '0');

	d += (s[3] - '0')*10;
	d += (s[4] - '0');

	return v[m] + d;
}

void get_format(int x){
	char ans[2]; 
	char k = (char)(x/10 + '0'), z = (char)(x%10 + '0');
	cout << k << z;
}

void get_date(int x){
	int m, d;
	frr(i, 12){
		if(v[i+1] >= x){
			m = i;
			break;
		}
	}
	d = x - v[m];

	//cout << m << " " << d<< endl;
	get_format(m);
	cout << "-";
	get_format(d);
	cout << endl;
}

int n;
vector<int> a;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	fr(i, n){
		string s;
		cin >> s;
		cin >> s;

		a.pb(get_num(s));
	}

	sort(a.begin(), a.end());

	//for(auto x: a) cout << x<< endl;

	int ans = -1;
	int val = a[0] + 365 - a.back();

	vector<int> pos;
	pos.pb(a[ans + 1] - 1);

	fr(i, a.size() - 1){
		if(val < a[i + 1]  - a[i]){
			pos.clear();
			pos.pb(a[i + 1] - 1);
			ans = i;
			val = a[i + 1] - a[i];
		}
		else if(val == a[i+1] - a[i]){
			pos.pb(a[i + 1] - 1);
		}
	}

	if(pos.size() == 1){
		ans = pos[0];
	}
	else{
		if(pos.back() > 300){
			for(int i = 0; i < pos.size(); i++){
      	if(pos[i] > 300){
        	ans = pos[i];
          break;
        }
      }    
       
    
		}
		else{
			ans = pos[0];
		}
	}

	//cout << ans << endl;

	get_date(ans);
}
