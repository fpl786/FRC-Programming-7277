#include "Robot.h"

#include <iostream>

DriveTrain* Robot::drivetrain = NULL;
ShootingMotor* Robot::shootingmotor = NULL;
OI* Robot::oi = NULL;

void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
	drivetrain = new DriveTrain();
	shootingmotor = new ShootingMotor();
	oi =  new OI();
	autonomousCommand = new Autonomous(1.1);
	joyControl = new ArcadeDriveWithJoystick();

}

void Robot::AutonomousInit() {
	//autonomousCommand.Start();
	std::cout << "Starting Auto" << std::endl;
	autonomousCommand -> Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand -> Cancel();
	std::cout << "Starting Teleop" << std::endl;
	joyControl->Start();

}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot)
