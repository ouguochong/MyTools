#ifndef __CLGRAMMAR_H__
#define __CLGRAMMAR_H__ TRUE

#include "ToolsPublic.h"

typedef struct _GrammarContext
{
	WCHAR	szCmd[64];				//简化命令,如(QueryProcess) or (i) or (360) or (280x360) // 去掉-
	_GrammarContext()
	{
		ZeroMemory(szCmd, sizeof(szCmd));
	}
}GrammarContext, *PGrammarContext;

//中间码维护表
typedef struct _GrammarTran
{
	WCHAR	wszCmd[64];
	LPVOID	pFunAddr;
}GrammarTran;

typedef DWORD(WINAPI * GrammarFun)(std::vector<GrammarContext>& vlst, LPWSTR pwszRetMsg);


class CLGrammar
{
public:
	CLGrammar();
	~CLGrammar();

	static BOOL						AnalysisGrammar(_In_ LPCWSTR pwszText, _Out_ LPWSTR pwszErrMsg);
	static std::vector<GrammarContext>&	GetGrammarList();
	static std::vector<GrammarTran>&		GetTranList();
	static VOID						AddTranList(_In_ LPCWSTR pwszCmd, _In_ GrammarFun lpfun);
	static LPVOID					GetFunAddr(_In_ LPCWSTR pwszCmd);
	static DWORD					Query_DWORDParm_By_GrammarList(_In_ UINT uIndex, _In_ std::vector<GrammarContext>& vlst);
	static float					Query_FLOATParm_By_GrammarList(_In_ UINT uIndex, _In_ std::vector<GrammarContext>& vlst);
	static LPCWSTR					Query_LPWSTRParm_By_GrammarList(_In_ UINT uIndex, _In_ std::vector<GrammarContext>& vlst);
	static BOOL						Check_ParmCount_By_GrammarList(_In_ UINT uCount, _In_ std::vector<GrammarContext>& vlst);
};


#endif