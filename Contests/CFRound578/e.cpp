#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, int> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 1000010
#define MOD 1000000007

char ans[MAXN];

int main(){
		ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int size_prev;
    size_prev = s.size();

    fr(i, size_prev) ans[i] = s[i];
    int ind = size_prev;

    n--;
    while(n--){
        cin >> s;

				int a = 0;
				for(int i = s.size() - 1; i>=0; i--){
						int j = 0;
						while(j <= i && j+1 <= ind && ans[ind - i + j - 1] == s[j]) j++;

						if(j == i + 1){
								a = j;
								break;
						}
				}


				for(int i = a; i < s.size(); i++) ans[ind++] = s[i];

    }

    fr(i, ind) cout << ans[i];
    cout << endl;
}
