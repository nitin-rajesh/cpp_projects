#include<iostream>
using namespace std;
class B;
class A{
    private:
        int a;
    public:
        A(){
            a=5;
        }
        friend void hackMe(A,B);
};
class B{
    private:
        int b;
    public:
        B(){
            b=10;
        }
        friend void hackMe(A,B);
};
void hackMe(A lol, B yolo){
    cout<<lol.a+yolo.b;
} 
int main(){
    A dext;
    B rext;
    hackMe(dext,rext);
    
}
