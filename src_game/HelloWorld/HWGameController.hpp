#ifndef DT3_BOUNCYGAMECONTROLLER
#define DT3_BOUNCYGAMECONTROLLER
//==============================================================================
///	
///	File: BouncyGameController.hpp
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
/// The base game controller. The Game controller manages the game rules and
/// state and also manages the players.
//==============================================================================

class BouncyGameController: public GameController {    
    public:
        DEFINE_TYPE(BouncyGameController,GameController)
		DEFINE_CREATE_AND_CLONE

										BouncyGameController    (void);
										BouncyGameController    (const BouncyGameController &rhs);
        BouncyGameController &			operator =				(const BouncyGameController &rhs);
        virtual							~BouncyGameController   (void);
    
        virtual void					archive                 (const std::shared_ptr<Archive> &archive);
        virtual void                    archive_done            (const std::shared_ptr<Archive> &archive);

	public:
		/// Called to initialize the object
		virtual void                    initialize				(void);
    
        /// Callback called when the object is getting a tick
        void                            run_co                  (Coroutine<BouncyGameController> *co) __attribute__ ((noreturn));

		/// Callback called when the object is getting a tick
		/// \param dt delta time
		virtual void                    tick                    (const DTfloat dt);

		/// Object was added to a world
		/// world world that object was added to
        virtual void                    add_to_world            (World *world);

		/// Object was removed from a world
        virtual void                    remove_from_world       (void);

    private:
        Coroutine<BouncyGameController> _co;

    
        //
        // UI
        //
    
        std::shared_ptr<GUIGridLayout>  _gui_layout_master;
    
        void                            show_pause              (void);
    
        void                            show_high_score         (void);
        void                            click_key               (std::string k);

        void                            resume                  (void) {}
        void                            quit                    (void) {}
        void                            submit                  (void);
        void                            skip                    (void);

        void                            click_facebook          (void);
        void                            click_twitter           (void);

        std::shared_ptr<GUIObject>      make_key                (const std::string &key, DTfloat width, DTfloat height);
        std::shared_ptr<GUIObject>      make_key_space          (DTfloat width, DTfloat height);

        //
        // UI widgets
        //

#if DT3_OS != DT3_ANDROID
        // Social Media
        std::shared_ptr<GUIGridLayout>  _social_media_layout;
#endif

        // Pause
        std::shared_ptr<GUIGridLayout>  _gui_layout_pause;

        // Pause
        std::shared_ptr<GUIGridLayout>  _gui_pause_button;
        std::shared_ptr<GUIGridLayout>  _gui_pause;

        // High score
        std::shared_ptr<GUIGridLayout>  _enter_high_score_layout;
        std::shared_ptr<GUIGridLayout>  _enter_high_score_rows;
        std::shared_ptr<GUIGridLayout>  _row1;
        std::shared_ptr<GUIGridLayout>  _row2;
        std::shared_ptr<GUIGridLayout>  _row3;
        std::shared_ptr<GUIGridLayout>  _row4;
        std::shared_ptr<GUIGridLayout>  _row5;
        std::shared_ptr<GUIGridLayout>  _row_buttons;
        std::shared_ptr<GUIObject>      _text_box;

        // GUI Controler
        std::shared_ptr<GUIController>  _gui_controller;
        
};

//==============================================================================
//==============================================================================

} // DT3

#endif
