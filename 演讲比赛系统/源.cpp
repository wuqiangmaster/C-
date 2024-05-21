#include<iostream>
#include<fstream>
#include"Player.h"
#include"Function.h"
#include"Menu.h"

int main()
{
	Player player[12];
	for (int i = 0; i < 12; i++)
	{
		player[i].setPlayer(i);
	}
	system("cls");
	int A[6], B[6];
	randomized(A, B);
	int select{1};
	while (select)
	{
		mainMenu();
		cin >> select;
		if (select == 1)
		{
			startGame(A, B, player);
			cout << "按下任意键返回主菜单";
			cin.get();
		}
		if (select == 2)
		{
			Player winplayer[100];
			read(winplayer);
			for (int i = 0; i < 100; i+=3)
			{
				cout << "第"<<(i/3)+1<<"届演讲比赛优胜者" << endl;
				cout << winplayer[i].getRank() << '\t' << winplayer[i].getName() 
					<< '\t' << winplayer[i].getGrade() << endl;
				cout << winplayer[i+1].getRank() << '\t' << winplayer[i+1].getName()
					<< '\t' << winplayer[i+1].getGrade() << endl;
				cout << winplayer[i+2].getRank() << '\t' << winplayer[i+2].getName()
					<< '\t' << winplayer[i+2].getGrade() << endl;
			}
			save(winplayer);
			cout << "按下任意键返回主菜单";
			cin.get();
		}
		if (select == 3)
		{
			Player emptyPlayer[100];
			read(emptyPlayer);
		}
		system("cls");
	}
}