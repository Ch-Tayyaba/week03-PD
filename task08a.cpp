#include<iostream>
using namespace std;
main()
{
float vegetablePrice;
float fruitPrice;
int kgOfVegetable;
int kgOfFruit;
float amountInCoins;
float finalAmount;
cout << "Enter Vegetable price per kilogram : ";
cin >> vegetablePrice;
cout << "Enter Fruit price per kilogram : ";
cin >> fruitPrice;
cout << "Enter Total kilograms of vegetables : ";
cin >> kgOfVegetable;
cout << "Enter Total kilograms of fruits : ";
cin >> kgOfFruit;
amountInCoins = (vegetablePrice * kgOfVegetable) +(fruitPrice * kgOfFruit);
finalAmount = amountInCoins/1.94;
cout << "Total earning : " << finalAmount; 
}