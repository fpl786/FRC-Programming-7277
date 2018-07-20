
#include "Robot.h"

#include <iostream>

#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>

//Setting these pointer to a null before actually declaring them so that the program doesn't freak out
DriveTrain* Robot::drivetrain = nullptr;
OI* Robot::oi = nullptr;
ELToro1* Robot::eltoro1 = nullptr;
Winch* Robot::winch = nullptr;
Pulley* Robot::pulley =  nullptr;

//This run once when the Robot is turn on
void Robot::RobotInit() {
	//Creating an object for the pointer to point to.
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

//This runs one before the Autonomous mode is activated
void Robot::AutonomousInit() {
	//Auto Code here
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData.length() > 0){
		if(gameData[0] == 'L'){
			LAuto->Start();
		} else {
			RAuto->Start();
		}
	}
	//Put output here
	std::cout << "Starting Auto" << std::endl;
}

//This continous runs while the Autonomous mode is active
void Robot::AutonomousPeriodic() {
	Schedule->Run();
	Log();
}

//This runs once before the Teleoperated mode is activate
void Robot::TeleopInit() {
	/*
	 * This makes sure that the autonomous stops running when
	*teleop starts running. If you want the autonomous to
	* continue until interrupted by another command, remove
	* this line or comment it out.
	* */
	std::cout << "Starting Teleop" << std::endl;



}

//This countinously runs while Teleoperated mode is active
void Robot::TeleopPeriodic() {
	Schedule->Run();
	Log();
}

//This runs countinously while Test mode is active
void Robot::TestPeriodic() {

}

//This is run once before the Robot is disable
void Robot::DisabledInit(){
	Reset->Start();
}

//Function to log robots variables ad out put it
void Robot::Log(){
	frc::SmartDashboard::PutNumber("Distance Traveled",
			round((double)drivetrain->GetAveRev()*47.9));
}

//Starting the robot
START_ROBOT_CLASS(Robot)
