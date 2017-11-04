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
		int if_change_lane(vector<vector<double>> sensor_fusion, vector<double> car_data, int prev_size);
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
	
int DrivingBehave::if_change_lane(vector<vector<double>> sensor_fusion, vector<double> car_data, int prev_size)
{
#if ket_debug_
	cout << " watch list creation" <<car_data[0];
#endif
	
	double car_x=car_data[0];
	double car_y=car_data[1];
	double car_s=car_data[2];
	double car_d=car_data[3];
	double car_speed=car_data[4];
	int car_lane= identify_lane(car_d);
	vector<double> lane_rewards;
	
	for (int i; i<3; i++) lane_rewards.push_back(-10000.0);
#if ket_debug
	lane_rewards[car_lane]=cur_lane_reward;
	
	if ( car_lane == -1) 
	{
		cout << "we cannot identify the car lane in switch_lane " << endl; 
		return -1;
	}
	
	for (int i=0; i<sensor_fusion.size(); i++)
	{
		double vx = sensor_fusion[i][3];
		double vy = sensor_fusion[i][4];
		double check_car_speed = sqrt(vx*vx+vy*vy);
		double check_car_s = sensor_fusion[i][5];
		double check_car_d = sensor_fusion[i][6];
		int check_car_lane= identify_lane(check_car_d);
		double check_car_lane_reward=-11000.0;
		
	
		if (car_lane != check_car_lane and fabs(check_car_s-car_s)>40.0)
		{
			//check car distance and car_speed, and identify if you would like to switch.
			
			check_car_lane_reward=lane_reward(car_s, check_car_speed, car_speed, check_car_speed, true);
			if (check_car_lane_reward < lane_rewards[check_car_lane])
				lane_rewards[check_car_lane]=check_car_lane_reward;
			
		}
#endif
		
#if ket_debug_
	cout << "i: " << i<< " car_s: " << car_s << " check_car_s: "<< check_car_s << " front or back: " << (front > back) << " this.cur_lane_reward: "<< cur_lane_reward << endl;  
#endif
#if ket_debug
	cout << "i: " << i<< " car_s: " << car_s << " check_car_s: "<< check_car_s << " front or back: " << (check_car_s-car_s) << " this.cur_lane_reward: "<< cur_lane_reward << " lane_reward "<<lane_rewards[check_car_lane] << endl;  
#endif
	}

} //end of if_change_lane		
#endif //KET_H
