#include "Adivino.h"

Adivino::Adivino() {
	numAdivinar = NULL;
	numIntentos = NULL;
	maxIntentos = NULL;
}

Adivino::~Adivino() = default;

void Adivino::setArchivo() {
	ifstream leer;
	string nombreArchivo;

	cout << "Indique el nombre del archivo: ";
	cin >> nombreArchivo;
	leer.open(nombreArchivo.c_str());
	cout << "Abriendo";
	for (int i = NULL; i < 3; i++) {
		Sleep(1000);
		cout << ".";
	}
	cout << " ";
	while (!leer.is_open()) {
		system("CLS");
		cout << "Archivo invalido." << endl;
		cout << "Indique el nombre del archivo: ";
		cin >> nombreArchivo;
		leer.open(nombreArchivo.c_str());
		cout << "Abriendo";
		for (int i = NULL; i < 3; i++) {
			Sleep(1000);
			cout << ".";
		}
	}
	cout << "[CORRECTO]" << endl;
	archivo = nombreArchivo;

	setNumAdivinar(leer);
	setMaxIntentos(leer);
	leer.close();
}

void Adivino::setNumAdivinar(ifstream & buffer_in) {
	buffer_in >> numAdivinar;
}

void Adivino::setMaxIntentos(ifstream & buffer_in) {
	buffer_in >> maxIntentos;
}

bool Adivino::isCorrect(const int & num)
{
	return num == numAdivinar;
}

bool Adivino::contabilizarIntento() {
	numIntentos++;
	return numIntentos == maxIntentos;
}

std::string Adivino::getArchivo() {
	return archivo;
}

int Adivino::getNumIntentos() {
	return numIntentos;
}

int Adivino::getNumAdivinar() {
	return numAdivinar;
}

int Adivino::getMaxIntentos()
{
	return maxIntentos;
}

void Adivino::setJuego(int & limSup, int & limInf) {
	bool adivinado = false;
	while (!adivinado && numIntentos < maxIntentos) {
		int num = getNumeroValido(limSup, limInf);
		adivinado = isCorrect(num);
		if (adivinado)
			cout << "Has acertado en " << numIntentos + 1 << " intentos." << endl;
		else {
			if (isMayor(num))
				limSup = num - 1;
			else
				limInf = num + 1;
			contabilizarIntento();
		}
	}

	if (!adivinado)
		cout << "Has agotado todos tus intentos." << endl;

	system("PAUSE");
}

bool Adivino::isMayor(const int & num) {
	return num > numAdivinar;
}

int Adivino::getNumeroValido(const int & limSup, const int & limInf) {
	int num = NULL;
	cout << "Indique un numero entre " << limInf << " y " << limSup << ": ";
	cin >> num;
	while (num < limInf || num > limSup || cin.fail()) {
		cout << "Error: tiene que estar entre " << limInf << " y " << limSup << endl;
		cout << "Indique un numero entre " << limInf << " y " << limSup << ": ";
		cin >> num;
	}
	return num;
}