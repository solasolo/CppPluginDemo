#include "stdafx.h"

#include "PluginB.h"

#include<iostream>

REGIST_PLUGIN(PluginB)

PluginB::PluginB()
{
	std::cout << "Hello B" << std::endl;
}

void PluginB::Hello()
{
	std::cout << "I'm B" << std::endl;
}

PluginB::~PluginB()
{
	std::cout << "Bye B" << std::endl;
}

