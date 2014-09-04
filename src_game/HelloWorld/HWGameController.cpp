//==============================================================================
///	
///	File: BouncyGameController.cpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "Bouncy/BouncyGameController.hpp"
#include "DT3Core/System/Factory.hpp"
#include "DT3Core/System/System.hpp"
#include "DT3Core/System/Application.hpp"
#include "DT3Core/System/Globals.hpp"
#include "DT3Core/Types/FileBuffer/Archive.hpp"
#include "DT3Core/Types/FileBuffer/ArchiveData.hpp"
#include "DT3Core/Types/FileBuffer/FilePath.hpp"
#include "DT3Core/Types/Math/MoreMath.hpp"
#include "DT3Core/Types/GUI/GUILayoutPolicy.hpp"
#include "DT3Core/Types/GUI/GUIGridLayout.hpp"
#include "DT3Core/Types/GUI/GUIAnimKey.hpp"
#include "DT3Core/Types/Utility/ConsoleStream.hpp"
#include "DT3Core/Types/Utility/LatentCall.hpp"
#include "DT3Core/Types/Utility/MoreStrings.hpp"
#include "DT3Core/Types/Utility/Analytics.hpp"
#include "DT3Core/Types/Threads/ThreadMainTaskQueue.hpp"
#include "DT3Core/World/World.hpp"
#include "DT3Core/Objects/GUIController.hpp"
#include "DT3Core/Objects/GUIObject.hpp"
#include "DT3Core/Devices/DeviceAudio.hpp"
#include "DT3Core/Resources/ResourceTypes/FontResource.hpp"
#include "DT3Core/Components/ComponentGUIButton.hpp"
#include "DT3Core/Components/ComponentGUIToggleButton.hpp"
#include "DT3Core/Components/ComponentGUIDrawButton.hpp"
#include "DT3Core/Components/ComponentGUIDrawText.hpp"
#include "DT3Core/Components/ComponentGUIDrawIcon.hpp"

#include <algorithm>

#if DTP_USE_PORTAL
    #include "DTPortalSDK/DTPortalLib/DTPortalSDK.hpp"
#endif

#ifndef DT3_EDITOR
    extern void show_twitter    (const std::string &msg);
    extern void show_facebook   (const std::string &msg);
#else
    inline void show_twitter    (const std::string &msg)    {}
    inline void show_facebook   (const std::string &msg)    {}
#endif

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Register with object factory
//==============================================================================

IMPLEMENT_FACTORY_CREATION_PLACEABLE(BouncyGameController,"Bouncy","")
    
//==============================================================================
/// Standard class constructors/destructors
//==============================================================================

BouncyGameController::BouncyGameController (void)
    :   _co                 (this, &BouncyGameController::run_co, 1024*1024)
{

}
	
BouncyGameController::BouncyGameController (const BouncyGameController &rhs)
    :   GameController(rhs),
        _co                 (this, &BouncyGameController::run_co, 1024*1024)
{

}

BouncyGameController & BouncyGameController::operator = (const BouncyGameController &rhs)
{
    // Make sure we are not assigning the class to itself
    if (&rhs != this) {
		GameController::operator = (rhs);
    }
    return (*this);
}
		
BouncyGameController::~BouncyGameController (void)
{

}

//==============================================================================
//==============================================================================

void BouncyGameController::initialize (void)
{
	GameController::initialize();
}

//==============================================================================
//==============================================================================

void BouncyGameController::archive (const std::shared_ptr<Archive> &archive)
{
    GameController::archive(archive);

    archive->push_domain (class_id ());
    
    archive->pop_domain ();
}

void BouncyGameController::archive_done (const std::shared_ptr<Archive> &archive)
{		
	GameController::archive_done (archive);
    
    if (archive->is_writing())
        return;
}

//==============================================================================
// _____                     
//|  __ \                    
//| |__) |_ _ _   _ ___  ___ 
//|  ___/ _` | | | / __|/ _ \
//| |  | (_| | |_| \__ \  __/
//|_|   \__,_|\__,_|___/\___|
//        
//==============================================================================

