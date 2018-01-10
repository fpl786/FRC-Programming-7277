
#include "OI.h"

#include <WPILib.h>

OI::OI() {



}

frc::Joystick* OI::GetJoystick() {
	return &joy;
}
