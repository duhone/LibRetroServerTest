#include <tchar.h>
#include <Platform\PathUtils.h>
#include <LibRetroServer\CoreProcess.h>

using namespace std::chrono_literals;

int _tmain(int /*argc*/, _TCHAR* /*argv[]*/)
{
	auto core1 = CR::LibRetroServer::CreateCoreProcess();
	auto core2 = CR::LibRetroServer::CreateCoreProcess();
	auto core3 = CR::LibRetroServer::CreateCoreProcess();
	auto core4 = CR::LibRetroServer::CreateCoreProcess();

	core1->WaitForClose(10s);
	core2->WaitForClose(10s);
	core3->WaitForClose(10s);
	core4->WaitForClose(10s);

	return 0;
}

