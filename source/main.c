#define GS_IMPL
#include <gs/gs.h>

#define GS_IMMEDIATE_DRAW_IMPL
#include <gs/util/gs_idraw.h>

gs_command_buffer_t cb    = {0};
gs_immediate_draw_t gsi   = {0};

void init() 
{
	cb = gs_command_buffer_new();
	gsi = gs_immediate_draw_new();
}

void update()
{
	if (gs_platform_key_pressed(GS_KEYCODE_ESC)) {
		gs_engine_quit();
	}

	const float t = gs_platform_elapsed_time() * 0.0001f;
	gsi_camera3D(&gsi);
	gsi_rotatefv(&gsi, gs_deg2rad(90.f), GS_ZAXIS); gsi_rotatefv(&gsi, t, GS_YAXIS);
	gsi_sphere(&gsi, 0.f, 0.f, 0.f, 1.f, 50, 150, 200, 50, GS_GRAPHICS_PRIMITIVE_LINES);
	gsi_camera2D(&gsi);
	gsi_text(&gsi, 325.f, 280.f, "Hello, Gunslinger.", NULL, false, 255, 255, 255, 255);
	gsi_render_pass_submit(&gsi, &cb, gs_color(10, 10, 10, 255));

	// Submit command buffer for GPU
	gs_graphics_submit_command_buffer(&cb);
}

gs_app_desc_t gs_main(int32_t argc, char** argv)
{
	return (gs_app_desc_t) {
		.window_width = 800,
		.window_height = 600,
		.init = init,
		.update = update
	};
}
