#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second
typedef pair<int,int> pii;
typedef pair<int, int> pint;
typedef pair<double, double> ponto;
typedef vector<vector<int>> matrix;

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

struct complex_t {
  double a {0.0}, b {0.0};
  complex_t() {}
  complex_t(double na, double nb) : a{na}, b{nb} {}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
  }
};

const int MAX_SUM = 1 << 10;
#define MAXS 1000010

struct FFT{
  const double PI = acos(-1);

  using cd = complex<double>;
  void fft(vector<cd> & a, bool invert) {
      int n = a.size();
      if (n == 1)
          return;

      vector<cd> a0(n / 2), a1(n / 2);
      for (int i = 0; 2 * i < n; i++) {
          a0[i] = a[2*i];
          a1[i] = a[2*i+1];
      }
      fft(a0, invert);
      fft(a1, invert);

      double ang = 2 * PI / n * (invert ? -1 : 1);
      cd w(1), wn(cos(ang), sin(ang));
      for (int i = 0; 2 * i < n; i++) {
          a[i] = a0[i] + w * a1[i];
          a[i + n/2] = a0[i] - w * a1[i];
          if (invert) {
              a[i] /= 2;
              a[i + n/2] /= 2;
          }
          w *= wn;
      }
  }

  vector<int> multiply(vector<int> & a, vector<int> & b) {
      vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
      int n = 1;
      while (n < a.size() + b.size()) 
          n <<= 1;
      fa.resize(n);
      fb.resize(n);

      fft(fa, false);
      /*
      cout << "--------------dentro4\n";
      fr(i, 50) cout << fb[i].real() <<' ';
      cout << endl;
      cout << "--------------dentro4\n";
      */

      fft(fb, false);
      /*
      cout << "--------------dentro2\n";
      fr(i, 50) cout << fb[i].real() <<' ';
      cout << endl;
      cout << "--------------dentro2\n";
      */
      for (int i = 0; i < n; i++)
          fa[i] *= fb[i];
      fft(fa, true);

      vector<int> result(n);
      for (int i = 0; i < n; i++)
          result[i] = round(fa[i].real());
      return result;
  }

  vector<int> fastxp(vector<int> & a, int exp){
    if(exp == 1) return a;

    vector<int> ret = fastxp(a, exp/2);
    
    ret = multiply(ret, ret);
    if(exp%2 == 1) ret = multiply(ret, a);
    
    return ret;
  }
};

int n, k;
FFT f;

int main(){
  ios::sync_with_stdio(false);

  vector<int> v(1001), ans(1001);

  cin >> n >> k;

  int maior = 0;

  fr(i, n){
    int aux;
    cin >> aux;
    maior = max(maior, aux);

    v[aux] = ans[aux] = 1;
  }

  ans = f.fastxp(ans, k);
  FFT F;
  
  int resp = 0;
  fr(i, ans.size()) if(ans[i]) cout << i << " ";
  cout << endl;
}
