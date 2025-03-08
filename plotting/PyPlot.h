#ifndef _PY_PLOT_H_
#define _PY_PLOT_H_

#include "math/EigenTypes.h"

#include <matplotlibcpp17/pyplot.h>
#include <memory>

class __attribute__ ((visibility("hidden"))) PyPlot
{
public:
  PyPlot()
    : guard_()
    , plt_(matplotlibcpp17::pyplot::import())
  {
    putenv(const_cast<char*>(std::string("XDG_SESSION_TYPE=x11").c_str()));
  }

  auto& operator()()
  { 
    return plt_;
  }

  static std::vector<ScalarType> fromEigen(const VectorX& v)
  {
    return std::vector<ScalarType>(v.data(), v.data() + v.size());
  }

private:
  pybind11::scoped_interpreter guard_;
  matplotlibcpp17::pyplot::PyPlot plt_;
};

#endif