#include <glm\glm.hpp>
#include <graphics_framework.h>

using namespace std;
using namespace graphics_framework;
using namespace glm;

geometry geom;
effect eff;
target_camera cam;
float theta = 0.0f;
float rho = 0.0f;
vec3 pos(0.0f, 0.0f, 0.0f);
float s = 1.0f;
double xpos, old_xpos = 0.0f;
double ypos, old_ypos = 0.0f;


bool load_content() {
	// Create cube data - twelve triangles 
	// *********************************
	/* Add the position data for triangles here, (6 verts per side)
	*     7---------5
	*   / |        /|
	*  2----------1 |
	*  |  |       | |
	*  |  8---------6
	*  | /        |/
	*  4----------3       */
	// Positions
	vector<vec3> positions{
		// *********************************
		// Add the position data for triangles here, (6 verts per side)
		// Front 123
		vec3(1.0f, 1.0f, 1.0f),
		vec3(-1.0f, 1.0f, 1.0f),
		vec3(1.0f, -1.0f, 1.0f),
		// Front 243
		vec3(-1.0f, 1.0f, 1.0f),
		vec3(-1.0f, -1.0f, 1.0f),
		vec3(1.0f, -1.0f, 1.0f),
		// Back 567
		vec3(1.0f, 1.0f, -1.0f),
		vec3(1.0f, -1.0f, -1.0f),
		vec3(-1.0f, 1.0f, -1.0f),
		// Back 687
		vec3(1.0f, -1.0f, -1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		vec3(-1.0f, 1.0f, -1.0f),
		// Right 651
		vec3(1.0f, -1.0f, -1.0f),
		vec3(1.0f, 1.0f, -1.0f),
		vec3(1.0f, 1.0f, 1.0f),
		// Right 136
		vec3(1.0f, 1.0f, 1.0f),
		vec3(1.0f, -1.0f, 1.0f),
		vec3(1.0f, -1.0f, -1.0f),
		// Left 278
		vec3(-1.0f, 1.0f, 1.0f),
		vec3(-1.0f, 1.0f, -1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		// Left 284
		vec3(-1.0f, 1.0f, 1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		vec3(-1.0f, -1.0f, 1.0f),
		// Top 572
		vec3(1.0f, 1.0f, -1.0f),
		vec3(-1.0f, 1.0f, -1.0f),
		vec3(-1.0f, 1.0f, 1.0f),
		// Top 152
		vec3(1.0f, 1.0f, 1.0f),
		vec3(1.0f, 1.0f, -1.0f),
		vec3(-1.0f, 1.0f, 1.0f),
		// Bottom 348
		vec3(1.0f, -1.0f, 1.0f),
		vec3(-1.0f, -1.0f, 1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		// Bottom 638
		vec3(1.0f, -1.0f, -1.0f),
		vec3(1.0f, -1.0f, 1.0f),
		vec3(-1.0f, -1.0f, -1.0f)
		// *********************************
	};
	// Colours
	vector<vec4> colours;
	for (auto i = 0; i < positions.size(); ++i) {
		colours.push_back(vec4(i % 2, 0.6, 0.0f, 1.0f)); // Notice how I got those Rad colours?
	}

	// Add to the geometry
	geom.add_buffer(positions, BUFFER_INDEXES::POSITION_BUFFER);
	geom.add_buffer(colours, BUFFER_INDEXES::COLOUR_BUFFER);

	// Load in shaders
	eff.add_shader("shaders/basic.vert", GL_VERTEX_SHADER);
	eff.add_shader("shaders/basic.frag", GL_FRAGMENT_SHADER);
	// Build effect
	eff.build();

	// Set camera properties
	cam.set_position(vec3(10.0f, 10.0f, 10.0f));
	cam.set_target(vec3(0.0f, 0.0f, 0.0f));
	auto aspect = static_cast<float>(renderer::get_screen_width()) / static_cast<float>(renderer::get_screen_height());
	cam.set_projection(quarter_pi<float>(), aspect, 2.414f, 1000.0f);
	return true;
}

bool update(float delta_time) {
<<<<<<< HEAD
	// *********************************
	// Use keys to update transform values
	// WSAD - movement
	// Cursor - rotation
	// O decrease scale, P increase scale
	// Key events
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_W)) {
		pos += vec3(0.0f, 5.0f, 0.0f) * delta_time;
	}
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_S)) {
		pos += vec3(0.0f, -5.0f, 0.0f) * delta_time;
	}
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_D)) {
		pos += vec3(5.0f, 0.0f, 0.0f) * delta_time;
	}
	if (glfwGetKey(renderer::get_window(), GLFW_KEY_A)) {
		pos += vec3(-5.0f, 0.0f, 0.0f) * delta_time;
	}

	if (glfwGetMouseButton(renderer::get_window(), GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
	{
		glfwGetCursorPos(renderer::get_window(), &xpos, &ypos);
		//If the old xpos is different from the new xpos, rotate cube
		if (xpos > old_xpos) {
			rho += pi<float>() * delta_time;
			old_xpos = xpos;
		}
		if (xpos < old_xpos) {
			rho -= pi<float>() * delta_time;
			old_xpos = xpos;
		}
		if (ypos > old_ypos) {
			theta += pi<float>() * delta_time;
			old_ypos = ypos;
		}
		if (ypos < old_ypos) {
			theta -= pi<float>() * delta_time;
			old_ypos = ypos;
		}
	}




	// *********************************
	// Update the camera
	cam.update(delta_time);
	return true;
}

bool render() {
	// Bind effect
	renderer::bind(eff);
	mat4 T, R, S, M;
	// *********************************
	// Create transformation matrix
	//Variables for quat rotation
	vec3 vx(0.0f, 0.0f, 1.0f);
	vec3 vy(0.0f, 1.0f, 0.0f);
	quat qx(rotate(quat(), theta, vx));
	quat qy(rotate(quat(), rho, vy));
	quat qr = qy * qx;
	T = translate(mat4(1.0f), pos);
	//R = eulerAngleXZ(theta, rho);
	R = mat4_cast(qr);
	M = T * R;



	// *********************************
	// Create MVP matrix
	auto V = cam.get_view();
	auto P = cam.get_projection();
	auto MVP = P * V * M;
	// Set MVP matrix uniform
	glUniformMatrix4fv(eff.get_uniform_location("MVP"), 1, GL_FALSE, value_ptr(MVP));
	// Render geometry
	renderer::render(geom);
	return true;
}

void main() {
	// Create application
	app application("20_Transformed_Cube");
	// Set load content, update and render methods
	application.set_load_content(load_content);
	application.set_update(update);
	application.set_render(render);
	// Run application
	application.run();
}