#pragma once

namespace mtmath {

float saturate(float value)
{
	if (value < 0)
		return 0;
	if (value > 1)
		return 1;
	return value;
}

float clamp(float value, float minValue, float maxValue);

}