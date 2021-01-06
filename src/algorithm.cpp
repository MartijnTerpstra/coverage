#include <algorithm.h>



float mtmath::clamp(float value, float minValue, float maxValue)
{
	if (value < minValue)
		return minValue;
	if (value > maxValue)
		return maxValue;
	return value;
}