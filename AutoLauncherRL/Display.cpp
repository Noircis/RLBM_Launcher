#include "Display.h"

/**
*	Function : Display()
*	@param[in] bakkesPath - path to the bakkesMod .exe - Is used as placeHolder in the button while no path is selected
*	@param[in] pathToRL - path to the Rocket League .exe - Is used as placeHolder in the button while no path is selected
*	@param target - parent window  
*	@desc : Build all the wxbuttons needed
*/
Display::Display(std::string pathToBakkes, std::string pathToRL, wxFrame* target)
{
	btn_bakkes_path		= new wxButton(target,										// Target
									10001,											// Unique ID
									pathToBakkes,									// Content (txt) of the button
									wxPoint(this->margin, this->margin),			// button position
									wxSize(this->btn_sizeX, this->btn_sizeY));		// button size

	btn_RL_path			= new wxButton(target,
									10002, 
									pathToRL, 
									wxPoint(this->margin, this->margin + 30 + 15), 
									wxSize(this->btn_sizeX, this->btn_sizeY));

	btn_Launch			= new wxButton(target,
									10003, 
									"LAUNCH", 
									wxPoint(this->margin, this->margin + 60 + 30), 
									wxSize(this->btn_sizeX - 600, this->btn_sizeY));
}


Display::~Display()
{

}

// methodes

/**
*	Function : update_button
*	@param[in] eventID - pressed button ID
*	@param[in] pathToBakkes - path to bakkesMod.exe in std::string
*	@param[in] pathToRL - path to RocketLeague.exe in std::string
*	@desc : update the content of the button
*/
void Display::update_button(int eventID, std::string pathToBakkes, std::string pathToRL)
{
	switch (eventID)
	{
	case 10001:
		this->btn_bakkes_path->SetLabelText(pathToBakkes.c_str());
		break;

	case 10002:
		this->btn_RL_path->SetLabelText(pathToRL.c_str());
		break;

	default:
		break;
	}
}

/**
*	Function : button_state
*	@param[in] eventID - pressed button ID
*	@param[in] state - boolean to choose whitch colour to apply ( from System::fileExists() )
*	@desc : change the colour of the button given the bool in param. (can be merged in update button later)
*/
void Display::button_state(int eventID, bool state)
{
	switch (eventID)
	{
	case 10001:
		if (state)
		{
			this->btn_bakkes_path->SetBackgroundColour(wxColour(0, 200, 0));
		}
		else
		{
			this->btn_bakkes_path->SetBackgroundColour(wxColour(200, 0, 0));
		}
			break;

	case 10002:
		if (state)
		{
			this->btn_RL_path->SetBackgroundColour(wxColour(0, 200, 0));
		}
		else
		{
			this->btn_RL_path->SetBackgroundColour(wxColour(200, 0, 0));
		}
		break;

	default:
		break;
	}
}

// getters 

wxButton* Display::get_btn_bakkes_path()
{
	return this->btn_bakkes_path;
}

wxButton* Display::get_btn_RL_path()
{
	return this->btn_RL_path;
}

wxButton* Display::get_btn_Launch()
{
	return this->btn_Launch;
}