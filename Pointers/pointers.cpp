#include<iostream>
using namespace std;
int main(){
    int a;
    int*p=&a;
    *p=10;
    cout<<p<<'\t'<<*p<<endl;
    cout<<++p;
    *p=10;
    cout<<*p<<endl;
}