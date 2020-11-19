#include <vector>
#include <lexer.hpp>
#include <arbol.hpp>

namespace analizador{
    class parser{
        std::vector<lexer::Token> genVector();
        std::string leerLiteral(std::istream& s);
    };
}

