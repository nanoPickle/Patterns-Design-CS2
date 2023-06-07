#include <cstring>
#include <iostream>
#include <memory>

// Clase que va interpretar el lenguaje gramatico
class RNInterpreter {
public:
  virtual void interpret(char *input, int &total) = 0;

protected:
  virtual char one() = 0;
  virtual const char *four() = 0;
  virtual char five() = 0;
  virtual const char *nine() = 0;
  virtual int multiplier() = 0;
};

// Clase para los numeros romanos de millares
class Thousand : public RNInterpreter {
public:
  void interpret(char *input, int &total) override {
    int index = 0;
    if (!strncmp(input, nine(), 2)) {
      total += 9 * multiplier();
      index += 2;
    } else if (!strncmp(input, four(), 2)) {
      total += 4 * multiplier();
      index += 2;
    } else {
      if (input[0] == five()) {
        total += 5 * multiplier();
        index = 1;
      } else {
        index = 0;
      }
      for (int end = index + 3; index < end; index++) {
        if (input[index] == one()) {
          total += 1 * multiplier();
        } else {
          break;
        }
      }
    }
    strcpy(input, &(input[index]));
  }

protected:
  char one() override { return 'M'; }
  const char *four() override { return ""; }
  char five() override { return '\0'; }
  const char *nine() override { return ""; }
  int multiplier() override { return 1000; }
};

// Clase de centenas en este caso para los numeros romanos
class Hundred : public RNInterpreter {
public:
  void interpret(char *input, int &total) override {
    int index = 0;
    if (!strncmp(input, nine(), 2)) {
      total += 9 * multiplier();
      index += 2;
    } else if (!strncmp(input, four(), 2)) {
      total += 4 * multiplier();
      index += 2;
    } else {
      if (input[0] == five()) {
        total += 5 * multiplier();
        index = 1;
      } else {
        index = 0;
      }
      for (int end = index + 3; index < end; index++) {
        if (input[index] == one()) {
          total += 1 * multiplier();
        } else {
          break;
        }
      }
    }
    strcpy(input, &(input[index]));
  }

protected:
  char one() override { return 'C'; }
  const char *four() override { return "CD"; }
  char five() override { return 'D'; }
  const char *nine() override { return "CM"; }
  int multiplier() override { return 100; }
};

// Clase para las decenas en romanos
class Ten : public RNInterpreter {
public:
  void interpret(char *input, int &total) override {
    int index = 0;
    if (!strncmp(input, nine(), 2)) {
      total += 9 * multiplier();
      index += 2;
    } else if (!strncmp(input, four(), 2)) {
      total += 4 * multiplier();
      index += 2;
    } else {
      if (input[0] == five()) {
        total += 5 * multiplier();
        index = 1;
      } else {
        index = 0;
      }
      for (int end = index + 3; index < end; index++) {
        if (input[index] == one()) {
          total += 1 * multiplier();
        } else {
          break;
        }
      }
    }
    strcpy(input, &(input[index]));
  }

protected:
  char one() override { return 'X'; }
  const char *four() override { return "XL"; }
  char five() override { return 'L'; }
  const char *nine() override { return "XC"; }
  int multiplier() override { return 10; }
};

// CLase para las unidades de los romanos
class One : public RNInterpreter {
public:
  void interpret(char *input, int &total) override {
    int index = 0;
    if (!strncmp(input, nine(), 2)) {
      total += 9 * multiplier();
      index += 2;
    } else if (!strncmp(input, four(), 2)) {
      total += 4 * multiplier();
      index += 2;
    } else {
      if (input[0] == five()) {
        total += 5 * multiplier();
        index = 1;
      } else {
        index = 0;
      }
      for (int end = index + 3; index < end; index++) {
        if (input[index] == one()) {
          total += 1 * multiplier();
        } else {
          break;
        }
      }
    }
    strcpy(input, &(input[index]));
  }

protected:
  char one() override { return 'I'; }
  const char *four() override { return "IV"; }
  char five() override { return 'V'; }
  const char *nine() override { return "IX"; }
  int multiplier() override { return 1; }
};

// CLase que va crear el lenguaje gramatico de los numeros romanos
class RNInterpreterFactory {
public:
  static std::unique_ptr<RNInterpreter> createThousand() {
    return std::make_unique<Thousand>();
  }
  static std::unique_ptr<RNInterpreter> createHundred() {
    return std::make_unique<Hundred>();
  }
  static std::unique_ptr<RNInterpreter> createTen() {
    return std::make_unique<Ten>();
  }
  static std::unique_ptr<RNInterpreter> createOne() {
    return std::make_unique<One>();
  }
};

int main() {
  std::unique_ptr<RNInterpreter> thousands =
      RNInterpreterFactory::createThousand();
  std::unique_ptr<RNInterpreter> hundreds =
      RNInterpreterFactory::createHundred();
  std::unique_ptr<RNInterpreter> tens = RNInterpreterFactory::createTen();
  std::unique_ptr<RNInterpreter> ones = RNInterpreterFactory::createOne();

  char input[20];
  std::cout << "Enter Roman Numeral: ";
  while (std::cin >> input) {
    int total = 0;
    thousands->interpret(input, total);
    hundreds->interpret(input, total);
    tens->interpret(input, total);
    ones->interpret(input, total);

    if (input[0] != '\0') {
      std::cout << "Invalid input. Please enter a valid Roman numeral."
                << std::endl;
    } else {
      std::cout << "Interpretation is " << total << std::endl;
    }

    std::cout << "Enter Roman Numeral: ";
  }

  return 0;
}
