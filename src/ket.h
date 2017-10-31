#ifndef KET_H
#define KET_H
#define ket_debug 1
#define ket_debug_ 0

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DrivingBehavior {

	public:
		vector<int> WatchList(vector<vector<double>> sensor_fusion, vector<double> car_data);
		//DrivingBehavoir();
		
	}

vector<int> DrivingBehavior::WatchList(vector<vector<double>> sensor_fusion, vector<double> car_data)
{
#if ket_debug
	cout << car_data[0];
#endif
	vector<int> value;
	value.push_back(3);
	return value;
}

/*	

	for (int i=0; i < sensor_fusion.size(); i++)
			{
			
				double vx = sensor_fusion[i][3];
				double vy = sensor_fusion[i][4];
				double check_speed = sqrt(vx*vx+vy*vy);
				double check_car_s = sensor_fusion[i][5];
				check_car_s+=((double) prev_size*0.02*check_speed);
				bool check_front_car=	(((check_car_s > car_s) && ((check_car_s-car_s) <30)));
				bool check_behind_car= (((check_car_s < car_s) && ((car_s - check_car_s) <20)));
				if ( check_front_car || check_behind_car) 
//						(car_s - check_car_s) <30 )
				{ // there is behind or infront of our car or behind us
					// add the index of this car to the list
#if ket_debug
					watch_list.push_back(sensor_fusion[i][0]);				
					cout << "ith sensor is added to watch list "<< i << endl;
					cout <<  check_car_s-car_s  << " " << check_car_s-car_s<<endl;
#endif
#if ket_debug
				cout << "  " << car_x << " " << car_y << " " << car_s << " "<< car_d << endl;				
				cout << sensor_fusion[i][0] << " " << sensor_fusion[i][1] << " " << sensor_fusion[i][2] << " " << sensor_fusion[i][5] << " "<< sensor_fusion[i][6] << endl;
#endif




}
*/

			
#endif //KET_H
