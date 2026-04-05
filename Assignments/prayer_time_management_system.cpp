#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Date {
public:
    int yy, mm, dd;

    Date() {
        yy = mm = dd = 0;
    }

    Date(int y, int m, int d) {
        yy = y;
        mm = (m >= 1 && m <= 12) ? m : 1;
        dd = (d >= 1 && d <= 31) ? d : 1;
    }
};

class Time {
public:
    int hh, min;

    Time() {
        hh = min = 0;
    }

    Time(int h, int m) {
        hh = (h >= 0 && h <= 23) ? h : 0;
        min = (m >= 0 && m <= 59) ? m : 0;
    }

    void display() const {
        int displayHour = hh;
        string period = "am";

        if (hh == 0) displayHour = 12;
        else if (hh == 12) period = "pm";
        else if (hh > 12) {
            displayHour = hh - 12;
            period = "pm";
        }

        cout << setw(2) << setfill('0') << displayHour << ":"
             << setw(2) << setfill('0') << min << " " << period;
    }
};

class Location {
public:
    double latitude, longitude;

    Location() {
        latitude = longitude = 0.0;
    }
};

class Prayer {
public:
    char Prayer_Name[20];
    Date Today;
    Time Start_Time;

    Prayer() {
        strcpy(Prayer_Name, "");
    }

    Prayer(const char* pn, const Date& t, const Time& st) {
        strncpy(Prayer_Name, pn, sizeof(Prayer_Name) - 1);
        Prayer_Name[sizeof(Prayer_Name) - 1] = '\0'; // Ensure null termination
        Today = t;
        Start_Time = st;
    }
};

class Prayer_Times {
    Location Loc;
    Prayer Prayers[7];

public:
    void Get_Location() {
        cout << "Please Enter Your Location" << endl;
        cout << "Enter Latitude : ";
        cin >> Loc.latitude;
        cout << "Enter Longitude: ";
        cin >> Loc.longitude;
    }

    void Show_Location() {
        cout << fixed << setprecision(7);
        cout << "Location: " << Loc.latitude << ", " << Loc.longitude << endl;
    }

    void Get_Times() {
        int y, m, d;
        cout << "Enter year month (January = 1) and date: ";
        cin >> y >> m >> d;
        Date today(y, m, d);

        const char* names[7] = { "Fajr", "Sunrise", "Dhuhr", "Asr", "Sunset", "Maghrib", "Isha" };

        for (int i = 0; i < 7; i++) {
            int h, mn;
            cout << "Enter Time of " << names[i] << " (hh mm): ";
            cin >> h >> mn;
            Time t(h, mn);
            Prayers[i] = Prayer(names[i], today, t);
        }
    }

    void Show_Times() {
        static const char* monthNames[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };

        cout << "-------------------------------------------------\n";
        cout << "Date: " << monthNames[Prayers[0].Today.mm] << " "
             << Prayers[0].Today.dd << ", " << Prayers[0].Today.yy << endl;

        Show_Location();
        cout << endl;

        for (int i = 0; i < 7; i++) {
            cout << left << setw(8) << Prayers[i].Prayer_Name << ": \t";
            Prayers[i].Start_Time.display();
            cout << endl;
        }
    }
};

int main() {
    Prayer_Times pt;
    pt.Get_Location();
    pt.Get_Times();
    pt.Show_Times();
    return 0;
}
