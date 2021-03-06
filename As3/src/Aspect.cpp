/*
 * Aspect.cpp
 *
 *  Created on: Mar 2, 2019
 *      Author: Alexander Pasinski
 *      Contributor: Sushil J Louis (Feb 7, 2018)
 */

#include "Aspect.h"
#include "Entity381.h"  //Aspect includes Entity381.h

Aspect::Aspect(Entity381 *ent)
{
    entity = ent;
}

Aspect::~Aspect()
{

}

void Aspect::Tick(float dt)
{

}



Physics::Physics(Entity381* ent)
        : Aspect(ent)
{

}

Physics::~Physics()
{

}

void Physics::Tick(float dt)
{
    if(entity->speed < entity->desiredSpeed)
    {
        entity->speed += entity->acceleration;
        
        if(entity->speed > entity->maxSpeed)
        {
            entity->speed = entity->maxSpeed;
        }
    }
    else if(entity->speed > entity->desiredSpeed)
    {
        entity->speed -= entity->acceleration;
        
        if(entity->speed < entity->minSpeed)
        {
            entity->speed = entity->minSpeed;
        }
    }
    
    if(entity->heading < entity->desiredHeading)
    {
        entity->turningPort = true;
        entity->turningStarboard = false;
    }
    else if(entity->heading > entity->desiredHeading)
    {
        entity->turningPort = false;
        entity->turningStarboard = true;
    }
    
    entity->velocity.z = entity->speed * -1.0f * Ogre::Math::Sin(Ogre::Math::DegreesToRadians(entity->heading));
    entity->velocity.x = entity->speed * Ogre::Math::Cos(Ogre::Math::DegreesToRadians(entity->heading));
    
    entity->position = entity->position + entity->velocity * dt; //entity381's position will now change every frame (tick)
}



Renderable::Renderable(Entity381* ent)
        : Aspect(ent)
{

}

Renderable::~Renderable()
{

}

void Renderable::Tick(float dt)
{
    entity->sceneNode->setPosition(entity->position);
    if(entity->turningPort)
    {
        entity->sceneNode->yaw(Ogre::Radian(Ogre::Degree(entity->turningRate * dt)));
        entity->heading += entity->turningRate * dt;
    }
    else if(entity->turningStarboard)
    {
        entity->sceneNode->yaw(Ogre::Radian(Ogre::Degree(-1 * entity->turningRate * dt)));
        entity->heading -= entity->turningRate * dt;
    }
    //entity->sceneNode->yaw(Ogre::Radian(Ogre::Degree((entity->heading - entity->previousHeading) * dt)));
    //entity->previousHeading = entity->heading;
    
    if(entity->isSelected)
    {
        entity->sceneNode->showBoundingBox(true);
    }
    else
    {
        entity->sceneNode->showBoundingBox(false);
    }
}
