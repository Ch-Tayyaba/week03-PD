#include<iostream>
using namespace std;
main()
{
string movieName;
float adultTicketPrice;
float childTicketPrice;
float numberOfAdultTickets;
float numberOfChildTickets;
float charityPercentage;
float totalAmount;
float finalAmount;
float charity;
cout << "Enter today's Movie Name : ";
cin >> movieName;
cout << "Enter Price of Adult's Ticket : ";
cin >> adultTicketPrice;
cout << "Enter Price of Child's Ticket :";
cin >> childTicketPrice;
cout << "Enter Total Number of Adult's Tickets that slod today : ";
cin >> numberOfAdultTickets;
cout << "Enter Total Number of Child's Tickets that slod today :";
cin >> numberOfChildTickets;
cout << "Enter Percentage of the amount to be donated to the charity : ";
cin >> charityPercentage;
totalAmount = (adultTicketPrice * numberOfAdultTickets) + (childTicketPrice * numberOfChildTickets);
cout << "Total amount Generated : " << totalAmount << endl;
charity = (charityPercentage/100) * totalAmount;
finalAmount = totalAmount - charity;
cout << "Amount after donation : " << finalAmount;
}