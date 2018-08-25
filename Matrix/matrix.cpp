#include<iostream>
#include<string.h>
using namespace std;
//int r,c, max;
int m[32][32][16];
void matPrint(int, int, int);
void matProd(int, int, int, int);
void matReset(int, int, int);
void matIn(int, int, int);
bool checkRep();
//void matReset(int r, int c, int s);

int main(){
    int r1, c1, r2, c2, s=0;
    bool doAgain;
    cout<<"Matrix op\n";
    //cout<<"Number of matrices: ";
    //cin>>n;
        
    //for(s=0;s<n;){
    cout<<"Matrix "<<s+1<<'\n';
    //if(s==0){
    cout<<"Enter number of rows: ";
    cin>>r1;
    //}
    cout<<"Enter number of columns: ";
    cin>>c1;
    matReset(r1,c1,s);
    matPrint(r1,c1,s);
    matIn(r1,c1,s);
    matPrint(r1,c1,s);
    do{
        //}
        s++;
        r2=c1;
		cout<<"Tr00l\n";
        cout<<"Matrix "<<s+1<<"\nEnter no. of columns: ";
        cin>>c2;
        //cout<<'\n'<<s<<'\t'<<r2<<'\t'<<c2;
        matReset(r2,c2,s);
        matPrint(r2,c2,s);
        matIn(r2,c2,s);
        s++;
        matProd(r1,c2,r2,s);
        matPrint(r1,c2,s);
        c1=c2;
        doAgain=checkRep();
    }
    while(doAgain);
}


void matPrint (int r, int c, int max){
	cout << "\033[2J\033[1;1H";
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		cout/*<<i<<':'<<j<<'-'*/<<m[i][j][max]<<'\t';
		}
		cout<<'\n';
	}
	return ;
}
void matProd(int r1,int c2, int r2, int s){
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			m[i][j][s]=0;
			for(int k=0; k<r2;k++){
				m[i][j][s]+=m[i][k][s-2]*m[k][j][s-1];
			}
		}
	}
    return ;
}
void matReset(int r, int c, int s){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            m[i][j][s]=0;
        }
    }
}
void matIn(int r, int c, int s){
   for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            matPrint(r,c,s);
            cin>>m[i][j][s];
        }
    } 
}
bool checkRep(){
    char oui[5];
    cout<<"One more matrix?\n";
    cin>>oui;
        if(strcmp(oui,"yes")==0||strcmp(oui,"YES")==0)
            return 1;
        else
            return 0;
}
