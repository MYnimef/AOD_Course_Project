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
    this->day = this->dayStr.toInt(&isDate);

    index++;
    int index2 = findSymb(str, index);
    this->monthStr = str.mid(index, index2 - index);
    this->month = this->monthStr.toInt(&isDate);

    this->yearStr = str.right(str.length() - index2 - 1);
    if (this->yearStr.length() == 2)
    {
        this->yearStr = "20" + yearStr;
    }
    this->year = this->yearStr.toInt(&isDate);

    this->isDate = checkDate();
}

bool Date::checkDate()
{
    switch(month) {
    case 1:
        if (day <= 31) {
            break;
        }
        return false;
    case 2:
        if (year % 4 == 0) {
            if (day <= 29) {
                break;
            }
        } else {
            if (day <= 28) {
                break;
            }
        }
        return false;
    case 3:
        if (day <= 31) {
            break;
        }
        return false;
    case 4:
        if (day <= 30) {
            break;
        }
        return false;
    case 5:
        if (day <= 31) {
            break;
        }
        return false;
    case 6:
        if (day <= 30) {
            break;
        }
        return false;
    case 7:
        if (day <= 31) {
            break;
        }
        return false;
    case 8:
        if (day <= 31) {
            break;
        }
        return false;
    case 9:
        if (day <= 30) {
            break;
        }
        return false;
    case 10:
        if (day <= 31) {
            break;
        }
        return false;
    case 11:
        if (day <= 30) {
            break;
        }
        return false;
    case 12:
        if (day <= 31) {
            break;
        }
        return false;
    default:
        return false;
    }

    if (day < 0) {
        return false;
    }

    return true;
}

int Date::findSymb(QString str, int pos)
{
    int index1 = str.indexOf('.', pos);
    int index2 = str.indexOf('/', pos);
    int index3 = str.indexOf(' ', pos);

    if (index1 != -1) {
        return index1;
    }
    else if (index2 != -1) {
        return index2;
    }
    else if (index3 != -1) {
        return index3;
    }

    return -1;
    this->isDate = false;
}

QString Date::toDefaultString()
{
    if (isDate)
    {
        return dayStr + "." + monthStr + "." + yearStr;
    }
    return "Wrong date format!";
}

QString Date::toAmericanString()
{
    if (isDate)
    {
        return monthStr + "." + dayStr + "." + yearStr;
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
