#ifndef BRIGHT_AI_AIMANAGER_H
#define BRIGHT_AI_AIMANAGER_H

#include <memory>
#include <map>
#include <iostream>
#include "base/actorcontrolsresourcemanager.hpp"
#include "base/actorcontrolcontroller.hpp"
#include "base/controlactor.hpp"

namespace bright{

  namespace ai{

class AIManager {
public:
  AIManager(std::shared_ptr<bright::base::ActorControlsResourceManager> pActorControlsResourceManager);

  // Return number of monsters that are moved but haven't yet reached player.
  int AIManager::handle_ai();
private:

  std::map<std::string, bright::base::ControlActor>& controlPlayers_;
  std::map<std::string, bright::base::ControlActor>& controlNpcs_;
  std::map<std::string, bright::base::ActorControlController>& playerControllers_;
  std::map<std::string, bright::base::ActorControlController>& npcControllers_;
  std::map<std::string, bright::physics::AABB>& playerAABBs_;
  std::map<std::string, bright::physics::AABB>& npcAABBs_;

};



  }
}
#endif
