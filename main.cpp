#include <iostream>
#include <vector>
#include "./hpps/empresa.hpp"
/**
* @file main.cpp
* @brief projeto final da 3º unidade de LP1
* @author João Marcelo de Souza
* @since 01/07/2023
*/
int main(){
  Empresa *atacadaoDosCalcados = new Empresa();
  atacadaoDosCalcados->carregaFuncoes();
  return 0;
}