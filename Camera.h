#pragma once

import lMath;
import lOpenGL;

// Uniform struct, needs to be arranged in multiples of 4 * 4 B for tight packing on GPU
using namespace losMath;
using namespace losGraphics;



struct CameraParam {
	lm44  WTVmatrix;    // 16 * 4 B ->   0 -  15
	lm44 VTPmatrix;    // 16 * 4 B ->  16 -  31
	lv3 position;        //  3 * 4 B ->  32 -  34
};

class CameraL {


private:
	lv3 lookp, yvec;
	lv3 heading, side, up;
	lFloat mspeed, rspeed, phi, theta;
	lFloat frustumFar;

	bool isPaused;
	bool needUpdate;

	lUnsignedInt cameraBuffer;
	lInt* winWidth, * winHeight;

	CameraParam param;

	void Update();
	void UploadParams();

public:
	CameraL(lv3 startpos, lInt* screenWidth, lInt* screenHeight,
		lFloat farInit);

	bool Init();
	void SetFrustum();
	void ResetCamera(lv3 pos);
	void MoveForward(lFloat deltaT);
	void MoveRight(lFloat deltaT);
	void MoveUp(lFloat deltaT);
	void RotateCamera(lInt dx, lInt dy);
	void UpdateCamera();

	void TogglePause() { isPaused = !isPaused; }

	lFloat* GetSpeedPtr() { return &mspeed; }

	lFloat* GetRotSpeedPtr() { return &rspeed; }

	CameraParam* GetCameraInfo() { return &param; }
};

