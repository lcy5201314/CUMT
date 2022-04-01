#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QLineEdit>
#include<iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    void MainWindow::check();
    ~MainWindow();

    int err;

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
