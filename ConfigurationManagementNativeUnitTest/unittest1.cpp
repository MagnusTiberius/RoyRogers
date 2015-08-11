#include "stdafx.h"
#include "CppUnitTest.h"

#include "ConfigResource.h"
#include "ConfigItem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConfigurationManagementNativeUnitTest
{		
	class Vehicle
	{
	public:
		Vehicle(string mmake, string mmodel, string mstyle)
		{
			make = mmake;
			model = mmodel;
			style = mstyle;
		}

		string make;
		string model;
		string style;
	};


	class CodeBuild
	{
	public:
		string mVersion;
		CodeBuild(string version)
		{
			mVersion.assign(version);
		}
	};

	class SureIdProduct
	{
	public:
		string mName;
		SureIdProduct(string name)
		{
			mName.assign(name);
		}
	};


	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			ConfigResource<CodeBuild>* r = new ConfigResource<CodeBuild>();
			CodeBuild *v = new CodeBuild("1.0.2");
			ConfigItem<CodeBuild>* ri = new ConfigItem<CodeBuild>(v);
			r->AddItem("Build1", ri);
		}

		TEST_METHOD(TestMethod2)
		{
			ConfigResource<SureIdProduct>* r = new ConfigResource<SureIdProduct>();
			SureIdProduct *v = new SureIdProduct("Sure ID Machine");
			ConfigItem<SureIdProduct>* ri = new ConfigItem<SureIdProduct>(v);
			r->AddItem("Demo Machine", ri);
		}


		TEST_METHOD(TestMethod3)
		{
			ConfigResource<Vehicle>* r = new ConfigResource<Vehicle>();
			Vehicle *v = new Vehicle("Ferrari", "488", "Spider");
			ConfigItem<Vehicle>* ri = new ConfigItem<Vehicle>(v);
			r->AddItem("Car1", ri);
			Vehicle *v2 = new Vehicle("Porsche", "911", "Coupe");
			ConfigItem<Vehicle>* ri2 = new ConfigItem<Vehicle>(v2);
			r->AddItem("Car2", ri2);

			ConfigResource<Vehicle> r2 = *r;

		}

	};


}