void BouncyGameController::show_pause (void)
{

}

//==============================================================================
// _    _ _       _        _____
//| |  | (_)     | |      / ____|                   
//| |__| |_  __ _| |__   | (___   ___ ___  _ __ ___ 
//|  __  | |/ _` | '_ \   \___ \ / __/ _ \| '__/ _ \
//| |  | | | (_| | | | |  ____) | (_| (_) | | |  __/
//|_|  |_|_|\__, |_| |_| |_____/ \___\___/|_|  \___|
//           __/ |                                  
//          |___/
//==============================================================================

void BouncyGameController::click_key (std::string k)
{
//    std::string label = Globals::global("APP_USER_NAME");
//    
//    if (label == "BouncyDude") {
//        label.clear();
//    }
//    
//    if (k == "<") {
//
//        if (label.size() > 0)
//            label = label.substr(0,label.size()-1);
//        
//    } else {
//
//        // Replace last character
//        if (label.size() >= 32)
//            label = label.substr(0,31);
//
//        label += k;
//    }
//    
//    Globals::set_global("APP_USER_NAME", label, Globals::PERSISTENT);
}

void BouncyGameController::submit (void)
{
//    random_fade_out(_enter_high_score_layout);
//    
//    if (!_submitted) {
//        _submitted = true;
//
//        DTPortal::HighScore s;
//        s.name = Globals::global("APP_USER_NAME");
//
//        DTshort wins = MoreStrings::cast_from_string<DTshort>(Globals::global("APP_USER_SCORE_WINS"));
//        DTshort losses = MoreStrings::cast_from_string<DTshort>(Globals::global("APP_USER_SCORE_LOSSES"));
//
//        s.score = (wins << 16) | losses;
//
//        DTPortal::submit_high_score("Bouncy", s, NULL, NULL);
//    }
//    
//    System::application()->transition_to_world(FilePath("{title.lvl}"), "TransitionFadeOutIn", 1.0F, NULL, NULL);
}

void BouncyGameController::skip (void)
{
//    random_fade_out(_enter_high_score_layout);
//    
//    System::application()->transition_to_world(FilePath("{title.lvl}"), "TransitionFadeOutIn", 1.0F, NULL, NULL);
}

//==============================================================================
//==============================================================================

void BouncyGameController::click_facebook (void)
{
    show_facebook (Globals::global("TXT_FACEBOOK_MSG"));
}

void BouncyGameController::click_twitter (void)
{
    show_twitter (Globals::global("TXT_TWITTER_MSG"));
}

//==============================================================================
//==============================================================================

void BouncyGameController::run_co (Coroutine<BouncyGameController> *co)
{
    while (1) {
        _co.yield(1.0F);
    }
}

//==============================================================================
//==============================================================================

void BouncyGameController::tick (const DTfloat dt)
{
    _co.resume();
}

//==============================================================================
//==============================================================================

std::shared_ptr<GUIObject> BouncyGameController::make_key(const std::string &key, DTfloat width, DTfloat height)
{
    DTfloat screen_width = System::renderer()->screen_width();
    DTfloat screen_height = System::renderer()->screen_height();

    DTboolean phone_mode = screen_height > screen_width;
    if (!phone_mode) {
        DTfloat scale = screen_width / 1024.0F;
        screen_width /= scale;
        screen_height /= scale;
    }

    std::shared_ptr<GUIObject> widget = GUIObject::create();
    world()->add_node_unique_name(widget);
    _gui_controller->add_child(widget);
    
    widget->set_label("{FMT_BUTTON}" + key);
    widget->set_width(width);
    widget->set_height(height);
    widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));
    
    // Interaction 
    std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
    widget->add_component(widget_interaction);
    widget_interaction->set_button_pressed_latent_call(make_latent_call(this,&type::click_key, key));

    // Drawing
    std::shared_ptr<ComponentGUIDrawButton> widget_drawing = ComponentGUIDrawButton::create();
    widget->add_component(widget_drawing);
    
    widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_button.mat}")));
    widget_drawing->set_disabled_material(MaterialResource::import_resource(FilePath("{ui_button_disabled.mat}")));
    widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
    widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
    widget_drawing->set_corner_height(0.025F);
    widget_drawing->set_corner_width(0.025F);

    return widget;
}

