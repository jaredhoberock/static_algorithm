#pragma once

#include <iterator>

namespace detail
{

//template<unsigned int init, unsigned int n, unsigned int step>
//  struct static_for_impl
//{
//  static const unsigned int half_n      = n / 2;
//  static const unsigned int remainder_n = n - half_n;
//  static const unsigned int second_init = half_n * step + init; 
//
////  static const unsigned int one_tenth_n = n / 10u;
////  static const unsigned int remainder_n = n - 9u * one_tenth_n;
//
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    // in general do half, then do the other half
//    f = static_for_impl<init, half_n, step>::do_it(f);
//    f = static_for_impl<second_init, remainder_n, step>::do_it(f); 
//
////    // do this in tenths
////    f = static_for_impl<0u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<1u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<2u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<3u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<4u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<5u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<6u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<7u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<8u * one_tenth_n * step + init, one_tenth_n, step>::do_it(f);
////    f = static_for_impl<9u * one_tenth_n * step + init, remainder_n, step>::do_it(f);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 0u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 1u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 2u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 3u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 4u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 5u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    f(init + 4u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 6u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    f(init + 4u * step);
//    f(init + 5u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 7u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    f(init + 4u * step);
//    f(init + 5u * step);
//    f(init + 6u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 8u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    f(init + 4u * step);
//    f(init + 5u * step);
//    f(init + 6u * step);
//    f(init + 7u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 9u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    f(init + 4u * step);
//    f(init + 5u * step);
//    f(init + 6u * step);
//    f(init + 7u * step);
//    f(init + 8u * step);
//    return f;
//  }
//};
//
//template<unsigned int init, unsigned int step>
//  struct static_for_impl<init, 10u, step>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(init + 0u * step);
//    f(init + 1u * step);
//    f(init + 2u * step);
//    f(init + 3u * step);
//    f(init + 4u * step);
//    f(init + 5u * step);
//    f(init + 6u * step);
//    f(init + 7u * step);
//    f(init + 8u * step);
//    f(init + 9u * step);
//    return f;
//  }
//};
//
//template<unsigned int first, unsigned int last, unsigned int step = 1u, unsigned int num_steps = ((last - first - 1) / step) + 1>
//  struct static_for
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    return static_for_impl<first, num_steps, step>::do_it(f);
//  }
//};
  
//// XXX it might be a better idea to do multiple steps at once so we don't perform so much instantiation
//// XXX tried it (above); it seems to produce worse code
//template<unsigned int first, unsigned int last, unsigned int step = 1u, bool done = (last <= first)>
//  struct static_for
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    f(first);
//
//    return static_for<first + step, last, step>::do_it(f);
//  }
//};

//template<unsigned int first, unsigned int last, unsigned int step>
//  struct static_for<first, last, step, true>
//{
//  template<typename UnaryFunction>
//  inline static __host__ __device__
//  UnaryFunction do_it(UnaryFunction f)
//  {
//    return f;
//  }
//};

// XXX this one seems to be the winner
template<unsigned int first, unsigned int last, unsigned int step = 1u, unsigned int num_steps = ((last - first - 1) / step) + 1>
  struct static_for
{
  template<typename UnaryFunction>
  inline static __host__ __device__
  UnaryFunction do_it(UnaryFunction f)
  {
    #pragma unroll
    for(unsigned int i = 0u; i < num_steps; ++i)
    {
      f(first + i * step);
    }
    return f;
  }
};

template<typename RandomAccessIterator, typename Function>
  struct for_each_closure
{
  RandomAccessIterator m_iter;
  Function m_f;

  inline __host__ __device__
  for_each_closure(RandomAccessIterator iter, Function f)
    : m_iter(iter), m_f(f)
  {}

  template<typename Integer>
  inline __host__ __device__
  void operator()(Integer i)
  {
    m_f(m_iter[i]);
  }
};

template<typename RandomAccessIterator1, typename RandomAccessIterator2, typename Function>
  struct for_each2_closure
{
  RandomAccessIterator1 m_iter1;
  RandomAccessIterator2 m_iter2;
  Function m_f;

  inline __host__ __device__
  for_each2_closure(RandomAccessIterator1 iter1, RandomAccessIterator2 iter2, Function f)
    : m_iter1(iter1), m_iter2(iter2), m_f(f)
  {}

  template<typename Integer>
  inline __host__ __device__
  void operator()(Integer i)
  {
    m_f(m_iter1[i], m_iter2[i]);
  }
};

template<unsigned int n, typename RandomAccessIterator1, typename RandomAccessIterator2, typename Function>
  Function static_for_each(RandomAccessIterator1 first1, RandomAccessIterator2 first2, Function f)
{
  for_each2_closure<RandomAccessIterator1,RandomAccessIterator2,Function> body(first1,first2,f);
  return static_for<0,n>::do_it(body).m_f;
}

template<typename RandomAccessIterator1, typename RandomAccessIterator2, typename UnaryFunction>
  struct transform1_closure
{
  RandomAccessIterator1 m_first;
  RandomAccessIterator2 m_result;
  UnaryFunction m_f;

