#ifndef _EKF_H_
#define _EKF_H_

#include "math/EigenTypes.h"

#include <Eigen/LU>

#include <iostream>

class EKF
{
public:
  EKF(const VectorX &initialState, const MatrixX &initialStateCovariance)
    : x_(initialState), P_(initialStateCovariance)
  {}

  virtual ~EKF()
  {}

  template <typename TDynamicModel, typename... TControls>
  void predict(TDynamicModel dynamicModel, const MatrixX& processNoiseCovariance, TControls&&... u)
  {
    VectorXAD x = x_.cast<AutoDiffType>();
    VectorXAD fx;
    const MatrixX F = AutoDiff::jacobian(std::move<std::function<VectorXAD(const VectorXAD&, TControls&&...)>>(dynamicModel), AutoDiff::wrt(x), AutoDiff::at(x, std::forward<TControls>(u)...), fx);
    x_ = fx.cast<ScalarType>();
    const MatrixX FP = F * P_;
    P_ = processNoiseCovariance;
    P_.noalias() += FP * F.transpose();
    P_ += P_.transpose().eval();
    P_ *= 0.5;
  }
  
  template <typename TMeasurementModel, typename... TParameters>
  void update(TMeasurementModel measurementModel, const MatrixX& measurementNoiseCovariance, const VectorX& z, TParameters&&... p)
  {
    VectorXAD x = x_.cast<AutoDiffType>();
    VectorXAD hx;
    const MatrixX H = AutoDiff::jacobian(std::move<std::function<VectorXAD(const VectorXAD&, TParameters&&...)>>(measurementModel), AutoDiff::wrt(x), AutoDiff::at(x, std::forward<TParameters>(p)...), hx);
    const VectorX e = z - hx.cast<ScalarType>();
    const MatrixX PHT = P_ * H.transpose();
    const MatrixX S = H * PHT + measurementNoiseCovariance;
    const MatrixX K = PHT * S.inverse();
    x_ += K * e;
    const MatrixX HP = H * P_;
    P_.noalias() -= (K * HP);
    P_ += P_.transpose().eval();
    P_ *= 0.5;
  }

  VectorX getState() const
  {
    return x_;
  }

  MatrixX getCovariance() const
  {
    return P_;
  }

protected:
  MatrixX P_;
  VectorX x_;
};

#endif