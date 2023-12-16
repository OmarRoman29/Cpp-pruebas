#include <algorithm>
#include <iostream>

// clase es una estructura de programación que permite
// definir un tipo de datos personalizado con sus propios
// miembros (variables y funciones). Las clases son la
// base de la programación orientada a objetos

// Definición de la clase
// la palabra reservada class define una clase, y
// MiClase es el nombre que se le da
class MiClase {
  // Por defecto todos los miebros son "Privados"
  int varPriv;
  int metodoPriv();

private:
  int otraVarPriv;

public:
  int varPub;
  int metodoPub() {
    std::cout << "Este es un metodo" << std::endl;

    // Los miembros privados solo se pueden acceder
    // desde la propia clase
    varPriv = 1;
    return varPriv;
  }
};

int main() {
  // Crear objeto / instancia de clase MiClase
  MiClase objeto;

  // Se puede acceder a los miembros publicos
  // como:
  objeto.varPub = 1;
  int var = objeto.metodoPub();
  std::cout << "El valor de var es: " << var << std::endl;

  // Pero al tener miembros privados no podemos
  // acceder como:
  // objeto.varPriv // Marca error
}
