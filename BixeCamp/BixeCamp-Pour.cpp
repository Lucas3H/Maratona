#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
	int d = a + b;

	a = max(a, b);
	b = d - a;

	while(a%b != 0){
		d = a;
		a = max(a - b, b);
		b = d - a;
	}

	return b;
}

int main(){
	int testes;
	cin >> testes;

	for(int i = 0; i < testes; i++){
		int a, b, c;

		cin >> a >> b >> c;
	
		int d = mdc(a, b);

		if(c > max(a, b) || c%d != 0) cout << -1 << endl;
		else if(c == a || c == b) cout << 1 << endl;
		else{

			int resp1 = 0, v_a = 0, v_b = 0;

			while(v_a != c && v_b != c){
				if(v_a == 0){
					resp1++;
					v_a = a;

				}
				else{
					while(v_a > 0 && v_a != c && v_b != c){
						resp1++;
						int y = v_b;
						v_b += min(b - y, v_a);
						v_a -= min(b - y, v_a);

						if(v_b == b && v_a != c && v_b != c){
							v_b = 0;
							resp1++;
						}
					}
				}
			}
			
			int x = a, resp2 = 0;
			a = b;
			b = x;
			v_a = 0;
			v_b = 0;

			while(v_a != c && v_b != c){
				if(v_a == 0){
					resp2++;
					v_a = a;

				}
				else{
					while(v_a > 0 && v_a != c && v_b != c){
						resp2++;
						int y = v_b;
						v_b += min(b - y, v_a);
						v_a -= min(b - y, v_a);

						if(v_b == b && v_a != c && v_b != c){
							v_b = 0;
							resp2++;
						}
					}
				}
			}

			cout << min(resp1, resp2) << endl;
		}
	}

	return 0;
}