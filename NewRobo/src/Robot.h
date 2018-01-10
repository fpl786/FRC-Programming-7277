#ifndef ROBOT_H
#define ROBOT_H


#include <memory>

#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Scheduler.h>



#include "Commands/ArcadeDriveWithJoystick.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"


class Robot: public frc::IterativeRobot {
public:
	static DriveTrain* drivetrain;
	static OI* oi;

private:
	ArcadeDriveWithJoystick* joyControl;
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	frc::Scheduler* Schedule = Scheduler::GetInstance();

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};

#endif  // ROBOT_H_
