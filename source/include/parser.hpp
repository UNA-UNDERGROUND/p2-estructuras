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
		Estado estado;
		std::string buffer;
		size_t posLinea = 0;
		size_t posColumna = 0;

		void leerPalabra(std::istream& is);
		void leerLiteral(std::istream& s);
		public:
		std::vector<lexer::Token> genVector(std::istream& is);
		
	};
}

