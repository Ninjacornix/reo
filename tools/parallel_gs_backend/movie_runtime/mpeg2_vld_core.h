#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <d3d11_4.h>
#include <dxgi1_2.h>
#include <dxva.h>
#include <wrl/client.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <vector>
#include <utility>

namespace reo_gpu_movie {
using Microsoft::WRL::ComPtr;
// Exact Windows SDK dxva.h no-encryption GUID; dxguid.lib has no definition.
constexpr GUID noEncrypt = {
    0x1b81bed0, 0xa0c7, 0x11d3, {0xb9, 0x84, 0x00, 0xc0, 0x4f, 0x2e, 0x73, 0xc5}};

// Metadata and compressed bytes are command input. No coefficient, motion,
// IDCT, pixel, color-conversion, scaling or blending math runs on the host here.
// The elementary-stream parser must supply the documented DXVA MPEG-2 fields;
// it is not included in this proposal and no game call is bypassed by this API.
struct PictureSubmission {
    DXVA_PictureParameters picture{};
    DXVA_QmatrixData quantizers{};
    const DXVA_SliceInfo* slices = nullptr;
    UINT sliceCount = 0;
    const uint8_t* compressed = nullptr;
    UINT compressedBytes = 0;
    int64_t presentationTime100ns = 0;
    D3D11_VIDEO_FRAME_FORMAT frameFormat = D3D11_VIDEO_FRAME_FORMAT_PROGRESSIVE;
};

// All methods use the caller's serialized video owner. Caller retains decode
// reference surfaces and exported output slots until every referencing command
// has completed. This class never destroys a surface at individual frame EOF.
class Mpeg2VldCore {
    ComPtr<ID3D11Device> device_;
    ComPtr<ID3D11DeviceContext> context_;
    ComPtr<ID3D11VideoDevice> video_;
    ComPtr<ID3D11VideoContext> videoContext_;
    ComPtr<ID3D11VideoDecoder> decoder_;
    ComPtr<ID3D11Texture2D> nv12_;
    std::vector<ComPtr<ID3D11VideoDecoderOutputView>> decoderViews_;
    UINT width_ = 0, height_ = 0;
    bool live_ = false;

    HRESULT copyCompressedControl(D3D11_VIDEO_DECODER_BUFFER_TYPE type, const void* bytes,
                                  UINT count, D3D11_VIDEO_DECODER_BUFFER_DESC& desc) {
        UINT capacity = 0;
        void* dst = nullptr;
        auto hr = videoContext_->GetDecoderBuffer(decoder_.Get(), type, &capacity, &dst);
        if (FAILED(hr))
            return hr;
        if (!dst || count > capacity)
            hr = E_BOUNDS;
        else
            std::memcpy(dst, bytes, count);
        const auto released = videoContext_->ReleaseDecoderBuffer(decoder_.Get(), type);
        if (FAILED(hr))
            return hr;
        if (FAILED(released))
            return released;
        desc = {};
        desc.BufferType = type;
        desc.DataSize = count;
        return S_OK;
    }

  public:
    Mpeg2VldCore() = default;
    Mpeg2VldCore(const Mpeg2VldCore&) = delete;
    Mpeg2VldCore& operator=(const Mpeg2VldCore&) = delete;

