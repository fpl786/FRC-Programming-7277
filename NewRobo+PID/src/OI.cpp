
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
	button3.WhenPressed(new Climb(1,1,0));//pole extends
	button3.WhenReleased(new Climb(0,0,0));

	button4.WhenPressed(new Climb(-1,0,0));//pole withdraws
	button4.WhenReleased(new Climb(0,0,0));

	button5.WhenPressed(new Climb(0,1,0));//robot is lifted
	button5.WhenReleased(new Climb(0,0,0));

	button6.WhenPressed(new Climb(0,-1,0));//robot is lowered
	button6.WhenReleased(new Climb(0,0,0));
}

XboxController* OI::GetController(){
	return &c_1;
}
