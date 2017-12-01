#ifndef ArcadeDriveWithJoystick_H
#define ArcadeDriveWithJoystick_H

#include <Commands/Command.h>


class ArcadeDriveWithJoystick : public Command {
public:
	ArcadeDriveWithJoystick();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

};

#endif  // ArcadeDriveWithJoystick_H
