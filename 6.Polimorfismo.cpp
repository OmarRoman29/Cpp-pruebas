/*"Usar un mismo método a diferentes objetos esperando que el"
 * Resultado sea diferente en consecuencia a sus propiedades*/

#include <iostream>

using std::string, std::cout, std::endl;

/* Polimorfismo de ejecución (Dinámico):
 * En tiempo de ejecución, se decide qué método de qué clase se va
 * a llamar. Este concepto se manifiesta en la sobreescritura de
 * métodos, donde una clase derivada proporciona una implementación
 * específica para un método que ya está definido en la clase base.
 */

/* Sobrecarga de funciones:
 * Capacidad de una clase para proporcionar varios métodos con el
 * mismo nombre pero diferentes en cuanto a tipos y/o cantidad de
 * argumentos.
 * En este caso se verá en los constructores
 */

/* Polimorfismo de compilación estática: Se refiere a la
 * capacidad de un lenguaje de programación de seleccionar la
 * función adecuada en tiempo de compilación, basándose en el tipo
 * estático de las variables involucradas. Esto está relacionado
 * con la resolución estática de enlaces y no implica la capacidad
 * de tener varios métodos con el mismo nombre (como ocurre en la
 * sobrecarga de funciones).
 */

class Profesion {
public:
  string trabajo;
  float ganancia;

  Profesion();
  Profesion(string _trabajo, float _ganancia);

  virtual void cobrar();
};

Profesion::Profesion() : trabajo("Desempleado"), ganancia(0) {}
Profesion::Profesion(string _trabajo, float _ganancia) {
  trabajo = _trabajo;
  ganancia = _ganancia;
}

void Profesion::cobrar() {
  cout << "El pago para " << this->trabajo << " es: " << this->ganancia << endl;
}

class FreeLance : public Profesion {
public:
  FreeLance() : Profesion(){};
  FreeLance(string _trabajo, float ganancia) : Profesion(_trabajo, ganancia){};

  void cobrar() override;
};

void FreeLance::cobrar() {
  // Se descuenta porcentaje por impuestos(?)
  float pago = ganancia - (ganancia * 0.16);
  cout << "El pago para " << this->trabajo << " es: " << pago << endl;
}

class Empleado : public Profesion {
public:
  Empleado() : Profesion(){};
  Empleado(string _trabajo, float ganancia) : Profesion(_trabajo, ganancia){};

  void cobrar() override;
};

void Empleado::cobrar() {
  // Se descuenta porcentaje por impuestos + el cobro del jefe(?)
  float pago = ganancia - (ganancia * 0.16) - (ganancia * 0.20);
  cout << "El pago para " << this->trabajo << " es: " << pago << endl;
}

// Polimorfismo dinámico(?)
template <typename TipoGenerico>
void pago_quincenal(TipoGenerico objeto){
    objeto.cobrar();
}

int main() {
  Profesion profesion1, profesion2("Inge", 15000.50);
  FreeLance trabajador1("Desarrollador móvil", 10000);
  Empleado trabajador2("Gerente", 10000);

  pago_quincenal(profesion1);
  pago_quincenal(profesion2);
  pago_quincenal(trabajador1);
  pago_quincenal(trabajador2);
}
