#pragma once

static constexpr float PI = 22 / 7;

static float eulerToRad(float e) {
	return e * (PI / 180.f);
}

static float radToEuler(float r) {
	return r / (PI / 180.f);
}