#include "bullet.h"

Bullet::Bullet()
{
    //加载自动资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标初始化
    m_X = GAME_WIDTH *0.5 - m_Bullet.width() * 0.5;
    m_Y = GAME_HEIGHT;

    //子弹空闲状态
    m_Free = true;

    //子弹速度
    m_Speed = BULLET_SPEED;

    //子弹矩形边框 （碰撞检测）
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要计算坐标
    if(m_Free)
    {
        return;
    }

    //子弹向上移动
    m_Y -=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y <= - m_Rect.height())
    {
        m_Free = true;
    }

}
