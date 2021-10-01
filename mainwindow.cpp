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
}


void MainWindow::on_dateInput2_clicked()
{
    date2->buildDate(ui->dateEdit2->toPlainText());
    ui->dateLabel2->setText(date2->toDefaultString());
}
