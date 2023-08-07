#include <iostream>
#include <fstream>
#include <iomanip>
#include "../hpps/empresa.hpp"
using namespace std;

Empresa::Empresa() {}

Empresa::Empresa(string nomeEmpresa, float faturamentoMensal, string cnpj){
    this->faturamentoMensal = faturamentoMensal;
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
}

float Empresa::getFaturamentoMensal(){
    return this->faturamentoMensal; 
}

string Empresa::getNomeEmpresa(){ 
    return this->nomeEmpresa; 
}

string Empresa::getCnpj(){ 
    return this->cnpj; 
}

Pessoa* Empresa::getDono(){ 
    return Dono; 
}

vector<Vendedor> Empresa::getVendedores(){ 
    return this->vendedores; 
}

vector<Asg> Empresa::getAsg(){ 
    return this->asgs; 
}

vector<Gerente> Empresa::getGerente(){ 
    return this->gerentes; 
}

void Empresa::setFaturamentoMensal(float faturamentoMensal){
    this->faturamentoMensal = faturamentoMensal;
}

void Empresa::setNomeEmpresa(string nomeEmpresa){
    this->nomeEmpresa = nomeEmpresa;
}

void Empresa::setCnpj(string cnpj){
    this->cnpj = cnpj;
}

void Empresa::carregaFuncoes(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/funcoes.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }
        
        arquivo.close();
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == "carregarEmpresa()"){
                cout << "\nCarregando empresa..." << endl;
                carregarEmpresa();
            }else if(temp[i] == "carregarAsg()"){
                cout << "\nCarregando asgs..." << endl;
                carregarAsg();
            }else if(temp[i] == "carregarVendedor()"){
                cout << "\nCarregando vendedores..." << endl;
                carregarVendedor();
            }else if(temp[i] == "carregarGerente()"){
                cout << "\nCarregando gerentes..." << endl;
                carregarGerente();
            }else if(temp[i] == "carregaDono()"){
                cout << "\nCarregando dono..." << endl;
                carregaDono();
            }else if(temp[i] == "imprimeAsgs()"){
                imprimeAsgs();
            }else if(temp[i] == "imprimeVendedores()"){
                imprimeVendedores();
            }else if(temp[i] == "imprimeGerentes()"){
                imprimeGerentes();
            }else if(temp[i] == "imprimeDono()"){
                imprimeDono();
            }else if(temp[i] == "buscaFuncionario()"){
                string matricula = temp[i+1];
                i++;
                buscaFuncionario(matricula);
            }else if(temp[i] == "calculaSalarioFuncionario()"){
                string matricula = temp[i+1];
                i++;
                calculaSalarioFuncionario(matricula);
            }else if(temp[i] == "calculaTodoOsSalarios()"){
                calculaTodoOsSalarios();
            }else if(temp[i] == "calcularRescisao()"){
                string matricula = temp[i+1];
                Data desligamento;
                desligamento.ano = stoi(temp[i+2]);
                desligamento.mes = stoi(temp[i+3]);
                desligamento.dia = stoi(temp[i+4]);
                i+=4;
                calcularRescisao(matricula, desligamento);
            }else if(temp[i] == "contratarFuncionario()"){
                contratarFuncionario();
            }else if(temp[i] == "demitirFuncionario()"){
               string matricula = temp[i+1];
               Data desligamento;
               desligamento.ano = stoi(temp[i+2]);
               desligamento.mes = stoi(temp[i+3]);
               desligamento.dia = stoi(temp[i+4]);
               i+=4;
               demitirFuncionario(matricula,desligamento);
            }
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo de funções. Erro: " << erro.what() << endl;
    } 
}

