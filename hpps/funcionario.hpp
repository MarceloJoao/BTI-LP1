#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "util.hpp"
/**
* @brief Implementação da classe abstrata funcionario
*/
class Funcionario {
private:
    float salario;
    int diasFaltas;
    std::string matricula;
    Data ingressoEmpresa;

public:
    /**
    * @brief metodo virtual de funcionario para calcular Salário
    * @param quantidade de dias que o funcionario faltou
    * @return retorna o salario mensal do funcionario
    */
    virtual float calcularSalario(int diasFaltas) = 0;
    /**
    * @brief metodo virtual de funcionario para calcular a Rescisão
    * @param Data de saída do funcionario
    * @return retorna o valor da Rescisão do funcionario
    */
    virtual float calcularRecisao(Data desligamento) = 0;
    /**
    * @brief função para o atributo privado salario
    * @return retorna o salario
    */
    float getSalario();
    /**
    * @brief função para o atributo privado matricula
    * @return retorna a matricula
    */
    std::string getMatricula();
    /**
    * @brief função para o atributo privado ingresso do tipo Data
    * @return retorna a data de ingresso do funcionario na empresa
    */
    Data getDataingresso();
    void setSalario(float salario); /**<seta o salario*/
    void setMatricula(std::string matricula);/**<seta a matricula*/
    void setDataingresso(Data ingressoEmpresa);/**<seta a Data de ingresso*/
    /**
    * @brief função para o atributo privado Diasfaltas
    * @return retorna os dias que o funcionario faltou
    */
    int getDiasFaltas();
    void setDiasFaltas(int diasFaltas);/**<seta os dias de faltas*/
};

#endif