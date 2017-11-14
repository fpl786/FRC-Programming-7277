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
	frc::Joystick snes { 1 };

	// Create some buttons
	frc::JoystickButton blue { &snes, 1 };
	frc::JoystickButton red { &snes, 2 };
	frc::JoystickButton green { &snes, 3 };
	frc::JoystickButton yellow { &snes, 4 };

};

#endif  // OI_H_
