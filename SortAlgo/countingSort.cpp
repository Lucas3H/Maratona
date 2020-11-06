#include<bits/stdc++.h>

using namespace std;

#define RANGE 10

void countSort(int v[], int tam){
    int countArr[RANGE + 1];

    memset(countArr, 0, sizeof(countArr));

    for(int i = 1; i <= tam; i++){
        countArr[v[i]]++;
    }    

    for(int i = 1; i <= RANGE; i++){
        countArr[i] += countArr[i-1];
    }

    int aux[tam + 1];

    for(int i = 1; i <= tam; i++){
        aux[countArr[v[i]]] = v[i];
        countArr[v[i]]--;
    }

    for(int i = 1; i <= tam; i++){
        v[i] = aux[i];
    }
}

int main(){
    int n;
    cin >> n;

    int arr[100010];

    for(int i = 1; i <= n; i++) cin >> arr[i];

    countSort(arr, n);

    for(int i = 1; i <= n; i++) cout << arr[i] << " ";

    cout << endl;
}