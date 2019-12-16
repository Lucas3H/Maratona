#include<bits/stdc++.h>

using namespace std;

int main(){
	string p;
	char resp[50010];
	int ind = 0;

	bool up = 1;

	while(cin >> p){
		vector<char> fortes, fmin;

		if(p[0]>='A' && p[0] <='Z') up = 1;
		else up = 0;

		if(up){
			fortes = {'B', 'C', 'D', 'G', 'K', 'N', 'P', 'T'};
		}
		else{	
			fortes = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};
		}

		fmin = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};

		char cmin = 200;
		for(char cf: fortes){
			if(abs(cf - p[0]) < abs(cmin - p[0])) cmin = cf;
		}

		p[0] = cmin;
		resp[ind] = p[0];
		ind++;

		bool prim = 1;

		for(int i = 1; i < p.size(); i++){
			if(p[i] == '-') prim = 0;

			if(!prim && binary_search(fmin.begin(), fmin.end(), p[i])){
				p[i] = tolower(p[0]);
				resp[ind] = p[i];
				ind++;
			}
			else if(p[i] != '-'){
				resp[ind] = p[i];
				ind++;
			}
		}

		if(tolower(p.back()) == 98 || tolower(p.back()) == 99 || tolower(p.back()) == 100 || tolower(p.back()) == 103){
			resp[ind] = 'a';
			ind++;
			resp[ind] = 'h';
			ind++;
		}
		else if(tolower(p.back()) == 107 || tolower(p.back()) == 110 || tolower(p.back()) == 112){
			resp[ind] = 'o';
			ind++;
			resp[ind] = 'h';
			ind++;	
		}
		else if(tolower(p.back()) == 116){
			resp[ind] = 'u';
			ind++;
			resp[ind] = 'h';
			ind++;
		}

		resp[ind] = ' ';
		ind++;
	}

	for(int i = 0; i < ind; i++) printf("%c", resp[i]);
	
}