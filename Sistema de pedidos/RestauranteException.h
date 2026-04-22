#ifndef RESTAURANTE_EXCEPTION_H
#define RESTAURANTE_EXCEPTION_H
#include <stdexcept>
#include <string>

class RestauranteException : public std::runtime_error {
public:
	RestauranteException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

#endif

