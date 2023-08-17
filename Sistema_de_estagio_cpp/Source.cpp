#include <iostream>
#include "Display.h"

void assertFalse(bool expected, bool actual) {
	if (expected == actual)
		std::cout << "Teste de search funcionou! Nao foi encontrado usuarios!";
	else
		std::cout << "Teste falhou!";
}

void assertTrue(bool expected, bool actual) {
	if (expected == actual)
		std::cout << "Teste de search funcionou! Existe usuarios!";
	else
		std::cout << "Teste falhou!";
}

void testSearchTrainee() {
	Repo a{};

	assertFalse(false,a.searchTrainee("email@inexistente.com")); //Teste antes de adicionar no repositorio. Falharia se retornasse verdadeiro.
	
	Trainee dummy{ "abc","abc@aluno.com","123" };
	a.addTrainee(dummy);
	assertTrue(true, a.searchTrainee(dummy.getEmail())); //Teste apos adicao no repo. Falharia se retornarsse falso.
	std::cout << std::endl;
}

int main() {
	testSearchTrainee();
	Display display{};
	display.runApp();

}