#pragma once
#include "BaseID.h"
#include <vector>
#include <map>

template <class T>
class ConfigItem : public BaseID
{
public:
	ConfigItem()
	{

	}

	~ConfigItem()
	{

	}

private:
	std::map<string, T*> itemList;

};

