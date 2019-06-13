#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Arquivo.h"

//construtor
map<string, vector<string>> arquivo::indiceInvertido;


arquivo::arquivo(string nomeArquivo){

    enterdata =  nomeArquivo;

    std :: ifstream arquivoentrada;

    arquivoentrada.open(enterdata);

    string linhadentrada;

    if (arquivoentrada.is_open()){
    //faz a leitura dos arquivos
    while(getline(arquivoentrada,linhadentrada)){
        
        vector <string> texto = this->tratamento(linhadentrada);
        
        for(vector<string>::iterator palavra = texto.begin(); palavra != texto.end(); ++palavra){

                map<string, vector<string>>::iterator chave = arquivo::indiceInvertido.find(*palavra);
				if(chave != arquivo::indiceInvertido.end())
				{
					if(std::find(chave->second.begin(), chave->second.end(), this-> enterdata) == chave->second.end())
					{
						vector<string>::iterator vecArquivos = chave->second.end();
						chave->second.insert(vecArquivos, this->enterdata);
					}
				}
				else
				{
					vector<string> novoValor {this->enterdata};
					arquivo::indiceInvertido.insert(std::pair<string, vector<string>>(*palavra, novoValor));
				}
        }

    }
    }
    else{
        if (nomeArquivo != ""){  
    std::cout<< "problema na leitura do arquivo"<<std::endl;
        }
    }


    arquivoentrada.close();
}

vector<string> arquivo::tratamento(string line){
        // Deixa todas os caracteres minusculos e retira as pontuações
        for(int i = 0; line[i]; i++)
		{
			line[i] = tolower(line[i]);
            if(!((line[i] >= 30 && line[i] <= 39) ||(line[i] >= 97 && line[i] <= 122) )){
                  while(!((line[i] >= 97 && line[i] <= 122)|| line[i] <= 32 )){
                            line.erase(i,1);         
                            }
           }
		}  
        // separa palavras
        string word;
        std::stringstream x(line);
        vector<string> saida;
        while( x >> word){
            saida.push_back(word);
        }

        return saida;
}

bool arquivo::consulta(vector<string>& resultado, const string& palavra)
	{
		std::map<string, vector<string>>::iterator busca;
		busca = arquivo::indiceInvertido.find(palavra);
		std::cout << "Pesquisando por: '" << palavra << "'" << std::endl;
		if(busca != arquivo::indiceInvertido.end())
		{
			resultado = busca->second;
			return true;
		}
		else
		{
			return false;
		}
}

arquivo::~arquivo(){
    indiceInvertido.clear();
}