void Empresa::carregarEmpresa(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/empresa.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        this->nomeEmpresa = temp[2];
        this->cnpj = temp[3];
        this->faturamentoMensal = stof(temp[4]);

    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo empresa.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregarAsg(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/asg.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        Asg tAsg;

        for(int i = 0; i<temp.size(); i+=26){
            tAsg.setNome(temp[i+3]);
            tAsg.setCpf(temp[i+4]);
            tAsg.setQtdFilhos(stoi(temp[i+5]));
            tAsg.setEstadoCivil(temp[i+6]);
            Endereco tEnd;
            tEnd.cidade = temp[i+8];
            tEnd.cep = temp[i+9];
            tEnd.bairro = temp[i+10];
            tEnd.rua = temp[i+11];
            tEnd.numero = stoi(temp[i+12]);
            tAsg.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+14]);
            tnasc.mes = stoi(temp[i+15]);
            tnasc.dia = stoi(temp[i+16]);
            tAsg.setDataNascimento(tnasc);
            tAsg.setMatricula(temp[i+18]);
            tAsg.setSalario(stof(temp[i+19]));
            tAsg.setAdcionalInsabubridade(stof(temp[i+20]));
            tAsg.setDiasFaltas(stoi(temp[i+21]));
            Data ting;
            ting.ano = stoi(temp[i+23]);
            ting.mes = stoi(temp[i+24]);
            ting.dia = stoi(temp[i+25]);
            tAsg.setDataingresso(ting);
            asgs.push_back(tAsg);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo de asgs.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregarVendedor(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/vendedor.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        Vendedor tVend;
        for(int i = 0; i<temp.size(); i+=26){
            tVend.setNome(temp[i+3]);
            tVend.setCpf(temp[i+4]);
            tVend.setQtdFilhos(stoi(temp[i+5]));
            tVend.setEstadoCivil(temp[i+6]);
            Endereco tEnd;
            tEnd.cidade = temp[i+8];
            tEnd.cep = temp[i+9];
            tEnd.bairro = temp[i+10];
            tEnd.rua = temp[i+11];
            tEnd.numero = stoi(temp[i+12]);
            tVend.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+14]);
            tnasc.mes = stoi(temp[i+15]);
            tnasc.dia = stoi(temp[i+16]);
            tVend.setDataNascimento(tnasc);
            tVend.setMatricula(temp[i+18]);
            tVend.setSalario(stof(temp[i+19]));
            tVend.setTipoVendedor(temp[i+20]);
            tVend.setDiasFaltas(stoi(temp[i+21]));
            Data ting;
            ting.ano = stoi(temp[i+23]);
            ting.mes = stoi(temp[i+24]);
            ting.dia = stoi(temp[i+25]);
            tVend.setDataingresso(ting);
            vendedores.push_back(tVend);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo vendedores.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregarGerente(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/gerente.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        Gerente tGer;

        for(int i = 0; i<temp.size(); i+=26){
            tGer.setNome(temp[i+3]);
            tGer.setCpf(temp[i+4]);
            tGer.setQtdFilhos(stoi(temp[i+5]));
            tGer.setEstadoCivil(temp[i+6]);
            Endereco tEnd;
            tEnd.cidade = temp[i+8];
            tEnd.cep = temp[i+9];
            tEnd.bairro = temp[i+10];
            tEnd.rua = temp[i+11];
            tEnd.numero = stoi(temp[i+12]);
            tGer.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+14]);
            tnasc.mes = stoi(temp[i+15]);
            tnasc.dia = stoi(temp[i+16]);
            tGer.setDataNascimento(tnasc);
            tGer.setMatricula(temp[i+18]);
            tGer.setSalario(stof(temp[i+19]));
            tGer.setParticipacaoLucros(stof(temp[i+20]));
            tGer.setDiasFaltas(stoi(temp[i+21]));
            Data ting;
            ting.ano = stoi(temp[i+23]);
            ting.mes = stoi(temp[i+24]);
            ting.dia = stoi(temp[i+25]);
            tGer.setDataingresso(ting);
            gerentes.push_back(tGer);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo gerente.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregaDono(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/dono.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }
        
        arquivo.close();
        for(int i = 0; i<temp.size(); i+=25){
            getDono()->setNome(temp[i+2]);
            getDono()->setCpf(temp[i+3]);
            getDono()->setQtdFilhos(stoi(temp[i+4]));
            getDono()->setEstadoCivil(temp[i+5]);
            Endereco tEnd;
            tEnd.cidade = temp[i+6];
            tEnd.cep = temp[i+7];
            tEnd.bairro = temp[i+8];
            tEnd.rua = temp[i+9];
            tEnd.numero = stoi(temp[i+10]);
            getDono()->setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+11]);
            tnasc.mes = stoi(temp[i+12]);
            tnasc.dia = stoi(temp[i+13]);
            getDono()->setDataNascimento(tnasc);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo dono.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::imprimeAsgs(){
    cout << "\n#################    ASGS    #################" <<endl;
    for(int i = 0; i<asgs.size(); i++){
        cout<< "Nome: " << asgs[i].getNome() << endl;
        cout<< "CPF: " << asgs[i].getCpf() << endl;
        cout<< "FILHOS: " << asgs[i].getQtdFilhos() << endl;
        cout<< "Estado civil: " << asgs[i].getEstadoCivil() << endl;
        cout<< "Cidade: " << asgs[i].getEndereco().cidade << endl;
        cout<< "Rua: " << asgs[i].getEndereco().rua << endl;
        cout<< "Data de nascimento: " << asgs[i].getDataNascimento().dia <<"/" << asgs[i].getDataNascimento().mes << "/" << asgs[i].getDataNascimento().ano << endl;
        cout<< "Matrícula: " << asgs[i].getMatricula() << endl;
        cout<< "Salário: " << asgs[i].getSalario() << endl;
        cout<< "Insalubridade: " << asgs[i].getAdcionalInsabubridade() << endl;
        cout<< "Data de ingresso: " << asgs[i].getDataingresso().dia <<"/" << asgs[i].getDataingresso().mes << "/" << asgs[i].getDataingresso().ano << endl;
        cout << "*****************************************" <<endl;
    }
}

