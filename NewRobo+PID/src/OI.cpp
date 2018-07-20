//Including necessary files in order for button mapping
#include <Commands/SpinWinch.h>
#include <Commands/SpinPulley.h>
#include <Commands/Spin.h>
#include "OI.h"
#include <WPILib.h>

//Definfing the OI 
OI::OI() {
	//Map button for El Toro In
	buttonX.WhenPressed(new Spin(1));
	buttonX.WhenReleased(new Spin(0));

	//Map button for El Toro Out
	buttonB.WhenPressed(new Spin(-1));
	buttonB.WhenReleased(new Spin(0));

	//Map Button for raising pulley
	buttonY.WhenPressed(new SpinPulley(1,0));//pole extends
	buttonY.WhenReleased(new SpinPulley(0,0));

	//Map Button for lowering pulley
	buttonA.WhenPressed(new SpinPulley(-1,0));//pole withdraws
	buttonA.WhenReleased(new SpinPulley(0,0));

	//Map button for lifting robot
	buttonLb.WhenPressed(new SpinWinch(1,0));//robot is lifted
	buttonLb.WhenReleased(new SpinWinch(0,0));

	//Map button for lowering robot
	buttonRb.WhenPressed(new SpinWinch(-1,0));//robot is lowered
	buttonRb.WhenReleased(new SpinWinch(0,0));
}

//Returning the objects so that the controller can be access from other variables
XboxController* OI::GetController(){
	return &c_1;
}
Joystick* OI::GetJoystick(){
	return &joystick;
}
