#ifndef _KF_H_
#define _KF_H_

#include "math/EigenTypes.h"

class KF
{
public:
  KF(const VectorX& x, const MatrixX& P)
    : x_(x), P_(P)
  {}

  virtual ~KF()
  {}

  void predict(const MatrixX& F, const VectorX& u, const MatrixX& Q)
  {
    x_ = F * x_ + u;
    const MatrixX FP = F * P_;
    P_ = Q;
    P_.noalias() += FP * F.transpose();
    P_ += P_.transpose().eval();
    P_ *= 0.5;
  }

  void predict(const MatrixX& F, const MatrixX& Q)
  {
    x_ = F * x_;
    const MatrixX FP = F * P_;
    P_ = Q;
    P_.noalias() += FP * F.transpose();
    P_ += P_.transpose().eval();
    P_ *= 0.5;
  }

  void update(const MatrixX& H, const VectorX& z, const MatrixX& R)
  {
    const MatrixX PHT = P_ * H.transpose();
    const MatrixX S = H * PHT + R;
    const MatrixX K = PHT * S.inverse();
    const VectorX e = z - H * x_;
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