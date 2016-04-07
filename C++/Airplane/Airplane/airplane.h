#include <iostream>

class Airplane {
  public:
    virtual void fly(const std::string& dest) = 0;
  protected:
    void defaultFly(const std::string& dest) {
        std::cout << "fuck";
    }
};

class ModelA : public Airplane {
  public:
    void fly(const std::string& dest) {
        std::cout << "The airplane flies straightly to airport " << dest << '.' << std::endl;
    }
};

class ModelB : public Airplane {
  public:
    void fly(const std::string& dest) {
        std::cout << "The airplane flies straightly to airport " << dest << '.' << std::endl;
    }
};

class ModelC : public Airplane {
  public:
    void fly(const std::string& dest) {
        std::cout << "The airplane flies in a semi-circle track to airport " << dest << '.' << std::endl;
    }
};


