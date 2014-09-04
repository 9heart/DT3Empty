//==============================================================================
///	
///	File: BouncyWorld.cpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "Bouncy/BouncyWorld.hpp"
#include "DT3Core/System/Factory.hpp"
#include "DT3Core/Types/FileBuffer/Archive.hpp"
#include "DT3Core/Types/FileBuffer/ArchiveData.hpp"
#include "DT3Core/World/WorldNode.hpp"
#include "DT3Core/Objects/PlaceableObject.hpp"
#include "DT3Core/Objects/GUIController.hpp"
#include "DT3Core/Components/ComponentDrawImagePlane.hpp"
#include "Bouncy/BouncyMainMenu.hpp"
#include <algorithm>

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Register with node factory
//==============================================================================

IMPLEMENT_FACTORY_CREATION_WORLD(BouncyWorld)
		
//==============================================================================
/// Standard class constructors/destructors
//==============================================================================

BouncyWorld::BouncyWorld (void)	
{
	set_name("BouncyWorld");
}	

BouncyWorld::~BouncyWorld (void)
{    

}

//==============================================================================
//==============================================================================

void BouncyWorld::initialize (void)	
{
	World::initialize();
}

//==============================================================================
//==============================================================================

void BouncyWorld::process_args (const std::string &args)
{
//    if (args.find("launch_store") != std::string::npos) {
//
//        // Check for main menu controller
//        for (auto &i : nodes()) {
//
//            std::shared_ptr<BouncyMainMenu> mm = checked_cast<BouncyMainMenu>(i);
//            if (mm)
//                mm->go_to_store();
//
//        }
//
//    }
//
}

//==============================================================================
//==============================================================================

void BouncyWorld::archive (const std::shared_ptr<Archive> &archive)
{
	World::archive(archive);

	archive->push_domain (class_id ());
    
	archive->pop_domain();
}

//==============================================================================
//==============================================================================

} // DT3

