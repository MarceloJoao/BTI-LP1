#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"
/**
* @brief Implementação da classe Pessoa
*/
class Pessoa {
private:
  std::string nome;
  std::string cpf;
  Data dataNascimento;
  Endereco enderecoPessoal;
  std::string estadoCivil;
  int qtdFilhos;

public:
  Pessoa();
  Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);
  /**
  * @brief Função para o atributo privado Nome
  * @return retorna o Nome
  */
  std::string getNome();
  /**
  * @brief Função para o atributo privado cpf
  * @return retorna o cpf
  */
  std::string getCpf();
  /**
  * @brief Função para o atributo privado DataNascimento do tipo Data
  * @return retorna a data de nascimento
  */
  Data getDataNascimento();
  /**
  * @brief Função para o atributo privado enderecoPessoal do tipo Endereco
  * @return retorna o endereco
  */
  Endereco getEndereco();
  /**
  * @brief Função para o atributo privado EstadoCivil
  * @return retorna o EstadoCivil
  */
  std::string getEstadoCivil();
  /**
  * @brief Função para o atributo privado QtdFilhos
  * @return retorna a quantidade de filhos
  */
  int getQtdFilhos();
  void setNome(std::string nome);/**<seta o nome*/
  void setCpf(std::string cpf);/**<seta o cpf*/
  void setDataNascimento(Data dataNascimento);/**<seta a dataNascimento*/
  void setEndereco(Endereco enderecoPessoal);/**<seta o enderecoPessoal*/
  void setEstadoCivil(std::string estadoCivil);/**<seta o estadoCivil*/
  void setQtdFilhos(int qtdFilhos);/**<seta a QtdFilhos*/
};

#endif