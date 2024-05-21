#pragma once
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
class Player
{
private:
	string name;
	string number;
	double grade;
	int rank;
public:
	double getGrade()
	{
		return grade;
	}
	string getName()
	{
		return name;
	}
	int getRank()
	{
		return rank;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setRank(int rank)
	{
		this->rank = rank;
	}
	void setPlayer(int number)
	{
		cout << "请输入 "<<number+1<<" 号选手名字：";
		cin >> name;
		this->number = number+1;
	}
	void saveGrade(double grade)
	{
		this->grade = grade;
	}
	void setGrade()
	{
		double Grade[10];
		for (int i = 0; i < 10; i++)
		{
			cin >> Grade[i];
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = i+1; j < 10; j++)
			{
				if (Grade[i] > Grade[j])
				{
					double temp;
					temp = Grade[i];
					Grade[i] = Grade[j];
					Grade[j] = temp;
				}

			}
		}
		grade = 0;
		for (int i = 1; i < 9; i++)
		{
			grade+= Grade[i];
		}
		grade /= 8;
	}
};