template<typename T>
T vmin(T&&t)
{
  return std::forward<T>(t);
}

template<typename T0, typename T1, typename... Ts>
typename std::common_type<
  T0, T1, Ts...
>::type vmin(T0&& val1, T1&& val2, Ts&&... vs)
{
  if (val2 < val1)
    return vmin(val2, std::forward<Ts>(vs)...);
  else
    return vmin(val1, std::forward<Ts>(vs)...);
}

template<typename T>
T vmax(T&&t)
{
  return std::forward<T>(t);
}

template<typename T0, typename T1, typename... Ts>
typename std::common_type<
  T0, T1, Ts...
>::type vmax(T0&& val1, T1&& val2, Ts&&... vs)
{
  if (val2 < val1)
    return vmax(val1, std::forward<Ts>(vs)...);
  else
    return vmax(val2, std::forward<Ts>(vs)...);
}
