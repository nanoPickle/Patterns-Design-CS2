#include <iostream>

// Interfaz común
class CommonInterface {
public:
    virtual void DoSomething() = 0;
    virtual ~CommonInterface(){};
};

// Clase real que implementa la interfaz
class RealClass : public CommonInterface {
public:
    void DoSomething() override {
        std::cout << "Doing something." << std::endl;
    }
};

// Proxy virtual que también implementa la interfaz
class ProxyClass : public CommonInterface {
private:
    CommonInterface* realObject;

public:
    ProxyClass(CommonInterface* obj) : realObject(obj) {}

    void DoSomething() override {
        // Realiza alguna lógica adicional antes o después de llamar al método en el objeto real
        std::cout << "Proxy: Before calling DoSomething." << std::endl;

        realObject->DoSomething();

        std::cout << "Proxy: After calling DoSomething." << std::endl;
    }
};

int main() {
    CommonInterface* proxy = new ProxyClass(new RealClass());
    proxy->DoSomething();

    delete proxy;

    return 0;
}
