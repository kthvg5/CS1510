//Programer: Kyle Hatfield 12396364     Date: 1/22/2015
//file: helloall.cpp
//purpose: get practice with submitting

#include <iostream>
#include <string>
using namespace std;

int main()
{
  const int INIT_TO_ZERO = 0;

  int num_peeps;
  string my_name_is;

  cout << "How many people should I say hello to?" << endl;
  cin >> num_peeps;
  for (int i = INIT_TO_ZERO; i < num_peeps; i++)
  {
    cout << "What is your name?" << endl;
    cin >> my_name_is;
    cout << "Hello " << my_name_is << "." << endl;
    if (i != num_peeps - 1)
    {
      cout << "NEXT!!!" << endl;
    }
  }
  return 0;
}