std::shared_ptr<GUIObject> BouncyGameController::make_key_space(DTfloat width, DTfloat height)
{
    DTfloat screen_width = System::renderer()->screen_width();
    DTfloat screen_height = System::renderer()->screen_height();
    
    DTboolean phone_mode = screen_height > screen_width;
    if (!phone_mode) {
        DTfloat scale = screen_width / 1024.0F;
        screen_width /= scale;
    }

    // Make it bigger
    std::shared_ptr<GUIObject> space = make_key(" ", 350.0F / screen_width, height);
    return space;
}

//==============================================================================
//==============================================================================

void BouncyGameController::add_to_world(World *world)
{
    GameController::add_to_world(world);
    
    world->register_for_tick(this, make_callback(this, &type::tick));

#ifndef DT3_EDITOR
    DTboolean full_version = MoreStrings::cast_from_string<DTboolean>(Globals::global("APP_FULL_VERSION"));

    DTfloat screen_width = System::renderer()->screen_width();
    DTfloat screen_height = System::renderer()->screen_height();

    DTboolean phone_mode = screen_height > screen_width;
    if (!phone_mode) {
        DTfloat scale = screen_width / 1024.0F;
        screen_width /= scale;
        screen_height /= scale;
    }

    _gui_layout_master = GUIGridLayout::create();
    _gui_layout_master->set_rows_and_columns(3, 3);
    if (phone_mode)
        _gui_layout_master->set_row_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 150.0F/screen_width));
    else
        _gui_layout_master->set_row_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 200.0F/screen_width));
    _gui_layout_master->set_row_policy(1, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_layout_master->set_row_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 200.0F/screen_width));
    _gui_layout_master->set_column_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 200.0F/screen_height));
    _gui_layout_master->set_column_policy(1, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_layout_master->set_column_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 200.0F/screen_height));
    
    
    // Build GUI
    _gui_controller = GUIController::create();
    _gui_controller->set_use_stencil(false);
    world->add_node_unique_name(_gui_controller);
    
    DTfloat button_size = phone_mode ? 100.0F : 64.0F;

    
    // _____
    //|  __ \                    
    //| |__) |_ _ _   _ ___  ___ 
    //|  ___/ _` | | | / __|/ _ \
    //| |  | (_| | |_| \__ \  __/
    //|_|   \__,_|\__,_|___/\___|
    //

    _gui_pause_button = GUIGridLayout::create();
    _gui_pause_button->set_rows_and_columns(3, 3);
    _gui_pause_button->set_row_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_pause_button->set_row_policy(1, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, button_size*0.5F/screen_height));

    if (full_version) {
        _gui_pause_button->set_row_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 25.0F/screen_height));
    } else {
        if (phone_mode)
            _gui_pause_button->set_row_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 110.0F/screen_height));
        else
            _gui_pause_button->set_row_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 75.0F/screen_height));
    }

    _gui_pause_button->set_column_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 5.0F/screen_width));
    _gui_pause_button->set_column_policy(1, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, button_size*0.5F/screen_width));
    _gui_pause_button->set_column_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    // Pause
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _gui_pause_button->add_item(1,1,widget);
        
        widget->set_color(Color4f(1.0F,1.0F,1.0F,1.0F));
        
        // Interaction 
        std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
        widget->add_component(widget_interaction);
        widget_interaction->set_button_pressed_latent_call(make_latent_call(this,&BouncyGameController::show_pause));

        // Drawing
        std::shared_ptr<ComponentGUIDrawIcon> widget_drawing = ComponentGUIDrawIcon::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_pause.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
    }


    _gui_pause = GUIGridLayout::create();
    _gui_pause->set_rows_and_columns(8, 3);
    _gui_pause->set_row_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_pause->set_row_policy(1, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 10.0F/screen_height));
    _gui_pause->set_row_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, button_size/screen_height));   // Quit
    _gui_pause->set_row_policy(3, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, button_size/screen_height));   // Sound
    _gui_pause->set_row_policy(4, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, button_size/screen_height));   // Resume
    _gui_pause->set_row_policy(5, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, button_size/screen_height));   // Title
    _gui_pause->set_row_policy(6, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 10.0F/screen_height));
    _gui_pause->set_row_policy(7, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_pause->set_column_policy(0, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_pause->set_column_policy(1, GUILayoutPolicy (GUILayoutPolicy::POLICY_FIXED_SIZE, 300.0F/screen_width));
    _gui_pause->set_column_policy(2, GUILayoutPolicy (GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _gui_layout_master->add_item(1, 1, _gui_pause);
    
    // Background
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _gui_pause->set_border_item(widget, 0.05F, 0.05F);
        
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));
        
        // Drawing
        std::shared_ptr<ComponentGUIDrawIcon> widget_drawing = ComponentGUIDrawIcon::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_draw_style(ComponentGUIDrawIcon::DRAW_STYLE_STRETCH_CENTER_2X2);
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_bg.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
    }

    // Title
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _gui_pause->add_item(5,1,widget);
        
        widget->set_label("{TXT_PAUSE}");
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));
        
        // Drawing
        std::shared_ptr<ComponentGUIDrawText> widget_drawing = ComponentGUIDrawText::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
    }

    // Resume
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _gui_pause->add_item(4,1,widget);
        
        widget->set_label("{TXT_RESUME}");
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));

        // Interaction 
        std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
        widget->add_component(widget_interaction);
        widget_interaction->set_button_pressed_latent_call(make_latent_call(this,&BouncyGameController::resume));

        // Drawing
        std::shared_ptr<ComponentGUIDrawButton> widget_drawing = ComponentGUIDrawButton::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_button.mat}")));
        widget_drawing->set_disabled_material(MaterialResource::import_resource(FilePath("{ui_button_disabled.mat}")));
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
    }

    // Quit
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _gui_pause->add_item(2,1,widget);
        
        widget->set_label("{TXT_QUIT}");
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));

        // Interaction 
        std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
        widget->add_component(widget_interaction);
        widget_interaction->set_button_pressed_latent_call(make_latent_call(this,&BouncyGameController::quit));

        // Drawing
        std::shared_ptr<ComponentGUIDrawButton> widget_drawing = ComponentGUIDrawButton::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_button.mat}")));
        widget_drawing->set_disabled_material(MaterialResource::import_resource(FilePath("{ui_button_disabled.mat}")));
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
    }

    // _    _ _       _        _____
    //| |  | (_)     | |      / ____|                   
    //| |__| |_  __ _| |__   | (___   ___ ___  _ __ ___ 
    //|  __  | |/ _` | '_ \   \___ \ / __/ _ \| '__/ _ \
    //| |  | | | (_| | | | |  ____) | (_| (_) | | |  __/
    //|_|  |_|_|\__, |_| |_| |_____/ \___\___/|_|  \___|
    //           __/ |                                  
    //          |___/

    DTfloat keyboard_button_size;
    DTfloat keyboard_buttons_width = 1.0F;
    DTfloat keyboard_buttons_height = 1.0F;

    if (phone_mode) {
        keyboard_button_size = 1.0F/12.0F * screen_width;
        keyboard_buttons_width = 1.0F/12.0F;
        keyboard_buttons_height = keyboard_button_size / screen_height;

    } else {
        keyboard_button_size = 64.0F;
        keyboard_buttons_width = 64.0F / screen_width;
        keyboard_buttons_height = 64.0F / screen_height;
    }

    _enter_high_score_layout = GUIGridLayout::create();
    _enter_high_score_rows = GUIGridLayout::create();
    _row1 = GUIGridLayout::create();
    _row2 = GUIGridLayout::create();
    _row3 = GUIGridLayout::create();
    _row4 = GUIGridLayout::create();
    _row5 = GUIGridLayout::create();
    _row_buttons = GUIGridLayout::create();
    
    _enter_high_score_rows->set_rows_and_columns(13,3);

    if (phone_mode) {
        _enter_high_score_rows->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 10.0F/screen_height));
    } else {
#if DT3_OS == DT3_ANDROID
        _enter_high_score_rows->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 50.0F/screen_height));