void Empresa::imprimeVendedores(){
    cout << "\n##############    VENDEDORES    ##############" <<endl;
    for(int i = 0; i<vendedores.size(); i++){
        cout<< "Nome: " << vendedores[i].getNome() << endl;
        cout<< "CPF: " << vendedores[i].getCpf() << endl;
        cout<< "FILHOS: " << vendedores[i].getQtdFilhos() << endl;
        cout<< "Estado civil: " << vendedores[i].getEstadoCivil() << endl;
        cout<< "Cidade: " << vendedores[i].getEndereco().cidade << endl;
        cout<< "Rua: " << vendedores[i].getEndereco().rua << endl;
        cout<< "Data de nascimento: " << vendedores[i].getDataNascimento().dia <<"/" << vendedores[i].getDataNascimento().mes << "/" << vendedores[i].getDataNascimento().ano << endl;
        cout<< "Matrícula: " << vendedores[i].getMatricula() << endl;
        cout<< "Salário: " << vendedores[i].getSalario() << endl;
        cout<< "Tipo de vendedor: " << vendedores[i].getTipoVendedor() << endl;
        cout<< "Data de ingresso: " << vendedores[i].getDataingresso().dia <<"/" << vendedores[i].getDataingresso().mes << "/" << vendedores[i].getDataingresso().ano << endl;
        cout << "*****************************************" <<endl;
    }
}

