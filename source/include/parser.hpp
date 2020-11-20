#include <vector>
#include <lexer.hpp>
#include <arbol.hpp>

namespace analizador{
	class Parser{
		enum class Estado{
			ninguno,		//estado general
			identificador,	//nombres
			literal,		//"string"
			numero			//1234
		};
		Estado estado = Estado::ninguno;
		std::string buffer;
		size_t posLinea = 0;
		size_t posColumna = 0;

		void leerPalabra(std::istream& is);
		void leerLiteral(std::istream& is);
		void leerNumero(std::istream& is);
		
		public:
		std::vector<lexer::Token> genVector(std::istream& is);
		
	};
}

