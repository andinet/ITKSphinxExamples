/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkAntiAliasBinaryImageFilter.h"

int
main(int argc, char * argv[])
{
  if (argc < 3)
  {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " <inputImage> <outputImage>";
    std::cerr << " [maximumRMSError]";
    std::cerr << " [numberOfIterations]";
    std::cerr << " [numberOfLayers]" << std::endl;
    return EXIT_FAILURE;
  }

  const char * inputFileName = argv[1];
  const char * outputFileName = argv[2];
  double       maximumRMSError = 0.001;
  if (argc > 3)
  {
    maximumRMSError = std::stod(argv[3]);
  }
  int numberOfIterations = 50;
  if (argc > 4)
  {
    numberOfIterations = std::stoi(argv[4]);
  }
  int numberOfLayers = 2;
  if (argc > 5)
  {
    numberOfLayers = std::stoi(argv[5]);
  }

  constexpr unsigned int Dimension = 2;
  using PixelType = float;
  using ImageType = itk::Image<PixelType, Dimension>;

  const auto input = itk::ReadImage<ImageType>(inputFileName);

  using FilterType = itk::AntiAliasBinaryImageFilter<ImageType, ImageType>;
  FilterType::Pointer filter = FilterType::New();
  filter->SetInput(input);
  filter->SetMaximumRMSError(maximumRMSError);
  filter->SetNumberOfIterations(numberOfIterations);
  filter->SetNumberOfLayers(numberOfLayers);

  try
  {
    itk::WriteImage(filter->GetOutput(), outputFileName);
  }
  catch (const itk::ExceptionObject & error)
  {
    std::cerr << "Error: " << error << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