void Empresa::imprimeGerentes(){
    cout << "\n##############    GERENTES    ##############" <<endl;
    for(int i = 0; i<gerentes.size(); i++){
        cout<< "Nome: " << gerentes[i].getNome() << endl;
        cout<< "CPF: " << gerentes[i].getCpf() << endl;
        cout<< "FILHOS: " << gerentes[i].getQtdFilhos() << endl;
        cout<< "Estado civil: " << gerentes[i].getEstadoCivil() << endl;
        cout<< "Cidade: " << gerentes[i].getEndereco().cidade << endl;
        cout<< "Rua: " << gerentes[i].getEndereco().rua << endl;
        cout<< "Data nascimento: " << gerentes[i].getDataNascimento().dia <<"/" << gerentes[i].getDataNascimento().mes << "/" << gerentes[i].getDataNascimento().ano << endl;
        cout<< "Matrícula: " << gerentes[i].getMatricula() << endl;
        cout<< "Salário: " << gerentes[i].getSalario() << endl;
        cout<< "Tipo de vendedor: " << gerentes[i].getParticipacaoLucros() << endl;
        cout<< "Data de ingresso: " << gerentes[i].getDataingresso().dia <<"/" << gerentes[i].getDataingresso().mes << "/" << gerentes[i].getDataingresso().ano << endl;
        cout << "*****************************************" <<endl;
    }
}

void Empresa::imprimeDono(){
    cout << "\n##############    DONO    ##############" <<endl;
    cout<< "Nome: " << getDono()->getNome() << endl;
    cout<< "CPF: " << getDono()->getCpf() << endl;
    cout<< "FILHOS: " << getDono()->getQtdFilhos() << endl;
    cout<< "Estado civil: " << getDono()->getEstadoCivil() << endl;
    cout<< "Cidade: " << getDono()->getEndereco().cidade << endl;
    cout<< "Rua: " << getDono()->getEndereco().rua << endl;
    cout<< "Data de nascimento: " << getDono()->getDataNascimento().dia <<"/" << getDono()->getDataNascimento().mes << "/" << getDono()->getDataNascimento().ano << endl;
    cout << "*****************************************" <<endl;
}

