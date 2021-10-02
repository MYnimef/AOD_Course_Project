#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
private:
    bool isDate;
    short day;
    short month;
    short year;
    QString dayStr;
    QString monthStr;
    QString yearStr;
    QString dayOfWeek;

    int findSymb(QString str, short pos);
    bool checkDate();
    void correctDate(int correction);
public:
    Date();
    Date(QString date);
    void buildDate(QString date);
    void setDayOfWeek();
    QString toDefaultString();
    QString toAmericanString();
    bool getIsDate();
    void increment();
    void decrement();
    void updateStrings();
    bool checkCorrection(int &correct, int amountOfDays, int amountOfDaysOld);
};

#endif
