#include <iomanip>
#include <lexer.hpp>
#include <ostream>
#include <sstream>
namespace analizador {
namespace lexer {

std::string Token::toString() const {
	std::stringstream s;
	s << "[" << tipo << "]";
	s << "(" << categoria << ")";
	if (pos.linea != (size_t)-1) {
		s << "{" << std::setw(2) << std::left << pos.linea;
		s << ", " << std::setw(2) << std::left << pos.caracter << "}";
	} else {
		s << "{N/A   }";
	}
	s << ": " << contenido;
	return s.str();
}

std::vector<std::string> generarArbol(std::vector<Token> tokens, Arbol<Token>& arbol){
	std::vector<std::string> errores; 
	Arbol<Token> nuevo;
	size_t nivel = 0;
	//aca se lleva el control mediante un automata finito
	for (const Token& t: tokens){
		if (t.categoria == CatToken::llave){
			switch (t.tipo){
			case TipoToken::llaveIzquierda:
			case TipoToken::cuadIzquierdo:
			case TipoToken::parentesisIzquierdo:
				nivel++;
				break;
			case TipoToken::llaveDerecha:
			case TipoToken::cuadDerecho:
			case TipoToken::parentesisDerecho:
				if(nivel == 0){
					errores.push_back("llave de cierre no esperada:\n" + t.toString());
					break;
				}
				nivel--;
				break;
			default:
				break;
			}
		}
		
    }
	if(nivel != 0){
		errores.push_back("faltan llaves de cierre");
	}
	return errores;
}

} // namespace lexer
} // namespace analizador





std::string strTipoToken[] = {"numero",
                              "tipo",
                              "identificador",
                              "asignacion",
                              "string",
                              "parentesisIzquierdo",
                              "parentesisDerecho",
                              "cuadDerecho",
                              "cuadIzquierdo",
                              "llaveDerecha",
                              "llaveIzquierda",
                              "mayor",
                              "menor",
                              "igual",
                              "negacion",
                              "mayorIgual",
                              "menorIgual",
                              "diferente",
                              "mas",
                              "menos",
                              "asterisco",
                              "slash",
                              "punto",
                              "coma",
                              "dosPuntos",
                              "puntoComa",
                              "comillaSimple",
                              "comillaDoble",
                              "amperson",
                              "pleca",
                              "cond_if",
                              "cond_else",
                              "cond_switch",
                              "cond_case",
                              "cliclo_for",
                              "ciclo_while",
                              "indefinido"};
std::string strCatToken[] = {
    "identificador", "tipo",    "asignacion", "comparacion", "aritmetico",
    "numerico",      "literal", "llave",      "otro",        "indefinido"};

std::ostream &operator<<(std::ostream &os,
                         const analizador::lexer::TipoToken tp) {
	os << std::setw(20) << std::left << strTipoToken[(const size_t)tp];
	return os;
}
std::ostream &operator<<(std::ostream &os,
                         const analizador::lexer::CatToken ct) {
	os << std::setw(20) << std::left << strCatToken[(const size_t)ct];
	return os;
}
