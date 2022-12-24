#include<iostream>
using namespace std;
main()
{
float initialVelocity;
float finalVelocity;
float acceleration;
float time;
cout << "Enter Initial Velocity : ";
cin >> initialVelocity;
cout << "Enter Acceleration : "; 
cin >> acceleration;
cout << "Enter Time : ";
cin >> time;
finalVelocity = initialVelocity + (acceleration * time);
cout << "Final Velocity : ";
cout << finalVelocity;
}