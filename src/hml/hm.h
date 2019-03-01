/*
===================================================================================================
================================================ENG================================================
===================================================================================================

Handy Math Library
Copyright (C) 2005  Alexander Tretyak (tav86@mail.ru)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA



BRIEF DOCUMENTATION:


Configuring Library:

Initially, library represents matrices in column major order.
Vectorization for 4D vectors initially is enabled.
To change this behaviour define some of following constants before including "hm.h":

CONSTANT                         DESCRIPTION
==============================   ==================================================================
#define D3D_MAT_STYLE            Represents matrices in row major order. But because of particular
                                 treatment of matrices in D3D it affects just on matrix-matrix,
                                 matrix-vector and vector-matrix multiplications.
#define QUAT_MUL_REVERSE_ORDER   If this constant is defined, multiplications of quaternions and
                                 quaternion by 3D-vector are performed in inverse order, so
                                 for the multiply operator the left argument of expression should
                                 be a 3D-vector and the right should be a quaternion.
#define DISABLE_VECTORIZATION    Disable vectorization for Tvec4 types.


Supported Types:

TvecN - vector,

  where T - type of vector's components:

    T       Corresponding HM type
    --      ---------------------
    b       HMbool
    i       HMint
    d       HMdouble
    ld      HMlong_double
    s       HMshort
    us      HMushort
    ub      HMubyte

  If T is missing, then vector's components are of type HMfloat.

  N represent the dimension of the vector.

  The names of the components of a vector are denoted by a single letter. As a notational
  convenience, several letters are associated with each component based on common usage of
  position, color or texture coordinate vectors. The individual components of a vector can be
  selected by following the variable name with period ( . ) and then the component name.
  The component names supported are:
  {x, y, z, w} useful when accessing vectors that represent points or normals
  {r, g, b, a} useful when accessing vectors that represent colors
  {s, t, p, q} useful when accessing vectors that represent texture coordinates
  The component names x, r, and s are, for example, synonyms for the same (first) component in a
  vector.
  Note that the third component of a texture, r in OpenGL, has been renamed p so as to avoid the
  confusion with r (for red) in a color.
  The component selection syntax allows multiple components to be selected by appending their names
  (from the same name set) with parentheses after the period ( . ). Example: vec4 v4; v4.yzw();
  Array subscripting syntax can also be applied to vectors to provide numeric indexing. So in
  pos[2] refers to the third element of pos and is equivalent to pos.z.

TmatN - matrix, where T (one of 'i','d' and 'ld') and N have the same meaning that in TvecN.

  If T is missing, then matrix's components are of type HMfloat.

  The components of a matrix can be accessed using array subscripting syntax. Applying a single
  subscript to a matrix treats the matrix as an array of column vectors, and selects a single
  column, whose type is a vector of the same size as the matrix. The leftmost column is column 0.
  A second subscript would then operate on the column vector, as defined earlier for vectors.
  Hence, two subscripts select a column and then a row.

Tquat - quaternion, where T (either 'd' or 'ld') has the same meaning that in Tvec4.

  If T is missing, then quaternion's components are of type HMfloat.

  The component names of a quaternion supported are x, y, z, and w. Also .xyz() can be used to
  select first 3 components of the quaternion (i.e. vector of quaternion) as a separate 3D-vector.

Taabb - axis aligned bounding box, where T (one of 'i','s','d' and 'ld') has the same meaning that
        in Tvec3.

  If T is missing, then box's components are of type HMfloat.

  Box consists of two bounding 3D-vectors of corresponding type: min and max. Each of them can be
  accessed by appending its name after the period ( . ). Example: aabb b; b.min;

Trect - rectangle, where T (one of 'i','s','d' and 'ld') has the same meaning that in Tvec2.

  If T is missing, then rectangle's components are of type HMfloat.

  Rectangle consists of two bounding 2D-vectors of corresponding type: min and max. Each of them
  can be accessed by appending its name after the period ( . ). Example: rect r; r.max;


Constructors:

  Constructors can be used to create vectors, matrices, or quaternions from a set of scalars,
vectors, matrices, or quaternions.
  If there is a single scalar parameter to a vector constructor, it is used to initialize all
components of the constructed vector to that scalar�s value. If there is a single scalar parameter
to a matrix constructor, it is used to initialize all the components on the matrix�s diagonal, with
the remaining components initialized to 0.0. If there is a single scalar parameter to a quaternion
constructor, it is used to initialize the scalar of quaternion (i.e. value of component w), with
the remaining components (x,y,z) initialized to 0.0. If there is a single 3D-vector parameter to a
quaternion constructor, it is used to initialize the vector of quaternion (i.e. first 3 components
of quaternion), with the remaining component w initialized to 0.0. If there are 4 scalar parameters
to a quaternion constructor, they are used to initialize all the components of the quaternion. If
there is a single scalar parameter to an aabb/rect constructor it is used to initialize vector min
to the negative of that scalar's value and max to that scalar�s value; but if scalar�s value is
zero, constructor creates a null aabb/rect, i.e. such aabb/rect that contains empty volume. If
there are 2 scalar or 2 vector parameters to an aabb/rect constructor, vector construction rules
are used to initialize vector min to the first parameter and vector max to the second parameter.
  Vectors can be constructed from multiple vector parameters, and/or multiple scalar parameters,
than they will be assigned in order, from left to right, to the components of the constructed
vector. In this case, there must be enough (but no more) components provided in the parameters to
provide an initializer for every component in the constructed vector. Matrices will be constructed
in column major order, and can be constructed from multiple scalar parameters with number of
matrix's components or from multiple vector parameters. In last case, number of vectors to
initialize the matrix and their dimension must be equal to the dimension of the constructed matrix.
  Matrices can be constructed from other matrices. If matrix is constructed from greater dimension
matrix, then its submatrix starting with first element is used to initialize all components of the
constructed matrix. If matrix is constructed from less dimension matrix, then it is used to
initialize submatrix of the constructed matrix starting with first element. The remaining
components initialized to 1.0 if they are on the matrix�s diagonal, and 0.0 otherwise.
  Also matrices can be constructed by the rules used to construct matrices with less dimension,
i.e. 4D-matrix can be constructed from two 2D-vectors, or three 3D-vectors, or 9 scalar parameters
(as to construct 3D-matrix) and etc. In this case, rules of matrix construction from less dimension
matrix are used.
  Remaining allowable constructors are listed below:

CONSTRUCTOR                     DESCRIPTION
=============================   ===================================================================
mat3(quat q,                    Constructs a 3D-matrix from quaternion q. If quatIsUnit==true,
     bool quatIsUnit=false)     q must be unit quaternion.

mat4(quat q,                    Constructs a 4D-matrix from quaternion q. If quatIsUnit==true,
     bool quatIsUnit=false)     q must be unit quaternion.

quat(mat3 M,                    Constructs a quaternion from the 3D-matrix M. If quatIsUnit==true
     bool quatIsUnit=false)     constructed quaternion is unit. Matrix must contain only rotation
                                transform in order to achieve the desired result.

quat(mat4 M,                    Constructs a quaternion from the 4D-matrix M. If quatIsUnit==true
     bool quatIsUnit=false)     constructed quaternion is unit. Matrix must contain only rotation
                                transform in order to achieve the desired result.

quat(vec3 v,float alpha)        Constructs a quaternion that rotates around v on alpha radians.
                                Vector v mustn't be normalized.

aabb(uint count,                Constructs an aabb that bounds count points from array vertices[].
     vec3 vertices[])

rect(uint count,                Constructs a rectangle that bounds count points from array
     vec2 vertices[])           vertices[].


Operations:

  Assignments of values to variable names are done with the assignment operator ( = ), like
  lvalue = expression
  The assignment operator stores the value of expression into lvalue. Expression and lvalue must
have the same type. All desired type-conversions must be specified explicitly via a constructor.
  Other assignment operators are the arithmetic assignments add into (+=), subtract from (-=),
multiply into (*=), and divide into (/=). The expression "lvalue op= expression" is equivalent to
"lvalue = lvalue op expression" and the lvalue and expression must satisfy the semantic
requirements of both op and equals (=).
  The arithmetic binary operators supported are add (+), subtract (-), multiply (*), and
divide (/). The two operands must be the same type, or one can be a scalar and the other a vector,
matrix, or quaternion. Additionally, for multiply (*), one can be a vector and the other a matrix
with the same dimensional size of the vector, or one can be a quaternion and the other a 3D-vector.
If one operand is scalar and the other is a vector, matrix, or quaternion the scalar is applied
component-wise to the vector, matrix, or quaternion, resulting in the same type as the vector,
matrix, or quaternion.
  Multiply (*) applied to two vectors yields a component-wise multiply. Multiply (*) applied to two
matrices yields a linear algebraic matrix multiply, not a component-wise multiply. Multiply (*)
applied to two quaternions yields an algebraic quaternion multiply, not a component-wise multiply.
  If the left argument of expression is a vector and the right is a matrix with a compatible
dimension, then multiply operator (*) will do a row vector matrix multiplication, and will result
in the same type as the vector.
  If the left argument of expression is a matrix and the right is a vector with a compatible
dimension, then multiply operator (*) will do a column vector matrix multiplication, and will
result in the same type as the vector.
  If the left argument of expression is a quaternion and the right is a 3D-vector, then multiply
operator (*) will rotate the vector by quaternion, and will result in the same type as the vector.
  Use functions dot, cross, and matrixCompMult to get, respectively, vector dot product, vector
cross product, and matrix component-wise multiplication.
  The arithmetic unary operators supported are negate (-), post- and pre-increment and decrement
(-- and ++) that operate on vectors and matrices. These result with the same type they operated on.
For post- and pre-increment and decrement, the expression must be one that could be assigned to (an
l-value). Pre-increment and predecrement add or subtract 1 or 1.0 to the contents of the expression
they operate on, and the value of the pre-increment or pre-decrement expression is the resulting
value of that modification. Post-increment and post-decrement expressions add or subtract 1 or 1.0
to the contents of the expression they operate on, but the resulting expression has the
expression�s value before the post-increment or post-decrement was executed.
  The equality operators equal (==) and not equal (!=) operate on all supported types. They result
in a scalar HMbool. All components of the operands must be equal for the operands to be considered
equal. To get component-wise equality results for vectors, use functions equal and notEqual.

Vector and Matrix Operations:

  With a few exceptions, operations are component-wise. When an operator operates on a vector or
matrix, it is operating independently on each component of the vector or matrix, in a
component-wise fashion. For example,
  vec3 v, u;
  HMfloat f;

  v = u + f;
  will be equivalent to
  v.x = u.x + f;
  v.y = u.y + f;
  v.z = u.z + f;

  And

  vec3 v, u, w;
  w = v * u;
  will be equivalent to
  w.x = v.x * u.x;
  w.y = v.y * u.y;
  w.z = v.z * u.z;

  and likewise for most operators. The exceptions are matrix multiplied by vector, vector
multiplied by matrix, and matrix multiplied by matrix. These do not operate component-wise, but
rather perform the correct linear algebraic multiply. They require the size of the operands match.
  All unary operations works component-wise on their operands. For binary arithmetic operations, if
the two operands are the same type, then the operation is done component-wise and produces a result
that is the same type as the operands. If one operand is a scalar and the other operand is a vector
or matrix, then the operation proceeds as if the scalar value was replicated to form a matching
vector or matrix operand.

Quaternion Operations:

  Multiply (*) and divide (/) applied to a quaternion and a scalar yields a component-wise multiply
or divide, respectively. Add (+) and subtract (-) applied to two quaternions yields a
component-wise add or subtract, respectively. Multiply (*) applied to two quaternions perform an
algebraic quaternion multiply. Multiply (*) applied to a quaternion as the left argument and a
3D-vector as the right will rotate the vector by quaternion, and will result the rotated vector.
  Other arguments for binary operators add (+), subtract (-), multiply (*), and divide (/) are not
defined and using them will result in an error.
  Unary negation operator (-) works component-wise on quaternions.

AABB/Rectangle Operations:

  Add (+) applied to two aabbs/rectangles will result in union of the operands, i.e. such
aabb/rectangle that contains both of the operands. Multiply (*) applied to two aabbs/rectangles
will result in intersection of the operands, which has the same type as they are. Add (+) applied
to an aabb/rectangle and a 3D/2D-vector will expand aabb/rectangle so that it will be contain
this vector, and returns the resulting aabb/rectangle.


Supported Functions:

When functions are specified below, where the input arguments (and corresponding output) can be
HMfloat, vec2, vec3, vec4, HMdouble, dvec2, dvec3, dvec4, HMlong_double, ldvec2, ldvec3, or ldvec4,
genType is used as the argument. Similarly, vec is used to denote any type vectors, mat - to denote
any type matrices and so on for all library types.
Also float is used to denote any supported floating point type: HMfloat, HMdouble or HMlong_double.
And genTypeInt is used to denote HMint, ivec2, ivec3, or ivec4.

SYNTAX                                    DESCRIPTION

=======================================   =========================================================

                                    ------TYPE CAST FUNCTIONS------

#vec vec_cast<#vec>(vec v)                Converts vector v to the type of #vec. Example:
                                            ivec3 a,b;
                                            ldvec3 c=vec_cast<ldvec3>(a+b);

#mat mat_cast<#mat>(mat m)                Converts matrix m to the type of #mat. Example:
                                            mat3 a=mat3(1);
                                            dmat4 b=mat_cast<dmat4>(a);//mat_cast<dmat4>(a) returns
                                                                       //the identity 4D matrix

#quat quat_cast<#quat>(quat q)            Converts quaternion q to the type of #quat. Example:
                                            dvec3 v; dquat q;
                                            quat r=quat_cast<quat>(q*dquat(v)*conjugate(q));

#aabb aabb_cast<#aabb>(aabb b)            Converts aabb b to the type of #aabb.

#rect rect_cast<#rect>(rect r)            Converts rectangle r to the type of #rect.

                                    ------ANGLE FUNCTIONS------

genType radians(genType deg)              Converts degrees to radians and returns the result.
genType degrees(genType rad)              Converts radians to degrees and returns the result.

                                    ------EXPONENTIAL FUNCTIONS------

genType exp2(genType x)                   Returns 2 raised to the x power.

genType log2(genType x)                   Returns the base 2 logarithm of x, i.e., returns the
                                          value y which satisfies the equation x = 2^y.
                                          Result is undefined if x <= 0.

genType inversesqrt(genType x)            Returns the reciprocal of the positive square root of x.
                                          Result is undefined if x <= 0.

                                    ------PSEUDORANDOM NUMBER GENERATOR FUNCTIONS------

uint random(uint randMax)                 Returns a pseudorandom integer in the range 0 to randMax.

uint random(uint randMin,                 Returns a pseudorandom integer in the range randMin to
            uint randMax)                 randMax.

long_double random(long_double randMax)   Returns a pseudorandom float in the range 0.0 to randMax.

long_double random(long_double randMin,   Returns a pseudorandom float in the range randMin to
                   long_double randMax)   randMax.

void rseed(uint seed)                     Sets a seed for random-number generation, i.e. the
                                          starting point for generating a series of pseudorandom
                                          integers or floats.

                                    ------COMMON FUNCTIONS------

genType square(genType x)                 Returns the square of x.

genType sign(genType x)                   Returns 1.0 if x > 0, 0.0 if x = 0, and �1.0 if x < 0.

genType fract(genType x)                  Returns x - floor (x).

genType mod(genType x, genType y)         Modulus. Returns x - y*floor(x/y).

genType wrap(genType x,                   Wraps x at range [0,maxVal). Returns mod(x,y).
             genType maxVal)

genType wrap(genType x,                   Wraps x at range [minVal,maxVal).
             genType minVal,              Returns mod(x-minVal, maxVal-minVal) + minVal.
             genType maxVal)

genType min(genType v)                    Returns the minimal of the v components.

genType min(genType x, genType y)         Returns y if y < x, otherwise it returns x.

genType min(genType x,                    Returns the minimal value of x, y and z.
            genType y,
            genType z)

genType min(genType x,                    Returns the minimal value of x, y, z and w.
            genType y,
            genType z,
            genType w)

genType max(genType v)                    Returns the maximal of the v components.

genType max(genType x, genType y)         Returns y if x < y, otherwise it returns x.

genType max(genType x,                    Returns the maximal value of x, y and z.
            genType y,
            genType z)

genType max(genType x,                    Returns the maximal value of x, y, z and w.
            genType y,
            genType z,
            genType w)

genType clamp(genType x,                  Returns min (max (x, minVal), maxVal).
              genType minVal,
              genType maxVal)

genType mix (genType x,                   Returns x * (1 - a) + y * a, i.e., the linear blend of
             genType y,                   x and y.
             genType2 a)

genType lerp(genType x,                   The same as mix(x,y,a).
             genType y,
             genType2 a)

genType cerp(genType x,                   Performs Cosine intERPolation (CERP) between x and y.
             genType y,
             genType2 a)

genType herp3(genType x,                  Performs Hermite intERPolation (HERP) between x and y
              genType y,                  using polynomial of degree 3.
              genType2 a)

genType herp5(genType x,                  Performs Hermite intERPolation (HERP) between x and y
              genType y,                  using polynomial of degree 5.
              genType2 a)

genType step(genType edge, genType x)     Returns 0.0 if x < edge, otherwise it returns 1.0.

genType smoothstep(genType edge0,         Returns 0.0 if x <= edge0 and 1.0 if x >= edge1 and
                   genType edge1,         performs smooth Hermite interpolation between 0 and 1
                   genType x)             when edge0 < x < edge1. This is useful in cases where you
                                          would want a threshold function with a smooth transition.
										  This is equivalent to:
                                            genType t;
                                            t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
                                            return t * t * (3 - 2 * t);

                                    ------GEOMETRIC FUNCTIONS------

float dot(genType v0, genType v1)         Returns the dot product of v0 and v1.

float length(genType v)                   Returns the length of vector v.

float sqlen(genType v)                    Returns the squared length of vector v.

float distance(genType p0, genType p1)    Returns the distance between p0 and p1, i.e.
                                          length (p0 � p1).

vec3 cross(vec3 v0, vec3 v1)              Returns the cross product of v0 and v1.

genType normalize(genType v)              Returns a vector in the same direction as v but with a
                                          length of 1.

vec2 perp(vec2 v)                         Returns the perpendicular of vector v, i.e.
                                          vec2(-v.y, v.x).

vec3 perp(vec3 v)                         Returns the perpendicular of vector v.

vec3 slerp(vec3 v1,vec3 v2,float t)       Returns Spherical Linear intERPolation (SLERP) of vectors
                                          v1 and v2.

genType faceforward(genType N,            If dot (Nref, I) < 0 return N otherwise return �N.
                    genType I,
                    genType Nref)

genType reflect(genType V, genType N)     For the incident vector V and surface orientation N,
                                          returns the reflection direction:
                                            result = V - 2*dot(N,V)*N;
                                          N must already be normalized in order to achieve the
                                          desired result.
genType reflect(genType V, vec4 Plane)    For the incident vector V and plane Plane, returns the
                                          reflection direction.
                                          Plane must already be normalized in order to achieve the
                                          desired result.

genType refract(genType V,                For the incident vector V and surface normal N, and the
                genType N,                ratio of indices of refraction eta, return the refraction
                float eta)                vector. The returned result is computed by
                                            k = 1.0 - eta * eta * (1.0 - dot(N, V) * dot(N, V))
                                            if (k < 0.0)
                                                result = genType(0.0)
                                            else
                                                result = eta * V - (eta * dot(N, V) + sqrt(k)) * N
                                          The input parameters for the incident vector V and
                                          the surface normal N must already be normalized
                                          to get the desired results.

                                    ------MATRIX FUNCTIONS------

mat matrixCompMult(mat x, mat y)          Multiply matrix x by matrix y component-wise, i.e.,
                                          result[i][j] is the scalar product of x[i][j] and
                                          y[i][j].
                                          Note: to get linear algebraic matrix multiplication, use
                                          the multiply operator (*).

mat inverse(mat m)                        Returns the inverse of matrix m.

mat transpose(mat m)                      Returns the transpose of matrix m.

mat3 orthonormalize(mat3 m)               Returns the orthonormalized matrix m.

mat4 scalingMat(vec3 s)                   Returns the matrix m which satisfies the equation
mat4 scalingMat4(vec3 s)                  m*vec4(v,1.0) = vec4(s*v,1.0), where v - arbitrary three-
                                          dimensional vector.

mat3 scalingMat3(vec3 s)                  Returns the matrix m which satisfies the equation
                                          m*v = s*v, where v - arbitrary three-dimensional vector.

mat3 scalingMat(vec2 s)                   Returns the matrix m which satisfies the equation
mat3 scalingMat3(vec2 s)                  m*vec3(v,1.0) = vec3(s*v,1.0), where v - arbitrary two-
                                          dimensional vector.

mat2 scalingMat2(vec2 s)                  Returns the matrix m which satisfies the equation
                                          m*v = s*v, where v - arbitrary two-dimensional vector.

mat4 translationMat(vec3 tr)              Returns the matrix m which satisfies the equation
mat4 translationMat4(vec3 tr)             m*vec4(v,1.0) = vec4(tr+v,1.0), where v - arbitrary
                                          three-dimensional vector.

mat3 translationMat(vec2 tr)              Returns the matrix m which satisfies the equation
mat3 translationMat3(vec2 tr)             m*vec3(v,1.0) = vec3(tr+v,1.0), where v - arbitrary two-
                                          dimensional vector.

mat3 crossMat(vec3 n)                     Returns the matrix m which satisfies the equation
mat3 crossMat3(vec3 n)                    m*v = cross(n,v), where v - arbitrary three-dimensional
                                          vector.

mat4 crossMat4(vec3 n)                    Returns the matrix m which satisfies the equation
                                          m*vec4(v,1.0) = vec4(cross(n,v),1.0), where v - arbitrary
                                          three-dimensional vector.

                                    ------VECTOR RELATIONAL FUNCTIONS------

bvec isZero(vec v)                        Returns the component-wise compare of v == 0.
bvec notZero(vec v)                       Returns the component-wise compare of v != 0.
bvec lessThan(vec a, vec b)               Returns the component-wise compare of a < b.
bvec lessThanEqual(vec a, vec b)          Returns the component-wise compare of a <= b.
bvec greaterThan(vec a, vec b)            Returns the component-wise compare of a > b.
bvec greaterThanEqual(vec a, vec b)       Returns the component-wise compare of a >= b.
bvec equal(vec a, vec b)                  Returns the component-wise compare of a == b.
bvec notEqual(vec a, vec b)               Returns the component-wise compare of a != b.
bool any(bvec v)                          Returns true if any component of v is true.
bool all(bvec v)                          Returns true only if all components of v are true.
bvec not(bvec v)                          Returns the component-wise logical complement of v.

                                    ------NOISE FUNCTIONS------

  The noise functions below are defined to have the following characteristics:
� The return value(s) are uniform distrubuted in the range [-1.0,1.0].
� The return value(s) have an overall average of 0.0.
� They are repeatable, in that a particular input value will always produce the same return value.
� The spatial frequency is 1.0.
� Their period is 2.0^32.

float noise1(genType v,ferp=herp5)        Returns a 1D noise value based on the input value v.
 vec2 noise2(genType v,ferp=herp5)        Returns a 2D noise value based on the input value v.
 vec3 noise3(genType v,ferp=herp5)        Returns a 3D noise value based on the input value v.
 vec4 noise4(genType v,ferp=herp5)        Returns a 4D noise value based on the input value v.

  int noise1(genTypeInt v)                Returns a 1D noise value based on the input value v.
ivec2 noise2(genTypeInt v)                Returns a 2D noise value based on the input value v.
ivec3 noise3(genTypeInt v)                Returns a 3D noise value based on the input value v.
ivec4 noise4(genTypeInt v)                Returns a 4D noise value based on the input value v.

                                    ------PSEUDO-PLANE FUNCTIONS------

vec3 planeNormal(vec3 p0,                 Returns the normal of plane containing points p0, p1 and
                 vec3 p1,                 p2.
				 vec3 p2)

vec4 plane(vec3 p0, vec3 p1, vec3 p2)     Constructs a plane from 3 point lying in that plane.

vec4 plane(vec3 n, vec3 p)                Constructs a plane from normal and point lying in this
                                          plane.

vec4 unitPlane(vec3 p0,                   Constructs a unit plane from 3 point lying in that plane.
               vec3 p1,
			   vec3 p2)

vec4 unitPlane(vec3 n, vec3 p)            Constructs a unit plane from normal and point lying in
                                          this plane.

vec4 normalizePlane(vec4 Plane)           Converts Plane to the unit plane and returns the result.

vec4 translatePlane(vec4 Plane,vec3 tr)   Move Plane on the vector tr and returns the result.

vec3 planePoint(vec4 Plane)               Returns a point lying in the specified plane.

vec3 unitPlanePoint(vec4 Plane)           Returns a point lying in the specified unit plane.

vec4 reflectPlane(vec4 Plane,             For the incident plane Plane and unit plane R, returns
                  vec4 R)                 the Plane reflected relative to R.
                                          Plane R must already be normalized in order to achieve
                                          the desired result. But Plane mustn't be normalized.

float planeDist(vec4 Plane, vec3 point)   Returns the distance between plane Plane and point.

float planeDist(vec4 Plane, vec4 point)   Returns the distance between plane Plane and point in
                                          homogeneous coordinates.

float unitPlaneDist(vec4 Plane,           Returns the distance between unit plane Plane and point.
                    vec3 point)

float unitPlaneDist(vec4 Plane,           Returns the distance between unit plane Plane and point
                    vec4 point)           in homogeneous coordinates.

bool onPlane(vec4 Plane, vec3 point)      Returns true if point lying on Plane, otherwise it
                                          returns false.

bool outOfPlane(vec4 Plane,               Returns true if point not lying on Plane, otherwise it
                vec3 point)               returns false.

bool abovePlane(vec4 Plane,               Returns true if point is above Plane, otherwise it
                vec3 point)               returns false.

bool onPlaneOrAbove(vec4 Plane,           Returns true if point is above Plane or lying on it,
                    vec3 point)           otherwise function returns false.

bool belowPlane(vec4 Plane,               Returns true if point is below Plane, otherwise it
                vec3 point)               returns false.

bool onPlaneOrBelow(vec4 Plane,           Returns true if point is below Plane or lying on it,
                    vec3 point)           otherwise function returns false.

bool rayPlaneIntn(out float t,            Returns true if line (rayStart,rayStart+rayDirn) is not
                  vec3 rayStart,          parallel to Plane. In that case t sets to the parameter
                  vec3 rayDirn,           value in point of intersection from parametric
                  vec4 Plane)             representation of line. Otherwise function returns false.

bool rayPlaneIntn(out vec3 intn,          Returns true if ray (rayStart,rayStart+rayDirn)
                  vec3 rayStart,          intersects Plane in point between min (and max if
                  vec3 rayDirn,           specified). In that case the point of intersection puts
                  vec4 Plane,             into the vector intn.
                  float min=0[,max])      Otherwise function returns false.

bool segPlaneIntn(out float t,            Returns true if line (segStart,segEnd) is not parallel
                  vec3 segStart,          to Plane. In that case t sets to the parameter value in
                  vec3 segEnd,            point of intersection from parametric representation of
                  vec4 Plane)             line. Otherwise function returns false.

bool segPlaneIntn(out vec3 intn,          Returns true if segment (segStart,segEnd) intersects the
                  vec3 segStart,          Plane in point between min (and max if specified). In
                  vec3 segEnd,            that case the point of intersection puts into the vector
                  vec4 Plane,             intn.
                  float min=0[,max])      Otherwise function returns false.

                                    ------LOOKAT FUNCTIONS------

mat4 lookAtDirnMat(vec3 eye,              Creates a viewing matrix derived from an eye point, a
                   vec3 dirn,             look-at direction, and an UP vector.
                   vec3 up)

mat4 lookAtMat(vec3 eye,                  Creates a viewing matrix derived from an eye point, a
               vec3 center,               reference point indicating the center of the scene, and
               vec3 up)                   an UP vector.

mat4 lookAtDirnMat(vec3 eye,              Creates a viewing matrix derived from an eye point and a
                   vec3 dirn)             look-at direction.

mat4 lookAtMat(vec3 eye,                  Creates a viewing matrix derived from an eye point and a
               vec3 center)               reference point indicating the center of the scene.

mat4 lookAtDirnMat(vec3 dirn)             Creates a viewing matrix derived from only a look-at
                                          direction.

                                    ------AUXILIARY FUNCTIONS------

vec3 rotateX(float angle,vec3 vec)        Rotates vec around the OX on angle radians.

mat3 rotationXMat(float angle)            Produces a rotation matrix of angle radians around the
mat3 rotationXMat3(float angle)           OX.
mat4 rotationXMat4(float angle)

vec3 rotateY(float angle,vec3 vec)        Rotates vec around the OY on angle radians.

mat3 rotationYMat(float angle)            Produces a rotation matrix of angle radians around the
mat3 rotationYMat3(float angle)           OY.
mat4 rotationYMat4(float angle)

vec3 rotateZ(float angle,vec3 vec)        Rotates vec around the OZ on angle radians.

mat3 rotationZMat(float angle)            Produces a rotation matrix of angle radians around the
mat3 rotationZMat3(float angle)           OZ.
mat4 rotationZMat4(float angle)

vec3 rotate(float angle,                  Rotates vec around the vector axis on angle radians.
            vec3 axis,
            vec3 vec)

mat3 rotationMat(float angle,vec3 axis)   Produces a rotation matrix of angle radians around the
mat3 rotationMat3(float angle,vec3 axis)  vector axis.
mat4 rotationMat4(float angle,vec3 axis)

mat4 reflectionMat(vec4 Plane)            Produces a matrix reflected relative to Plane.

vec3 project(vec3 V,vec4 Plane)           For the incident vector V and plane Plane, returns the
vec4 project(vec4 V,vec4 Plane)           projection of V on Plane.
                                          Plane must already be normalized in order to achieve the
                                          desired result.

mat4 projectionMat(vec4 Plane)            Produces an on Plane projection matrix.

bool intersect(aabb b0,aabb b1)           Returns true if b0 and b1 intersect, otherwise it returns
bool intersect(rect b0,rect b1)           false.

                                    ------QUATERNION FUNCTIONS------

quat conjugate(quat q)                    Returns the conjugated of quaternion q.
float dot(quat q0,quat q1)                Returns the dot product of q0 and q1.
float norm(quat q)                        Returns the norm of quaternion q.
float magnitude(quat q)                   Returns the magnitude of quaternion q.
float length(quat q)                      The same as magnitude(q).
quat normalize(quat q)                    Returns the normalized of quaternion q.
quat inverse(quat q)                      Returns the inverse of quaternion q.

quat shortestArcQuat(vec3 from,           Returns a quaternion that rotates vector from to vector
                     vec3 to)             to by the shortest path.

quat shortestArcUnitQuat(vec3 from,       Returns an unit quaternion that rotates vector from to
                         vec3 to)         vector to by the shortest path.

mat3 quatToMat (quat q)                   Converts quaternion q to rotation 3D matrix and returns
mat3 quatToMat3(quat q)                   the result.

mat4 quatToMat4(quat q)                   Converts quaternion q to rotation 4D matrix and returns
                                          the result.

mat3 unitQuatToMat (quat q)               Converts unit quaternion q to rotation 3D matrix and
mat3 unitQuatToMat3(quat q)               returns the result.

mat4 unitQuatToMat4(quat q)               Converts unit quaternion q to rotation 4D matrix and
                                          returns the result.

float quatToAxisAngle(out vec3 axis,      Converts quaternion q to "angle and axis" notation.
                      quat q)             Function returns angle and puts unit axis to the
                                          corresponding vector variable.

float unitQuatToAxisAngle(out vec3 axis,  Converts unit quaternion q to "angle and axis" notation.
                      quat q)             Function returns angle and puts unit axis to the
                                          corresponding vector variable.

vec3 quatToAxisAngle(quat q)              Converts quaternion q to "angle and axis" notation.
                                          Function returns an axis-vector with a length of angle.

vec3 unitQuatToAxisAngle(quat q)          Converts unit quaternion q to "angle and axis" notation.
                                          Function returns an axis-vector with a length of angle.

float quatAngle(quat q)                   Returns the rotation angle of quaternion in range
                                          [0; 2*PI).

float unitQuatAngle(quat q)               Returns the rotation angle of unit quaternion in range
                                          [0; 2*PI).

quat matToQuat(mat M)                     Converts matrix M to quaternion and returns the result.

quat matToUnitQuat(mat M)                 Converts matrix M to unit quaternion and returns the
                                          result.

quat slerp(quat from,quat to,float t)     Interpolate between from and to quaternion rotations
                                          along the shortest arc, i.e. returns Spherical Linear
                                          intERPolation (SLERP) of from and to quaternions.

quat squad(quat p,                        Returns slerp(slerp(p,q,t), slerp(a,b,t), 2*t*(1-t)),
           quat a,                        i.e. spherical cubic blend of p, a, b and q.
           quat b,
           quat q,
           float t)



===================================================================================================
================================================RUS================================================
===================================================================================================

Handy Math Library
Copyright (C) 2005  ��������� ������� (tav86@mail.ru)

������ ���������� �������� ���������� ����������� ������������;
�� ������ �������������� � �/��� �������������� �� ��������
����������� ������������ �������� ������������� ���������� GNU,
�������� Free Software Foundation, ������ 2.1 ��� (�� ������
����������) ����� ����� ������� ������.

��� ���������� ���������������� � �������, ��� ��� ����� �������,
������ ��� �����-���� ��������; ���� ��� �������� �����������
������������� � ������������ ����� ��� �������� ��� �����������
����������. ��� ����� ��������� ���������� �������� �����������
������������ �������� ������������� ���������� GNU.

�� ������ ���� �������� ����� ����������� ������������ ��������
������������� ���������� GNU ������ � ���� �����������.
� ��������� ������, �������� � Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA



������� ������������:


��������� ����������:

�� ���������, ���������� ������������ ������� � ������� ���������� ��������.
������������ ��� 4-������� �������� �� ��������� ��������.
��� ��������� ���� �������� ���������� ����������� ��������� ����� ���������� "hm.h":

���������                        ��������
==============================   ==================================================================
#define D3D_MAT_STYLE            ������� �������������� � ������� ���������� �����. �� ��-��
                                 ������� ������������� ������ � D3D �������� ������ ������ ��
                                 �������� ��������� ������� �� �������, ������� �� ������ � �������
                                 �� �������.
#define QUAT_MUL_REVERSE_ORDER   ���� ��� ��������� ����������, ��������� ���� ������������ �
                                 ����������� �� 3D-������ ����������� � �������� �������, �����
                                 ������� ��� ��������� ����� �������� ������ ���� 3D-��������, �
                                 ������ - ������������.
#define DISABLE_VECTORIZATION    ��������� ������������ ��� ����� Tvec4.


�������������� ����:

TvecN - ������,

  ��� T - ��� ��������� �������:

    T       ��������������� ���
    --      ---------------------
    b       HMbool
    i       HMint
    d       HMdouble
    ld      HMlong_double
    s       HMshort
    us      HMushort
    ub      HMubyte

  ���� T ��������� � ���������� �������, �� ���������� ������ ������� ����� ��� HMfloat.

  N ������������ ����������� �������.

  �������� ��������� ������� ������������ ����� ������. ��� ��������, � ������ �����������
  ������������� ��������� ���� ��� ������������� ������ ���� ��� ����������� ���������, ����� ���
  ���������� ���������. ��������� ���������� ������� ����� ���� �������� ��������� ����� �����
  ���������� ����� ( . ) � ��������� �� ��� ��������� ����������.
  �������������� �������� ���������:
  {x, y, z, w} ������� ��� ������������� �������� ������������ ����� ��� �������
  {r, g, b, a} ������� ��� ������������� �������� ������������ �����
  {s, t, p, q} ������� ��� ������������� �������� ������������ ���������� ����������
  �������� ��������� x, r � s, � �������, ���������� ���� � �� �� (������) ���������� �������.
  �������� ��������, ��� ������ ���������� ��������, ���������� r � OpenGL, ���� ������������� � p
  ��-�� ������������ � ����������� r ��� (��������) �����.
  ��������� ������ ��������� ��������� �������� ��������� ��������� ������� ����������� ����������
  �� �������� (�� ������ ��������� ���) �� �������� ����� ����� ( . ). ����.: vec4 v4; v4.yzw();
  ��� ������� � ��������� ������� ����� ������������ ����� �������� �������������� ( [] ). �����
  �������, pos[2] ���������� ������ ������� ������� pos, � ��� ������ ������������ pos.z.

TmatN - �������, ��� T (����� ���� 'i','d' ��� 'ld') � N ����� ��� �� �����, ��� � � TvecN.

  ���� T ��������� � ���������� �������, �� ���������� ����� ������� ����� ��� HMfloat.

  ���������� ������� �������� ����� �������� �������������� ( [] ). ��� ��������� ��������������
  ������� ��������������� ��� ������ ������-��������, � ��� ������������� ����� ���������
  ������������ �������, ������� ����� ��� ������� ��� �� ����������� ��� � �������. ��������������
  �������� ���������� � ����. ������ �������� �������������� ����� ��� ����������� � �������, ���
  ���� ������� ���� ��� ��������. ������, 2 ��������� �������������� �������� ������� �������, �
  ����� ������, � ����� ������� ���������� ���� ������� �������.

Tquat - ����������, ��� T (����� ���� 'd' ��� 'ld') ����� ��� �� �����, ��� � � Tvec4.

  ���� T ��������� � ���������� �����������, �� ��� ���������� ����� ��� HMfloat.

  �������������� �������� ��������� �����������: x, y, z � w. ����� ����� ������������ .xyz() ���
  ������ ������ ��� ��������� ����������� (�.�. ������ �����������) ��� ��������� 3D-������.

Taabb - ����������� �� ���� �������������� ����� ("����"), ��� T (����� ���� 'i','s','d' ��� 'ld')
        ����� ��� �� �����, ��� � � Tvec3.

  ���� T ��������� � ���������� �����, �� ��� ���������� ����� ��� HMfloat.

  ���� ������� �� ���� �������������� 3D-�������� ���������������� ����: min � max. � ������� ��
  ��� ����� ����������, ������ ��� �������� ����� ����� ( . ). ��������: aabb b; b.min;

Trect - �������������, ��� T (����� ���� 'i','s','d' ��� 'ld') ����� ��� �� �����, ��� � � Tvec2.

  ���� T ��������� � ���������� ��������������, �� ��� ���������� ����� ��� HMfloat.

  ������������� ������� �� ���� �������������� 2D-�������� ���������������� ����: min � max. �
  ������� �� ��� ����� ����������, ������ ��� �������� ����� ����� ( . ). ��������: rect r; r.max;


������������:

  ������������ ������������ ��� �������� ��������, ������ � ������������ �� ��������� ��������,
��������, ������ ��� ������������.
  ���� � ����������� ������� ��������� ���� ��������� ��������, �� ������������ ��� �������������
���� ��������� ������ ������� � ��������� �� � ��� ��������� ��������. ���� � ����������� �������
��������� ���� ��������� ��������, �� ������������ ��� ������������� ���� ��������� �� ���������
�������, � ��������� �������� ��������������� � 0.0. ���� � ����������� ����������� ���������
���� ��������� ��������, �� ������������ ��� ������������� ������� ����������� (�.�. ��������
���������� w), � ��������� ���������� ����������� (x,y,z) ��������������� � 0.0. ���� � �����������
����������� ��������� ���� 3D-������, �� ������������ ��� ������������� ������� ����������� (�.�.
������ ��� ��������� �����������), � ���������� ���������� w ��������������� � 0.0. ���� �
����������� ����������� ���������� 4 ��������� ���������, ��� ������������ ��� ������������� ����
��������� �����������. ���� � ����������� �����/�������������� ��������� ���� ��������� ��������,
�� ������������ ��� ������������� ������� min � ��������������� �������� ���������, � ������� max �
��� ��������� ��������; ������ ���� �������� ����� ��������� ����� ����, �� ����������� ������
������ ����/�������������, �.�. ����� ����/�������������, ������� ������������ ������ �����. ����
� ����������� �����/�������������� ���������� 2 ��������� ��� 2 ��������� ���������, ������� min �
max ���������������� �� �������� �������� ��������, ������ ������ min ���������������� ������
����������, � max - ������.
  ������� ����� ���� ������� �� ��������� ��������� ����������, �/��� ��������� ���������, �����
��� ����������� ����������� ������ ������� � ������� ����� �������. � ���� ������, ������������
��������� ���������� ������ ���� ���������� (�� �� ������) ��� ������������� ���� ���������
�������. ������� ��������� � ������� ���������� ��������, � ����� ���� ������� �� ���������
��������� ���������� �� ����� ��������� ������� ��� �� ��������� ��������� ����������. � ���������
������, ����� �������� ��� ������������� ������� � �� ����������� ������ ���� ����� �����������
����������� �������.
  ������� ����� ��������� �� ������ ������. ���� ������� �������� �� ������� ������� �����������,
�� � ����������, ������������ � ������� ��������, ������������ ��� ������������� ���� ���������
����������� �������. ���� ������� �������� �� ������� ������� �����������, �� ��� ������������ ���
������������� ���������� (������������ � ������� ��������) ����������� �������. ��������� ��������
����� ������� ��������������� � 1.0, ���� ��� ����� �� ��������� ������� � � 0.0 � ���������
������.
  ����� ������� ����� ��������� �� �������� �������� ������ ������� �����������, �.�. 4D-�������
����� ���� ������� �� ���� 2D-��������, ��� 3D-��������, 9 ��������� ���������� (��� ��� ��������
3D-�������) � �.�. � ���� ������, ���������� ������� �������� ������ �� ������ ������� �����������.
  ��������� ���������� ������������ ����������� ����:

�����������                     ��������
=============================   ===================================================================
mat3(quat q,                    ������ 3D-������� �� ����������� q. ���� quatIsUnit==true,
     bool quatIsUnit=false)     q ������ ���� ��������� ������������.

mat4(quat q,                    ������ 4D-������� �� ����������� q. ���� quatIsUnit==true,
     bool quatIsUnit=false)     q ������ ���� ��������� ������������.

quat(mat3 M,                    ������ ���������� �� 3D-������� M. ���� quatIsUnit==true, ��������
     bool quatIsUnit=false)     ��������� ����������. ������� ������ ��������� ������ �������� ���
                                ���������� ��������� ����������.

quat(mat4 M,                    ������ ���������� �� 4D-������� M. ���� quatIsUnit==true, ��������
     bool quatIsUnit=false)     ��������� ����������. ������� ������ ��������� ������ �������� ���
                                ���������� ��������� ����������.

quat(vec3 v,float alpha)        ������ ���������� �������� ������ ������� v �� alpha ������.
                                ������ v �� ������ ���� ���������.

aabb(uint count,                ������ ����, �������������� count ����� �� ������� vertices[].
     vec3 vertices[])

rect(uint count,                ������ �������������, �������������� count ����� �� �������
     vec2 vertices[])           vertices[].


��������:

  ������������ �������� ���������� (��������) ������������ ���������� ������������ ( = ):
  lvalue = expression
  �������� ������������ �������� �������� ��������� expression � lvalue. Expression � lvalue ������
���� ������ ����. ��� ����������� �������������� ����� ������ ���� ���� ������ ����� ������������.
  ������ ��������� ������������: ��������� � (+=), ������� �� (-=), �������� �� (*=) �
��������� �� (/=). ��������� "lvalue op= expression" ������������ "lvalue = lvalue op expression",
������ lvalue � expression ����� ������������� ������������� ���������� ��� ��������� op, ��� �
������������ (=).
  �������������� �������������� �������� ���������: �������� (+), ��������� (-), ��������� (*) �
������� (/). ��� �������� ������ ���� ������ ���� ��� ���� ����� ���� ������, � ������ ��������,
�������� ��� ������������. ����� ����, ��� ��������� (*), ���� ����� ���� ��������, � ������ -
�������� ��� �� �����������, ��� � ������, ��� �� ���� ����� ���� ������������, � ������ -
3D-��������. ���� ���� ������� - �����, � ������ - ������, ������� ��� ����������, �����
������������� ����������� � �������, ������� ��� �����������. ��������� ����� ��� �� ���, ��� �
������, ������� ��� ����������.
  ������������ (*) ���� �������� ��� �������������� ���������. ������������ (*) ���� ������ ���
��������� ������������ �� �������� �������� �������, � �� �������������� ���������. ���������-
��� (*) ���� ������������ ��� �������������� ������������ ������������, � �� ��������������
���������.
  ���� ����� �������� ��������� - ������, � ������ - ������� ��� �� �����������, �� ��������
��������� (*) ��������� ��������� ������-������ �� �������. ��������� ����� ��� �� ���, ��� �
������.
  ���� ����� �������� ��������� - �������, � ������ - ������ ��� �� �����������, �� ��������
��������� (*) ��������� ��������� ������� �� ������-�������. ��������� ����� ��� �� ���, ��� �
������.
  ���� ����� �������� ��������� - ����������, � ������ - 3D-������, �� �������� ��������� (*)
������� ���� ������ ������������. ��������� ����� ��� �� ���, ��� � ������.
  ����������� ������� dot, cross � matrixCompMult ��� ���������� �������������� ����������
������������ ��������, ���������� ������������ �������� � ��������������� ��������� ������.
  �������������� ������� ���������: ��������� (-), ����- � ���-��������� � ��������� (-- � ++),
������� ��������� ��� ��������� � ���������. ��������� ����� ��� �� ���, ��� � ������� ����
����������. ��� ����- � ���-���������� � ���������� ��������� ������ ���� l-value. ���-��������� �
��������� ���������� ��� �������� 1 ��� 1.0 � ������� �������� ���������, � ������� ��� ���������,
� �������� ���-���������� � ���������� - ��������� ����� ���������. ����-��������� � ����-���������
���������� ��� �������� 1 ��� 1.0 � ������� �������� ���������, � ������� ��� ���������, ��
����������� ����� �������� ��������� �� ���������� ��������� ����-���������� ��� ����-����������.
  ��������� ��������� - ����� (==) � �� ����� (!=) �������� �� ����� ��������������� ������.
��������� ����� ��� HMbool. ����� �������� ��������� �������, ��� �� ���������� ������ ���� �����.
��� ��������� ����������� ��������������� ��������� ��������, ����������� ������� equal � notEqual.

��������� � ��������� ��������:

  �� ��������� �����������, ��� �������� ��������������. ����� �������� ����������� � ������� ���
�������, �� ����������� ���������� � ������� �������� ������� ��� �������, �������������. ��������:
  vec3 v, u;
  HMfloat f;

  v = u + f;
  ����� ������������
  v.x = u.x + f;
  v.y = u.y + f;
  v.z = u.z + f;

  �

  vec3 v, u, w;
  w = v * u;
  ����� ������������
  w.x = v.x * u.x;
  w.y = v.y * u.y;
  w.z = v.z * u.z;

  � ��� ��� ����������� ����������. ���������� ���������� ��������� ������� �� ������, ������� ��
������� � ������� �� �������. � ���� ������ ����������� �� ������������� ���������, � �������-
�������� �������������� ���������. ��� ��������� ������� ������������ ����������� ���������.
  ��� ������� ��������� �������� ������������� � �� ����������. ��� �������� ��������������
����������, ���� ��� �������� ������ ����, �� �������� ����������� ������������� � ��������� �����
��� �� ���, ��� � ��������. ���� ���� ������� - �����, � ������ - ������ ��� �������, �� ��������
����������� ���, ��� ���� �� ����� ���� ���������� ��� ����������� �������� ������� ��� �������.

�������� ��� �������������:

  ������������ (*) � ������� (/) ����������� � ����� ��� �������������� ��������� ��� �������
��������������. �������� (+) � ��������� (-) ���� ������������ ��� �������������� �������� ���
��������� ��������������. ��������� (*) ���� ������������ ��� �������������� ������������
������������. ���� ����� �������� ��������� - ����������, � ������ - 3D-������, �� ��������
��������� (*) ������� ���� ������ ������������ � ����� ��������� ������.
  ������ ��������� ��� �������� ���������� �������� (+), ��������� (-), ��������� (*) � ������� (/)
�� ���������� � �� ������������� ������� � ������������� ������.
  ������� �������� ��������� (-) ��� ������������� �������� �������������.

�������� ��� ������� � ����������������:

  �������� (+) ���� ������/��������������� ��� ����������� ���������, �.�. ����� ����/����������-
���, ������� �������� ��� ��������. ��������� (*) ���� ������/��������������� ��� �����������
���������, ��������� �������� ����� ��� �� ���, ��� � ��������. �������� (+) �����/�������������� �
3D/2D-������� ��������� ����/������������� ����� �������, ����� �� �������� ���� ������,
����������� �������� �������� ���������� ����/�������������.


�������������� �������:

� ���������� ������������� �������, ��� ������� ��������� (� ��������������� ��������) ����� ����
HMfloat, vec2, vec3, vec4, HMdouble, dvec2, dvec3, dvec4, HMlong_double, ldvec2, ldvec3 ��� ldvec4,
genType ������������ � �������� ���������. ����������, vec ������������ ��� ����������� �������
������ ����, mat - ��� ����������� ������� ������ ���� � �.�. ��� ���� ����� ����������.
����� float ������������ ��� ����������� ������ ��������������� ������������� ����: HMfloat,
HMdouble ��� HMlong_double.
� genTypeInt ������������ ��� ����������� HMint, ivec2, ivec3 ��� ivec4.

���������                                 ��������

=======================================   =========================================================

                                    ------������� �������������� �����------

#vec vec_cast<#vec>(vec v)                ����������� ������ v � ���� #vec. ������:
                                            ivec3 a,b;
                                            ldvec3 c=vec_cast<ldvec3>(a+b);

#mat mat_cast<#mat>(mat m)                ����������� ������� m � ���� #mat. ������:
                                            mat3 a=mat3(1);
                                            dmat4 b=mat_cast<dmat4>(a);//mat_cast<dmat4>(a) ������-
                                                                       //���� ��������� 4D �������

#quat quat_cast<#quat>(quat q)            ����������� ���������� q � ���� #quat. ������:
                                            dvec3 v; dquat q;
                                            quat r=quat_cast<quat>(q*dquat(v)*conjugate(q));

#aabb aabb_cast<#aabb>(aabb b)            ����������� ���� b � ���� #aabb.

#rect rect_cast<#rect>(rect r)            ����������� ������������� r � ���� #rect.

                                    ------������� ��� ������ � ������------

genType radians(genType deg)              ����������� ������� � ������� � ���������� ���������.
genType degrees(genType rad)              ����������� ������� � ������� � ���������� ���������.

                                    ------���������������� �������------

genType exp2(genType x)                   ���������� 2 � ������� x.

genType log2(genType x)                   ���������� �������� �� ��������� 2 �� x, �.�., ����������
                                          �������� y, ������� ������������� ������� x = 2^y.
                                          ��������� ���������� ���� x <= 0.

genType inversesqrt(genType x)            ���������� �������� ���������� ������ ����� x.
                                          ��������� ���������� ���� x <= 0.

                                    ------������� ���������� ��������������� �����------

uint random(uint randMax)                 ���������� ��������������� ����� ����� � ��������� �� 0
                                          �� randMax.

uint random(uint randMin,                 ���������� ��������������� ����� ����� � ��������� ��
            uint randMax)                 randMin �� randMax.

long_double random(long_double randMax)   ���������� ��������������� ������������ ����� � ���������
                                          �� 0.0 �� randMax.

long_double random(long_double randMin,   ���������� ��������������� ������������ ����� � ���������
                   long_double randMax)   �� randMin �� randMax.

void rseed(uint seed)                     ����� ��������� ����� ��� ��������� ��������� �����, �.�.
                                          ����� ������� ��� ��������� ����� ��������������� �����
                                          ��� ������������ ��������.

                                    ------����� �������------

genType square(genType x)                 ���������� ������� ����� x.

genType sign(genType x)                   ���������� 1.0 ���� x>0, 0.0 ���� x==0, � �1.0 ���� x<0.

genType fract(genType x)                  ���������� x - floor (x).

genType mod(genType x, genType y)         ������� �� �������. ���������� x - y*floor(x/y).

genType wrap(genType x,                   ����������� x � ��������� [0,maxVal). ���������� mod(x,y).
             genType maxVal)

genType wrap(genType x,                   ����������� x � ��������� [minVal,maxVal).
             genType minVal,              ���������� mod(x-minVal, maxVal-minVal) + minVal.
             genType maxVal)

genType min(genType v)                    ���������� ����������� ���������� ������� v.

genType min(genType x, genType y)         ���������� y ���� y < x, ����� ���������� x.

genType min(genType x,                    ���������� ����������� �� �������� x, y � z.
            genType y,
            genType z)

genType min(genType x,                    ���������� ����������� �� �������� x, y, z � w.
            genType y,
            genType z,
            genType w)

genType max(genType v)                    ���������� ������������ ���������� ������� v.

genType max(genType x, genType y)         ���������� y ���� x < y, ����� ���������� x.

genType max(genType x,                    ���������� ������������ �� �������� x, y � z.
            genType y,
            genType z)

genType max(genType x,                    ���������� ������������ �� �������� x, y, z � w.
            genType y,
            genType z,
            genType w)

genType clamp(genType x,                  ���������� min (max (x, minVal), maxVal).
              genType minVal,
              genType maxVal)

genType mix (genType x,                   ���������� x * (1 - a) + y * a, �.�. ��������
             genType y,                   ������������ x � y.
             genType2 a)

genType lerp(genType x,                   �� �� ��� � mix(x,y,a).
             genType y,
             genType2 a)

genType cerp(genType x,                   ���������� ���������������� ������������ (CERP) x � y.
             genType y,
             genType2 a)

genType herp3(genType x,                  ���������� ������������ ������ (HERP) ����� x � y �
              genType y,                  ������� ���������� 3 �������.
              genType2 a)

genType herp5(genType x,                  ���������� ������������ ������ (HERP) ����� x � y �
              genType y,                  ������� ���������� 5 �������.
              genType2 a)

genType step(genType edge, genType x)     ���������� 0.0 ���� x < edge, ����� ���������� 1.0.

genType smoothstep(genType edge0,         ���������� 0.0 ���� x <= edge0 � 1.0 ���� x >= edge1 �
                   genType edge1,         ���������� ������� ���������������� ������ ����� 0 � 1
                   genType x)             ����� edge0 < x < edge1. ��� ����� ���� ������� �����
                                          ��������� ��������� ������� � ������� ���������.
										  ����� ������� ������������:
                                            genType t;
                                            t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
                                            return t * t * (3 - 2 * t);

                                    ------�������������� �������------

float dot(genType v0, genType v1)         ���������� ��������� ������������ �������� v0 � v1.

float length(genType v)                   ���������� ����� ������� v.

float sqlen(genType v)                    ���������� ������� ����� ������� v.

float distance(genType p0, genType p1)    ���������� ���������� ����� ������� p0 � p1, �.�.
                                          length (p0 � p1).

vec3 cross(vec3 v0, vec3 v1)              ���������� ��������� ������������ �������� v0 � v1.

genType normalize(genType v)              ���������� ������, ������� �� �� ����������� ��� � v, ��
                                          ����� �������� ����� 1.

vec2 perp(vec2 v)                         ���������� ������, ���������������� v, �.�.
                                          vec2(-v.y, v.x).

vec3 perp(vec3 v)                         ���������� ������, ���������������� v.

vec3 slerp(vec3 v1,vec3 v2,float t)       ���������� ����������� �������� ������������ (SLERP)
                                          �������� v1 � v2.

genType faceforward(genType N,            ���� dot (Nref, I) < 0 ���������� N, � ��������� ������
                    genType I,            ���������� �N.
                    genType Nref)

genType reflect(genType V, genType N)     ��� ������������� ������� V � ���������� ����������� N,
                                          ���������� ��������� �����������:
                                            result = V - 2*dot(N,V)*N;
                                          N ������ ���� ���������� ��� ���������� ���������
                                          ����������.
genType reflect(genType V, vec4 Plane)    ��� ������������� ������� V � ��������� Plane, ����������
                                          ��������� ����������� ������� V.
                                          ��������� ������ ���� ������������� ��� ����������
                                          ��������� ����������.

genType refract(genType V,                ��� ������������� ������� V, ������� � ����������� N �
                genType N,                ��������� ������������� ����������� eta, ����������
                float eta)                ����������� ������. ������������ ��������� ����������-
                                          ���� ��������� �������:
                                            k = 1.0 - eta * eta * (1.0 - dot(N, V) * dot(N, V))
                                            if (k < 0.0)
                                                result = genType(0.0)
                                            else
                                                result = eta * V - (eta * dot(N, V) + sqrt(k)) * N
                                          ������� �������� - ������ V � ������� � ����������� N -
                                          ������ ���� ������������� ��� ���������� ���������
                                          ����������.

                                    ------������� ��� ������ � ���������------

mat matrixCompMult(mat x, mat y)          ������������� �������� ������� x �� y, �.�., result[i][j]
                                          ����������� ��� ������������ x[i][j] � y[i][j].
                                          ����������: ��� ���������� ���������� ���������������
                                          ��������� ������ ����������� �������� ��������� (*).

mat inverse(mat m)                        ���������� �������, �������� m.

mat transpose(mat m)                      ���������� ����������������� ������� m.

mat3 orthonormalize(mat3 m)               ���������� ������� m ����� ����������������.

mat4 scalingMat(vec3 s)                   ���������� ������� m ������� ������������� �������
mat4 scalingMat4(vec3 s)                  m*vec4(v,1.0) = vec4(s*v,1.0), ��� v - ����� ���������
                                          ������.

mat3 scalingMat3(vec3 s)                  ���������� ������� m ������� ������������� �������
                                          m*v = s*v, ��� v - ����� ��������� ������.

mat3 scalingMat(vec2 s)                   ���������� ������� m ������� ������������� �������
mat3 scalingMat3(vec2 s)                  m*vec3(v,1.0) = vec3(s*v,1.0), ��� v - ����� ����������
                                          ������.

mat2 scalingMat2(vec2 s)                  ���������� ������� m ������� ������������� �������
                                          m*v = s*v, ��� v - ����� ���������� ������.

mat4 translationMat(vec3 tr)              ���������� ������� m ������� ������������� �������
mat4 translationMat4(vec3 tr)             m*vec4(v,1.0) = vec4(tr+v,1.0), ��� v - ����� ���������
                                          ������.

mat3 translationMat(vec2 tr)              ���������� ������� m ������� ������������� �������
mat3 translationMat3(vec2 tr)             m*vec3(v,1.0) = vec3(tr+v,1.0), ��� v - ����� ����������
                                          ������.

mat3 crossMat(vec3 n)                     ���������� ������� m ������� ������������� �������
mat3 crossMat3(vec3 n)                    m*v = cross(n,v), ��� v - ����� ��������� ������.

mat4 crossMat4(vec3 n)                    ���������� ������� m ������� ������������� �������
                                          m*vec4(v,1.0) = vec4(cross(n,v),1.0), ��� v - �����
                                          ��������� ������.

                                    ------������� ��������� ��������------

bvec isZero(vec v)                        ���������� �������������� ��������� a == 0.
bvec notZero(vec v)                       ���������� �������������� ��������� a != 0.
bvec lessThan(vec a, vec b)               ���������� �������������� ��������� a < b.
bvec lessThanEqual(vec a, vec b)          ���������� �������������� ��������� a <= b.
bvec greaterThan(vec a, vec b)            ���������� �������������� ��������� a > b.
bvec greaterThanEqual(vec a, vec b)       ���������� �������������� ��������� a >= b.
bvec equal(vec a, vec b)                  ���������� �������������� ��������� a == b.
bvec notEqual(vec a, vec b)               ���������� �������������� ��������� a != b.
bool any(bvec v)                          ���������� true ���� ����� ���������� v �������.
bool all(bvec v)                          ���������� true ������ ����� ��� ���������� v �������.
bvec not(bvec v)                          ���������� �������������� ���������� ��������� v.

                                    ------������� ����------

  ������������� ���� ������� ���� ����� ��������� ��������������:
� ������������ ��������(�) ���������� ������������(�) �� ��������� [-1.0,1.0].
� ������������ ��������(�) ����� ����� ������� �������� 0.0.
� ��� ����������, �.�. ���������� ������� �������� ������ ��� ���� � �� �� �������� ��������.
� ���������������� ������� - 1.0.
� ������ ������� - 2.0^32.

float noise1(genType v,ferp=herp5)        ���������� 1D �������� ����, ���������� �� v.
 vec2 noise2(genType v,ferp=herp5)        ���������� 2D �������� ����, ���������� �� v.
 vec3 noise3(genType v,ferp=herp5)        ���������� 3D �������� ����, ���������� �� v.
 vec4 noise4(genType v,ferp=herp5)        ���������� 4D �������� ����, ���������� �� v.

  int noise1(genTypeInt v)                ���������� 1D �������� ����, ���������� �� v.
ivec2 noise2(genTypeInt v)                ���������� 2D �������� ����, ���������� �� v.
ivec3 noise3(genTypeInt v)                ���������� 3D �������� ����, ���������� �� v.
ivec4 noise4(genTypeInt v)                ���������� 4D �������� ����, ���������� �� v.

                                    ------������� ��� ������ � �����������------

vec3 planeNormal(vec3 p0,                 ���������� ������� � ���������, � ������� ����� ����� p0,
                 vec3 p1,                 p1 � p2.
				 vec3 p2)

vec4 plane(vec3 p0, vec3 p1, vec3 p2)     ������ ��������� �� 3-� ������� � ��� ������.

vec4 plane(vec3 n, vec3 p)                ������ ��������� �� ������� � �����, �������������
                                          ���� ���������.

vec4 unitPlane(vec3 p0,                   ������ ��������� ��������� �� 3-� ������� � ��� ������.
               vec3 p1,                   ����������: ��� ��������� ����� ���������� ��������� �
			   vec3 p2)                   ��������� ��������.

vec4 unitPlane(vec3 n, vec3 p)            ������ ��������� ��������� �� ������� � �����,
                                          ������������� ���� ���������.

vec4 normalizePlane(vec4 Plane)           ����������� Plane � ��������� ��������� � ����������
                                          ���������.

vec4 translatePlane(vec4 Plane,vec3 tr)   ���������� Plane �� ������ tr � ���������� ���������.

vec3 planePoint(vec4 Plane)               ���������� �����, ������� � �������� ���������.

vec3 unitPlanePoint(vec4 Plane)           ���������� �����, ������� � �������� ��������� ���������.

vec4 reflectPlane(vec4 Plane,             ��� ������������ ��������� Plane � ��������� ��������� R,
                  vec4 R)                 ���������� ��������� ��������� Plane ������������ R.
                                          ��������� R ������ ���� ��������� ��� ����������
                                          ��������� ����������. �� Plane �� ������� ���� ���������.

float planeDist(vec4 Plane, vec3 point)   ���������� ���������� �� ��������� Plane �� ����� point.

float planeDist(vec4 Plane, vec4 point)   ���������� ���������� �� ��������� Plane �� ����� point,
                                          �������� � ���������� �����������.

float unitPlaneDist(vec4 Plane,           ���������� ���������� �� ��������� ��������� Plane ��
                    vec3 point)           ����� point.

float unitPlaneDist(vec4 Plane,           ���������� ���������� �� ��������� ��������� Plane ��
                    vec4 point)           ����� point, �������� � ���������� �����������.

bool onPlane(vec4 Plane, vec3 point)      ���������� true ���� ����� ����� �� ��������� Plane,
                                          ����� ������� ���������� false.

bool outOfPlane(vec4 Plane,               ���������� true ���� ����� �� ����� �� ��������� Plane,
                vec3 point)               ����� ������� ���������� false.

bool abovePlane(vec4 Plane,               ���������� true ���� ����� ����� ���� ��������� Plane,
                vec3 point)               ����� ������� ���������� false.

bool onPlaneOrAbove(vec4 Plane,           ���������� true ���� ����� ����� ���� ��� �� ���������
                    vec3 point)           Plane, ����� ������� ���������� false.

bool belowPlane(vec4 Plane,               ���������� true ���� ����� ����� ���� ��������� Plane,
                vec3 point)               ����� ������� ���������� false.

bool onPlaneOrBelow(vec4 Plane,           ���������� true ���� ����� ����� ���� ��� �� ���������
                    vec3 point)           Plane, ����� ������� ���������� false.

bool rayPlaneIntn(out float t,            ���������� true ���� ������ (rayStart,rayStart+rayDirn)
                  vec3 rayStart,          �� ����������� Plane. � ���� ������ � t ��������� ���-
                  vec3 rayDirn,           ����� ��������� � ����� ����������� �� ����������������
                  vec4 Plane)             ������������� ������. ����� ������� ���������� false.

bool rayPlaneIntn(out vec3 intn,          ���������� true ���� ��� (rayStart,rayStart+rayDirn)
                  vec3 rayStart,          ���������� ��������� Plane � ����� ����� min (� max ����
                  vec3 rayDirn,           �������� �������). � ���� ������ ����� �����������
                  vec4 Plane,             ��������� � ������-������ intn.
                  float min=0[,max])      ����� ������� ���������� false.

bool segPlaneIntn(out float t,            ���������� true ���� ������ (segStart,segEnd) �� �����-
                  vec3 segStart,          ������ Plane. � ���� ������ � t ��������� �������� ����-
                  vec3 segEnd,            ����� � ����� ����������� �� ���������������� ����������-
                  vec4 Plane)             ��� ������. ����� ������� ���������� false.

bool segPlaneIntn(out vec3 intn,          ���������� true ���� ������� (segStart,segEnd) ����������
                  vec3 segStart,          ��������� Plane � ����� ����� min (� max ���� ��������
                  vec3 segEnd,            �������). � ���� ������ ����� ����������� ��������� �
                  vec4 Plane,             ������-������ intn.
                  float min=0[,max])      ����� ������� ���������� false.

                                    ------������� ����------

mat4 lookAtDirnMat(vec3 eye,              ������ ������� ���� �� ��������� ��������� ������ eye,
                   vec3 dirn,             ����������� ������� dirn � ������� ����� up.
                   vec3 up)

mat4 lookAtMat(vec3 eye,                  ������ ������� ���� �� ��������� ��������� ������ eye,
               vec3 center,               ��������� �����, �������� ����� �����, � ������� �����
               vec3 up)                   up.

mat4 lookAtDirnMat(vec3 eye,              ������ ������� ���� �� ��������� ��������� ������ eye �
                   vec3 dirn)             ����������� ������� dirn.

mat4 lookAtMat(vec3 eye,                  ������ ������� ���� �� ��������� ��������� ������ eye �
               vec3 center)               ��������� �����, �������� ����� �����.

mat4 lookAtDirnMat(vec3 dirn)             ������ ������� ���� �� ��������� ������ �����������
                                          ������� dirn.

                                    ------��������������� �������------

vec3 rotateX(float angle,vec3 vec)        ������������ vec ������ OX �� angle � ��������.

mat3 rotationXMat(float angle)            ������ ������� �������� �� ���� angle � �������� ������
mat3 rotationXMat3(float angle)           OX.
mat4 rotationXMat4(float angle)

vec3 rotateY(float angle,vec3 vec)        ������������ vec ������ OY �� angle � ��������.

mat3 rotationYMat(float angle)            ������ ������� �������� �� ���� angle � �������� ������
mat3 rotationYMat3(float angle)           OY.
mat4 rotationYMat4(float angle)

vec3 rotateZ(float angle,vec3 vec)        ������������ vec ������ OZ �� angle � ��������.

mat3 rotationZMat(float angle)            ������ ������� �������� �� ���� angle � �������� ������
mat3 rotationZMat3(float angle)           OZ.
mat4 rotationZMat4(float angle)

vec3 rotate(float angle,                  ������������ vec ������ ������� axis �� angle � ��������.
            vec3 axis,
            vec3 vec)

mat3 rotationMat(float angle,vec3 axis)   ������ ������� �������� �� ���� angle � �������� ������
mat3 rotationMat3(float angle,vec3 axis)  ������� axis.
mat4 rotationMat4(float angle,vec3 axis)

mat4 reflectionMat(vec4 Plane)            ������ ������� ��������� ������������ ��������� Plane.

vec3 project(vec3 V,vec4 Plane)           ��� ������������� ������� V � ��������� Plane, ����������
vec4 project(vec4 V,vec4 Plane)           �������� ������� V �� Plane.
                                          ��������� ������ ���� ������������� ��� ����������
                                          ��������� ����������.

mat4 projectionMat(vec4 Plane)            ������ ������� ������������� �� ��������� Plane.

bool intersect(aabb b0,aabb b1)           ���������� true ���� b0 � b1 ������������, ����� �������
bool intersect(rect b0,rect b1)           ���������� false.

                                    ------������� ��� ������ � �������������------

quat conjugate(quat q)                    ���������� ����������, ����������� q.
float dot(quat q0,quat q1)                ���������� ��������� ������������ ������������ q0 � q1.
float norm(quat q)                        ���������� ����� ����������� q.
float magnitude(quat q)                   ���������� ������ (�����) ����������� q.
float length(quat q)                      �� �� ��� � magnitude(q).
quat normalize(quat q)                    ����������� ���������� q � ���������� ���������.
quat inverse(quat q)                      ���������� ����������, �������� q.

quat shortestArcQuat(vec3 from,           ���������� ����������, ������� ������� ������ from �
                     vec3 to)             ������� to �� ����������� ����.

quat shortestArcUnitQuat(vec3 from,       ���������� ��������� ����������, ������� ������� ������
                         vec3 to)         from � ������� to �� ����������� ����.

mat3 quatToMat (quat q)                   ����������� ���������� q � 3D ������� �������� �
mat3 quatToMat3(quat q)                   ���������� ���������.

mat4 quatToMat4(quat q)                   ����������� ���������� q � 4D ������� �������� �
                                          ���������� ���������.

mat3 unitQuatToMat (quat q)               ����������� ��������� ���������� q � 3D ������� ��������
mat3 unitQuatToMat3(quat q)               � ���������� ���������.

mat4 unitQuatToMat4(quat q)               ����������� ��������� ���������� q � 4D ������� ��������
                                          � ���������� ���������.

float quatToAxisAngle(out vec3 axis,      ������� ���������� ���� �������� ����������� q � � axis
                      quat q)             �������� ��������� ������-���, ������ �������� ��
                                          ���������� ��������.

float unitQuatToAxisAngle(out vec3 axis,  ������� ���������� ���� �������� ���������� ����������� q
                      quat q)             � � axis �������� ��������� ������-���, ������ ��������
                                          �� ���������� ��������.

vec3 quatToAxisAngle(quat q)              ������� ���������� ������-���, ������ �������� ����������
                                          �������� ���������� q. ����� ����� ������� ����� ����
                                          �������� � ��������.

vec3 unitQuatToAxisAngle(quat q)          ������� ���������� ������-���, ������ �������� ����������
                                          �������� ��������� ���������� q. ����� ����� �������
                                          ����� ���� �������� � ��������.

float quatAngle(quat q)                   ���������� ���� �������� ����������� q � ���������
                                          [0; 2*PI).

float unitQuatAngle(quat q)               ���������� ���� �������� ���������� ����������� q �
                                          ��������� [0; 2*PI).

quat matToQuat(mat M)                     ����������� ������� M � ���������� � ����������
                                          ���������.

quat matToUnitQuat(mat M)                 ����������� ������� M � ��������� ���������� � ����������
                                          ���������.

quat slerp(quat from,quat to,float t)     ���������� ������������ ������������ from � to ��
                                          ���������� ����, �.�. ���������� ����������� ��������
                                          ������������ (SLERP) ������������ from � to.

quat squad(quat p,                        ���������� slerp(slerp(p,q,t), slerp(a,b,t), 2*t*(1-t)),
           quat a,                        �.�. ����������� ���������� ������������ p, a, b � q.
           quat b,
           quat q,
           float t)
*/

#ifndef HM_H
#define HM_H

#include "typedef.h"
#include "vec.h"
#include "mat.h"
#include "quat.h"
#include "aabb.h"
#include "func.h"

#endif //HM_H
