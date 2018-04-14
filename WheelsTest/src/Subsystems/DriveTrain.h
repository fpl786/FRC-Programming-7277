/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once
#ifndef DriveTrain_H
#define DriveTrain_H


#include <Drive/DifferentialDrive.h>
#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Spark.h>
#include <Joystick.h>
#include <GenericHID.h>

class DriveTrain : public frc::Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand() override;
	void ArcadeDrive();
	void Spin180();
	void StopMotors();

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::Spark LMotor {3};
	frc::Spark RMotor {1};
	frc::DifferentialDrive driveTrain{LMotor,RMotor};
	frc::Joystick* stick;
};
#endif //DriveTrain_H
