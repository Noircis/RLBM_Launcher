#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "BakkesMod RL launcher", wxPoint(150, 150), wxSize(800, 250))
{

	// init 
	this->system = new System(this, disp = new Display("Path to the BakkesMod .exe", "Path to the RocketLeague .exe", this));
	
	// Binding
	this->system->cBind(this->disp->get_btn_bakkes_path());
	this->system->cBind(this->disp->get_btn_RL_path());
	this->system->cBind(this->disp->get_btn_Launch());
}

cMain::~cMain()
{

}