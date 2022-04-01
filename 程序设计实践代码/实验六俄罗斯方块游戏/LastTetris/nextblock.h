#ifndef NEXTBLOCK_H
#define NEXTBLOCK_H

#include <QWidget>
#include<QPen>
#include<QPainter>
#include"gamewidget.h"
#include<QColor>
#include "mainwindow.h"


class NextBlock : public QWidget
{
    Q_OBJECT
public:
    explicit NextBlock(QWidget *parent = nullptr);

    void paintEvent (QPaintEvent *e);
signals:

public slots:
};

#endif // NEXTBLOCK_H
