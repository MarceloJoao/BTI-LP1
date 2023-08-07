#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
* @brief Implementaçao da classe Asg
* @details classe filha de pessoa e funcionario
*/
class Asg: public Pessoa, public Funcionario{  
private:
    float adicionalInsalubridade = 0.05;

public:
    Asg();
    Asg(float adicionalInsalubridade);
    /**
    * @brief função para o atributo privado adicionalInsurabilidade         
    * @return retorna o adicionalInsalubridade
    */
    float getAdcionalInsabubridade();
    void setAdcionalInsabubridade(float adicionalInsalubridade); /**<seta o adicionalInsaburidade*/
   /**
    * @brief função para calcular salario
    * @param DiasFaltas
    * @return retorna o salario do asg
   */
    float calcularSalario(int diasFaltas);
   /**
    * @brief função para calcular a Rescisão
    * @param Data no qual o asg foi desligado da empresa
    * @return retorna o valor da Rescisão
   */
    float calcularRecisao(Data desligamento);
};

#endif