#ifndef Object_hpp
#define Object_hpp

#include <ostream>

class Object
{
	public:
	  int id;
	  int weight;
	  double value;
	  double value_per_unit_weight;

	  Object(int i, int w, double v);

	  inline bool operator< (const Object& obj) const
	  {
	    return value_per_unit_weight < obj.value_per_unit_weight;
	  }

	  friend std::ostream& operator<< (std::ostream& os, const Object& obj);
};
#endif //Object_hpp
