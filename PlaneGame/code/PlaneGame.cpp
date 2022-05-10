#include "PlaneGame.h"
#include <QDebug>
#include <ctime>
#include <QSound>

PlaneGame::PlaneGame(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	m_recorder = 0;
	initScene();

	//启动背景音乐
	//QSound::play(SOUND_BACKGROUND);
}

void PlaneGame::initScene()
{
	//初始化窗口大小
	setFixedSize(GAME_WIDTH, GAME_HEIGHT);
	//设置窗口标题
	setWindowTitle(QStringLiteral(GAME_TITLE));
	//图标设置
	setWindowIcon(QIcon(":/resource/app.ico"));

	//定时器设置
	m_Timer.setInterval(GAME_RATE);

	//开始游戏
	playGame();


	//随机数种子
	srand((unsigned int)time(NULL));
}

void PlaneGame::playGame()
{
	//启动定时器
	m_Timer.start();
	//监听定时器
	connect(&m_Timer, &QTimer::timeout, [=]() {
		//敌机出场
		enemyToScene();
		//更新游戏中元素的坐标
		updatePosition();
		//重新绘制图片
		update();
		//碰撞检测
		collisionDetection();
	});
}

void PlaneGame::updatePosition()
{
	//更新地图坐标
	m_map.mapPosition();

	//发射子弹
	m_hero.shoot();
	//计算子弹坐标
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//如果子弹状态为非空闲，计算发射位置
		if (!m_hero.m_bullets[i].m_Free)
		{
			m_hero.m_bullets[i].updatePosition();
		}
	}
	//敌机坐标计算
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//非空闲敌机 更新坐标
		if (m_enemys[i].m_Free == false)
		{
			m_enemys[i].updatePosition();
		}
	}
	//计算爆炸播放的图片
	for (int i = 0; i < BOMB_NUM; i++)
	{
		if (m_bombs[i].m_Free == false)
		{
			m_bombs[i].updateInfo();
		}
	}
}

void PlaneGame::enemyToScene()
{
	m_recorder++;
	//300ms出一次敌机
	if (m_recorder < ENEMY_INTERVAL)
	{
		return;
	}
	m_recorder = 0;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemys[i].m_Free)
		{
			//敌机空闲状态改为false
			m_enemys[i].m_Free = false;
			//设置坐标
			m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());//随机出现位置
			m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
			break;
		}
	}
}

void PlaneGame::collisionDetection()
{
	//遍历所有非空闲的敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemys[i].m_Free)
		{
			//空闲飞机 跳转下一次循环
			continue;
		}
		//遍历所有 非空闲的子弹
		for (int j = 0; j < BULLET_NUM; j++)
		{
			if (m_hero.m_bullets[j].m_Free)
			{
				//空闲子弹 跳转下一次循环
				continue;
			}
			//如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
			if (m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
			{
				m_enemys[i].m_Free = true;
				m_hero.m_bullets[j].m_Free = true;

				//播放爆炸效果
				for (int k = 0; k < BOMB_NUM; k++)
				{
					if (m_bombs[k].m_Free)
					{
						//爆炸状态设置为非空闲
						m_bombs[k].m_Free = false;
						//更新坐标
						m_bombs[k].m_X = m_enemys[i].m_X;
						m_bombs[k].m_Y = m_enemys[i].m_Y;
						break;
					}
				}				//播放爆炸音效
				//QSound::play(SOUND_BOMB);
			}
		}
	}
}

void PlaneGame::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	//绘制地图
	painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
	painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

	//绘制英雄 
	painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_Plane);

	//绘制子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//如果子弹状态为非空闲，计算发射位置
		if (!m_hero.m_bullets[i].m_Free)
		{
			painter.drawPixmap(m_hero.m_bullets[i].m_X, m_hero.m_bullets[i].m_Y, m_hero.m_bullets[i].m_Bullet);
		}
	}
	//绘制敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemys[i].m_Free == false)
		{
			painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
		}
	}
	//绘制爆炸图片
	for (int i = 0; i < BOMB_NUM; i++)
	{
		if (m_bombs[i].m_Free == false)
		{
			painter.drawPixmap(m_bombs[i].m_X, m_bombs[i].m_Y, m_bombs[i].m_pixArr[m_bombs[i].m_index]);
		}
	}

}

void PlaneGame::mouseMoveEvent(QMouseEvent * event)
{
	qDebug() << "pos :: " << event->pos();
	int x = event->x() - m_hero.m_Rect.width()*0.5; //鼠标位置 - 飞机矩形的一半
	int y = event->y() - m_hero.m_Rect.height()*0.5;

	//边界检测
	if (x <= 0)
	{
		x = 0;
	}
	if (x >= GAME_WIDTH - m_hero.m_Rect.width())
	{
		x = GAME_WIDTH - m_hero.m_Rect.width();
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (y >= GAME_HEIGHT - m_hero.m_Rect.height())
	{
		y = GAME_HEIGHT - m_hero.m_Rect.height();
	}
	m_hero.setPosition(x, y);
}
