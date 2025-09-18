/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:29:57 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void test_header(const std::string& test_name) {
	std::cout << "\n=== " << test_name << " ===" << std::endl;
}

template<typename T>
void print_array_info(const Array<T>& arr, const std::string& name) {
	std::cout << name << " size: " << arr.size() << std::endl;
	if (arr.size() > 0) {
		std::cout << name << " elements: ";
		for (unsigned int i = 0; i < arr.size(); i++) {
			std::cout << arr.getElement()[i] << " ";
		}
		std::cout << std::endl;
	}
}

int main( void )
{
	test_header("Test 1: Default constructor (empty array)");
	try {
		Array<int> empty_array;
		std::cout << "Empty array size: " << empty_array.size() << std::endl;
		
		std::cout << "Trying to access element [0] of empty array..." << std::endl;
		std::cout << empty_array[0] << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 2: Constructor with size parameter");
	try {
		Array<int> int_array(5);
		std::cout << "Created int array with size: " << int_array.size() << std::endl;
		
		std::cout << "Initial values: ";
		for (unsigned int i = 0; i < int_array.size(); i++) {
			std::cout << int_array[i] << " ";
		}
		std::cout << std::endl;
		
		int_array[0] = 10;
		int_array[1] = 20;
		int_array[2] = 30;
		
		std::cout << "After modification: ";
		for (unsigned int i = 0; i < int_array.size(); i++) {
			std::cout << int_array[i] << " ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 3: Copy constructor");
	try {
		Array<int> original(4);
		original[0] = 100;
		original[1] = 200;
		original[2] = 300;
		original[3] = 400;
		
		print_array_info(original, "Original array");
		
		Array<int> copy(original);
		print_array_info(copy, "Copied array");
		
		original[0] = 999;
		std::cout << "After modifying original[0] to 999:" << std::endl;
		print_array_info(original, "Original array");
		print_array_info(copy, "Copied array (should be unchanged)");
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 4: Out of bounds access");
	try {
		Array<int> test_array(3);
		test_array[0] = 1;
		test_array[1] = 2;
		test_array[2] = 3;
		
		std::cout << "Valid access test_array[1]: " << test_array[1] << std::endl;
		
		std::cout << "Trying to access test_array[5] (out of bounds)..." << std::endl;
		std::cout << test_array[5] << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 5: Different types - strings");
	try {
		Array<std::string> string_array(3);
		string_array[0] = "Hello";
		string_array[1] = "World";
		string_array[2] = "Test";
		
		std::cout << "String array contents: ";
		for (unsigned int i = 0; i < string_array.size(); i++) {
			std::cout << "\"" << string_array[i] << "\" ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 6: Different types - floats");
	try {
		Array<float> float_array(4);
		float_array[0] = 3.14f;
		float_array[1] = 2.71f;
		float_array[2] = 1.41f;
		float_array[3] = 1.73f;
		
		std::cout << "Float array contents: ";
		for (unsigned int i = 0; i < float_array.size(); i++) {
			std::cout << float_array[i] << " ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 7: setElement method");
	try {
		Array<int> test_array(3);
		
		std::cout << "Using setElement method:" << std::endl;
		test_array.setElement(89, 1);
		test_array.setElement(45, 0);
		test_array.setElement(67, 2);
		
		print_array_info(test_array, "Array after setElement");
		
		std::cout << "Trying setElement with out of bounds index..." << std::endl;
		test_array.setElement(99, 5);
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	test_header("Test 8: Copy constructor with scope test");
	try {
		Array<int> outer_array(2);
		outer_array[0] = 42;
		outer_array[1] = 84;
		
		{
			Array<int> inner_array(outer_array);
			inner_array[0] = 100;
			std::cout << "Inner array [0]: " << inner_array[0] << std::endl;
			std::cout << "Inner array [1]: " << inner_array[1] << std::endl;
		}
		
		std::cout << "Outer array after inner scope:" << std::endl;
		std::cout << "Outer array [0]: " << outer_array[0] << std::endl;
		std::cout << "Outer array [1]: " << outer_array[1] << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== All Array tests completed ===" << std::endl;
	return 0;
}
