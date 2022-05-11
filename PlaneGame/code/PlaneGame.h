#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QFont>
#include <QMouseEvent>

#include "ui_PlaneGame.h"
#include "config.h"
#include "Map.h"
#include "HeroPlane.h"
#include "Bullet.h"
#include "EnemyPlane.h"
#include "Bomb.h"

class PlaneGame : public QMainWindow
{
    Q_OBJECT

public:
    PlaneGame(QWidget *parent = Q_NULLPTR);

	void initScene();
	void connectInit();

	//启动游戏 用于启动定时器对象
	void playGame();
	void stopGame();
	//更新坐标
	void updatePosition();
	//敌机出场
	void enemyToScene();

	//碰撞检测
	void collisionDetection();	void clearScene();
protected:
	//绘图事件
	void paintEvent(QPaintEvent *event);
	//鼠标移动事件
	void mouseMoveEvent(QMouseEvent *event);


private:
	QTimer m_Timer;
	//地图对象
	Map m_map;
	//主飞机对象
	HeroPlane m_hero;
	//敌机数组
	EnemyPlane m_enemys[ENEMY_NUM];
	//敌机出场间隔记录
	int m_recorder;
	//爆炸数组
	Bomb m_bombs[BOMB_NUM];
	bool isOver = false;
private:
    Ui::PlaneGameClass ui;
};
