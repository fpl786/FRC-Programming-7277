#include "Robot.h"

#include <iostream>

//Setting up the pointer to contain NULL in case the robot init doesn not run, I guess
 DriveTrain* Robot::drivetrain = NULL;
 OI* Robot::oi = NULL;

void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
	drivetrain = new DriveTrain();
	oi =  new OI();
	frc::SmartDashboard::PutData(drivetrain);
}

void Robot::AutonomousInit() {
	std::cout << "Starting Auto" << std::endl;

}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)
