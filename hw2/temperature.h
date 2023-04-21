// header file for temprature.cpp


class Temperature
{
private:
	double temp;
	char scale;
	char format;

	double ConvertToK(double deg, char sc);
	
public:
	// constructor
	// must be a valid temp (above absolute 0) 
	// and a valid scale (K, k, C, c, F, f)
	Temperature(double tempC = 0, char scaleC = 'C');

	// prompts user for temp
	void Input();

	// outputs temperature to the screen
	void Show();

	// sets temperature. Returns false if temperature is intvalid
	bool Set(double deg, char s);

	// getters
	double GetDegrees();
	char GetScale();

	// sets format ('f'). Returns false if invalid input
	//'D' = Default, 'P' = Precision-1, 'L' = Long	
	bool SetFormat (char f);
	
	// converts temp to new scale ('sc'). Returns false if invalid input
	bool Convert (char sc);

	// compares two Temperature objects
	// returns -1 if calling obj is lower 
	// returns 0 if objects represent same temp
	// returns 1 if paramater object has lower temp
	int Compare(const Temperature& d);

	// increments temperature by the specified degrees in the 'sc' scale
	// note: the scale of the object is unchanged
	void Increment(int deg, char sc);	
};
