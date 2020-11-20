#include <iostream>
#include <parser.hpp>
#include <util.hpp>

namespace analizador {
std::vector<lexer::Token> Parser::genVector(std::istream &is) {
	noskipws(is);
	std::vector<lexer::Token> tokens;

	for (char c : istream_it<char>(is)) {
		if (c == '\n') {
			posLinea = 0;
			posColumna++;
			continue;
		}
		posLinea++;
		buffer = c;

		switch (estado) {
		case Estado::ninguno: {
			if (isalpha(c)) {
				estado = Estado::literal;
				leerPalabra(is);
			} else if (isdigit(c)) {
				estado = Estado::numero;
				leerNumero(is);
			} else if (c == '"') {
				estado = Estado::literal;
			}
		} break;
		default:
			break;
		}
	}

	return tokens;
}

// lee una palabra
void Parser::leerPalabra(std::istream &is) {
	for (char c : istream_it<char>(is)) {
		posLinea++;
		if (isalnum(c)) {
			buffer += c;
		} else if (isspace(c)) {
			break;
		}
		// simbolo inesperado
		else {
			buffer += c;
			break;
		}
	}
	estado = Estado::ninguno;
	std::cout << "identificador: " << buffer << "\n";
}
// lee una cadena literal ejemplo = "hola mundo"
// cuenta las comillas pero no las incluye
void Parser::leerLiteral(std::istream &is) {
	for (char c : istream_it<char>(is)) {
		posLinea++;
		if (isalnum(c)) {
			buffer += c;
		} else if (isspace(c)) {
			break;
		}
		// simbolo inesperado
		else {
			buffer += c;
			break;
		}
	}
	estado = Estado::ninguno;
	std::cout << "identificador: " << buffer << "\n";
}
void Parser::leerNumero(std::istream& is) {
	for (char c : istream_it<char>(is)) {
		posLinea++;
		if (isalnum(c) || c == '.') {
			buffer += c;
		} else if (isspace(c)) {
			break;
		}
		// simbolo inesperado
		char sig = is.peek();
		if(sig == EOF || (!isdigit(c) && c != '.')){
			break;
		}
	}
	estado = Estado::ninguno;
	std::cout << "numero: " << buffer << "\n";
}
} // namespace analizador
