#ifndef DATE_H
#define DATE_H

#include <QString>

class Date {
private:
    bool isDate;
    short day;
    short month;
    short year;
    QString dayOfWeek;

    int findSymb(QString str, short pos);
    bool checkDate();
    void correctDate(int correction);
    void getStrings(QString &dayStr, QString &monthStr, QString &yearStr);
    bool checkCorrection(int &correct, int amountOfDays, int amountOfDaysOld);
    int rdn();

public:
    Date();
    Date(QString date);
    short getDay();
    short getMonth();
    short getYear();
    void buildDate(QString date);
    void setDayOfWeek();
    QString toDefaultString();
    QString toAmericanString();
    bool getIsDate();
    void increment();
    void decrement();
    void change(int numOfDays);
    QString dayDifference(Date date);
};

#endif
