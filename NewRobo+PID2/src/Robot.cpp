#include "Robot.h"

#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>

DriveTrain* Robot::drivetrain = nullptr;
OI* Robot::oi = nullptr;
ELToro1* Robot::eltoro1 = nullptr;
Winch* Robot::winch = nullptr;
Pulley* Robot::pulley =  nullptr;
Climber* Robot::climber =  nullptr;
void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
	climber = new Climber();
	drivetrain = new DriveTrain();
	oi =  new OI();
	eltoro1 =new ELToro1();
	Reset = new ResetSensor();
	RAuto = new RAutonomous(1);
	LAuto = new LAutonomous(1);

	winch = new Winch();
	pulley = new Pulley();
	/**frc::SmartDashboard::PutData(drivetrain);
	frc::SmartDashboard::PutData(eltoro1);
	frc::SmartDashboard::PutData(winch);
	frc::SmartDashboard::PutData(pulley);**/
	CameraServer::GetInstance()->StartAutomaticCapture();
	Log();

}

void Robot::AutonomousInit() {
	//Auto Code here
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData.length() > 0){
		if(gameData[0] == 'L'){
			RAuto->Start();
		} else {
			LAuto->Start();

		}
	}
	//Put output here
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
