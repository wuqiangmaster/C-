#pragma once
#include<iostream>

void save(Player* player);
void read(Player* player);

void randomized(int* A,int* B)
{
	int number[12];
	for (int i = 0; i < 12; i++)
	{
		number[i] = i + 1;
	}
	for (int i = 0; i < 12; i++)
	{
		time_t temp;
		srand(time(&temp));
		int randomized = (rand() % 12);
		int j{0};
		number[i] = j;
		number[i] = number[randomized];
		number[randomized] = i;
	}
	for (int i = 0; i < 6; i++)
	{
		A[i] = number[i];
	}
	for (int i = 0; i < 6; i++)
	{
		B[i + 6] = number[i + 6];
	}
};

void startGame(int A[6], int B[6], Player* player)
{
	cout << "������ʼ��" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "����A�� " << A[i] << " ��ѡ����̨" << endl;
		cout << "��A�� " << A[i + 1] << " ��ѡ������׼��" << endl;
		cin.get();
		cout << "������ίΪA�� " << A[i] << " ��ѡ������" << endl;
		player[A[i]].setGrade();
		system("cls");
	}

	cout << "A���ѡ�ֳɼ�" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << A[i] << "��ѡ��" << ":" << player[A[i]].getName() << "�ɼ�Ϊ��" << player[A[i]].getGrade();
	}
	system("cls");
	cout << "�г���Ϣ10����" << "/n" << "��B��ѡ������׼��" << endl;
	cin.get();
	cout << "�г���Ϣ����" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "����B�� " << B[i] << " ��ѡ����̨" << endl;
		cout << "��B�� " << B[i + 1] << " ��ѡ������׼��" << endl;
		cin.get();
		cout << "������ίΪA�� " << B[i] << " ��ѡ������" << endl;
		player[B[i]].setGrade();
		system("cls");
	}
	cout << "B���ѡ�ֳɼ�" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << B[i] << "��ѡ��" << ":" << player[B[i]].getName() << "�ɼ�Ϊ��" << player[A[i]].getGrade();
	}
	system("cls");
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (player[A[i]].getGrade() < player[A[j]].getGrade())
			{
				int temp;
				temp = A[i];
				A[i] = A[j];
				A[j] = A[i];
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (player[B[i]].getGrade() < player[B[j]].getGrade())
			{
				int temp;
				temp = B[i];
				B[i] = B[j];
				B[j] = B[i];
			}
		}
	}

	cout << "A�����ѡ��Ϊ" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << A[i] << "��ѡ�� " << player[A[i]].getName() << ":" << player[A[i]].getGrade();
	}
	cout << "B�����ѡ��Ϊ" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << B[i] << "��ѡ�� " << player[B[i]].getName() << ":" << player[B[i]].getGrade();
	}
	system("cls");
	cout << "�����������ʼ����";
	cin.get();
	cout << "������ʼ��" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "���� " << A[i] << " ��ѡ����̨" << endl;
		cout << "�� " << A[i + 1] << " ��ѡ������׼��" << endl;
		cin.get();
		cout << "������ίΪ" << A[i] << " ��ѡ������" << endl;
		player[A[i]].setGrade();
		system("cls");
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "���� " << B[i] << " ��ѡ����̨" << endl;
		cout << "�� " << B[i + 1] << " ��ѡ������׼��" << endl;
		cin.get();
		cout << "������ίΪ" << B[i] << " ��ѡ������" << endl;
		player[B[i]].setGrade();
		system("cls");
	}

	cout << "��ѡ�ֳɼ�" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << A[i] << "��ѡ��" << ":" << player[A[i]].getName() << "�ɼ�Ϊ��" << player[A[i]].getGrade();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << B[i] << "��ѡ��" << ":" << player[B[i]].getName() << "�ɼ�Ϊ��" << player[A[i]].getGrade();
	}
	system("cls");
	double number[6];
	int rank[6];
	for (int i = 0; i < 6; i++)
	{
		number[i] = player[A[i]].getGrade();
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (number[i]< number[i+1])
			{
				int temp;
				temp = number[i];
				number[i] = number[j];
				number[j] = number[i];
			}
		}
		for (int k = 0; k < 3; k++)
		{
			if (player[A[k]].getGrade() == number[i])
			{
				rank[i] = A[k];
			}
			if (player[B[k]].getGrade() == number[i])
			{
				rank[i] = B[k];
			}
		}
	}

	cout << "��ʤ��Ϊ" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << rank[i] << "��ѡ��" << ":" << player[rank[i]].getName() << "�ɼ�Ϊ��" << player[A[i]].getGrade();
		player[rank[i]].setRank(i);
	}

	save(player);
}
void save(Player* player)
{

	std::ofstream output;
	output.open("gameRecorg.csv");
	for (int i = 0; i <100; i++)
	{
		output << player[i].getRank() << "\t" << player[i].getName() << "\t" << player[i].getGrade() << "\n";
	}
	output.close();
};
void read(Player* player)
{
	std::ifstream input;
	input.open("gameRecorg.csv");
	int rank;
	string  name;
	double grade;
	for (int i = 0; i < 3 && input >> rank >> name >> grade; i++)
	{
		player[i].setRank(rank);
		player[i].setName(name);
		player[i].saveGrade(grade);
	}
	input.close();
};