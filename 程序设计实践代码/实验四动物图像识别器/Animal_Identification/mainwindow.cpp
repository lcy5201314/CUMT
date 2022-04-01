#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew,&QAction::triggered,this,&MainWindow::openImageSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openImageSlot()
{
    imgPath = QFileDialog::getOpenFileName(this,"选择图片",QCoreApplication::applicationFilePath());
    if(imgPath.isEmpty())
    {
        QMessageBox::warning(this,"提示","请选择一张图片");

    }

    QPixmap pix(imgPath);
    ui->label->setPixmap(pix);
}


void MainWindow::on_pushButton_clicked()
{
    QByteArray img = Image::imageToBase64(imgPath);
    QByteArray imgData = "image=" + img;

    //获取access_token
    QByteArray replyData;

    QString url = QString(BaiduTokenUrl).arg(client_id).arg(secret_id);

    QMap<QString, QString> header;
    header.insert(QString("Content-Type"), QString("application/x-www-form-urlencoded"));

    QString accessToken;
    bool result;
    result = Http::post_sync(url, header, imgData, replyData);
    if(result)
    {
        QJsonObject obj = QJsonDocument::fromJson(replyData).object();
        qDebug() << obj.value("access_token").toString();
        accessToken = obj.value("access_token").toString();

    }

    char*  ch;
    QByteArray ba = accessToken.toLatin1();
    ch=ba.data();

    replyData.clear();
    QString imgUrl = baiduImageUrl + accessToken;
    qDebug() << imgUrl;

    //发起第二次请求
    result = Http::post_sync(imgUrl,header,imgData,replyData);
    if(result)
    {
        //没办法解析？？？
        QJsonObject obj = QJsonDocument::fromJson(replyData).object();

        qDebug() << obj.value("log_id").toString();
        QJsonValue val = obj.value("result");
        if(val.isArray())
        {
            QJsonValue first = val.toArray().at(0);

            if(first.isObject())
            {
                QString name = first.toObject().value("name").toString();
                qDebug() << first.toObject().value("name").toString();
                ui->lineEdit->setText(name);
                return;
            }
        }

    }

    ui->lineEdit->setText("识别错误，这是什么呢？");
    return;
}
