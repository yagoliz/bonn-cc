#include "image.h"
#include "io_tools.h"

namespace igg {

// Getter function
const int& Image::at(int row, int col) const {
    return data_[row * cols_ + col];
}

// Setter function
int& Image::at(int row, int col) {
    return data_[row * cols_ + col];
}

// Fill the Image class with PGM file
bool Image::FillFromPgm(const std::string& file_name) {
    // Read the data using the io_tools library
    io_tools::ImageData image = io_tools::ReadFromPgm(file_name);

    // Check whether the file was opened
    if (image.data.empty()) {
        return false;
    }

    // Transfer data to Image object
    rows_ = image.rows;
    cols_ = image.cols;
    max_val_ = image.max_val;
    data_.assign(image.data.begin(), image.data.end());

    return true;
}

// Write data to pgm file
void Image::WriteToPgm(const std::string& file_name) {
    // Create an image object
    io_tools::ImageData image{
        rows_, 
        cols_,
        max_val_,
        data_};

    // Write image to file using the tools library
    if (io_tools::WriteToPgm(image, file_name)) {
        std::cout << "Data written successfully to: " << file_name
            << std::endl;
    }
    else {
        std::cout << "There was an error when writing to file."
            << std::endl;
    }   
}

std::vector<float> Image::ComputeHistogram(int bins) {
    // Create vector and reserve space
    std::vector<float> histograms;
    histograms.reserve(bins);

    // Iterate through bins
    for (int i = 0; i < bins; i++) {
        histograms.emplace_back(std::count_if(data_.begin(), data_.end(), 
            [i, bins](int j){return (j < (((i+1.0)/(double) bins)*255.0 + 1.0) && j >= (double) i*255.0/(double) bins);}));
    }

    // Normalize
    float data_size = data_.size();
    for (float &value: histograms){
        value = value / data_size;
    }

    return histograms;
}
} // namespace igg


