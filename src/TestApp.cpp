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
	void OnDestroy();
	volatile bool m_finished{false};

	std::unique_ptr<CR::Platform::IWindow> m_window;
	std::vector<std::unique_ptr<CR::LibRetroServer::ICoreProcess>> m_cores;
};

TestApp::TestApp()
{
	m_window = CR::Platform::CRCreateWindow("Lib Retro Server", 500, 500, [this]() { this->OnDestroy(); });
	
	m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
	//m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
	//m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());
	//m_cores.push_back(CR::LibRetroServer::CreateCoreProcess());

	m_cores[0]->Initialize("mame_libretro.dll", "galaga.zip");
	//m_cores[1]->Initialize("mame_libretro.dll", "joust.zip");
	//m_cores[2]->Initialize("mame_libretro.dll", "pacplus.zip");
	//m_cores[3]->Initialize("mame_libretro.dll", "goldnaxe.zip");
}

TestApp::~TestApp()
{
	CR::Core::ForEach(m_cores, [](auto& core) {	core->WaitForClose(10s); });
}

void TestApp::Run()
{
	while(!m_finished)
	{
		std::this_thread::sleep_for(1s);
	}
}

void TestApp::OnDestroy()
{
	m_finished = true;
	CR::Core::ForEach(m_cores, [](auto& core) {	core->Shutdown(); });
}

std::unique_ptr<ITestApp> CreateTestApp()
{
	return std::make_unique<TestApp>();
}