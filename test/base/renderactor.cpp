#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.h"
#include "base/renderactor.hpp"

  std::string mesh();
  void mesh(std::string mesh);

  std::string shader();
  void shader(std::string shader);

  std::string name();
  void name(std::string name);

  std::string camera_type();
  void camera_type(std::string cameraType);


SCENARIO( "renderactor's public interface should work as designed", "[renderactor]" ) {

  GIVEN( "A shared pointer to a default constructed renderactor" ) {
    auto pRenderActor = std::make_shared<bright::base::RenderActor>();

    REQUIRE( pRenderActor->name().compare("") == 0 );
    REQUIRE( pRenderActor->mesh().compare("") == 0 );
    REQUIRE( pRenderActor->shader().compare("") == 0 );
    REQUIRE( pRenderActor->camera_type().compare("") == 0 );
 
    WHEN( "the name is set" ) {
      pRenderActor->name( "newName!" );

      THEN( "the name is different" ) {
        REQUIRE( pRenderActor->name().compare("newName!") == 0 );
      }
    }
    WHEN( "the mesh is set" ) {
      pRenderActor->mesh("newMesh!");

      THEN( "mesh is different" ) {
        REQUIRE( pRenderActor->mesh().compare("newMesh!") == 0 );
      }
    }
    WHEN( "the shader is set" ) {
      pRenderActor->shader("newShader!");

      THEN( "shader is different" ) {
        REQUIRE( pRenderActor->shader().compare("newShader!") == 0 );
      }
    }
    WHEN( "the camera_type is set" ) {
      pRenderActor->shader("newCameraType!");

      THEN( "camera_type is different" ) {
        REQUIRE( pRenderActor->camera_type().compare("newCameraType!") == 0 );
      }
    }

  }

}


SCENARIO( "renderactor shared pointer should work as expected", "[renderactor]" ) {

  GIVEN( "A shared pointer to a default constructed renderactor that has been modified" ) {
    std::shared_ptr<bright::base::Actor> pRenderActor = std::make_shared<bright::base::Actor>();
 
    REQUIRE( pRenderActor->name().compare("") == 0 );
    REQUIRE( pRenderActor->mesh().compare("") == 0 );
    REQUIRE( pRenderActor->shader().compare("") == 0 );
    REQUIRE( pRenderActor->camera_type().compare("") == 0 );

    pRenderActor->name("heheh")
    REQUIRE( pRenderActor->name().compare("heheh!") == 0 );

  }

}