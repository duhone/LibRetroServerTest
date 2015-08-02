#pragma once
#include <memory>

struct ITestApp
{
	virtual ~ITestApp() = default;
	virtual void Run() = 0;
};

std::unique_ptr<ITestApp> CreateTestApp();