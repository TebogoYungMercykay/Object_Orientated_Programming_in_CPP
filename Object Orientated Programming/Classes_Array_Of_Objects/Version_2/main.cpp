#include "dog.h"
void swapNames(Dog& first, Dog& second)
{
    std::string nameFirst = first.getName();
    first.setName(second.getName());
    second.setName(nameFirst);
}

int main()
{
    int sizedogs = 2;
    Dog** myArray = new Dog*[1*5*sizedogs];
    int store = 0;
    for(int tau = 0;tau<10;tau+=1){ myArray[tau] = NULL;}
    int oop, ageLemon ,myArrayInt;
    oop = 0;
    ageLemon = myArrayInt = 0;
    for(int tau2 = 0; tau2 < 10; tau2+=1)
    {
        std::string Lemon{};
        std::string citizen{};
        std::string citizenName{};
        std::string citizenAddress{};

        std::cout<<"Enter 1 to add a dog, 2 to swap names or 3 to stop: ";
        std::cin>>oop;
        if(oop!=3)
        {
            if(oop == 1)
            {
                std::cout<<"Please enter the name of the dog: ";
                std::cin>>Lemon;
                std::cout<<"Please enter the age: ";
                std::cin>>ageLemon;
                std::cout<<"Does the dog have an owner: ";
                std::cin>>citizen;

                if(citizen=="Yes")
                {
                    std::cout<<"Please enter the owners name: ";
                    std::cin>>citizenName;
                    std::cout<<"Please enter the address: ";
                    std::cin>>citizenAddress;
                }

                myArray[myArrayInt] = new Dog();
                myArray[myArrayInt]->setName(Lemon);
                myArray[myArrayInt]->setAge(ageLemon);
                Citizen citizenVariable;

                if(citizen=="Yes")
                {
                    citizenVariable.setName(citizenName);
                    citizenVariable.setAddress(citizenAddress);
                }

                myArray[myArrayInt]->setCitizen(&citizenVariable);
                myArrayInt+=1;
                store = -1;

                for(int tau = 0;tau<10;tau+=1)
                {
                    if(myArray[tau]!=NULL)store+=1;
                }
                std::cout<<"The list of dogs are as follows: ";
                for(int tau = 0;tau<10;tau+=1)
                {
                    if(myArray[tau]!=NULL)
                    {
                        if(store == 0)
                        {
                            std::cout<<myArray[tau]->getName()+"(Owner: "+myArray[tau]->getCitizen()->getName()+")"<<std::endl;
                        }
                        else if(tau <= store-1)
                        {
                            std::cout<<myArray[tau]->getName()+"(Owner: "+myArray[tau]->getCitizen()->getName()+"), ";
                        }
                        else
                        {
                            std::cout<<myArray[tau]->getName()+"(Owner: "+myArray[tau]->getCitizen()->getName()+")"<<std::endl;
                        }
                    }
                }
            }
            else if(oop == 2)
            {
                std::string firstDog{};
                std::string secondDog{};

                std::cout<<"Enter name of first dog: ";
                std::cin>>firstDog;
                std::cout<<"Enter name of second dog: ";
                std::cin>>secondDog;
                
                int dogOne = 0,dogTwo =  0;
                store = -1;
                for(int tau = 0;tau<10;tau+=1)
                {
                    if(myArray[tau]!=NULL)store+=1;
                }
                for(int tau = 0;tau<10;tau+=1)
                {
                    if(myArray[tau]!=NULL)
                    {
                        if(myArray[tau]->getName() == firstDog)
                        {
                            dogOne = tau;
                            break;
                        }
                    }
                    else
                    {
                        dogOne = -1;
                    }
                }
                for(int tau = 0;tau<10;tau+=1)
                {
                    if(myArray[tau]!=NULL)
                    {
                        if(myArray[tau]->getName() == secondDog)
                        {
                            dogTwo = tau;
                            break;
                        }
                    }
                    else
                    {
                        dogTwo = -1;
                    }
                }
                if(dogOne!=-1 && dogTwo!=-1)
                {
                    swapNames(*myArray[dogOne],*myArray[dogTwo]);
                    std::cout<<"The list of dogs are as follows: ";
                    for(int tau = 0;tau<10;tau+=1)
                    {
                        if(myArray[tau]!=NULL)
                        {
                            if(store == 0)
                            {
                                std::cout<<myArray[tau]->getName()+"(Owner: "+myArray[tau]->getCitizen()->getName()+")"<<std::endl;
                            }
                            else if(tau <= store-1)
                            {
                                std::cout<<myArray[tau]->getName()+"(Owner: "+myArray[tau]->getCitizen()->getName()+"), ";
                            }
                            else
                            {
                                std::cout<<myArray[tau]->getName()+"(Owner: "+myArray[tau]->getCitizen()->getName()+")"<<std::endl;
                            }
                        }
                    }
                }
                else
                {
                    std::cout<<"No dog found"<<std::endl;
                }
            }
        }
        else
        {
            break;
        }
    }
    while(false)
    {
        break;
    }
    return 0;
}