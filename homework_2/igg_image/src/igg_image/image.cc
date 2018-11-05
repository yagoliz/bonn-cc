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
    double interval = 255.0/(double) bins;
    for (int i = 0; i < bins; i++) {
        histograms.emplace_back(std::count_if(data_.begin(), data_.end(), 
            [i, interval](int j){return (j < ((double) i + 1.0) * interval && j >= (double) i * interval);}));
    }

    // Normalize
    float data_size = data_.size();
    for (float &value: histograms){
        value = value / data_size;
    }

    return histograms;
}

void Image::DownScale(int scale) {
    // Create the downscaled image
    int downscaled_rows = rows_/scale;
    int downscaled_cols = cols_/scale;
    std::vector<int> downscaled_image;
    downscaled_image.reserve(downscaled_rows * downscaled_cols);
    

    // Iterate over image
    for (int i = 0; i < rows_; i+=scale) {
        for (int j = 0; j < cols_; j+=scale) {
            downscaled_image.emplace_back(data_[i * cols_ + j]);
        }
    }

    rows_ = downscaled_rows;
    cols_ = downscaled_cols;
    data_ = downscaled_image;
}

void Image::UpScale(int scale) {
    // Create the upscaled image
    int upscaled_rows = rows_*scale;
    int upscaled_cols = cols_*scale;
    std::vector<int> upscaled_image(upscaled_rows * upscaled_cols + 1, 0);

    // Iterate over the image
    for (int i = 0; i < rows_; i++) {
        int row_jump = i * scale;
        for (int j = 0; j < cols_; j++) {
            int col_jump = j*scale;
            // Fill values for upscaled image
            for (int u = 0; u < scale; u++) {
                for (int v = 0; v < scale; v++) {
                    upscaled_image[(row_jump+u)*upscaled_cols + col_jump + v] = data_[i * cols_ + j];
                }
            }
        }
    }

    rows_ = upscaled_rows;
    cols_ = upscaled_cols;
    data_ = upscaled_image;
}
} // namespace igg


