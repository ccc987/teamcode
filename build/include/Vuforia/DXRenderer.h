/*===============================================================================
Copyright (c) 2018 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.

@file 
    DXRenderer.h

@brief
    Header file for DX renderer classes.
===============================================================================*/

#ifndef _VUFORIA_DXRENDERER_H_
#define _VUFORIA_DXRENDERER_H_

// Include files
#include <Vuforia/Renderer.h>
#include <wrl/client.h>
#include <d3d11.h>

namespace Vuforia 
{

// DirectX-specific classes

/// DirectX-specific texture data.
/**
 * DXTextureData object passed to Vuforia to set the DX texture info of the video
 * background texture created by the app.
 *
 * Use with Renderer::setVideoBackgroundTexture() and in conjunction
 * with Renderer::updateVideoBackgroundTexture().
 */
class VUFORIA_API DXTextureData : public TextureData
{
public:
    /// Convenience constructor
    /**
     * \param texture2D The texture object to use.
     */
    DXTextureData(ID3D11Texture2D* texture2D);
    DXTextureData();
    ~DXTextureData();

    virtual const void* buffer() const;

    struct {
        Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture2D;
    } mData;
};

/// DirectX-specific rendering data.
/**
 * DXRenderData object passed to %Vuforia when performing DirectX rendering
 * operations. Pass a pointer to the current Direct3D 11 rendering device
 * in mD3D11Device.
 *
 * Use with Renderer::begin() and Renderer::end().
 */
class VUFORIA_API DXRenderData : public RenderData
{
public:
    DXRenderData();
    DXRenderData(ID3D11Device* d3d11Device);
    ~DXRenderData();

    virtual const void* buffer() const;

    Microsoft::WRL::ComPtr<ID3D11Device> mD3D11Device;
};

} // namespace Vuforia

#endif //_VUFORIA_DXRENDERER_H_