    // Pass the D3D11 device whose adapter LUID equals the active Vulkan device.
    // These capabilities must also have passed the root's hardware profile probe.
    // A VLD decoder is mandatory: MOCOMP/IDCT profiles are deliberately rejected.
    HRESULT initialize(ID3D11Device* device, UINT width, UINT height, UINT surfaces = 8) {
        if (live_ || !device || !width || !height || (width & 1) || (height & 1) || width > 1920 ||
            height > 1088 || surfaces < 3 || surfaces > 32)
            return E_INVALIDARG;
        device_ = device;
        device_->GetImmediateContext(&context_);
        auto hr = device_.As(&video_);
        if (FAILED(hr))
            return hr;
        hr = context_.As(&videoContext_);
        if (FAILED(hr))
            return hr;
        const GUID profiles[] = {D3D11_DECODER_PROFILE_MPEG2_VLD,
                                 D3D11_DECODER_PROFILE_MPEG2and1_VLD};
        GUID chosen{};
        D3D11_VIDEO_DECODER_CONFIG config{};
        bool found = false;
        auto plain = [](const GUID& g) {
            return IsEqualGUID(g, noEncrypt) || IsEqualGUID(g, GUID_NULL);
        };
        for (const auto& profile : profiles) {
            BOOL format = FALSE;
            hr = video_->CheckVideoDecoderFormat(&profile, DXGI_FORMAT_NV12, &format);
            if (FAILED(hr) || !format)
                continue;
            D3D11_VIDEO_DECODER_DESC desc{profile, width, height, DXGI_FORMAT_NV12};
            UINT count = 0;
            hr = video_->GetVideoDecoderConfigCount(&desc, &count);
            if (FAILED(hr))
                continue;
            for (UINT i = 0; i < count; ++i) {
                hr = video_->GetVideoDecoderConfig(&desc, i, &config);
                if (FAILED(hr))
                    continue;
                if (config.ConfigBitstreamRaw != 1 ||
                    !plain(config.guidConfigBitstreamEncryption) ||
                    !plain(config.guidConfigMBcontrolEncryption) ||
                    !plain(config.guidConfigResidDiffEncryption))
                    continue;
                if (config.ConfigMinRenderTargetBuffCount > surfaces)
                    continue;
                hr = video_->CreateVideoDecoder(&desc, &config, &decoder_);
                if (SUCCEEDED(hr)) {
                    chosen = profile;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found)
            return DXGI_ERROR_UNSUPPORTED;
        D3D11_TEXTURE2D_DESC td{};
        td.Width = width;
        td.Height = height;
        td.MipLevels = 1;
        td.ArraySize = surfaces;
        td.Format = DXGI_FORMAT_NV12;
        td.SampleDesc.Count = 1;
        td.Usage = D3D11_USAGE_DEFAULT;
        td.BindFlags = D3D11_BIND_DECODER;
        hr = device_->CreateTexture2D(&td, nullptr, &nv12_);
        if (FAILED(hr))
            return hr;
        decoderViews_.resize(surfaces);
        for (UINT i = 0; i < surfaces; ++i) {
            D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC dv{};
            dv.DecodeProfile = chosen;
            dv.ViewDimension = D3D11_VDOV_DIMENSION_TEXTURE2D;
            dv.Texture2D.ArraySlice = i;
            hr = video_->CreateVideoDecoderOutputView(nv12_.Get(), &dv, &decoderViews_[i]);
            if (FAILED(hr))
                return hr;
        }
        width_ = width;
        height_ = height;
        live_ = true;
        return S_OK;
    }

    HRESULT enqueueDecode(const PictureSubmission& in) {
        if (!live_ || !in.compressed || !in.compressedBytes ||
            in.compressedBytes > 16u * 1024u * 1024u || !in.slices || !in.sliceCount ||
            in.sliceCount > 65535)
            return E_INVALIDARG;
        if (in.picture.wDecodedPictureIndex >= decoderViews_.size())
            return E_BOUNDS;
        for (const auto ref :
             {in.picture.wForwardRefPictureIndex, in.picture.wBackwardRefPictureIndex})
            if (ref != 0xffff && ref >= decoderViews_.size())
                return E_BOUNDS;
        auto hr = videoContext_->DecoderBeginFrame(
            decoder_.Get(), decoderViews_[in.picture.wDecodedPictureIndex].Get(), 0, nullptr);
        if (FAILED(hr))
            return hr;
        D3D11_VIDEO_DECODER_BUFFER_DESC desc[4]{};
        hr = copyCompressedControl(D3D11_VIDEO_DECODER_BUFFER_PICTURE_PARAMETERS, &in.picture,
                                   sizeof(in.picture), desc[0]);
        if (SUCCEEDED(hr))
            hr = copyCompressedControl(D3D11_VIDEO_DECODER_BUFFER_INVERSE_QUANTIZATION_MATRIX,
                                       &in.quantizers, sizeof(in.quantizers), desc[1]);
        if (SUCCEEDED(hr))
            hr = copyCompressedControl(D3D11_VIDEO_DECODER_BUFFER_SLICE_CONTROL, in.slices,
                                       in.sliceCount * UINT(sizeof(DXVA_SliceInfo)), desc[2]);
        if (SUCCEEDED(hr))
            hr = copyCompressedControl(D3D11_VIDEO_DECODER_BUFFER_BITSTREAM, in.compressed,
                                       in.compressedBytes, desc[3]);
        const UINT macroblocks = (UINT(in.picture.wPicWidthInMBminus1) + 1) *
                                 (UINT(in.picture.wPicHeightInMBminus1) + 1);
        desc[2].NumMBsInBuffer = macroblocks;
        desc[3].NumMBsInBuffer = macroblocks;
        if (SUCCEEDED(hr))
            hr = videoContext_->SubmitDecoderBuffers(decoder_.Get(), 4, desc);
        const auto end = videoContext_->DecoderEndFrame(decoder_.Get());
        return FAILED(hr) ? hr : end;
    }

    ID3D11Texture2D* decoderSurfaceArray() const {
        return nv12_.Get();
    }
    UINT width() const {
        return width_;
    }
    UINT height() const {
        return height_;
    }
};
} // namespace reo_gpu_movie
