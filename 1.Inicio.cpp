// Libreria de entrada y salida estandar
#include <iostream>

// el main de toda la vida
int main() {
  // Imprimir en pantalla
  std::cout << "Hello world!" << std::endl;

  // Obtener entrada del usuario
  int a, b;

  // std::cin >> a;
  // std::cin >> b;

  // También se puede poner como:
  // De esta forma puedes poner un num separado
  // del otro por el espacio, o poner primer dato,
  // enter y el segundo
  std::cin >> a >> b;

  std::cout << "La suma de " << a << " y " << b << " es: " << a + b << std::endl;

  return 0;
}
