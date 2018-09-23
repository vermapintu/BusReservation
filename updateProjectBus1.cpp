#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<bits/stdc++.h>
#include"fun.h"
using namespace std;
typedef unsigned long ul;
typedef unsigned int ui;
string CalcDayOfWeek(int, ui, ui);
ui CalcDayNumFromDate(int, ui, ui);
class A {
 protected:int year1;
    string source1, dest1, Pname1;
    ui month1, day1;
    int t1, t2, t3;
 public:char name[10];
    string source;
    string dest;
    int age;
    int mobno;
    int seat;
    int n, bnum;
    string gender;
    void businfo(int year, ul month, ul day) {
        day1 = day;
        month1 = month;
        year1 = year;
    } void businfo1(string source, string dest) {
        source1 = source;
        dest1 = dest;
    } string CalcDayOfWeek(int year1, ui month, ui day) {
        string days[] = {
            "Wednesday", "Thursday", "Friday", "Saturday", "Sunday",
            "Monday", "Tuesday"
        };
        ul dn = CalcDayNumFromDate(year1, month1, day1);
        return days[dn % 7];
    }
    ul CalcDayNumFromDate(int year1, ui month1, ui day1) {
        month1 = (month1 + 9) % 12;
        year1 -= month1 / 10;
        ul dn =
            365 * year1 + year1 / 4 - year1 / 100 + year1 / 400 +
            (month1 * 306 + 5) / 10 + (day1 - 1);
        return dn;
    }
    int VFare = 1000;
    int OFare = 500;
    int SFare = 700;
    int payment;
    void buslistwrite() {
        int w;
        cout << "BUS LIST:" << endl;
        cout << "S.r." << "\t" << "Bus Type" << "\t" << "arrival Time" << "\t"
            << "Departure Time" << endl;
        cout << "1." << "\t" << "volvo" << "\t\t" << "2PM" << "\t\t" << "3PM"
            << endl;
        cout << "2." << "\t" << "ordinary" << "\t" << "4PM" << "\t\t" << "6PM"
            << endl;
        cin >> w;
        switch (w) {
        case 1:
            cout << "volvo is choosed(4040)" << "\t" << "Fare is 1000" << endl;
            cout << "plz enter volvo bus no" << endl;
            cin >> bnum;
            break;
        case 2:
            cout << "ordinary is choosed(5050)" << "\t" << "Fare is 500" <<
                endl;
            cout << "plz enter ordinary bus no" << endl;
            cin >> bnum;
            break;
        }
    }
    void buslistwrite1() {
        int w1;
        cout << "BUS LIST1:" << endl;
        cout << "S.r." << "\t" << "Bus Type" << "\t" << "arrival Time" << "\t"
            << "Departure Time" << endl;
        cout << "1." << "\t" << "volvo" << "\t\t" << "10AM" << "\t\t" << "11AM"
            << endl;
        cout << "2." << "\t" << "semidelux" << "\t" << "11AM" << "\t\t" <<
            "12AM" << endl;
        cin >> w1;
        switch (w1) {
        case 1:
            cout << "volvo is choosed(4040)" << "\t" << "Fare is 1000" << endl;
            cout << "plz enter volvo bus no" << endl;
            cin >> bnum;
            break;
        case 2:
            cout << "semidelux is choosed(6060)" << "\t" << "Fare is 700" <<
                endl;
            cout << "plz enter semidelux bus no" << endl;
            cin >> bnum;
            break;
        }
    }
    void readdata() {
        cout << "enter seat no";
        cin >> seat;
        cout << "enter name";
        cin >> name;
        cout << "enter age";
        cin >> age;
        cout << "enter gender";
        cin >> gender;
        cout << "enter mobno";
        cin >> mobno;
        cout << "enter source";
        cin >> source;
        cout << "enter destination";
        cin >> dest;
    } void writedata() {
        cout << "seat no." << "\t" << "name" << "\t" << "age" << "\t" << "mobno"
            << endl;
        cout << seat << "\t\t" << name << "\t" << age << "\t" << mobno << endl;
    } void readpay(int n) {
        if (bnum == 4040) {
            payment = n * VFare;
        } else if (bnum == 5050) {
            payment = n * OFare;
        } else if (bnum == 6060) {
            payment = n * SFare;
        }
    }
    void writepay() {
        cout << "total payment" << endl;
        cout << payment << endl;
    } void cancellationread(int ntic) {
        if (bnum == 4040) {
            payment = payment - ntic * VFare;
        } else if (bnum == 5050) {
            payment = payment - ntic * OFare;
        } else if (bnum == 6060) {
            payment = payment - ntic * SFare;
        }
    }
    void cancellationwrite() {
        cout << "refund money" << endl;
        cout << payment;
    }
    /*void getbookingtime(int (now->tm_year + 1900),int  (now->tm_mon + 1) ,int now->tm_mday)
       {
       t1=(now->tm_year + 1900);
       t2= (now->tm_mon + 1);
       t3=now->tm_mday;

       }
       void show()
       {
       cout<<"name"<<"\t"<<"source"<<"\t"<<"Destineation"<<"\t"<<"booking time"<<"\t"<<"departure time"<<"\t"<<"seatnumber"<<"\t"<<"gender"<<"\t"<<"age"<<"\t"<<"mobno"<<endl; 

       }   */
};

