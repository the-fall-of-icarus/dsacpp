#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k;

/*
    cout << endl;
    for(i=5; i>0; i--){
        for(j=i; j>0; j--){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    for(i=5; i>=1; i--){
        for(j=i; j>=1; j--){
            cout << j;
        }
        cout << endl;
    }

    cout << endl;
    int rows = 5; 
    for (int i = 1; i <= rows; ++i) {
        //spaces
        for (int j = 1; j <= rows - i; ++j) {
            cout << " ";
        }
        //stars
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "*";
        }
        
        cout << endl;
    }
    
    cout << endl;
    
    for(int i = 0; i <= 5; i++){
        for (int j = 0; j <i; j++){
            cout << " ";
        }
        for (int k=0; k< 11 - 2 * i; k++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    for (i=0; i< 6; i++){
        for(j =0; j<5 - i; j++){
            cout << " ";
        }
        for(k =0; k < (2*i+1); k++){
            cout << "*";
        }
        cout << endl;
    }

    for(i=5; i>0; i--){
        for(j =0; j<=(5 - i); j++){
            cout << " ";
        }
        for (k=1; k<=(2*i -1); k++){
            cout << "*";
        }
        cout << endl; 
    }
    for(i=0; i<6; i++){
    for(j=0; j<i; j++){
        cout << "*";
    }
    cout << endl;
   }
   for(i=4; i>=1; i--){
        for(j=i; j>=1; j--){
            cout << "*";
        }
        cout << endl;
    }

    for (i=0; i<=5; i++){
    for (j=0; j<i; j++){
        if((i+j)%2 == 0){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    cout << endl;
   }

   int r = 5;
    int space = 2 * (r - 1);

    for(i = 1; i <= r; i++) {
        // Print increasing numbers
        for(j = 1; j <= i; j++) {
            cout << j;
        }
        
        // Print spaces
        for(j = 1; j <= space; j++) {
            cout << " ";
        }
        
        // Print decreasing numbers
        for(j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
        space -= 2; 
    }
*/

    int num=1;
    for (int i=1; i<=5; i++){
        for(int j=1; j<=i; j++){
            cout << num << " ";
            num++;
        }
        cout<< endl;
    }

    cout<< endl;
    for(char a='A';a<='E'; a++){
        for(char ch = 'A'; ch<=a;ch++){
            cout<<ch<<" ";
        }
        cout << endl;
    }
    
    return 0;
}
    
    