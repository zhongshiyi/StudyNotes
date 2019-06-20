#pragma execution_character_set("utf-8")
#pragma once

#include <QtWidgets/QWidget>
#include "ui_Sushi.h"

class Sushi : public QWidget
{
	Q_OBJECT

public:
	Sushi(QWidget *parent = Q_NULLPTR);

public slots:
	void Calculate();//º∆À„

private:
	int price[25] = { 0 };
	int level[25] = { 0 };
	int *dp;
	Ui::SushiClass ui;

};
