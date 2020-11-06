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

#define MAXN 100010
#define MOD 1000000007

int mov_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int mov_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int i, int j){

}

int main(){
		ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
      char a, b;
      cin >> a >> b;
      bfs(a - 'a', b - '1');

      cin >> a >> b;

      cout << dist[a - 'a'][b - '1'];
    }
}
