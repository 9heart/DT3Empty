#ifndef DT3_HWGAMECONTROLLER
#define DT3_HWGAMECONTROLLER
//==============================================================================
///	
///	File: HWGameController.hpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "DT3Core/Objects/GameController.hpp"
#include "DT3Core/Types/Math/Matrix4.hpp"
#include "DT3Core/Types/GUI/GUIGridLayout.hpp"
#include "DT3Core/Types/Utility/Coroutine.hpp"
#include <list>

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================

class GUIController;

//==============================================================================
/// The game controller. The Game controller manages the game rules and
/// state and also manages the players.
//==============================================================================

class HWGameController: public GameController {    
    public:
        DEFINE_TYPE(HWGameController,GameController)
		DEFINE_CREATE_AND_CLONE

										HWGameController        (void);
										HWGameController        (const HWGameController &rhs);
        HWGameController &              operator =				(const HWGameController &rhs);
        virtual							~HWGameController       (void);
    
        virtual void					archive                 (const std::shared_ptr<Archive> &archive);
        virtual void                    archive_done            (const std::shared_ptr<Archive> &archive);

	public:
		/// Called to initialize the object
		virtual void                    initialize				(void);

		/// Callback called when the object is getting a tick
		/// \param dt delta time
		virtual void                    tick                    (const DTfloat dt);

		/// Object was added to a world
		/// world world that object was added to
        virtual void                    add_to_world            (World *world);

		/// Object was removed from a world
        virtual void                    remove_from_world       (void);

    private:

};

//==============================================================================
//==============================================================================

} // DT3

#endif
