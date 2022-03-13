#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include <fstream>


using namespace std;



/* Define a function pointer for our imported
 * function.
 * This reads as "introduce the new type f_funci as the type:
 *                pointer to a function returning an int and
 *                taking no arguments.
 *
 * Make sure to use matching calling convention (__cdecl, __stdcall, ...)
 * with the exported function. __stdcall is the convention used by the WinAPI
 */

typedef int(__stdcall* f_funci)();




int main() {

	ifstream ifile;
	ifile.open("C://Users/pxj59//Desktop//PopExportMessage.dll");
	if (ifile) {
	
		HINSTANCE hGetProcIDDLL = LoadLibrary(L"C:\\Users\\pxj59\\Desktop\\PopExportMessage.dll");
		if (!hGetProcIDDLL) {
			std::cout << "could not load the dynamic library" << std::endl;
			return EXIT_FAILURE;
		}

		f_funci funci = (f_funci)GetProcAddress(hGetProcIDDLL, "doSomething");
		if (!funci) {
			std::cout << "could not locate the function" << std::endl;
			cout << "got here";
			return EXIT_FAILURE;
		}

		std::cout << "funci() returned " << funci() << std::endl;

		return 0;
	}
	else {
		cout << "file doesn't exist";
		return 0;
	}
	
}