/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:29:42 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void test_header(const std::string& test_name) {
	std::cout << "\n=== " << test_name << " ===" << std::endl;
}

int main( void ) {
	test_header("Test 1: Basic int swap, min, max");
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	
	::swap( a, b );
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	test_header("Test 2: String swap, min, max");
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	test_header("Test 3: Float types");
	float f1 = 3.14f;
	float f2 = 2.71f;
	std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
	
	::swap(f1, f2);
	std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min( f1, f2 ) << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max( f1, f2 ) << std::endl;

	test_header("Test 4: Equal values");
	int equal1 = 42;
	int equal2 = 42;
	std::cout << "Equal values: equal1 = " << equal1 << ", equal2 = " << equal2 << std::endl;
	std::cout << "min( equal1, equal2 ) = " << ::min( equal1, equal2 ) << std::endl;
	std::cout << "max( equal1, equal2 ) = " << ::max( equal1, equal2 ) << std::endl;

	test_header("Test 5: Character types");
	char ch1 = 'z';
	char ch2 = 'a';
	std::cout << "Before swap: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
	
	::swap(ch1, ch2);
	std::cout << "After swap: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
	std::cout << "min( ch1, ch2 ) = " << ::min( ch1, ch2 ) << std::endl;
	std::cout << "max( ch1, ch2 ) = " << ::max( ch1, ch2 ) << std::endl;

	test_header("Test 6: Double types with negative values");
	double d1 = -5.5;
	double d2 = 10.2;
	std::cout << "Before swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
	
	::swap(d1, d2);
	std::cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
	std::cout << "min( d1, d2 ) = " << ::min( d1, d2 ) << std::endl;
	std::cout << "max( d1, d2 ) = " << ::max( d1, d2 ) << std::endl;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
