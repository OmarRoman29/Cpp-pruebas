// Un constructor es un método que define los valores de nuestro
// objeto al momento de ser creado

#include <iostream>

class BoletoCine {
  std::string vendedor;

public:
  float precio;
  unsigned short numAsiento;

  // Metodo Constructor1
  BoletoCine(float _precio, unsigned short _numAsiento, std::string _vendedor);
  // Metodo Constructor1
  BoletoCine();
  // Metodo cualquiera
  void mostrarBoleto();
};

BoletoCine::BoletoCine(float _precio, unsigned short _numAsiento,
                       std::string _vendedor) {
  precio = _precio;
  numAsiento = _numAsiento;
  vendedor = _vendedor;
}

BoletoCine::BoletoCine() {
  precio = -1;
  numAsiento = 0;
  vendedor = "No hay vendedor";
}

void BoletoCine::mostrarBoleto() {
  std::cout << "Mi boleto costó: " << precio << std::endl;
  std::cout << "Mi asiento es: " << numAsiento << std::endl;
  std::cout << "Vendido por: " << vendedor << std::endl;
}

int main() {
  // Usamos el constructor para definir los valores del
  // objeto al crearse
  BoletoCine boleto1(100.5, 2, "José"), boleto2(100.5, 3, "Gabriela"), boleto3;
  boleto1.mostrarBoleto();
  boleto2.mostrarBoleto();
  boleto3.mostrarBoleto();
}
