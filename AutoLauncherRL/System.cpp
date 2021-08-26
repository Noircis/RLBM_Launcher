#include "System.h"

System::System(wxFrame* target, Display* display)
{
	this->DirDialog_bakkes		= new wxDirDialog(target, "Select the folder that contains 'bakkesMod.exe'");
	this->DirDialog_RL			= new wxDirDialog(target, "Select the folder that contains 'RocketLeague.exe'");

	this->display = display;

	this->str_path_to_bakkes	= "path to BakkesMod";
	this->str_path_to_RL		= "path to Rocket League";
}

System::~System()
{

}

// methodes

/**
*	Function : fileExists
*	@param[in] filename - name of the file to test
*	@desc : return true if file exists
*/
bool System::fileExists(const std::string filename)
{
	std::ifstream file(filename);
	return file.good();
}


void System::savePath()
{
	
}

void System::loadPath() 
{

}

/**
*	Function : onClick
*	@param[in] event - catch mouse button event
*	@desc : switch around event.type() and apply a set of actions [...]
*/
void System::onClick(wxCommandEvent &event)
{
	int evntType = (event.GetId());
	switch (evntType)
	{
	case 10001 :
		this->DirDialog_bakkes->ShowModal();
		str_path_to_bakkes = DirDialog_bakkes->GetPath();
		str_path_to_bakkes.append("\\BakkesMod.exe");
		this->display->update_button(event.GetId(), this->str_path_to_bakkes, this->str_path_to_RL);
		this->display->button_state(event.GetId(), fileExists(str_path_to_bakkes));
		break; 
	case 10002 :
		this->DirDialog_RL->ShowModal();
		str_path_to_RL = DirDialog_RL->GetPath();
		str_path_to_RL.append("\\RocketLeague.exe");
		this->display->update_button(event.GetId(), this->str_path_to_bakkes, this->str_path_to_RL);
		this->display->button_state(event.GetId(), fileExists(str_path_to_RL));
		break;
	case 10003 :
			this->launch();
		break;

	default:
		break;
	}
}

/**
*	Function : cBind
*	@param[in] button - button to link
*	@desc : Bind the button passed into param to the specified function
*/
void System::cBind(wxButton* button)
{
	button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &System::onClick, this);
}

/**
*	Function : launch
*	@desc : Launch the two apps (system() might not be the most secure way)
*/
bool System::launch()
{
	system(this->str_path_to_bakkes.c_str());
	system(this->str_path_to_RL.c_str());
	return true;
}

// getters 

std::string System::get_str_path_to_bakkes()
{
	return this->str_path_to_bakkes;
}

std::string System::get_str_path_to_RL()
{
	return this->str_path_to_RL;
}

std::string System::get_config_filename()
{
	return this->config_filename;
}

std::string System::get_bakkes_filename()
{
	return this->bakkes_filename;
}

std::string System::get_RL_filename()
{
	return this->RL_filename;
}
