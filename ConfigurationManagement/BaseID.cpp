#include "BaseID.h"

BaseID::BaseID()
{
	Init();
}


BaseID::~BaseID()
{
}

void BaseID::Init()
{
	GuidToString(guid);
}

void BaseID::GuidToString(char* szGuid)
{
	GUID *guid = 0x00;
	guid = new GUID;
	CoCreateGuid(guid);
	sprintf_s(szGuid, 40, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", guid->Data1, guid->Data2, guid->Data3, guid->Data4[0], guid->Data4[1], guid->Data4[2], guid->Data4[3], guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]);
}