#include<iostream>
using namespace std;
main()
{
float subject01;
float subject02;
float subject03;
float subject04;
float subject05;
float percentage;
string name;
cout << "Enter your Name : ";
cin >> name;
cout << "Enter marks of subject01 : "; 
cin >> subject01;
cout << "Enter marks of subject02 : ";
cin >> subject02;
cout << "Enter marks of subject03 : ";
cin >> subject03;
cout << "Enter marks of subject04 : ";
cin >> subject04;
cout << "Enter marks of subject05 : ";
cin >> subject05;
percentage = ((subject01+subject03+subject03+subject04+subject05)/500)*100;
cout << "Your Percentage : ";
cout << percentage;
}