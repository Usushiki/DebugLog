#include"Log.hpp"

int main()
{
	int   value  = 22;
	float fvalue = 2.5f;
	

//	DebugLog(value + fvalue);
	DebugLog("Test", value, fvalue);
	DebugLogFileLine("sss");

	return 0;
}