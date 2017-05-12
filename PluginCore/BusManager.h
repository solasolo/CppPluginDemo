#pragma once

#include "Singleton.h"
#include "Bus.h"

#include <map>
#include <string>

 class _declspec(dllexport) BusManager
{
private:
	BusManager();
	std::map<std::string, BaseBus*> BusPool;

public:
	~BusManager();

	static BusManager& Instance();

	void* Get(const char* name);
	void Regist(const char* name, BaseBus* bus);
 };

 template<class T>
 class BusRegister
 {
 public:
	 BusRegister(char* name)
	 {
		 BusManager::Instance().Regist(name, new Bus<T>);
	 }
 };