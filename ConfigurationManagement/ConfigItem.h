#pragma once
#include "BaseID.h"
#include <vector>
#include <map>

template <class T>
class ConfigItem : public BaseID
{
public:
	ConfigItem(T* item)
	{
		mItem = item;
	}

	~ConfigItem()
	{

	}

private:
	std::map<string, T*> itemList;

	T* mItem;
};

