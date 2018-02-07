#ifndef Spin_H
#define Spin_H

#include <Commands/Command.h>


class Spin : public Command {
public:
	Spin(double Direction);
	void Initialize() override;
	bool IsFinished() override;
	void End( )override;
private:
	double Direction;

};

#endif  // Spin_H
