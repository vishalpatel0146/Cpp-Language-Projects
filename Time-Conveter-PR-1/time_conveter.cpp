#include <iostream>
using namespace std;

class TimeConverter
{

private:
    int h, m, s;
    int totalSec;

public:
    void secondsToTime(int givenSec)
    {

        h = givenSec / 3600;
        m = (givenSec % 3600) / 60;
        s = givenSec % 60;

        cout << "HH:MM:SS => " << h << ":" << m << ":" << s<< endl  << endl;
    }

    void timeToSecond(int hr, int min, int sec)
    {

        totalSec = (hr * 3600) + (min * 60) + sec;

        cout << "In Seconds :- " << totalSec << " sec" << endl << endl;
    }
};

int main()
{

    TimeConverter t1;

    int choice;

    do
    {

        cout << "Press 1 to convert 'seconds' into 'Hour Minute Second'" << endl;
        cout << "Press 2 to convert 'Hour Minute Second' into 'Seconds'" << endl;
        cout << "Press 3 to Exit" << endl;
        tryAgain:
        cout << "Enter Your Choice :- ";
        cin >> choice;

        if(choice < 1 || choice > 3) {
            cout << endl << "Invalid Choice Enter.............." << endl;
            goto tryAgain;
        }

        switch (choice)
        {
        case 1:

            int sec;
            cout << endl
                 << "Enter seconds to Convert :- ";
            cin >> sec;

            t1.secondsToTime(sec);

            break;

        case 2:

            int hour, minute, second;

            cout << "Enter hour :- ";
            cin >> hour;

            cout << "Enter minute :- ";
            cin >> minute;

            cout << "Enter second :- ";
            cin >> second;

            t1.timeToSecond(hour, minute, second);

            break;

        case 3:
            cout << endl << "<===== Thank You =====>";
            break;
        }

    } while (choice != 3);

    return 0;
}