#ifndef INPUT_OBJ_H
#define INPUT_OBJ_H



enum class DeviceType
{
	Keyboard,
	Mouse,
	Gamepad,
};
enum class InputType
{
	Button,
	Axis,
};
enum class Direction
{
	Positive,
	Negative,
	None,
};

struct InputObj
{
	DeviceType deviceType;
	unsigned deviceID;
	InputType inputType;
	unsigned inputID;
	Direction direction;

	InputObj() = default;
	InputObj(DeviceType dt, unsigned did, InputType it, unsigned iid, Direction d)
		: deviceType(dt), deviceID(did), inputType(it), inputID(iid), direction(d) {}
};

#endif