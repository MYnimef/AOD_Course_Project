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
    this->dayStr = str.left(index);
    this->day = this->dayStr.toShort(&isDate);

    index++;
    int index2 = findSymb(str, index);
    this->monthStr = str.mid(index, index2 - index);
    this->month = this->monthStr.toShort(&isDate);

    this->yearStr = str.right(str.length() - index2 - 1);
    if (this->yearStr.length() == 2)
    {
        this->yearStr = "20" + yearStr;
    }
    this->year = this->yearStr.toShort(&isDate);

    this->isDate = checkDate();
    if (isDate)
    {
        setDayOfWeek();
    }
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
    short februaryDays = year % 4 ? 29 : 28;
    short monthDays[] = {31, februaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day <= monthDays[month] && day > 0)
    {
        return true;
    }
    return false;
}

int Date::findSymb(QString str, short pos)
{
    int index1 = str.indexOf('.', pos);
    int index2 = str.indexOf('/', pos);
    int index3 = str.indexOf(' ', pos);
    int index4 = str.indexOf('-', pos);

    if (index1 != -1) {
        return index1;
    }
    else if (index2 != -1) {
        return index2;
    }
    else if (index3 != -1) {
        return index3;
    }
    else if (index4 != -1) {
        return index4;
    }

    return -1;
    this->isDate = false;
}

QString Date::toDefaultString()
{
    if (isDate)
    {
        return dayStr + "." + monthStr + "." + yearStr + ", " + dayOfWeek;
    }
    return "Wrong date format!";
}

QString Date::toAmericanString()
{
    if (isDate)
    {
        return monthStr + "." + dayStr + "." + yearStr + ", " + dayOfWeek;
    }
    return "Wrong date format!";
}

bool Date::getIsDate()
{
    return isDate;
}

void Date::increment()
{
    correctDate(day + 1);
    updateStrings();
}

void Date::decrement()
{
    correctDate(day - 1);
    updateStrings();
}

void Date::updateStrings()
{
    dayStr = QString::number(day);
    if (dayStr.length() < 2)
    {
        dayStr = "0" + dayStr;
    }
    monthStr = QString::number(month);
    if (monthStr.length() < 2)
    {
        monthStr = "0" + monthStr;
    }
    yearStr = QString::number(year);
    if (yearStr.length() < 2)
    {
        yearStr = "0" + yearStr;
    }
    setDayOfWeek();
}

void Date::correctDate(int correction)
{
    switch(month) {
    case 1:
        if (correction <= 31 && correction > 0) {
            day = correction;
            break;
        }
        else if (correction > 31)
        {
            month++;
            correction -= 31;
        }
        else if (correction <= 0)
        {
            year--;
            month += 11;
            correctDate(correction + 31);
            break;
        }
    case 2:
        if (checkCorrection(correction, year % 4 == 0 ? 29 : 28, 31))
            break;
    case 3:
        if (checkCorrection(correction, 31, year % 4 == 0 ? 29 : 28))
            break;
    case 4:
        if (checkCorrection(correction, 30, 31))
            break;
    case 5:
        if (checkCorrection(correction, 31, 30))
            break;
    case 6:
        if (checkCorrection(correction, 30, 31))
            break;
    case 7:
        if (checkCorrection(correction, 31, 30))
            break;
    case 8:
        if (checkCorrection(correction, 31, 31))
            break;
    case 9:
        if (checkCorrection(correction, 30, 31))
            break;
    case 10:
        if (checkCorrection(correction, 31, 30))
            break;
    case 11:
        if (checkCorrection(correction, 30, 31))
            break;
    case 12:
        if (correction <= 31 && correction > 0) {
            day = correction;
            break;
        }
        else if (correction > 31)
        {
            year++;
            month = 1;
            correctDate(correction - 31);
            break;
        }
        else if (correction <= 0)
        {
            month--;
            correctDate(correction + 30);
            break;
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
