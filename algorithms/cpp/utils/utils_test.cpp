//
// Created by tianm on 2019-09-07.
//



# include <iostream>
#include <myutils.h>
#include <typeinfo>

using namespace std;

class Solution {

};

int main() {
    print(5);
    print('c');
    print("ssss");
    print("dddd");
    cout<< typeid("djfkdjakfdsja").name()<<endl;
    print("sss" == std::string());


    return 0;
}
