#include "Adivino.h"
int main() {
	Adivino juego;
	int minimo = NULL, maximo = 100;
	juego.setArchivo();
	juego.setJuego(maximo, minimo);
	return EXIT_SUCCESS;
}