#include <tokens.hpp>


namespace analizador {
std::unordered_map<std::string, lexer::Token> mapaToken;
void inicializar() {
	using lexer::CatToken;
	using lexer::TipoToken;
	using lexer::Token;
	using lexer::TokenPos;
	TokenPos tp;
	std::string s;
	mapaToken.emplace(
	    "=", Token(tp, TipoToken::asignacion, CatToken::asignacion, s));
}
} // namespace analizador

