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
enum class AxisDir
{
	Positive,
	Negative,
	None,
};

class InputObj
{
public:
	DeviceType deviceType;
	unsigned deviceID;
	InputType inputType;
	unsigned inputID;
	AxisDir axisDir;

	InputObj(DeviceType deviceType, unsigned deviceID, InputType inputType, unsigned inputID, AxisDir axisDir)
		: deviceType(deviceType), deviceID(deviceID), inputType(inputType), inputID(inputID), axisDir(axisDir) {}
};



#endif