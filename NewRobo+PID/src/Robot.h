#ifndef ROBOT_H
#define ROBOT_H


#include <memory>

#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Scheduler.h>
#include <PowerDistributionPanel.h>
#include <SmartDashboard/SendableChooser.h>
#include <CameraServer.h>


#include "Commands/AutoDrive.h"
#include "Commands/HDriveWithJoystick.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/ELToro1.h"
#include "Commands/ResetSensor.h"
#include "Subsystems/Climber.h"

class Robot: public frc::IterativeRobot {
public:
	static DriveTrain* drivetrain;
	static OI* oi;
	static ELToro1* eltoro1;
	static Climber* climber;

private:
	frc::Scheduler* Schedule = Scheduler::GetInstance();
	ResetSensor* Reset;
	AutoDrive* AutoD;
	std::string gameData;
	//frc::SendableChooser<Command*>* autoChooser;
	//Command* AutoCommand;
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
