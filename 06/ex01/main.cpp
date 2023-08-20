#include "Serializer.hpp"
#include <iostream>

int main (void) {

	Data* data = new Data;
	data->n = 42;
	std::cout << data << std::endl;
	std::cout << typeid(data).name() << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << raw << std::endl;
	std::cout << typeid(raw).name() << std::endl;

	Data* data2 = Serializer::deserialize(raw);
	std::cout << typeid(data2).name() << std::endl;
	std::cout << data2 << std::endl;

	std::cout << Serializer::deserialize(Serializer::serialize(data))->n << std::endl;
	delete data;
	return 0;
}