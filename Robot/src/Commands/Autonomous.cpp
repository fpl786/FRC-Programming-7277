#include "Autonomous.h"

#include <iostream>
#include <Commands/Drive.h>
#include <Commands/AutonomousShooting.h>


//Note:
// To run multiple commands at the same time,
// use AddParallel()
// e.g. AddParallel(new Command1());
//      AddSequential(new Command2());
// Command1 and Command2 will run in parallel.

Autonomous::Autonomous(double timeCo) :
		frc::CommandGroup("autonomousCommand"){
		AddSequential(new Drive( -0.75 , 0.0001 , 0.7*timeCo)); //Move forward 30 inches
		AddSequential(new Drive( 0.5 , 1.0, 0.70*timeCo)); //Turn 90 degrees right
		AddSequential(new Drive( -0.75 , 0.0001 , 0.7*timeCo)); //Move Forward 30 inches
		AddSequential(new Drive( 0.5, -1.0, 1.5*timeCo)); //Turn 180 degrees (right)
		//Engage shooting motor for 2 seconds (ideally 1 ball)
		AddSequential(new AutonomousShooting(1, 2));

		//Leave commented
		//AddSequential(new Drive( 0.5, -1.0, 0.07*timeCo)); //Turn 9 degrees (left?)
		//Engage shooting motor for 2 seconds (ideally 1 ball)
		//AddSequential(new AutonomousShooting(1, 2*timeCo));



}
