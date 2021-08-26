#pragma once

#include "Display.h"
#include "System.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private:

	Display* disp	= nullptr;
	System* system	= nullptr;
};

