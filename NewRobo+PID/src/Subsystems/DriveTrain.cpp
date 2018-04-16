#include "DriveTrain.h"
#include <Joystick.h>
#include <XboxController.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/HDriveWithJoystick.h"

DriveTrain::DriveTrain()
	: Subsystem("drivetrain") {
	//Setting up the basics of the DriveTrain
	driveTrain.SetSafetyEnabled(false);
	driveTrain.SetExpiration(0.1);
	driveTrain.SetMaxOutput(1.0);

	//Configure the Follower Motor
	tx_rghtFollower->Follow(*tx_rghtFront);
	tx_leftFollower->Follow(*tx_leftFront);

	//This is to check if the sensor is right and invert them if needed
	tx_rghtFront->SetSensorPhase(false);
	tx_leftFront->SetSensorPhase(true);

	//tx_rghtFront->SetSensorDirection();
	//Configure the output and such
	//Minial Output
	tx_rghtFront->ConfigNominalOutputForward(0, kTimeoutMs);
	tx_rghtFront->ConfigNominalOutputReverse(0, kTimeoutMs);
	tx_leftFront->ConfigNominalOutputForward(0, kTimeoutMs);
	tx_leftFront->ConfigNominalOutputReverse(0, kTimeoutMs);

	//Max Output
	tx_rghtFront->ConfigPeakOutputForward(1, kTimeoutMs);
	tx_rghtFront->ConfigPeakOutputReverse(-1, kTimeoutMs);
	tx_leftFront->ConfigPeakOutputForward(1, kTimeoutMs);
	tx_leftFront->ConfigPeakOutputReverse(-1, kTimeoutMs);

	//Setting the Sensors (Mag Encoder with PID id of 0 and timeout of 10)
	tx_rghtFront->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);
	tx_leftFront->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);

	//Change all the PIDF value accordingly. :)
	//Setting the P value
	tx_rghtFront->Config_kP(kPIDLoopIdx, 0.1, kTimeoutMs);
	tx_leftFront->Config_kP(kPIDLoopIdx, 0.1, kTimeoutMs);

	//Setting the I value
	tx_rghtFront->Config_kI(kPIDLoopIdx, 0, kTimeoutMs);
	tx_leftFront->Config_kI(kPIDLoopIdx, 0, kTimeoutMs);

	//Setting the D value
	tx_rghtFront->Config_kD(kPIDLoopIdx, 0, kTimeoutMs);
	tx_leftFront->Config_kD(kPIDLoopIdx, 0, kTimeoutMs);

	//Setting the F value
	tx_rghtFront->Config_kF(kPIDLoopIdx, 0, kTimeoutMs);
	tx_leftFront->Config_kF(kPIDLoopIdx, 0, kTimeoutMs);

	int absolutePosition = tx_rghtFront->GetSelectedSensorPosition(0) & 0xFFF;
	tx_rghtFront->SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx,
					kTimeoutMs);
}

void DriveTrain::InitDefaultCommand (){
	SetDefaultCommand(new HDriveWithJoystick());
}

//This is Arcade Driving
void DriveTrain::Drive(double yMoveValue, double xMoveValue, double rotateValue){
	driveTrain.ArcadeDrive(yMoveValue, rotateValue);
	t_middleH.Set(xMoveValue);
}


void DriveTrain::MainDrive(frc::Joystick* joystick, frc::XboxController* controller){

	/*double yValue = 0;
	if (controller -> GetTriggerAxis(GenericHID::JoystickHand::kLeftHand) == 0){
		yValue = controller -> GetTriggerAxis(GenericHID::JoystickHand::kRightHand);
	}else if(controller -> GetTriggerAxis(GenericHID::JoystickHand::kRightHand) == 0){
		yValue = -(controller -> GetTriggerAxis(GenericHID::JoystickHand::kLeftHand));
	}
	driveTrain.ArcadeDrive(yValue, controller->GetX(GenericHID::JoystickHand::kLeftHand));*/

	driveTrain.ArcadeDrive(-joystick->GetY(), joystick->GetX());
	t_middleH.Set(0.35 * (controller->GetX(GenericHID::JoystickHand::kRightHand)));


}

void DriveTrain::AutoDrive(double leftMoveValue, double rightMoveValue){
	tx_leftFront->Set(ControlMode::Position, leftMoveValue*4096);
	tx_rghtFront->Set(ControlMode::Position, rightMoveValue*4096);
}

double DriveTrain::GetAveRev(){
	double rghtRev;
	double leftRev;

	rghtRev = tx_rghtFront->GetSelectedSensorPosition(kPIDLoopIdx);
	leftRev = tx_leftFront->GetSelectedSensorPosition(kPIDLoopIdx);
	frc::SmartDashboard::PutNumber("right rev", rghtRev);
	frc::SmartDashboard::PutNumber("left rev", leftRev);

	return ( ((double)rghtRev+(double)leftRev)/2/4096 );
}

void DriveTrain::ResetSensor(){
	tx_rghtFront->GetSensorCollection().SetQuadraturePosition(0, kTimeoutMs);
	tx_leftFront->GetSensorCollection().SetQuadraturePosition(0, kTimeoutMs);
}
