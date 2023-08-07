#ifndef UTIL_HPP
#define UTIL_HPP
#include <iostream>

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  std::string rua, bairro, cidade, cep;
  int numero;
} Endereco;

#endif