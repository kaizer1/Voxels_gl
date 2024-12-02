


import lMath;
import lOpenGL;

using namespace losMath;
using namespace losGraphics;

#include "Camera.h"
#include "lDefine.h"
#define _USE_MATH_DEFINES
#include "cmath"
#include "GL_utilities.h"



CameraL::CameraL(lv3 startpos, lInt* screenWidth, lInt* screenHeight,
	lFloat farInit) {

	isPaused = true;
	needUpdate = true;

	param.position = startpos;
	yvec = lv3(0.0f, 1.0f, 0.0f);

	mspeed = 10.0f;
	rspeed = 0.001f;
	phi = 2.0f * (lFloat)M_PI / 2.0f;
	theta = 2.0f * (lFloat)M_PI / 4.0f;

	frustumFar = farInit;

	winWidth = screenWidth;
	winHeight = screenHeight;

	SetFrustum();
	Update();
}

bool CameraL::Init() {
	glGenBuffersm(1, &cameraBuffer);
	glBindBufferBasem(uniformBuffer, UNIFORM_BINDING::CAMERA, cameraBuffer);
	glBufferDatam(uniformBuffer, sizeof(CameraParam), NULL, glStreamDraw);

	// Set starting WTVmatrix
	UploadParams();

	return true;
}

void CameraL::ResetCamera(lv3 pos) {
	param.position = pos;

	phi = 7.0f * (float)M_PI / 4.0f;
	theta = (float)M_PI / 2.0f;
}

void CameraL::SetFrustum() {
	GLfloat ratio = (GLfloat)*winWidth / (GLfloat)*winHeight;
	GLfloat width = (ratio > 1.0f) ? 1.0f : ratio;
	GLfloat height = (ratio > 1.0f) ? 1.0f / ratio : 1.0f;

	param.VTPmatrix = glm::frustum(-width, width, -height, height, 1.0f,
		frustumFar);

	needUpdate = true;
}


void CameraL::Update() {
	// Update directions
	heading = glm::normalize(
		glm::vec3(-sin(theta) * sin(phi), cos(theta), sin(theta) * cos(phi)));
	side = glm::normalize(glm::cross(heading, yvec));
	up = glm::normalize(glm::cross(side, heading));

	// Update camera matrix
	lookp = param.position + heading;
	param.WTVmatrix = lookAt(param.position, lookp, yvec);
}

void CameraL::UploadParams() {
	glBindBufferBasem(uniformBuffer, CAMERA, cameraBuffer);
	glBufferSubDatam(uniformBuffer, NULL, sizeof(CameraParam), &param);
}

void CameraL::UpdateCamera() {
	if (needUpdate) {
		Update();
		UploadParams();
	}
	needUpdate = false;
}

void CameraL::MoveForward(GLfloat deltaT) {
	if (!isPaused) {
		auto speedDelta = mspeed * deltaT;
		param.position += heading * speedDelta; //mspeed * deltaT;
		needUpdate = true;
	}
}

void CameraL::MoveRight(GLfloat deltaT) {
	if (!isPaused) {
		auto mSped = mspeed * deltaT;
		lv3 mya = side * mSped;
		param.position += mya; // * mspeed * deltaT;
		needUpdate = true;
	}
}

void CameraL::MoveUp(GLfloat deltaT) {
	if (!isPaused) {
		param.position += up * mspeed * deltaT;
		needUpdate = true;
	}
}

void CameraL::RotateCamera(GLint dx, GLint dy) {
	if (!isPaused) {
		float eps = 0.001f;

		phi += rspeed * dx;
		theta += rspeed * dy;

		phi = (float)fmod(phi, 2.0f * (float)M_PI);
		theta = theta < (float)M_PI - eps ? (theta > eps ? theta : eps) :
			(float)M_PI - eps;
		needUpdate = true;
	}
}