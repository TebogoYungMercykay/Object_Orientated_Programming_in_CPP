#ifndef TEST_CITIZEN_H
#define TEST_CITIZEN_H
#include <iostream>
#include <string>
using namespace std;

class Citizen {

private:
  string Name;
  string Address{};

public:
  Citizen();
  ~Citizen();

  const string &getName() const;

  void setName(const string &name);

  const string &getAddress() const;

  void setAddress(const string &address);
};
#endif // TEST_CITIZEN_H