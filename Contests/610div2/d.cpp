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
#define MAXL 30
#define ROOT 1

int main(){
	ios::sync_with_stdio(false);
	int ans1, ans2, tam;
	cout << 'a' << endl;
	cin >> ans1;

	fr(i, ans1) cout << 'b';
	cout << endl;
	cin >> ans2;

	if(ans2 == 0){
		fr(i, ans1) cout << 'b';
		cout << endl;
	}
	else if(ans1 == ans2-1){
		fr(i, ans2) cout << 'a';
		cout << endl;
	}
	else{
		tam = ans1+1;

		char s[501];
		fr(i, tam) s[i] = 'b';

/*ans2 é a quantidade de a's na string*/
		ans1 = ans2;

		fr(j, tam){
			s[j] = 'a';
			fr(i, tam){
				cout << s[i];
			}
			cout << endl;
			cin >> ans2;

			if(ans2 == 0) break;

			if(ans2 >= ans1) s[j] = 'b';

			ans1 = ans2;
		}
	} 


}
