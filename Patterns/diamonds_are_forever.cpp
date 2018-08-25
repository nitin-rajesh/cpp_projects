#include<iostream>
using namespace std;
#define line cout<<endl
#define clear cout<<"\033[2J\033[;H"

void diamondsAreForever(int n, char c, bool fill, bool num, bool invert){
    int i=0,j,k, pos1, pos2;
    bool flip=false;
    clear;
    char c1=c,c2=' ';
    if(invert){
        c1=' ';
        c2=c;
    }
    while(i>=0){
        pos1=n-i;
        pos2=n+i;
        k=1;
        //cout<<i;
        for(j=1;j<n*2;j++){
            if(invert&&((i==(n-1))||((i==(n-2)&&flip))))
                break;
            if(j==pos1){
                if(num)
                    cout<<k;
                else
                    cout<<c1;
            }
            else if(j==pos2){
                if(num){
                    k=1;
                    if(k<10)
                        cout<<k;
                    else 
                        cout<<'0';
                }
                else
                    cout<<c1;
                
            } else if(j>pos1&&j<pos2) {
                if(fill){
                    if(j<=n)
                        k++;
                    else
                        k--;
                    if(num&&!invert)
                        if(k<10)
                            cout<<k;
                        else 
                            cout<<'0';
                    else
                        cout<<c1;
                }else{
                    cout<<c2;
                }
                
            } else{
                cout<<c2;
            }
            
        }
        if(invert&&((i==(n-1))||((i==(n-2)&&flip)))){}
        else
            line;
        if(i<n&&!flip)
            i++;
        if(i==n){
            flip=true;
            i--;
        }
        if(flip)
            i--;
    }
}

int main(){
    int r; 
    char c;
    bool fill, num, invert;
    clear;
    cin>>r>>c>>fill>>num>>invert;
    line;
    diamondsAreForever(r,c,fill,num,invert);
    line;
}