#include <tokens.hpp>

namespace analizador {
std::unordered_map<std::string, lexer::Token> mapaToken;
void inicializar() {
	static bool inicializado = false;
	if(inicializado){
		return;
	}
	inicializado = true;


	using lexer::CatToken;
	using lexer::TipoToken;
	using lexer::Token;
	using lexer::TokenPos;
	TokenPos tp;
	// identificador
	// tipo
	mapaToken.emplace("void",
	                  Token(tp, CatToken::tipo, TipoToken::tipo, "void"));
	mapaToken.emplace("int", Token(tp, CatToken::tipo, TipoToken::tipo, "int"));
	mapaToken.emplace("float",
	                  Token(tp, CatToken::tipo, TipoToken::tipo, "float"));
	mapaToken.emplace("string",
	                  Token(tp, CatToken::tipo, TipoToken::tipo, "string"));
	// asignacion
	mapaToken.emplace(
	    "=", Token(tp, CatToken::asignacion, TipoToken::asignacion, "="));
	// comparacion
	mapaToken.emplace("==",
	                  Token(tp, CatToken::comparacion, TipoToken::igual, "=="));
	mapaToken.emplace(
	    "!", Token(tp, CatToken::comparacion, TipoToken::negacion, "!"));
	mapaToken.emplace(
	    ">=", Token(tp, CatToken::comparacion, TipoToken::mayorIgual, ">="));
	mapaToken.emplace(
	    "<=", Token(tp, CatToken::comparacion, TipoToken::menorIgual, "<="));
	mapaToken.emplace(
	    "!=", Token(tp, CatToken::comparacion, TipoToken::diferente, "!="));
	// aritmetico
	mapaToken.emplace("+",
	                  Token(tp, CatToken::aritmetico, TipoToken::mas, "+"));
	mapaToken.emplace("-",
	                  Token(tp, CatToken::aritmetico, TipoToken::menos, "-"));
	mapaToken.emplace(
	    "*", Token(tp, CatToken::aritmetico, TipoToken::asterisco, "*"));
	mapaToken.emplace("/",
	                  Token(tp, CatToken::aritmetico, TipoToken::slash, "/"));
	// numerico (N/A)
	// literal (N/A)
	// llave
	mapaToken.emplace(
	    "(", Token(tp, CatToken::llave, TipoToken::parentesisIzquierdo, "("));
	mapaToken.emplace(
	    ")", Token(tp, CatToken::llave, TipoToken::parentesisDerecho, ")"));
	mapaToken.emplace(
	    "[", Token(tp, CatToken::llave, TipoToken::cuadIzquierdo, "["));
	mapaToken.emplace("]",
	                  Token(tp, CatToken::llave, TipoToken::cuadDerecho, "]"));
	mapaToken.emplace(
	    "{", Token(tp, CatToken::llave, TipoToken::llaveIzquierda, "{"));
	mapaToken.emplace("}",
	                  Token(tp, CatToken::llave, TipoToken::llaveDerecha, "}"));
	// otro
	mapaToken.emplace(";",
	                  Token(tp, CatToken::otro, TipoToken::puntoComa, ";"));
	mapaToken.emplace(",",
	                  Token(tp, CatToken::otro, TipoToken::coma, ","));
}
} // namespace analizador
