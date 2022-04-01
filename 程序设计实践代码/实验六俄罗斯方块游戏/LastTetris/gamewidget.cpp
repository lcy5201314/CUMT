#include "gamewidget.h"



Control  GameWidget::con;
Control  GameWidget::anotherCon;
QTimer* GameWidget::timer;

bool GameWidget::gameOver=false;


QVector<QColor> GameWidget::color=
{
    QColor::fromRgb(85,170,255),QColor::fromRgb(255,125,33),
    QColor::fromRgb(33,178,74),QColor::fromRgb(189,121,82),
    QColor::fromRgb(140,0,16),QColor::fromRgb(57,73,206),
    QColor::fromRgb(255,203,8),QColor::fromRgb(181,231,24)
};



GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    //设置尺寸
    this->resize(350,700);
    //调整尺寸
    for(int i=0;i<10;i++)
    {
        Control::map.push_back(QVector<int>(20,0));
    }
    for(int i=0;i<10;i++)
    {
        Control::colorMap.push_back(QVector<int>(20,0));
    }
    //con.rePaint();
}


void GameWidget::paintEvent (QPaintEvent *)
{
    QPainter p(this);
    p.setViewport(this->rect());
    p.setWindow(-1,-1,101,201);
    QPen pen;
    pen.setWidth(0);
    pen.setColor("black");
    p.setPen(pen);
    p.drawRect(-1,-1,100,200);
    //根据1的标志 来绘画砖块
    for(int i=0;i<Control::map.size();i++)
    {
        for(int j=0;j<Control::map[i].size();j++)
        {
            if(Control::map[i][j])
            {
                p.fillRect(i*10,j*10,9,9,color[Control::colorMap[i][j]]);
            }
        }
    }
    pen.setWidth(0);
    pen.setColor("white");
    p.setPen(pen);

    //画线
    for(int i=1;i<20;i++)
    {
        p.drawLine(0,i*10,99,i*10);
    }
    for(int i=1;i<10;i++)
    {
        p.drawLine(i*10,1,i*10,198);
    }
    if(gameOver)
    {
        delete timer;
        timer = nullptr;
        emit GameOver();
    }
}


//void GameWidget::keyPressEvent(QKeyEvent *e){
//    if(e->key()==Qt::Key_Up){
//        con.move(1);
//    }
//    else if(e->key()==Qt::Key_Down){
//        con.move(2);
//    }
//    else if(e->key()==Qt::Key_Left){
//        con.move(3);
//    }
//    else if(e->key()==Qt::Key_Right){
//        con.move(4);
//    }
//    update();
//}

