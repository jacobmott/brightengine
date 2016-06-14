#include "base/controlactor.hpp"

using namespace bright::base;

ControlActor::ControlActor(): isLoggedIn_(false), isPlayer_(false), name_(""), haveUpdate_(false){
}


void ControlActor::aabb(std::string name){
  aabb_ = name;
}


std::string ControlActor::aabb(){
  return aabb_;
}


bool ControlActor::is_player(){
  return isPlayer_;
}


void ControlActor::is_player(bool value){
  isPlayer_ = value;
}

bool ControlActor::is_logged_in(){
  return isLoggedIn_;
}


void ControlActor::is_logged_in(bool value){
  isLoggedIn_ = value;
}


void ControlActor::name(std::string name){
  name_ = name;
}


std::string ControlActor::name(){
  return name_;
}


bool ControlActor::have_update(){
  return haveUpdate_;
}


void ControlActor::have_update(bool value){
  haveUpdate_ = value;
}


glm::vec3 ControlActor::pos(){
  return pos_;
}


void ControlActor::pos(glm::vec3 pos){
  pos_ = pos;
}


glm::vec3 ControlActor::rotation(){
  return rotation_;
}


void ControlActor::rotation(glm::vec3 rotation){
  rotation_ = rotation;
}


ControlActor ControlActor::clone(){

  ControlActor cloned;
  cloned.pos( pos() );
  cloned.rotation( rotation() );
  return cloned;
}