#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const long int SECONDSPERYEAR = 31556926;
const long int SECONDSPERMONTH = 2629743;
const long int SECONDSPERDAY = 86400;
const string EVENTTYPE[9] = {
    "Meeting", "Birthday Reminder", "Party",   "Semester Test", "Class Test",
    "Exam",    "Lecture",           "Booking", "Study Session"};

struct event_data {
  long int start;
  long int end;
  int id;
  string type;
};

//////////////////////////////////////////////////////////////////////////
///////////////////DO NOT CHANGE ANY CODE ABOVE///////////////////////////
//////////////////////////////////////////////////////////////////////////

/////////////////////////////YOUR CODE HERE//////////////////////////////
template <class T> static string to_string(T input) {
  stringstream ss;
  ss << input;
  return ss.str();
}

template <class T> static int to_int(T input) {
  stringstream ss;
  int temp;
  ss << input;
  ss >> temp;
  return temp;
}

template <class T> static int long to_long(T input) {
  stringstream ss;
  long int temp;
  ss << input;
  ss >> temp;
  return temp;
}
////////////////////////////YOUR CODE HERE///////////////////////////////

//////////////////////////////////////////////////////////////////////////
////////////////////DO NOT CHANGE ANY CODE BELOW//////////////////////////
//////////////////////////////////////////////////////////////////////////

static string unix_to_string(long int timestamp) {
  if (timestamp < 0)
    timestamp = 0;
  long int year = timestamp / SECONDSPERYEAR + 1970;
  int month = timestamp % SECONDSPERYEAR / SECONDSPERMONTH + 1;
  int day = timestamp % SECONDSPERYEAR % SECONDSPERMONTH / SECONDSPERDAY + 1;
  int hour = timestamp % SECONDSPERDAY / 3600;
  int minutes = timestamp / 60 % 60;
  int seconds = timestamp % 60;
  stringstream ss;
  ss << to_string(year) << "/"
     << ((month < 10) ? "0" + to_string(month) : to_string(month)) << "/"
     << ((day < 10) ? "0" + to_string(day) : to_string(day)) << " ";
  ss << ((hour < 10) ? "0" + to_string(hour) : to_string(hour)) << ":";
  ss << ((minutes < 10) ? "0" + to_string(minutes) : to_string(minutes)) << ":"
     << ((seconds < 10) ? "0" + to_string(seconds) : to_string(seconds));
  return ss.str();
}

static vector<event_data> get_api_results(int seed, int count) {
  srand(seed);
  vector<event_data> results;
  for (int i = 0; i < count; i++) {
    event_data temp;
    temp.start = rand() % 99999999 + 1660000000;
    temp.end = temp.start + rand() % 9999999;
    temp.id = rand() % 10000;
    temp.type = EVENTTYPE[rand() % 9];
    results.push_back(temp);
  }
  return results;
}

#endif // UTILS_H