#include "ELToro1.h"


ELToro1::ELToro1() : Subsystem("ELToro1") {

}

void ELToro1::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ELToro1::Spin(double Direction){
	Left_Toro.Set(Direction);
	Right_Toro.Set(-Direction);
}

