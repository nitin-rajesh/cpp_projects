#include <stdio.h>
#include <time.h>
#include<iostream>

using namespace std;

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

int main ()
{
  int n;
  int minutes = 0;
  int hours = 0;

  printf ("Starting countdown...\n");
  for (n=0; n<=60; n++)
  {
    //printf ("%d\n",n);

    wait (1);
    if(n == 60)
    {
         minutes += 1;
         n = 0;
    }
    if(minutes == 60)
    {
         hours += 1;
    }

    cout<<hours<<":"<<minutes<<":"<<n<<endl;

  }
  printf ("FIRE!!!\n");
  system("pause");
  return 0;
}
