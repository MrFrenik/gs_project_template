#define GS_IMPL
#include <gs/gs.h>

#define GS_IMMEDIATE_DRAW_IMPL
#include <gs/util/gs_idraw.h>

#define GS_GUI_IMPL
#include <gs/util/gs_gui.h>

typedef struct app_t 
{
    gs_command_buffer_t cb;
    gs_immediate_draw_t gsi;
    gs_gui_context_t gui;
} app_t; 

void app_init() 
{
    app_t* app = gs_user_data(app_t);
	app->cb = gs_command_buffer_new();
	app->gsi = gs_immediate_draw_new(gs_platform_main_window());
    gs_gui_init(&app->gui, gs_platform_main_window());
}

void app_update()
{
    app_t* app = gs_user_data(app_t);
    gs_command_buffer_t* cb = &app->cb;
    gs_immediate_draw_t* gsi = &app->gsi;
    gs_gui_context_t* gui = &app->gui;

	gs_vec2 fbs = gs_platform_framebuffer_sizev(gs_platform_main_window()); 
	const float t = gs_platform_elapsed_time() * 0.0001f;

	if (gs_platform_key_pressed(GS_KEYCODE_ESC)) {
		gs_quit();
	}

	gsi_camera3D(gsi, fbs.x, fbs.y);
	gsi_rotatev(gsi, gs_deg2rad(90.f), GS_ZAXIS); gsi_rotatev(gsi, t, GS_YAXIS);
	gsi_sphere(gsi, 0.f, 0.f, 0.f, 1.f, 50, 150, 200, 50, GS_GRAPHICS_PRIMITIVE_LINES);
	gsi_camera2D(gsi, fbs.x, fbs.y);
	gsi_text(gsi, fbs.x * 0.5f - 70.f, fbs.y * 0.5f, "Hello, Gunslinger.", NULL, false, 255, 255, 255, 255);
	gsi_renderpass_submit(gsi, cb, fbs.x, fbs.y, gs_color(10, 10, 10, 255));

    // Render gui
    gs_gui_begin(gui, fbs); 
    if (gs_gui_window_begin(gui, "App", gs_gui_rect(100, 100, 200, 200))) {
        gs_gui_layout_row(gui, 1, (int[]){-1}, 0);
        gs_gui_text(gui, "Hello, Gunslinger.");
        gs_gui_window_end(gui);
    }
    gs_gui_end(gui);
    gs_gui_render(gui, cb);

	// Submit command buffer for GPU
	gs_graphics_command_buffer_submit(cb);
}

void app_shutdown()
{
    app_t* app = gs_user_data(app_t);
    gs_immediate_draw_free(&app->gsi);
    gs_command_buffer_free(&app->cb);
    gs_gui_free(&app->gui);
}

gs_app_desc_t gs_main(int32_t argc, char** argv)
{
	return (gs_app_desc_t) {
        .user_data = gs_malloc_init(app_t),
		.window_width = 800,
		.window_height = 600,
		.init = app_init,
		.update = app_update,
        .shutdown = app_shutdown
	};
}
