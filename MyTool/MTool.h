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
	* ��ȡ��ǰ���г�����ļ�����
	*/
	static std::string GetApplicationNameA();

	/**
	* ʹ��ǰ��������Ψһ
	*/
	static app_run_e RunUnique(std::string exeName = "");

	/**
	 * ��ȡ��ǰִ�г����·��
	 */
	static std::string GetApplicationPathA();

	/************************************************************************/
	/* ��ȡ��ǰ�����appdataĿ¼
	/************************************************************************/
	static std::wstring GetAppdataPathW();

	/************************************************************************/
	/* ��ȡ��ǰ�����appdataĿ¼
	/************************************************************************/
	static std::string GetAppdataPathA();

	/************************************************************************/
	/* ��ȡ��ǰӦ�õľ���·��
	/************************************************************************/
	static bool GetApplicationPath(wchar_t(&des)[MAX_PATH]);

	/************************************************************************/
	/* ��ǰ����Ϊunicode,charתwchar_t
	/************************************************************************/
	static std::wstring ANSIToUnicode(const std::string& str);

	/************************************************************************/
	/* ��ǰ����Ϊunicode,wchar_tתchar
	/************************************************************************/
	static std::string UnicodeToANSI(const std::wstring& str);

	/************************************************************************/
	/* ��ǰ����Ϊunicode,wchar_tתchar
	/************************************************************************/
	static std::string UnicodeToANSIS(const std::wstring& str);

	/************************************************************************/
	/* ��ǰ����ΪUTF8,charתwchar_t
	/************************************************************************/
	static std::wstring UTF8ToUnicode(const std::string& str);

	/************************************************************************/
	/* ��ǰ����ΪUTF8,wchar_tתchar
	/************************************************************************/
	static std::string UnicodeToUTF8(const std::wstring& str);

	/************************************************************************/
	/* ����SessionID
	/************************************************************************/
	static std::string GetSessionId();

	/************************************************************************/
	/* ��ʱ�����ӷ�
	/************************************************************************/
	static void Systemtime_Add_Milliseconds(SYSTEMTIME src, SYSTEMTIME &dst, unsigned long Milliseconds);
	/************************************************************************/
	/* ��ʱ��������
	/************************************************************************/
	static void Systemtime_Del_Milliseconds(SYSTEMTIME src, SYSTEMTIME &dst, unsigned long Milliseconds);
	/************************************************************************/
	/* ��װ�ַ���
	/************************************************************************/
	static void BuildFormatStr(std::string &str, const char* format, ...);
	/*ָ��ʱ���ʽ��*/
	static std::string getTimeStr(SYSTEMTIME *time);
	/*ʱ��������*/
	static double TimeString_Del_TimeString(std::string start,std::string end);

private:
	/*�ַ���תʱ��*/
	static time_t convert_string_to_time_t(const std::string & time_string);
};
#endif