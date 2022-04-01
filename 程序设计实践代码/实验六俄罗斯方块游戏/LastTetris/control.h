#ifndef CONTROL_H
#define CONTROL_H
#include<QVector>
#include<QPoint>
#include<QDebug>

class Control
{
public:
    Control();
    //当前处于的x坐标
    int x;
    //当前处于的y坐标
    int y;
    //方块的类型
    int type;
    //方块类型变成了那种了
    int process;
    //颜色类型
    int color;


    static QVector<QVector<int>> map; //map类  地图信息
    static QVector<QVector<QVector<QPoint>>> block; //留存砖块形状 配合control类生成方块
    static QVector<QVector<int>> colorMap;

    //生成新的砖块
    void newBlock();

    //砖块发生移动的时候 检查下标
    bool indexCheck(int moveX,int moveY,int newProcess);

    //移动操作
    void move(int type);

    //垃圾回收 即发生移动过后 清楚上一步的痕迹
    void gc();

    //重新绘制
    void rePaint();

    //判断清除一行
    void clearRow();

    //重置等于操作
    void operator=(Control&);

    void gameOver();
};

#endif // CONTROL_H
