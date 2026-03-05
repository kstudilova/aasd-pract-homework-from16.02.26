#include <iostream>

template< class T >
T* mergeN(const T* const* a, size_t sa, const size_t* sai, T* c)
{
  if (sa == 0)
  {
    return c;
  }

  size_t totalSize = sai[0];
  for (size_t i = 0; i < totalSize; ++i)
  {
    c[i] = a[0][i];
  }

  for (size_t i = 1; i < sa; ++i)
  {
    T* tmp = nullptr;
    try {
      tmp = new T[totalSize + sai[i]];
      size_t k = 0;
      size_t indexC = 0;
      size_t indexA = 0;
      while (indexC < totalSize && indexA < sai[i])
      {
        if (c[indexC] < a[i][indexA])
        {
          tmp[k++] = c[indexC++];
        } else {
          tmp[k++] = a[i][indexA++];
        }
      }
      while (indexC < totalSize)
      {
        tmp[k++] = c [indexC++];
      }
      while (indexA < sai[i])
      {
        tmp[k++] = a[i][indexA++];
      }
      for (size_t j = 0; j < totalSize + sai[i]; ++j) {
        c[j] = tmp[j];
      }
      totalSize += sai[i];
      delete[] tmp;
      tmp = nullptr;
    } catch(...) {
      delete[] tmp;
      throw;
    }
  }
  return c + totalSize;
}