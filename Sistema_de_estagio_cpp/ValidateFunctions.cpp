#include <string>
#include "Options.h"
#include "ValidateFunctions.h"
#include <stdexcept>
#include "NotValidInfo.h"

using std::string;
using std::stoi;

MenuOptions
inputToOptions(const string& op)
{
	if (stoi(op) < int(MenuOptions::sign_up) || stoi(op) > int(MenuOptions::exit))
		throw std::range_error{ "Alternativa fora do intervalo." };
	MenuOptions option{ stoi(op) };
	return option;
}

TraineeMenuOptions
inputToTraineeOptions(const string& op)
{
	if (stoi(op) < int(TraineeMenuOptions::view_profile) || stoi(op) > int(TraineeMenuOptions::exit))
		throw std::range_error{ "Alternativa do menu de estagiario fora do intervalo." };
	TraineeMenuOptions option{ stoi(op) };
	return option;
}

ProfileOptions
inputToProfileOptions(const string& op)
{
	if (stoi(op) < int(ProfileOptions::name) || stoi(op) > int(ProfileOptions::exit))
		throw std::range_error{ "Alternativa do menu de editor de perfil fora do intervalo." };
	ProfileOptions option{ stoi(op) };
	return option;
}

bool
validateSignUp(const string_view& email)
{
	bool isValid = false;
	if (email.find("@aluno.com") != -1)
		isValid = true;

	return isValid;
}

Trainee*
validateLogin(const string_view& email, const string_view& pw, Trainee* user)
{

	if ((email.compare(user->getEmail()) == 0) && (pw.compare(user->getPassword()) == 0)) {
		return user;
	}

	else
		throw NotValidInfo{ "Login e/ou senha incorreto(s)." };
}