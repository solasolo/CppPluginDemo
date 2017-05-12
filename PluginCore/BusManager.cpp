#include "BusManager.h"

#include <typeinfo.h>

BusManager* BusManager::_Instance = NULL;

BusManager* BusManager::Instance()
{
	if (!_Instance)
	{
		_Instance = new BusManager();
	}

	return _Instance;
}

BusManager::BusManager()
{
}


BusManager::~BusManager()
{
}

void* BusManager::Get(const char* name)
{
	if (this->BusPool.find(name) == this->BusPool.end())
	{
		throw std::exception("not resisted bus");
	}
	else
	{
		return this->BusPool[name];
	}
}

void BusManager::Regist(const char* name, void* bus)
{
	this->BusPool[name] = bus;
}