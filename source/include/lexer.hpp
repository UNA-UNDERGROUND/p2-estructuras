#pragma once
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

namespace analizador {
namespace lexer {

enum class TipoToken {
	numero,              // 12
	tipo,                // int, float, bool, string
	identificador,       // variable
	asignacion,          // =
	string,              // "Hola Mundo"
	parentesisIzquierdo, //	(
	parentesisDerecho,   // )
	cuadDerecho,         // [
	cuadIzquierdo,       // ]
	llaveDerecha,        // {
	llaveIzquierda,      // }
	mayor,               // >
	menor,               // <
	igual,               // ==
	negacion,            // !
	mayorIgual,          // >=
	menorIgual,          // <=
	diferente,           // !=
	mas,                 // +
	menos,               // -
	asterisco,           // *
	slash,               // /
	punto,               // .
	coma,                // ,
	dosPuntos,           // :
	puntoComa,           // ;
	comillaSimple,       // '
	comillaDoble,        // "
	amperson,            // &
	pleca,               // |
	cond_if,             // if
	cond_else,           // else
	cond_switch,         // switch(cond)
	cond_case,           // case <val>
	cliclo_for,          // for(var;cond;incr)
	ciclo_while          // while(cond)
};

class TokenPos {
	const size_t linea;
	const size_t caracter;

  public:
	TokenPos(size_t linea, size_t caracter)
	    : linea(linea), caracter(caracter){};
	const size_t getlinea() { return linea; }
	const size_t getCaracter() { return caracter; }
};

class Token {
	const TokenPos pos;
	const TipoToken tipoToken;
	const std::string_view contenido;

  public:
	Token(const TokenPos &pos, TipoToken tipoToken,
	      const std::string_view &contenido)
	    : pos(pos), tipoToken(tipoToken), contenido(contenido){};
};
} // namespace lexer
} // namespace analizador