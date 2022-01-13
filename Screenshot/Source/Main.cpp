#include <iostream>
#include <string>

#include <Windows.h>
//#include <vector>
////#include <CString>
////#include <atlstr.h>
////#include <atlimage.h>
//#include <chrono>
//#include <array>
//#include <stdexcept>
//
//#include <thread>
//
//#include <fstream>
//

//
//// Can be removed no !build error!
//#include <memory>
//#include <cstdio>

#include "Screenshot.hpp"

std::string saveLocation = "C:/Dev/Website/jeroenj.com/images/";
//std::string dateTimeNow = "";
//
//// Take a screenshot
////void MakeScreenshot(POINT pos1, POINT pos2, std::string path)
////{
////	std::cout << "Taking Screenshot..." << std::endl;
////
////	auto tp = std::chrono::system_clock::now();
////	auto dp = floor<std::chrono::days>(tp);
////	std::chrono::year_month_day ymd{ dp };
////	std::chrono::hh_mm_ss time{ floor<std::chrono::milliseconds>(tp - dp) };
////	
////	// check if this file already exists, if so add .01, or .02 etc
////	path += std::to_string(static_cast<int>(ymd.year())) + "-" +
////	std::to_string(static_cast<unsigned>(ymd.month())) + "-" +
////	std::to_string(static_cast<unsigned>(ymd.day())) + " " +
////	std::to_string((time.hours().count() + 1)) + "." +
////	std::to_string((time.minutes().count() + 1)) + "." +
////	std::to_string((time.seconds().count() + 1)) + ".png";
////
////	std::cout << path << std::endl;
////
////	//setting to the screen shot
////	keybd_event(VK_SNAPSHOT, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
////	keybd_event(VK_SNAPSHOT, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
////
////	//handler of the bitmap that save the screen shot
////	HBITMAP hBitmap;
////
////	// Allow time ig
////	Sleep(100);
////
////	// Take Screenshot
////	OpenClipboard(NULL);
////
////	// Save the screen shot in the bitmap handler 
////	hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);
////
////	// Relese the screen shot
////	CloseClipboard();
////
////	std::vector<BYTE> buf;
////	IStream* stream = NULL;
////	HRESULT hr = CreateStreamOnHGlobal(0, TRUE, &stream);
////	CImage image;
////	ULARGE_INTEGER liSize;
////
////	// Screenshot to jpg and save to stream
////	image.Attach(hBitmap);
////	image.Save(stream, Gdiplus::ImageFormatJPEG);
////	IStream_Size(stream, &liSize);
////	DWORD len = liSize.LowPart;
////	IStream_Reset(stream);
////	buf.resize(len);
////	IStream_Read(stream, &buf[0], len);
////	stream->Release();
////
////	// Put the image in the file
////	std::fstream fi;
////	fi.open(path, std::fstream::binary | std::fstream::out);
////	fi.write(reinterpret_cast<const char*>(&buf[0]), buf.size() * sizeof(BYTE));
////	fi.close();
////
////	std::cout << "Screenshould Taken!" << std::endl;
////}
//
//// Helper Methods
//int GetFilePointer(HANDLE FileHandle) 
//{
//	return SetFilePointer(FileHandle, 0, 0, FILE_CURRENT);
//}
//
//
//std::string DateTimeNow()
//{
//	auto tp = std::chrono::system_clock::now();
//	auto dp = floor<std::chrono::days>(tp);
//	std::chrono::year_month_day ymd{ dp };
//	std::chrono::hh_mm_ss time{ floor<std::chrono::milliseconds>(tp - dp) };
//
//	// check if this file already exists, if so add .01, or .02 etc
//	return std::to_string(static_cast<int>(ymd.year())) + "-" +
//		std::to_string(static_cast<unsigned>(ymd.month())) + "-" +
//		std::to_string(static_cast<unsigned>(ymd.day())) + "-" +
//		std::to_string((time.hours().count() + 1)) + "." +
//		std::to_string((time.minutes().count() + 1)) + "." +
//		std::to_string((time.seconds().count() + 1)) + ".png";
//}
//
//std::wstring s2ws(const std::string& s)
//{
//	int len;
//	int slength = (int)s.length() + 1;
//	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
//	wchar_t* buf = new wchar_t[len];
//	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
//	std::wstring r(buf);
//	delete[] buf;
//	return r;
//}
//
//std::string exec(const char* cmd) 
//{
//	std::array<char, 128> buffer;
//	std::string result;
//	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
//
//	if (!pipe) 
//	{
//		throw std::runtime_error("popen() failed!");
//	}
//
//	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) 
//	{
//		result += buffer.data();
//	}
//	return result;
//}
//
//bool SaveBMPFile(HBITMAP bitmap, HDC bitmapDC, int width, int height, std::string folderPath) 
//{
//	bool Success = false;
//	HDC SurfDC = NULL;        // GDI-compatible device context for the surface
//	HBITMAP OffscrBmp = NULL; // bitmap that is converted to a DIB
//	HDC OffscrDC = NULL;      // offscreen DC that we can select OffscrBmp into
//	LPBITMAPINFO lpbi = NULL; // bitmap format info; used by GetDIBits
//	LPVOID lpvBits = NULL;    // pointer to bitmap bits array
//	HANDLE BmpFile = INVALID_HANDLE_VALUE;    // destination .bmp file
//	BITMAPFILEHEADER bmfh;  // .bmp file header
//
//	// We need an HBITMAP to convert it to a DIB:
//	if ((OffscrBmp = CreateCompatibleBitmap(bitmapDC, width, height)) == NULL)
//		return false;
//
//	// The bitmap is empty, so let's copy the contents of the surface to it.
//	// For that we need to select it into a device context. We create one.
//	if ((OffscrDC = CreateCompatibleDC(bitmapDC)) == NULL)
//		return false;
//
//	// Select OffscrBmp into OffscrDC:
//	HBITMAP OldBmp = (HBITMAP)SelectObject(OffscrDC, OffscrBmp);
//
//	// Now we can copy the contents of the surface to the offscreen bitmap:
//	BitBlt(OffscrDC, 0, 0, width, height, bitmapDC, 0, 0, SRCCOPY);
//
//	// GetDIBits requires format info about the bitmap. We can have GetDIBits
//	// fill a structure with that info if we pass a NULL pointer for lpvBits:
//	// Reserve memory for bitmap info (BITMAPINFOHEADER + largest possible
//	// palette):
//	if ((lpbi = (LPBITMAPINFO)(new char[sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)])) == NULL)
//		return false;
//
//
//	ZeroMemory(&lpbi->bmiHeader, sizeof(BITMAPINFOHEADER));
//	lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
//	// Get info but first de-select OffscrBmp because GetDIBits requires it:
//	SelectObject(OffscrDC, OldBmp);
//	if (!GetDIBits(OffscrDC, OffscrBmp, 0, height, NULL, lpbi, DIB_RGB_COLORS))
//		return false;
//
//	// Reserve memory for bitmap bits:
//	if ((lpvBits = new char[lpbi->bmiHeader.biSizeImage]) == NULL)
//		return false;
//
//	// Have GetDIBits convert OffscrBmp to a DIB (device-independent bitmap):
//	if (!GetDIBits(OffscrDC, OffscrBmp, 0, height, lpvBits, lpbi, DIB_RGB_COLORS))
//		return false;
//
//	// Create a file to save the DIB to:
//	if ((BmpFile = CreateFile(s2ws(folderPath).c_str(),
//		GENERIC_WRITE,
//		0, NULL,
//		CREATE_ALWAYS,
//		FILE_ATTRIBUTE_NORMAL,
//		NULL)) == INVALID_HANDLE_VALUE)
//
//		return false;
//
//	DWORD Written;    // number of bytes written by WriteFile
//
//	// Write a file header to the file:
//	bmfh.bfType = 19778;        // 'BM'
//	// bmfh.bfSize = ???        // we'll write that later
//	bmfh.bfReserved1 = bmfh.bfReserved2 = 0;
//	// bmfh.bfOffBits = ???     // we'll write that later
//	if (!WriteFile(BmpFile, &bmfh, sizeof(bmfh), &Written, NULL))
//		return false;
//
//	if (Written < sizeof(bmfh))
//		return false;
//
//	// Write BITMAPINFOHEADER to the file:
//	if (!WriteFile(BmpFile, &lpbi->bmiHeader, sizeof(BITMAPINFOHEADER), &Written, NULL))
//		return false;
//
//	if (Written < sizeof(BITMAPINFOHEADER))
//		return false;
//
//	// Calculate size of palette:
//	int PalEntries;
//	// 16-bit or 32-bit bitmaps require bit masks:
//	if (lpbi->bmiHeader.biCompression == BI_BITFIELDS)
//		PalEntries = 3;
//	else
//		// bitmap is palettized?
//		PalEntries = (lpbi->bmiHeader.biBitCount <= 8) ?
//		// 2^biBitCount palette entries max.:
//		(int)(1 << lpbi->bmiHeader.biBitCount)
//		// bitmap is TrueColor -> no palette:
//		: 0;
//	// If biClrUsed use only biClrUsed palette entries:
//	if (lpbi->bmiHeader.biClrUsed)
//		PalEntries = lpbi->bmiHeader.biClrUsed;
//
//	// Write palette to the file:
//	if (PalEntries) {
//		if (!WriteFile(BmpFile, &lpbi->bmiColors, PalEntries * sizeof(RGBQUAD), &Written, NULL))
//			return false;
//
//		if (Written < PalEntries * sizeof(RGBQUAD))
//			return false;
//	}
//
//	// The current position in the file (at the beginning of the bitmap bits)
//	// will be saved to the BITMAPFILEHEADER:
//	bmfh.bfOffBits = GetFilePointer(BmpFile);
//
//	// Write bitmap bits to the file:
//	if (!WriteFile(BmpFile, lpvBits, lpbi->bmiHeader.biSizeImage, &Written, NULL))
//		return false;
//
//	if (Written < lpbi->bmiHeader.biSizeImage)
//		return false;
//
//	// The current pos. in the file is the final file size and will be saved:
//	bmfh.bfSize = GetFilePointer(BmpFile);
//
//	// We have all the info for the file header. Save the updated version:
//	SetFilePointer(BmpFile, 0, 0, FILE_BEGIN);
//	if (!WriteFile(BmpFile, &bmfh, sizeof(bmfh), &Written, NULL))
//		return false;
//
//	if (Written < sizeof(bmfh))
//		return false;
//
//	CloseHandle(BmpFile);
//	return true;
//}
//
//void ScreenCapture(int x, int y, int width, int height, std::string folderPath) 
//{
//	// get a DC compat. w/ the screen
//	HDC hDc = CreateCompatibleDC(0);
//
//	// make a bmp in memory to store the capture in
//	HBITMAP hBmp = CreateCompatibleBitmap(GetDC(0), width, height);
//
//	// join em up
//	SelectObject(hDc, hBmp);
//
//	// copy from the screen to my bitmap
//	BitBlt(hDc, 0, 0, width, height, GetDC(0), x, y, SRCCOPY);
//
//	// save my bitmap
//	if (!SaveBMPFile(hBmp, hDc, width, height, folderPath))
//	{
//		std::cout << "Could not save image!" << std::endl;
//	}
//
//	// free the bitmap memory
//	DeleteObject(hBmp);
//}

