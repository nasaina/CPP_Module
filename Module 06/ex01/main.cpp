/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 14:50:13 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	std::cout << "Testing Serializer functionality:" << std::endl << std::endl;

	std::cout << "--- Test 1: Basic serialization/deserialization ---" << std::endl;
	Data *original = new Data;
	original->content = "Hello World";
	
	std::cout << "Original pointer address: " << original << std::endl;
	std::cout << "Original content: " << original->content << std::endl;
	
	uintptr_t serialized = Serializer::serialize(original);
	std::cout << "Serialized value: " << serialized << std::endl;
	
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized pointer address: " << deserialized << std::endl;
	std::cout << "Deserialized content: " << deserialized->content << std::endl;
	
	std::cout << "Pointers equal: " << (original == deserialized ? "Yes" : "No") << std::endl;
	std::cout << "Content equal: " << (original->content == deserialized->content ? "Yes" : "No") << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 2: Multiple data structures ---" << std::endl;
	Data *data1 = new Data;
	Data *data2 = new Data;
	Data *data3 = new Data;
	
	data1->content = "First data";
	data2->content = "Second data";
	data3->content = "Third data";
	
	uintptr_t ser1 = Serializer::serialize(data1);
	uintptr_t ser2 = Serializer::serialize(data2);
	uintptr_t ser3 = Serializer::serialize(data3);
	
	Data *des1 = Serializer::deserialize(ser1);
	Data *des2 = Serializer::deserialize(ser2);
	Data *des3 = Serializer::deserialize(ser3);
	
	std::cout << "Data1 - Original: " << data1 << " Deserialized: " << des1 << " Match: " << (data1 == des1 ? "Yes" : "No") << std::endl;
	std::cout << "Data2 - Original: " << data2 << " Deserialized: " << des2 << " Match: " << (data2 == des2 ? "Yes" : "No") << std::endl;
	std::cout << "Data3 - Original: " << data3 << " Deserialized: " << des3 << " Match: " << (data3 == des3 ? "Yes" : "No") << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 3: Empty content ---" << std::endl;
	Data *emptyData = new Data;
	emptyData->content = "";
	
	uintptr_t emptySer = Serializer::serialize(emptyData);
	Data *emptyDes = Serializer::deserialize(emptySer);
	
	std::cout << "Empty data test - Match: " << (emptyData == emptyDes ? "Yes" : "No") << std::endl;
	std::cout << "Empty content preserved: " << (emptyData->content == emptyDes->content ? "Yes" : "No") << std::endl;
	std::cout << std::endl;

	std::cout << "All tests completed successfully!" << std::endl;

	delete original;
	delete data1;
	delete data2;
	delete data3;
	delete emptyData;
	
	return (0);
}