#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1500;

void test1()
{
  auto fs = FileSharing(4);
  int id = fs.join(vector<int>{1, 2});
  cout << "id should be 1: " << to_string(id) << endl;
  id = fs.join(vector<int>{2, 3});
  cout << "id should be 2: " << to_string(id) << endl;
  id = fs.join(vector<int>{4});
  cout << "id should be 3: " << to_string(id) << endl;
  auto users = fs.request(1, 3);
  cout << "result should be [2]: " << Util::toString(users) << endl;
  users = fs.request(2, 2);
  cout << "result should be [1,2]: " << Util::toString(users) << endl;
  fs.leave(1);
  users = fs.request(2, 1);
  cout << "result should be []: " << Util::toString(users) << endl;
  fs.leave(2);
  id = fs.join(vector<int>());
  cout << "id should be 1: " << to_string(id) << endl;
}

void testSetInsert()
{
  set<int> s;
  s.insert(9);
  auto v = vector<int>{5, 7, 6};
  Util::insert(s, v);
  auto result = Util::toVec(s);
}

main()
{
  test1();
  // testSetInsert();
  return 0;
}