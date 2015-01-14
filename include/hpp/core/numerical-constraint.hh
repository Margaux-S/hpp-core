// Copyright (c) 2015, LAAS-CNRS
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of hpp-core.
// hpp-core is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-core is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-core. If not, see <http://www.gnu.org/licenses/>.


#ifndef HPP_CORE_NUMERICALCONSTRAINT_HH
# define HPP_CORE_NUMERICALCONSTRAINT_HH

# include <hpp/core/equation.hh>

namespace hpp {
  namespace core {
    /// \addtogroup constraints
    /// \{

    /// With the same notation as in Equation, this class represents equation:
    /// \li that cannot be explicitely defined;
    /// \li in which \f$ f \f$ is a differentiable function.
    class HPP_CORE_DLLAPI NumericalConstraint : public Equation {
      public:
        /// Create a shared pointer to a new instance.
        /// \sa constructors
        static NumericalConstraintPtr_t create (const DifferentiableFunctionPtr_t& function,
            ComparisonTypePtr_t comp = ComparisonType::createDefault());

        /// Create a shared pointer to a new instance.
        /// \sa constructors
        static NumericalConstraintPtr_t create (const DifferentiableFunctionPtr_t& function,
            ComparisonTypePtr_t comp, vectorIn_t rhs);

        /// \sa Equation::rightHandSideFromConfig
        void rightHandSideFromConfig (ConfigurationIn_t config);

        /// Return a reference to the inner function.
        DifferentiableFunction& function () const;

        /// Return a reference to the value.
        /// This vector can be used to store the output of the function,
        /// its size being initialized.
        vector_t& value ()
        {
          return value_;
        }

        /// Return a reference to the jacobian.
        /// This matrix can be used to store the derivative of the function,
        /// its size being initialized.
        matrix_t& jacobian ()
        {
          return jacobian_;
        }

      protected:
        /// Constructor
        /// \param function the differentiable function
        NumericalConstraint (const DifferentiableFunctionPtr_t& function,
            ComparisonTypePtr_t comp = ComparisonType::createDefault());

        /// Constructor
        /// \param function the differentiable function
        /// \param rhs the right hand side of this equation
        NumericalConstraint (const DifferentiableFunctionPtr_t& function,
            ComparisonTypePtr_t comp, vectorIn_t rhs);

      private:
        DifferentiableFunctionPtr_t function_;

        vector_t value_;
        matrix_t jacobian_;
    };
    /// \}
  } // namespace core
} // namespace hpp

#endif // HPP_CORE_NUMERICALCONSTRAINT_HH