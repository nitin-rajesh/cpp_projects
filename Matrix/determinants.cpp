#include<iostream>
using namespace std;
int det2x2(int mat[2][2]){
    return mat[0][0]*mat[1][1]+mat[0][1]*mat[1][0];
}
int det3x3(int mat[3][3]){
    int mini[2][2];
    //int*minP=mini[0];
    for(int i=0;i<3;i++){
    	switch(i){
    	    case 0:
    	    	mini[0][0]=mat[1][1];
    	    	mini[0][1]=mat[1][2];
    	}
    }
}
void minorIty(int mat[3][3], int minor[2][2], int i, int j){
    int *pBig=mat[3];
    int *pMin=minor[0];
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            if(pBig==&mat[x][j]||pBig==&mat[i][y]){
                pBig++;
                continue;
            }
            else{
                *pMin=*pBig;
                pMin++;
                pBig++;
            }
        }    
    }
}
int coFactor(int mat[3][3],int i, int j){
    int minor[2][2];
    int*P=mat[0], *minP=minor[0];
    minorIty(mat, minor, i, j);
}

void matAdjoint(int mat[3][3]){
	int matCopy[3][3];
	
	for(int i=0, *p1=mat[0], *ptr2=matCopy[0]; i<9;i++,ptr1++,ptr2++){
	    *p2=*p1;
	}
	
	for(int i=0;i<3;i++){
	    for(int j=0;j<3;j++){
	        matCopy[i][j]=coFactor(mat,i,j);
	        
	    }
	}	
}
int main(){
    int det[3][3]={1,2,3,4,5,6,7,8,9};
    int minor[2][2];
    int*loc=det[0];
    minorIty(det,minor,1,1)
    for(int x=0;x<2;x++){
        for(int y=0;y<2;y++){
            cout<<minor[x][y]<<'\t';
        }
        cout<<endl
    
    }
    
}
