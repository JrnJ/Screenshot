#include "Screenshot.hpp"

#include <CString>
#include <atlstr.h>
#include <atlimage.h>

//private:

const int GetFilePointer(HANDLE FileHandle)
{
	return SetFilePointer(FileHandle, 0, 0, FILE_CURRENT);
}

const std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

const std::string getDateTimeString()
{
	auto tp = std::chrono::system_clock::now();
	auto dp = floor<std::chrono::days>(tp);
	std::chrono::year_month_day ymd{ dp };
	std::chrono::hh_mm_ss time{ floor<std::chrono::milliseconds>(tp - dp) };

	// check if this file already exists, if so add .01, or .02 etc
	return std::to_string(static_cast<int>(ymd.year())) + "-" +
		std::to_string(static_cast<unsigned>(ymd.month())) + "-" +
		std::to_string(static_cast<unsigned>(ymd.day())) + " - " +
		std::to_string((time.hours().count() + 1)) + "-" +
		std::to_string((time.minutes().count() + 1)) + "-" +
		std::to_string((time.seconds().count() + 1));
}

const std::string exec(const char* cmd)
{
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);

	if (!pipe)
	{
		throw std::runtime_error("popen() failed!");
	}

	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	{
		result += buffer.data();
	}
	return result;
}

const bool BMPtoPNG(HBITMAP bmp, std::string savePath)
{
	CImage image;
	image.Attach(bmp);
	image.Save(s2ws(savePath).c_str());

	return true;
}

//public:

const void Screenshot::TakeScreenshot(int x, int y, int width, int height, std::string savePath, bool dateTimeName)
{
	// get a DC compat. w/ the screen
	HDC hDc = CreateCompatibleDC(0);

	// make a bmp in memory to store the capture in
	HBITMAP hBmp = CreateCompatibleBitmap(GetDC(0), width, height);

	// join em up
	SelectObject(hDc, hBmp);

	// copy from the screen to my bitmap
	BitBlt(hDc, 0, 0, width, height, GetDC(0), x, y, SRCCOPY);

	// Create a name
	if (dateTimeName)
	{
		savePath += getDateTimeString() + ".png";
	}

	BMPtoPNG(hBmp, savePath);

	// free the bitmap memory
	DeleteObject(hBmp);
}

const void Screenshot::UploadScreenshot()
{
	/*std::string cmdAddFile = "git -C C:/Dev/Website/jeroenj.com/images/ add " + dateTimeNow;
	std::cout << cmdAddFile << std::endl;
	exec(cmdAddFile.c_str());
	Sleep(500);

	exec("git -C C:/Dev/Website/jeroenj.com/images/ commit -m Added");
	Sleep(500);

	exec("git -C C:/Dev/Website/jeroenj.com/images/ push");
	Sleep(5000);

	std::string url = "https://jeroenj.com/images/" + dateTimeNow;
	ShellExecute(0, 0, s2ws(url).c_str(), 0, 0, SW_SHOW);*/
}
