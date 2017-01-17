#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\euler_angles.hpp>
#include <glm\gtx\projection.hpp>
#include <iostream>
#include <glm\gtx\string_cast.hpp>

using namespace std;
using namespace glm;

int main() {
	// 12.1.1 - Defining Vectors
	//Exercise 1 - define two of each vector type
	vec2 u_vec(1.0f, 0.0f);
	vec2 ut_vec(5.0f, 0.0f);

	vec3 v_vec(0.0f, 5.0f, 0.0f);
	vec3 vt_vec(0.0f, 3.0f, 0.0f);

	vec4 z_vec(0.0f, 0.0f, 2.0f, 0.0f);
	vec4 zt_vec(0.0f, 0.0f, 6.0f, 0.0f);

	//Create another 6 variables
	// -convert one 2d vec to 3d
	vec3 uv_vec(u_vec, 0.0f);
	// -convert one 2d vec to 4d
	vec4 utz_vec(ut_vec, 0.0f, 0.0f);
	// -convert one 3d vec to 2d
	vec2 vu_vec(v_vec);
	// -convert one 3d vec to 4d
	vec4 vtz_vec(vt_vec, 0.0f);
	// -convert one 4d vec to 2d
	vec2 zu_vec(z_vec);
	// -convert one 4d vec to 3d
	vec3 zv_vec(zt_vec);

	// 12.1.2 - Vector Addition and Subtraction
	//Create 6 more variables
	// -add 2d vecs
	vec2 uadd = u_vec + ut_vec;
	// -subtract 2d vecs
	vec2 usub = u_vec - ut_vec;
	// -add 3d vecs
	vec3 vadd = v_vec + vt_vec;
	// -subtract 3d vecs
	vec3 vsub = v_vec + vt_vec;
	// -add 4d vecs
	vec4 zadd = z_vec + zt_vec;
	// -subtract 4d vecs
	vec4 zsub = z_vec - zt_vec;

	// 12.1.3 - Vector Scaling
	// Multiplication operators also overloaded in GLM for vectors...however:
	// MULTIPLYING two vectors is component-wise (useful for colour work)
	//Create 6 more variables
	// -2d by scalar
	vec2 uscal = 5.0f * u_vec;
	// -2d divided by scalar
	vec2 udiv = ut_vec / 2.0f;
	// -3d by scalar
	vec3 vscal = 8.0f * v_vec;
	// -3d divided by scalar
	vec3 vdiv = vt_vec / 5.0f;
	// -4d by scalar
	vec4 zsal = 9.0f * z_vec;
	// -4d divided by scalar
	vec4 zdiv = zt_vec / 5.0f;

	// 12.1.4 - Length of a Vector
	//Create 3 float values from a 2d, 3d and 4d vector
	float ulen = length(u_vec);
	float vlen = length(v_vec);
	float zlen = length(z_vec);

	// 12.1.5 - Normalizing a Vector
	// Create 3 variables storing the result of normalising a 2d, 3d and 4d vector
	vec2 unor = normalize(u_vec);
	vec3 vnor = normalize(v_vec);
	vec4 znor = normalize(z_vec);

	// 12.1.6 - Dot Product
	// Create 3 variables to store the dot product result for a 2d, 3d and 
	// 4d vector
	float udot = dot(u_vec, ut_vec);
	float vdot = dot(v_vec, vt_vec);
	float zdot = dot(z_vec, zt_vec);

	// Extra - vector projection
	// Projection function declared in glm\gtx\projection.hpp
	// Perform 3 projection operations
	// Project a 2d onto 2d, 3d onto 3d and 4d onto 4d
	vec2 upro = proj(u_vec, ut_vec);
	vec3 vpro = proj(v_vec, vt_vec);
	vec4 zpro = proj(z_vec, zt_vec);

	// 12.1.7 - Cross Product
	// Perform cross product on two 3d vectors and store the result
	vec3 vcro = cross(v_vec, vt_vec);

	// 12.2 MATRICES
	// 12.2.1 - Defining a Matrix
	mat4 m(1.0f);
    auto mf = m.length;
	mat3 thr(2.0f, 4.0f, 2.0f,
			 5.0f, 2.0f, 1.0f,
			 1.0f, 2.0f, 1.0f);

	mat3 n(1.0f);
	//Convert mat4 to mat3
	mat3 o(mat4(1.0f));
	//get length/magnitude
	//float of = o.length;

	//Matrix addition
	mat3 p = n + o;
	mat3 q = n - o;

	//Matrix scaling
	mat3 r = 5.0f * p;
	mat4 s = 5.0f * m;
	mat3 t = p / 5.0f;
	mat4 c = m / 5.0f;

	//Matrix multiplication
	mat3 d = r * t;
	mat2x3 e(1.0f);
	mat2x3 f = d * e;

	//Matrix-Vector multiplication
	mat4 T;
	vec3 uT; //Must be converted to a 4D vector
	vec4 vvv = T * vec4(uT, 1.0f);
	//To retieve the 3D version (if required)...
	vec3 www = vec3(T * vec4(uT, 1.0f));

	vec3 su = vec3(s * vec4(v_vec, 1.0f));

	//12.3 TRANSFORM
	//12.3.1 TRANSLATION
	//Example
	// mat4 T = translate(mat4(1.0f), vec3(x,y,z));
	//Create a translation matrix, transform 3D vector, store result in 
	//another 3D vector
	// 1. Create translation matrix using u_plus_v
	mat4 TT = translate(mat4(1.0f), vec3(vt_vec));
	// 2. Transform 3D vector uT using the translation matrix, store in transVec
	vec3 transVec = vec3(TT * vec4(uT, 1.0f));
	// Run with ctl + f5
	cout << "EXERCISE 12.3.1" << endl;
	cout << "Translation vector: " + to_string(vt_vec) << endl; //Vector
	cout << "Translation matrix: " + to_string(TT) << endl; //Made into translation matrix (top to bottom, left to right)
	cout << "To be translated: " + to_string(uT) << endl; //Vector to be translated
	cout << "Result: " + to_string(transVec) << endl; // The result

													  //12.3.2 ROTATION
													  //Example
													  //mat4 Rx = rotate(mat4(1.0f), angle, vec3(1.0f, 0.0f, 0.0f));
													  //mat4 Ry = rotate(mat4(1.0f), angle, vec3(0.0f, 1.0f, 0.0f));
													  //mat4 Rz = rotate(mat4(1.0f), angle, vec3(0.0f, 0.0f, 1.0f));
													  //Task - create 3 rotation matrices - one for each type.

	vec3 x_origin(3.0f, 1.0f, 1.0f);
	vec3 y_origin(1.0f, 3.0f, 1.0f);
	vec3 z_origin(1.0f, 1.0f, 2.0f);

	mat4 Rxx = rotate(mat4(1.0f), quarter_pi<float>(), vec3(1.0f, 0.0f, 0.0f));
	mat4 Ryy = rotate(mat4(1.0f), quarter_pi<float>(), vec3(0.0f, 1.0f, 0.0f));
	mat4 Rzz = rotate(mat4(1.0f), quarter_pi<float>(), vec3(0.0f, 0.0f, 1.0f));

	//Rotate about the x-axis(pitch)
	vec3 rot_x = vec3(Rxx * vec4(x_origin, 1.0f));
	//Rotate about the y-axis (yaw)
	vec3 rot_y = vec3(Ryy * vec4(y_origin, 1.0f));
	//Rotate about the z-axis
	vec3 rot_z = vec3(Rzz * vec4(z_origin, 1.0f));

	//Combine the rotation matrices and then produce transform
	mat4 Rxy = Rxx * Ryy;
	mat4 Rxyz = Rxy * Rzz;
	//Rotate vector using combo matrix
	vec3 rot_xyz = vec3(Rxyz * vec4(x_origin, 1.0f));

	//Using Euler angles instead
	mat4 Re = eulerAngleYXZ(quarter_pi<float>(), quarter_pi<float>(), quarter_pi<float>());


	cout << "EXERCISE 12.3.2" << endl;
	cout << "Rotation matrix: " + to_string(Rxx) << endl; //Made into rotation matrix
	cout << "To be rotated: " + to_string(x_origin) << endl; //Vector to be translated
	cout << "Result: " + to_string(rot_x) << endl; // The result
	cout << "Combo matrix: " + to_string(Rxyz) << endl; // Combined matrix
	cout << "Combo result: " + to_string(rot_xyz) << endl; //Combo result
	cout << "Euler angles: " + to_string(Re) << endl;

	//12.3.3 SCALE
	//Example
	// mat4 S = scale(mat4(1.0f), vec3(x,y,z));
	//Create a scale matrix and transform a 3D vector with it

	//Scaling vector
	vec3 sl(5.0f, 5.0f, 5.0f);
	//Create scale matrix
	mat4 SL = scale(mat4(1.0f), sl);
	//Transform vector and store result
	vec4 TS = SL * vvv;

	// 12.3.4 COMBINING MATRICES
	// Example
	// mat4 trans = T* (R * S)

	// 12.4 QUATERNIONS
	quat qq(5.0f, vec3(1.0f, 2.0f, 2.0f));

	// 12.4.2 QUATERNIONS FOR ROTATIONS
	// Example
	// quat q = rotate(quat(), angle, vec3(x,y,z));
	quat rx = rotate(qq, quarter_pi<float>(), vec3(1.0f, 0.0f, 0.0f));
	quat ry = rotate(qq, quarter_pi<float>(), vec3(0.0f, 1.0f, 0.0f));
	quat rz = rotate(qq, quarter_pi<float>(), vec3(0.0f, 0.0f, 1.0f));

	// 12.4.3 QUAT MULTIPLICATION
	// Example
	// quat R = rz * rx * ry;

	quat Rzxy = rz * rx * ry;

	// 12.4.4 CONVERSION TO MATRIX
	// Example
	// mat4 R = mat4_cast(q);
	mat4 QR = mat4_cast(Rzxy);



}