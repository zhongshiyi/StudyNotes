# 虚基类：

## 1、虚基类的作用

如果一个派生类有多个基类，而这些直接基类又有一个共同的基类，则最终的派生类中会保留该间接共同基类数据成员的多分同名成员。在引用这些同名的成员时，必须在派生类对象名后增加直接基类名，以避免产生二义性，使其使用唯一地标识成员。

+ C++ 提供 **虚基类**(virtual base class)的方法，使得**在继承间接公共基类时只保留一份成员**。

## 2、声明虚基类的一般形式：

**class 派生类名：virtual 继承方式 基类名**

## 代码：
```c
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:		//保护成员
	string name;
	string sex;
	int age;
public:
	//默认构造函数（Default constructor）
	Person() {
		name = "Miles";
		sex = "male";
		age = 32;
	}
	Person(string name, string sex, int age) {
		this->name = name;
		this->sex = sex;
		this->age = age;
	}
};

class Teacher :virtual public Person {
protected:
	string title;		//职称
public:
	Teacher():Person() {
		this->title = "stupid";
	}
	Teacher(string name, string sex, int age, string title) :Person(name, sex, age) {
		this->title = title;
	}
};

class Student :virtual public Person {
protected:
	float score;		//分数
public:
	Student():Person() {
		score = 0;
	}
	Student(string name, string sex, int age, float score) :Person(name, sex, age) {
		this->score = score;
	}
};

class Graduate :public Teacher, public Student {
protected:
	float allowance;		//津贴
public:
	Graduate() :Teacher(), Student() {
		this->allowance = 0;
	}
	Graduate(string name, string sex, int age, string title, float score, float allowance) :Teacher(name, sex, age, title), Student(name, sex, age, score) {
		this->allowance = allowance;
	}

	void show() {
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
		cout << "age:" << age << endl;
		cout << "title:" << title << endl;
		cout << "score:" << score << endl;
		cout << "allowance:" << allowance << endl<< endl;
	}
};

int main() {
	Graduate one;
	cout << "* Default constructor!" << endl;
	one.show();

	Graduate tow("zhongshiyi", "male", 21, "assistant", 100, 1000);
	cout << "* Constructor!" << endl;
	tow.show();

	return 0;
}
```

## 结果：

![virtual.png](https://upload-images.jianshu.io/upload_images/17431817-e35d5db469348f55.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
