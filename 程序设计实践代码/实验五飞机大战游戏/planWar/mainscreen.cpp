#include "mainscreen.h"


MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent)
{

    //启动背景音乐(循环播放)
    //QSound::play(SOUND_BACKGROUND);
    QSound *sound = new QSound(SOUND_BACKGROUND,this);
    sound->setLoops(-1);
    sound->play();


    QPushButton *button=new QPushButton(this);
    button->setText("开始游戏");
    button->setStyleSheet("background:#C3C8C9;color:gray");
    resize(GAME_WIDTH,GAME_HEIGHT);
    button->move(width()*0.35,height()*0.65);

    Inumber = 0;
    score = 0;

    connect(button,&QPushButton::clicked,[=](){

        QMessageBox::StandardButton rb = QMessageBox::information(this,"游戏规则","控制鼠标移动击打飞机。",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
            initScene();
        }
        else if (rb == QMessageBox::No)
        {
            exit(1);
        }
        button->hide();
        //this->hide();
        });

//    QMessageBox::StandardButton rb = QMessageBox::information(this,"游戏规则","控制鼠标移动击打飞机。",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//    if(rb == QMessageBox::Yes)
//    {
//        initScene();
//    }
//    else if (rb == QMessageBox::No)
//    {
//        exit(1);
//    }
    //initScene();
}

MainScreen::~MainScreen()
{

}

void MainScreen::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置窗口标题
    setWindowIcon(QIcon(GAME_ICON));

    //设置定时器间隔
    //m_Timer.setSingleShot(true);
    m_Timer.setInterval(GAME_RATE);

    //QMessageBox::about(this,"游戏规则","鼠标左键移动");


    //清屏
    //system ("clear");
    //initialDisplay();
    //调用启动游戏接口
    playGame();

    //敌机出场纪录变量 初始化
    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));
}

void MainScreen::slotStart()
{
    //QMessageBox::about(this,"游戏规则","鼠标左键移动");


    //设置定时器间隔
    m_Timer.setInterval(GAME_RATE);
    //initialDisplay();

    //system ("clear");
    initialDisplay();

    playGame();

    //敌机出场纪录变量 初始化
    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));
}


void MainScreen::initialDisplay()
{

    //绘制飞机
    m_hero.m_X = GAME_WIDTH * 0.5 - m_hero.m_Plane.width() *0.5;
    m_hero.m_Y = GAME_HEIGHT - m_hero.m_Plane.height() - 100;


    //绘制子弹

    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        m_hero.m_bullets[i].m_X = GAME_WIDTH *0.5 - m_hero.m_bullets[i].m_Bullet.width() * 0.5;
        m_hero.m_bullets[i].m_Y = GAME_HEIGHT;
        m_hero.m_bullets[i].m_Free == true;
    }



    //绘制敌机
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        m_enemys[i].m_X = 0;
        m_enemys[i].m_Y = 0;

        m_enemys[i].m_Free == true;
    }


    //绘制爆炸图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
       m_bombs[i].m_Free == true;
    }


    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));

    m_Timer.setTimerType(Qt::CoarseTimer);
    m_Timer.setInterval(GAME_RATE + Inumber);

    //敌机出场
    enemyToScene();
    //更新游戏中所有元素的坐标
    updatePosition();
    //游戏中的元素 绘制到屏幕中
    update();

}


void MainScreen::playGame()
{


    //玩游戏 启动定时器
    m_Timer.start();

    //监听定时器的信号
    connect(&m_Timer , &QTimer::timeout,[=](){


        //敌机出场
        enemyToScene();
        //更新游戏中所有元素的坐标
        updatePosition();
        //游戏中的元素 绘制到屏幕中
        update();
        //再调用paintEvent函数

        //碰撞检测
        collisionDetection();
    });
}

void MainScreen::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //发射子弹
    m_hero.shoot();

    //计算子弹坐标
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(m_hero.m_bullets[i].m_Free == false)
        {
            m_hero.m_bullets[i].updatePosition();
        }

    }

    //敌机坐标计算
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲敌机 更新坐标
       if(m_enemys[i].m_Free == false)
       {
          m_enemys[i].updatePosition();
       }
    }

    //计算爆炸播放的图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
           m_bombs[i].updateInfo();
        }
    }

    //测试子弹
//    temp_Bullet.m_Free = false;
//    temp_Bullet.updatePosition();
}


void MainScreen::paintEvent(QPaintEvent *event)
{
    //利用画家画图图片
    QPainter painter(this);


    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

    //绘制子弹
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲 ，绘制图片
        if(m_hero.m_bullets[i].m_Free == false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }

    }

    //绘制敌机
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    //绘制爆炸图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
           painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }

    //测试子弹
    //painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);
}




void MainScreen::mouseMoveEvent(QMouseEvent * event)
{
    int x =  event->x() -m_hero.m_Rect.width() * 0.5;
    int y =  event->y() -m_hero.m_Rect.height() *0.5;

    //边界检测

    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HEIGHT - m_hero.m_Rect.height();
    }

    m_hero.setPosition(x,y);
}



void MainScreen::enemyToScene()
{
    //累加出场间隔
    m_recorder++;
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //敌机空闲状态改为false
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}





void MainScreen::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }

            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                //播放音效
                QSound::play(SOUND_BOMB);


                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;

                //调用爆炸特效
                //播放爆炸效果
                score++;
              for(int k = 0 ; k < BOMB_NUM;k++)
              {
                  if(m_bombs[k].m_Free)
                  {
                      //爆炸状态设置为非空闲
                      m_bombs[k].m_Free = false;
                      //更新坐标
                      m_bombs[k].m_X = m_enemys[i].m_X;
                      m_bombs[k].m_Y = m_enemys[i].m_Y;
                      break;
                  }
              }

            }
        }
    }

    //遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }
        if(m_enemys[i].m_Rect.intersects(m_hero.m_Rect))
        {
            QSound::play(SOUND_BOMB);

            m_Timer.stop();

            for(int k = 0 ; k < BOMB_NUM;k++)
            {
                if(m_bombs[k].m_Free)
                {
                    //爆炸状态设置为非空闲
                    m_bombs[k].m_Free = false;
                    //更新坐标
                    m_bombs[k].m_X = m_enemys[i].m_X;
                    m_bombs[k].m_Y = m_enemys[i].m_Y;
                    break;
                }
            }


            QMessageBox::StandardButton rb = QMessageBox::information(this,"游戏失败","分数为：" + QString::number(score)+"\n"+"游戏是否重新开始？",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            if(rb == QMessageBox::Yes)
            {
                score = 0;
                Inumber += 10;
                initialDisplay();
                //initScene();
                playGame();
                //需要一个游戏开始的页面
                //slotStart();
            }
            else if (rb == QMessageBox::No)
            {
                exit(1);
            }
            //QMessageBox::about(this,"游戏失败","分数为：" + QString::number(score)+" ");
            //exit(1);
        }

    }
}

