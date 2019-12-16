// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4282
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
#define mod(a, b) (a + b)%b
#define MAXN 100010
#define MOD 1000000007

map<char, int> alphabet;

vector<int> build(string s, int tam){
	int t = s.size(), i = 1, j = 0, dif;
	vector<int> lps(t);
	lps[0] = 0;

	while(i < t){
		if(j == 0) dif = mod(alphabet[s[i]] - alphabet[s[j]], tam);

		if(mod(alphabet[s[i]] - alphabet[s[j]], tam) == dif) lps[i++] = ++j;
		else if(j == 0) lps[i++] = 0;
		else {
			j = lps[j-1];
			if( j > 0) dif = mod(alphabet[s[i-1]] - alphabet[s[j-1]], tam);
		}
	}

	return lps;
}

void check(string w, string s, int tam){
	int tw = w.size(), ts = s.size(), i = 0, j = 0, dif;
	vector<int> lps = build(w, tam);
	vector<int> visto(tam), ans;
	
	fr(i, tam) visto[i] = 0;

	while(i < ts){
		if( j == 0 ) dif = mod(alphabet[s[i]] - alphabet[w[j]], tam);

		if(mod(alphabet[s[i]] - alphabet[w[j]], tam) == dif){
			i++;
			j++;
		}

		if(j == tw){
			visto[(dif + tam)%tam]++;
			j = lps[j-1];



			if(j > 0) dif = mod(alphabet[s[i-1]] - alphabet[w[j-1]], tam);
		}
		else if(i < ts && mod(alphabet[s[i]] - alphabet[w[j]], tam) != dif){
			if(j == 0) i++;
			else{
				j = lps[j-1];
				if(j > 0) dif = mod(alphabet[s[i-1]] - alphabet[w[j-1]], tam);		
			}
		} 
	}

	fr(i, tam){
		if(visto[i] == 1) ans.pb(i);
	}

	sort(ans.begin(), ans.end());

	if(ans.size() == 0) cout << "no solution\n";
	else if(ans.size() == 1) cout << "unique: " << ans[0] << endl;
	else{
		cout << "ambiguous: ";
		fr(i, ans.size() - 1) cout << ans[i] <<" ";
		cout << ans[ans.size()-1];
		cout << endl;
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--){
		alphabet.clear();
		string a, w, s;
		cin >> a >> w >> s;

		fr(i, a.size()) alphabet[a[i]] = i;
		check(w, s, a.size());
	}
}
