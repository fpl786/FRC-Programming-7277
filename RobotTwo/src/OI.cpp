#include "OI.h"

#include <WPILib.h>

OI::OI() {
	// Connect the buttons to commands

}

frc::Joystick* OI::GetJoystick() {
	return &joy;
}
