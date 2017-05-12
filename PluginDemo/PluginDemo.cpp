// CppPluginDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>

#include "Bus.h"
#include "BasePlugin.h"
#include "BusManager.h"

// 这里是很白痴的部分:
// 可以不用包含可能用到的所有插件头文件
// 但是依然需要在项目里包含所有插件的cpp


int main()
{
	// 加载 Plugin Dll
	HMODULE hm = LoadLibrary(L"Plugins.dll");

	std::cout << "Program Start" << std::endl;

	BusInstance(BasePlugin)->Get("PluginA").Hello();
	BusInstance(BasePlugin)->Get("PluginB").Hello();

	getchar();

	std::cout << "Program End" << std::endl;

	return 0;
}

