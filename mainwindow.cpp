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

    dialog = new QDialog(this);
    dialog->setWindowTitle(tr("Изменить дату"));
    ledit = new QLineEdit(dialog);

    btn_box = new QDialogButtonBox(dialog);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(btn_box, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, dialog, &QDialog::reject);

    layout = new QFormLayout();
    layout->addRow(tr("Введите кол-во дней:"), ledit);
    layout->addWidget(btn_box);

    dialog->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete date1;
    delete date2;

    delete layout;
    delete btn_box;
    delete ledit;
    delete dialog;
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

        ui->increaseDate1->setEnabled(true);
        ui->decreaseDate1->setEnabled(true);
    }
    else
    {
        ui->incrementDate1->setEnabled(false);
        ui->decrementDate1->setEnabled(false);

        ui->increaseDate1->setEnabled(false);
        ui->decreaseDate1->setEnabled(false);
    }
}

void MainWindow::showDate1()
{
    if (format)
        ui->dateLabel1->setText(date1->toDefaultString());
    else
        ui->dateLabel1->setText(date1->toAmericanString());
    if (date2->getIsDate())
        ui->dateDifference->setText(date1->dayDifference(*date2));
}


void MainWindow::on_dateInput2_clicked()
{
    date2->buildDate(ui->dateEdit2->toPlainText());
    showDate2();

    if (date2->getIsDate())
    {
        ui->incrementDate2->setEnabled(true);
        ui->decrementDate2->setEnabled(true);

        ui->increaseDate2->setEnabled(true);
        ui->decreaseDate2->setEnabled(true);
    }
    else
    {
        ui->incrementDate2->setEnabled(false);
        ui->decrementDate2->setEnabled(false);

        ui->increaseDate2->setEnabled(false);
        ui->decreaseDate2->setEnabled(false);
    }
}

void MainWindow::showDate2()
{
    if (format)
        ui->dateLabel2->setText(date2->toDefaultString());
    else
        ui->dateLabel2->setText(date2->toAmericanString());
    if (date1->getIsDate())
        ui->dateDifference->setText(date2->dayDifference(*date1));
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
    if(dialog->exec() == QDialog::Accepted)
    {
        bool flag;
        int num = ledit->text().toInt(&flag);
        ledit->setText("");
        if (flag)
        {
            date1->change(num);
            showDate1();
        }
    }
}


void MainWindow::on_decreaseDate1_clicked()
{
    if(dialog->exec() == QDialog::Accepted)
    {
        bool flag;
        int num = ledit->text().toInt(&flag);
        ledit->setText("");
        if (flag)
        {
            date1->change(-num);
            showDate1();
        }
    }
}


void MainWindow::on_increaseDate2_clicked()
{
    if(dialog->exec() == QDialog::Accepted)
    {
        bool flag;
        int num = ledit->text().toInt(&flag);
        ledit->setText("");
        if (flag)
        {
            date2->change(num);
            showDate2();
        }
    }
}


void MainWindow::on_decreaseDate2_clicked()
{
    if(dialog->exec() == QDialog::Accepted)
    {
        bool flag;
        int num = ledit->text().toInt(&flag);
        ledit->setText("");
        if (flag)
        {
            date2->change(-num);
            showDate2();
        }
    }
}
