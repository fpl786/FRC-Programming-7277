#include "Robot.h"
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>


DriveTrain* Robot::driveTrain = nullptr;
OI* Robot::oi = nullptr;

void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
	Robot::driveTrain = new DriveTrain();
	Robot::oi =  new OI();



	/**frc::SmartDashboard::PutData(drivetrain);
	frc::SmartDashboard::PutData(eltoro1);
	frc::SmartDashboard::PutData(winch);
	frc::SmartDashboard::PutData(pulley);**/
	CameraServer::GetInstance()->StartAutomaticCapture();
	Log();

}

void Robot::AutonomousInit() {
	//Auto Code here

	//Put output here
	//std::cout << "Starting Auto" << std::endl;
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
	//std::cout << "Starting Teleop" << std::endl;



}

void Robot::TeleopPeriodic() {
	Schedule->Run();
	Log();
}

void Robot::TestPeriodic() {

}

void Robot::DisabledInit(){

}

void Robot::Log(){

}

START_ROBOT_CLASS(Robot)