void Empresa::buscaFuncionario(string matricula){
    cout << "\n##########    Buscando funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            cout << "Função: ASG" << endl;
            cout << "Nome: " <<asgs[i].getNome() << endl;
            cout << "CPF: " <<asgs[i].getCpf() << endl;
            cout << "Salário base: " <<asgs[i].getSalario() << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " <<vendedores[i].getNome() << endl;
            cout << "CPF: " <<vendedores[i].getCpf() << endl;
            cout << "Salário base: " <<vendedores[i].getSalario() << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            cout << "Função: Gerente" << endl;
            cout << "Nome: " <<gerentes[i].getNome() << endl;
            cout << "CPF: " <<gerentes[i].getCpf() << endl;
            cout << "Salário base: " <<gerentes[i].getSalario() << endl;
            return;
        }
    }
    cout  << "Funcionario não localizado no sistema!" << endl;
}
void Empresa::contratarFuncionario(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/novoFuncionario.txt", ios::in);
        vector<string> temp;
        string linha;
        string categoria;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        categoria = temp[0];
        
        if(categoria == "ASG"){
            Asg novoAsg;
            
            novoAsg.setNome(temp[2]);
            novoAsg.setCpf(temp[3]);
            novoAsg.setQtdFilhos(stoi(temp[4]));
            novoAsg.setEstadoCivil(temp[5]);

            Endereco tEnd;
            tEnd.cidade = temp[7];
            tEnd.cep = temp[8];
            tEnd.bairro = temp[9];
            tEnd.rua = temp[10];
            tEnd.numero = stoi(temp[11]);
            novoAsg.setEndereco(tEnd);

            Data tNasc;
            tNasc.ano = stoi(temp[13]);
            tNasc.mes = stoi(temp[14]);
            tNasc.dia = stoi(temp[15]);
            novoAsg.setDataNascimento(tNasc);

            novoAsg.setMatricula(temp[17]);
            novoAsg.setSalario(stof(temp[18]));
            novoAsg.setAdcionalInsabubridade(stof(temp[19]));
            novoAsg.setDiasFaltas(stoi(temp[20]));

            Data tIng;
            tIng.ano = stoi(temp[22]);
            tIng.mes = stoi(temp[23]);
            tIng.dia = stoi(temp[24]);

            novoAsg.setDataingresso(tIng);
          
          fstream arquivoasg;
          arquivoasg.open("./leitura/asg.txt", ios::out | ios::app);
    arquivoasg << "#########################################################" << endl;
     arquivoasg << "ASG Nº: 4" << endl;
     arquivoasg << "##### DADOS PESSOAIS #####" << endl;
     arquivoasg << novoAsg.getNome() << endl;
     arquivoasg << novoAsg.getCpf() << endl;
     arquivoasg << novoAsg.getQtdFilhos() << endl;
     arquivoasg << novoAsg.getEstadoCivil() << endl;
     arquivoasg << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
     arquivoasg << tEnd.cidade << endl;
     arquivoasg << tEnd.cep << endl;
     arquivoasg << tEnd.bairro << endl;
     arquivoasg << tEnd.rua << endl;
     arquivoasg << tEnd.numero << endl;
     arquivoasg << "***** Data de nascimento (ano, mes, dia) ****" << endl;
     arquivoasg << tNasc.ano << endl;
     arquivoasg << tNasc.mes << endl;
     arquivoasg << tNasc.dia << endl;
     arquivoasg << "##### DADOS FUNCIONAIS #####" << endl;
     arquivoasg << novoAsg.getMatricula() << endl;
     arquivoasg << novoAsg.getSalario() << endl;
     arquivoasg << novoAsg.getAdcionalInsabubridade() << endl;
     arquivoasg << novoAsg.getDiasFaltas() << endl;
     arquivoasg << "***** Data de ingresso (ano, mes, dia) ****" << endl;
     arquivoasg << tIng.ano << endl;
     arquivoasg << tIng.mes << endl;
     arquivoasg << tIng.dia << endl;
     arquivoasg.close();
        }else if(categoria == "Vendedor"){
            Vendedor novoVendedor;

            novoVendedor.setNome(temp[2]);
            novoVendedor.setCpf(temp[3]);
            novoVendedor.setQtdFilhos(stoi(temp[4]));
            novoVendedor.setEstadoCivil(temp[5]);

            Endereco tEnd;
            tEnd.cidade = temp[7];
            tEnd.cep = temp[8];
            tEnd.bairro = temp[9];
            tEnd.rua = temp[10];
            tEnd.numero = stoi(temp[11]);
            novoVendedor.setEndereco(tEnd);

            Data tNasc;
            tNasc.ano = stoi(temp[13]);
            tNasc.mes = stoi(temp[14]);
            tNasc.dia = stoi(temp[15]);
            novoVendedor.setDataNascimento(tNasc);

            novoVendedor.setMatricula(temp[17]);
            novoVendedor.setSalario(stof(temp[18]));
            novoVendedor.setTipoVendedor(temp[19]);
            novoVendedor.setDiasFaltas(stoi(temp[20]));

            Data tIng;
            tIng.ano = stoi(temp[22]);
            tIng.mes = stoi(temp[23]);
            tIng.dia = stoi(temp[24]);

            novoVendedor.setDataingresso(tIng);
          fstream arquivovend;
          arquivovend.open("./leitura/vendedor.txt", ios::out | ios::app);
    arquivovend <<"#########################################################" << endl;
     arquivovend << "VENDEDOR Nº: 5" << endl;
     arquivovend << "##### DADOS PESSOAIS #####" << endl;
     arquivovend << novoVendedor.getNome() << endl;
     arquivovend << novoVendedor.getCpf() << endl;
     arquivovend << novoVendedor.getQtdFilhos() << endl;
     arquivovend << novoVendedor.getEstadoCivil() << endl;
     arquivovend << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
     arquivovend << tEnd.cidade << endl;
     arquivovend << tEnd.cep << endl;
     arquivovend << tEnd.bairro << endl;
     arquivovend << tEnd.rua << endl;
     arquivovend << tEnd.numero << endl;
     arquivovend << "***** Data de nascimento (ano, mes, dia) ****" << endl;
     arquivovend << tNasc.ano << endl;
     arquivovend << tNasc.mes << endl;
     arquivovend << tNasc.dia << endl;
     arquivovend << "##### DADOS FUNCIONAIS #####" << endl;
     arquivovend << novoVendedor.getMatricula() << endl;
     arquivovend << novoVendedor.getSalario() << endl;
     arquivovend << novoVendedor.getTipoVendedor() << endl;
     arquivovend << novoVendedor.getDiasFaltas() << endl;
     arquivovend << "***** Data de ingresso (ano, mes, dia) ****" << endl;
     arquivovend << tIng.ano << endl;
     arquivovend << tIng.mes << endl;
     arquivovend << tIng.dia << endl;
     arquivovend.close();
        }else if(categoria == "Gerente"){
            Gerente novoGerente;

            novoGerente.setNome(temp[2]);
            novoGerente.setCpf(temp[3]);
            novoGerente.setQtdFilhos(stoi(temp[4]));
            novoGerente.setEstadoCivil(temp[5]);

            Endereco tEnd;
            tEnd.cidade = temp[7];
            tEnd.cep = temp[8];
            tEnd.bairro = temp[9];
            tEnd.rua = temp[10];
            tEnd.numero = stoi(temp[11]);
            novoGerente.setEndereco(tEnd);

            Data tNasc;
            tNasc.ano = stoi(temp[13]);
            tNasc.mes = stoi(temp[14]);
            tNasc.dia = stoi(temp[15]);
            novoGerente.setDataNascimento(tNasc);

            novoGerente.setMatricula(temp[17]);
            novoGerente.setSalario(stof(temp[18]));
            novoGerente.setParticipacaoLucros(stof(temp[19]));
            novoGerente.setDiasFaltas(stoi(temp[20]));

            Data tIng;
            tIng.ano = stoi(temp[22]);
            tIng.mes = stoi(temp[23]);
            tIng.dia = stoi(temp[24]);

            novoGerente.setDataingresso(tIng);

            fstream arquivoger;
            arquivoger.open("./leitura/gerente.txt", ios::out | ios::app);
             arquivoger <<"#########################################################" << endl;
     arquivoger << "VENDEDOR Nº: 5" << endl;
     arquivoger << "##### DADOS PESSOAIS #####" << endl;
     arquivoger << novoGerente.getNome() << endl;
     arquivoger << novoGerente.getCpf() << endl;
     arquivoger << novoGerente.getQtdFilhos() << endl;
     arquivoger << novoGerente.getEstadoCivil() << endl;
     arquivoger << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
     arquivoger << tEnd.cidade << endl;
     arquivoger << tEnd.cep << endl;
     arquivoger << tEnd.bairro << endl;
     arquivoger << tEnd.rua << endl;
     arquivoger << tEnd.numero << endl;
     arquivoger << "***** Data de nascimento (ano, mes, dia) ****" << endl;
     arquivoger << tNasc.ano << endl;
     arquivoger << tNasc.mes << endl;
     arquivoger << tNasc.dia << endl;
     arquivoger << "##### DADOS FUNCIONAIS #####" << endl;
     arquivoger << novoGerente.getMatricula() << endl;
     arquivoger << novoGerente.getSalario() << endl;
     arquivoger << novoGerente.getParticipacaoLucros() << endl;
     arquivoger << novoGerente.getDiasFaltas() << endl;
     arquivoger << "***** Data de ingresso (ano, mes, dia) ****" << endl;
     arquivoger << tIng.ano << endl;
     arquivoger << tIng.mes << endl;
     arquivoger << tIng.dia << endl;
     arquivoger.close();
        }else{
            cout << "Não foi possivel encontrar esse tipo de categoria na empresa." << endl;
            return;
        }

    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo do novo funcionário.txt Erro: " << erro.what() << endl;
        return;
    }
}

