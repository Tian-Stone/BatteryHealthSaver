#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
//    MessageBox(NULL, "欢迎使用智能电池健康管理系统！", "电池健康", MB_ICONINFORMATION | MB_SYSTEMMODAL);
	int l, h;
	fstream fin("config", ios::in);
	fin >> l >> h;
	int ti = 60000;
    while(true)
    {
        LPSYSTEM_POWER_STATUS power = new _SYSTEM_POWER_STATUS();
	    int ret = GetSystemPowerStatus(power);
        int percent = (int)power->BatteryLifePercent;
        int isCharge = power->ACLineStatus;
        if(percent >= h && isCharge == 1)
        {
            MessageBox(NULL, "电量已达到设定值，可停止充电！", "电池健康", MB_ICONINFORMATION | MB_SYSTEMMODAL);
			ti = 60000;
        }
        if(percent <= l && isCharge == 0)
        {
            MessageBox(NULL, "电量低，建议开始充电！", "电池健康", MB_ICONINFORMATION | MB_SYSTEMMODAL);
			ti = 60000;
        }
		if(percent >= h - 5 && isCharge == 1)
		{
			ti = 10000;
		}
		if(percent <= l + 5 && isCharge == 0)
		{
			ti = 10000;
		}
		if(percent >= h - 1 && isCharge == 1)
		{
			ti = 100;
		}
		if(percent <= l + 1 && isCharge == 0)
		{
			ti = 100;
		}
        delete power;
		Sleep(ti);
    }
    return 0;
}
