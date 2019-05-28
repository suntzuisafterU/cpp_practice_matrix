#include <iostream> // for std::logic_error

namespace Utils {
  class NotImplementedException : public std::logic_error{
    public: // private by default
      NotImplementedException() : std::logic_error{"Function not implemented.\n"} {} // What are the last 2 brackets for??
      /*                                    why curly braces here? ^ */
  };
}
