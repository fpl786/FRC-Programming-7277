#ifndef OI_H_
#define OI_H_

#include <Buttons/JoystickButton.h>
#include <XboxController.h>
#include <Joystick.h>

class OI {
public:
	OI();
	frc::XboxController* GetController();


private:
	frc::XboxController c_1 { 0 };
	frc::Joystick xBoxControllerMap { 0 };
	frc::JoystickButton button1 {&xBoxControllerMap, 1 };
	frc::JoystickButton button2 {&xBoxControllerMap, 2 };

};

#endif  // OI_H_
