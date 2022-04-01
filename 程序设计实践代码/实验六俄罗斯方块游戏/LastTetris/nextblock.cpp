#include "nextblock.h"

NextBlock::NextBlock(QWidget *parent) : QWidget(parent)
{

}


//{0, 0}, {1, 0}, {0, 1}, {1, 1}
void NextBlock::paintEvent (QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(this);
    p.setViewport(this->rect());
    p.setWindow(0,0,80,80);

    QPen pen;
    pen.setWidth(0);
    pen.setColor("blue");
    p.setPen(pen);
    p.drawRect(10,10,60,60);

    GameWidget::anotherCon.block[GameWidget::anotherCon.type][GameWidget::anotherCon.process];

    for(int i=0;i<4;i++)
    {
        int width = GameWidget::anotherCon.block[GameWidget::anotherCon.type][GameWidget::anotherCon.process][i].x();
        int height = GameWidget::anotherCon.block[GameWidget::anotherCon.type][GameWidget::anotherCon.process][i].y();
        p.fillRect(25+width*10,25+height*10,10,10,GameWidget::color[GameWidget::anotherCon.color]);

        pen.setWidth(0);
        pen.setColor("white");
        p.setPen(pen);
        p.drawRect(25+width*10,25+height*10,10,10);
    }

}
