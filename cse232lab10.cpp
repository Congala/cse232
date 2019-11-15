
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#include <iomanip>

int main() {

  std::ifstream ifs("input_data.txt");
  std::vector<double> data;

  while (!ifs.eof()) {
    double d{};
    if (ifs >> d)
      data.push_back(d);
    else {
      ifs.clear();
      ifs.ignore();
    }
  }

  std::cout << std::fixed << std::setprecision(2); 
  
  std::cout << "data = ";
  for (double d : data)
    std::cout << d << ", ";

  auto [min, max] = std::minmax_element(std::begin(data), std::end(data));
  std::cout << "\nmin = " << *min << "\nmax = " << *max;

  auto mean =
      std::accumulate(std::begin(data), std::end(data), 0.) / data.size();
  std::cout << "\nmean = " << mean;

  auto mid_point = data.size() / 2;
  std::nth_element(std::begin(data), std::begin(data) + mid_point,
                   std::end(data));
  auto median = data[mid_point];
  if (data.size() % 2 == 0)
    median = (median + *std::max_element(std::begin(data), 
                                          std::begin(data) + mid_point)) /
             2;
  std::cout << "\nmedian = " << median << "\n";
}

std::cout << "hello" << endl;
