#include "stdafx.h"
#include "CppUnitTest.h"

#include "ConfigResource.h"
#include "ConfigItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConfigurationManagementNativeUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ConfigResource<string>* r = new ConfigResource<string>();
			ConfigItem<string>* ri = new ConfigItem<string>();
		}

	};
}