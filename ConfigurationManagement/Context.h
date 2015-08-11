#pragma once
#include "BaseID.h"
#include <map>
#include "ConfigResource.h"

template <class T>
class Context : public BaseID
{
public:
	Context()
	{

	}

	~Context()
	{

	}

private:
	std::map<string, ConfigResource<T>*> mapResourceList;

};

