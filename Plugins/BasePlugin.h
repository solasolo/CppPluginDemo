#pragma once

#include "Bus.h"
#include "BusManager.h" 

class BasePlugin
{
public:
	virtual ~BasePlugin() {};
	virtual void Hello() = 0;

	template<class T> 
	static void Regist(char* name)
	{
		BusInstance(BasePlugin)->Register(name, new T());
	}
};