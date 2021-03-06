#include <iostream>
#include <Shlwapi.h>
#include <thread>
#include "ClassInstance.h"
#include "Character.h"
#include "CLFile.h"
#include "CLPublic.h"
#include "CLThread.h"
#include "CLExpression.h"
#include "Log.h"
#include "CLResManager.h"
#include "CLPic.h"
#include "Script.h"
#include <mutex>
#include "ByteBuffer.h"
#define _SELF L"s.cpp"
using namespace std;

class CBnsScript : public MyTools::CScript
{
public:
	CBnsScript()
	{
		_fnExceptionPtr = [] { return TRUE; };
		_fnLogPtr = [](CONST std::wstring& wsFileName, int nLine, CONST std::wstring& wsText) 
		{
			std::wcout << wsFileName.c_str() << L":" << nLine << L"," << wsText.c_str();
		};

		_fnIfPtr = [](CONST Script_Code_If& Code_If) 
		{
			if (Code_If.wsCondition == L"3==" && Code_If.VecValue.at(0).GetString() == L"3")
				return TRUE;
			return FALSE;
		};

		_fnWhilePtr = [](CONST Script_Code_If& Code_While)
		{
			static int i = 0;
			if (++i == 10)
				return FALSE;

			if (Code_While.wsCondition == L"4==" && Code_While.VecValue.at(0).GetString() == L"4")
				return TRUE;
			return FALSE;
		};

		std::vector<Script_Code_Custome_Method> Vec = 
		{
			{ L"AAA", std::bind(&CBnsScript::AAA, this) },
			{ L"BBB", std::bind(&CBnsScript::BBB, this) },
			{ L"CCC", std::bind(&CBnsScript::CCC, this) },
		};

		for (auto& itm : Vec)
			AddCustomeFunAddr(itm);
	}
	~CBnsScript() = default;

	BOOL AAA()
	{
		std::wcout << L"AAA" << endl;
		return TRUE;
	}
	BOOL BBB()
	{
		std::wcout << L"BBB" << endl;
		return TRUE;
	}
	BOOL CCC()
	{
		std::wcout << L"CCC" << endl;
		return TRUE;
	}
private:

};


int main()
{
	CLog::GetInstance().SetClientName(L"MyTools", L"D:\\", FALSE, 20 * 1024 * 1024);
	
	return 0;
}
