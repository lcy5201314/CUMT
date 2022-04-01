#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QSound>
#include <QKeyEvent>
#include <QTimer>
#include <QSound>
#include <QMessageBox>
#include <QResource>

#define GAME_RES_PATH  "./res.rcc" //rcc文件路径

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void keyPressEvent (QKeyEvent *);

    static int running;

    static int score;


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
