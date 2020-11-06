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

int n;
struct show{
  int ini, fim, song, stage;
};

bool ord(show a, show b){
  return a.ini < b.ini;
}

vector<show> s;

int memo[1001][1100];

int dp(int ind, int mask){
  //cout << mask << endl;
  if(ind == s.size() && mask + 1 != (1 << n)) return -10000000;
  if(mask + 1 == (1 << n) && ind == s.size()) return 0;
  if(memo[ind][mask] >= -10000000) return memo[ind][mask];

  int ans = dp(ind+1, mask);

  int in = ind, fi = s.size() - 1, meio;

  fr(i, 13){
    meio = (in + fi)/2;

    if(s[meio].ini >= s[ind].fim) fi = meio;
    else in = meio;
  }

  //cout << "OKOdas " << (mask|(1 << (s[ind].stage))) << endl;
  if(s[ind].fim > s[s.size() - 1].ini) fi = s.size();

  ans = max(ans, dp(fi, (mask|(1 << (s[ind].stage)))) + s[ind].song);

  //if(ans > 0) cout << mask << " "  << ans << endl;
  return memo[ind][mask] = ans;

}

int main(){
		ios::sync_with_stdio(false);

    cin >> n;
    fr(i, n){
      int k;
      show S;
      cin>> k;

      fr(j, k){
          cin >> S.ini >> S.fim >> S.song;
          S.stage = i;
          s.pb(S);
      }
    }

    fr(i, s.size()){
      fr(j, (1 << n)) memo[i][j] = -10000001;
    }

    sort(s.begin(), s.end(), ord);

    int d = dp(0, 0);
    if(d < 0) cout << -1 << endl;
    else cout << d << endl;

}
