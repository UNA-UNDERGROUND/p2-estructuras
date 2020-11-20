#include <iostream>
#include <lexer.hpp>
#include <parser.hpp>
#include <arbol.hpp>
#include <fstream>

using analizador::lexer::Token;
using analizador::Parser;


bool test1() {
    Arbol<Token> arbol;
    arbol.raiz->valor = std::make_unique<Token>(Token());
    return arbol.raiz->valor->tipoToken == analizador::lexer::TipoToken::indefinido;
}


int main(){
    Parser parser;
    std::ifstream archivo("codigo");
    noskipws(archivo);
    parser.genVector(archivo);
}