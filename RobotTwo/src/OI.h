#ifndef OI_H_
#define OI_H_

#include <Buttons/JoystickButton.h>
#include <Joystick.h>

class OI {
public:
	OI();
	frc::Joystick* GetJoystick();

private:
	frc::Joystick joy { 0 };

};

#endif  // OI_H_
