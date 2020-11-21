#include <vector>
#include <lexer.hpp>
#include <arbol.hpp>

namespace analizador{
	class Parser{
		
		std::string buffer;
		size_t posLinea = 0;
		size_t posColumna = 0;

		lexer::Token leerPalabra(std::istream& is);
		lexer::Token leerLiteral(std::istream& is);
		lexer::Token leerNumero(std::istream& is);
	    lexer::Token leerSimbolo(std::istream &is);
		
		public:
		Parser();
		std::vector<lexer::Token> genVector(std::istream& is);
		
	};
}

