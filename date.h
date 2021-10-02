#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
private:
    bool isDate;
    int day;
    int month;
    int year;
    QString dayStr;
    QString monthStr;
    QString yearStr;

    int findSymb(QString str, int pos);
    bool checkDate();
    void correctDate(int correction);
public:
    Date();
    Date(QString date);
    void buildDate(QString date);
    QString toDefaultString();
    QString toAmericanString();
    bool getIsDate();
    void increment();
    void decrement();
    void updateStrings();
    bool checkCorrection(int &correct, int amountOfDays, int amountOfDaysOld);
};

#endif
