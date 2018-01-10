#if defined(_WIN32)
#include <Windows.h>
#endif
#include <iostream>


namespace sign{

	inline
    std::ostream& question(std::ostream& stream)
    {
		#if defined(_WIN32)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		#endif

		stream  << "[?] ";

		#if defined(_WIN32)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		#endif

		return stream;
    }

	inline
	std::ostream& error(std::ostream& stream)
	{
		#if defined(_WIN32)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		#endif

		stream << "[!] ";

		#if defined(_WIN32)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		#endif
		return stream;
	}

	inline
	std::ostream& success(std::ostream& stream)
	{
		#if defined(_WIN32)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		#endif

		stream << "[*] ";

		#if defined(_WIN32)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		#endif

		return stream;
	}
}
