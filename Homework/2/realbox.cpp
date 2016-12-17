#include "realbox.h"
using namespace std;

const int INIT_TO_ZERO = 0;

//constructor
RealBox::RealBox(int s, float a)
{
  m_reals = new float[s];
  for (int i = INIT_TO_ZERO; i < s; i++)
    m_reals[i] = a;
  m_boxsize = s;
}

//destructor
RealBox::~RealBox()
{
  delete[]m_reals;
}

//operator=
const RealBox& RealBox::operator= (const RealBox & rhs)
{
  delete[]m_reals;
  m_boxsize = rhs.m_boxsize;
  m_reals = new float[m_boxsize];
  for (int i = INIT_TO_ZERO; i < rhs.m_boxsize; i++)
    m_reals[i] = rhs.m_reals[i];
  return *this;
}
//copy constructor
RealBox::RealBox(const RealBox& rhs)
{
  m_reals = new float[rhs.m_boxsize];
  (*this) = rhs;
}

//accessor
void RealBox::set(int i, float x)
{
  m_reals[i] = x;
  return;
}

//prints the realbox
ostream& operator << (ostream&outs, const RealBox& box)
{
  outs << "[ ";
  for (int i = INIT_TO_ZERO; i < box.m_boxsize; i++)
    outs << box.m_reals[i] << ", ";
  outs << "]" << endl;
  return(outs);
}