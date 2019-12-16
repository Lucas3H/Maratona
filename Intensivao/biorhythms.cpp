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

void EuclideanExtended(int a, int b, int *x, int *y){
  if(b == 0){
    *x = 1;
    *y = 0;

    return;
  }

  int x0, y0;
  EuclideanExtended(b, a%b, &x0, &y0);

  *x = y0;
  *y = x0 - (a/b)*y0;
}

int main(){
		ios::sync_with_stdio(false);

    int inv28[28], inv23[23], inv33[33];
    int x, y;
    frr(i, 27){
      EuclideanExtended(i, 28, &x, &y);
      inv28[i] = (x+28)%28;
    }

    frr(i, 22){
      EuclideanExtended(i, 23, &x, &y);
      inv23[i] = (x+23)%23;
    }

    frr(i, 32){
      EuclideanExtended(i, 33, &x, &y);
      inv33[i] = (x+33)%33;
    }

    int p, e, i, d;
    cin >> p >> e >> i >> d;
    int tests = 1;
    int cnt = 28*23*33;

    while(p != -1){
      ll k = 28*33*inv23[(28*33)%23]*p + 23*33*inv28[(23*33)%28]*e + 23*28*inv33[(23*28)%33]*i;

      k = (k+cnt)%(cnt);

  //    cout << k << " " << k%23 << " " << k%28 << " " << k%33 << endl;

      if(d < k) cout << "Case " << tests << ": " << "the next triple peak occurs in " << k - d<<" days."<< endl;
      else  cout << "Case " << tests << ": " << "the next triple peak occurs in " << k + 23*28*33 - d<<" days."<< endl;

      cin >> p >> e >> i >> d;
      tests++;
    }
}
