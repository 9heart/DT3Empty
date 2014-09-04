#ifndef DT3_BOUNCYWORLD
#define DT3_BOUNCYWORLD
//==============================================================================
///	
///	File: BouncyWorld.hpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "DT3Core/World/World.hpp"
#include "DT3Core/Types/Graphics/DrawBatcher.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================

typedef Callback<const std::shared_ptr<CameraObject> &, DrawBatcher *, DTfloat> DrawBatchedCallbackType;
typedef WorldEntry<DrawBatchedCallbackType> DrawBatchedCallbackEntry;

//==============================================================================
//==============================================================================

class BouncyWorld: public World {
    public:
        DEFINE_TYPE(BouncyWorld,World)
		DEFINE_CREATE

									BouncyWorld             (void);
	private:
									BouncyWorld             (const BouncyWorld &rhs);
        BouncyWorld &               operator =              (const BouncyWorld &rhs);
	public:
        virtual						~BouncyWorld            (void);
                                        
        virtual void				archive                 (const std::shared_ptr<Archive> &archive);

    public:
		/// Called to initialize the object
		virtual void				initialize              (void);

		/// Process arguments
		virtual void                process_args            (const std::string &args);

    private:
        DrawBatcher                 _b;
};

//==============================================================================
//==============================================================================

} // DT3

#endif
