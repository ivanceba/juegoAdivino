#ifndef ADIVINO_H
#define ADIVINO_H
// Used libraries
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

// Namespace assignation
using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::ifstream;

class Adivino {
private:
	string archivo;
	int maxIntentos, numAdivinar, numIntentos;
public:
	// Constructor
	Adivino();

	// Destructor
	~Adivino();

	// Asigna el nombre del archivo
	void setArchivo();

	/*
	 *	Asigna el numero a adivinar
	 *	@param stream de lectura
	 */
	void setNumAdivinar(ifstream &);

	/*
	*	Asigna el maximo numero de intentos
	*	@param stream de lectura
	*/
	void setMaxIntentos(ifstream &);

	/*
	*	Determina si el numero dado es correcto
	*		@param		numero a comparar
	*		@return		Devuelve true si es correcto, false en caso contrario
	*/
	bool isCorrect(const int &);

	/*
	*	En el caso de que no sea correcto contabuiliza el intento y devuelve si ha llegado al limite
	*		@return		Devuelve true si se ha alcanzado el limite, false en caso contrario
	*/
	bool contabilizarIntento();

	/*
	*	Devuelve el nombre del archivo
	*		@return		nombre del archivo de lectura
	*/
	string getArchivo();

	/*
	*	Devuelve el numero de intentos
	*		@return		numero de intentos
	*/
	int getNumIntentos();

	/*
	*	Devuelve el numero a adivinar
	*		@return		numero a adivinar
	*/
	int getNumAdivinar();

	/*
	*	Devuelve el numero maximo de intentos
	*		@return		numero maximo de intentos
	*/
	int getMaxIntentos();

	/*
	*	Inicia la dinamica del juego
	*		@param		limite superior
	*		@param		limite inferior
	*/
	void setJuego(int &, int &);

	/*
	*	Determina si el numero dado es mayor que el numero a adivinar
	*		@param		numero dado
	*		@return		Devuelve true si es mayor, false en caso contrario
	*/
	bool isMayor(const int &);

	/*
	*	Devuelve el numero pedido al usuario dentro de los limites establecidos
	*		@param		limite superior
	*		@param		limite inferior
	*		@return		Devuelve el numero dentro del intervalo
	*/
	int getNumeroValido(const int &, const int &);
};
#endif