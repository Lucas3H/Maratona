#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++) 
#define frj(j, n) for(int j = 0; j < n; j++) 
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--) 

#define pb push_back
#define erase(i) erase(v.begin() + i, v.begin() + i + 1) 
typedef pair<int,int> pii;

#define mp make_pair
#define pq priority_queue

#define ll long long

#define MAXN 100010

int main(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	//int v[MAXN];
	//stack<int> r[4];
	deque<char> l[4];

	char C, x;
	int R;
	for(int i = 0; i < q; i++){
		cin >> C >> R;

		//cout << i << endl;
		//for(int j = 0; j < n; j++) cout << v[j] << " ";

		if(C == '-'){
			//v[r[R-1].top()] = 0;
			//r[R-1].pop();
			l[R-1].pop_back();

			int j = 0;
			int a = 0, b = 0, c = 0;
			while((a < l[0].size() || b < l[1].size() || c < l[2].size()) && j < n){

			//	cout << s[j] << l[2][c] <<endl;

				if(a < l[0].size()){

					if(l[0][a] == s[j]) a++;
					else{
						if(b < l[1].size()){
							if(l[1][b] == s[j]) b++;
							else{
								if(c < l[2].size()){
									if(l[2][c] == s[j])c++;
								}
							}
						}
						else{
							if(c < l[2].size()){
								if(l[2][c] == s[j]) c++;
							}
						}
					}
				}
				else{
					cout << "ok " << j << endl;
					cout << b << l[1].size() <<endl;

					if(b < l[1].size()){
						if(l[1][b] == s[j]) b++;
						else{
							if(c < l[2].size()){
								if(l[2][c] == s[j]) c++;
							}
						}
					}
					else{

						cout << s[j] << l[2][c] <<endl;

						if(c < l[2].size()){
							if(l[2][c] == s[j]) c++;
						}
					}
				}

				j++;
			}

/*			cout << a << " " << b  << " " << c << endl;

			cout << l[0].size() << " "<< l[1].size() << " " << l[2][c] << endl;


			cout << "Size" << endl;
			cout << l[0].size() << " "<< l[1].size() << " " << l[2].size() << endl;
*/
			if(a == l[0].size() && b == l[1].size() && c == l[2].size()) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else{
			cin >> x;

			l[R-1].push_back(x);

			int j = 0;
			int a = 0, b = 0, c = 0;
		
			
			while((a < l[0].size() || b < l[1].size() || c < l[2].size()) && j < n){
				if(a < l[0].size()){
					if(l[0][a] == s[j]) a++;
					else{
						if(b < l[1].size()){
							if(l[1][b] == s[j]) b++;
							else{
								if(c < l[2].size()){
									if(l[2][c] == s[j]) c++;
								}
							}
						}
						else{
							if(c < l[2].size()){
								if(l[2][c] == s[j]) c++;
							}
						}
					}
				}
				else{
					if(b < l[1].size()){
						if(l[1][b] == s[j]) b++;
						else{
							if(c < l[2].size()){
								if(l[2][c] == s[j]) c++;
							}
						}
					}
					else{
						if(c < l[2].size()){
							if(l[2][c] == s[j]) c++;
						}
					}
				}

				j++;
			}


			cout << a << " " << b  << " " << c << endl;

			if(a == l[0].size() && b == l[1].size() && c == l[2].size()) cout << "YES" << endl;
			else cout << "NO" << endl;

		}

	}

	return 0;
}
