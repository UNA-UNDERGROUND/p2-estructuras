#include "lexer.hpp"
#include <iostream>
#include <parser.hpp>
#include <tokens.hpp>
#include <util.hpp>

namespace analizador {

Parser::Parser() { inicializar(); }

std::vector<lexer::Token> Parser::genVector(std::istream &is) {
	noskipws(is);
	std::vector<lexer::Token> tokens;

	for (char c : istream_it<char>(is)) {
		if (c == '\n') {
			posColumna = 0;
			posLinea++;
			continue;
		}
		posColumna++;
		buffer = c;

		if (isalpha(c)) {

			tokens.push_back(leerPalabra(is));
		} else if (isdigit(c)) {

			tokens.push_back(leerNumero(is));
		} else if (c == '"') {
			tokens.push_back(leerLiteral(is));
		} else if (!isspace(c)) {
			tokens.push_back(leerSimbolo(is));
		}
	}

	return tokens;
}

// lee una palabra
lexer::Token Parser::leerPalabra(std::istream &is) {
	if (isalnum(is.peek())) {
		for (char c : istream_it<char>(is)) {
			posColumna++;

			if (isalnum(c)) {
				buffer += c;
			} else if (isspace(c)) {
				if (c == '\n') {
					posColumna = 0;
					posLinea++;
				}
				break;
			}
			// simbolo inesperado
			char sig = is.peek();
			if (sig == EOF || (!isalnum(sig))) {
				break;
			}
		}
	}


	if (mapaToken.find(buffer) != mapaToken.end()) {
		lexer::Token t = mapaToken.at(buffer);
		t.pos.caracter = posColumna;
		t.pos.linea = posLinea;
		return t;
	} else {
		return lexer::Token(lexer::TokenPos(posLinea, posColumna),
		                    lexer::CatToken::identificador,
		                    lexer::TipoToken::identificador, buffer);
	}
}
// lee una cadena literal ejemplo = "hola mundo"
// cuenta las comillas pero no las incluye
lexer::Token Parser::leerLiteral(std::istream &is) {
	for (char c : istream_it<char>(is)) {
		posColumna++;
		if (c == '\n') {
			posColumna = 0;
			posLinea++;
			break;
		}
		buffer += c;
		if (c == '"') {
			break;
		}
	}
	return lexer::Token(lexer::TokenPos(posLinea, posColumna),
	                    lexer::CatToken::literal, lexer::TipoToken::string,
	                    buffer);
}
lexer::Token Parser::leerNumero(std::istream &is) {
	char sig = is.peek();
	if (isdigit(sig) || sig == '.') {
		bool esFloat = sig == '.';
		if (esFloat) {
			buffer += ".";
		}
		for (char c : istream_it<char>(is)) {
			posColumna++;
			if (isalnum(c) || (c == '.' && !esFloat)) {
				esFloat = true;
				buffer += c;
			} else if (isspace(c)) {
				if (c == '\n') {
					posColumna = 0;
					posLinea++;
				}
				break;
			}
			// simbolo inesperado
			sig = is.peek();
			if (sig == EOF || (!isdigit(sig) && !(sig == '.' && esFloat))) {
				break;
			}
		}
	}
	return lexer::Token(lexer::TokenPos(posLinea, posColumna),
	                    lexer::CatToken::numerico, lexer::TipoToken::numero,
	                    buffer);
}
lexer::Token Parser::leerSimbolo(std::istream &is) {
	// revisar si viene un proximo =
	if (buffer == "<" || buffer == ">" || buffer == "!" || buffer == "=") {
		// solo revisaremos si es un espacio o directamente es el =
		if (isspace(is.peek()) || is.peek() == '=') {
			for (char c : istream_it<char>(is)) {
				posColumna++;
				if (isspace(c)) {
					if (c == '\n') {
						posColumna = 0;
						posLinea++;
					}
					break;
				}
				if (c == '=') {
					buffer += c;
					break;
				}
			}
		}
	}
	if (mapaToken.find(buffer) != mapaToken.end()) {
		lexer::Token t = mapaToken.at(buffer);
		t.pos.caracter = posColumna;
		t.pos.linea = posLinea;
		return t;
	} else {
		return lexer::Token(lexer::TokenPos(posLinea, posColumna),
		                    lexer::CatToken::otro, lexer::TipoToken::indefinido,
		                    buffer);
	}
}
} // namespace analizador
