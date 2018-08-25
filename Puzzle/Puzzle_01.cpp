#include<iostream>
using namespace std;

int main(){
    int mat[3][3][1024],final[3][3];
    int x=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                if(i!=j&&j!=k&&i!=k){
                    if(i/j/k==3){
                        cout<<i<<" / "<<j<<" / "<<k<<" = "<<3<<endl;
                        mat[0][0][x]=i;
                        mat[0][1][x]=j;
                        mat[0][2][x]=k;
                        
                    }
                    if(i*j+k==43){
                        //cout<<i<<" / "<<j<<" / "<<k<<" = "<<3<<endl;
                        mat[0][0][x]=i;
                        mat[1][0][x]=j;
                        mat[2][0][x]=k;
                    
                        cout<<i<<" x "<<j<<" + "<<k<<" = "<<43<<endl;
                    }
                    if(i+j*k==16){
                        //cout<<i<<" / "<<j<<" / "<<k<<" = "<<3<<endl;
                        mat[1][0][x]=i;
                        mat[1][1][x]=j;
                        mat[1][2][x]=k;
                    
                    cout<<i<<" + "<<j<<" x "<<k<<" = "<<16<<endl;
                    }
                    if(i+j-k==10){
                        //cout<<i<<" / "<<j<<" / "<<k<<" = "<<3<<endl;
                        mat[2][0][x]=i;
                        mat[2][1][x]=j;
                        mat[2][2][x]=k;
                    cout<<i<<" + "<<j<<" - "<<k<<" = "<<10<<endl;
                    }
                    if(i-j+k==9){
                        //cout<<i<<" / "<<j<<" / "<<k<<" = "<<3<<endl;
                        mat[0][1][x]=i;
                        mat[1][1][x]=j;
                        mat[2][1][x]=k;
                    cout<<i<<" - "<<j<<" + "<<k<<" = "<<9<<endl;
                    }
                    if(i*j-k==1){
                        //cout<<i<<" / "<<j<<" / "<<k<<" = "<<3<<endl;
                        mat[0][2][x]=i;
                        mat[1][2][x]=j;
                        mat[2][2][x]=k;
                        cout<<i<<" x "<<j<<" - "<<k<<" = "<<1<<endl;
                    }
                    x++;
                }
            }
        }
    }
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            for(int q=0;q<=x;q++){
                for(int w=0;w<=x;x++){
                    if(mat[i][j][q]==mat[i][j][w]){
                        final[i][j]=mat[i][j][q];
                    }
                }
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<final[i][j]<<'\t';
        }
        cout<<endl<<endl;
    }
}