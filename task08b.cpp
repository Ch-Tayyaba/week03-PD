#include<iostream>
using namespace std;
main()
{
int number;
int rem01;
int rem02;
int rem03;
int div01;
int div02;
int div03;
int sum;
cout << "Enter a four digit number : ";
cin >> number;
rem01 = number%10;
div01 = number/10;
rem02 = div01%10;
div02 = div01/10;
rem03 = div02%10;
div03 = div02/10;
sum = rem01+rem02+rem03+div03;
cout << "Sum : " << sum;
}