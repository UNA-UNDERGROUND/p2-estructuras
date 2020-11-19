#include <iostream>
#include <lexer.hpp>
#include <parser.hpp>
#include <arbol.hpp>

using analizador::lexer::Token;
using std::cout;


int main() {
    Arbol<Token> arbol;
    arbol.raiz->valor = std::make_unique<Token>(Token());
    bool res = arbol.raiz->valor->tipoToken == analizador::lexer::TipoToken::indefinido;
    cout << (res ? "verdadero": "falso") << "\n";
}