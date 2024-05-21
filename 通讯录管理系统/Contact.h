#pragma once
#include<iostream>
#include<string>
#include"Menu.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

class contact
{
private:
	string name;
	string gende;
	string age;
	string phone;
	string home;
	bool Exist=false;
public:
		string getName()
		{
			return name;
		}
		string getGende()
		{
			return gende;
		}
		string getAge()
		{
			return age;
		}
		string getPhone()
		{
			return phone;
		}
		string getHome()
		{
			return home;
		}
		void setName(string name)
		{
			 this->name=name;
		}
		void setGende(string gender)
		{
			this->gende=gender;
		}
		void setAge(string age)
		{
			this->age=age;
		}
		void setPhone(string phone)
		{
			this->phone=phone;
		}
		void setHome(string home)
		{
			this->home=home;
		}
		bool getExist()
		{
			return Exist;
		}
		void setExist()
		{
			Exist=true;
		}

	void addContact()
	{
		Exist = true;
		cout << "请输入联系人名字：" ;
		cin >> name;
		cout << "请输入联系人性别(male||female)：" ;
		cin >> gende;
		cout << "请输入联系人年龄：" ;
		cin >> age;
		cout << "请输入联系人电话号码：" ;
		cin >> phone;
		cout << "请输入联系人家庭住址：" ;
		cin >> home;
	}

	void disPlayContact()
	{
		if(Exist)
		{
			cout << "联系人名字：" << name<<endl;
			cout << "联系人性别：" << gende << endl;
			cout << "联系人年龄：" << age << endl;
			cout << "联系人电话号码：" << phone<<endl;
			cout << "联系人家庭住址：" << home << endl;
		}
	}

	void deleteContact()
	{
		Exist = false;
	}

	void modifyContact()
	{
		int select=0;
		do
		{
			system("cls");
			this->disPlayContact();
			menuModify();
			cin >> select;
			switch (select)
			{
			case 1:
				cout << "请输入修改为后的联系人名字：";
				cin >> name;
				break;
			case 2:
				cout << "请输入修改为后的联系人性别(male||female)：";
				cin >> gende;
				break;
			case 3:
				cout << "请输入修改为后的联系人年龄：";
				cin >> age;
				break;
			case 4:
				cout << "请输入修改为后的联系人电话号码：";
				cin >> phone;
				break;
			case 5:
				cout << "请输入修改为后的联系人家庭住址：";
				cin >> home;
				break;
			case 0:
				this->disPlayContact();
				select = 0;
				int I;
				cout << "输入 0 返回上级菜单" << endl;
				cin >> I;
				if (I == 0)system("cls");
				break;
			}
		} while (select);
	}
};

void deleteContact(contact contact[100])
{
	int select;
	do
	{
		menuDelete();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "请输入编号(0--100):" << endl;
			int BH;
			cin >> BH;
			if (contact[BH].getExist() != false)
			{
				if (contact[BH].getExist() != false)
				{
					cout << "联系人编号：" << BH << endl;
					contact[BH].disPlayContact();
				}
				for (int j = BH; j < 100; j++)
				{
					contact[j] = contact[j + 1];
				}
			}
			else
			{
				cout << "不存在编号为 " << BH << " 的联系人 " << endl;
			}
			int I;
			cout << "输入 0 返回上级菜单" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 2:
		{
			cout << "请输入姓名:" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name == contact[i].getName())
				{
					cout << "联系人编号：" << i << endl;
					contact[i].disPlayContact();
					for (int j = i; j < 100; j++)
					{
						contact[j] = contact[j + 1];
					}
				}
				if(i==100)
				{
					cout<<"不存在姓名为 " << name << " 的联系人" << endl;
				}
			}
			int I;
			cout << "输入 0 返回上级菜单" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 3:
		{
			cout << "请输入电话号码:" << endl;
			string phone;
			cin >> phone;
			for (int i = 0; i < 100; i++)
			{
				if (phone == contact[i].getPhone())
				{
					cout << "联系人编号：" << i << endl;
					contact[i].disPlayContact();
					for (int j = i; j < 100; j++)
					{
						contact[j] = contact[j + 1];
					}
				}
				if (i == 100)
				{
					cout << "不存在电话号码为 " << phone << " 的联系人" << endl;
				}
			}
			int I;
			cout << "输入 0 返回上级菜单" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}
		break;
		case 0:
			system("cls");
			select = 0;
			break;
	    }
	} while (select);
};

void findContact(contact contact[100])
{
	int select;
	menuFind();
	do
	{
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "请输入编号(0--100):" << endl;
			int BH;
			cin >> BH;
			if (contact[BH].getExist() != 0)
			{
				contact[BH].disPlayContact();
			}
			else
			{
				cout << "不存在编号为 " << BH << " 的联系人 " << endl;
			}
		}break;
		case 2:
		{
			cout << "请输入姓名:" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name == contact[i].getName())
				{
					contact[i].disPlayContact();
				}
				if (i == 100)
				{
					cout << "不存在姓名为 " << name << " 的联系人" << endl;
				}
			}
		}break;
		case 3:
		{
			cout << "请输入电话号码:" << endl;
			string phone;
			cin >> phone;
			for (int i = 0; i < 100; i++)
			{
				if (phone == contact[i].getPhone())
				{
					contact[i].disPlayContact();
				}
				if (i == 100)
				{
					cout << "不存在电话号码为 " << phone << " 的联系人" << endl;
				}
			}
		}
		break;
		case 0:
			system("cls");
			select = 0;
			break;
		}
	} while (select);
};

void emptyContact(contact contact[100])
{
	for (int i = 0; i < 100; i++)
	{
		contact[i].deleteContact();
	}
};

void ModifyContact(contact contact[100])
{
	int select;
	do
	{
		menumodify();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "请输入编号(0--100):" << endl;
			int BH;
			cin >> BH;
			if (contact[BH].getExist() != false)
			{
				if (contact[BH].getExist() != false)
				{
					cout << "联系人编号：" << BH << endl;
					contact[BH].modifyContact();
				}
			}
			else
			{
				cout << "不存在编号为 " << BH << " 的联系人 " << endl;
			}
			int I;
			cout << "输入 0 返回上级菜单" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 2:
		{
			cout << "请输入姓名:" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name == contact[i].getName())
				{
						cout << "联系人编号：" << i << endl;
					    contact[i].modifyContact();
				}
				if (i == 100)
				{
					cout << "不存在姓名为 " << name << " 的联系人" << endl;
				}
			}
			int I;
			cout << "输入 0 返回上级菜单" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 3:
		{
			cout << "请输入电话号码:" << endl;
			string phone;
			cin >> phone;
			for (int i = 0; i < 100; i++)
			{
				if (phone == contact[i].getPhone())
				{
					cout << "联系人编号：" << i << endl;
					contact[i].modifyContact();
				}
				if (i == 100)
				{
					cout << "不存在电话号码为 " << phone << " 的联系人" << endl;
				}
			}
			int I;
			cout << "输入 0 返回上级菜单" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}
		break;
		case 0:
			system("cls");
			select = 0;
			break;
		}
	} while (select);
};