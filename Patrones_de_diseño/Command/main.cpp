#include <iostream>
#include <vector>

using namespace std;

// Clase Command -----------------------|
class Command {
public:
  virtual void execute() = 0;
  virtual ~Command() {}
};

// Clase concreta MoveCommand-----------------------|
class MoveCommand : public Command {
private:
  int x;
  int y;

public:
  MoveCommand(int x, int y) : x(x), y(y) {}

  void execute() override {
    cout << "Moviendo unidad a la posición: (" << x << ", " << y << ")" << endl;
    // Lógica para mover la unidad a la posición especificada
  }
};

// Clase concreta AttackCommand-----------------------|
class AttackCommand : public Command {
public:
  void execute() override {
    cout << "Atacando objetivo" << endl;
    // Lógica para que la unidad realice un ataque al objetivo
  }
};

// Clase Invoke que representa una unidad militar-----------------------|
class Invoke {
private:
  Command *command;

public:
  void setCommand(Command *command) { this->command = command; }

  void executeCommand() { command->execute(); }
};

int main() {
  // Crear una instancia de la unidad
  Invoke unit;

  // Crear comandos concretos
  Command *moveCommand = new MoveCommand(5, 10);
  Command *attackCommand = new AttackCommand();

  // Asignar comandos a la unidad
  unit.setCommand(moveCommand);
  unit.executeCommand();

  unit.setCommand(attackCommand);
  unit.executeCommand();

  // Liberar la memoria de los comandos
  delete moveCommand;
  delete attackCommand;

  return 0;
}
