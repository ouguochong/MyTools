#ifndef _MYTOOLS_CHARACTER_CHARACTER_H__
#define _MYTOOLS_CHARACTER_CHARACTER_H__

#include "ToolsPublic.h"

enum ReadMemoryType
{
	Read_Pointer	=	0x1,
	Read_API		=	0x2
};
typedef const std::wstring cwstring;
typedef const std::string  cstring;
#define Split_Option_RemoveEmptyEntries 0x2L
#define Split_Option_None				0x4L
#define Split_Option_KeepOnly			0x8L
class CCharacter
{
public:
	static ReadMemoryType s_ReadMemoryType;
public:
	static LPSTR	strcpy_my(LPSTR strDest, LPCSTR strSrc,	size_t len = sizeof(CHAR) * 1024);											//ASCII		拷贝字符串
	static LPWSTR	wstrcpy_my(LPWSTR strDest, LPCWSTR strSrc, size_t len = sizeof(WCHAR) * 1024);										//Unicode	拷贝字符串
	static bool		strcmp_my(LPCSTR strDest, LPCSTR strSrc);																			//ASCII		对比字符串
	static bool		wstrcmp_my(LPCWSTR strDest, LPCWSTR strSrc);																		//Unicode	对比字符串
	static bool		strstr_my(LPCSTR strDest, LPCSTR strSrc);																			//ASCII		是否存在字符串
	static bool		wstrstr_my(LPCWSTR strDest,	LPCWSTR strSrc);																		//Unicdoe	是否存在字符串
	static LPSTR	Trim_A(LPSTR str);																									//ASCII		去除所有空格
	static LPWSTR	Trim_W(LPWSTR str);																									//Unicode	去除所有空格
	static std::string&	Trim_A(std::string& str);
	static std::wstring& Trim_W(std::wstring& wstr);
	static LPWSTR	RemoveQuotation(LPWSTR lpszText);																					//Unicode	去除所有的引号"
	static std::wstring& GetRemoveLeft(_In_ cwstring& wsText, _In_ cwstring& wsParm, _Out_ std::wstring& wsRetText);
	static LPWSTR	GetRemoveLeft(LPCWSTR lpszText,LPCWSTR parm,LPWSTR RetParm);															//Unicode	去除字符串的一部分,如GetRemoveLeft(L"fun(123)",L"(",L"fun")最后一个参数是返回
	static LPSTR	GetRemoveLeftA(LPCSTR lpszText,LPCSTR parm,LPSTR RetParm);
	static LPWSTR	GetRemoveRight(LPCWSTR lpszText,LPCWSTR parm,LPWSTR RetParm);															//Unicode	去除字符串的一部分,如GetRemoveRight(L"fun(123)",L"(",L"123)")最后一个参数是返回
	static std::wstring&	GetRemoveRight(_In_ cwstring& wsText, _In_ cwstring& wsParm, _Out_ std::wstring& wsRetText);
	static LPSTR	GetRemoveRightA(LPCSTR lpszText, LPCSTR parm, LPSTR RetParm);
	static DWORD	ReadDWORD(DWORD dwAddr);																							//			读取内存
	static WORD		ReadWORD(DWORD dwAddr);																								//			读取内存
	static BYTE		ReadBYTE(DWORD dwAddr);																								//			读取内存
	static float	ReadFloat(DWORD dwAddr);																							//			读取内存
	static double	ReadDouble(DWORD dwAddr);
	static BOOL		WriteDWORD(DWORD dwAddr, DWORD dwValue);																			//			写入内存
	static BOOL		WriteFloat(DWORD dwAddr, float fValue);																				//			写入内存
	static BOOL		WriteBYTE(DWORD dwAddr, BYTE bValue);																				//			写入内存
	static LPSTR	UnicodeToASCII(LPCWSTR lpszWText,LPSTR lpszText);																	//			Unicode的字符串转换成ASCII
	static std::string   UnicodeToASCII(cwstring& wstr);
	static LPWSTR	ASCIIToUnicode(LPCSTR lpszText,LPWSTR lpszWText);																	//			ASCII的字符串转换成Unicode
	static std::wstring  ASCIIToUnicode(const std::string& str);
	static LPWSTR	UTF8ToUnicode(LPWSTR pszText, LPCSTR pUTF8);																		//			UTF-8的字符串转换成Unicode
	static wstring  UTF8ToUnicode(_In_ cstring& csText);																					//

	static LPSTR	UnicodeToUTF8(LPCWSTR pszText, LPSTR pUTF8);																		//			Unicode的字符串转换成UTF-8
	static string	UnicodeToUTF8(_In_ cwstring& wsText);																				//
	
	static LPSTR	UnicodeToGB2312(LPCWSTR pszText, LPSTR pGB2312);																	//			Unicode的字符串转换成GB2312
	
	static LPWSTR	GB2312ToUnicode(LPCSTR pGB2312, LPWSTR pszText);																	//			GB2312的字符串转换成Unicode
	static int		GetRand(int nMax, int nMin = 0);
	static DWORD	GetRand();
	static DWORD	GetRand_For_DWORD();
	static UINT     GetCount_By_CharacterA(LPCSTR pszText, LPCSTR pszContent);															//ASCII		查找pszContent出现的次数
	static UINT		GetCount_By_CharacterW(LPCWSTR pwszText, LPCWSTR pwszContent);														//Unicode	查找pszContent出现的次数
	static UINT		GetCount_By_CharacterW(_In_ cwstring& wsText, _In_ cwstring& wsContent);

	
	static UINT		Split(_In_ cwstring& wsText, _In_ cwstring& wsFormat, _Out_opt_ std::vector<std::wstring>& vlst, _In_opt_ int emOption);
	static UINT		SplitA(_In_ cstring& sText, _In_ cstring& sFormat, _Out_opt_ std::vector<std::string>& vlst, _In_opt_ int emOption);

	static BOOL		GetSplit_By_List(_In_ std::wstring& wsText, _In_ CONST std::vector<std::wstring>& vSplit, _Out_opt_ std::vector<std::wstring>& vSplitContent, _In_opt_ int emOption);

	static BOOL		GetTime_By_Text(_In_ cwstring& wsText, _Out_opt_ SYSTEMTIME& SysTime);												//			格式: 2015-1-1 2:3:4

	static BOOL		ReadUTF8Text(_In_ DWORD dwAddr, _Out_ wstring& wsText);

	static LPCWSTR  FormatText(_In_ LPCWSTR pwszFormat, ...);

	static std::wstring MakeTextToLower(_In_ cwstring& wsText);

	static std::wstring MakeTextToUpper(_In_ cwstring& wsText);

	template<typename _fnPtr>
	static std::wstring MakeTextTo(_In_ cwstring& wsText, _In_ _fnPtr fnPtr)
	{
		std::wstring tmpText;
		for (auto& itm : wsText)
			tmpText.push_back(static_cast<wchar_t>(fnPtr(itm)));

		return tmpText;
	}

	static VOID GetVecByParm_RemoveQuotes(_In_ cwstring& wsText, _In_ WCHAR wchKeyword, _Out_opt_ std::vector<std::wstring>& VecParm);
};

#define SetConsole_Language_CHINA		setlocale(LC_ALL,"")

#endif//_CHARACTER_H__

