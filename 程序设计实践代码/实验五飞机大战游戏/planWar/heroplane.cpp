#include "heroplane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    //加载飞机图片资源
    m_Plane.load(HERO_PATH);

    //初始化坐标(通过计算飞机在屏幕坐标得)
    m_X = GAME_WIDTH * 0.5 - m_Plane.width() *0.5;
    m_Y = GAME_HEIGHT - m_Plane.height() - 100;

    //矩形边框 碰撞检测用
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);

    //初始化间隔记录变量
    m_recorder = 0;
}

//设置飞机位置
void HeroPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

//发射子弹
void HeroPlane::shoot()
{
    //累加事件间隔记录的变量
    m_recorder++;


    //如果记录数字 未达到发射间隔，直接return
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    //发射子弹
    for(int i = 0 ; i < BULLET_NUM;i++)
    {
        //如果是空闲状态的子弹，发射子弹
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free = false;
            m_bullets[i].m_X = m_X+m_Rect.width()*0.5 - 10;
            m_bullets[i].m_Y = m_Y - 25 ;
            break;
        }

    }
}
