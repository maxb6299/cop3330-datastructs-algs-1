// driver file for temperature.cpp

#include <iostream>

#include "temperature.h"

using namespace std;

int main()
{
	cout << "\ntest constructor START\n\n";
	
	Temperature t1;
	cout << "Should be\n0 C\n";
	t1.Show();
	cout << "___________\n\n";
	
	Temperature t2(23.5, 'f');
	cout << "Should be\n23.5 F\n";
	t2.Show();
	cout << "___________\n\n";

	Temperature t3(12.5, 'Z');
	cout << "Should be\n0 C\n";
	t3.Show();
	cout << "___________\n\n";
	
	Temperature t4(-300, 'C');
	cout << "Should be\n0 C\n" ;
	t4.Show();
	cout << "___________\n\n";
	
	Temperature t5(15, 'K');
	cout << "Should be\n15 K\n";
	t5.Show();
	cout << "___________\n\n";

	cout << "\ntest constructor END\n\n";	


	cout << "\n---------------------- \n";


	cout << "\ntest Input() START\n\n";
	

	cout << "Should be\n43.6 K\n";
	t1.Input();
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\n53.5 C\n";
	t1.Input();
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\n100 F\n";
	t1.Input();
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\n-273.15 C\n";
	t1.Input();
	t1.Show();
	cout << "___________\n\n";

	cout << "Please input '12.3 q , -5 K , -278 C , -500 F'\n" 
	<< "Should be\n'Invalid Temperature. Please Try again' \n";
	t1.Input();
	t1.Show();
	cout << "___________\n\n";

	cout << "\ntest Input() END\n\n";


	cout << "\n---------------------- \n";


	cout << "\ntest Set() START\n\n";

	cout << "Should be\nTRUE\n" << 
	"23.5 F\n";
	cout << t1.Set(23.5, 'F') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nFALSE\n" << 
	"23.5 F\n";
	cout << t1.Set(12.6, 'Z') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nFALSE\n" << 
	"23.5 F\n";
	cout << t1.Set(-300, 'c') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE\n" << 
	"15 K\n";
	cout << t1.Set(15, 'k') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE\n" << 
	"15 C\n";
	cout << t1.Set(15, 'c') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "\ntest Set() END\n\n";


	cout << "\n---------------------- \n";


	cout << "\ntest GetDegrees() & GetScale() START\n\n";

	cout << "Should be\n15 C\n";
	cout << t1.GetDegrees() << " " << t1.GetScale() << "\n";
	cout << "___________\n\n";


	cout << "Should be\n23.5 F\n";
	cout << t2.GetDegrees() << " " << t2.GetScale() << "\n";
	cout << "___________\n\n";


	cout << "Should be\n0 C\n";
	cout << t3.GetDegrees() << " " << t3.GetScale() << "\n";
	cout << "___________\n\n";

	cout << "\ntest GetDegrees() & GetScale() END\n\n";
	

	cout << "\n---------------------- \n";


	cout << "\ntest SetFormat() START\n\n";

	cout << "Should be\n" <<
	"**.**** C\n";
	t1.Show();
	t2.Show();
	t3.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE \n" <<
	"**.**** C\n";
	cout << t1.SetFormat('D') << "\n";
	t1.Show();
	cout << t2.SetFormat('d') << "\n";
	t2.Show();
	cout << t3.SetFormat('D') << "\n";
	t3.Show();
	cout << "___________\n\n";


	cout << "Should be\nFALSE \n" <<
	"**.**** C\n";
	cout << t1.SetFormat('g') << "\n";
	t1.Show();
	cout << t2.SetFormat('h') << "\n";
	t2.Show();
	cout << t3.SetFormat('a') << "\n";
	t3.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE \n" <<
	"**.* C\n";
	cout << t1.SetFormat('P') << "\n";
	t1.Show();
	cout << t2.SetFormat('p') << "\n";
	t2.Show();
	cout << t3.SetFormat('P') << "\n";
	t3.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE \n" <<
	"**.**** Celsius\n";
	cout << t1.SetFormat('L') << "\n";
	t1.Show();
	cout << t2.SetFormat('l') << "\n";
	t2.Show();
	cout << t3.SetFormat('L') << "\n";
	t3.Show();
	cout << "___________\n\n";

	cout << "\ntest SetFormat() END\n\n";


	cout << "\n---------------------- \n";


	cout << "\ntest Convert() START\n\n";

	t1.Set(68.9, 'f');
	t1.SetFormat('D');
	cout << "Temp is: " << "\n";
	t1.Show();
	cout << "___________\n\n";
	

	cout << "Should be\nFALSE\n" << 
	"68.9 F\n";
	cout << t1.Convert('T') << "\n";
	t1.Show();
	cout << "___________\n\n";	

	cout << "Should be\nTRUE\n" << 
	"20.5 C\n";
	cout << t1.Convert('c') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE\n" << 
	"293.65 K\n";
	cout << t1.Convert('K') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE\n" << 
	"68.9 F\n";
	cout << t1.Convert('F') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE\n" << 
	"293.65 K\n";
	cout << t1.Convert('k') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "Should be\nTRUE\n" << 
	"20.5 C\n";
	cout << t1.Convert('C') << "\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "\ntest Convert() END\n\n";


	cout << "\n---------------------- \n";


	cout << "\ntest Compare() START\n\n";

	t1.Set(0, 'c');
	t2.Set(31.5, 'F');
	cout << "Should be\n1\n";
	cout << t1.Compare(t2) << "\n\n";
	cout << "Should be\n-1\n";
	cout << t2.Compare(t1) << "\n";
	cout << "___________\n\n";
	
	t1.Set(0, 'c');
	t2.Set(0, 'C');
	cout << "Should be\n0\n";
	cout << t1.Compare(t2) << "\n\n";
	cout << "Should be\n0\n";
	cout << t2.Compare(t1) << "\n";
	cout << "___________\n\n";

	t1.Set(12, 'k');
	t2.Set(0, 'C');
	cout << "Should be\n-1\n";
	cout << t1.Compare(t2) << "\n\n";
	cout << "Should be\n1\n";
	cout << t2.Compare(t1) << "\n";
	cout << "___________\n\n";

	cout << "\ntest Compare() END\n\n";


	cout << "\n---------------------- \n";


	cout << "\ntest Increment() START\n\n";

	t1.Set(20.5, 'c');
	
	t1.Increment(3, 'C');
	cout << "Should be\n23.5 C\n";
	t1.Show();
	cout << "___________\n\n";

	t1.Increment(6, 'F');
	cout << "Should be\n26.833 C\n";
	t1.Show();
	cout << "___________\n\n";

	cout << "\ntest Increment() END\n\n";


	cout << "\n---------------------- \n";
}

