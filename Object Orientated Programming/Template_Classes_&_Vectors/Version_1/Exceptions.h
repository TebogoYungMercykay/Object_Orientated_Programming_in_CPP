#ifndef Exception_H
#define Exception_H
#include <sstream>

class UnauthorisedEx{
    
};

class EmptyEx{
    
};

template <class E>
class UndervaluedEx{
    public:
        UndervaluedEx(E* UnderVal1, double sum);
        E* getUndervalued() const;
        double getSum() const;
    private:
        E* underVal;
        double sum;
};

class AboveWeightEx{
    private:
        double weightDiff;
    public:
        AboveWeightEx(double weightDiff1);
        double getDifference() const;
};

template <class E>
class NotFoundEx{
    public:
        NotFoundEx(E* mising1);
        E* getNotFound() const;
    private:
        E* missing;
};
#include "Exceptions.cpp"
#endif