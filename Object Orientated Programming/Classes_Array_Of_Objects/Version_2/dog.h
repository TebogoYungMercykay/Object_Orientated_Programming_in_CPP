#ifndef TEST_DOG_H
#define TEST_DOG_H
#include "citizen.h"
#include <string>
using namespace std;

class Dog {

	public:
		Dog();
		~Dog();
		const string &getName() const;
		void setName(const string &name);
		int getAge() const;
		void setAge(int age);
		Citizen* getCitizen();
		void setCitizen(Citizen* citizen);
    private:
        string Name;
        int Age;
		Citizen * owner = NULL;
};

#endif //TEST_DOG_H