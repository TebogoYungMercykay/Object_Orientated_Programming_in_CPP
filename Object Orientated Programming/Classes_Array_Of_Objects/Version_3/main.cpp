#include "dog.h"

void swapNames( Dog& first, Dog& second){
    string nameFirst = first.getName();
    string nameSecond = second.getName();
    first.setName(nameSecond);
    second.setName(nameFirst);
}

int containsDog(Dog* array[], string name){
    for(int k_iterator = 0;k_iterator<10;k_iterator++){
        if(array[k_iterator]!=NULL){
            if(array[k_iterator]->getName() == name){
                return k_iterator;
            }
        }
    }
    return -1;
}

void printDogs(Dog* array[]){
    string printOut = "";
    cout<<"The list of dogs are as follows: ";
    for(int k_iterator = 0;k_iterator<10;k_iterator++){
        if(array[k_iterator]!=NULL){
            printOut+=array[k_iterator]->getName()+"(Owner: "+array[k_iterator]->getCitizen()->getName()+"), ";
        }
    }
    cout<<printOut.substr(0,printOut.length()-2)<<endl;
}

int main() {
    Dog** myDogArray = new Dog*[10];
    for(int k_iterator = 0;k_iterator<10;k_iterator++){
        myDogArray[k_iterator] = NULL;
    }
    // cout<<containsDog(myDogArray, "PitBull")<<" False "<<false<<endl;
    int optionsVar = 0, ageDog = 0,indexVar = 0;
    do{
        string nameDog = "",haveOwner = "",nameOwner = "",addressOwner = "";
        cout<<"Enter 1 to add a dog, 2 to swap names or 3 to stop: ";
        cin>>optionsVar;
        if(optionsVar!=3){
            if(optionsVar == 1){
                // Taking Usser Input
                cout<<"Please enter the name of the dog: ";
                cin>>nameDog;
                cout<<"Please enter the age: ";
                cin>>ageDog;
                cout<<"Does the dog have an owner: ";
                cin>>haveOwner;
                if(haveOwner=="Yes"){
                    cout<<"Please enter the owners name: ";
                    cin>>nameOwner;
                    cout<<"Please enter the address: ";
                    cin>>addressOwner;
                }
                // Initializing the Object
                myDogArray[indexVar] = new Dog();
                myDogArray[indexVar]->setName(nameDog);
                myDogArray[indexVar]->setAge(ageDog);
                Citizen ownerVar;
                if(haveOwner=="Yes"){
                    ownerVar.setName(nameOwner);
                    ownerVar.setAddress(addressOwner);
                }
                myDogArray[indexVar]->setCitizen(&ownerVar);
                indexVar++;
                printDogs(myDogArray);
            }
            else if(optionsVar == 2){
                string firstDog = "",secondDog = "";
                cout<<"Enter name of first dog: ";
                cin>>firstDog;
                cout<<"Enter name of second dog: ";
                cin>>secondDog;
                if(containsDog(myDogArray,firstDog)!=-1 && containsDog(myDogArray,secondDog)!=-1){
                    swapNames(*myDogArray[containsDog(myDogArray,firstDog)],*myDogArray[containsDog(myDogArray,secondDog)]);
                    printDogs(myDogArray);
                }
                else{
                    cout<<"No dog found"<<endl;
                }
            }
        }
    }while(optionsVar!=3);
    return 0;
}