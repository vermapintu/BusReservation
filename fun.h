#include<iostream>
using namespace std;
struct Date 
{
	int y2,m2,d2;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 

// This function counts number of leap years before the
// given date
int countLeapYears(Date d2)
{
    int years = d2.y2;
 
    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d2.m2 <= 2)
        years--;
 
    return years / 4 - years / 100 + years / 400;
}
 
// This function returns number of days between two given
// dates
int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = dt1.y2*365 + dt1.d2;
 
    // Add days for months in given date
    for (int i=0; i<dt1.m2 - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
 
    long int n2 = dt2.y2*365 + dt2.d2;
    for (int i=0; i<dt2.m2 - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    return (n2 - n1);
}

 