  inline __host__ __device__
  transform1_closure(RandomAccessIterator1 first, RandomAccessIterator2 result, UnaryFunction f)
    : m_first(first), m_result(result), m_f(f)
  {}

  template<typename Integer>
  inline __host__ __device__
  void operator()(Integer i)
  {
    m_result[i] = m_f(m_first[i]);
  }
};

template<typename RandomAccessIterator1, typename RandomAccessIterator2, typename RandomAccessIterator3, typename BinaryFunction>
  struct transform2_closure
{
  RandomAccessIterator1 m_first1;
  RandomAccessIterator2 m_first2;
  RandomAccessIterator3 m_result;
  BinaryFunction m_f;

  inline __host__ __device__
  transform2_closure(RandomAccessIterator1 first1, RandomAccessIterator2 first2, RandomAccessIterator3 result, BinaryFunction f)
    : m_first1(first1), m_first2(first2), m_result(result), m_f(f)
  {}

  template<typename Integer>
  inline __host__ __device__
  void operator()(Integer i)
  {
    m_result[i] = m_f(m_first1[i], m_first2[i]);
  }
};

template<typename Generator>
  struct generate_closure
{
  Generator m_g;

  inline __host__ __device__
  generate_closure(Generator g)
    : m_g(g)
  {}

  template<typename T>
  inline __host__ __device__
  void operator()(T x)
  {
    x = m_g();
  }
};

template<typename T>
  struct fill_generator
{
  const T &m_val;

  inline __host__ __device__
  fill_generator(const T &val)
    : m_val(val)
  {}

  inline __host__ __device__
  const T &operator()() const
  {
    return m_val;
  }
};

template<typename RandomAccessIterator, typename T>
  struct iota_closure
{
  RandomAccessIterator m_iter;
  const T &m_val;

  inline __host__ __device__
  iota_closure(RandomAccessIterator iter, const T &val)
    : m_iter(iter), m_val(val)
  {}

  template<typename Integer>
  inline __host__ __device__
  void operator()(Integer x)
  {
    m_iter[x] = m_val + x;
  }
};

template<typename T, typename BinaryOperation>
  struct accumulate_closure
{
  T m_acc;
  BinaryOperation m_binary_op;

  inline __host__ __device__
  accumulate_closure(const T &init, BinaryOperation binary_op)
    : m_acc(init), m_binary_op(binary_op)
  {}

  template<typename U>
  inline __host__ __device__
  T operator()(const U &x)
  {
    m_acc = m_binary_op(m_acc, x);
    return m_acc;
  }
};

template<typename T, typename BinaryOperation1, typename BinaryOperation2>
  struct inner_product_closure
{
  T m_acc;
  BinaryOperation1 m_binary_op1;
  BinaryOperation2 m_binary_op2;

  inline __host__ __device__
  inner_product_closure(const T &init, BinaryOperation1 binary_op1, BinaryOperation2 binary_op2)
    : m_acc(init), m_binary_op1(binary_op1), m_binary_op2(binary_op2)
  {}

  template<typename U1, typename U2>
  inline __host__ __device__
  T operator()(const U1 &x, const U2 &y)
  {
    m_acc = m_binary_op1(m_acc, m_binary_op2(x,y));
    return m_acc;
  }
};

} // end detail

template<unsigned int first, unsigned int last, typename UnaryFunction>
inline __host__ __device__
UnaryFunction static_for(UnaryFunction f)
{
  return detail::static_for<first, last>::do_it(f);
}

template<unsigned int first, unsigned int last, unsigned int step, typename UnaryFunction>
inline __host__ __device__
UnaryFunction static_for(UnaryFunction f)
{
  return detail::static_for<first, last, step>::do_it(f);
}

template<unsigned int n, typename RandomAccessIterator, typename UnaryFunction>
inline __host__ __device__
UnaryFunction static_for_each(RandomAccessIterator first, UnaryFunction f)
{
  detail::for_each_closure<RandomAccessIterator,UnaryFunction> body(first, f);
  return static_for<0u,n>(body).m_f;
}

template<unsigned int n, typename T, typename UnaryFunction>
inline __host__ __device__
UnaryFunction static_for_each(T (&rng)[n], UnaryFunction f)
{
  return static_for_each<n>(&rng[0u], f);
}

template<unsigned int n, typename T, typename UnaryFunction>
inline __host__ __device__
UnaryFunction static_for_each(const T (&rng)[n], UnaryFunction f)
{
  return static_for_each<n>(&rng[0u], f);
}

template<unsigned int n, typename RandomAccessIterator, typename Generator>
inline __host__ __device__
void static_generate(RandomAccessIterator first, Generator g)
{
  detail::generate_closure<Generator> body(g);
  static_for_each<n>(first, body);
}

template<unsigned int n, typename T, typename Generator>
inline __host__ __device__
void static_generate(T (&rng)[n], Generator g)
{
  return static_generate<n>(&rng[0], g);
}

