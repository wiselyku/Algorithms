#include <iostream>
#include <vector>
#include <list>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()
#include <string>

using namespace std;

int main(){

int a=123, b=456;
cout<<"a="<<a<<" b="<<b<<endl;
a = a - b;
b = a + b;
a = b - a;
cout<<"a="<<a<<" b="<<b<<endl;
char x='a', y='b';
cout<<"x="<<x<<" y="<<y<<endl;
x = x^y;
y = x^y;
x = x^y;
cout<<"x="<<x<<" y="<<y<<endl;
return 0;
}

