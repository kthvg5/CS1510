//Kyle Hatfield 12396364, lec 1B
//Homework 1

//forloop vars used: i, j, k, l, m, n, p, q

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
const int INIT_TO_ZERO = 0;

int main()
{
  srand(time(NULL));
  int num_graphs;
  int width;
  int height;
  int flowers_crushed;
  int least_flowers_crushed;
  int x;
  int y;
  int ** make_grid;
  cin >> num_graphs;
  for (int i = INIT_TO_ZERO; i < num_graphs; i++)//used i here
  {
    cin >> width;
    cin >> height;
    make_grid = new int *[width];
    for (int j = INIT_TO_ZERO; j < width; j++) //used j here
    {
      make_grid[j] = new int[height];
      //cout << "vert " << j << " made" << endl;
    }
    for (int k = INIT_TO_ZERO; k < height; k++) //used k here
    {
      for (int l = INIT_TO_ZERO; l < width; l++)// used l here
      {
        //make_grid[l][k] = (rand() % 10);//for testing
        cin >> make_grid[l][k];
        //cout << " " << make_grid[l][k]; //for testing
      }
      //cout << " row " << k << endl;
    }
    
    flowers_crushed = INIT_TO_ZERO;
    for (int m = INIT_TO_ZERO; m < width - 2; m++)//used m here
    {
      for (int n = INIT_TO_ZERO; n < height - 2; n++)//used n here
      {
        flowers_crushed = INIT_TO_ZERO;
        for (int p = INIT_TO_ZERO; p < 3; p++)//used p here. I hate using o.
        {
          for (int q = INIT_TO_ZERO; q < 3; q++)//used q here
            flowers_crushed += make_grid[m + q][n + p];
        }
        if (flowers_crushed < least_flowers_crushed || (m == INIT_TO_ZERO && n == INIT_TO_ZERO))
        {
          least_flowers_crushed = flowers_crushed;
          x = m;
          y = n;
        }
      }
    }
    cout << "#" << i << ": (" << x << ", " << y << ") " << least_flowers_crushed << endl;
    for (int r = INIT_TO_ZERO; r < width; r++)
      delete[] make_grid[r];
    delete[] make_grid;
  }

  return INIT_TO_ZERO;
}
