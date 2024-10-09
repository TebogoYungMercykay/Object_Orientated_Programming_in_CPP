#include "dog.h"

void swapNames(Dog &first, Dog &second) {
  std::string nameFirst = first.getName();
  first.setName(second.getName());
  second.setName(nameFirst);
}

int containsDog(Dog *array[], std::string name);

int main() {
  const int p = 10;
  Dog **arrayDogs = new Dog *[p];

  std::string str = "";
  int k = 0;
  int option_Exit = 3;
  int temp = 0;
  int age = 0;
  int count = 0;

  for (; k < 10;) {
    arrayDogs[k] = NULL;
    k++;
  }

  do {
    std::string name = "";
    std::string Owner = "";
    std::string name2 = "";
    std::string address = "";

    std::cout << "Enter 1 to add a dog, 2 to swap names or 3 to stop: ";

    std::cin >> temp;

    if (temp != option_Exit) {
      if (temp == option_Exit - 2) {

        std::cout << "Please enter the name of the dog: ";
        std::cin >> name;

        std::cout << "Please enter the age: ";
        std::cin >> age;

        std::cout << "Does the dog have an owner: ";
        std::cin >> Owner;

        if (Owner == "Yes") {
          std::cout << "Please enter the owners name: ";
          std::cin >> name2;

          std::cout << "Please enter the address: ";
          std::cin >> address;
        }

        arrayDogs[count] = new Dog();

        arrayDogs[count]->setName(name);

        arrayDogs[count]->setAge(age);

        Citizen ownerVar;

        if (Owner == "Yes") {
          ownerVar.setName(name2);

          ownerVar.setAddress(address);
        }

        arrayDogs[count]->setCitizen(&ownerVar);

        count++;
        str = "";

        std::cout << "The list of dogs are as follows: ";
        int k = 0;

        for (; k < 10;) {
          if (arrayDogs[k]) {
            str += arrayDogs[k]->getName();
            str += "(Owner: ";
            str += arrayDogs[k]->getCitizen()->getName();
            str += "), ";
          }

          k++;
        }
        std::cout << str.substr(0, str.length() - (option_Exit - 1))
                  << std::endl;
      } else if (temp == option_Exit - 1) {
        std::string firs = "", secon = "";
        std::cout << "Enter name of first dog: ";
        std::cin >> firs;

        std::cout << "Enter name of second dog: ";
        std::cin >> secon;
        if (firs == "") {
          for (; k < 10;) {
            if (arrayDogs[k]) {
              firs += arrayDogs[k]->getName();
              firs += "(Owner: ";
              firs += arrayDogs[k]->getCitizen()->getName();
              firs += "), ";
            }

            k++;
          }
        } else if (containsDog(arrayDogs, firs) == -1 ||
                   containsDog(arrayDogs, secon) == -1) {
          std::cout << "No dog found" << std::endl;
        } else {
          swapNames(*arrayDogs[containsDog(arrayDogs, firs)],
                    *arrayDogs[containsDog(arrayDogs, secon)]);

          str = "";
          std::cout << "The list of dogs are as follows: ";
          int k = 0;

          for (; k < 10;) {
            if (arrayDogs[k]) {
              str += arrayDogs[k]->getName();
              str += "(Owner: ";
              str += arrayDogs[k]->getCitizen()->getName();
              str += "), ";
            }

            k++;
          }
          std::cout << str.substr(0, str.length() - (option_Exit - 1))
                    << std::endl;
        }
      }
    }
  } while (temp != option_Exit);

  return 0;
}