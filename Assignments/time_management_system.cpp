#include <iostream>
using namespace std;
class Time 
{
    int hours;
    int minutes;
    int seconds;

    public:
    Time () 
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time (int h, int m, int s) 
    {
        setTime (h, m, s);
    }
    void setTime (int h, int m, int s) 
    {
        hours = (h >= 0 && h < 24) ? h : 0;
        minutes = (m >= 0 && m < 60) ? m : 0;
        seconds = (s >= 0 && s < 60) ? s : 0;
    }
    void tick () 
    {
        seconds ++;
        if (seconds == 60) 
        {
            seconds = 0;
            minutes ++;
        }
        if (minutes == 60) 
        {
            minutes = 0;
            hours ++;
        }
        if (hours == 24) 
        {
            hours = 0;
        }
    }
    void print () 
    {
        cout << (hours < 10 ? "0" : "") << hours 
             << ":" << ((minutes < 10 )? "0" : "") << minutes 
             << ":" << ((seconds < 10 )? "0" : "") << seconds << endl;
    }

    Time add (Time t1, Time t2) 
    {
        Time t3;
        t3.seconds = t1.seconds + t2.seconds;
        if (t3.seconds >= 60) 
        {
            t3.seconds -= 60;
            t1.minutes ++;
        }

        t3.minutes = t1.minutes + t2.minutes;
        if (t3.minutes >= 60) 
        {
            t3.minutes -= 60;
            t1.hours ++;
        }

        t3.hours = t1.hours + t2.hours;
        if (t3.hours >= 24) 
        {
            t3.hours -= 24;
        }

        return t3;
    }
};

int main() 
{
    Time t1 (23, 59, 55);
    cout << "Time Increment: " << endl;
    for (int i = 0; i < 1000; i++) 
    {
        t1.tick ();
        t1.print ();
    }
    Time t2 (12, 30, 45);
    Time t3 (2, 45, 50);
    Time result = result.add (t2, t3);

    cout << "Adding Two Time Objects: " << endl;
    cout << "First Time Object: ";
    t2.print ();
    cout << "Second Time Object: ";
    t3.print ();
    cout << "Result After Addition: ";
    result.print ();

    return 0;
}
