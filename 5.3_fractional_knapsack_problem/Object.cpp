#include "Object.hpp"

Object::Object(int i, int w, double v)
  : id(i), weight(w), value(v), value_per_unit_weight(v / w)
{
}

std::ostream& operator<< (std::ostream& os, const Object& obj)
{
  os << "[" << obj.id << "] 가격: " << obj.value << " \t무게: " << obj.weight << " \t단위 무게당 가격: " << obj.value_per_unit_weight;
	return os;
}