#else
        _enter_high_score_rows->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 100.0F/screen_height));
#endif
    }

    _enter_high_score_rows->set_row_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, button_size/screen_height));
    _enter_high_score_rows->set_row_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _enter_high_score_rows->set_row_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_height));
    _enter_high_score_rows->set_row_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_height));
    _enter_high_score_rows->set_row_policy(5, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_height));
    _enter_high_score_rows->set_row_policy(6, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_height));
    _enter_high_score_rows->set_row_policy(7, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_height));
    _enter_high_score_rows->set_row_policy(8, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _enter_high_score_rows->set_row_policy(9, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, button_size/screen_height));
    _enter_high_score_rows->set_row_policy(10, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _enter_high_score_rows->set_row_policy(11, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    if (phone_mode) {
        _enter_high_score_rows->set_row_policy(12, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 150.0F/screen_height));
    } else {
#if DT3_OS == DT3_ANDROID
        _enter_high_score_rows->set_row_policy(12, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 50.0F/screen_height));
#else
        _enter_high_score_rows->set_row_policy(12, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 100.0F/screen_height));
#endif
    }

    if (phone_mode) {
        _enter_high_score_rows->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 15/screen_width));
        _enter_high_score_rows->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
        _enter_high_score_rows->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 15/screen_width));
    } else {
        _enter_high_score_rows->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
        _enter_high_score_rows->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 800/screen_width));
        _enter_high_score_rows->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    }

    _enter_high_score_rows->add_item(7,1, _row1);
    _enter_high_score_rows->add_item(6,1, _row2);
    _enter_high_score_rows->add_item(5,1, _row3);
    _enter_high_score_rows->add_item(4,1, _row4);
    _enter_high_score_rows->add_item(3,1, _row5);
    _enter_high_score_rows->add_item(1,1, _row_buttons);
    
    
    
    _enter_high_score_layout->set_rows_and_columns(1,1);
    _enter_high_score_layout->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _enter_high_score_layout->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    
    _enter_high_score_layout->add_item(0,0, _enter_high_score_rows);
    
    // Background
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _enter_high_score_rows->set_border_item(widget, 0.02F, 0.05F);
        
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));
        
        // Drawing
        std::shared_ptr<ComponentGUIDrawIcon> widget_drawing = ComponentGUIDrawIcon::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_draw_style(ComponentGUIDrawIcon::DRAW_STYLE_STRETCH_CENTER_2X2);
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_bg.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
    }
    
    _row1->set_rows_and_columns(1,13);
    _row1->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row1->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row1->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(5, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(6, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(7, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(8, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(9, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(10, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(11, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row1->set_column_policy(12, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    
    _row1->add_item(0,1,make_key("1",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,2,make_key("2",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,3,make_key("3",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,4,make_key("4",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,5,make_key("5",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,6,make_key("6",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,7,make_key("7",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,8,make_key("8",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,9,make_key("9",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,10,make_key("0",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row1->add_item(0,11,make_key("<",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);



    _row2->set_rows_and_columns(1,12);
    _row2->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row2->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row2->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(5, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(6, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(7, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(8, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(9, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(10, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row2->set_column_policy(11, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    _row2->add_item(0,1,make_key("Q",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,2,make_key("W",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,3,make_key("E",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,4,make_key("R",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,5,make_key("T",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,6,make_key("Y",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,7,make_key("U",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,8,make_key("I",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,9,make_key("O",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row2->add_item(0,10,make_key("P",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);



    _row3->set_rows_and_columns(1,11);
    _row3->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row3->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row3->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(5, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(6, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(7, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(8, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(9, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row3->set_column_policy(10, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    _row3->add_item(0,1,make_key("A",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,2,make_key("S",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,3,make_key("D",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,4,make_key("F",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,5,make_key("G",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,6,make_key("H",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,7,make_key("J",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,8,make_key("K",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row3->add_item(0,9,make_key("L",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);



    _row4->set_rows_and_columns(1,9);
    _row4->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row4->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row4->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(5, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(6, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(7, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, keyboard_buttons_width));
    _row4->set_column_policy(8, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    _row4->add_item(0,1,make_key("Z",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row4->add_item(0,2,make_key("X",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row4->add_item(0,3,make_key("C",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row4->add_item(0,4,make_key("V",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row4->add_item(0,5,make_key("B",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row4->add_item(0,6,make_key("N",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    _row4->add_item(0,7,make_key("M",keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);
    
    
    _row5->set_rows_and_columns(1,3);
    _row5->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row5->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row5->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 350.0F/screen_width));
    _row5->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    _row5->add_item(0,1,make_key_space(keyboard_buttons_width, keyboard_buttons_height),GUIGridLayoutItem::RESIZE_MODE_DO_NOTHING);


    _row_buttons->set_rows_and_columns(1,5);
    _row_buttons->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row_buttons->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row_buttons->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 200.0F/screen_width));
    _row_buttons->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
    _row_buttons->set_column_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 200.0F/screen_width));
    _row_buttons->set_column_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));

    
    
    // Title
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _enter_high_score_rows->add_item(11, 1, widget);
        
        widget->set_label("{TXT_ENTER_HIGH_SCORE}");
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));
        
        // Drawing
        std::shared_ptr<ComponentGUIDrawText> widget_drawing = ComponentGUIDrawText::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        
    }

    // Name text box
    {
        _text_box = GUIObject::create();
        world->add_node_unique_name(_text_box);
        _gui_controller->add_child(_text_box);
        
        _enter_high_score_rows->add_item(9, 1, _text_box);
        
        _text_box->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));
        _text_box->set_no_focus(true);
        _text_box->set_width(450.0F / screen_width);
        _text_box->set_height(50.0F / screen_height);

        _text_box->set_label("{FMT_BUTTON}{APP_USER_NAME}");

        // Drawing
        std::shared_ptr<ComponentGUIDrawButton> widget_drawing = ComponentGUIDrawButton::create();
        _text_box->add_component(widget_drawing);
        
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_button.mat}")));
        widget_drawing->set_disabled_material(MaterialResource::import_resource(FilePath("{ui_button_disabled.mat}")));
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
        
    }
    
    
    // Submit
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _row_buttons->add_item(0, 3, widget);
        
        widget->set_label("{TXT_SUBMIT}");
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));

        // Interaction 
        std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
        widget->add_component(widget_interaction);
        widget_interaction->set_button_pressed_latent_call(make_latent_call(this,&BouncyGameController::submit));

        // Drawing
        std::shared_ptr<ComponentGUIDrawButton> widget_drawing = ComponentGUIDrawButton::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_button.mat}")));
        widget_drawing->set_disabled_material(MaterialResource::import_resource(FilePath("{ui_button_disabled.mat}")));
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
    }

    // Skip
    {
        std::shared_ptr<GUIObject> widget = GUIObject::create();
        world->add_node_unique_name(widget);
        _gui_controller->add_child(widget);
        
        _row_buttons->add_item(0, 1, widget);
        
        widget->set_label("{TXT_SKIP}");
        widget->set_color(Color4f(1.0F,1.0F,1.0F,0.0F));

        // Interaction 
        std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
        widget->add_component(widget_interaction);
        widget_interaction->set_button_pressed_latent_call(make_latent_call(this,&BouncyGameController::skip));

        // Drawing
        std::shared_ptr<ComponentGUIDrawButton> widget_drawing = ComponentGUIDrawButton::create();
        widget->add_component(widget_drawing);
        
        widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_button.mat}")));
        widget_drawing->set_disabled_material(MaterialResource::import_resource(FilePath("{ui_button_disabled.mat}")));
        widget_drawing->set_font_material(MaterialResource::import_resource(FilePath("{cards.mat}")));
        widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        widget_drawing->set_corner_height(0.025F);
        widget_drawing->set_corner_width(0.025F);
    }
    
    _enter_high_score_layout->layout(Rectangle(0.0F,1.0F,0.0F,1.0F));
    
#if DT3_OS != DT3_ANDROID
    //  _____            _       _   __  __          _ _
    // / ____|          (_)     | | |  \/  |        | (_)      
    //| (___   ___   ___ _  __ _| | | \  / | ___  __| |_  __ _ 
    // \___ \ / _ \ / __| |/ _` | | | |\/| |/ _ \/ _` | |/ _` |
    // ____) | (_) | (__| | (_| | | | |  | |  __/ (_| | | (_| |
    //|_____/ \___/ \___|_|\__,_|_| |_|  |_|\___|\__,_|_|\__,_|

    if (!phone_mode) {
        _social_media_layout = GUIGridLayout::create();
        _social_media_layout->set_rows_and_columns(3,5);
        _social_media_layout->set_row_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 20.0F/screen_height));
        _social_media_layout->set_row_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 30.0F/screen_height));
        _social_media_layout->set_row_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
        _social_media_layout->set_column_policy(0, GUILayoutPolicy(GUILayoutPolicy::POLICY_WEIGHTED_SIZE, 1.0F));
        _social_media_layout->set_column_policy(1, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 30.0F/screen_width));
        _social_media_layout->set_column_policy(2, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 20.0F/screen_width));
        _social_media_layout->set_column_policy(3, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 30.0F/screen_width));
        _social_media_layout->set_column_policy(4, GUILayoutPolicy(GUILayoutPolicy::POLICY_FIXED_SIZE, 20.0F/screen_width));

        // Facebook
        {
            std::shared_ptr<GUIObject> widget = GUIObject::create();
            world->add_node_unique_name(widget);
            _gui_controller->add_child(widget);
            
            _social_media_layout->add_item(1, 1, widget);
            
            widget->set_color(Color4f(1.0F,1.0F,1.0F,1.0F));
            
            // Interaction 
            std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
            widget->add_component(widget_interaction);
            widget_interaction->set_button_pressed_latent_call(make_latent_call(this, &type::click_facebook));

            // Drawing
            std::shared_ptr<ComponentGUIDrawIcon> widget_drawing = ComponentGUIDrawIcon::create();
            widget->add_component(widget_drawing);
            
            widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_facebook.mat}")));
            widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        }

        // Twitter
        {
            std::shared_ptr<GUIObject> widget = GUIObject::create();
            world->add_node_unique_name(widget);
            _gui_controller->add_child(widget);
            
            _social_media_layout->add_item(1, 3, widget);
            
            widget->set_color(Color4f(1.0F,1.0F,1.0F,1.0F));
            
            // Interaction 
            std::shared_ptr<ComponentGUIButton> widget_interaction = ComponentGUIButton::create();
            widget->add_component(widget_interaction);
            widget_interaction->set_button_pressed_latent_call(make_latent_call(this, &type::click_twitter));

            // Drawing
            std::shared_ptr<ComponentGUIDrawIcon> widget_drawing = ComponentGUIDrawIcon::create();
            widget->add_component(widget_drawing);
            
            widget_drawing->set_material(MaterialResource::import_resource(FilePath("{ui_twitter.mat}")));
            widget_drawing->set_shader(ShaderResource::import_resource(FilePath("{default.shdr}")));
        }
        
        _social_media_layout->layout(Rectangle(0.0F,1.0F,0.0F,1.0F));
    }
#endif
    
    _gui_pause_button->layout(Rectangle(0.0F,1.0F,0.0F,1.0F));
    _gui_layout_master->layout(Rectangle(0.0F,1.0F,0.0F,1.0F));
    
#endif

    //ThreadMainTaskQueue::add_task(make_latent_call(this, &BouncyGameController::set_state, STATE_DEALING, _dealer), 0.0F, 0.5F);
}

void BouncyGameController::remove_from_world (void)
{
    world()->unregister_for_tick(this, make_callback(this, &type::tick));

    GameController::remove_from_world();
}

//==============================================================================
//==============================================================================

} // DT3

