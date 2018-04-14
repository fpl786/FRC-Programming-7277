#ifndef ROBOT_H
#define ROBOT_H

#include <memory>
#include <DriverStation.h>
#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Scheduler.h>
#include <PowerDistributionPanel.h>
#include <SmartDashboard/SendableChooser.h>
#include <CameraServer.h>
#include <SmartDashboard/SmartDashboard.h>

#include "OI.h"
#include "Subsystems/DriveTrain.h"

class Robot: public frc::IterativeRobot {

public:

    static DriveTrain* driveTrain;
    static OI* oi;

private:
		frc::Scheduler* Schedule = Scheduler::GetInstance();

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
