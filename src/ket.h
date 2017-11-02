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
		int _currentLane;
	
	public:
		int switch_lane(vector<vector<double>> sensor_fusion, vector<double> car_data, int prev_size);
		//DrivingBehavoir();
		int identify_lane(double d);
	};

int DrivingBehave::identify_lane(double d)
{
	if ( d < 4.0) 
		{ _currentLane=0; 
		  return _currentLane; }
	if ( d >= 4.0 and d < 8.0)
		{ _currentLane=1; return _currentLane;}
	else 
		{ _currentLane=2;
		  return _currentLane;
		}
		
	return -1;			
	
}
	
int DrivingBehave::switch_lane(vector<vector<double>> sensor_fusion, vector<double> car_data, int prev_size)
{
#if ket_debug_
	cout << " watch list creation" <<car_data[0];
#endif
	
	double car_x=car_data[0];
	double car_y=car_data[1];
	double car_s=car_data[2];
	double car_d=car_data[3];
	double car_speed=car_data[4];
	int car_lane=-1;
	
	if (identify_lane(car_d) != -1) car_lane=_current_lane;
	
	for (int i=0; i<sensor_fusion.size(); i++)
	{
		double vx = sensor_fusion[i][3];
		double vy = sensor_fusion[i][4];
		double check_speed = sqrt(vx*vx+vy*vy);
		double check_car_s = sensor_fusion[i][5];
		double check_car_d = sensor_fusion[i][6];
		int check_car_lane=-1;
		if (identify_lane(check_car_d) != -1) int check_car_lane =_current_lane;
		
		if (car_lane != check_car_lane)
		{
			//check car distance and car_speed, and identify if you would like to switch.
		}
		
	
	}	
	
	
	
	
	
	if (i != -1)
		return _currentLane;
	else
		return -1;
}			
#endif //KET_H
