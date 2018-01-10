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

	// Create some buttons
	frc::JoystickButton button { &joy, 1 };
};

#endif  // OI_H_
