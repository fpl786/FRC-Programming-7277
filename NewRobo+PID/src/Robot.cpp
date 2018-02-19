#include "Robot.h"

#include <iostream>
#include <cmath>
#include <SmartDashboard/SmartDashboard.h>

DriveTrain* Robot::drivetrain = nullptr;
OI* Robot::oi = nullptr;
ELToro1* Robot::eltoro1 = nullptr;
Climber* Robot::climber = nullptr;

void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
	drivetrain = new DriveTrain();
	oi =  new OI();
	eltoro1 =new ELToro1();
	Reset = new ResetSensor();
	climber = new Climber();
	frc::SmartDashboard::PutData(drivetrain);
	frc::SmartDashboard::PutData(eltoro1);

	Log();

}

void Robot::AutonomousInit() {
	//AutoCommand = autoChooser->GetSelected();
	//AutoCommand->Run();

	//autonomousCommand.Start();
	std::cout << "Starting Auto" << std::endl;
}

void Robot::AutonomousPeriodic() {
	Schedule->Run();
	Log();
}

void Robot::TeleopInit() {
	/*
	 * This makes sure that the autonomous stops running when
	*teleop starts running. If you want the autonomous to
	* continue until interrupted by another command, remove
	* this line or comment it out.
	* */
	std::cout << "Starting Teleop" << std::endl;



}

void Robot::TeleopPeriodic() {
	Schedule->Run();
	Log();
}

void Robot::TestPeriodic() {

}

void Robot::DisabledInit(){
	Reset->Start();
}

void Robot::Log(){
	frc::SmartDashboard::PutNumber("Distance Traveled",
			round((double)drivetrain->GetAveRev()*47.9));
}

START_ROBOT_CLASS(Robot)
