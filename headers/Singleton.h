/*#pragma once
#include "GerenciadorEventos.h"

class Singleton
{
private:
	static Singleton* instance;
	GerenciadorEventos ge;

	Singleton(const GerenciadorEventos ge);

public:
	Singleton(Singleton& other) = delete;
	void operator=(const Singleton&) = delete;
	static Singleton* getInstance(const GerenciadorEventos& ge);

	
};

Singleton* Singleton::instance = nullptr;
*/