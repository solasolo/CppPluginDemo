#pragma once

#include <map>

#include "Singleton.h"
#include <stdio.h>
#include <string>

// 这个类的存在，只是为了可以在BusManager里调用析构函数
class _declspec(dllexport) BaseBus
{
public:
	BaseBus() {};
	virtual ~BaseBus() {};
};

template<class T>
class _declspec(dllexport) Bus : public BaseBus
{
	typedef std::map<std::string, T*> TypeObjectPool; 

private:
	typename TypeObjectPool Pool;

public:
	Bus();
	virtual ~Bus();

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
	((Bus<T>*)(BusManager::Instance()->Get(#T)))

// 放在插件cpp文件里，防止重复定义
#define REGIST_PLUGIN(class_name)		\
   PluginRegister<class_name> _##class_name##register_(#class_name); 

#define REGIST_BUS(class_name)		\
   BusRegister<class_name> _bus##_##class_name##register_(#class_name); 