void Empresa::calculaSalarioFuncionario(string matricula){
    cout << "\n##########    Calculando salário de funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            cout << "Função: ASG" << endl;
            cout << "Nome: " << asgs[i].getNome() << endl;
            cout << "Salario base: " << asgs[i].getSalario() << endl;
            cout << "Salario calculado: " << asgs[i].calcularSalario(asgs[i].getDiasFaltas()) << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " << vendedores[i].getNome() << endl;
            cout << "Salario base: " << vendedores[i].getSalario() << endl;
            cout << "Salario calculado: " << vendedores[i].calcularSalario(vendedores[i].getDiasFaltas()) << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            cout << "Função: Gerente" << endl;
            cout << "Nome: " << gerentes[i].getNome() << endl;
            cout << "Salario base: " << gerentes[i].getSalario() << endl;
            cout << "Salario calculado: " << gerentes[i].calcularSalario(gerentes[i].getDiasFaltas()) << endl;
            return;
        }
    }
    cout  << "Funcionario não localizado no sistema!" << endl;
}

void Empresa::calculaTodoOsSalarios(){

    fstream relatorio;
    relatorio.open("./escrita/relatorioFinanceiro.txt", ios::out);

    float soma = 0, somaAsg = 0, somaVend = 0, somaGer = 0;

    cout << "\n##########    Calculando todos os salários    ##########" <<endl;
    relatorio << "##########    ASGS    ##########" << endl;
    for(int i = 0; i<asgs.size() ;i++){
        relatorio << "Nome: " << asgs[i].getNome() << " - R$ " << asgs[i].getSalario() << endl; 
        somaAsg += asgs[i].calcularSalario(asgs[i].getDiasFaltas());
        soma += somaAsg;
    }
    relatorio << "Soma ASGs: " <<somaAsg << endl;
    relatorio << "\n##########    Vendedores    ##########" << endl;
    for(int i = 0; i<vendedores.size() ;i++){
        relatorio << "Nome: " << vendedores[i].getNome() << " - R$ " << vendedores[i].getSalario() << endl; 
        somaVend += vendedores[i].calcularSalario(vendedores[i].getDiasFaltas());
        soma += somaVend;
    }
    relatorio << "Soma Vendedores: " << somaVend << endl;
    relatorio << "\n##########    Gerentes    ##########" << endl;
    for(int i = 0; i<gerentes.size() ;i++){
        relatorio << "Nome: " << gerentes[i].getNome() << " - R$ " << gerentes[i].getSalario() << endl; 
        somaGer += gerentes[i].calcularSalario(gerentes[i].getDiasFaltas());
        soma += somaGer;
    }
    relatorio << "Soma Gerentes: " << somaGer << endl;
    relatorio << endl;
    relatorio << "**************************** " << endl;
    relatorio << "Soma de salarios: " << soma << endl;
    relatorio << "**************************** " << endl;
    
    cout  << "Soma dos salarios calculados: "<< soma << endl;
    relatorio << "Faturamento Mensal da Empresa: " << getFaturamentoMensal() << endl;
   float porcentagemAsg = (somaAsg/getFaturamentoMensal())*100;
   float porcentagemVendedor = (somaVend/getFaturamentoMensal())*100;
   float porcentagemGerente = (somaGer/getFaturamentoMensal())*100;
   
   relatorio << "porcentagem do custo dos Asgs: " << setprecision(2) << porcentagemAsg << "%" << endl;
   relatorio << "porcentagem do custo dos Vendedores: " << setprecision(2) << porcentagemVendedor << "%" << endl;
   relatorio << "porcentagem do custo dos Gerentes: " << setprecision(2) << porcentagemGerente << "%" << endl;
   if(getFaturamentoMensal() - soma > 0){
     relatorio << "A EMPRESA TEVE LUCRO ESSE MES" << endl;
   }else{
     relatorio << "A EMPRESA TEVE PREJUIZO ESSE MES" << endl;
   }
}
void Empresa::calcularRescisao(string matricula, Data desligamento){
    cout << "\n##########    Calculando a rescisão de funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            cout << "Função: ASG" << endl;
            cout << "Nome: " << asgs[i].getNome() << endl;
            cout << "Salario base: " << asgs[i].getSalario() << endl;
            cout << "Rescisão calculada: " << asgs[i].calcularRecisao(desligamento) << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " << vendedores[i].getNome() << endl;
            cout << "Salario base: " << vendedores[i].getSalario() << endl;
            cout << "Rescisão calculada: " << vendedores[i].calcularRecisao(desligamento) << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            cout << "Função: Gerente" << endl;
            cout << "Nome: " << gerentes[i].getNome() << endl;
            cout << "Salario base: " << gerentes[i].getSalario() << endl;
            cout << "Rescisão calculada: " << gerentes[i].calcularRecisao(desligamento) << endl;
            return;
        }
    }
    cout  << "Funcionario não localizado no sistema!" << endl;
}

