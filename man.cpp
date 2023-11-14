#include<iostream>

#include "Hashing/LinearProbing.h"


using namespace std;
int main(){
    linearProbing<double,int> l(10);
    l.getItem(2.222);
    cout << l.getItem(2.222) << endl;

}