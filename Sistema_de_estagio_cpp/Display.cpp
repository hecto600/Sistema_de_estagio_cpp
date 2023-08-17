#include <iostream>
#include <string>
#include <iomanip>
#include "Options.h"
#include "ValidateFunctions.h"
#include "Display.h"
#include "NotValidInfo.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::stoi;
using std::left;

void
Display::consoleColor(const WORD color)
{
	SetConsoleTextAttribute(hConsole, color);
}

void
Display::dyedInput(const WORD color, string& input)
{
	SetConsoleTextAttribute(hConsole, color);
	cin >> input;
	SetConsoleTextAttribute(hConsole, int(col::dark_white));

}

void
Display::dyedOutput(const WORD color, const string& output)
{
	SetConsoleTextAttribute(hConsole, color);
	cout << output;
	SetConsoleTextAttribute(hConsole, int(col::dark_white));
}



void
Display::runApp()
{
	string op;
	consoleColor(int(col::aqua));
	cout << textDiv << endl
		<< textTitle << endl
		<< textDiv << endl;
	consoleColor(int(col::dark_white));

	do
	{
		consoleColor(int(col::aqua));
		cout << textDiv << endl
			<< "Menu de principal" << endl
			<< textDiv << endl;
		consoleColor(int(col::dark_white));


		cout << "Selecione uma alternativa:" << endl
			<< "1: Cadastrar usuario" << endl
			<< "2: Login de usuario" << endl
			<< "3: Sair" << endl;
		dyedInput(int(col::yellow), op);


		mainMenu(op);
	} while (stoi(op) != int(MenuOptions::exit));
	consoleColor(int(col::green));
	cout << "Aplicativo encerrado.";
}

void
Display::mainMenu(const string& op)
{
	try
	{
		MenuOptions options = inputToOptions(op);

		switch (options)
		{
		case MenuOptions::sign_up:
			signUp();
			break;

		case MenuOptions::login:
			login();
			break;

		case MenuOptions::exit:

			break;
		default:
			cout << "Impossivel." << endl;
			break;
		}
	}
	catch (const std::range_error rangeEx)
	{
		consoleColor(int(col::red));
		cerr << "Error: " << rangeEx.what() << " Tente novamente." << endl;
		consoleColor(int(col::dark_white));
	}
	catch (const NotValidInfo& invalidInfoEx)
	{
		consoleColor(int(col::red));
		cerr << "\tError: " << invalidInfoEx.getError() << " Tente novamente." << endl;
		consoleColor(int(col::dark_white));
	}

}

void
Display::signUp()
{
	string email{};
	string name{};
	string pw{};
	bool isValid = false;


	consoleColor(int(col::aqua));
	cout << "\t" << textDiv << endl
		<< "\tMenu de cadastro" << endl
		<< "\t" << textDiv << endl;
	consoleColor(int(col::dark_white));


	cout << "\tNome: ";
	dyedInput(int(col::yellow), name);

	cout << "\tSenha: ";
	dyedInput(int(col::yellow), pw);


	do
	{
		cout << "\tEmail(@aluno.com): ";
		dyedInput(int(col::yellow), email);


		if (traineeRepo.searchTrainee(email))
			cout << "\tEmail ja existe." << endl;
		else
			isValid = validateSignUp(email);

		if (!isValid)
			cout << "\tEmail invalido." << endl;

	} while (!isValid);

	Trainee dummy{ name,email,pw };
	traineeRepo.addTrainee(dummy);

	dyedOutput(int(col::green), "\tCadastro concluido.\n\n");

}

void
Display::login()
{
	string email{};
	string pw{};

	consoleColor(int(col::aqua));
	cout << "\t" << textDiv << endl
		<< "\t" << "Menu de login" << endl
		<< "\t" << textDiv << endl;
	consoleColor(int(col::dark_white));


	cout << "\tDigite seu email de login: ";
	dyedInput(int(col::yellow), email);
	cout << "\tDigite a senha de login: ";
	dyedInput(int(col::yellow), pw);

	currentTrainee = validateLogin(email, pw, traineeRepo.getTrainee(email));

	traineeMenu();
}

void
Display::traineeMenu()
{
	string op;
	dyedOutput(int(col::green), " \tLogin efetuado com exito.\n\n");

	consoleColor(int(col::aqua));
	cout << "\t" << textDiv << endl
		<< "\tMenu do estagiario" << endl
		<< "\t" << textDiv << endl;
	consoleColor(int(col::dark_white));

	do
	{

		cout << "\t1: Ver perfil" << endl
			<< "\t2: Alterar perfil" << endl
			<< "\t3: Sair" << endl << "\t";
		dyedInput(int(col::yellow), op);


		traineeMenuSelection(op);

	} while (stoi(op) != int(TraineeMenuOptions::exit));

}

void
Display::traineeMenuSelection(const string& op)
{
	TraineeMenuOptions options = inputToTraineeOptions(op);
	switch (options)
	{
	case TraineeMenuOptions::view_profile:
		dyedOutput(int(col::green), currentTrainee->toString());
		break;
	case TraineeMenuOptions::edit_profile:
		editProfile();
		break;
	case TraineeMenuOptions::exit:
		break;
	default:
		break;
	}
}

void Display::editProfile()
{
	consoleColor(int(col::aqua));
	cout << "\t\t" << textDiv << endl
		<< "\t\tEditor de perfil" << endl
		<< "\t\t" << textDiv << endl;
	consoleColor(int(col::dark_white));

	string op;
	do
	{
		cout << "\t\tEscolha o campo para ser alterado" << endl
			<< "\t\t1: Nome" << endl
			<< "\t\t2: Email" << endl
			<< "\t\t3: Senha" << endl
			<< "\t\t4: Sair" << endl
			<< "\t\t";
		dyedInput(int(col::yellow), op);
		editSelection(op);


	} while (stoi(op) != int(ProfileOptions::exit));
}

void Display::editSelection(const string& op)
{
	boolean isValid = false;
	string input;
	ProfileOptions option = inputToProfileOptions(op);
	switch (option)
	{
	case ProfileOptions::name:
		cout << "\t\tDigite novo nome: ";
		dyedInput(int(col::yellow), input);
		currentTrainee->setName(input);
		break;

	case ProfileOptions::email:

		do
		{
			cout << "\t\tNovo email(@aluno.com): ";
			dyedInput(int(col::yellow), input);

			if (traineeRepo.searchTrainee(input))
				cout << "\t\tEmail ja existe." << endl;
			else
				isValid = validateSignUp(input);

			if (!isValid)
				cout << "\t\tEmail invalido." << endl;

		} while (!isValid);
		currentTrainee->setEmail(input);
		break;

	case ProfileOptions::password:
		cout << "\t\tNova senha: ";
		dyedInput(int(col::yellow), input);
		currentTrainee->setPassword(input);
		break;

	case ProfileOptions::exit:
		break;
	default:
		dyedOutput(int(col::red), "Opcao invalida!");
		break;
	}
}



