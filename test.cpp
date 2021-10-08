#include<iostream>
#include<stdlib.h>
using namespace std;
void testa()
{
    int a=-2147483648;
    unsigned int b=a;
    unsigned short c=a;
    short d=a;
    float e=a;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
}
void testb()
{
    short a=-12345;
    int  b=a;
    unsigned short c=b;
    unsigned int d=c;
    int e=d;
    float f=e;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;
    cout<<f<<endl;
}
void testc()
{
    float a=-123456.789e5;
    double b=a;
    float c=b;
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<&c<<endl;
}
void testd()
{
    unsigned int a=1+4294967295UL;
    unsigned int b=1-4294967295UL;
    int c=1+2147483647UL;
    int d=-2147483647UL-1;
    short e=-12345>>2;
    short f=-12345<<2;
}
int main()
{
    cout<<"testa:"<<endl;
    testa();
    cout<<"testb:"<<endl;
    testb();
    cout<<"testc:"<<endl;
    testc();
    cout<<"testd:"<<endl;
    testd();
    system("pause");
    return 0;
}