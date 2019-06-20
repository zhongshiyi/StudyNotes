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
	//----------------LineEdit ��˾���ࡢ��Ԥ��---------------

	QString str_sushi_num = ui.lineEdit_Sushi_num->text();//��˾����
	int sushi_num = str_sushi_num.toInt();//��String ת��Ϊ int����

	QString str_totle_budget = ui.lineEdit_totle_budget->text();//��Ԥ��
	int total_budget = str_totle_budget.toInt();

	//�ж���˾��������
	if (sushi_num < 1 || sushi_num > 20) {
		QMessageBox::critical(NULL, "��Χ����", "��˾������ 1-20 ֮��",
			QMessageBox::Yes, QMessageBox::Yes);
		ui.lineEdit_Sushi_num->setFocus();
		return;
	}
	//�ж���Ԥ��
	if (total_budget < 1 || total_budget > pow(10, 9)) {
		QMessageBox::critical(NULL, "��Χ����", "��Ԥ���� 1-10^9 ֮��",
			QMessageBox::Yes, QMessageBox::Yes);
		ui.lineEdit_totle_budget->setFocus();
		return;
	}

	//TextEdit ��˾�ļ۸�͵ȼ�
	QString price_level = ui.textEdit->toPlainText();//��ȡ TextEdit �е�����

	total_budget = total_budget / 100;//Ԥ����С100��
	int i = 1;
	bool error = false;
	try {
		for (QString s : price_level.split("\n")) {//�Իس��ָ�
			QStringList sl = s.split(" ");//�Կո�ָ�
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
		QMessageBox::critical(NULL, "��������", "�۸�/�ȼ���ʽ���ڴ���",
			QMessageBox::Yes, QMessageBox::Yes);
		ui.textEdit->setFocus();
	}
	//����
	if (!error) {
		dp = new int[total_budget + 5];
		memset(dp, 0, sizeof(int)*total_budget);//��ʼ��
		for (int i = 1; i <= sushi_num; i++) {
			for (int j = price[i]; j <= total_budget; j++) {
				dp[j] = std::max(dp[j], dp[j - price[i]] + level[i]);
			}
		}
		
		ui.LogOutput->appendPlainText(QString("���ȼ�Ϊ��%1").arg(dp[total_budget]));
	
		delete[] dp;
	}
}
