#ifndef ELToro1_H
#define ELToro1_H

#include <Commands/Subsystem.h>
#include <Spark.h>

class ELToro1 : public Subsystem {
private:
	frc::Spark Left_Toro{ 3 };
	frc::Spark Right_Toro{ 4 };

public:
	ELToro1();
	void InitDefaultCommand();
	void Spin(double Direction);
};

#endif  // ELToro1_H
