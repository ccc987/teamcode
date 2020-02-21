/*===============================================================================
Copyright (c) 2018 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.

@file 
    Vuforia_UWP.h

@brief
    Header file for global Vuforia methods that are UWP specific.
===============================================================================*/

#ifndef _VUFORIA_UWP_H_
#define _VUFORIA_UWP_H_

// Include files
#include <Vuforia/System.h>

namespace Vuforia
{

/// Set Vuforia initialization parameters
/**
 * <b>UWP:</b> Call this function before calling Vuforia::init().
 *
 * See the "Lifecycle of a Vuforia app" section on the main %Vuforia
 * reference page for more information. \ref Lifecycle "Lifecycle of a Vuforia app"
 *
 * \param key Your %Vuforia license key.
 */
void VUFORIA_API setInitParameters(const char* key);

/// Set the current screen orientation.
/**
 * <b>UWP:</b> Call to set any rotation on the %Vuforia rendered video background
 * and augmentation projection matrices to compensate for your application's
 * auto-rotation behaviour.
 *
 * The value specified is used internally by %Vuforia to adapt rendering and
 * tracking to the current screen orientation.
 *
 * This method should be called from the call-back registered with
 * DisplayInformation->OrientationChanged.
 *
 * Refer to the sample apps for full details.
 *
 * \param orientation The orientation of the screen.
 */
void VUFORIA_API setCurrentOrientation(Windows::Graphics::Display::DisplayOrientations orientation);

/// Set the app coordinate system.
/**
 * <b>UWP (Holographic):</b> Call to set the app coordinate system for Windows
 * Holographic applications. Call after Vuforia::init() but before the camera
 * is started.
 *
 * \param appSpecifiedCS A pointer to an ISpatialCoordinateSystem object representing
 * your app's coordinate system.
 */
bool VUFORIA_API setHolographicAppCS(void* appSpecifiedCS);

} // namespace Vuforia

#endif //_VUFORIA_UWP_H_
