#include "Robot.h"

#include <iostream>

//Setting up the share Subsystems and oi so that the commands can use it
std::shared_ptr<DriveTrain> Robot::drivetrain = std::make_shared<DriveTrain>();
std::unique_ptr<OI> Robot::oi = std::make_unique<OI>();

void Robot::RobotInit() {
	frc::SmartDashboard::PutData(drivetrain.get());
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
