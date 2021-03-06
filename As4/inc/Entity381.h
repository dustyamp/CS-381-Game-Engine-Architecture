#ifndef __Entity381_h_
#define __Entity381_h_

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreVector3.h>

#include "Engine.h"
#include "EntityMgr.h"
#include "GameMgr.h"
#include "GfxMgr.h"
#include "InputMgr.h"
#include "Aspect.h" //Entity381 includes Aspect.h, this is circular! A no-no

class Entity381
{
public:
  Entity381(Engine* engine, std::string meshfilename, Ogre::Vector3 pos, int identity);
  virtual ~Entity381();

  //static data
  int identity;
  std::string name;
  std::string meshfilename;
  Ogre::SceneNode* sceneNode;
  Ogre::Entity*    ogreEntity;
  float acceleration, turnRate;
  float minSpeed, maxSpeed;

  //dynamic data
  Ogre::Vector3 position;
  Ogre::Vector3 velocity;
  bool isSelected;
  float desiredHeading, desiredSpeed;
  float heading, speed;

  std::vector<Aspect* > aspects;

  void Tick(float dt);

protected:


};

class Carrier: Entity381 {
public:
	Carrier(Engine* engine, std::string meshfilename, Ogre::Vector3 pos, int identity);
	virtual ~Carrier();

};

class DDG51: Entity381 {
public:
	DDG51(Engine* engine, std::string meshfilename, Ogre::Vector3 pos, int identity);
	virtual ~DDG51();

};

class SpeedBoat: Entity381 {
public:
	SpeedBoat(Engine* engine, std::string meshfilename, Ogre::Vector3 pos, int identity);
	virtual ~SpeedBoat();

};

class Frigate: Entity381 {
public:
	Frigate(Engine* engine, std::string meshfilename, Ogre::Vector3 pos, int identity);
	virtual ~Frigate();

};

class Alien: Entity381 {
public:
	Alien(Engine* engine, std::string meshfilename, Ogre::Vector3 pos, int identity);
	virtual ~Alien();

};


#endif // #ifndef __Entity381_h_
