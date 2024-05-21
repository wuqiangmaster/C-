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
	cout << "比赛开始！" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "有请A组 " << A[i] << " 号选手上台" << endl;
		cout << "请A组 " << A[i + 1] << " 号选手做好准备" << endl;
		cin.get();
		cout << "有请评委为A组 " << A[i] << " 号选手评分" << endl;
		player[A[i]].setGrade();
		system("cls");
	}

	cout << "A组各选手成绩" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << A[i] << "号选手" << ":" << player[A[i]].getName() << "成绩为：" << player[A[i]].getGrade();
	}
	system("cls");
	cout << "中场休息10分钟" << "/n" << "请B组选手做好准备" << endl;
	cin.get();
	cout << "中场休息结束" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "有请B组 " << B[i] << " 号选手上台" << endl;
		cout << "请B组 " << B[i + 1] << " 号选手做好准备" << endl;
		cin.get();
		cout << "有请评委为A组 " << B[i] << " 号选手评分" << endl;
		player[B[i]].setGrade();
		system("cls");
	}
	cout << "B组各选手成绩" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << B[i] << "号选手" << ":" << player[B[i]].getName() << "成绩为：" << player[A[i]].getGrade();
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

	cout << "A组晋级选手为" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << A[i] << "号选手 " << player[A[i]].getName() << ":" << player[A[i]].getGrade();
	}
	cout << "B组晋级选手为" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << B[i] << "号选手 " << player[B[i]].getName() << ":" << player[B[i]].getGrade();
	}
	system("cls");
	cout << "按下任意键开始决赛";
	cin.get();
	cout << "比赛开始！" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "有请 " << A[i] << " 号选手上台" << endl;
		cout << "请 " << A[i + 1] << " 号选手做好准备" << endl;
		cin.get();
		cout << "有请评委为" << A[i] << " 号选手评分" << endl;
		player[A[i]].setGrade();
		system("cls");
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "有请 " << B[i] << " 号选手上台" << endl;
		cout << "请 " << B[i + 1] << " 号选手做好准备" << endl;
		cin.get();
		cout << "有请评委为" << B[i] << " 号选手评分" << endl;
		player[B[i]].setGrade();
		system("cls");
	}

	cout << "各选手成绩" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << A[i] << "号选手" << ":" << player[A[i]].getName() << "成绩为：" << player[A[i]].getGrade();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << B[i] << "号选手" << ":" << player[B[i]].getName() << "成绩为：" << player[A[i]].getGrade();
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

	cout << "优胜者为" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << rank[i] << "号选手" << ":" << player[rank[i]].getName() << "成绩为：" << player[A[i]].getGrade();
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