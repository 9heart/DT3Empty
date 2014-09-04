#ifndef DT3_HWWORLD
#define DT3_HWWORLD
//==============================================================================
///	
///	File: HWWorld.hpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "DT3Core/World/World.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================


//==============================================================================
//==============================================================================

class HWWorld: public World {
    public:
        DEFINE_TYPE(HWWorld,World)
		DEFINE_CREATE

									HWWorld                 (void);
	private:
									HWWorld                 (const HWWorld &rhs);
        HWWorld &                   operator =              (const HWWorld &rhs);
	public:
        virtual						~HWWorld                (void);
                                        
        virtual void				archive                 (const std::shared_ptr<Archive> &archive);

    public:
		/// Called to initialize the object
		virtual void				initialize              (void);
};

//==============================================================================
//==============================================================================

} // DT3

#endif
