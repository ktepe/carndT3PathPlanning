#ifndef KET_H
#define KET_H
#define ket_debug 1
#define ket_debug_ 0

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DrivingBehave {
	private:
		int _current_lane;
		
	public:
		double cur_lane_reward;
		//DrivingBehavoir();
		int identify_lane(double d);
		double lane_reward(double car_s, double check_car_s, double car_speed, double  check_car_speed, bool ahead);
	};

	
double DrivingBehave::lane_reward(double car_s, double check_car_s, double car_speed, double  check_car_speed, bool ahead)
{ 
	double reward = 0.0;
	double speed_bias=0.05;
	double distance_bias=1.0;
	
	if(ahead) {
		// distance^2+speed_dif^3
		// if ahead car is faster better,
		reward = distance_bias*(check_car_s-car_s)*(check_car_s-car_s);
		//did not include the speed for this version
		//reward+= speed_bias*(check_car_speed-car_speed)*(check_car_speed-car_speed)*(check_car_speed-car_speed);
		return reward;
	} 
	else
	{ //distance^2+speed_dif^3
		// if behind car is slower is better
		reward = distance_bias*(car_s-check_car_s)*(car_s-check_car_s);
		//reward += speed_bias*(car_speed-check_car_speed)*(car_speed-check_car_speed)*(car_speed-check_car_speed);
		return reward;
	}	
}

int DrivingBehave::identify_lane(double d)
{
	if ( d < 4.0)  
	{ return 0;}
	if ( d >= 4.0 and d < 8.0)
	{ return 1;}
	else 
	{ return 2;}
	//return -1 if the lane cannot be determined as error message.
	return -1;			
	
}
#endif //KET_H
