module;

#include <windows.h>
#include <filesystem>
#include <string_view>

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <regex>

export module lLog;



namespace lLogs {


	void fileWrite();

	std::ofstream myTechicalTxtLogFile;

	export void fileWriteWinAPi(std::string_view str) {

		if (myTechicalTxtLogFile.is_open()) {

			long f = myTechicalTxtLogFile.tellp();
			myTechicalTxtLogFile.seekp(f + 50);
			//myTechicalTxtLogFile.seekg(0, myTechicalTxtLogFile.end);


			std::time_t result = std::time(nullptr);
			std::string techLog{ std::asctime(std::localtime(&result)) };

			techLog = std::regex_replace(techLog, std::regex("\\r\\n|\\r|\\n"), "");

			techLog.append(str);
			std::cout << " my string = " << techLog << " \n";
			myTechicalTxtLogFile << techLog;



		}
		else {

			fileWrite();
			//myTechicalTxtLogFile.
		}





	}

	void fileWrite() {

		//std::cout << " my path = " << std::filesystem::current_path() << " \n";		
		auto p1 = std::filesystem::current_path() / "TechicalLogs.txt";
		//if (std::filesystem::exists(p1)) 
		myTechicalTxtLogFile.open(p1);
	}

	export void closeLogsWrite() {
		myTechicalTxtLogFile.close();
	}


	export void currentWorkLogWrite() {

	}

	export void logPrintWindows() {

		fileWrite();
		OutputDebugStringW(L"Print error or not \n");



	}


	export void logPrintWindowsClear(const char* messagesToPrint, int n = 0) {

		//LPCWSTR
		//change LPCWSTR to char2 

		//OutputDebugStringW((LPCWSTR)messagesToPrint);

		WCHAR EmptyMess[70] = L"Simple message to empty \n";
		std::string newSteing = messagesToPrint;
		std::wstring kjj(newSteing.size(), 0);
		MultiByteToWideChar(CP_UTF8, 0, &newSteing[0], (int)newSteing.size(), &kjj[0], newSteing.size());



		//  n : 0 ?   , 

		if (n == 0) {
			wsprintfW(EmptyMess, L"Debug Message: %s \n", kjj.c_str()); //
		}
		else {
			wsprintfW(EmptyMess, L"Debug Message: %s %d \n", kjj.c_str(), n); //
		}

		OutputDebugStringW(EmptyMess);

	}

	export void logPrintWindowsClearFloat(const char* messagesToPrint, float n) {

		WCHAR EmptyMess[70] = L"Simple message to empty \n";
		std::string newSteing = messagesToPrint;
		std::wstring kjj(newSteing.size(), 0);
		MultiByteToWideChar(CP_UTF8, 0, &newSteing[0], (int)newSteing.size(), &kjj[0], newSteing.size());
		wsprintfW(EmptyMess, L"Debug Message1: %s \n", kjj.c_str()); //


		OutputDebugStringW(EmptyMess);


	}


	export void logPrintWindowsInt(std::string_view errorName, int number) {

		//_setmode(_fileno(stdout), _O_U16TEXT);

		wchar_t* msgBuf = new wchar_t[256];
		swprintf(msgBuf, 100, L"%s %d\n", errorName, number);  // sprintf_s

		//char text[] = "something";
		//wchar_t wtext[256];
		//mbstowcs(wtext, msgBuf, strlen(msgBuf) + 1);

		OutputDebugString(msgBuf);  // LPCWSTR
		//delete msgBuf;
	}



}