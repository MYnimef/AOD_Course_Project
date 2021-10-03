#include "date.h"

Date::Date()
{
    this->isDate = false;
}

Date::Date(QString str)
{
    buildDate(str);
}

void Date::buildDate(QString str)
{
    this->isDate = true;

    int index = findSymb(str, 0);
    QString dayStr = str.left(index);
    this->day = dayStr.toShort(&isDate);

    index++;
    int index2 = findSymb(str, index);
    QString monthStr = str.mid(index, index2 - index);
    this->month = monthStr.toShort(&isDate);

    QString yearStr = str.right(str.length() - index2 - 1);
    this->year = yearStr.toShort(&isDate);
    if (this->year < 100)
        year += 2000;

    this->isDate = checkDate();
    if (isDate)
        setDayOfWeek();
}

void Date:: setDayOfWeek()
{
    QString week[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};

    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    short num = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;

    this->dayOfWeek = week[num];
}

bool Date::checkDate()
{
    short februaryDays = year % 4 == 0 ? 29 : 28;
    short monthDays[] = {31, februaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year > 0)
        if (month >= 1 && month <= 12)
            if (day <= monthDays[month - 1] && day >= 1)
                return true;
    return false;
}

int Date::findSymb(QString str, short pos)
{
    int index1 = str.indexOf('.', pos);
    int index2 = str.indexOf('/', pos);
    int index3 = str.indexOf(' ', pos);
    int index4 = str.indexOf('-', pos);

    if (index1 != -1)
        return index1;
    else if (index2 != -1)
        return index2;
    else if (index3 != -1)
        return index3;
    else if (index4 != -1)
        return index4;

    this->isDate = false;
    return -1;
}

QString Date::toDefaultString()
{
    QString dayStr, monthStr, yearStr;
    getStrings(dayStr, monthStr, yearStr);

    if (isDate)
        return dayStr + "." + monthStr + "." + yearStr + ", " + dayOfWeek;
    return "Wrong date format!";
}

QString Date::toAmericanString()
{
    QString dayStr, monthStr, yearStr;
    getStrings(dayStr, monthStr, yearStr);

    if (isDate)
        return monthStr + "." + dayStr + "." + yearStr + ", " + dayOfWeek;
    return "Wrong date format!";
}

bool Date::getIsDate()
{
    return isDate;
}

void Date::increment()
{
    correctDate(day + 1);
}

void Date::decrement()
{
    correctDate(day - 1);
}

void Date::change(int numOfDays)
{
    correctDate(day + numOfDays);
}

void Date::getStrings(QString &dayStr, QString &monthStr, QString &yearStr)
{
    dayStr = QString::number(day);
    if (dayStr.length() < 2)
        dayStr = "0" + dayStr;

    monthStr = QString::number(month);
    if (monthStr.length() < 2)
        monthStr = "0" + monthStr;

    yearStr = QString::number(year);
    if (yearStr.length() < 4)
        yearStr = "0" + yearStr;

    setDayOfWeek();
}

void Date::correctDate(int correction)
{
    short februaryDays = year % 4 == 0 ? 29 : 28;
    short monthDays[] = {31, februaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 1)
    {
        if (correction <= 31 && correction > 0) {
            day = correction;
            return;
        }
        else if (correction > 31)
        {
            month++;
            correction -= 31;
        }
        else
        {
            year--;
            month += 11;
            correctDate(correction + 31);
            return;
        }
    }

    for (int i = 2; i <= 11; i++)
        if (i == month)
            if (checkCorrection(correction, monthDays[i - 1], monthDays[i - 2]))
                return;

    if (month == 12)
    {
        if (correction <= 31 && correction > 0) {
            day = correction;
        }
        else if (correction > 31)
        {
            year++;
            month = 1;
            correctDate(correction - 31);
        }
        else
        {
            month--;
            correctDate(correction + 30);
        }
    }
}

bool Date::checkCorrection(int &correct, int amountOfDays, int amountOfDaysOld)
{
    if (correct <= amountOfDays && correct > 0) {
        day = correct;
        return true;
    }
    else if (correct > amountOfDays)
    {
        month++;
        correct -= amountOfDays;
        return false;
    }
    else
    {
        month--;
        correctDate(correct + amountOfDaysOld);
        return true;
    }
}

short Date::getDay()
{
    if (isDate)
        return day;
    else
        return -1;
}

short Date::getMonth()
{
    if (isDate)
        return month;
    else
        return -1;
}

short Date::getYear()
{
    if (isDate)
        return year;
    else
        return -1;
}

QString Date::dayDifference(Date date)
{

}
