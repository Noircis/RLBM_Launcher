#pragma once

#include <wx/wx.h>
#include <fstream>  

class Display : public wxFrame
{
public: 
	Display(std::string pathToBakkes, std::string pathToRL, wxFrame* target);
	~Display();

	// methodes

	/**
*	Function : update_button
*	@param[in] eventID - pressed button ID
*	@param[in] pathToBakkes - path to bakkesMod.exe in std::string
*	@param[in] pathToRL - path to RocketLeague.exe in std::string
*	@desc : update the content of the button
*/
	void update_button(int eventID, std::string pathToBakkes, std::string pathToRL);
	/**
*	Function : button_state
*	@param[in] eventID - pressed button ID
*	@param[in] state - boolean to choose whitch colour to apply ( from System::fileExists() )
*	@desc : change the colour of the button given the bool in param. (can be merged in update button later)
*/
	void button_state(int eventID, bool state);
	
	// getters 

	wxButton* get_btn_bakkes_path();
	wxButton* get_btn_RL_path();
	wxButton* get_btn_Launch();

private: 

	// buttons

	wxButton* btn_bakkes_path = nullptr;
	wxButton* btn_RL_path = nullptr;
	wxButton* btn_Launch = nullptr; 

	// Directory dialog

	wxDirDialog* DirDialog = nullptr;

	// param

	int windowX = 800;
	int windowY = 600;

	int btn_sizeX = 700;
	int btn_sizeY = 30;

	int margin = 15;
};

