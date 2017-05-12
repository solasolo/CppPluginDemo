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

void BusManager::Release()
{
	if (_Instance)
	{
		delete _Instance;
	}
}

BusManager::BusManager()
{
}


BusManager::~BusManager()
{
	for (std::map<std::string, BaseBus*>::iterator iter = this->BusPool.begin(); iter != this->BusPool.end(); iter++)
	{
		delete iter->second;
	}
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

void BusManager::Regist(const char* name, BaseBus* bus)
{
	this->BusPool[name] = bus;
}