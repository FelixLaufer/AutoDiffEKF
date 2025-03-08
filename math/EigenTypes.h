#ifndef _EIGEN_TYPES_H_
#define _EIGEN_TYPES_H_

#include <autodiff/forward/real.hpp>
#include <autodiff/forward/real/eigen.hpp>
#include <complex>
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace AutoDiff = autodiff;

using ScalarType = double;
using ComplexType = std::complex<ScalarType>;
using AutoDiffType = AutoDiff::real;

using Quaternion = Eigen::Quaternion<ScalarType>;

using VectorX = Eigen::Matrix<ScalarType, -1, 1>;
using VectorXC = Eigen::Matrix<ComplexType, -1, 1>;
using VectorXAD = Eigen::Matrix<AutoDiffType, -1, 1>;

using MatrixX = Eigen::Matrix<ScalarType, -1, -1>;
using MatrixXC = Eigen::Matrix<ComplexType, -1, -1>;
using MatrixXAD = Eigen::Matrix<AutoDiffType, -1, -1>;

template <int N>
using VectorN = Eigen::Matrix<ScalarType, N, 1>;

template <int N>
using VectorNC = Eigen::Matrix<ComplexType, N, 1>;

template <int N>
using VectorNAD = Eigen::Matrix<AutoDiffType, N, 1>;

template <int N, int M>
using MatrixNxM = Eigen::Matrix<ScalarType, N, M>;

template <int N, int M>
using MatrixNxMC = Eigen::Matrix<ComplexType, N, M>;

template <int N, int M>
using MatrixNxMAD = Eigen::Matrix<AutoDiffType, N, M>;

using Vector2 = Eigen::Matrix<ScalarType, 2, 1>;
using Vector3 = Eigen::Matrix<ScalarType, 3, 1>;
using Vector4 = Eigen::Matrix<ScalarType, 4, 1>;
using Vector5 = Eigen::Matrix<ScalarType, 5, 1>;
using Vector6 = Eigen::Matrix<ScalarType, 6, 1>;
using Vector7 = Eigen::Matrix<ScalarType, 7, 1>;
using Vector8 = Eigen::Matrix<ScalarType, 8, 1>;
using Vector9 = Eigen::Matrix<ScalarType, 9, 1>;

using Matrix2x2 = Eigen::Matrix<ScalarType, 2, 2>;
using Matrix3x3 = Eigen::Matrix<ScalarType, 3, 3>;
using Matrix4x4 = Eigen::Matrix<ScalarType, 4, 4>;
using Matrix5x5 = Eigen::Matrix<ScalarType, 5, 5>;
using Matrix6x6 = Eigen::Matrix<ScalarType, 6, 6>;
using Matrix7x7 = Eigen::Matrix<ScalarType, 7, 7>;
using Matrix8x8 = Eigen::Matrix<ScalarType, 8, 8>;
using Matrix9x9 = Eigen::Matrix<ScalarType, 9, 9>;

#endif
