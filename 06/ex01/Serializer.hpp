#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>

struct Data {
	int n;
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const& copy);
	Serializer& operator=(Serializer const& copy);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_H */
