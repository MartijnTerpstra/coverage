#include <algorithm.hpp>

float mtmath::saturate(float value)
{
	if (value < 0)
		return 0;
	if (value > 1)
		return 1;
	return value;
}

float mtmath::clamp(float value, float minValue, float maxValue)
{
	if (value < minValue)
		return minValue;
	if (value > maxValue)
		return maxValue;
	return value;
}