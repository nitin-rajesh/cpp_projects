#include <iostream>
using namespace std;
#define line cout<<endl
#define vitals i,j,k,gap
void starHeaps(int);
void numHeaps(int);
void psuedoStarPyr(int);
void numPyr(int);
void hollowDiamond(int);
void numDiamond(int);
void starWedges(int);
void numWedges(int);
void starRhombus(int);
void numRhombus(int);

void starHeaps(int row){
    int vitals;
    //Ascending stars, left align
    for (i=1;i<=row;++i){
        for (j=1;j<=i;++j)
            {
                cout<<"*";
            }
        line;
    }
    line;
    //Descending stars, left align
    for (i=row;i>=1;--i){
        for (j=i;j>=1;--j)
            {
                cout<<"*";
            }
        line;
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
    line;
    }
    line;
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
        line;
    }
    line;
}
void numHeaps(int row){
    int vitals;
    //Ascending no.s, left align
    for (i=1;i<=row;++i){
        for (j=1;j<=i;++j)
            {if (j>=10)
                cout<<"0";
            else
                cout<<j;}
        line;
    }
    line;
    //Descending no.s, left align
    for (i=row;i>=1;--i){
        for (j=1;j<=i;++j)
            {if (j>=10)
                cout<<"0";
            else
                cout<<j;}
        line;
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
    line;
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
        line;
    }
    line;
}
void psuedoStarPyr(int row){
    int vitals;
    //Pseudo star pyramid
    for (i=1;i<=row;++i){
        for (j=1;j<=row-i;++j)
            {cout<<" ";}
        while (j<=row){

                cout<<"* ";
                j++;
        }
        line;
    }
    line;
}
void numPyr(int row){
    int vitals;
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

        line;
    }
    line;
}
void hollowDiamond(int row){
    int vitals;
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
        line;
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
    line;
    }
    line;
}
void numDiamond(int row){
    int vitals;
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
        line;
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
        line;
    }
    //cout<<"i: "<<i<<"j: "<<j;
    line;
}
void starWedges(int row){
    int vitals;
    //Star table
    for (i=1;i<=row-1;++i){
        for (j=1;j<=i;++j)
            {cout<<"*";}
        for(j=1;j<=2*(row-i)-1;j++)
            cout<<" ";
        for(j=1;j<=i;j++)
            cout<<"*";
        line;
    }
    for (i=1;i<=2*row-1;++i)
        cout<<"*";
    line;
    line;
    //upside down wedges+stars
         for (i=1;i<=row;++i)
            cout<<"*";
        while(i>=2){
            if(i-2>0)
                cout<<"*";
            i--;
        }
        line;
    for (i=1;i<=row;++i)
        if(i>=2){
    for(j=1;j<=row-i+1;j++)
        cout<<"*";
    for(j=1;j<=2*i-3;j++)
        cout<<" ";
    for (j=row-i+1;j>=1;--j)
        cout<<"*";
    line;
    }
    line;
}
void numWedges(int row){
    int vitals;
    //Number valley
    line;
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
        line;
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
    line;
    line;
    //Upside down wedges+no.s
     line;
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
        line;
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
    line;
    }
    line;
}
void starRhombus(){
    int vitals;
     //hollow stars+rhombus
    line;
     for (i=1;i<=row;++i)
            cout<<'x';
        while(i>=2){
            if(i-2>0)
            cout<<'x';
            i--;
        }
        line;
    for (i=1;i<=row;++i)
        if(i>=2){
    for(j=1;j<=row-i+1;j++)
        cout<<'x';
    for(j=1;j<=2*i-3;j++)
        cout<<" ";
    for (j=row-i+1;j>=1;--j)
        cout<<'x';
    line;
    }
    for (i=1;i<=row-1;++i){
        if(i>=2){
        for (j=1;j<=i;++j)
            {cout<<'x';}
        for(j=1;j<=2*(row-i)-1;j++)
            cout<<" ";
        for(j=i;j>=1;j--)
            cout<<'x';
        line;
        }
     }
        for (i=1;i<=row;++i)
            cout<<'x';
        while(i>=2){
            if(i-2>0)
            cout<<'x';
            i--;
            }
     line;
}
void numRhombus(int row){
    int vitals;
    line;
    //hollow no.s+rhombus
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
        line;
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
    line;
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
        line;
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
     line;
}
int main(){
    char patType[][20]={
        "starHeaps",
        "numHeaps",
        "psuedoStarPyr",
        "numPyr",
        "hollowDiamond",
        "numDiamond",
        "starWedges",
        "numWedges",
        "starRhombus",
        "numRhombus"
    };
    char repeat[4];
    bool isRep;
    int row;
    cout<<"Enter lenght of patterns: ";
    cin>>row;
    do{
        cout<<"Pattern kind";
        line;
        int i;
        for(i=0;i<10;i++){
            cout<<i+1<<". "<<patType[i]<<endl;
        }
        int num;
        cin>>num;
        switch(num){
            case 1: starHeaps(row);
            break;
            case 2: numHeaps(row);
            break;
            case 3: psuedoStarPyr(row);
            break;
            case 4: numPyr(row);
            break;
            case 5: hollowDiamond(row);
            break;
            case 6: numDiamond(row);
            break;
            case 7: starWedges(row);
            break;
            case 8: numWedges(row);
            break;
            case 9: starRhombus(row);
            break;
            case 10: numRhombus(row);
            break;
        }
        cout<<"\nOne more pattern?";
        cin>>repeat;
        if(strcmp(repeat,"yes")==0||strcmp(repeat,"y")==0){
            isRep=1;
        }
        else
            isRep=0;
        line;
    }while(isRep);
    /*int arr[5]={1,2,3,5,8};
    for(int &ijk : arr){
        cout<<ijk;
    }*/
}


