#include "filtering/EKF.h"
#include "plotting/PyPlot.h"

#include <random>

int main()
{
  const ScalarType dt = 0.01;
  const ScalarType a = 1;
  const ScalarType w = 10;
  const ScalarType phi = 0;

  const ScalarType sigmaM = 0.5;
  const ScalarType sigmaA = 0.1;
  const ScalarType sigmaW = 0.2;

  const size_t samples = 1000;
  VectorX t = VectorX(samples);
  VectorX x = VectorX(samples);
  VectorX y = VectorX(samples);
  std::default_random_engine gen;
  std::normal_distribution<ScalarType> dist(0, sigmaM);
  for (size_t n = 0; n < samples; ++n)
  {
    t(n) = n * dt;
    x(n) = a * std::sin(w * t(n) + phi);
    y(n) = x(n) + dist(gen);
  }

  EKF ekf(Vector3(0.1, 0.1, 0.1), MatrixX::Identity(3, 3) * 3);

  Matrix3x3 Q = Matrix3x3::Zero();
  Q(0, 0) = dt * std::pow(sigmaA, 2);
  Q(1, 1) = dt * sigmaW;
  Q(2, 2) = std::pow(dt, 3)/3.0 * std::pow(sigmaW, 2);
  Q(1, 2) = std::pow(dt, 2)/2.0 * std::pow(sigmaW, 2);
  Q(2, 1) = std::pow(dt, 2)/2.0 * std::pow(sigmaW, 2);

  const Matrix2x2 R = Matrix2x2::Identity();

  VectorX xHat = VectorX(samples);
  for (size_t n = 0; n < samples; ++n)
  {
    ekf.predict([](const auto& x, const ScalarType& dt)
    {
      Matrix3x3 F = Matrix3x3::Identity();
      F(2, 1) = dt;
      return (F * x).eval();
    }, Q, dt);

    const Vector2 z = Vector2(y(n), 0);

    ekf.update([](const auto& x)
    {
      VectorXAD ret(2);
      ret << x(0) * sin(x(2)), 0;
      return ret;
    }, R, z);

    const Vector3 p = ekf.getState();
    xHat(n) = p(0) * std::sin(p(2));
  }

  PyPlot plt;
  plt().plot(Args(PyPlot::fromEigen(t), PyPlot::fromEigen(x)), Kwargs("color"_a = "black", "linestyle"_a = "dotted", "linewidth"_a = 1, "alpha"_a = 0.75, "label"_a = "ground truth"));
  plt().scatter(Args(PyPlot::fromEigen(t), PyPlot::fromEigen(y)), Kwargs("color"_a = "red", "marker"_a = "x", "s"_a = 5, "label"_a = "noisy observations"));
  plt().plot(Args(PyPlot::fromEigen(t), PyPlot::fromEigen(xHat)), Kwargs("color"_a = "blue", "label"_a = "EKF estimation"));
  plt().legend();
  plt().show();

  return 0;
}