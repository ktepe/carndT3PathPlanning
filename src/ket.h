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
		int if_change_lane(vector<vector<double>> sensor_fusion, vector<double> car_data, int prev_size);
		//DrivingBehavoir();
		int identify_lane(double d);
	};

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
	
	if ( car_lane == -1) 
	{
		cout << "we cannot identify the car lane in switch_lane " << endl; 
		return -1;
	}
	for (int i=0; i<sensor_fusion.size(); i++)
	{
		double vx = sensor_fusion[i][3];
		double vy = sensor_fusion[i][4];
		double check_speed = sqrt(vx*vx+vy*vy);
		double check_car_s = sensor_fusion[i][5];
		double check_car_d = sensor_fusion[i][6];
		int check_car_lane= identify_lane(check_car_d);
	
		if (car_lane != check_car_lane and check_car_lane !=-1)
		{
			//check car distance and car_speed, and identify if you would like to switch.
			bool front = (car_s <= check_car_s);
			bool back = (car_s > check_car_s);
			
			
#if ket_debug
	cout << "i: " << i<< " car_s: " << car_s << " check_car_s: "<< check_car_s << " front or back: 1 == front " << (front > back) << endl;  
#endif

		}
		
	
	}	
	

} //end of if_change_lane		
#endif //KET_H
