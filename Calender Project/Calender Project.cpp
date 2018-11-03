// Calender Project.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include <iostream>

using namespace std;

/************************************
* Get the user inputed year
************************************/
int getUserYear()
{
	int userYear;
	cout << "Pick a year after 1752: ";
	cin >> userYear;

	// Validate year
	while (userYear < 1753)
	{
		cout << "Please enter in a year after Dec 31, 1752: ";
		cin >> userYear;
	}
	return userYear;
}

/************************************
* Get the user inputed month
************************************/
int getUserMonth()
{
	int userMonth;

	cout << "Pick a month.  Please enter in a number instead of the name. \n"
		<< "Example: for March, enter in 3: ";
	cin >> userMonth;

	// Validate month
	while (userMonth < 1 || userMonth > 13)
	{
		cout << "Please enter in a valid month {1,2,3,4,5,6,7,8,9,10,11,12}";
		cin >> userMonth;
	}

	return userMonth;
}

/****************************************************
* Is the year chosen leap year?
****************************************************/
bool isLeapYear(int userYear)
{
	if ((userYear % 4 == 0 && userYear % 100 != 0) || userYear % 400 == 0)
		return true;
	else
		return false;
}

/****************************************************
* Calculate # of days that have passed between start
* year and user entered month
****************************************************/
int getTotalMonthDays(int userYear, int userMonth)
{
	int monthDays;
	int numMonthDays = 0;

	for (int currentMonth = 1; currentMonth < userMonth; currentMonth++)
	{
		if (currentMonth == 1 || currentMonth == 3 || currentMonth == 5 || currentMonth == 7 || currentMonth == 8 || currentMonth == 10 || currentMonth == 12)
			monthDays = 31;
		else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11)
			monthDays = 30;
		else if (currentMonth == 2)
		{
			if ((userYear % 4 == 0 && userYear % 100 != 0) || (userYear % 400 == 0))
				monthDays = 29;
			else
				monthDays = 28;
		}
		numMonthDays += monthDays;
	}

	return numMonthDays;
}

/****************************************************
* Calculate # of days that have passed between start
* year and user entered year
****************************************************/
int getDaysInYear(int currentYear)
{
	bool isLeap = isLeapYear(currentYear);
	int daysInYear;

	if (isLeap == true)
	{
		daysInYear = 366;
	}
	else
	{
		daysInYear = 365;
	}

	return daysInYear;
}

/**********************************************************
* This will return how many days are in the month for the
* calender display
***********************************************************/
int getDaysInMonth(int userYear, int userMonth)
{
	int days;

	if (userMonth == 1 || userMonth == 3 || userMonth == 5
		|| userMonth == 7 || userMonth == 8 || userMonth == 10 || userMonth == 12)
	{
		days = 31;
	}
	else if (userMonth == 2)
	{
		if (isLeapYear(userYear))
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
	}
	else if (userMonth == 4 || userMonth == 6 || userMonth == 9 || userMonth == 11)
	{
		days = 30;
	}

	return days;
}

/**********************************************************
* Calculate Offset
***********************************************************/
int getOffset(int userMonth, int userYear)
{
	int numDays = 0;

		// Figure out how many days are in each year
			for (int currentYear = 1753; currentYear < userYear; currentYear++)
			{
				numDays += getDaysInYear(currentYear);
			}
			for (int currentMonth = 1; currentMonth < userMonth; currentMonth++)
			{
				numDays += getDaysInMonth(currentMonth, userYear);
			}
		int offset = numDays % 7;
		return offset;
}

/**********************************************************
* This will display the calender
***********************************************************/
void calenderHead(int userMonth, int userYear)
{
	if (userMonth == 1)
		cout << "January, " <<  userYear << endl;
	else if (userMonth == 2)
		cout << "February, " << userYear << endl;
	else if (userMonth == 3)
		cout << "March, " << userYear << endl;
	else if (userMonth == 4)
		cout << "April, " << userYear << endl;
	else if (userMonth == 5)
		cout << "May, " << userYear << endl;
	else if (userMonth == 6)
		cout << "June, " << userYear << endl;
	else if (userMonth == 7)
		cout << "July, " << userYear << endl;
	else if (userMonth == 8)
		cout << "August, " << userYear << endl;
	else if (userMonth == 9)
		cout << "September, " << userYear << endl;
	else if (userMonth == 10)
		cout << "October, " << userYear << endl;
	else if (userMonth == 11)
		cout << "November, " << userYear << endl;
	else if (userMonth == 12)
		cout << "December, " << userYear << endl;

	cout << setw(1) << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
}

/**********************************************************
* This will display the calender
***********************************************************/
void displayTable(int numDays, int offset)
{

	int day;
	int blankSpace = (offset + 1) % 7;

	for (day = 0; day < blankSpace; day++)
	{
		cout << "    ";
	}

	for (int day = 1; day <= numDays; day++)
	{
		cout << setw(4) << day;
		if ((day + blankSpace) % 7 == 0)
		{
					cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	// User entered month
	int userMonth = getUserMonth();

	// User entered year
	int userYear = getUserYear();

	// How many months are in a given month/year
	int daysInMonth = getDaysInMonth(userYear, userMonth);

	// What is the offset to create the start date on calender
	int offset = getOffset(userYear, userMonth);

	// How many days are in the year
	int daysInYear = getDaysInYear(userYear);

	// How many days are in the year from Jan -> user Month
	int totalDaysInMonthYear = getTotalMonthDays(userYear, userMonth);

	calenderHead(userMonth, userYear);
	displayTable(daysInMonth, offset);


	// Displays variables to check math
	cout << "month: " << userMonth << "\n";
	cout << "year: " << userYear << "\n";
	cout << "days in month: " << daysInMonth << "\n";
	cout << "daysInYear: " << daysInYear << "\n";
	cout << "Offset: " << offset << "\n";
	cout << "total days from  Jan -> userMonth: " << totalDaysInMonthYear << endl;

    return 0;
}

