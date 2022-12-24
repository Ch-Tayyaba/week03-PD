#include<iostream>
using namespace std;
main()
{
float bagSize;
float bagCost;
float area;
float fertilizerCost;
float costOfFertilizingArea;
cout << "Enter Bag size in Pounds : ";
cin >> bagSize;
cout << "Enter Cost of the bag : ";
cin >> bagCost;
cout << "Enter Area covered by each bag in square feet : ";
cin >> area;
fertilizerCost = bagCost / bagSize;
cout << "Cost of fertilizer per pound : " << fertilizerCost << endl;
costOfFertilizingArea = bagSize * area ;
cout  << "Cost of fertilizing area per per square feet" << costOfFertilizingArea;
}