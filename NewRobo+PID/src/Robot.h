#ifndef ROBOT_H
#define ROBOT_H


#include <memory>

//Including necessary files from the library
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <PowerDistributionPanel.h>
#include <SmartDashboard/SendableChooser.h>
#include <CameraServer.h>

//Including the commands files
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <Commands/LAutonomous.h>
#include <Commands/RAutonomous.h>
#include <Commands/AutoDrive.h>
#include <Commands/HDriveWithJoystick.h>
#include <Commands/ResetSensor.h>
#include <Commands/LAutonomous.h>
#include <Commands/RAutonomous.h>

//Including all of the Subsystems
#include <Subsystems/Winch.h>
#include <Subsystems/Pulley.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/ELToro1.h>

//Including the OI files for proper mapping and
#include "OI.h"

//Creation of the class robot that inherit from the class IterativeRobot from the IterativeRobot.h file
class Robot: public frc::IterativeRobot {
//Public variables
public:
	/*Static: it can be accessed before any objects of its class are created, and without reference to any object.
	These are pointers to the actual subsystems created in the Subsystem folder*/
	static DriveTrain* drivetrain;
	static ELToro1* eltoro1;
	static Winch* winch;
	static Pulley* pulley;
	//Pointer to the OI file
	static OI* oi;

//Prive members
private:
	//A type scheduler pointer to the an instance of the scheduler
	frc::Scheduler* Schedule = Scheduler::GetInstance();
	//Pointers to the commands that will be later declare in Robot.cpp
	ResetSensor* Reset;
	RAutonomous* RAuto;
	LAutonomous* LAuto;
	//A place holder for te Gamdata
	std::string gameData;
	//frc::SendableChooser<Command*>* autoChooser;
	//Command* AutoCommand;
	//Creating the commands that declare that we will be overiding the following functions
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void DisabledInit() override;
	void Log();
};

#endif  // ROBOT_H_
