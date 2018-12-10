#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

//input plan:
//create an array to contain the answers:

double PI = 3.1415926525;
double precision = 0.00001;

int is0(double near0) {
	if (abs(0 - near0) <= precision) {
		return 0;
	}
	return 1;
}

int mod(int a, int b) {
	//return positve a%b
	int result = a%b;
	if (result < 0) {
		result+=b;
	}
	return result;
}
double x_coord = 0;double y_coord = 0;
int direction = 90; // from as in geometry, the angle with the x-axis
string command; // lt, rt, fd, bk
vector<long long> answers;

void restore() {
	x_coord = 0; y_coord = 0;
	direction = 90;
}

void angle_updater(int angle) {
	//turn the turtle angle left
	direction+=angle;
	direction=mod(direction, 360);
	//cout << "direction now is: " << direction << endl;
}
void position_updater(long long step) {
	//update the position of the turtle
	double x_increment, y_increment;
	double rad_direction = direction * 2 * PI / 360;
	x_increment = step*cos(rad_direction);y_increment = step*sin(rad_direction);
	//cout << "x_increment is: " << x_increment << endl;
	//cout << "y_increment is: " << y_increment << endl;
	x_coord += x_increment; y_coord += y_increment;
	
	//test code
	//cout << "(" << x_coord << ","  << y_coord << ")" << endl;
}	
	
void updater(string command, string arg) {
	//receives a command, update the parameters of the turtle
	int argument = stoi(arg);
	if (command == "lt") {
	       	angle_updater(argument);
	}
       if (command == "rt") {
	       angle_updater(360 - argument);
       }
       if (command == "fd") {
	       position_updater(argument);
       }
       if (command == "bk") {
	       position_updater(0-argument);
       }
}

double length(double x1, double y1, double x2, double y2) {
	double x_part = x2 - x1; double y_part = y2 - y1;
	double square = x_part*x_part + y_part*y_part;
	double len = pow(square,0.5);
	//cout << "Calculated by length: " << len << endl;
	return len;
}

long long toint(double x) {
	double temp = x;
	if (x < 0) {
		temp*=-1;
	}
	temp+=0.5;
	long long y = (int) temp;
	if (x < 0) {
		return -y;
	}
	return y;
}

double arctan(double d1, double d2) {
	//calculate arctan(d1/d2)
	if (is0(d2) == 0) {
		if (d1 < 0) {
			return -PI/2;
		}
		else {
			return PI/2;
		}
	} else {
		return atan(d1/d2);
	}
}
	
int missing_angle(double xi, double yi, double xf, double yf) {
	//line1: (xf,yf)-(xi,yi)
	//line2: (0,0)-(xi,fi)
	//line3: (0,0)-(xf,xf)
	//(xi,yi) the point where commands is missing
	//(xf,yf) end point
	//calculate turn line1 to line2
	//len(line1) == len(line2)
	//arcsin(0.5line3/line1)*2
	//return angle needed counterclockwise(lt)
	double i0x = 0 - xi;
	double i0y = 0 - yi;
	double ifx = xf - xi;
	double ify = yf - yi;
	//cout << "xi yi xf yf " << xi << " " << yi << " " << xf << " " <<yf << endl;
	//cout << i0x << " " << i0y << endl;
	//cout << ifx << " " << ify << endl;
	double anglei0_r = arctan(i0y,i0x);
	double anglei0_d = anglei0_r * 360/(2*PI);
	if (i0x < 0 && is0(i0x) != 0) {
		anglei0_d += 180;
		anglei0_d = toint(anglei0_d);
		anglei0_d = mod(anglei0_d,360);
	}
	double angleif_r = arctan(ify,ifx);
	double angleif_d = angleif_r * 360/(2*PI);
	//cout << "anglei0_d is: " << anglei0_d << endl;
	//cout << "angleif_d is: " << angleif_d << endl;
	if (ifx < 0 && is0(ifx) != 0) {
		angleif_d += 180;
		//cout << "in if:angleif_d: " << angleif_d << endl;
		angleif_d = toint(angleif_d);
		angleif_d = mod(angleif_d, 360);
		//cout << "angleif_d after mod is: " << angleif_d << endl;
	}
	//double result_r = anglei0_r - angleif_r;
        //cout << "anglei0_d is: " << anglei0_d << endl;
	//cout << "angleif_d is: " << angleif_d << endl;

	//cout << "result_r is: " << result_r << endl;
	double result_d = anglei0_d - angleif_d;
	//cout << "result_d: " << result_d << endl;
	int result = toint(result_d);
	//cout << "result is: " << result;
	result = mod(result, 360);
	//cout << "result is: " << result << endl;
	return result;
}

long long missing_length(double xf ,double yf, int angle) {
	//first decide whether we need to go fw or bk
	//then calculate length
	double rad = arctan(yf,xf);
	if (0 - xf < 0) {
		rad += PI;
	}
	double degree = rad * (360/(2*PI));
	int angle2 = toint(degree);
	//cout << "angle is" << angle << endl;
	//cout << "angle2 is" << angle2 << endl;
	double len = length(xf,yf,0,0);
	long long l = toint(len);
	//cout << "l = " << l << endl;
	if (angle == angle2) {
		//cout << "l is returned" << endl;
		return l;
	}
	else if (abs(angle2 - angle) == 180) {
		//cout << "l is not returned" << endl;
		return 0 - l;
	}
}



void small_step(int num) {
	//input to a vector of commands and a vector of arguments
	//num, the number of commands
	vector<string> arguments;
	vector<string> commands;
	string tempstr;
	int index; // index of ?
	for (int i = 0; i < num; ++i) {
		cin >> tempstr;
		commands.push_back(tempstr);
		cin >> tempstr;
		arguments.push_back(tempstr);
		if (tempstr == "?") {
			index = i;
		}
	}
	for (int i = 0; i < index; ++i) {
		updater(commands[i], arguments[i]);
	}
	double xi = x_coord; double yi = y_coord;
	double anglei = direction;
	//cout << "direction now is: " << direction << endl;
	if (index < num - 1) {
		//cout << "The second loop is running" << endl;
		for (int i = index + 1; i < num; ++i) {
			updater(commands[i], arguments[i]);
		}
	}
	double xf = x_coord; double yf = y_coord;
	if (commands[index].compare("lt") == 0) {
		int result = missing_angle(xi,yi,xf,yf);
		answers.push_back(result);
	}
	if (commands[index].compare("rt") == 0) {
		int result = missing_angle(xi,yi,xf,yf);
		answers.push_back(360 - result);
	}
	if (commands[index].compare("fd") == 0) {
		long long result = missing_length(xf,yf,anglei);
		//cout << "result is" << result << endl;
		answers.push_back(result);
	}
	if (commands[index].compare("bk") == 0) {
		long long result = (-1)*missing_length(xf,yf,anglei);
		answers.push_back(result);
	}
}

void driver() {
	int num_test_cases;
	int n;
	cin >> num_test_cases;
	for (int i = 0; i < num_test_cases; ++i) {
		restore();
		cin >> n;
		small_step(n);
	}
	for (int i = 0; i < num_test_cases; ++i) {
		cout << answers[i] << " ";
	}
	cout << endl; 
}


int main() {
//cout << "mod(180,360) is" << mod(180,360) << endl;


	driver();
}
	
