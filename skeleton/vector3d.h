#pragma once

class Vector3D {
	float x, y, z;
public:
	Vector3D(int xValue, int yValue, int zValue);
	float module();
	Vector3D normalize();
	Vector3D operator*(const float& r)const&;

	//scalar product
	float operator*(const Vector3D& r)const&;

	Vector3D operator+(const Vector3D& r) const&;
	Vector3D operator-(const Vector3D& r) const&;

	float getX() const;
	float getY()const;
	float getZ()const;
};