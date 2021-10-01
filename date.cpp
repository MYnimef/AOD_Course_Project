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
    this->dateStr = str.left(index);
    this->day = this->dateStr.toInt(&isDate);

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
        return dateStr + "." + monthStr + "." + yearStr;
    }
    return "Wrong date format!";
}

QString Date::toAmericanString()
{
    if (isDate)
    {
        return monthStr + "." + dateStr + "." + yearStr;
    }
    return "Wrong date format!";
}
