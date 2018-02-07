#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <RobotDrive.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/MotorControl/SensorCollection.h>
#include <GenericHID.h>
namespace frc {
class XboxController;
}

/*tx Indicate that the motor controler is Talon SRX
 * t Indicate that the motor controler is Talon
 * s indicate that the motor controller is Spark
 */

class DriveTrain : public frc::Subsystem {
private:
	WPI_TalonSRX * tx_rghtFront = new WPI_TalonSRX(2);
	WPI_TalonSRX * tx_rghtFollower = new WPI_TalonSRX(4);
	WPI_TalonSRX * tx_leftFront = new WPI_TalonSRX(1);
	WPI_TalonSRX * tx_leftFollower = new WPI_TalonSRX(3);
	SpeedControllerGroup * rghtFront = new SpeedControllerGroup{*tx_rghtFront, *tx_rghtFollower};
	SpeedControllerGroup * leftFront = new SpeedControllerGroup{*tx_leftFront, *tx_leftFollower};

	frc::DifferentialDrive driveTrain {*leftFront ,*rghtFront};
	frc::Talon t_middleH1 { 0 };
	frc::Talon t_middleH2 { 1 };
	frc::SpeedControllerGroup t_middleH {t_middleH1, t_middleH2};

public:
	DriveTrain();

	void InitDefaultCommand() override;

	/**
	 * Tank style driving for the DriveTrain.
	 * @param left Speed in range [-1,1]
	 * @param right Speed in range [-1,1]
	*/
	void Drive(double yMoveValue, double xMoveValue, double rotateValue);

	/**
	* @param joy
	*/
	void ArcadeDrive(frc::XboxController* controller);

	/**
	* @param joy
	*/
	void MainDrive(frc::XboxController* controller);


	double GetAveRev();

	void ResetSensor();


};

#endif  // DriveTrain_H
