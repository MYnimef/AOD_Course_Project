#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    date1 = new Date();
    date2 = new Date();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dateInput1_clicked()
{
    date1->buildDate(ui->dateEdit1->toPlainText());
    ui->dateLabel1->setText(date1->toDefaultString());

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


void MainWindow::on_dateInput2_clicked()
{
    date2->buildDate(ui->dateEdit2->toPlainText());
    ui->dateLabel2->setText(date2->toDefaultString());

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