template<unsigned int n, typename RandomAccessIterator, typename T>
inline __host__ __device__
void static_fill(RandomAccessIterator first, const T &value)
{
  detail::fill_generator<T> body(value);
  static_generate<n>(first, body);
}

template<unsigned int n, typename T1, typename T2>
inline __host__ __device__
void static_fill(T1 (&rng)[n], const T2 &value)
{
  return static_fill<n>(&rng[0],value);
}

template<unsigned int n, typename RandomAccessIterator, typename T>
inline __host__ __device__
void static_iota(RandomAccessIterator first, const T &value)
{
  detail::iota_closure<RandomAccessIterator,T> body(first, value);
  static_for<0,n>(body);
}

template<unsigned int n, typename T1, typename T2>
inline __host__ __device__
void static_iota(T1 (&rng)[n], const T2 &value)
{
  return static_iota<n>(&rng[0], value);
}

template<unsigned int n, typename RandomAccessIterator1, typename RandomAccessIterator2, typename UnaryFunction>
inline __host__ __device__
void static_transform(RandomAccessIterator1 first, RandomAccessIterator2 result, UnaryFunction f)
{
  detail::transform1_closure<RandomAccessIterator1,RandomAccessIterator2,UnaryFunction> body(first,result,f);
  static_for<0,n>(body);
}

template<unsigned int n, typename T, typename RandomAccessIterator2, typename UnaryFunction>
inline __host__ __device__
void static_transform(const T (&rng1)[n], RandomAccessIterator2 result, UnaryFunction f)
{
  return static_transform<n>(&rng1[0], result, f);
}

template<unsigned int n, typename RandomAccessIterator1, typename RandomAccessIterator2, typename RandomAccessIterator3, typename BinaryFunction>
inline __host__ __device__
void static_transform(RandomAccessIterator1 first1, RandomAccessIterator2 first2, RandomAccessIterator3 result, BinaryFunction f)
{
  detail::transform2_closure<RandomAccessIterator1,RandomAccessIterator2,RandomAccessIterator3,BinaryFunction> body(first1,first2,result,f);
  static_for<0,n>(body);
}

template<unsigned int n, typename T, typename RandomAccessIterator1, typename RandomAccessIterator2, typename BinaryFunction>
inline __host__ __device__
void static_transform(const T (&rng1)[n], RandomAccessIterator1 first2, RandomAccessIterator2 result, BinaryFunction f)
{
  return static_transform<n>(&rng1[0], first2, result, f);
}

template<unsigned int n, typename RandomAccessIterator, typename T, typename BinaryFunction>
inline __host__ __device__
T static_accumulate(RandomAccessIterator first, T init, BinaryFunction binary_op)
{
  detail::accumulate_closure<T,BinaryFunction> body(init, binary_op);
  return static_for_each<n>(first, body).m_acc;
}

template<unsigned int n, typename T1, typename T2, typename BinaryFunction>
inline __host__ __device__
T2 static_accumulate(const T1 (&rng)[n], T2 init, BinaryFunction binary_op)
{
  return static_accumulate<n>(&rng[0], init, binary_op);
}

template<unsigned int n, typename RandomAccessIterator1, typename RandomAccessIterator2, typename BinaryOperation>
inline __host__ __device__
void static_partial_sum(RandomAccessIterator1 first, RandomAccessIterator2 result, BinaryOperation binary_op)
{
  if(n)
  {
    typedef typename std::iterator_traits<RandomAccessIterator1>::value_type value_type;
    value_type init = *first;
    *result = init;
    detail::accumulate_closure<value_type, BinaryOperation> body(init, binary_op);
    static_transform<n-1>(first + 1, result + 1, body);
  } // end if
}

template<unsigned int n, typename T, typename RandomAccessIterator, typename BinaryOperation>
inline __host__ __device__
void static_partial_sum(const T (&rng)[n], RandomAccessIterator result, BinaryOperation binary_op)
{
  return static_partial_sum<n>(&rng[0], result, binary_op);
}

template<unsigned int n, typename RandomAccessIterator1, typename RandomAccessIterator2, typename T, typename BinaryOperation1, typename BinaryOperation2>
inline __host__ __device__
T static_inner_product(RandomAccessIterator1 first1, RandomAccessIterator2 first2, T init, BinaryOperation1 binary_op1, BinaryOperation2 binary_op2)
{
  detail::inner_product_closure<T,BinaryOperation1,BinaryOperation2> body(init, binary_op1, binary_op2);
  return detail::static_for_each<n>(first1, first2, body).m_acc;
}

template<unsigned int n, typename T1, typename RandomAccessIterator, typename T2, typename BinaryOperation1, typename BinaryOperation2>
inline __host__ __device__
T2 static_inner_product(const T1 (&rng1)[n], RandomAccessIterator first2, T2 init, BinaryOperation1 binary_op1, BinaryOperation2 binary_op2)
{
  return static_inner_product<n>(&rng1[0], first2, init, binary_op1, binary_op2);
}

