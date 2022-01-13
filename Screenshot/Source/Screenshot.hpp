#ifndef SCREENSHOT_HPP
#define SCREENSHOT_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <array>
#include <vector>
#include <stdexcept>
#include <Windows.h>
#include <fstream>

#include <memory>
#include <cstdio>

namespace Screenshot
{
	const void TakeScreenshot(int x, int y, int width, int height, std::string savePath, bool dateTimeName = true);
	const void UploadScreenshot();
};

#endif
