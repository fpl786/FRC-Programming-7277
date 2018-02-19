
#include "OI.h"
#include "Commands/Spin.h"
#include "Commands/Climb.h"
#include <WPILib.h>

OI::OI() {
	//Map one button
	button1.WhenPressed(new Spin(1));
	button1.WhenReleased(new Spin(0));
	//Map another Button
	button2.WhenPressed(new Spin(-1));
	button2.WhenReleased(new Spin(0));

	//SNES controls for climbing mechanism
	sbutton1.WhenPressed(new Climb(1,0,0));//pole extends
	sbutton1.WhenReleased(new Climb(0,0,0));

	sbutton2.WhenPressed(new Climb(-1,0,0));//pole withdraws
	sbutton2.WhenReleased(new Climb(0,0,0));

	sbutton3.WhenPressed(new Climb(0,1,0));//robot is lifted
	sbutton3.WhenReleased(new Climb(0,0,0));

	sbutton4.WhenPressed(new Climb(0,-1,0));//robot is lowered
	sbutton4.WhenReleased(new Climb(0,0,0));
}

XboxController* OI::GetController(){
	return &c_1;
}
