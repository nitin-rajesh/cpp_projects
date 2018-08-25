#include<iostream>
#define clear cout<<"\033[2J\033[;H"
//if cout<<"\033[2J\033[;H" doesn't work, use system("cls")
#define line cout<<endl
using namespace std;
const int x=10;
struct grid{
    char pos[x][4];
    int red[x];
    int white[x];
}board;
void boardReset();
void boardPrint();
bool colorCount(int,char[]);
int main(){
    char answer[4];
    bool isWinner;
    cout<<"Answer- ";
    for(int i=0;i<4;i++)
        cin>>answer[i];
    boardReset();
    for(int row=x-1;row>=0;row--){
        boardPrint();
        for(int i=0;i<4;i++)
            cin>>board.pos[row][i];
        isWinner=colorCount(row,answer);
        if(isWinner)
            break;
    }
    boardPrint();
    if(isWinner)
        cout<<"You win!";
    else
        cout<<"N00B";
    line;
    
}
void boardReset(){
    clear;
    cout<<"?   ?   ?   ?"<<endl;
    for(int i=0;i<x;i++){
        board.red[i]=0;
        board.white[i]=0;
        for(int j=0;j<4;j++){
            board.pos[i][j]='*';
            cout<<board.pos[i][j]<<"   ";
        }
        cout<<'\t'<<"R-"<<board.red[i]<<"  W-"<<board.white[i];
        line;
    }
}
void boardPrint(){
    clear;
    cout<<"?   ?   ?   ?"<<endl;
    for(int i=0;i<x;i++){
        //board.red[i]=0;
        //board.white[i]=0;
        for(int j=0;j<4;j++){
            //board.pos[i][j]='*';
            cout<<board.pos[i][j]<<"   ";
        }
        cout<<'\t'<<"R-"<<board.red[i]<<"  W-"<<board.white[i];
        line;
    }    
}
bool colorCount(int row, char answer[4]){
    //white
    bool skip;
    for(int i=0;i<4;i++){
        skip=false;
        for(int j=0;j<4;j++){
            if(answer[i]==board.pos[row][j]){
                skip=true;
                board.white[row]++;
            }
            if(skip)
                break;
        }
    }
    //red
    for(int i=0;i<4;i++){
            if(answer[i]==board.pos[row][i]){
                board.red[row]++;
        }
    }
    board.white[row]-=board.red[row];
    if(board.red[row]==4)
        return true;
    else
        return false;
}