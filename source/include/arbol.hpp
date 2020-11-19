#pragma once
#include <memory> // unique_ptr
#include <vector>

template <typename T> struct Arbol {
	struct Nodo {
		std::unique_ptr<T> valor = nullptr;
		std::vector<Nodo> hijos;

	  public:
		Nodo() = default;
		Nodo(T *valor) : valor(valor) {}
	};
	std::unique_ptr<Nodo> raiz = std::make_unique<Nodo>(Nodo());
	Arbol() = default;
};
