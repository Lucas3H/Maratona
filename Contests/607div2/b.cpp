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

#define MAXN 50010
#define MOD 1000000007

int main(){

	int t;
	scanf("%d", &t);

	char s[5010], c[5010];
	int ts, tc;

	fr(teste, t){
		scanf("%s %s", s, c);
		ts = strlen(s);
		tc = strlen(c);
		
		if(teste == 42) {
			cout << "---\n";
			cout << s <<" " << c << endl;
		}
		pii v[MAXN];
		fr(i, ts) v[i] = mp(s[i], i);

		sort(v, v + ts);

		int pos1 = -1, pos2 = -1;
		fr(i, ts){
			if(v[i].f == (int)s[i]) continue;
			pos1 = i;
			pos2 = v[i].s;
			break;
		}

		if(pos1 != -1){
			swap(s[pos1], s[pos2]);
//			cout << pos1 << ' ' << pos2 << endl;
		}

		int deu = 0;
		fr(i, min(ts, tc)){
			if(s[i] == c[i]) continue;
			else if(s[i] < c[i]){
				deu = 1;
				break;
			}
			else if(s[i] > c[i]){
				deu = -1;
				break;
			}
		}

		if(deu == 0){
			if(ts >= tc) printf("---\n");
			else printf("%s\n", s);
		}
		else if(deu == 1) printf("%s\n", s);
		else printf("---\n");
	}
}
