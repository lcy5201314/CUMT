#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include "config.h"
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"
#include "start.h"
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <QSound>
#include <ctime>
#include <QMessageBox>
#include <QPushButton>

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    MainScreen(QWidget *parent = 0);
    ~MainScreen();

    //初始化场景
    void initScene();

    //游戏重新开始
    void slotStart();

    //初始化显示
    void initialDisplay();
    //启动游戏  用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *);

    //敌机出场
    void enemyToScene();

    //碰撞检测
    void collisionDetection();


    //地图对象
    Map m_map;

    //创建飞机对象
    HeroPlane m_hero;


    //定时器对象
    QTimer m_Timer;


    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder;

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];


    //得分计算
    int score;

    int Inumber;

    Start ui;
    //测试子弹
    //Bullet temp_Bullet;
};

#endif // MAINSCREEN_H
