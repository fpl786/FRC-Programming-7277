
#ifndef OI_H_
#define OI_H_

//Include files from nessercary libary
#include <Buttons/JoystickButton.h>
#include <XboxController.h>
#include <Joystick.h>

//Declare the class for the file
class OI {
//Public class that can be access by any other file encapsule within the same project
public:
	//Declaration of the class object
	OI();
	//Creating the objects
	frc::XboxController* GetController();
	frc::Joystick* GetJoystick();

//Private class that only accessable by the class itself 
private:
	//Mapping the variables to actual button
	frc::XboxController c_1 { 0 };
	frc::Joystick xBoxControllerMap { 0 };
	frc::Joystick xBoxControllerMap2 { 1 };
	frc::Joystick joystick { 1 };
	frc::JoystickButton buttonA {&xBoxControllerMap, 1 };
	frc::JoystickButton buttonB {&xBoxControllerMap, 2 };

	frc::JoystickButton buttonX {&xBoxControllerMap, 3 };
	frc::JoystickButton buttonY {&xBoxControllerMap, 4 };

	frc::JoystickButton buttonLb {&xBoxControllerMap, 5 };
	frc::JoystickButton buttonRb {&xBoxControllerMap, 6 };
	/*configures snes controller
	frc::Joystick SNES { 1 };
	frc::JoystickButton sbutton1 {&SNES, 1 };
	frc::JoystickButton sbutton2 {&SNES, 2 };
	frc::JoystickButton sbutton3 {&SNES, 9 };
	frc::JoystickButton sbutton4 {&SNES, 10 };
	*/

};

//Ending 
#endif  // OI_H_
