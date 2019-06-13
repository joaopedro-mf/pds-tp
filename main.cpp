#include <string>
#include <iostream>
#include <vector>
#include <dirent.h>
#include "arquivo.h"
#include "arquivo.cpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;

void mostraResultado(vector<string> resultado);

string tratamentoentrada(string searchword);

int main (int argc, char *argv[]){
 		arquivo selection("");
 for (int a=0; a< argc; a++){
		cout << "Para o arquivo: " << a << endl; 
    	cout <<argv[a] << endl;
        selection = arquivo (argv[a]); 
 	}
 

 
 string searchword;
 vector<string> result;

 while(1)
	{
		std::cout << "Digite a palavra desejada ou digite 'SAIR' para encerrar programa)" << std::endl;
		std::cin >> searchword;

		if(searchword == "SAIR" || searchword == "sair")
		{
			break;
		}
		searchword = tratamentoentrada(searchword);

		bool existe = selection.consulta(result, searchword);

		if(existe)
		{
			std::cout << "Palavra existe nos seguintes arquivos: " << std::endl;
			mostraResultado(result);
		}
		else
		{
			std::cout << "Palavra nao existe nos arquivos!" << std::endl ;
            std::cout << "\n" ; 
		}
	}
	return 1;
    
}

void mostraResultado(vector<string> resultado)
{
	for (vector<string>::iterator res = resultado.begin() ; res != resultado.end(); ++res)
	{
		std::cout << *res << std::endl;
	}
	std::cout << "\n" ;
}


string tratamentoentrada(string searchworld)
{

	 for(int i = searchworld.length(); i >= 0 ; i--){
			searchworld[i]=tolower(searchworld[i]);
            if(!((searchworld[i] >= 97 && searchworld[i] <= 122)||searchworld[i] == 32 )){
            searchworld.erase(i,1);
			}
	}
	return searchworld;
}