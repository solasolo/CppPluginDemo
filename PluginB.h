#pragma once

#include "BasePlugin.h"
#include "Bus.h"

class PluginB : public BasePlugin
{
public:
	PluginB();

	virtual ~PluginB();
	virtual void Hello();
};

