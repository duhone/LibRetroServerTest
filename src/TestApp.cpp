#include "TestApp.h"
#include <Platform\Window.h>
#include <LibRetroServer\CoreProcess.h>
#include <thread>
#include <vector>
#include <core\algorithm.h>

using namespace std::chrono_literals;

class TestApp : public ITestApp
{
public:
	TestApp();
	virtual ~TestApp();
	void Run() override;
private:
	std::unique_ptr<CR::Platform::IWindow> m_window;
	std::vector<std::unique_ptr<CR::LibRetroServer::ICoreProcess>> m_cores;
};

TestApp::TestApp()
{
	m_window = CR::Platform::CRCreateWindow("Lib Retro Server", 500, 500);
	
	m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
	m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
	m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
	m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
}

TestApp::~TestApp()
{
	CR::Core::ForEach(m_cores, [](auto& core) {	core->WaitForClose(10s); });
}

void TestApp::Run()
{
	std::this_thread::sleep_for(2s);
}

std::unique_ptr<ITestApp> CreateTestApp()
{
	return std::make_unique<TestApp>();
}