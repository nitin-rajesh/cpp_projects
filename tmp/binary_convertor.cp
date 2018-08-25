//
//  main.cpp
//  Binary
//
//  Created by Nitin Rajesh on 10/07/17.
//  Copyright © 2017 ITGuy. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    int num, i, mod;
    num=134;
    i=8;
    std::string bin;
    bin = "00000000";
//    std::cout<<"Enter a number\n";
//    std::cin>>num;
    i=num;
    do {
        mod=num % 2;
        std::cout<<mod;
        num=num/2;
        std::string bin = std::to_string(num);
        i=i-1;
       
        
    }
    while (num >=1);
    std::cout<<"\n";
}
