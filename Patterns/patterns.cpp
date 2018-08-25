#include <iostream>
using namespace std;
#define line cout<<endl

int main(){
    int row, i, j, k, gap;
    cout<<"Enter lenght of patterns: ";
    cin>>row;
    //Ascending stars, left align
    for (i=1;i<=row;++i){
        for (j=1;j<=i;++j)
            {cout<<"*";}
        cout<<endl;
    }
    line;
    //Descending stars, left align
    for (i=row;i>=1;--i){
        for (j=i;j>=1;--j)
            {cout<<"*";}
        cout<<endl;
    }
    line;
    //Ascending stars, right align
    for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            {cout<<" ";}
        while (j<=row){

                cout<<"*";
                j++;
            }
    cout<<endl;
    }
    cout<<endl;
    //Descending stars, right align
    for (i=1;i<=row;++i){
        for (j=1;j<=i-1;++j)
            {cout<<" ";}
        while (j<=row){
            {
                cout<<"*";
                j++;
            }
        }
        cout<<endl;
    }
    line;
    //Ascending no.s, left align
    for (i=1;i<=row;++i){
        for (j=1;j<=i;++j)
            {if (j>=10)
                cout<<"0";
            else
                cout<<j;}
        cout<<endl;
    }
    line;
    //Descending no.s, left align
    for (i=row;i>=1;--i){
        for (j=1;j<=i;++j)
            {if (j>=10)
                cout<<"0";
            else
                cout<<j;}
        cout<<endl;
    }
    line;
    //Ascending no.s, right align
     for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            {cout<<" ";}
        while (j<=row){
                if (j>=10)
                cout<<"0";
            else
                cout<<j;
                j++;
            }
    cout<<endl;
    }
    line;
    //Descending no.s, right align
    for (i=1;i<=row;++i){
        for (j=1;j<=i-1;++j)
            {cout<<" ";}
        while (j<=row){
                if (j>=10)
                cout<<"0";
            else
                cout<<j;
                j++;
        }
        cout<<endl;
    }
    line;
    //Pseudo star pyramid
    for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            {cout<<" ";}
        while (j<=row){

                cout<<"* ";
                j++;
        }
        cout<<endl;
    }
    line;
    //Number pyramid
    for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            {cout<<" ";}
        for (k=i;k<=i*2-1;k++)
            if (k>=10)
            cout<<"0";
        else
            cout<<k;
        for (k-=2;k>=i;k--)
            if (k>=10)
            cout<<"0";
        else
            cout<<k;

        cout<<endl;
    }
    line;
    //Hollow Diamond
    for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            cout<<" ";
        cout<<"*";
        if (i>=2){
        for (gap=0;gap<=2*i-4;++gap)
            cout<<" ";
        cout<<"*";
        }


    cout<<endl;
    }
    for (i=1;i<=row-1;++i){
        for (j=1;j<=i;j++)
            cout<<" ";
            cout<<"*";
    if (i<row-1){
    for (j=1; j<=(row-i)*2-3;j++)
            cout<<" ";
    cout<<"*";
    }
    cout<<endl;
    }
    line;
    //Number diamond
     for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            {cout<<" ";}
        for (k=1;k<=i;k++)
            if(k>=10)
                cout<<"0";
            else
                cout<<k;
        for (k-=2;k>=1;k--)
            if(k>=10)
                cout<<"0";
            else
                cout<<k;
        cout<<endl;
    }
    for (i=1;i<row;++i){
        for (j=1;j<=i;++j)
            {cout<<" ";}
        while (j<row){
                if(j>=10)
                    cout<<"0";
                else

                    cout<<j;
                j++;

        }

        while (j>=i+1){
            if (j>=10)
                cout<<"0";
            else
                cout<<j;
            j--;
        }
        cout<<endl;
    }
    //cout<<"i: "<<i<<"j: "<<j;
    cout<<endl;
    //Star table
     for (i=1;i<=row-1;++i){
        for (j=1;j<=i;++j)
            {cout<<"*";}
        for(j=1;j<=2*(row-i)-1;j++)
            cout<<" ";
        for(j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }
    for (i=1;i<=2*row-1;++i)
        cout<<"*";
        cout<<endl;
     //Number valley
    cout<<endl;
    for (i=1;i<=row-1;++i){
        for (j=1;j<=i;++j)
            {if (j>=10)
                cout<<"0";
            else
                cout<<j;}
        for(j=1;j<=2*(row-i)-1;j++)
            cout<<" ";
        for(j=i;j>=1;j--)
            if (j>=10)
                cout<<"0";
            else
            cout<<j;
        cout<<endl;
    }
        for (i=1;i<=row;++i)
            if (i>=10)
                cout<<"0";
            else
                cout<<i;
        while(i>=2){
            if(i-2>0)
                cout<<i-2;
            i--;
        }
    cout<<endl;
    line;
    //upside down wedges+stars
         for (i=1;i<=row;++i)
            cout<<"*";
        while(i>=2){
            if(i-2>0)
            cout<<"*";
            i--;
        }
        cout<<endl;
    for (i=1;i<=row;++i)
        if(i>=2){
    for(j=1;j<=row-i+1;j++)
        cout<<"*";
    for(j=1;j<=2*i-3;j++)
        cout<<" ";
    for (j=row-i+1;j>=1;--j)
        cout<<"*";
    cout<<endl;
    }
    line;
    //Upside down wedges+no.s
     cout<<endl;
     for (i=1;i<=row;++i)
        if (i>=10)
                cout<<"0";
            else
            cout<<i;
        while(i>=2){
            if(i-2>0)
                if (i-2>=10)
                cout<<"0";
            else
            cout<<i-2;
            i--;
        }
        cout<<endl;
    for (i=1;i<=row;++i)
        if(i>=2){
    for(j=1;j<=row-i+1;j++)
        if (j>=10)
            cout<<"0";
        else
            cout<<j;
    for(j=1;j<=2*i-3;j++)
        cout<<" ";
    for (j=row-i+1;j>=1;--j)
    if (j>=10)
                cout<<"0";
            else
        cout<<j;
    cout<<endl;
    }
    line;
    //hollow no.s+rhombus
    cout<<endl;
     for (i=1;i<=row;++i)
        if (i>=10)
            cout<<"0";
        else
            cout<<i;

        while(i>=2){
            if(i-2>0)
                if (i-2>=10)
                    cout<<"0";
                else
                    cout<<i-2;
            i--;
        }
        cout<<endl;
    for (i=1;i<=row;++i)
        if(i>=2){
            for(j=1;j<=row-i+1;j++)
                if (j>=10)
                    cout<<"0";
                else
                    cout<<j;
        for(j=1;j<=2*i-3;j++)
            cout<<" ";
        for (j=row-i+1;j>=1;--j)
            if (j>=10)
                cout<<"0";
            else
                cout<<j;
        cout<<endl;
    }
    for (i=1;i<=row-1;++i){
        if(i>=2){
        for (j=1;j<=i;++j)
            {if (j>=10)
                cout<<"0";
            else
                cout<<j;}
        for(j=1;j<=2*(row-i)-1;j++)
            cout<<" ";
        for(j=i;j>=1;j--)
        if (j>=10)
                cout<<"0";
            else
            cout<<j;
        cout<<endl;
        }
     }
        for (i=1;i<=row;++i)
        if (i>=10)
                cout<<"0";
            else
            cout<<i;
        while(i>=2){
            if(i-2>0)
            if (i-2>=10)
                cout<<"0";
            else
            cout<<i-2;
            i--;
            }
     cout<<endl;
     line;
     //hollow stars+rhombus
    cout<<endl;
     for (i=1;i<=row;++i)
            cout<<'x';
        while(i>=2){
            if(i-2>0)
            cout<<'x';
            i--;
        }
        cout<<endl;
    for (i=1;i<=row;++i)
        if(i>=2){
    for(j=1;j<=row-i+1;j++)
        cout<<'x';
    for(j=1;j<=2*i-3;j++)
        cout<<" ";
    for (j=row-i+1;j>=1;--j)
        cout<<'x';
    cout<<endl;
    }
    for (i=1;i<=row-1;++i){
        if(i>=2){
        for (j=1;j<=i;++j)
            {cout<<'x';}
        for(j=1;j<=2*(row-i)-1;j++)
            cout<<" ";
        for(j=i;j>=1;j--)
            cout<<'x';
        cout<<endl;
        }
     }
        for (i=1;i<=row;++i)
            cout<<'x';
        while(i>=2){
            if(i-2>0)
            cout<<'x';
            i--;
            }
     cout<<endl;
    int arr[5]={1,2,3,5,8};
    for(int &ijk : arr){
        cout<<ijk;
    }

}


