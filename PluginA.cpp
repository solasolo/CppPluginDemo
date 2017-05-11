#include "stdafx.h"

#include "PluginA.h"

#include<iostream>

REGIST_PLUGIN(PluginA)

PluginA::PluginA()
{
	std::cout << "Hello A" << std::endl;
}

void PluginA::Hello()
{
	std::cout << "I'm A" << std::endl;
}

PluginA::~PluginA()
{
	std::cout << "Bye A" << std::endl;
}

