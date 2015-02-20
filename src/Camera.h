#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "glm_header.h"

class Camera {
protected:
	float m_fFoV, m_fAspect, m_fNearZ, m_fFarZ;
	vec2 m_vMouseInitPos;
	vec3 m_vEye, m_vTo, m_vUp;
	mat4 m_mWorldTransform, m_mViewTransform, m_mProjTransform, m_mProjViewTransform;
	void UpdateProjectionViewTransform();
public:
	Camera();
	virtual void update(const float a_fdt) = 0;
	void setPerspective(const float a_fFoV, const float a_fAspect, const float a_fNearZ, const float a_fFarZ);
	void setLookAt(const vec3 a_vFrom, const vec3 a_vTo, const vec3 a_vUp);
	void setPos(const vec3 a_vPos);
	void setFoV(const float a_fFoV);
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();
	float getFoV();
};

class FlyCamera : public Camera {
private:
	float m_fSpeed;
	bool m_bMousePress;
public:
	FlyCamera(const float a_fSpeed);
	void update(const float a_fdt);
	void setSpeed(const float a_fSpeed);
};

#endif//_CAMERA_H_