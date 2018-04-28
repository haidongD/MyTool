#ifndef TOOL_H
#define TOOL_H

#include <windows.h>
#include <string>

typedef enum _app_run_e
{
	AppRunFirst,
	AppRunRepeat,
	AppRunDeterminErro
}app_run_e;

class MTool
{
public:
	MTool();
	~MTool();

	/**
	* 获取当前运行程序的文件名称
	*/
	static std::string GetApplicationNameA();

	/**
	* 使当前程序运行唯一
	*/
	static app_run_e RunUniqueA(std::string exeName = "");

	/**
	 * 获取当前执行程序的路径
	 */
	static std::string GetApplicationPathA();

	/************************************************************************/
	/* 获取当前程序的appdata目录
	/************************************************************************/
	static std::wstring GetAppdataPathW();

	/************************************************************************/
	/* 获取当前程序的appdata目录
	/************************************************************************/
	static std::string GetAppdataPathA();

	/************************************************************************/
	/* 获取当前应用的绝对路径
	/************************************************************************/
	static bool GetApplicationPathW(wchar_t(&des)[MAX_PATH]);

	/************************************************************************/
	/* 当前编码为unicode,char转wchar_t
	/************************************************************************/
	static std::wstring ANSIToUnicode(const std::string& str);

	/************************************************************************/
	/* 当前编码为unicode,wchar_t转char
	/************************************************************************/
	static std::string UnicodeToANSI(const std::wstring& str);

	/************************************************************************/
	/* 当前编码为unicode,wchar_t转char
	/************************************************************************/
	static std::string UnicodeToANSIS(const std::wstring& str);

	/************************************************************************/
	/* 当前编码为UTF8,char转wchar_t
	/************************************************************************/
	static std::wstring UTF8ToUnicode(const std::string& str);

	/************************************************************************/
	/* 当前编码为UTF8,wchar_t转char
	/************************************************************************/
	static std::string UnicodeToUTF8(const std::wstring& str);

	/************************************************************************/
	/* 生成SessionID
	/************************************************************************/
	static std::string GetSessionId();

	/************************************************************************/
	/* 对时间做加法
	/************************************************************************/
	static void SystemtimeAddMilliseconds(SYSTEMTIME src, SYSTEMTIME &dst, unsigned long Milliseconds);
	/************************************************************************/
	/* 对时间做减法
	/************************************************************************/
	static void SystemtimeDelMilliseconds(SYSTEMTIME src, SYSTEMTIME &dst, unsigned long Milliseconds);
	/************************************************************************/
	/* 组装字符串
	/************************************************************************/
	static void BuildFormatStr(std::string &str, const char* format, ...);

	/*指定时间格式化yyyy-MM-dd HH:mm:ss*/
	static std::string GetTimeStr(SYSTEMTIME *time);
	/*时间做减法*/
	static double TimeStringDelTimeString(std::string start,std::string end);

private:
	/*字符串转时间*/
	static time_t convert_string_to_time_t(const std::string & time_string);
};
#endif