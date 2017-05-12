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
	std::map<std::string, BaseBus*> BusPool;

public:
	~BusManager();

	static BusManager* Instance();
	static void Release();	// 单例对象无法自动释放

	void* Get(const char* name);
	void Regist(const char* name, BaseBus* bus);
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