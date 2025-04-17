#include<iostream>
using namespace std;

int decTobinary(int decNum){
    int ans=0, pow=1;
    while(decNum>0){
        int rem=decNum%2;
        decNum=decNum/2;
        ans+=(rem*pow);
        pow=pow*10;
    }
    return ans;
}

int binaryToDec(int binNum){
    int ans=0, pow=1;
    int rem;
    while(binNum>0){
        rem=binNum%10;
        binNum/=10;
        ans+=(rem*pow);
        pow*=2;
    }
    return ans;
}

int main(){
    int num=15;
    cout<< decTobinary(num) << endl;

    int num2=1011001;
    cout<< "The decimal form of " << num2 << " is: " << binaryToDec(num2);
}