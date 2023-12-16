#include <cstdio>
#include <iostream>

typedef unsigned short ushort;

class Persona {
public:
  std::string nombre;
  ushort edad;

  Persona(std::string _nombre, ushort _edad);
  void presentarse();
};

// Otra forma de inicializar los atributos
Persona::Persona(std::string _nombre, ushort _edad)
    : nombre(_nombre), edad(_edad) {}

void Persona::presentarse() { std::cout << "Hola soy " << nombre << std::endl; }

// Estudiante "Hereda" los atributos de Persona, al
// ser público, todos los atributos publicos de Persona
// también son públicos de Estudiante

class Estudiante : public Persona {
public:
  char grupo;
  ushort grado;

  // Constructor de Estudiante que llama al constructor de Persona
  // Necesita los atributos que usa Persona para su constructor
  Estudiante(std::string _nombre, ushort _edad, char _grupo, ushort _grado);

  void presentarseEstudiante();
};

// Implementación del constructor de Estudiante
// Cómo es posible que se vuelva tan ilegible esta cosa jsjs
/*
Estudiante::Estudiante(std::string _nombre, ushort _edad, char _grupo, ushort
_grado) : Persona(_nombre, _edad), grupo(_grupo), grado(_grado) {}
*/

// La forma las legible que encontré de escribirlo
Estudiante::Estudiante(std::string _nombre, ushort _edad, char _grupo,
                       ushort _grado)
  // Llamado al constructor de persona
  : Persona(_nombre, _edad) {
  
  grupo = _grupo;
  grado = _grado;
}

void Estudiante::presentarseEstudiante() {
  presentarse();
  std::cout << "Soy de " << grado << "° " << grupo << std::endl;
}

int main() {
  Persona juan("Juan", 15);
  juan.presentarse();

  Estudiante jose("José", 15, 'A', 2);
  jose.presentarseEstudiante();
}
