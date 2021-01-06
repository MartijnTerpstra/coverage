#pragma once

namespace mtmath {

float saturate(float value)
{
	if (value < 0.0f)
		return minValue;
	if (value > 1.0f)
		return maxValue;
	return value;
}

float clamp(float value, float minValue, float maxValue);

}