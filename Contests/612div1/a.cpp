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

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;


	int even = n/2;
	int odds = n - even;

	int a[MAXN];
	fr(i, n) {
		cin >> a[i];
		if(a[i]%2 == 0) even--;
		else odds--;
	}

	int number_switches = 0;

	pq<int, vector<int>, greater<int>> between_odds;
	pq<int, vector<int>, greater<int>> between_even;

	int tam_block = 0;
	int last;
	int i = 0;

	pii first_block;
	pii last_block;

	while(i < n && a[i] == 0){
		i++;
		tam_block++;
	}

	if(tam_block > 0){
		if(a[i]%2 == 0) first_block = mp(tam_block, 1);
		else  first_block = mp(tam_block, 0);

		tam_block = 0;
	}

	last = a[i];

	while(i < n){
		if(a[i] == 0){
			while(i < n && a[i] == 0){
				i++;
				tam_block++;
			}

			if(i == n) {
				if(a[i]%2 == 0) last_block = mp(tam_block, 1);
				else  last_block = mp(tam_block, 0);
				
			}

			if((a[i] - last)%2 == 0){
				if((a[i])%2 == 0) between_even.push(tam_block);
				else between_odds.push(tam_block);
			}

			tam_block = 0;	
		}
		else{
			if((a[i] - last)%2 != 0) {
				number_switches++;
				//cout << a[i] << " " << last << " " << i << endl;
			}
			last = a[i];
			i++;
		}
	}

	int ans = 0;

	while(!between_odds.empty() && odds >= between_odds.top()){
	//	cout << odds << " " << between_odds.size() << endl;
		odds-=between_odds.top();
		between_odds.pop();
	}

	number_switches += 2*between_odds.size();

	while(!between_even.empty() && even >= between_even.top()){
	//	cout << even << " " << between_even.size() << endl;
		
		even-=between_even.top();
		between_even.pop();
	}

	number_switches += 2*between_even.size();

	cout << number_switches << endl;
}
