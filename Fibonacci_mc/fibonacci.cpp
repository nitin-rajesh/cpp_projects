#include<iostream>
#include<chrono>
#include<string.h>
using namespace std;
using namespace std::chrono;
unsigned long int badFibo(int);
unsigned long int goodFibo(int);
unsigned long int badFibo(int x){
    if(x==0)
        return 0;
    if (x==1)
        return 1;
    return badFibo(x-1)+badFibo(x-2);
}
unsigned long int goodFibo(int x){
    unsigned long int a=0, b=1;
    for(int C=1;C<=x/2;C++){
        a=a+b;
        b=b+a;
        //cout<<C<<". a: "<<a<<"\nb: "<<b<<endl;
    }
    if(x%2==0)
        return b;
    else
        return a;
}
int main(int argc,const char * argv[]){
    unsigned int fibo;
    char gb[4];
    cout<<"\033[2J\033[1;1HWe have begun!\nHow many? ";
    cin>>fibo;
    cout<<"Do you want to waste time?\n";
    cin>>gb;
    fibo=fibo==0?1:fibo;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    if(strcmp(gb,"yes")==0||strcmp(gb,"YES")==0||strcmp(gb,"Yes")==0){
        for (int i=1;i<=fibo;i++){
            cout<<badFibo(i)<<'\t';
            i%8==0?cout<<endl:cout<<'\0';
        }
    }
    else{
        for (int i=0;i<fibo;i++){
            cout<<goodFibo(i)<<'\t';
            i%8==0?cout<<endl:cout<<'\0';
        }
    }
    cout<<endl;
    //0 1 1 2 3 5 8 13 21 34
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    double duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout <<"\nProcess returned in "<<duration/1000000<<" seconds"<<endl;
}
