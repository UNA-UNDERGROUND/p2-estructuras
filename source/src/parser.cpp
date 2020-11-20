#include <iostream>
#include <parser.hpp>
#include <tokens.hpp>
#include <util.hpp>

namespace analizador {

Parser::Parser() {
	static bool Inicializado = false;
	if (!Inicializado) {
		Inicializado = true;
		inicializar();
	}
}

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
				leerLiteral(is);
			} else if (!isspace(c)) {
				estado = Estado::simbolo;
				leerSimbolo(is);
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
		if (sig == EOF || (!isalnum(c))) {
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
	estado = Estado::ninguno;
	std::cout << "identificador: " << buffer << "\n";
}
void Parser::leerNumero(std::istream &is) {
	for (char c : istream_it<char>(is)) {
		posColumna++;
		if (isalnum(c) || c == '.') {
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
		if (sig == EOF || (!isdigit(c) && c != '.')) {
			break;
		}
	}
	estado = Estado::ninguno;
	std::cout << "numero: " << buffer << "\n";
}
void Parser::leerSimbolo(std::istream &is) {
	//revisar si viene un proximo =
	if (buffer == "<" || buffer == ">" || buffer == "!" || buffer == "=") {
		//solo revisaremos si es un espacio o directamente es el =
		if(isspace(is.peek()) || is.peek() == '='){
			for (char c : istream_it<char>(is)) {
			posColumna++;
			if (isspace(c)) {
				if (c == '\n') {
					posColumna = 0;
					posLinea++;
				}
				break;
			}
			if(c == '='){
				buffer += c;
				break;
			}
			
		}
		}
	}

	estado = Estado::ninguno;
	std::cout << "simbolo: " << buffer << "\n";
}
} // namespace analizador
