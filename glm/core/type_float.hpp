///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glm/core/type_float.hpp
/// @date 2008-08-22 / 2011-06-15
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#ifndef glm_core_type_float
#define glm_core_type_float

#include "setup.hpp"

namespace glm{
namespace detail
{
	typedef float				float32;
	typedef double				float64;
}//namespace detail
	
	typedef float				lowp_float_t;
	typedef float				mediump_float_t;
	typedef double				highp_float_t;

	/// @addtogroup core_precision
	/// @{

	/// Low precision floating-point numbers. 
	/// There is no guarantee on the actual precision.
	/// 
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.4 Floats</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef lowp_float_t		lowp_float;

	/// Medium precision floating-point numbers.
	/// There is no guarantee on the actual precision.
	/// 
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.4 Floats</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mediump_float_t		mediump_float;

	/// High precision floating-point numbers.
	/// There is no guarantee on the actual precision.
	/// 
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.4 Floats</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef highp_float_t		highp_float;

#if(!defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef mediump_float		float_t;
#elif(defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef highp_float			float_t;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef mediump_float		float_t;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && defined(GLM_PRECISION_LOWP_FLOAT))
	typedef lowp_float			float_t;
#else
#	error "GLM error: multiple default precision requested for floating-point types"
#endif

	typedef float				float32;
	typedef double				float64;

////////////////////
// check type sizes
#ifndef GLM_STATIC_ASSERT_NULL
	GLM_STATIC_ASSERT(sizeof(glm::float32) == 4, "float32 size isn't 4 bytes on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::float64) == 8, "float64 size isn't 8 bytes on this platform");
#endif//GLM_STATIC_ASSERT_NULL

	/// @}

namespace detail
{
	//////////////////
	// float
	
	template <typename T>
	struct is_float
	{
		enum is_float_enum
		{
			_YES = 0,
			_NO = 1
		};
	};
	
	#define GLM_DETAIL_IS_FLOAT(T)	\
	template <>					\
	struct is_float<T>			\
	{							\
		enum is_float_enum		\
		{						\
			_YES = 1,			\
			_NO = 0				\
		};						\
	}
	
	////////////////////
	// Mark half to be flaot
	GLM_DETAIL_IS_FLOAT(float);
	GLM_DETAIL_IS_FLOAT(double);
	GLM_DETAIL_IS_FLOAT(long double);

	template <>
	struct float_or_int_trait<float32>
	{
		enum{ID = float_or_int_value::GLM_FLOAT};
	};

	template <>
	struct float_or_int_trait<float64>
	{
		enum{ID = float_or_int_value::GLM_FLOAT};
	};
	
	union uif64
	{
		GLM_FUNC_QUALIFIER uif64() :
		i(0)
		{}
		
		GLM_FUNC_QUALIFIER uif64(double f) :
		f(f)
		{}
		
		GLM_FUNC_QUALIFIER uif64(uint64 i) :
		i(i)
		{}
		
		double f;
		uint64 i;
	};
		
	//////////////////
	// type
		
	template <typename T>
	struct type
	{
		enum type_enum
		{
			is_float = is_float<T>::_YES,
			is_int = is_int<T>::_YES,
			is_uint = is_uint<T>::_YES,
			is_bool = is_bool<T>::_YES
		};
	};
}//namespace detail
}//namespace glm

#endif//glm_core_type_float
