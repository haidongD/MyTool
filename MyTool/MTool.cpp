#include "MTool.h"
#include <stdio.h>
#include <Objbase.h>
#include <Shlobj.h>
#pragma comment (lib, "Ole32.lib") 
#pragma comment(lib,"Shell32.lib")
#include <time.h>

MTool::MTool()
{

}

MTool::~MTool()
{

}

std::string MTool::GetApplicationNameA()
{
	std::string name = "";
	size_t len = 0;
	size_t converted = 0;
	char szPath[MAX_PATH] = { 0 };

	GetModuleFileNameA(NULL, szPath, MAX_PATH);
	std::string strPath = szPath;
	int npos = strPath.find_last_of("\\");
	if (npos != -1)
	{
		name = strPath.substr(npos + 1, strPath.length() - 1);
	}
	else
	{
		return "";
	}
	return name;
}

app_run_e MTool::RunUnique(std::string exeName /*= ""*/)
{
	HANDLE hMutex = NULL;
	std::string szName = GetApplicationNameA();
	if (0 != exeName.length())
	{
		szName = exeName;
	}
	app_run_e staus = AppRunFirst;
	do
	{
		hMutex = ::CreateMutexA(NULL, FALSE, szName.c_str());
		DWORD dwRet = ::GetLastError();
		switch (dwRet)
		{
		case 0:
		{
				  break;
		}
		case ERROR_ALREADY_EXISTS:
		{
									 //MessageBox(NULL, L"通知：该应用程序已经开启。\n", L"通知", MB_OK);
									 staus = AppRunRepeat;
									 break;
		}
		default:
		{
				   //MessageBox(NULL, L"提示：该应用程序创建互斥对象失败。\n", L"错误", MB_OK);
				   staus = AppRunDeterminErro;
				   break;
		}
		}
	} while (FALSE);
	return staus;
}

std::string MTool::GetApplicationPathA()
{
	size_t len = 0;
	size_t converted = 0;
	char szPath[MAX_PATH] = { 0 };

	GetModuleFileNameA(NULL, szPath, MAX_PATH);
	std::string strPath = szPath;
	int npos = strPath.find_last_of("\\");
	if (npos != -1)
	{
		strPath = strPath.substr(0, npos);
	}
	else
	{
		return "";
	}
	return strPath;
}

bool MTool::GetApplicationPath(wchar_t(&des)[MAX_PATH])
{
	size_t len = 0;
	size_t converted = 0;
	wchar_t szPath[MAX_PATH] = { 0 };

	GetModuleFileName(NULL, szPath, MAX_PATH);
	std::string strPath = UnicodeToANSI(szPath);
	int npos = strPath.find_last_of("\\");
	if (npos != -1)
	{
		strPath = strPath.substr(0, npos);
	}
	else
	{
		return false;
	}
	//wcscat_s(des, ANSIToUnicode(strPath).c_str());
	wcscpy_s(des, ANSIToUnicode(strPath).c_str());
	return true;
}

std::wstring MTool::ANSIToUnicode(const std::string& str)
{
	int len = 0;
	len = str.length();
	int unicodeLen = ::MultiByteToWideChar(CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0);
	wchar_t * pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP,
		0,
		str.c_str(),
		-1,
		(LPWSTR)pUnicode,
		unicodeLen);
	std::wstring rt;
	rt = (wchar_t*)pUnicode;
	delete pUnicode;
	return rt;
}

std::string MTool::UnicodeToANSI(const std::wstring& str)
{
	char* pElementText;
	int iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte(CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0,
		NULL,
		NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, sizeof(char)* (iTextLen + 1));
	::WideCharToMultiByte(CP_ACP,
		0,
		str.c_str(),
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL);
	std::string strText;
	strText = pElementText;
	delete[] pElementText;
	return strText;
}
std::wstring MTool::UTF8ToUnicode(const std::string& str)
{
	int len = 0;
	len = str.length();
	int unicodeLen = ::MultiByteToWideChar(CP_UTF8,
		0,
		str.c_str(),
		-1,
		NULL,
		0);
	wchar_t * pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8,
		0,
		str.c_str(),
		-1,
		(LPWSTR)pUnicode,
		unicodeLen);
	std::wstring rt;
	rt = (wchar_t*)pUnicode;
	delete pUnicode;
	return rt;
}
std::string MTool::UnicodeToUTF8(const std::wstring& str)
{
	char*     pElementText;
	int    iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte(CP_UTF8,
		0,
		str.c_str(),
		-1,
		NULL,
		0,
		NULL,
		NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, sizeof(char)* (iTextLen + 1));
	::WideCharToMultiByte(CP_UTF8,
		0,
		str.c_str(),
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL);
	std::string strText;
	strText = pElementText;
	delete[] pElementText;
	return strText;
}

