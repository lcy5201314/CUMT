#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();

    void myRand();

    //开始游戏的按钮，指针
    QPushButton *button;
    //4*4的数据集
    int s[4][4];
    //得分
    int score = 0;
    //状态
    bool state;

    //随机的一个点
    struct Ns
    {
        int i;
        int j;
    };


 //槽函数
public slots:
    void slotStart();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
