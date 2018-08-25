#include<iostream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

#define clear system("clear")
//if cout<<"\033[2J\033[;H" doesn't work, use system("cls")
#define line cout<<endl

using namespace std;

const int numberOfRows=12;

struct Grid{
    char pos[numberOfRows][4];
    int red[numberOfRows];
    int white[numberOfRows];
}board;

struct BoardRow{
    char values[5];
    int possibleValues[4][8];
    int red;
    int white;
}rowList[numberOfRows];

struct ColourComplex{
    int red;
    int white;
};

bool solutionSet[8][8][8][8];
int firstPosInSolutionSet[4] = {-1,-1,-1,-1};
void holdOn(){
    int time1, time2, j=0;
    cout<<"Thinking....";
    line;
    time1=time(NULL);
    for(int i=0;;i++){
        time2=time(new time_t);
        //cout<<endl<<time1<<endl<<time2;
        if(time2-time1==1){
            //cout<<".";
            j++;
        }
        if(j==4){
            return;
        }
    }
}
void boardReset();
void boardPrint();
ColourComplex colorCount(int,char[],bool shouldChangeBoard);
void rowGuesser(int);
bool colourCompare(int row, char i, char j, char k, char l);
void eliminateSolutions(int lastRowAnswered);
void gamePlayBegins();
void printRules();

int main(){
	char showRules, repCon;
	clear;
	cout<<"--MASTERMIND AI--"<<endl;
	cout<<endl<<"-Enter H for rules"<<endl<<"-Press enter to play";
	line;
	showRules=getchar();
	if(showRules=='h'||showRules=='H'){
		printRules();
		getchar();
	}
	do{
        fflush(stdin);
        gamePlayBegins();
        cout<<"Enter R to play again"<<endl;
        fflush(stdin);
        cin>>repCon;
	}while(repCon=='r'||repCon=='R');
}
void printRules(){
	cout<<"- The computer picks a sequence of four numbers. The numbers range from 1 to 8";
	getchar();
	cout<<"- The objective of the game is to guess the exact positions of the numbers in the computer's sequence.\n";
	cout<<"- A number can be used only once in a code sequence.";
	getchar();
	cout<<"- After filling a line with your guesses and pressing Enter, the computer responses with the result of your guess.\n";
	cout<<"-'R' (red) counts the numbers in your guess that are of the correct value and in correct position in the code sequence.\n";
	cout<<"- 'W' (white) counts the numbers in your guess with the correct value but NOT in the correct position in the code sequence.";
	getchar();
	cout<<"- You win the game when you manage to guess all the colors in the code sequence and when they all in the right position before running out of tries.\nPress enter to begin";
}

void rowGuesser(int row){
    //cout<<"Psst guess this:";
    if(row==numberOfRows-1){
        strcpy(rowList[row].values,"1234");
        //cout<<1234<<endl;
        return;
    }
    eliminateSolutions(row+1);
    /*for(int i = 0; i < 4; ++i){
        cout<<firstPosInSolutionSet[i]+1;
    }
    cout<<endl;*/ 
}

void eliminateSolutions(int lastRowAnswered){
    for(int i = 0; i < 4; ++i){
        firstPosInSolutionSet[i] = -1;
    }

    for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
    for(int k = 0; k < 8; ++k){
    for(int l = 0; l < 8; ++l){
        if(!solutionSet[i][j][k][l]){
            continue;
        }
        if(!colourCompare(lastRowAnswered,i+'1',j+'1',k+'1',l+'1')){
            solutionSet[i][j][k][l] = false;
        } else if(firstPosInSolutionSet[0] == -1){
            firstPosInSolutionSet[0] = i;
            firstPosInSolutionSet[1] = j;
            firstPosInSolutionSet[2] = k;
            firstPosInSolutionSet[3] = l;
        } else {
        }
    }}}}
}

void generateRandomAnswer(char answer[4]){
    srand(time(new time_t));
    answer[0] = rand()%8+'1';
    for(int i = 1; i < 4; ++i){
        answer[i] = rand()%(8-i)+'1';
        for(int j = 0; j < i;++j){
            if(answer[i]==answer[j]){
                answer[i]++;
                j = -1;
            }
        }
    }
}

