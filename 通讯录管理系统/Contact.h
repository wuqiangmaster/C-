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
		cout << "��������ϵ�����֣�" ;
		cin >> name;
		cout << "��������ϵ���Ա�(male||female)��" ;
		cin >> gende;
		cout << "��������ϵ�����䣺" ;
		cin >> age;
		cout << "��������ϵ�˵绰���룺" ;
		cin >> phone;
		cout << "��������ϵ�˼�ͥסַ��" ;
		cin >> home;
	}

	void disPlayContact()
	{
		if(Exist)
		{
			cout << "��ϵ�����֣�" << name<<endl;
			cout << "��ϵ���Ա�" << gende << endl;
			cout << "��ϵ�����䣺" << age << endl;
			cout << "��ϵ�˵绰���룺" << phone<<endl;
			cout << "��ϵ�˼�ͥסַ��" << home << endl;
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
				cout << "�������޸�Ϊ�����ϵ�����֣�";
				cin >> name;
				break;
			case 2:
				cout << "�������޸�Ϊ�����ϵ���Ա�(male||female)��";
				cin >> gende;
				break;
			case 3:
				cout << "�������޸�Ϊ�����ϵ�����䣺";
				cin >> age;
				break;
			case 4:
				cout << "�������޸�Ϊ�����ϵ�˵绰���룺";
				cin >> phone;
				break;
			case 5:
				cout << "�������޸�Ϊ�����ϵ�˼�ͥסַ��";
				cin >> home;
				break;
			case 0:
				this->disPlayContact();
				select = 0;
				int I;
				cout << "���� 0 �����ϼ��˵�" << endl;
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
			cout << "��������(0--100):" << endl;
			int BH;
			cin >> BH;
			if (contact[BH].getExist() != false)
			{
				if (contact[BH].getExist() != false)
				{
					cout << "��ϵ�˱�ţ�" << BH << endl;
					contact[BH].disPlayContact();
				}
				for (int j = BH; j < 100; j++)
				{
					contact[j] = contact[j + 1];
				}
			}
			else
			{
				cout << "�����ڱ��Ϊ " << BH << " ����ϵ�� " << endl;
			}
			int I;
			cout << "���� 0 �����ϼ��˵�" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 2:
		{
			cout << "����������:" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name == contact[i].getName())
				{
					cout << "��ϵ�˱�ţ�" << i << endl;
					contact[i].disPlayContact();
					for (int j = i; j < 100; j++)
					{
						contact[j] = contact[j + 1];
					}
				}
				if(i==100)
				{
					cout<<"����������Ϊ " << name << " ����ϵ��" << endl;
				}
			}
			int I;
			cout << "���� 0 �����ϼ��˵�" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 3:
		{
			cout << "������绰����:" << endl;
			string phone;
			cin >> phone;
			for (int i = 0; i < 100; i++)
			{
				if (phone == contact[i].getPhone())
				{
					cout << "��ϵ�˱�ţ�" << i << endl;
					contact[i].disPlayContact();
					for (int j = i; j < 100; j++)
					{
						contact[j] = contact[j + 1];
					}
				}
				if (i == 100)
				{
					cout << "�����ڵ绰����Ϊ " << phone << " ����ϵ��" << endl;
				}
			}
			int I;
			cout << "���� 0 �����ϼ��˵�" << endl;
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
			cout << "��������(0--100):" << endl;
			int BH;
			cin >> BH;
			if (contact[BH].getExist() != 0)
			{
				contact[BH].disPlayContact();
			}
			else
			{
				cout << "�����ڱ��Ϊ " << BH << " ����ϵ�� " << endl;
			}
		}break;
		case 2:
		{
			cout << "����������:" << endl;
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
					cout << "����������Ϊ " << name << " ����ϵ��" << endl;
				}
			}
		}break;
		case 3:
		{
			cout << "������绰����:" << endl;
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
					cout << "�����ڵ绰����Ϊ " << phone << " ����ϵ��" << endl;
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
			cout << "��������(0--100):" << endl;
			int BH;
			cin >> BH;
			if (contact[BH].getExist() != false)
			{
				if (contact[BH].getExist() != false)
				{
					cout << "��ϵ�˱�ţ�" << BH << endl;
					contact[BH].modifyContact();
				}
			}
			else
			{
				cout << "�����ڱ��Ϊ " << BH << " ����ϵ�� " << endl;
			}
			int I;
			cout << "���� 0 �����ϼ��˵�" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 2:
		{
			cout << "����������:" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < 100; i++)
			{
				if (name == contact[i].getName())
				{
						cout << "��ϵ�˱�ţ�" << i << endl;
					    contact[i].modifyContact();
				}
				if (i == 100)
				{
					cout << "����������Ϊ " << name << " ����ϵ��" << endl;
				}
			}
			int I;
			cout << "���� 0 �����ϼ��˵�" << endl;
			cin >> I;
			if (I == 0)system("cls");
		}break;
		case 3:
		{
			cout << "������绰����:" << endl;
			string phone;
			cin >> phone;
			for (int i = 0; i < 100; i++)
			{
				if (phone == contact[i].getPhone())
				{
					cout << "��ϵ�˱�ţ�" << i << endl;
					contact[i].modifyContact();
				}
				if (i == 100)
				{
					cout << "�����ڵ绰����Ϊ " << phone << " ����ϵ��" << endl;
				}
			}
			int I;
			cout << "���� 0 �����ϼ��˵�" << endl;
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