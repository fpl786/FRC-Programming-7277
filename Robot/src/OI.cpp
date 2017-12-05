#include "Commands/SetShootingSpeed.h"
#include "OI.h"

#include <WPILib.h>

OI::OI() {
	// Connect the buttons to commands
	button.WhenPressed(new SetShootingSpeed(-1));
	button.WhenReleased(new SetShootingSpeed(0));


}

frc::Joystick* OI::GetJoystick() {
	return &joy;
}
