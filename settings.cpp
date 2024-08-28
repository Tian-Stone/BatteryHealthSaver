#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleTitle("设置中心");
	cout << "提示：请不要输入百分号！\n";
	cout << "请设置低电提醒电量（推荐：20, 0 ~ 50）";
	int l;
	cin >> l;
	if(l < 0 || l > 50)
	{
		while(l < 0 || l > 50)
		{
			cout << "输入有误！\n";
			cout << "请设置低电提醒电量（推荐：20, 0 ~ 50）";
			cin >> l;
		}
	}
	cout << "请设置停止充电提醒电量（推荐：70, 50 ~ 100）";
	int h;
	cin >> h;
	if(h < 50 || h > 100)
	{
		while(h < 50 || h > 100)
		{
			cout << "输入有误！\n";
			cout << "请设置停止充电提醒电量（推荐：70, 60 ~ 100）";
			cin >> h;
		}
	}
	fstream fout("config", ios::out);
	fout << l << "\n" << h;
	system("cls");
	cout << "设置成功！\n10 秒后将退出...";
	Sleep(10000);
	return 0;
}
