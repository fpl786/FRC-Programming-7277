#include "DriveTrain.h"
#include <XboxController.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/HDriveWithJoystick.h"

DriveTrain::DriveTrain()
	: Subsystem("drivetrain") {
	driveTrain.SetSafetyEnabled(false);
	driveTrain.SetExpiration(0.1);
	driveTrain.SetMaxOutput(1.0);
	tx_rghtFront->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
	tx_leftFront->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);

}

void DriveTrain::InitDefaultCommand (){
	SetDefaultCommand(new HDriveWithJoystick());
}

//This is Arcade Driving
void DriveTrain::Drive(double yMoveValue, double xMoveValue, double rotateValue){
	driveTrain.ArcadeDrive(yMoveValue, rotateValue);
	t_middleH.Set(xMoveValue);
}

void DriveTrain::ArcadeDrive(frc::XboxController* controller){
	driveTrain.ArcadeDrive(controller->GetX(GenericHID::JoystickHand::kLeftHand), controller->GetY(GenericHID::JoystickHand::kLeftHand));
}

void DriveTrain::MainDrive(frc::XboxController* controller){
	double yValue = 0;
	if (controller -> GetTriggerAxis(GenericHID::JoystickHand::kLeftHand) == 0){
		yValue = controller -> GetTriggerAxis(GenericHID::JoystickHand::kRightHand);
	}else if(controller -> GetTriggerAxis(GenericHID::JoystickHand::kRightHand) == 0){
		yValue = -(controller -> GetTriggerAxis(GenericHID::JoystickHand::kLeftHand));
	}
	driveTrain.ArcadeDrive(yValue, controller->GetX(GenericHID::JoystickHand::kLeftHand));
	t_middleH.Set(controller->GetX(GenericHID::JoystickHand::kRightHand));
}

double DriveTrain::GetAveRev(){
	double rghtRev;
	double leftRev;

	rghtRev = tx_rghtFront->GetSensorCollection().GetQuadraturePosition();
	leftRev = tx_leftFront->GetSensorCollection().GetQuadraturePosition();
	frc::SmartDashboard::PutNumber("right rev", rghtRev);
	frc::SmartDashboard::PutNumber("left rev", leftRev);

	return ( ((double)rghtRev+(double)leftRev)/2/4096 );

}

void DriveTrain::ResetSensor(){
	tx_rghtFront->GetSensorCollection().SetQuadraturePosition(0, 10);
	tx_leftFront->GetSensorCollection().SetQuadraturePosition(0, 10);
}
