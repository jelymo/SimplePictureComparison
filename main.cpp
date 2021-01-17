#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <string>
#include <thread>
#include "stb_image.h"

int main(int argv, char* argc[])
{
	if (argv < 2)
	{
		return 0;
	}

	if (argv >= 2 && std::string(argc[1]).compare("/help") == 0)
	{
		std::cout << "First param is 1st Image location relative to the executable." << std::endl;
		std::cout << "Second param is 2nd Image location relative to the executable." << std::endl;
		return 0;
	}

	int image1height = 0;
	int image1weight = 0;
	int image1channel = 0;

	unsigned char* image1data = stbi_load(argc[1],&image1height, &image1weight, &image1channel,0);
	int image1size = image1height * image1weight * image1channel;

	if (image1data == nullptr)
	{
		std::cout << "Error loading Image 1." << std::endl;
		return 0;
	}

	int image2height = 0;
	int image2weight = 0;
	int image2channel = 0;

	unsigned char* image2data = stbi_load(argc[2], &image2height, &image2weight, &image2channel, 0);
	int image2size = image2height * image2weight * image2channel;
	
	if (image2data == nullptr)
	{
		std::cout << "Error loading Image 2." << std::endl;
		return 0;
	}

	if (image1size != image2size)
	{
		std::cout << "The two images has different sizes." << std::endl;
		return 0;
	}

	for (unsigned char  *image1pixel = image1data, *image2pixel = image2data; 
		image1pixel != image1data+image1size; 
		image1pixel+=image1channel, image2pixel+=image1channel)
	{
		for (int channel = 0; channel < image1channel; channel++)
		{
			if (*(image1pixel + channel) != *(image2pixel + channel))
			{
				std::cout << "They two image are not equal." << std::endl;
				return 0;
			}
		}
	}

	std::cout << "They two image are equal." << std::endl;
	return 0;
}


//threading
//unsigned char* reduceResolution()