#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <PWMTalonSRX.h>
#include <RobotDrive.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
namespace frc {
class Joystick;
}

class DriveTrain : public frc::Subsystem {
private:
	frc::PWMTalonSRX m_frontLeft { 1 };
	frc::PWMTalonSRX m_rearLeft { 2 };
	frc::SpeedControllerGroup m_left{m_frontLeft, m_rearLeft};
	frc::PWMTalonSRX m_frontRight { 3 };
	frc::PWMTalonSRX m_rearRight { 4 };
	frc::SpeedControllerGroup m_right{m_frontRight, m_rearRight};
	frc::DifferentialDrive driveTrain { m_left, m_right };
	frc::PWMTalonSRX m_middleH { 5 };
public:
	DriveTrain();

	void InitDefaultCommand() override;

	/**
	 * Tank style driving for the DriveTrain.
	 * @param left Speed in range [-1,1]
	 * @param right Speed in range [-1,1]
	*/
	void Drive(double moveValue, double rotateValue);

	/**
	* @param joy
	*/
	void ArcadeDrive(frc::Joystick* joy);

	/**
	* @param joy
	*/
	void HDrive(frc::Joystick* joy);


};

#endif  // DriveTrain_H
