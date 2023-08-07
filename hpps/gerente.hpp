#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"
/**
* @brief Implementação da classe Gerente
* @details Classe filha de Pessoa e Funcionario
*/
class Gerente : public Pessoa, public Funcionario{

private:
    float participacaoLucros;

public:
    Gerente();  
    Gerente(float participacaoLucros);
  /**
  * @brief Função para o atributo privado ParticipacaoLucros
  * @return retorna a taxa de participação de lucros do gerente
  */
    float getParticipacaoLucros();
    void setParticipacaoLucros(float participacaoLucros);/**<seta a participacaoLucros*/
 /**
 * @brief Função para calcular o salário do gerente
 * @param Quantidade de dias que o gerente faltou
 * @return Retorna o salário do gerente
 */
    float calcularSalario(int diasFaltas);
  /**
  * @brief Função para calcular a rescisão do gerente
  * @param Data de desligamento
  * @return retorna o valor da Rescisão do gerente
  */
    float calcularRecisao(Data desligamento);
};

#endif