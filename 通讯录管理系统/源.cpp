#include<filesystem>
#include<fstream>
#include"Contact.h"
#include"Menu.h"
using namespace std;
void save(contact contact[100]);
void read(contact*contact);

int main()
{
	contact contact[100];
	read(contact);
	int select = 0;
	do
	{
		menuMain();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			for (int i= 0; i < 100; i++)
			{
				if(i < 100&&contact[i].getExist() == false)
				{
						contact[i].addContact();
						system("cls");
						i = 101;
				}
				if(i==100)
				{
					cout << "联系人已满" << endl;

				}
			}
		} break;
		case 2:
		{
			for (int i = 0; i < 100; i++)
			{
				if (contact[i].getExist() == true)
				{
					cout << "联系人编号：" << i << endl;
					contact[i].disPlayContact();
				}
			}
			int I;
			cout<< "输入 0 返回上级菜单" << endl;
			cin >> I;
			if ( I== 0)system("cls");
		}break;
		case 3:
		{
			system("cls");
			deleteContact(contact);
		}break;
		case 4:
		{
			system("cls");
		    findContact(contact);

		}break;
		case 5:
		{
			system("cls");
			ModifyContact(contact);
		}break;
		case 6:
		{
			system("cls");
			emptyContact(contact);
		}break;
		case 0:
			select = 0;
			break;
		default:
			system("cls");
			break;
		}
	} while (select);
	save(contact);
}
void save(contact contact[100])
{

	ofstream output;
	output.open("Contact.txt");
	for (int i = 0; i < 100; i++)
	{
		if (contact[i].getExist() == true)
		{
			output << contact[i].getName() << "\t" << contact[i].getGende() << "\t" << contact[i].getAge()
				<< "\t" << contact[i].getPhone() << "\t" << contact[i].getHome() << "\n";
		}
	}
	output.close();
};
void read(contact* contact)
{
	/*std::filesystem::path p{ "通讯录.txt" };
	std::ifstream input{ p };*/

	ifstream input;
	input.open("Contact.txt");
	string name, gender, age, phone,home;
	for (int i = 0; i < 100&& input >> name >> gender >> age >> phone >> home; i++)
	{
			contact[i].setName(name);
			contact[i].setGende(gender);
			contact[i].setAge(age);
			contact[i].setPhone(phone);
			contact[i].setHome(home);
			contact[i].setExist();
	}
	input.close();
		/*std::getline(input, (contact + i)->getName(), ' ');
		std::getline(input, (contact + i)->getGende(), ' ');
		std::getline(input, (contact + i)->getAge(), ' ');
		std::getline(input, (contact + i)->getPhone(), ' ');
		std::getline(input, (contact + i)->getHome(), '\n');*/
		/*input.seekg(0, std::ios::beg);
		input >> (contact + i)->getName();
		input >> (contact + i)->getGende();
		input >> (contact + i)->getAge();
		input >> (contact + i)->getPhone();
		input >> (contact + i)->getHome();*/
};
