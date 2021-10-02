#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    date1 = new Date();
    date2 = new Date();
    format1 = true;
    format2 = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dateInput1_clicked()
{
    date1->buildDate(ui->dateEdit1->toPlainText());
    if (format1)
    {
        ui->dateLabel1->setText(date1->toDefaultString());
    }
    else
    {
        ui->dateLabel1->setText(date1->toAmericanString());
    }

    if (date1->getIsDate())
    {
        ui->incrementDate1->setEnabled(true);
        ui->decrementDate1->setEnabled(true);

        ui->defaultFormat1->setEnabled(true);
        ui->americanFromat1->setEnabled(true);
    }
    else
    {
        ui->incrementDate1->setEnabled(false);
        ui->decrementDate1->setEnabled(false);

        ui->defaultFormat1->setEnabled(false);
        ui->americanFromat1->setEnabled(false);
    }
}


void MainWindow::on_dateInput2_clicked()
{
    date2->buildDate(ui->dateEdit2->toPlainText());
    if (format2)
    {
        ui->dateLabel2->setText(date2->toDefaultString());
    }
    else
    {
        ui->dateLabel2->setText(date2->toAmericanString());
    }

    if (date2->getIsDate())
    {
        ui->incrementDate2->setEnabled(true);
        ui->decrementDate2->setEnabled(true);

        ui->defaultFormat2->setEnabled(true);
        ui->americanFormat2->setEnabled(true);
    }
    else
    {
        ui->incrementDate2->setEnabled(false);
        ui->decrementDate2->setEnabled(false);

        ui->defaultFormat2->setEnabled(false);
        ui->americanFormat2->setEnabled(false);
    }
}

void MainWindow::on_incrementDate1_clicked()
{
    date1->increment();
    ui->dateLabel1->setText(date1->toDefaultString());
}


void MainWindow::on_decrementDate1_clicked()
{
    date1->decrement();
    ui->dateLabel1->setText(date1->toDefaultString());
}


void MainWindow::on_incrementDate2_clicked()
{
    date2->increment();
    ui->dateLabel2->setText(date2->toDefaultString());
}


void MainWindow::on_decrementDate2_clicked()
{
    date2->decrement();
    ui->dateLabel2->setText(date2->toDefaultString());
}


void MainWindow::on_defaultFormat1_clicked()
{
    if(!format1)
    {
        format1 = true;
        ui->dateLabel1->setText(date1->toDefaultString());
    }
}


void MainWindow::on_americanFromat1_clicked()
{
    if(format1)
    {
        format1 = false;
        ui->dateLabel1->setText(date1->toAmericanString());
    }
}


void MainWindow::on_defaultFormat2_clicked()
{
    if(!format2)
    {
        format2 = true;
        ui->dateLabel2->setText(date2->toDefaultString());
    }
}


void MainWindow::on_americanFormat2_clicked()
{
    if(format2)
    {
        format2 = false;
        ui->dateLabel2->setText(date2->toAmericanString());
    }
}


void MainWindow::on_increaseDate1_clicked()
{

}


void MainWindow::on_decreaseDate1_clicked()
{

}


void MainWindow::on_increaseDate2_clicked()
{

}


void MainWindow::on_decreaseDate2_clicked()
{

}

