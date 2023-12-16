#include <iostream>

typedef unsigned short ushort;

// Clase 1
class Persona {
public:
  int atributoCompartido;
  std::string nombre;
  ushort edad;

  Persona(std::string _nombre, ushort _edad);
  void presentarse();
};

Persona::Persona(std::string _nombre, ushort _edad) {
  nombre = _nombre;
  edad = _edad;
}

void Persona::presentarse() {
  std::cout << "Hola, soy " << nombre << std::endl;
}

// Clase 2
class Artista {
public:
  int atributoCompartido;
  std::string talento;
  Artista(std::string _talento);
};

Artista::Artista(std::string _talento) { talento = _talento; }

class EmpleadoArtista : public Persona, public Artista {
public:
  float sueldo;

  EmpleadoArtista(std::string _nombre, ushort _edad, std::string _talento,
                  float sueldo);

  void mostrarProfesion();
};

// Clase con herencia múltiple
EmpleadoArtista::EmpleadoArtista(std::string _nombre, ushort _edad,
                                 std::string _talento, float _sueldo)
    : Persona(_nombre, _edad), Artista(_talento) {
  sueldo = _sueldo;
}

void EmpleadoArtista::mostrarProfesion() {
  presentarse();
  std::cout << "Y me dedico a " << talento << std::endl;
}

int main() {
  EmpleadoArtista juan("Juan", 15, "Bailar", 200.5);
  juan.mostrarProfesion();

  // Para el atributo compartido, no pueden existir
  // métodos con el mismo nombre

  // juan.atributoCompartido = 1; // Marca error al estar en varias clases
  // Así diferenciamos atributos con el mismo nombre
  // sin embargo, también podemos acceder a los demás atributos de esta forma
  juan.Artista::atributoCompartido = 1;
  juan.Persona::atributoCompartido = 2;
}
