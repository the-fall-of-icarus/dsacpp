#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //for 
    cout << "FOR LOOP" << endl;
    int i;
    for(i=0; i<=3; i++){
        for(int j=0; j<=3; j++){
            cout << i << " " << j << endl;
        }
        
    }

    //while
    cout << "\nWHILE LOOP" << endl;
    int k=0;
    while(k != 5){
        cout << k << endl;
        k++;
    }

    //do-while
    cout << "\nDO_WHILE" << endl;
    int l=0;
    do {
        cout << l << endl;
        l++;
    } while (l<3);
    cout << "l after the loop: " << l << endl;
}