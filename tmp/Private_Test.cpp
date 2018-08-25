#include<iostream>
using namespace std;

class Holder{
    int a;
    public:
    void setA(int x){
        a=x;
    }
        static int sum(Holder A, Holder B){
            return A.a + B.a;
        }
};

int main(){
    Holder A, B;
    A.setA(12);
    B.setA(15);
    cout<<"Sum1 "<<Holder::sum(A,B)<<endl;
    //cout<<"Sum2"<<B.sum(A,B)<<endl;
}