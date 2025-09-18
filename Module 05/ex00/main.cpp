/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 09:40:17 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void newLine()
{
	std::cout << std::endl;
}

int	main(void)
{
	// Test création avec grade trop haut
	try {
		Bureaucrat b1("TropHaut", 0);
	} catch(const std::exception& e) {
		std::cerr << "Exception attendue (grade trop haut): " << e.what() << std::endl;
	}
	newLine();

	// Test création avec grade trop bas
	try {
		Bureaucrat b2("TropBas", 151);
	} catch(const std::exception& e) {
		std::cerr << "Exception attendue (grade trop bas): " << e.what() << std::endl;
	}
	newLine();

	// Test création avec grade minimum
	try {
		Bureaucrat b3("Min", 1);
		std::cout << "Création grade min: " << b3 << std::endl;
		b3.incrementation(); // Doit throw
	} catch(const std::exception& e) {
		std::cerr << "Exception attendue (incrémentation au min): " << e.what() << std::endl;
	}
	newLine();

	// Test création avec grade maximum
	try {
		Bureaucrat b4("Max", 150);
		std::cout << "Création grade max: " << b4 << std::endl;
		b4.decrementation(); // Doit throw
	} catch(const std::exception& e) {
		std::cerr << "Exception attendue (décrémentation au max): " << e.what() << std::endl;
	}
	newLine();

	// Test incrémentation/décrémentation normale
	try {
		Bureaucrat b5("Normal", 75);
		std::cout << "Avant incrémentation: " << b5 << std::endl;
		b5.incrementation();
		std::cout << "Après incrémentation: " << b5 << std::endl;
		b5.decrementation();
		std::cout << "Après décrémentation: " << b5 << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Erreur inattendue: " << e.what() << std::endl;
	}
	newLine();

	// Test opérateur= et constructeur de copie
	try {
		Bureaucrat original("Original", 42);
		Bureaucrat copie(original);
		Bureaucrat assign = original;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copie: " << copie << std::endl;
		std::cout << "Assign: " << assign << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Erreur inattendue: " << e.what() << std::endl;
	}
	newLine();

	// Test const correctness
	try {
		const Bureaucrat b6("ConstTest", 10);
		std::cout << "Nom (const): " << b6.getName() << ", Grade (const): " << b6.getGrade() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Erreur inattendue: " << e.what() << std::endl;
	}
	newLine();

	// Test affichage
	try {
		Bureaucrat b7("Affichage", 100);
		std::cout << b7 << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Erreur inattendue: " << e.what() << std::endl;
	}
	newLine();

	return 0;
}

