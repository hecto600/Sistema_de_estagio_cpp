#pragma once
#include <string>
#include "Trainee.h"
#include "Repo.h"
#include <Windows.h>

using std::string;
enum class col
{
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua = 3, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};

class Display
{
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	const string textDiv = "========================";
	const string textTitle = "|| Sistema de estagio ||";
	Trainee* currentTrainee{};
	Repo traineeRepo{};

public:
	void consoleColor(const WORD color);
	void dyedInput(const  WORD color, string& input);
	void dyedOutput(const WORD color, const string& output);
	void runApp();
	void mainMenu(const string& op);
	void signUp();
	void login();
	void traineeMenu();
	void traineeMenuSelection(const string& op);
	void editProfile();
	void editSelection(const string& op);
};
