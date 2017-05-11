#pragma once

#include <map>

#include "Singleton.h"
#include <stdio.h>

template<class T>
class Bus
{
	typedef std::map<const char*, T*> TypeObjectPool; 

private:
	typename TypeObjectPool Pool;

public:
	Bus();
	~Bus();

	T& Get(const char* name);
	void Register(const char* name, T* obj);
};


template<class T>
Bus<T>::Bus()
{
}

template<class T>
Bus<T>::~Bus()
{
	for (TypeObjectPool::iterator iter = this->Pool.begin(); iter != this->Pool.end(); iter++)
	{
		delete iter->second;
	}

	// For Debug
	getchar();
}

template<class T>
T& Bus<T>::Get(const char* name)
{
	if(this->Pool.find(name) == this->Pool.end()) {
		throw std::exception("not registed");
	}

	return *this->Pool[name];
}

template<class T>
void Bus<T>::Register(const char* name, T* obj)
{
	this->Pool.insert(std::make_pair(name, obj));
}

// 写成类是为了用定义的方式自动执行
template<class T>
class PluginRegister		
{									
    public:							
		PluginRegister(char* name)
        {							
			T::Regist<T>(name);
        }							
};		

#define BusInstance(T)	\
	Singleton< Bus<T> >::instance()

// 放在插件cpp文件里，防止重复定义
#define REGIST_PLUGIN(class_name)		\
   PluginRegister<class_name> _##class_name##register_(#class_name); 

