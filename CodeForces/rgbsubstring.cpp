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

int main(){
		ios::sync_with_stdio(false);

    int q;
    cin >> q;

    while(q--){
      int n, k;
      cin >> n >> k;

      string s;
      cin >> s;

      int t1 = 0, t2 = 0, t3 = 0;

      fr(i, k){
        if(i%3 == 0){
          if(s[i] == 'R'){
            t2++;
            t3++;
          }
          else if(s[i] == 'G'){
            t1++;
            t2++;
          }
          else{
            t1++;
            t3++;
          }
        }
        else if(i%3 == 1){

          if(s[i] == 'R'){
            t1++;
            t3++;
          }
          else if(s[i] == 'G'){
            t2++;
            t3++;
          }
          else{
            t1++;
            t2++;
          }
        }

        else{
          if(s[i] == 'R'){
            t2++;
            t1++;
          }
          else if(s[i] == 'G'){
            t1++;
            t3++;
          }
          else{
            t2++;
            t3++;
          }
        }
      }

      int m = min(t1, min(t2, t3));


		//	cout << q << " " << t1 << " " << t2 << " " << t3 << endl;

      for(int i = k; i < n; i++){

        if(i%3 == 0){
          if(s[i] == 'R'){
            t2++;
            t3++;
          }
          else if(s[i] == 'G'){
            t1++;
            t2++;
          }
          else{
            t1++;
            t3++;
          }
        }
        else if(i%3 == 1){

          if(s[i] == 'R'){
            t1++;
            t3++;
          }
          else if(s[i] == 'G'){
            t3++;
            t2++;
          }
          else{
            t1++;
            t2++;
          }
        }

        else{
          if(s[i] == 'R'){
            t2++;
            t1++;
          }
          else if(s[i] == 'G'){
            t1++;
            t3++;
          }
          else{
            t2++;
            t3++;
          }
        }


          if((i-k)%3 == 0){
            if(s[i-k] == 'R'){
              t2--;
              t3--;
            }
            else if(s[i-k] == 'G'){
              t1--;
              t2--;
            }
            else{
              t1--;
              t3--;
            }
          }
          else if((i-k)%3 == 1){

            if(s[i-k] == 'R'){
              t1--;
              t3--;
            }
            else if(s[i-k] == 'G'){
              t3--;
              t2--;
            }
            else{
              t1--;
              t2--;
            }
          }

          else{
            if(s[i-k] == 'R'){
              t2--;
              t1--;
            }
            else if(s[i-k] == 'G'){
              t1--;
              t3--;
            }
            else{
              t2--;
              t3--;
            }
          }

        m = min(m, t1);
        m = min(m, t2);
        m = min(m, t3);

			//	cout << q << " " << t1 << " " << t2 << " " << t3 << endl;
      }

      cout << m << endl;
    }
}
