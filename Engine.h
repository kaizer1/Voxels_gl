#pragma once



const int NUM_TEAPOTS_X = 8;
const int NUM_TEAPOTS_Y = 8;
const int NUM_TEAPOTS_Z = 8;
#include "Program.h"
//-------------------------------------------------------------------------
// Shared state for our app.
//-------------------------------------------------------------------------
struct android_app;

class Engine {
	//	MoreTeapotsRenderer renderer_;

	//ndk_helper::GLContext* gl_context_;

	Program* program = nullptr;
	bool initialized_resources_;
	bool has_focus_;

	//ndk_helper::DoubletapDetector doubletap_detector_;
	//ndk_helper::PinchDetector pinch_detector_;
	//ndk_helper::DragDetector drag_detector_;
	//ndk_helper::PerfMonitor monitor_;

//	ndk_helper::TapCamera tap_camera_;

//	android_app* app_;

//	ASensorManager* sensor_manager_;
//	const ASensor* accelerometer_sensor_;
//	ASensorEventQueue* sensor_event_queue_;

	//void UpdateFPS(float fps);
	//void ShowUI();
	//void TransformPosition(ndk_helper::Vec2& vec);

public:
	//static void HandleCmd(struct android_app* app, int32_t cmd);
	//static int32_t HandleInput(android_app* app, AInputEvent* event);

	Engine();
	~Engine();

//	void SetState(android_app* state);
//	int InitDisplay();
//	void LoadResources();
//	void UnloadResources();
//	void DrawFrame();
//	void TermDisplay();
//	void TrimMemory();
//	bool IsReady();
////	void UpdatePosition(AInputEvent* event, int32_t index, float& x, float& y);
//	void InitSensors();
//	void ProcessSensors(int32_t id);
//	void SuspendSensors();
//	void ResumeSensors();

};

