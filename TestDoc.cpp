#include<iostream>
#include<math.h>
using namespace std;

int main(){
	cout<<"\033[2J\033[1;1H";
	float a=1.0/3, ans;
	
	ans=pow(8,a);
	cout<<ans<<endl;
	long long unsigned int lol;
	lol=0;
	lol-=1;
	cout<<lol<<endl;
	
	
	int base10Number = 0;
    for (int i = 1; i < 9; i+=1)
    {
        base10Number += i;
        //cout << i << '\n';
        //cout << base10Number << '\n';
        std::cout << std::hex << base10Number << std::endl;
    }
}