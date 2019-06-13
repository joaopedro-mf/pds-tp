#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "arquivo.h"
#include "doctest.h"
#include <fstream>

class Teste
{
public:
  static string enterdata(const arquivo &e)
  {
    return e.enterdata;
  }
  static vector<string> formatalinha(const arquivo &f)
  {
    return f.formataLinha;
  }
  static map<string,vector<string>>indiceInvertido(const arquivo &i){
      return i.indiceInvertido;
  }
};

TEST_SUITE("arquivo")
{
  TEST_CASE ("arquivo::arquivo(string)"){
    Ofstream database;
    database.open("database.txt");
    arquivo documento();
    CHECK(Teste::enterdata(documento,)=="teste");
    CHECK(Teste::formatalinha(documento)== vector<"database.txt">);
    CHECK(Teste::indiceInvertido(documento)== map<teste,vector<database>>);
  }
}