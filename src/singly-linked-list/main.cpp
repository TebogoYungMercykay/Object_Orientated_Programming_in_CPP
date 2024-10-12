#include "Calendar.h"
#include "Event.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::cout << "----------- Practical 7 - Testing Main -----------"
            << std::endl;
  vector<event_data> data = get_api_results(1234, 7);
  Calendar *ptr = new Calendar(data);
  cout << "------ Constructor Done ---------" << endl;
  cout << *ptr;
  cout << endl;
  cout << "------ Operator Done ---------" << endl;
  cout << *ptr->getFirstEvent();
  cout << endl;
  cout << "------ First Element Done ---------" << endl;
  ptr->clearCalendar();
  if (ptr->getFirstEvent()) {
    cout << *ptr->getFirstEvent();
    cout << endl;
  } else {
    cout << "Data is gone" << endl;
  }
  delete ptr;
  ptr = NULL;
  cout << "------ clearCalendar Done ---------" << endl;
  Calendar *ptr2 = new Calendar(data);
  Event *temp = ptr2->getUpcomingEvent(1731014646);
  if (temp) {
    cout << *temp;
    cout << endl;
  } else {
    cout << "Events are probably gone" << endl;
  }
  cout << "------ getUpcomingEvent Done ---------" << endl;
  long int l = 1672224280;
  long int *li = &l;
  string s = "JustDoIt";
  string *si = &s;
  ptr2->alterEvent(4504, li, si);
  cout << *ptr2;
  cout << endl;
  cout << "------ alterEvent Done ---------" << endl;
  ptr2->removeEvent(168);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P1 Done ---------" << endl;
  ptr2->removeEvent(4504);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P2 Done ---------" << endl;
  ptr2->removeEvent(1964);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P3 Done ---------" << endl;
  ptr2->removeEvent(2728);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P4 Done ---------" << endl;
  ptr2->removeEvent(4375);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P5 Done ---------" << endl;
  ptr2->removeEvent(9755);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P6 Done ---------" << endl;
  ptr2->removeEvent(6155);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P7 Done ---------" << endl;
  ptr2->removeEvent(6155);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P8 Done ---------" << endl;
  ptr2->removeEvent(6155);
  cout << *ptr2;
  cout << endl;
  cout << "------ removeEvent P8 Done ---------" << endl;
  delete ptr2;
  ptr2 = NULL;
  int g = 168;
  int *idt = &g;
  Calendar *ptr3 = new Calendar(data);
  vector<Event> tempEvents = ptr3->filterEvents(idt, NULL, NULL, NULL);
  for (int k = 0; k < tempEvents.size(); k++) {
    cout << tempEvents[k];
    cout << endl;
  }
  cout << "------ filterEvents P1 Done ---------" << endl;
  string ty = "Semester Test";
  string *str = &ty;
  tempEvents = ptr3->filterEvents(NULL, NULL, NULL, str);
  for (int k = 0; k < tempEvents.size(); k++) {
    cout << tempEvents[k];
    cout << endl;
  }
  cout << "------ filterEvents P2 Done ---------" << endl;
  long int gs = 1704283364;
  long int *idts = &gs;
  long int ge = 1744708803;
  long int *idte = &ge;
  tempEvents = ptr3->filterEvents(NULL, idts, NULL, NULL);
  for (int k = 0; k < tempEvents.size(); k++) {
    cout << tempEvents[k];
    cout << endl;
  }
  cout << "------ filterEvents P3 Done ---------" << endl;
  tempEvents = ptr3->filterEvents(NULL, NULL, idte, NULL);
  for (int k = 0; k < tempEvents.size(); k++) {
    cout << tempEvents[k];
    cout << endl;
  }
  cout << "------ filterEvents P4 Done ---------" << endl;
  tempEvents = ptr3->filterEvents(NULL, idts, idte, NULL);
  for (int k = 0; k < tempEvents.size(); k++) {
    cout << tempEvents[k];
    cout << endl;
  }
  cout << "------ filterEvents P5 Done ---------" << endl;
  delete ptr3;
  ptr3 = NULL;
  return 0;
}