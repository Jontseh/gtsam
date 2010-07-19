/**
 * @file    simulated2DOriented
 * @brief   measurement functions and derivatives for simulated 2D robot
 * @author  Frank Dellaert
 */

#include "simulated2DOriented.h"
#include "TupleConfig-inl.h"

namespace gtsam {

	using namespace simulated2DOriented;
//	INSTANTIATE_LIE_CONFIG(PointKey, Point2)
//	INSTANTIATE_NONLINEAR_FACTOR_GRAPH(Config)
//	INSTANTIATE_NONLINEAR_OPTIMIZER(Graph, Config)

	namespace simulated2DOriented {

		static Matrix I = gtsam::eye(3);

		/* ************************************************************************* */
		Pose2 prior(const Pose2& x, boost::optional<Matrix&> H) {
			if (H) *H = I;
			return x;
		}

		/* ************************************************************************* */
		Pose2 odo(const Pose2& x1, const Pose2& x2, boost::optional<Matrix&> H1,
				boost::optional<Matrix&> H2) {
			return between(x1, x2, H1, H2);
		}

	/* ************************************************************************* */

	} // namespace simulated2DOriented
} // namespace gtsam