// Get mouse position
POINT GetMousePosition()
{
	POINT p;
	if (GetCursorPos(&p))
	{
		return p;
	}
	else
	{
		exit(1);
	}
}

HINSTANCE hinst;

int main()
{	
	bool keyDown = false;

	POINT pos1{
		0, 0
	};
	POINT pos2{
		0, 0
	};

	int currentPOINT = 0;

	while (true)
	{
		if ((GetKeyState(VK_NUMPAD7) & 0x8000) != 0)
		{
			if (!keyDown)
			{
				POINT p = GetMousePosition();
				std::cout << "X: " << p.x << " Y: " << p.y << std::endl;

				keyDown = true;

				switch (currentPOINT)
				{
					case 0:
						pos1 = GetMousePosition();

						// Up point by 1
						currentPOINT = 1;
						break;
					case 1:
						pos2 = GetMousePosition();

						POINT topLeft {
							min(pos1.x, pos2.x),
							min(pos1.y, pos2.y)
						};

						POINT bottomRight{
							max(pos1.x, pos2.x),
							max(pos1.y, pos2.y)
						};

						int width = bottomRight.x - topLeft.x;
						int height = bottomRight.y - topLeft.y;

						Screenshot::TakeScreenshot(topLeft.x, topLeft.y, width, height, saveLocation);

						return 0;
						break;
				}
			}
		}
		else
		{
			keyDown = false;
		}

		// Take Fullscreen Image
		if ((GetKeyState(VK_NUMPAD8) & 0x8000) != 0)
		{
			Screenshot::TakeScreenshot(0, 0, 1920, 1080, saveLocation);

			std::cout << "Fullscreen Screenshot taken!" << std::endl;

			return 0;
		}
	}
	
	return 0;
}