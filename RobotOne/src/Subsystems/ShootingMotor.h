#ifndef ShootingMotor_H
#define ShootingMotor_H

#include <Commands/Subsystem.h>
#include <Jaguar.h>

class ShootingMotor : public Subsystem {
private:
	frc::Jaguar shootingMotor{ 0 };

public:
	ShootingMotor();
	void InitDefaultCommand() override ;

	/**
	* @param Speed in range [-1,1]

	*/
	void setSpeed(double speed);
};

#endif  // ShootingMotor_H
