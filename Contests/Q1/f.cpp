#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
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

ll gcd(ll a, ll b){
	if(b == 0) return a;
  	else return gcd(b, a%b);
}

pii sum(pii a, pii b){
	ll d = a.s*b.s;

	ll n = (a.f*b.s + a.s*b.f);

	ll g = gcd(n, d);
	return mp(n/g, d/g);
}

pii sub(pii a, pii b){
	ll d = a.s*b.s;

	ll n = (a.f*b.s - a.s*b.f);

	ll g = gcd(n, d);
	return mp(n/g, d/g);
}

int main(){
	string s;
	while(cin >> s){
		ll i = 0;
		
		stack<char> sinals;
		int sinal_davez = 1;

		sinals.push('+');
		s = "(" + s + ")";
		
		vector<pii> final, aux;

    	while(i < s.size()){
    		if(s[i] >= '0' && s[i] <= '9'){
    			int sin = 1;
				
				if(s[i-1] == '-')
					sin *= -1;
				
				pii davez;
    			
    			ll num = 0;
    
    			while(s[i] != '/'){
    				num += (s[i] - '0');
    				num *= 10;
    				i++;
    			}
    
    			i++;
    
    			ll den = 0;
    			while(s[i] >= '0' && s[i] <= '9'){
    				den += (s[i] - '0');
    				den *= 10;
    				i++;
    			}
    
    			ll g = gcd(num, den);
    
    			davez = mp(num/g, den/g);
				
				if(sin*sinal_davez == 1)
					final.pb(mp('+', 0));
				else
					final.pb(mp('-', 0));

				final.pb(davez);
			}
			else if(s[i] == '('){
				if(i == 0 || (s[i-1] != '+' && s[i-1] != '-')){
					sinals.push('+');
				}
				else if(s[i-1] == '+'){
					sinals.push('+');	
				}
				else{
					sinals.push('-');
					sinal_davez*=-1;
				}
				i++;
			}
			else if(s[i] == '+' || s[i] == '-'){
				i++;
			}
			else{
				if(sinals.top() == '-')
					sinal_davez*=-1;

				sinals.pop();
				i++;
			}
		}

		pii ans = mp(0, 1);


		fr(i, final.size()){
			if(i%2 == 0){
				if(final[i].f == '+'){
					ans = sum(ans, final[i+1]);
				}
				else{
					ans = sub(ans, final[i+1]);
				}
			}/*
			else{
				cout << final[i].f << " / " << final[i].s << endl;
			}	*/
		}

		ll g = abs(gcd(ans.f, ans.s));	

		if(ans.s < 0){
			ans.s*=-1;
			ans.f*=-1;
		}

		cout << ans.f/g <<"/" << ans.s/g << endl;
	}
}