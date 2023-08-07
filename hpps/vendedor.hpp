#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
/**
* @brief Implementação da classe Vendedor
* @details classe filha de Pessoa e Funcionario
*/
class Vendedor : public Pessoa, public Funcionario{

private:
    std::string tipoVendedor; // A, B, C

public:
    Vendedor();
    Vendedor(char tipoVendedor);
  /**
  * @brief Função para o atributo privado TipoVendedor
  * @return retorna o tipo do Vendedor
  * @details De acordo com o seu tipo, o vendedor recebe uma bonificação
  */
    std::string getTipoVendedor();
    void setTipoVendedor(std::string tipoVendedor);/**<seta o tipoVendedor*/
  /**
  * @brief Função para calcular o salario do Vendedor
  * @param Quantidade de dias que o vendedor faltou
  * @return retorna o salario do vendedor
  */
    float calcularSalario(int diasFaltas);
  /**
  * @brief Função para calcular a rescisão do vendedor
  * @param Data de desligamento do vendedor
  * @return retorna o valor da rescisão
  */
    float calcularRecisao(Data desligamento);
};

#endif