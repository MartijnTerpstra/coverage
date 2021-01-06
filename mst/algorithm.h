#pragma once

namespace mtmath {

inline float saturate(float value)
{
	if (value < 0.0f)
		return 0.0f;
	if (value > 1.0f)
		return 1.0f;
	return value;
}

float clamp(float value, float minValue, float maxValue);

}