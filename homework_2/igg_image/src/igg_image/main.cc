#include <iostream>
#include <string>
#include "image.h"
#include "io_tools.h"

int main() {
    // File name to figure
    std::string file_name = "/home/yago/Documents/Lectures/Bonn-Modern-C++/Homework/homework_2/igg_image/data/lena.ascii.pgm"; 

    // Create Image class
    igg::Image image;

    // Load image
    if (!(image.FillFromPgm(file_name))) { 
        return 1;
    }

    // Write to another image
    std::string output = "/home/yago/Documents/Lectures/Bonn-Modern-C++/Homework/homework_2/igg_image/data/lena.ascii-2.pgm";
    image.WriteToPgm(output);

    // Compute 4 histograms
    int bins = 4;
    std::vector<float> histograms = image.ComputeHistogram(bins);
    for (auto v: histograms) {
        std::cout << v;
    }

    std::cout << std::endl;

    // Return successfully
    return 0;
}