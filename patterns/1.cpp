#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    for(i=0; i<5; i++){
        for(j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    for(i=1; i<=5; i++){
        for(j=1; j<=i; j++){
            cout << j;
        }
        cout << endl;
    }

    cout << endl;
    for(i=1; i<=5; i++){
        for(j=1; j<=i; j++){
            cout << i;
        }
        cout << endl;
    }

    return 0;
}