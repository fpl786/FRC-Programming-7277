#ifndef SetShootingSpeed_H
#define SetShootingSpeed_H

#include <Commands/Command.h>

class SetShootingSpeed : public Command {
public:
	SetShootingSpeed(double speed);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
private:
	double speed;
};

#endif  // ShootingSpeedFull_H
