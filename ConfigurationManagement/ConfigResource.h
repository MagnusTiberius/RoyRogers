#pragma once
#include "BaseID.h"
#include "ConfigItem.h"
#include "Specification.h"
#include "IJsonSerializable.h"
#include <map>
#include "json.h"

template <class T>
class ConfigResource : public BaseID, public IJsonSerializable
{
public:
	ConfigResource()
	{
		mIsSelected = false;
		mIsStandard = false;
	}

	~ConfigResource()
	{

	}

	ConfigResource(const ConfigResource& obj)
	{

		mIsSelected = obj.mIsSelected;
		mIsStandard = obj.mIsStandard;

		std::map<string, Specification*>::iterator itr;
		//for (itr = obj.mapSpecificationList.begin(); itr != obj.mapSpecificationList.end(); itr++)
		//{
		//	//var name = itr->first;
		//}


		//mapSpecificationList = new std::map<string, Specification*>();
		//foreach(var itm in obj.mapSpecificationList)
		//{
		//	mapSpecificationList.insert(itm);
		//}

		//mapResourceList = new std::map<string, ConfigResource*>();
		//mapResourceItemList = new std::map<string, ConfigItem<T>*>();
		//mapReplacementList = new std::map<string, ConfigResource*>();
		//mapVersionList = new std::map<string, ConfigResource*>();
	}

	ConfigResource& operator=(const ConfigResource& obj)
	{
		mIsSelected = obj.IsSelected;
		mIsStandard = obj.IsStandard;

		//std::map<string, Specification*>::iterator itr;
		//for (itr = obj.mapSpecificationList.begin(); itr != obj.mapSpecificationList.end(); itr++)
		//{
		//	var name = itr->first;
		//}

		//mapSpecificationList = new std::map<string, Specification*>();
		//foreach(var itm in obj.mapSpecificationList)
		//{
		//	mapSpecificationList.insert(itm);
		//}

		//mapResourceList = new std::map<string, ConfigResource*>();
		//mapResourceItemList = new std::map<string, ConfigItem<T>*>();
		//mapReplacementList = new std::map<string, ConfigResource*>();
		//mapVersionList = new std::map<string, ConfigResource*>();
	}

private:
	std::map<string, Specification*> mapSpecificationList;
	std::map<string, ConfigResource*> mapResourceList;
	std::map<string, ConfigItem<T>*> mapResourceItemList;
	std::map<string, ConfigResource*> mapReplacementList;
	std::map<string, ConfigResource*> mapRevisionList;

	bool mIsSelected;
	bool mIsStandard;

public:

	void Serialize(Json::Value& root)
	{
		root["IsSelected"] = mIsSelected;
		root["IsStandard"] = mIsStandard;
	}

	void Deserialize(Json::Value& root)
	{
		mIsSelected = root.get("IsSelected", 0).asBool();
		mIsStandard = root.get("IsStandard", 0).asBool();
	}

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

