#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    MessageBox(NULL, "欢迎使用智能电池健康管理系统！", "电池健康", MB_ICONINFORMATION | MB_SYSTEMMODAL);
    int ti = 60000;
    while(true)
    {
        LPSYSTEM_POWER_STATUS power = new _SYSTEM_POWER_STATUS();
	int ret = GetSystemPowerStatus(power);
        int percent = (int)power->BatteryLifePercent;
        int isCharge = power->ACLineStatus;
        if(percent >= 70 && isCharge == 1)
        {
            MessageBox(NULL, "电量已达到 70%，可停止充电！", "电池健康", MB_ICONINFORMATION | MB_SYSTEMMODAL);
	    ti = 60000;
        }
        if(percent <= 20 && isCharge == 0)
        {
            MessageBox(NULL, "电量低于 20%，建议开始充电！", "电池健康", MB_ICONINFORMATION | MB_SYSTEMMODAL);
	    ti = 60000;
        }
	if(percent >= 65 && isCharge == 1)
	{
		ti = 10000;
	}
	if(percent <= 25 && isCharge == 0)
	{
		ti = 10000;
	}
        delete power;
	Sleep(ti);
    }
    return 0;
}
