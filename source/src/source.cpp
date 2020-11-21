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
    std::vector<Token> tokens = parser.genVector(archivo);
    Arbol<Token> arbol;
    
    std::cout << " ---- elementos del arbol ----\n";
    for (const Token& t: tokens){
        std::cout << t.toString() << "\n";
    }
    std::cout << " -----------------------------\n";
	std::vector<std::string> errores =
		analizador::lexer::generarArbol(tokens, arbol);
    for (const auto& error: errores){
        std::cout << "Error: " << error << "\n";
    }
    
	} else {
		std::cout << "Error: "
		          << "no se encontro el archivo\n";
	}
}