#include <iostream>
#include <parser.hpp>
#include <util.hpp>

namespace analizador {
std::vector<lexer::Token> Parser::genVector(std::istream &is) {
	std::vector<lexer::Token> tokens;

	for (char c : istream_it<char>(is)) {
		if (c == '\n') {
			posLinea = 0;
			posColumna++;
			continue;
		}
		posLinea++;
		std::cout << c;

		switch (estado) {
		case Estado::ninguno: {
			if (isalpha(c)) {
				estado = Estado::literal;
			} else if (isdigit(c)) {
				estado = Estado::numero;
			} else if (c == '"') {
				estado = Estado::literal;
			}
		}
		break;
		case Estado::identificador: {
			
		}
		break;
		default:
			break;
		}
	}

	return tokens;
}

// lee una palabra
std::string Parser::leerPalabra(std::istream &is) { return ""; }
// lee una cadena literal ejemplo = "hola mundo"
// cuenta las comillas pero no las incluye
std::string Parser::leerLiteral(std::istream &s) { return ""; }
} // namespace analizador
