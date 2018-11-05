#include <iostream>
#include <string>
#include "image.h"
#include "io_tools.h"

int main() {
    // File name to figure
    std::string file_name = "/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii.pgm"; 

    // Create Image class
    igg::Image image;

    // Load image
    if (!(image.FillFromPgm(file_name))) { 
        return 1;
    }

    // Write to another image
    std::string output = "/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii-2.pgm";

    // Invert the values
    for (int i = 0, rows = image.rows(); i < rows; i++) {
        for (int j = 0, cols = image.cols(); j < cols; j++) {
            image.at(i, j) = 250 - image.at(i, j);
        }
    }

    image.WriteToPgm(output);

    // Compute 4 histograms
    int bins = 4;
    std::vector<float> histograms = image.ComputeHistogram(bins);

    // // Downscaled image
    std::string downscaled = "/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii-3.pgm";

    image.DownScale(2);
    image.WriteToPgm(downscaled);

        // Downscaled image
    std::string upscaled = "/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii-4.pgm";

    image.UpScale(2);
    image.WriteToPgm(upscaled);

    // Return successfully
    return 0;
}