void gamePlayBegins(){
	char answer[4];
    generateRandomAnswer(answer);
    bool isWinner=false,isAI=false, showAns=false;
    for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
    for(int k = 0; k < 8; ++k){
    for(int l = 0; l < 8; ++l){
        if(i == j||i == k||i == l||j == k||j == l||k == l){
            solutionSet[i][j][k][l] = false;
        } else {
            solutionSet[i][j][k][l] = true;
        }
    }}}}
    
    //cout<<"Answer- ";
    
    /*for(int i=0;i<4;i++)
        cin>>answer[i];
        */
    boardReset();
    for(int row=numberOfRows-1;row>=0;row--){
        fflush(stdin);
        boardPrint();
        if(showAns){
            cout<<"Answer: ";
            for(int i = 0; i<4;++i){
                cout<<answer[i];
            }
        }
        rowGuesser(row);
        /*for(int i = 0; i<4;++i){
            cout<<answer[i];
        }*/
        cout<<endl;
        if(!isAI){
        	cout<<"Enter 'AI' for computer to solve it";
        	line;
        	for(int i=0;i<4;i++){
		        /*if(row==x-1){
		            numMaker(row);
		            board.pos[row][i]=rowList[row].pos[i];
		            continue;
		        }*/
		        cin>>board.pos[row][i];
		        
		        if((board.pos[row][0]=='A'||board.pos[row][0]=='a')&&(board.pos[row][1]='I'||board.pos[row][1]=='I')){
    		        isAI=true;
    		        //rowList[row].values[i]=board.pos[row][i];
    		        break;
		        }
	        }
	        if(!showAns){
    	        for(int i=0;i<4;i++){
        	        if(board.pos[row][i]=='#')
        		            showAns=true;
        		        else
        		            showAns=false;
    	        }
	        }
		    if(isAI)
		    	break;
	    }
		if(isAI)
		    	break;
		//cout<<endl<<isAI<<endl;
        isWinner=(colorCount(row,answer,true).red == 4);
        if(isWinner)
            break;
           
    }
    if(isAI){
        boardReset();
    	for(int row=numberOfRows-1;row>=0;row--){
    	    boardPrint();
    	    holdOn();
    		rowGuesser(row);
    		if(row==numberOfRows-1){
        		strcpy(board.pos[row],"1234");
    		}
    		else{
				for(int i = 0; i < 4; ++i){
					board.pos[row][i]=firstPosInSolutionSet[i]+'1';
		   		}
		   	}
	   		isWinner=(colorCount(row,answer,true).red == 4);
        	if(isWinner)
            	break;
    	}
    }
    boardPrint();
    if(isWinner&&(!showAns&&!isAI))
        cout<<"You win!";
    else{
        if(isAI){
            cout<<"AI wins!";
            line;
        }
        else if(showAns){
            cout<<"Breach detected";
            line;
        }
        else{
            cout<<"N00B@";
            cout<<answer<<".com"<<endl;
        }
    }
    line;
    return ;
}

void boardReset(){
    clear;
    //cout<<"?   ?   ?   ?"<<endl;
    for(int i=0;i<numberOfRows;i++){
        board.red[i]=0;
        board.white[i]=0;
        for(int j=0;j<4;j++){
            board.pos[i][j]='*';
            cout<<board.pos[i][j]<<"   ";
            //Make this a loop
            //rowList[i].possibleValues[j]=0;
        }
        cout<<'\t'<<"R-"<<board.red[i]<<"  W-"<<board.white[i];
        line;
    }
}

void boardPrint(){
    clear;
    cout<<"?   ?   ?   ?"<<endl;
    for(int i=0;i<numberOfRows;i++){
        //board.red[i]=0;
        //board.white[i]=0;
        for(int j=0;j<4;j++){
            //board.pos[i][j]='*';
            cout<<board.pos[i][j]<<"   ";
        }
        cout<<'\t'<<"R-"<<board.red[i]<<"  W-"<<board.white[i]<<'\t';
        /*for(int j=0;j<4;j++)
            cout<<"Quo."<<j+1<<"\x1A"<<rowList[x].posVal[j]<<" ";
        */
        line;
    }
}

ColourComplex colorCount(int row, char givenAnswer[4],bool shouldChangeBoard ){
    //white
    bool skip;
    ColourComplex c;
    c.red = 0;
    c.white = 0;
    for(int i=0;i<4;i++){
        skip=false;
        for(int j=0;j<4;j++){
            if(givenAnswer[i]==board.pos[row][j]){
                skip=true;
                c.white++;
                //board.white[row]++;
            }
            if(skip)
                break;
        }
    }

    //red
    for(int i=0;i<4;i++){
            if(givenAnswer[i]==board.pos[row][i]){
                c.red++;
                //board.red[row]++;
        }
    }
    c.white -= c.red;
    //board.white[row]-=board.red[row];

    if(shouldChangeBoard){
        board.red[row] = c.red;
        board.white[row] = c.white;
    }
    return c;
}

bool colourCompare(int row, char i, char j, char k, char l){
    char possibleAnswer[4] = {i,j,k,l};
    ColourComplex c = colorCount(row,possibleAnswer,false);
    return(c.red == board.red[row] && c.white == board.white[row]);
}
