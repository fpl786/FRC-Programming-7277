#include "Commands/SetShootingSpeed.h"
#include "OI.h"

#include <WPILib.h>

OI::OI() {
	// Connect the buttons to commands
	blue.WhenPressed(new SetShootingSpeed(0.75));
	red.WhenPressed(new SetShootingSpeed(0));
	yellow.WhenPressed(new SetShootingSpeed(0.5));
	green.WhenPressed(new SetShootingSpeed(1));

}

frc::Joystick* OI::GetJoystick() {
	return &joy;
}
