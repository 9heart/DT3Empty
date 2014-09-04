//==============================================================================
///	
///	File: HWGameController.cpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "HelloWorld/HWGameController.hpp"
#include "HelloWorld/HWWorld.hpp"
#include "DT3Core/System/Factory.hpp"
#include "DT3Core/System/System.hpp"
#include "DT3Core/System/Application.hpp"
#include "DT3Core/Types/FileBuffer/Archive.hpp"
#include "DT3Core/Types/FileBuffer/ArchiveData.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Register with object factory
//==============================================================================

IMPLEMENT_FACTORY_CREATION_PLACEABLE(HWGameController,"HelloWorld","")
    
//==============================================================================
/// Standard class constructors/destructors
//==============================================================================

HWGameController::HWGameController (void)
{

}
	
HWGameController::HWGameController (const HWGameController &rhs)
    :   GameController(rhs)
{

}

HWGameController & HWGameController::operator = (const HWGameController &rhs)
{
    // Make sure we are not assigning the class to itself
    if (&rhs != this) {
		GameController::operator = (rhs);
    }
    return (*this);
}
		
HWGameController::~HWGameController (void)
{

}

//==============================================================================
//==============================================================================

void HWGameController::initialize (void)
{
	GameController::initialize();
}

//==============================================================================
//==============================================================================

void HWGameController::archive (const std::shared_ptr<Archive> &archive)
{
    GameController::archive(archive);

    archive->push_domain (class_id());
    archive->pop_domain ();
}

void HWGameController::archive_done (const std::shared_ptr<Archive> &archive)
{		
	GameController::archive_done (archive);
}

//==============================================================================
//==============================================================================

void HWGameController::tick (const DTfloat dt)
{
    // Do something here
}

//==============================================================================
//==============================================================================

void HWGameController::add_to_world(World *world)
{
    GameController::add_to_world(world);
    
    world->register_for_tick(this, make_callback(this, &type::tick));
}

void HWGameController::remove_from_world (void)
{
    world()->unregister_for_tick(this, make_callback(this, &type::tick));

    GameController::remove_from_world();
}

//==============================================================================
//==============================================================================

} // DT3

