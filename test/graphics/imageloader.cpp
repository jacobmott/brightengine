#include <iostream>
#include "graphics/imageloader.hpp"
#include "utils/fileworker.hpp"
#include <memory>
#include <algorithm>
#include <sstream>

int main(){

  auto pImageLoader = std::make_shared<bright::graphics::ImageLoader>();

  //If you're running this from the debuger/visual studio, then you need to specify the path to the 
  //meshes/obj directory starting from the "bright" directory, for example:
  //test/tools/meshes/obj
  //But if you're building this and creating the executable, which goes into the bin directory
  //in test/tools/bin then you need to specify the path as "../meshes/obj".
  //auto pGliTexture2D = pImageLoader->load_single_dds_image("../data", "default_material.dds");
  //auto pGliTexture2D = pImageLoader->load_single_dds_image("test/graphics/data", "default_material.dds");
  auto pFileWorker = std::make_shared<bright::utils::FileWorker>("test/graphics/data/files.fl");
  pFileWorker->read_in_list_of_files();
  pFileWorker->create_lookup_map_of_files_content();

  std::string fileContents = pFileWorker->get_file_contents("dirt.dds");
  std::stringstream stream(fileContents);

  auto pGliTexture2D = pImageLoader->load_single_dds_image( stream );

  std::cout << "DDS GliTexture2D: " << std::endl << std::flush;
  std::cout << "max level: " << pGliTexture2D->maxLevel() << std::endl << std::flush;
  std::cout << "x Dimension: " << pGliTexture2D->dimensions().x << std::endl << std::flush;
  std::cout << "y Dimension: " << pGliTexture2D->dimensions().y << std::endl << std::flush;
  std::cout << std::endl << std::flush;
  
  std::cout << "ctr+c to exit or x on the window" << std::endl;
  while (true){ }

  return 0;
}