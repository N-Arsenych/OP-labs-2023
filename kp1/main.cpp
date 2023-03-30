#include "sm.h"
#include "pr.h"

int main(int argc, char* argv[])
{
		string fname = "input.txt";
		string fnew = "output.txt";  
		const char* pfname = "input.txt";  
		const char* pfnew = "output.txt";
		
		char plus;
		int mode;

		string mode_flag(argv[1]);
		string mode_(argv[2]);
		if (mode_flag != "-mode"){												
			cout << "ERROR. Wrong mode" << endl;
			return 0;
		}
		if (mode_ == "FilePointer") {											
			mode = 0;
		}
		else if (mode_ == "FileStream") {
			mode = 1;
		}
		else
		{
			cout << "ERROR. Wrong mode" << endl;
			return 0;
		}

		switch (mode)
		{
		case 0: 
		{	cout << "FilePointer is activated..." << endl;
			do
			{
				switch_pointer(choose(), pfname, pfnew);
				cout << "If you want to continue enter + " << endl;
				cin >> plus;
			} while (plus == '+');
		}
			break;
		case 1:
		{	cout << "FileStream is activated..." << endl;
			do
			{	
				switch_stream(choose(), fname, fnew);
				cout << "If you want to continue enter + " << endl;
				cin >> plus;
			}while (plus == '+');
		}
			break;
		default:
			break;
		}

	return 0;
}


