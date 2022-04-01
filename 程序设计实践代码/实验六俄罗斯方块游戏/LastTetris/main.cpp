#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    //注册外部的二进制资源文件
    QResource::registerResource(GAME_RES_PATH);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
