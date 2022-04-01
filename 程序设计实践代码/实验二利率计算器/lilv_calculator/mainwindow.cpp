#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>

QString str_ans;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        err = 0;
        ui->setupUi(this);
    }
    int temp_1=0;
    int temp_2=0;

    MainWindow::~MainWindow()
    {
        delete ui;
    }

//void MainWindow::check()
//{

//}

void MainWindow::on_pushButton_clicked()
{

    double num1=ui->lineEdit->text().toInt();   //贷款年限（年）
    double num2=ui->lineEdit_2->text().toInt();    //贷款金额（万元）
    double num3=ui->lineEdit_3->text().toInt()/100.0;   //贷款利率
    double yue_num3=num3/12.0;    //月利率
    double yue_num2=num2/12.0;    //
    if(temp_1==0&&temp_2==0)
    {
        QMessageBox::critical(NULL, "错误信息", "未选择还款方式", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        //err = 1;
    }
    else if(temp_1==1&&temp_2==2)
    {
        QMessageBox::critical(NULL, "错误信息", "请选择一种还款方式", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        //err = 1;
    }
    else if(num1<=0)
         QMessageBox::critical(NULL, "错误信息", "未输入有效贷款年限信息", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    else if(num2<=0)
         QMessageBox::critical(NULL, "错误信息", "未输入有效贷款金额信息", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    else if(num3<=0)
         QMessageBox::critical(NULL, "错误信息", "未输入有效贷款利率信息", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    double ans=num1*num2*num3;
//    str_ans=Qstring::number(ui->lineEdit->text().toInt()*ui->lineEdit_2->text().toInt()*ui->lineEdit_3->text().toInt()/100);
//    for(int i=0;i<str_ans.size();i++)
//    {
//        ans+=(char(int(str_ans[i])-'0')*pow(10,str_ans.size()-i-1));
//    }
    if(num1<=0||num2<=0||num3<=0||(temp_1==0&&temp_2==0)||(temp_1==1&&temp_2==2))
    {
        ui->textBrowser_6->clear();
        ui->textBrowser_5->clear();
        ui->textBrowser_4->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    if(temp_1==1)
    {
        double nn=-((num2*num3*((1+yue_num3)*num1*12-(1+yue_num3)*(num1*12-1))/((1+yue_num3)*num1*12-1))*12-num2);
        ui->textBrowser_6->setText(QString::number((nn/10.0+num2)*10000));    //还款总额
        ui->textBrowser_5->setText(QString::number(nn*1000));    //利息总额
        ui->textBrowser_4->setText(QString::number((num2*yue_num3*(1+yue_num3)*num1*12.0)/(1+yue_num3)*num1*12.0-1000));  //月均还款
    }
    //ui->textBrowser_6->setText(QString::number(ans));    //还款总额
    //ui->textBrowser_5->setText(QString::number(ans));    //利息总额
    //ui->textBrowser_4->setText(QString::number(ans/12.0));  //月均还款
    if(temp_2==2)
    {
        double yue_huan=(num2/num1*12)+(num2)*yue_num3;
        double yue_lixi=(num2)*yue_num3;
        double total_lixi=((num2/num1*12+num2*yue_num3)+num2/num1*12*(1+yue_num3))/2*num1*12-num2;
        ui->textBrowser_6->setText(QString::number(((total_lixi/10000+num2)*10000)));    //还款总额
        ui->textBrowser_5->setText(QString::number(total_lixi));    //利息总额
        ui->textBrowser_4->setText(QString::number(yue_huan*100));
    }
}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    ui->textBrowser_6->clear();
    ui->textBrowser_5->clear();
    ui->textBrowser_4->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    temp_1=0;
    temp_2=0;
}


//等额本息
void MainWindow::on_checkBox_clicked()
{
    if(temp_1==1) temp_1=0;
    else temp_1=1;
    if(temp_2==2&&err == 0)
    {
        QMessageBox::critical(NULL, "错误信息", "请选择一种还款方式", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        ui->textBrowser_6->clear();
        ui->textBrowser_5->clear();
        ui->textBrowser_4->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->checkBox_2->click();
        //err = 1;
    }

}

//等额本金
void MainWindow::on_checkBox_2_clicked()
{
    if(temp_2==2) temp_2=0;
    else temp_2=2;
    if(temp_1==1)
    {
        QMessageBox::critical(NULL, "错误信息", "请选择一种还款方式", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        ui->textBrowser_6->clear();
        ui->textBrowser_5->clear();
        ui->textBrowser_4->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();

        ui->checkBox->click();
    }
}
