#include<iostream>
using namespace std;

int main(){
    char str[] = {'a','b','c','d','\0'};
    cout << str << endl;

    char s[10];
    char s2[200];
    cout << "Enter: ";
    cin >> s;
    cin.getline(s2,100,'$');
    cout <<s2 <<endl;

    return 0;
}