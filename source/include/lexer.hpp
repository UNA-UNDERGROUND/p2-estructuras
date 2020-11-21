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
	ciclo_while,         // while(cond)
	indefinido           // otro / nulo
};
enum class CatToken {
	identificador, // abc
	tipo,          // void int float string
	asignacion,    // =
	comparacion,   // >= <= !=
	aritmetico,    // + - * /
	numerico,      // 123.45
	literal,       // "hola mundo"
	llave,         // {} [] ()
	otro,          // ; ,
	indefinido     // indefinido
};

struct TokenPos {
	size_t linea = -1;
	size_t caracter = -1;
	TokenPos() = default;
	TokenPos(size_t linea, size_t caracter)
	    : linea(linea), caracter(caracter){};
	TokenPos(const TokenPos &otro)
	    : linea(otro.linea), caracter(otro.caracter){};

	TokenPos &operator=(const TokenPos &otro) {
		linea = otro.linea;
		caracter = otro.caracter;
		return *this;
	};
};

class Token {
  public:
	TokenPos pos;
	const CatToken categoria = CatToken::indefinido;
	const TipoToken tipo = TipoToken::indefinido;

	const std::string contenido;
	explicit Token(){};
	Token(const TokenPos &pos, const CatToken categoria = CatToken::indefinido,
	      const TipoToken tipo = TipoToken::indefinido,
	      const std::string contenido = "")
	    : pos(pos), categoria(categoria), tipo(tipo), contenido(contenido){};

	std::string toString() const;
};
} // namespace lexer
} // namespace analizador

std::ostream &operator<<(std::ostream &os,
                         const analizador::lexer::TipoToken tp);
std::ostream &operator<<(std::ostream &os,
                         const analizador::lexer::CatToken tp);