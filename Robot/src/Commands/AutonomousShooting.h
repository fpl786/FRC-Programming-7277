#ifndef AutonomousShooting_H
#define AutonomousShooting_H

#include <Commands/Command.h>

class AutonomousShooting : public Command {
public:
	AutonomousShooting(double speed, double timeout);
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:
	double speed;
	double timeout;
};

#endif  // ShootingSpeedFull_H
