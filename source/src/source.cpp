#include <iostream>
#include <lexer.hpp>
#include <parser.hpp>
#include <arbol.hpp>
#include <fstream>

using analizador::lexer::Token;
using analizador::lexer::TokenPos;
using analizador::lexer::TipoToken;
using analizador::Parser;


bool test1() {
    Arbol<Token> arbol(new Token(TokenPos()));
    return arbol.raiz->valor->tipo == analizador::lexer::TipoToken::indefinido;
}


int main(){
    Parser parser;
    std::ifstream archivo("codigo");
	if (archivo) {
    parser.genVector(archivo);
	} else {
		std::cout << "Error: "
		          << "no se encontro el archivo\n";
	}
}