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

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

char m[6][6];
int ok[30];
int pos = 0;

void build(char x){
	if(ok[x - 'a'] == 0){
		ok[x - 'a']++;

		m[pos/5][pos%5] = x;
		pos++;
	}
}

pii find(char c){
	fr(i, 5){
		fr(j, 5){
			if(m[i][j] == c) return mp(i, j);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	string s;
	deque<char> q;

	getline(cin, s);

	fr(i, s.size()){
		if(s[i] == ' ') continue;
		else build(s[i]);
	}

	fr(i, 26){
		if(i + 'a' == 'q') continue;
		build(i + 'a');
	}


	while(cin >> s){
		for(auto x: s) q.push_back(x);
	}
/*
	fr(i, 5){
		fr(j, 5) cout << m[i][j] << " ";
		cout << endl;
	}
*/
	vector<int> ans;

	while(q.empty() == 0){
		char um = q.front();
		q.pop_front();

		if(q.empty()){
			q.push_front('x');
			q.push_front(um);
			continue;
		}

		char dois = q.front();
		q.pop_front();

		if(um == dois){
			q.push_front(um);
			q.push_front('x');
			q.push_front(dois);

			continue;
		}

		//cout << um << " " << dois << endl;

		pii p1 = find(um), p2 = find(dois);

		if(p1.f == p2.f){
			//cout << m[p1.f][(p1.f + 1)%5] << " ||| " << m[p2.f][(p2.f + 1)%5] << endl;
			ans.pb(m[p1.f][(p1.s + 1)%5]);
			ans.pb(m[p2.f][(p2.s + 1)%5]);
		}
		else if(p1.s == p2.s){
			//cout << m[(p1.s + 1)%5][p1.s] << " ||| " << m[(p2.s + 1)%5][p2.s] << endl;
			ans.pb(m[(p1.f + 1)%5][p1.s]);
			ans.pb(m[(p2.f + 1)%5][p2.s]);
		}
		else{
			ans.pb(m[p1.f][p2.s]);
			ans.pb(m[p2.f][p1.s]);
		}
	}

	for(auto x: ans){
		cout << (char)(x - 'a' + 'A');
	}
	cout << endl;
}
