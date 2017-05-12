#pragma once

#include "Singleton.h"
#include "Bus.h"

#include <map>
#include <string>

 class _declspec(dllexport) BusManager
{
private:
	static BusManager* _Instance;

	BusManager();
	std::map<std::string, void*> BusPool;

public:
	~BusManager();

	static BusManager* Instance();

	void* Get(const char* name);
	void Regist(const char* name, void* bus);
 };

 template<class T>
 class BusRegister
 {
 public:
	 BusRegister(char* name)
	 {
		 BusManager::Instance()->Regist(name, new Bus<T>);
	 }
 };