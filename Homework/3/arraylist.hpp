//Kyle Hatfield, 12396364
//Date: 03/01/2015


//errobj, fix append (new arralist)

using namespace std;
const int INIT_TO_ZERO = 0;

//destructor
template <class T>
ArrayList<T>::~ArrayList()
{
  delete[]m_data;
}

//operator=
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  delete[] m_data;
  m_size = rhs.m_size;
  m_max = rhs.m_max;
  m_data = new T [m_max];
  for (int i = INIT_TO_ZERO; i < m_size; i++)
    m_data[i] = rhs.m_data[i];
  return *this;
}

//copy constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_data = new T[cpy.m_max];
  (*this) = cpy;
}

//size
template <class T>
int ArrayList<T>::size() const
{
  return m_size;
}

//first
template <class T>
const T& ArrayList<T>::first() const
{
  if (m_size == INIT_TO_ZERO)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << endl;
    return m_errobj;
  }
  {
    return m_data[INIT_TO_ZERO];
  }
}

//operator[]
template <class T>
T& ArrayList<T>:: operator[](int i)
{
  if (i < INIT_TO_ZERO || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
    return m_errobj;
  }
  else
  {
    return(m_data[i]);
  }
}

//const operator[]
template <class T>
const T& ArrayList<T>:: operator[](int i) const
{
  if (i < INIT_TO_ZERO || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
    return m_errobj;
  }
  else
  {
    return(m_data[i]);
  }
}

//find
template <class T>
int ArrayList<T>::find(const T& x)
{
  bool found = false;
  int rv = -1;
  int counter = INIT_TO_ZERO;
  while (found == false && counter < m_size)
  {
    if (m_data[counter] == x)
      found = true;
    else
      counter++;
  }
  if (found == true)
    rv = counter;
  return rv;
}

//clear
template <class T>
void ArrayList<T>::clear()
{
  delete m_data;
  m_data = new T[INIT_TO_ZERO];
  m_data[INIT_TO_ZERO] = NULL;
  m_size = INIT_TO_ZERO;
  m_max = INIT_TO_ZERO;
  return;
}

//insert_back
template <class T>
void ArrayList<T>::insert_back(const T& x)
{
  if (m_max == INIT_TO_ZERO)
  {
    m_max++;
  }
  if (m_size >= m_max-1)
  {
    m_max *= 2;
    T* tmp = new T[m_max];
    for (int i = INIT_TO_ZERO; i < m_size; i++)
      tmp[i] = m_data[i];
    delete[] m_data;
    m_data = tmp;
  }
  m_data[m_size] = x;
  m_size++;
  return;
}

//insert
template <class T>
void ArrayList<T>::insert(const T& x, int i)
{
  if (i < INIT_TO_ZERO || i >= m_size)
  {
  cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)" << endl;
  }
  else
  {
    if (m_size >= m_max - 1)
    {
      m_max *= 2;
      T* tmp = new T[m_max];
      for (int z = INIT_TO_ZERO; z < m_size; z++)
        tmp[z] = m_data[z];
      delete[] m_data;
      m_data = tmp;
    }
    for (int k = m_size; k > i; k--)
      m_data[k] = m_data[k - 1];
    m_data[i] = x;
    m_size++;
    return;
  }
}


//remove
template <class T>
void ArrayList<T>::remove(int i)
{
  if (i < INIT_TO_ZERO || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)";
    cout << endl;
  }
  else
  {
    for (int k = i; k < m_size - 1; k++)
      m_data[k] = m_data[k + 1];
    m_size--;
    while (m_size < m_max / 4)
    {
      T* tmp = new T[m_max / 2];
      for (int k = INIT_TO_ZERO; k < m_size; k++)
        tmp[k] = m_data[k];
      delete[] m_data;
      m_data = tmp;
      m_max /= 2;
    }
    return;
  }
}

//swap
template <class T>
void ArrayList<T>::swap(int i, int k)
{
  if (i < INIT_TO_ZERO || i >= m_size || k < INIT_TO_ZERO || k > m_size)
  {
    cout << "!--ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)";
    cout << endl;
  }
  else
  {
    T tmp = m_data[k];
    m_data[k] = m_data[i];
    m_data[i] = tmp;
    return;
  }
}

//append
template <class T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  int counter = INIT_TO_ZERO;
  int totalSize = m_size + alist.m_size;
  if (m_max < totalSize)
  {
    while (m_max <= m_size + alist.m_size)
    {
      m_max *= 2;
    }
    T* tmp = new T[m_max];
    for (int i = INIT_TO_ZERO; i < m_size; i++)
      tmp[i] = m_data[i];
    delete[] m_data;
    m_data = tmp;
  }

  for (int i = INIT_TO_ZERO; i < alist.m_size; i++)
  {
    m_data[i+m_size] = alist.m_data[i];
    counter++;
  }
  m_size += alist.m_size;
  return;
}

//purge
template <class T>
void ArrayList <T>::purge()
{
  for (int i = INIT_TO_ZERO; i < m_size; i++)
  {
    for (int k = i + 1; k < m_size; k++)
    {
      if (m_data[k] == m_data[i])
        remove(k);
    }
  }
  return;
}