#include "Spin.h"
#include "Robot.h"

Spin::Spin(double Direction):
frc::Command("Spin"){
	Requires(Robot::eltoro1);
	this->Direction = Direction;

}

// Called just before this Command runs the first time
void Spin::Initialize() {
	Robot::eltoro1->Spin(Direction);
}


// Make this return true when this Command no longer needs to run execute()
bool Spin::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void Spin::End() {

}


