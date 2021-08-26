#pragma once

#include <wx/wx.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Display.h"

/*
*	Class: System
*	@desc : Handle all the soft logics
*/
class System
{
public:
	System(wxFrame* target, Display* display);
	~System();

	// methodes 

/**
*	Function : fileExists
*	@param[in] filename - name of the file to test
*	@desc : return true if file exists
*/
	bool fileExists(const std::string filename);
/**
*	Function : onClick
*	@param[in] event - catch mouse button event
*	@desc : switch around event.type() and apply a set of actions [...]
*/
	void onClick(wxCommandEvent& event);
/**
*	Function : cBind
*	@param[in] button - button to link
*	@desc : Bind the button passed into param to the specified function
*/
	void cBind(wxButton* button);
/**
*	Function : launch
*	@desc : Launch the two apps (system() might not be the most secure way)
*/
	bool launch();

	void savePath();
	void loadPath();


	// getters

	std::string get_str_path_to_bakkes();
	std::string get_str_path_to_RL();

	std::string get_config_filename();
	std::string get_bakkes_filename();
	std::string get_RL_filename();

private:
	// param

	Display* display = nullptr;

	wxDirDialog* DirDialog_bakkes	= nullptr;
	wxDirDialog* DirDialog_RL		= nullptr;

	std::string str_path_to_bakkes;
	std::string str_path_to_RL;

	// const

	const std::string config_filename	= "config.ini";
	const std::string bakkes_filename	= "BakkesMod.exe";
	const std::string RL_filename		= "RocketLeague.exe";

};

