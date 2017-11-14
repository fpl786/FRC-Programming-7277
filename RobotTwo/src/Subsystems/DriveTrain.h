#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <RobotDrive.h>

namespace frc {
class Joystick;
}

class DriveTrain : public frc::Subsystem {

public:
	DriveTrain();

	void InitDefaultCommand() override;

	/**
	 * Tank style driving for the DriveTrain.
	 * @param left Speed in range [-1,1]
	 * @param right Speed in range [-1,1]
	*/
	void Drive(double left, double right);

	/**
	* @param joy
	*/
	void Drive(frc::Joystick* joy);

private:
	frc::Talon frontLeft { 2 };
	frc::Talon rearLeft { 3 };
	frc::Talon frontRight { 4 };
	frc::Talon rearRight { 5 };
	frc::RobotDrive driveTrain { frontLeft, rearLeft, frontRight, rearRight };


};

#endif  // DriveTrain_H
