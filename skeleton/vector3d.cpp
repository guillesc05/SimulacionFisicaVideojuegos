#include "vector3d.h"
#include "math.h"

Vector3D::Vector3D(int xValue, int yValue, int zValue) : x(xValue), y(yValue), z(zValue) {

}

float Vector3D::module() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3D Vector3D::normalize() {
	float m = module();
	return Vector3D(x / m, y / m, z / m);

}

Vector3D Vector3D::operator*(const float& r)const& {
	return Vector3D(x * r, y * r, z * r);
}

float Vector3D::operator*(const Vector3D& r)const& {
	return x * r.x + y * r.y + z * r.z;
}

Vector3D Vector3D::operator+(const Vector3D& r) const& {
	return Vector3D(x + r.x, y + r.y, z + r.z);
}
Vector3D Vector3D::operator-(const Vector3D& r) const& {
	return Vector3D(x - r.x, y - r.y, z - r.z);
}

float Vector3D::getX()const {
	return x;
}
float Vector3D::getY()const {
	return y;
}
float Vector3D::getZ()const {
	return z;
}