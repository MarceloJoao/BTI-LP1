#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"
/**
* @brief Implementação da classe Empresa
*/
class Empresa {
private:
  float faturamentoMensal;
  std::string nomeEmpresa;
  std::string cnpj;
  Pessoa *Dono = new Pessoa();
  std::vector<Asg> asgs;
  std::vector<Vendedor> vendedores;
  std::vector<Gerente> gerentes;

public:
  Empresa();
  Empresa(std::string nomeEmpresa,  float faturamentoMensal, std::string cnpj);
  /**
  * @brief Função para o atributo privado faturamentoMensal
  * @return retorna o faturamentoMensal
  */
  float getFaturamentoMensal();
  /**
  * @brief Função para o atributo privado NomeEmpresa
  * @return retorna o nome da empresa
  */
  std::string getNomeEmpresa();
  /**
  * @brief Função para o atributo privado cnpj
  * @return retorna o cnpj 
  */
  std::string getCnpj();
  Pessoa *getDono();
  /**
  * @brief Função para o atributo privado vector do tipo vendedor
  * @return retorna o vector de vendedores
  */
  std::vector<Vendedor> getVendedores();
  /**
  * @brief Função para o atributo privado vector do tipo asg
  * @return retorna o vector de asgs
  */
  std::vector<Asg> getAsg();
  /**
  * @brief Função para o atributo privado vector do tipo gerente
  * @return retorna o vector de gerentes
  */
  std::vector<Gerente> getGerente();
  void setFaturamentoMensal(float faturamentoMensal);/**<seta o faturamentoMensal*/
  void setNomeEmpresa(std::string nomeEmpresa);/**<seta o nomeEmpresa*/
  void setCnpj(std::string cnpj);/**<seta o cnpj*/
  /**
  * @brief Função para ler o arquivo funcoes.txt
  * @details Função principal do programa, serve para ler o arquivo e fazer a chamada das funções
  */
  void carregaFuncoes();
  /**
  * @brief Função para ler o arquivo empresa.txt e pegar as informações da empresa
  */
  void carregarEmpresa();
  /**
  * @brief Função para ler o arquivo asg.txt
  * @details Serve para ler o arquivo e adicionar informações do asg, no vector asgs
  */
  void carregarAsg();
  /**
  * @brief Função para ler o arquivo vendedor.txt
  * @details Serve para ler o arquivo e adicionar informações do vendedor, no vector vendedores
  */
  void carregarVendedor();
 /**
  * @brief Função para ler o arquivo gerente.txt
  * @details Serve para ler o arquivo e adicionar informações do gerente, no vector gerentes
 */
  void carregarGerente();
 /**
  * @brief Função para ler o arquivo dono.txt e pegar as informações do dono
  */
  void carregaDono();
 /**
 * @brief Função para imprimir todos os asgs da empresa
 */
  void imprimeAsgs();
 /**
 * @brief Função para imprimir todos os vendedores da empresa
 */
  void imprimeVendedores();
 /**
 * @brief Função para imprimir todos os gerentes da empresa
 */
  void imprimeGerentes();
 /**
 * @brief Função para imprimir o dono da empresa
 */
  void imprimeDono();
 /**
 * @brief Função para buscar um funcionario no sistema
 * @param matricula do funcionario
 * @return retorna os dados do funcionario buscado
 */
  void buscaFuncionario(std::string matricula);
 /**
 * @brief Função para calcular o salario do funcionario
 * @param matricula do funcionario
 * @return retorna o salario do funcionario buscado
 */
  void calculaSalarioFuncionario(std::string matricula);
 /**
 * @brief Função para calcular o salario total de cada categoria
 * @details calcula a soma dos salarios de cada categoria, além do custo total dos funcionarios, e a porcentagem do custo de cada categoria em relação ao faturamento mensal da empresa
 */
  void calculaTodoOsSalarios();
 /**
 * @brief Função para calcular a rescisão do funcionario
 * @param matricula e a data de desligamento do funcionario
 * @return retorna o valor da rescisão
 */
  void calcularRescisao(std::string matricula, Data desligamento);
 /**
 * @brief Função para contratar um novo funcionario
 * @details serve para ler o arquivo novoFuncionario.txt e adicionar as informações do novo funcionario no arquivo asg.txt
 */
  void contratarFuncionario();
 /**
 * @brief Função para demitir um funcionario
 * @param matricula e a data de desligamento do funcionario
 * @details serve para demitir um funcionario da empresa e acrescentar as informações do funcionario que foi desligado no arquivo relatoriodemissional.txt
 */
  void demitirFuncionario(std::string matricula, Data desligamento);
};

#endif