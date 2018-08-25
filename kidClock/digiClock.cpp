#include <stdio.h>
#include <time.h>
#include<iostream>
#include<ctype.h>
#define clear system("clear")
//use system("cls") for Windows
using namespace std;
void startClock(unsigned int, unsigned int, bool);
void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

bool checkTime(int minutes, int hours){
    if(hours>=0&&hours<24)
        if(minutes>=0&&minutes<60)
            return true;
            
    return false;
}
int main ()
{
    bool showSec=1;
    //change showSec to 0 if you don't want to see seconds
    unsigned int seconds;
    unsigned int minutes = 0;
    unsigned int hours = 0;
    char min[3]="00", hour[3]="00";
    char theTime[6];
    cout<<"-CLOCK-"<<endl;
    for(;;){
        cout<<"Enter time in 24hr format"<<endl;
        cout<<"<hour>:<minute>"<<endl;
        cin>>theTime;
        int i=0,j=0;
        while(isalnum(theTime[i])){
            hour[i]=theTime[i];
            //cout<<theTime[i];
            i++;
        }
        i++;
        cout<<endl;
        while(true){
            min[j]=theTime[i];
            //cout<<min[i];
            //cout<<theTime[i];
            i++;
            j++;
            if(theTime[i]=='\0')
                break;
        }
        hours=atoi(hour);
        minutes=atoi(min);
        if(checkTime(minutes,hours)){
            startClock(minutes,hours,showSec);
        }
        else
            cout<<"Didn't get the time format"<<endl;
    }
    //cout<<hour<<":"<<min<<endl;
    //printf ("Starting countdown...\n");
   
}
void startClock(unsigned int minutes, unsigned int hours, bool showSec){
    char am_pm[3];
    int hoursElapsed=0;
    if(hours<12){
        strcpy(am_pm,"am");
    }
    if(hours>=12){
        strcpy(am_pm,"pm");
        if(hours>12)
            hours-=12;
    }
    if(hours==0){
        hours=12;
        strcpy(am_pm,"am");
    }
    for (int seconds=0;; seconds++)
    {
              //cout<<'\a';
            //printf ("%d\n",seconds);
        
        wait (1);
        if(seconds == 60)
        {
             minutes += 1;
             seconds = 0;
             hoursElapsed++;
        }
        if(minutes == 60)
        {
            hours += 1;
            minutes=0;
            if(hours>=12){
                strcpy(am_pm,"pm");
                hours-=12;
            }
            else{
                strcpy(am_pm,"am");
            }
        }
        
        if(showSec){
            clear;
            cout<<hours<<":";
            minutes<10?cout<<"0"<<minutes:cout<<minutes;
            cout<<":"<<seconds<<am_pm<<endl;
        }
        else if(seconds==0){
                clear;
                cout<<hours<<":";
                minutes<10?cout<<"0"<<minutes:cout<<minutes;
                cout<<am_pm<<endl;
        }


    }
    printf ("FIRE!!!\n");
    //system("pause");
  
}
//Copyright
//ITGuy
