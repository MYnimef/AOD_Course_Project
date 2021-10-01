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
    QString dateStr;
    QString monthStr;
    QString yearStr;

    int findSymb(QString str, int pos);
public:
    Date();
    Date(QString date);
    void buildDate(QString date);
    bool checkDate();
    QString toDefaultString();
    QString toAmericanString();
};

#endif
