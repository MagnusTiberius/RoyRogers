#pragma once
#include <string>
#include <tchar.h>
#include "Objbase.h"


using namespace std;

class BaseID
{
public:
	BaseID();
	~BaseID();

private:
	char guid[40];
	string code;
	string description;
	string name;

private:
	void Init();
	void GuidToString(char* szGuid);

public:

	void SetCode(string v)
	{
		code.assign(v);
	}

	string GetCode()
	{
		return code;
	}

	void SetDescription(string v)
	{
		description.assign(v);
	}

	string GetDescription()
	{
		return description;
	}

	void SetName(string v)
	{
		name.assign(v);
	}

	string GetName()
	{
		return name;
	}


};

