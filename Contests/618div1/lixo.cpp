#include<bits/stdc++.h>

using namespace std;

int main(){
    FILE * myFile;
    
    myFile = fopen("in.txt", "w");
    
    fprintf(myFile, "%d %d ", 1000000, 2);
    for(int i = 0; i < 99999; i++) fprintf(myFile, "%d ", 1);

    fclose(myFile);
}