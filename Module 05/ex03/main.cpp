/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 10:06:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void newLine()
{
	std::cout << "\n-----------------------------\n";
}

int main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	// Test Intern form creation (valid and invalid)
	try {
		Intern intern;
		AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
		AForm* form2 = intern.makeForm("robotomy request", "Robot");
		AForm* form3 = intern.makeForm("presidential pardon", "Alice");
		std::cout << "Intern successfully created all forms." << std::endl;
		delete form1;
		delete form2;
		delete form3;
	} catch(const std::exception& e) {
		std::cerr << "Intern form creation failed: " << e.what() << std::endl;
	}
	newLine();

	// Test Intern with an unknown form name
	try {
		Intern intern;
		AForm* form = intern.makeForm("unknown form", "Nobody");
		delete form;
	} catch(const std::exception& e) {
		std::cerr << "Expected error for unknown form: " << e.what() << std::endl;
	}
	newLine();

	// Test Bureaucrat signing and executing all forms
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Bob");

		boss.signForm(shrub);
		boss.executeForm(shrub);
		newLine();

		boss.signForm(robot);
		for (int i = 0; i < 3; ++i)
			boss.executeForm(robot);
		newLine();

		boss.signForm(pardon);
		boss.executeForm(pardon);
	} catch(const std::exception& e) {
		std::cerr << "Error during bureaucrat form handling: " << e.what() << std::endl;
	}
	newLine();

	// Test execution without signature
	try {
		Bureaucrat exec("Exec", 1);
		RobotomyRequestForm robot("Target");
		exec.executeForm(robot); // Should throw because not signed
	} catch(const std::exception& e) {
		std::cerr << "Expected error (not signed): " << e.what() << std::endl;
	}
	newLine();

	// Test signing/executing with insufficient grade
	try {
		Bureaucrat low("LowRank", 150);
		ShrubberyCreationForm shrub("Forest");
		low.signForm(shrub); // Should fail
		low.executeForm(shrub); // Should fail
	} catch(const std::exception& e) {
		std::cerr << "Expected error (grade too low): " << e.what() << std::endl;
	}
	newLine();

	// Test polymorphism with AForm*
	try {
		Bureaucrat poly("Poly", 1);
		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("Tree");
		forms[1] = new RobotomyRequestForm("Bot");
		forms[2] = new PresidentialPardonForm("Alice");
		for (int i = 0; i < 3; ++i) {
			poly.signForm(*forms[i]);
			poly.executeForm(*forms[i]);
			delete forms[i];
		}
	} catch(const std::exception& e) {
		std::cerr << "Unexpected error in polymorphism test: " << e.what() << std::endl;
	}
	newLine();

	std::cout << "All tests completed." << std::endl;
	return 0;
}
