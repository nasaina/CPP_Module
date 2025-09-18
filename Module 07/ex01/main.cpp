/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:27:33 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void print_element(const T &element) {
	std::cout << element << " ";
}

template<typename T>
void increment_element(T &element) {
	element++;
}

template<typename T>
void double_element(T &element) {
	element *= 2;
}

void print_char(const char &c) {
	std::cout << "'" << c << "' ";
}

void print_string(const std::string &str) {
	std::cout << "\"" << str << "\" ";
}

void to_uppercase(char &c) {
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

void test_header(const std::string& test_name) {
	std::cout << "\n=== " << test_name << " ===" << std::endl;
}

template<typename T>
void print_array(T *array, int size, const std::string& label) {
	std::cout << label << ": ";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main( void )
{
	test_header("Test 1: Integer array with print function");
	int int_array[5] = {1, 2, 3, 4, 5};
	print_array(int_array, 5, "Original array");
	std::cout << "Using iter to print: ";
	::iter(int_array, 5, print_element<int>);
	std::cout << std::endl;

	test_header("Test 2: Integer array with increment function");
	print_array(int_array, 5, "Before increment");
	::iter(int_array, 5, increment_element<int>);
	print_array(int_array, 5, "After increment");

	test_header("Test 3: Integer array with double function");
	print_array(int_array, 5, "Before doubling");
	::iter(int_array, 5, double_element<int>);
	print_array(int_array, 5, "After doubling");

	test_header("Test 4: Float array");
	float float_array[4] = {1.1f, 2.2f, 3.3f, 4.4f};
	print_array(float_array, 4, "Original float array");
	std::cout << "Using iter to print: ";
	::iter(float_array, 4, print_element<float>);
	std::cout << std::endl;
	::iter(float_array, 4, double_element<float>);
	print_array(float_array, 4, "After doubling");

	test_header("Test 5: Character array");
	char char_array[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	std::cout << "Original char array: ";
	::iter(char_array, 5, print_char);
	std::cout << std::endl;
	
	::iter(char_array, 5, to_uppercase);
	std::cout << "After uppercase: ";
	::iter(char_array, 5, print_char);
	std::cout << std::endl;

	test_header("Test 6: String array");
	std::string string_array[3] = {"hello", "world", "test"};
	std::cout << "String array: ";
	::iter(string_array, 3, print_string);
	std::cout << std::endl;

	test_header("Test 7: Double array");
	double double_array[3] = {-1.5, 0.0, 2.7};
	print_array(double_array, 3, "Original double array");
	std::cout << "Using iter to print: ";
	::iter(double_array, 3, print_element<double>);
	std::cout << std::endl;

	test_header("Test 8: Empty array (size 0)");
	int *empty_array = NULL;
	std::cout << "Testing with size 0..." << std::endl;
	::iter(empty_array, 0, print_element<int>);
	std::cout << "No output expected above." << std::endl;

	std::cout << "\n=== All iter tests completed ===" << std::endl;
	return 0;
}
