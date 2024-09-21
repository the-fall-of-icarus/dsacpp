#include <bits/stdc++.h>
using namespace std;


void printName(string name){
    cout << "Hello, "<< name << "!" << endl;
}

int sum(int a, int b){
    int sum = a+b;
    return sum;
}
int main(){

    /*
    string name;
    cin >> name;
    printName(name);

    int a, b, ans;
    cin >> a >>b;
    ans = sum(a,b);
    cout << ans;
    */
    
    //INBUILT FUNCTIONS
    int num1, num2;
    cin >> num1 >> num2;
    int maximum = max(num1, num2);
    cout << maximum;
    
    return 0;
}
