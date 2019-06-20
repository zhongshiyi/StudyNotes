#include "Sushi.h"
#include<cmath>
#include<algorithm>
#include<qmessagebox.h>

Sushi::Sushi(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void Sushi::Calculate() {
	//----------------LineEdit 寿司种类、总预算---------------

	QString str_sushi_num = ui.lineEdit_Sushi_num->text();//寿司种类
	int sushi_num = str_sushi_num.toInt();//把String 转化为 int类型

	QString str_totle_budget = ui.lineEdit_totle_budget->text();//总预算
	int total_budget = str_totle_budget.toInt();

	//判断寿司种类数量
	if (sushi_num < 1 || sushi_num > 20) {
		QMessageBox::critical(NULL, "范围错误", "寿司数量在 1-20 之间",
			QMessageBox::Yes, QMessageBox::Yes);
		ui.lineEdit_Sushi_num->setFocus();
		return;
	}
	//判断总预算
	if (total_budget < 1 || total_budget > pow(10, 9)) {
		QMessageBox::critical(NULL, "范围错误", "总预算在 1-10^9 之间",
			QMessageBox::Yes, QMessageBox::Yes);
		ui.lineEdit_totle_budget->setFocus();
		return;
	}

	//TextEdit 寿司的价格和等级
	QString price_level = ui.textEdit->toPlainText();//获取 TextEdit 中的数据

	total_budget = total_budget / 100;//预算缩小100倍
	int i = 1;
	bool error = false;
	try {
		for (QString s : price_level.split("\n")) {//以回车分割
			QStringList sl = s.split(" ");//以空格分割
			if (sl.length() < 2 || sl[0].toInt() == 0 || sl[1].toInt() == 0) {
				throw 0;
			}
			
			price[i] = sl[0].toInt() / 100;
			level[i] = sl[1].toInt();
			i++;
		}
	}
	catch (...) {
		error = true;
		QMessageBox::critical(NULL, "发生错误", "价格/等级格式存在错误",
			QMessageBox::Yes, QMessageBox::Yes);
		ui.textEdit->setFocus();
	}
	//计算
	if (!error) {
		dp = new int[total_budget + 5];
		memset(dp, 0, sizeof(int)*total_budget);//初始化
		for (int i = 1; i <= sushi_num; i++) {
			for (int j = price[i]; j <= total_budget; j++) {
				dp[j] = std::max(dp[j], dp[j - price[i]] + level[i]);
			}
		}
		
		ui.LogOutput->appendPlainText(QString("最大等级为：%1").arg(dp[total_budget]));
	
		delete[] dp;
	}
}