void Empresa::demitirFuncionario(string matricula, Data desligamento){
  try{
  fstream arquivo;
  arquivo.open("./escrita/relatoriodemissional.txt", ios::out);
  arquivo << "##############################" << endl;
  arquivo << "Relatorio Demissional" << endl;
  arquivo << "##############################" << endl; 
  for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            arquivo << "Função: ASG" << endl;
            arquivo << "Nome: " <<asgs[i].getNome() << endl;
            arquivo << "CPF: " <<asgs[i].getCpf() << endl;
            arquivo << "Matricula: " <<asgs[i].getMatricula() << endl;
            arquivo << "******************************" << endl;
            arquivo << "valor da rescisão: " << asgs[i].calcularRecisao(desligamento) << endl;
            arquivo << "******************************" << endl;
            arquivo << "tempo de trabalho: " << desligamento.ano - asgs[i].getDataingresso().ano << " anos ," << desligamento.mes - asgs[i].getDataingresso().mes << " meses e " << desligamento.dia - asgs[i].getDataingresso().dia << " dias";
            return;
        }
  }
  for(int i=0; i<vendedores.size(); i++){
    if(matricula == vendedores[i].getMatricula()){
      arquivo << "Função: Vendedor" << endl;
      arquivo << "Nome: " << vendedores[i].getNome() << endl;
      arquivo << "CPF: " << vendedores[i].getCpf() << endl;
      arquivo << "Matricula: " << vendedores[i].getMatricula() << endl;
      arquivo << "******************************" << endl;
      arquivo << "valor da rescisão: " <<vendedores[i].calcularRecisao(desligamento) << endl;
      arquivo << "******************************" << endl;
      arquivo << "tempo de trabalho: " << desligamento.ano - vendedores
        [i].getDataingresso().ano << " anos," << desligamento.mes - vendedores[i].getDataingresso().mes << " meses e " << desligamento.dia - vendedores[i].getDataingresso().dia << " dias";
      return;
    }
  }
  for(int i=0; i<gerentes.size(); i++){
    if(matricula == gerentes[i].getMatricula()){
      arquivo << "Função: Gerente" << endl;
      arquivo << "Nome: " << gerentes[i].getNome() << endl;
      arquivo << "CPF: " << gerentes[i].getCpf() << endl;
      arquivo << "Matricula: " << gerentes[i].getMatricula() << endl;
      arquivo << "******************************" << endl;
      arquivo << "valor da rescisão: " <<gerentes[i].calcularRecisao(desligamento) << endl;
      arquivo << "******************************" << endl;
      arquivo << "tempo de trabalho: " << desligamento.ano - gerentes[i].getDataingresso().ano << "anos," << desligamento.mes - gerentes[i].getDataingresso().mes << "meses e" << desligamento.dia - gerentes[i].getDataingresso().dia << "dias";
      return;    
    }
  }
    arquivo.close();
   }catch(exception &error){
        cout<< "Não foi possivel abrir o arquivo relatoriofinanceiro.txt"<< error.what() << endl;
    }
}