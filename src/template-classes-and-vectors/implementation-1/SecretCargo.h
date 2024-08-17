#ifndef SecretCargo_H
#define SecretCargo_H

class SecretCargo {
public:
  SecretCargo(double weight);
  double getWeight() const;

private:
  double weight;
};
#endif