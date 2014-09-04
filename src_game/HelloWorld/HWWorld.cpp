//==============================================================================
///	
///	File: HWWorld.cpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "HelloWorld/HWWorld.hpp"
#include "DT3Core/System/Factory.hpp"
#include "DT3Core/Types/FileBuffer/Archive.hpp"
#include "DT3Core/Types/FileBuffer/ArchiveData.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Register with node factory
//==============================================================================

IMPLEMENT_FACTORY_CREATION_WORLD(HWWorld)
		
//==============================================================================
/// Standard class constructors/destructors
//==============================================================================

HWWorld::HWWorld (void)	
{
	set_name("HWWorld");
}	

HWWorld::~HWWorld (void)
{    

}

//==============================================================================
//==============================================================================

void HWWorld::initialize (void)	
{
	World::initialize();
}

//==============================================================================
//==============================================================================

void HWWorld::archive (const std::shared_ptr<Archive> &archive)
{
	World::archive(archive);

	archive->push_domain (class_id());
	archive->pop_domain();
}

//==============================================================================
//==============================================================================

} // DT3

