
#include "OI.h"
#include "Commands/Spin.h"
#include <WPILib.h>

OI::OI() {
	//Map one button
	button1.WhenPressed(new Spin(1));
	button1.WhenReleased(new Spin(0));
	//Map another Button
	button2.WhenPressed(new Spin(-1));
	button2.WhenReleased(new Spin(0));

}

XboxController* OI::GetController(){
	return &c_1;
}
