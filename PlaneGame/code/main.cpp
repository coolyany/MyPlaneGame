﻿#include "PlaneGame.h"
#include <QtWidgets/QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	////注册外部的二进制资源文件
	//QResource::registerResource(GAME_RES_PATH);

    PlaneGame w;
    w.show();
    return a.exec();
}
