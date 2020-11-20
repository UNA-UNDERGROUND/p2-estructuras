// tambien se puede utilizar el hashmap de sistematizaciones
// pero por simplicidad usaremos el de la stl para reducir el codigo
#include <lexer.hpp>
#include <unordered_map>

namespace analizador {
extern std::unordered_map<std::string, lexer::Token> mapaToken;
//carga todos los tokens en el mapa
void inicializar();
} // namespace analizador