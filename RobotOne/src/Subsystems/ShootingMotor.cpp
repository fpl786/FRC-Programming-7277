#include "ShootingMotor.h"
#include <LiveWindow/LiveWindow.h>

ShootingMotor::ShootingMotor()
		: Subsystem("ShootingMotor") {

}

void ShootingMotor::InitDefaultCommand() {

}

void ShootingMotor::setSpeed(double speed) {
	shootingMotor.Set(speed);
}
