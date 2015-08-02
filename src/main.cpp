#include <Windows.h>
#include "TestApp.h"

int CALLBACK WinMain(HINSTANCE /*a_instance*/, HINSTANCE /*a_prevInstance*/, LPSTR /*a_cmdLine*/, int /*a_cmdShow*/)
{
	auto testApp = CreateTestApp();
	testApp->Run();

	return 0;
}