int main()
{
    A c;
    A person[50];
    int n, n1;
    int ntic;
    ui day, month, year;
    fstream file;
    file.open("myfile.dat", ios::in | ios::out);
    cout << "how many persons do u want reservation" << endl;
    cin >> n;
    cout << "Booking date" << endl;
    time_t t = time(0);
    struct tm *now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
        << (now->tm_mon + 1) << '-' << now->tm_mday << endl;
    cout << "Deaparture date" << endl;
    cout << "enter year" << endl;
    cin >> year;
    cout << "enter month" << endl;
    cin >> month;
    cout << "enter day" << endl;
    cin >> day;
    c.businfo(year, month, day);
    string dow = c.CalcDayOfWeek(year, month, day);
    cout << "departure date" << endl;
    cout << setfill('0') << setw(4) << year << "/";
    cout << setfill('0') << setw(2) << month << "/";
    cout << setfill('0') << setw(2) << day << endl;
    cout << dow << endl;
    Date dt1 = {
        now->tm_mday, (now->tm_mon + 1), (now->tm_year + 1900)
    };
    Date dt2 = {
        day, month, year
    };
    int r = getDifference(dt1, dt2);

    //getbookingtime((now->tm_year + 1900),(now->tm_mon + 1), now->tm_mday); 
    cout << "enter bus type:" << endl;
    if (r <= 2922) {
        string str2[] = {
            "Sunday", "Monday", "Tuesday", "Wednesday"
        };
        string str1[] = {
            "Thursday", "Friday", "Saturday"
        };
        for (int i = 0; i < 4; i++) {
            int t;
            if (strcmp(str2[i].c_str(), dow.c_str()) == 0) {
                person[n].buslistwrite();
                file.write((char *)&person[n], sizeof(person[n]));
            }
        }
        for (int i = 0; i < 3; i++) {
            int t1 = strcmp(str1[i].c_str(), dow.c_str());
            if (t1 == 0) {
                person[n].buslistwrite1();
                file.write((char *)&person[n], sizeof(person[n]));
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << "Detail of person:" << "[" << i << "]" << endl;
            person[i].readdata();
            file.write((char *)&person[i], sizeof(person[i]));
        }
        file.seekg(0);
        for (int i = 1; i <= n; i++) {
            cout << "Detail of person:" << "[" << i << "]" << endl;
            file.read((char *)&person[i], sizeof(person[i]));
            person[i].writedata();
        }
        int opt;
        cout << "do u want to continue payment process then press 1." << endl;
        cin >> opt;
        if (opt == 1) {
            person[n].readpay(n);
            file.write((char *)&person[n], sizeof(person[n]));
            file.read((char *)&person[n], sizeof(person[n]));
            person[n].writepay();
        }
        cout << "for cancellation process press 2." << endl;
        int opt2;
        cin >> opt2;
        if (opt2 == 2) {
            cout << "how many person tickets do u want to cancel:" << endl;
            cin >> ntic;
            person[ntic].cancellationread(ntic);
            file.write((char *)&person[ntic], sizeof(person[ntic]));
            file.seekg(0);
            file.read((char *)&person[ntic], sizeof(person[ntic]));
            person[ntic].cancellationwrite();
        }
//cout<<"Show the all Details"<<endl;
//show();
        file.close();
    }
}
