//Creating Digital Watch in C++
#include<iostream>
#include<Windows.h>
using namespace std;

struct time{

    int hr,min,sec;
};
int main()
{
    time a;
    a.hr = 0;
    a.min = 0;
    a.sec = 0;

    for(int i = 0; i<24; i++)
    {
        if(a.hr == 23)
        {
            a.hr = 0;
        }

        for(int j = 0; j<60; j++)
        {
            if(a.min == 59)
            {
                a.min = 0;
            }

            for(int k = 0; k<60; k++)
            {
                if(a.sec == 59)
                {
                    a.sec = 0;
                }

                cout<<a.hr<<Ó : Ò<<a.min<<Ó : Ò<<a.sec<<endl;
                a.sec++;
                Sleep(1000);
                system(ÒClsÓ);
            }
        a.min++;

    }

        a.hr++;
    }

}
