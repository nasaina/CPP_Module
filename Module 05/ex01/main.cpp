/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 09:44:13 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void newLine()
{
    std::cout << std::endl;
}

int	main(void)
{
    // Test création Form avec grade de signature trop bas
    try {
        Form f1("TropBas", 151, 10);
    } catch(const std::exception& e) {
        std::cerr << "Exception attendue (sign trop bas): " << e.what() << std::endl;
    }
    newLine();

    // Test création Form avec grade d'exécution trop bas
    try {
        Form f2("TropBasExec", 10, 151);
    } catch(const std::exception& e) {
        std::cerr << "Exception attendue (exec trop bas): " << e.what() << std::endl;
    }
    newLine();

    // Test création Form avec grade de signature trop haut
    try {
        Form f3("TropHaut", 0, 10);
    } catch(const std::exception& e) {
        std::cerr << "Exception attendue (sign trop haut): " << e.what() << std::endl;
    }
    newLine();

    // Test création Form avec grade d'exécution trop haut
    try {
        Form f4("TropHautExec", 10, 0);
    } catch(const std::exception& e) {
        std::cerr << "Exception attendue (exec trop haut): " << e.what() << std::endl;
    }
    newLine();

    // Test création Form valide et affichage
    try {
        Form f5("Valide", 42, 100);
        std::cout << "Form valide: " << f5 << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
    }
    newLine();

    // Test signature par bureaucrate avec grade insuffisant
    try {
        Bureaucrat b1("Petit", 100);
        Form f6("A signer", 50, 50);
        b1.signForm(f6);
        std::cout << f6 << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Exception attendue (signature refusée): " << e.what() << std::endl;
    }
    newLine();

    // Test signature par bureaucrate avec grade suffisant
    try {
        Bureaucrat b2("Grand", 10);
        Form f7("A signer", 50, 50);
        b2.signForm(f7);
        std::cout << f7 << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
    }
    newLine();

    // Test double signature (doit rester signé)
    try {
        Bureaucrat b3("Boss", 1);
        Form f8("Unique", 10, 10);
        b3.signForm(f8);
        b3.signForm(f8);
        std::cout << f8 << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
    }
    newLine();

    // Test opérateur= et constructeur de copie
    try {
        Form f9("Copie", 20, 30);
        Form f10(f9);
        Form f11 = f9;
        std::cout << "Original: " << f9 << std::endl;
        std::cout << "Copie: " << f10 << std::endl;
        std::cout << "Assign: " << f11 << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Erreur inattendue: " << e.what() << std::endl;
    }
    newLine();

    return 0;
}