std::string MTool::GetSessionId()
{
	std::string sessionID = "";
	char buf[64] = { 0 };
	GUID guid;
	if (S_OK == ::CoCreateGuid(&guid))
	{
		_snprintf_s(buf, sizeof(buf)
			, "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X"
			, guid.Data1
			, guid.Data2
			, guid.Data3
			, guid.Data4[0], guid.Data4[1]
			, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
			, guid.Data4[6], guid.Data4[7]
			);
	}
	sessionID = buf;
	return sessionID;
}

void MTool::Systemtime_Add_Milliseconds(SYSTEMTIME src, SYSTEMTIME &dst, unsigned long Milliseconds)
{
	FILETIME ft;
	SystemTimeToFileTime(&src, &ft);
	*(__int64 *)(&ft) = *(__int64 *)(&ft) + ((__int64)Milliseconds) * 10000i64;
	FileTimeToSystemTime(&ft, &dst);
}

std::wstring MTool::GetAppdataPathW()
{
	TCHAR szBuffer[MAX_PATH];
	SHGetSpecialFolderPath(NULL, szBuffer, CSIDL_APPDATA, FALSE);
	return std::wstring(szBuffer);
}

std::string MTool::GetAppdataPathA()
{
	return UnicodeToANSIS(GetAppdataPathW());
}

std::string MTool::UnicodeToANSIS(const std::wstring& str)
{
	char* pElementText;
	int iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte(CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0,
		NULL,
		NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, sizeof(char)* (iTextLen + 1));
	::WideCharToMultiByte(CP_ACP,
		0,
		str.c_str(),
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL);
	std::string strText;
	strText = pElementText;
	delete[] pElementText;
	return strText;
}

void MTool::Systemtime_Del_Milliseconds(SYSTEMTIME src, SYSTEMTIME &dst, unsigned long Milliseconds)
{
	FILETIME ft;
	SystemTimeToFileTime(&src, &ft);
	*(__int64 *)(&ft) = *(__int64 *)(&ft) - ((__int64)Milliseconds) * 10000i64;
	FileTimeToSystemTime(&ft, &dst);
}

void MTool::BuildFormatStr(std::string &str, const char* format, ...)
{
	str = "";
	if (NULL == format)
	{
		return;
	}

	char buf[524288] = { 0 };
	va_list args;
	va_start(args, format);
	_vsnprintf_s(buf, sizeof(buf)-1, format, args);
	va_end(args);

	int length = strlen(buf);
	if (length == 0)
	{
		return;
	}
	str = buf;
}

std::string MTool::getTimeStr(SYSTEMTIME *time)
{
	std::string rlt;
	BuildFormatStr(rlt, "%04u-%02u-%02u %02u:%02u:%02u",
		time->wYear,
		time->wMonth,
		time->wDay,
		time->wHour,
		time->wMinute,
		time->wSecond);
	return rlt;
}

time_t MTool::convert_string_to_time_t(const std::string & time_string)
{
	struct tm tm1;
	time_t time1;
	int i = sscanf_s(time_string.c_str(), "%d-%d-%d %d:%d:%d",
		&(tm1.tm_year),
		&(tm1.tm_mon),
		&(tm1.tm_mday),
		&(tm1.tm_hour),
		&(tm1.tm_min),
		&(tm1.tm_sec),
		&(tm1.tm_wday),
		&(tm1.tm_yday));

	tm1.tm_year -= 1900;
	tm1.tm_mon--;
	tm1.tm_isdst = -1;
	time1 = mktime(&tm1);

	return time1;
}

double MTool::TimeString_Del_TimeString(std::string start, std::string end)
{
	time_t s, e;
	s = convert_string_to_time_t(start);
	e = convert_string_to_time_t(end);
	return difftime(e, s);
}
