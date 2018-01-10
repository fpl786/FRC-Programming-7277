#include "Robot.h"

#include <iostream>

DriveTrain* Robot::drivetrain = NULL;
OI* Robot::oi = NULL;

void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
	drivetrain = new DriveTrain();
	oi =  new OI();
	joyControl = new ArcadeDriveWithJoystick();

}

void Robot::AutonomousInit() {
	//autonomousCommand.Start();
	std::cout << "Starting Auto" << std::endl;
}

void Robot::AutonomousPeriodic() {
	Schedule->Run();
}

void Robot::TeleopInit() {
	/*
	 * This makes sure that the autonomous stops running when
	*teleop starts running. If you want the autonomous to
	* continue until interrupted by another command, remove
	* this line or comment it out.
	* */
	std::cout << "Starting Teleop" << std::endl;
	joyControl->Start();

}

void Robot::TeleopPeriodic() {
	Schedule->Run();
}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot)
