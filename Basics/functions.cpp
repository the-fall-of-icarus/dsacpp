#include <bits/stdc++.h>
using namespace std;


void printName(string name){
    cout << "Hello, "<< name << "!" << endl;
}

int sum(int a, int b){
    int sum = a+b;
    return sum;
}

bool isPrime(int n){
    if (n<=1){
        return false;
    }
    else{
        for(int i=2; i*i<=n; i++){
            if(n%i == 0) return false;
        }
    }
    return true;
}

void printPrime(int n){
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            cout << i << " ";
    }
    }
}

int fibo(int n){
    if(n<=1) return n;
    int a=0, b=1, next;
    for(int i=2; i<=n; i++){
        next=a+b;
        a=b;
        b=next;
    }
    return b;
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
    
    
    //INBUILT FUNCTIONS
    int num1, num2;
    cin >> num1 >> num2;
    int maximum = max(num1, num2);
    cout << maximum;
    */

    cout << "The number is prime: " << isPrime(47) < endl;
    printPrime(30);
    cout << endl;
    cout << "10th number in the fibonacci series is: " << fibo(10) << endl;
    return 0;
}
