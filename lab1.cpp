// Christopher Ochs 
#include <iostream>
using namespace std;

int main()
{

	cout << "What did one ocean say to the other?\n ";
	cout << "Nothing it just waved!\n ";

	const int ThisYear = 2016;
	int user_age;
	int user_retire;

	cout << "How old are you now? ";
	cin >> user_age;
	user_retire = ThisYear + (65 - user_age);
	cout << "You will be able to retire in the year " << user_retire << endl;

	double hours, rate, pay;

	//Get the number of hours worked 
	cout << "How many hours did you work? ";
	cin >> hours;

	// Get the hourly rate
	cout << "How much do you get paid an hour? ";
	cin >> rate;

	// Calulate the pay. 
	pay = hours * rate;

	// Display the pay 
	cout << "You have $" << pay << endl;
	return 0;
}
