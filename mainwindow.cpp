#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    date1 = new Date();
    date2 = new Date();
    format = true;

    connect(ui->defaultFormat, SIGNAL(triggered()), this, SLOT(setDefaultFormat()));
    connect(ui->americanFormat, SIGNAL(triggered()), this, SLOT(setAmericanFormat()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete date1;
    delete date2;
}

void MainWindow::setDefaultFormat()
{
    if (!format)
    {
        ui->americanFormat->setChecked(false);
        format = true;
        if (date1->getIsDate())
            showDate1();
        if (date2->getIsDate())
            showDate2();
    }
}

void MainWindow::setAmericanFormat()
{
    if (format)
    {
        ui->defaultFormat->setChecked(false);
        this->format = false;
        if (date1->getIsDate())
            showDate1();
        if (date2->getIsDate())
            showDate2();
    }
}


void MainWindow::on_dateInput1_clicked()
{
    date1->buildDate(ui->dateEdit1->toPlainText());
    showDate1();

    if (date1->getIsDate())
    {
        ui->incrementDate1->setEnabled(true);
        ui->decrementDate1->setEnabled(true);
    }
    else
    {
        ui->incrementDate1->setEnabled(false);
        ui->decrementDate1->setEnabled(false);
    }
}

void MainWindow::showDate1()
{
    if (format)
        ui->dateLabel1->setText(date1->toDefaultString());
    else
        ui->dateLabel1->setText(date1->toAmericanString());
}


void MainWindow::on_dateInput2_clicked()
{
    date2->buildDate(ui->dateEdit2->toPlainText());
    showDate2();

    if (date2->getIsDate())
    {
        ui->incrementDate2->setEnabled(true);
        ui->decrementDate2->setEnabled(true);
    }
    else
    {
        ui->incrementDate2->setEnabled(false);
        ui->decrementDate2->setEnabled(false);
    }
}

void MainWindow::showDate2()
{
    if (format)
        ui->dateLabel2->setText(date2->toDefaultString());
    else
        ui->dateLabel2->setText(date2->toAmericanString());
}

void MainWindow::on_incrementDate1_clicked()
{
    date1->increment();
    showDate1();
}


void MainWindow::on_decrementDate1_clicked()
{
    date1->decrement();
    showDate1();
}


void MainWindow::on_incrementDate2_clicked()
{
    date2->increment();
    showDate2();
}


void MainWindow::on_decrementDate2_clicked()
{
    date2->decrement();
    showDate2();
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
