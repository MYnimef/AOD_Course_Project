#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dateInput1_clicked();

    void on_dateInput2_clicked();

    void on_incrementDate1_clicked();

    void on_decrementDate1_clicked();

    void on_incrementDate2_clicked();

    void on_decrementDate2_clicked();

    void on_increaseDate1_clicked();

    void on_decreaseDate1_clicked();

    void on_increaseDate2_clicked();

    void on_decreaseDate2_clicked();

    void setDefaultFormat();

    void setAmericanFormat();

private:
    Ui::MainWindow *ui;
    Date* date1;
    Date* date2;
    bool format;

    QDialog* dialog;
    QLineEdit* ledit;
    QDialogButtonBox* btn_box;
    QFormLayout* layout;

    void showDate1();
    void showDate2();
};
#endif // MAINWINDOW_H
