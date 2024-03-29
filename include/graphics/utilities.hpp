#ifndef BRIGHT_GRAPHICS_UTILITIES_H
#define BRIGHT_GRAPHICS_UTILITIES_H

#include <map>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <memory>
#include "graphics/globalstructs.hpp"
#include "base/globalstructs.hpp"

#include <vector>

namespace bright{

  namespace graphics{

  bright::graphics::ActorGroupRenderInfo create_cube();
  bright::graphics::ActorGroupRenderInfo create_plane(float size);

  void generate_cube_coords(std::shared_ptr<bright::base::ActorData> pCubeData);
  void generate_cube_normals_coords(std::shared_ptr<bright::base::ActorData> pCubeData);
  void generate_cube_texture_coords(std::shared_ptr<bright::base::ActorData> pCubeData);

  void generate_plane_coords(std::shared_ptr<bright::base::ActorData> pPlaneData, float size);
  void generate_plane_normals_coords(std::shared_ptr<bright::base::ActorData> pPlaneData);
  void generate_plane_texture_coords(std::shared_ptr<bright::base::ActorData> pPlaneData);

  void load_data_into_graphics_memory(bright::graphics::ActorRenderInfo& actorRenderInfo, std::shared_ptr<bright::base::ActorData> pActorData);

  }
}

#endif