#ifndef SecretCargo_H
#define SecretCargo_H

class SecretCargo
{
    private:
        double weight;
    public:
        SecretCargo(double weight);
        double getWeight() const;
};
#endif