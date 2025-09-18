/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 09:56:12 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void newLine()
{
	std::cout << std::endl;
}

int main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));

    // Test creation with valid grades
    try {
        ShrubberyCreationForm f1("fail");
        PresidentialPardonForm f2("fail");
        RobotomyRequestForm f3("fail");
        std::cout << "Form creation OK" << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Unexpected error during creation: " << e.what() << std::endl;
    }
    newLine();

    // Test signing and execution with insufficient bureaucrat grade
    try {
        Bureaucrat b1("LowRank", 150);
        ShrubberyCreationForm shrub("garden");
        b1.signForm(shrub); // should fail
        b1.executeForm(shrub); // should fail
    } catch(const std::exception& e) {
        std::cerr << "Expected exception (grade too low): " << e.what() << std::endl;
    }
    newLine();

    // Test signing and execution with sufficient bureaucrat grade
    try {
        Bureaucrat b2("Boss", 1);
        ShrubberyCreationForm shrub("forest");
        b2.signForm(shrub);
        b2.executeForm(shrub);
    } catch(const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    newLine();

    // Test execution without signature
    try {
        Bureaucrat b3("Exec", 1);
        RobotomyRequestForm robot("target");
        b3.executeForm(robot); // should fail because not signed
    } catch(const std::exception& e) {
        std::cerr << "Expected exception (not signed): " << e.what() << std::endl;
    }
    newLine();

    // Test robotomy (random)
    try {
        Bureaucrat b4("Drill", 1);
        RobotomyRequestForm robot("victim");
        b4.signForm(robot);
        for (int i = 0; i < 5; ++i) {
            b4.executeForm(robot);
        }
    } catch(const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    newLine();

    // Test PresidentialPardonForm
    try {
        Bureaucrat b5("President", 1);
        PresidentialPardonForm pres("Bob");
        b5.signForm(pres);
        b5.executeForm(pres);
    } catch(const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    newLine();

    // Test polymorphism with AForm*
    try {
        Bureaucrat b6("Poly", 1);
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("tree");
        forms[1] = new RobotomyRequestForm("bot");
        forms[2] = new PresidentialPardonForm("Alice");
        for (int i = 0; i < 3; ++i) {
            b6.signForm(*forms[i]);
            b6.executeForm(*forms[i]);
            delete forms[i];
        }
    } catch(const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    newLine();

    return 0;
}