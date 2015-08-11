#pragma once
#include "BaseID.h"
#include "ConfigItem.h"
#include "Specification.h"
#include <map>

template <class T>
class ConfigResource : public BaseID
{
public:
	ConfigResource()
	{

	}

	~ConfigResource()
	{

	}

private:
	std::map<string, Specification*> mapSpecificationList;
	std::map<string, ConfigResource*> mapResourceList;
	std::map<string, ConfigItem<T>*> mapResourceItemList;
	std::map<string, ConfigResource*> mapReplacementList;
	std::map<string, ConfigResource*> mapVersionList;

	bool mIsSelected;
	bool mIsStandard;

public:

	void SetSelected(bool v)
	{
		mIsSelected = v;
	}

	bool IsSelected()
	{
		return mIsSelected;
	}

	void SetIsStandard(bool v)
	{
		mIsStandard = v;
	}

	bool IsStandard()
	{
		return mIsStandard;
	}


	void AddResource(string name, ConfigResource* resource)
	{
		mapResourceList.insert(make_pair(name, resource));
	}

	void AddItem(string name, ConfigItem<T>* item)
	{
		mapResourceItemList.insert(make_pair(name, item));
	}

	void AddSpecification(string name, Specification* item)
	{
		mapSpecificationList.insert(make_pair(name, item));
	}


};

