#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void btn_logic(int x , QString i = " ");

    void den_logic();

    void decimalToAny(int n,int d);



public:
    QString a;        //a来存储内容
    QString chh;
    QStringList b;    //b来存储运算符 b[0]数字1 b[1]运算符 b[2]数字2

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
