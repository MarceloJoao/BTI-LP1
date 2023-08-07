#include <iostream>
#include "../hpps/funcionario.hpp"

using namespace std;

float Funcionario::getSalario(){ 
    return this->salario; 
}

string Funcionario::getMatricula(){ 
    return this->matricula; 
}

Data Funcionario::getDataingresso(){ 
    return this->ingressoEmpresa; 
}

void Funcionario::setSalario(float salario){ 
    this->salario = salario; 
}

void Funcionario::setMatricula(string matricula){ 
    this->matricula = matricula; 
}

void Funcionario::setDataingresso(Data ingressoEmpresa){
        this->ingressoEmpresa = ingressoEmpresa;
}

int Funcionario::getDiasFaltas(){
    return this->diasFaltas;
}
void Funcionario::setDiasFaltas(int diasFaltas){
    this->diasFaltas = diasFaltas;
}