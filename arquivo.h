#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <vector>
#include <map>
#include <string>


using std::vector;
using std::string;
using std::map;

class arquivo
{
private:
            
    static map<string, vector<string>> indiceInvertido;
			
	static vector<string> formataLinha(string linha);
			
	string enterdata;

    friend class Teste;

public:
        
    arquivo(string enterdata);
    
    bool consulta (vector<string>& resultado, const string& palavra);

    static vector<string> tratamento(string line);

    ~arquivo();
};

#endif