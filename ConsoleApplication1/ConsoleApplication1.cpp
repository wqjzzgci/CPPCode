// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<string>
#include<locale>
#include<iostream>
#include <cstdlib>
#include<vector>
#include<sstream>
using namespace std;

#define TString wstring
/*
strlen()	返回ANSI字符串长度
wcslen()	返回宽字符串长度（一般为UNICODE）
lstrlen()	返回指定字符串的字节长度（ANSI版）或字符长度（双字节标准版）
*/
void getString();
void getDiscriptionString();
TString getTS(int k);
int main()
{
	getDiscriptionString();
	//getString();
	/*wchar_t* wct = L"中华人民共和国";
	wstring wstr = L"中国人民共和国";
	char* ch = "中华人民共和国";
	string str = "中华人民共和国";
	cout<<wcslen(wct) << endl;
	cout << wstr.length() << endl;
	cout << strlen(ch) << endl;
	cout << str.length() << endl;
	cout << str << endl;
	cout << ch;*/
    return 0;
}
void getString()
{
	//int text_size = 0;

	//const wchar_t* text_str = pAuMark->GetStringW("PARAM_S", text_size);
	//TString strText = TString(text_str, text_size);

	//const wchar_t* memo_str = GetMemoStringW(pAuMark, text_size);

	//TString memoText = TString(memo_str, text_size);

	//TString displayText;
	int text_size = 0;
	const wchar_t* text_str = L"9|10|0|14|15";
	TString strText = TString(text_str, sizeof(text_str));
	wchar_t* str_token = ::_wcsdup(strText.c_str());
	wchar_t *next_token = NULL;
	wchar_t* token = wcstok((wchar_t*)str_token, _T("|"));
	wchar_t* sep = L"|";
	vector<TString>vv;
	while (NULL!=token)
	{
		TString str(token);
		token = wcstok(NULL, sep);
		vv.push_back(str);
	}
	TString displaytext;

	for (int i = 0; i < vv.size(); i++)
	{
		TString t = vv[i];
		if (t == L"0")
		{
			continue;
		}
		else
		{
			int kk = 10;
			std::wostringstream ws;
			ws << (i+1);
			const std::wstring s(ws.str());
			displaytext +=s;
			displaytext+=L"|" + vv[i] + L",";
		}

	
	}
	int kk = 0;
}
void getDiscriptionString()
{
	//int text_size = 0;

	//const wchar_t* text_str = pAuMark->GetStringW("PARAM_S", text_size);
	//TString strText = TString(text_str, text_size);

	//const wchar_t* memo_str = GetMemoStringW(pAuMark, text_size);

	//TString memoText = TString(memo_str, text_size);

	//TString displayText;
	int text_size = 0;
	const wchar_t* text_str = L"9|10|0|14|15";
	TString strText = TString(text_str, sizeof(text_str));
	wchar_t* str_token = ::_wcsdup(strText.c_str());
	//wchar_t *next_token = NULL;
	wchar_t* token = wcstok((wchar_t*)str_token, _T("|"));
	wchar_t* sep = L"|";
	vector<TString>vv;
	int kk = 0;
	TString displaytext=L"高:";
	while (NULL != token)
	{
		TString str(token);
		token = wcstok(NULL, sep);
		kk++;
		if (str != L"0")
		{
			displaytext += getTS(kk) + L"|" + str+L",";
		}
		//vv.push_back(str);
	}
	int zz = 0;

	/*for (int i = 0; i < vv.size(); i++)
	{
		TString t = vv[i];
		if (t == L"0")
		{
			continue;
		}
		else
		{
			std::wostringstream ws;
			ws << (i + 1);
			const std::wstring s(ws.str());
			displaytext += s;
			displaytext += L"|" + vv[i] + L",";
		}


	}
	int kk = 0;*/
}
//int转wstring
TString getTS(int k)
{
	int kk = 10;
	std::wostringstream ws;
	ws << (k + 1);
	const std::wstring s(ws.str());
	return s;
}

