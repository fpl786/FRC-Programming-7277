#ifndef ROBOT_H
#define ROBOT_H


#include <memory>

#include <Commands/Command.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/ShootingMotor.h"

class Robot: public frc::IterativeRobot {
public:
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<ShootingMotor> shootingmotor;
	static std::unique_ptr<OI> oi;

private:
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};

#endif  // ROBOT_H_
