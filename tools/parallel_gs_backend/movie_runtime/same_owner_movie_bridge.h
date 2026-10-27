#pragma once
// Hardware producer on the existing GS worker. Compressed PES identity exists
// before original playback assigns a destination in presentation order.
#include "mpeg2_vld_core.h"
#include "import_receipt.h"
#include "movie_asset_sha256.h"
#include "movie_picture_identity.h"
#include "../movie_frame_signal.h"
#include "device.hpp"
#include "command_buffer.hpp"
#include <array>
#include <functional>
#include <limits>
#include <memory>
#include <stdexcept>

namespace reo_gpu_movie {
class SameOwnerMovieBridge {
    enum class OutputState { Free, Produced, Consumed };
    struct Slot {
        ComPtr<ID3D11Texture2D> nv12;
        ComPtr<ID3D11Fence> fence;
        Vulkan::Semaphore timeline;
        Vulkan::ImageHandle imported, rgba;
        Vulkan::ImageViewHandle y, uv, unorm;
        Vulkan::Fence ready, consumed;
        uint64_t value = 0, released = 0, lastD3DReady = 0, serial = 0;
        bool rgbaInitialized = false;
        OutputState state = OutputState::Free;
        MoviePictureIdentity identity{};
    };
    Vulkan::Device& gs_;
    ComPtr<ID3D11Device> decoderDevice_;
    ComPtr<ID3D11DeviceContext4> immediate_;
    Mpeg2VldCore decoder_;
    std::array<std::unique_ptr<Slot>, 3> slots_;
    std::array<uint64_t, 8> surfaceGeneration_{};
    Vulkan::Program* csc_ = nullptr;
    uint64_t generation_ = 0, surfaceSerial_ = 0;
    uint32_t width_ = 0, height_ = 0;
    bool poisoned_ = false, closed_ = false;
    Vulkan::CommandBufferHandle imageBatch_;
    MovieTextureTicket imageBatchTicket_{};
    bool imageBatchFinal_ = false, imageBatchRecorded_ = false;

    static void check(HRESULT hr, const char* message) {
        if (FAILED(hr))
            throw std::runtime_error(message);
    }
    static uint64_t next(Slot& slot) {
        if (slot.value == std::numeric_limits<uint64_t>::max())
            throw std::overflow_error("Movie timeline exhausted");
        return ++slot.value;
    }
    void assertOpen() const {
        if (closed_ || poisoned_)
            throw std::logic_error("Movie owner is closed or failed");
    }
    Slot& match(const MovieTextureTicket& ticket) {
        if (ticket.slot >= slots_.size() || !ticket.gpuSubmitted)
            throw std::invalid_argument("Invalid movie texture ticket");
        auto& slot = *slots_[ticket.slot];
        if (ticket.generation != generation_ || ticket.picture != slot.identity.picture ||
            ticket.slotSerial != slot.serial)
            throw std::invalid_argument("Stale movie texture ticket");
        return slot;
    }
    static void validateIdentity(const MoviePictureIdentity& identity,
                                 const PictureSubmission& submission) {
        if (!identity.generation || !identity.picture || !identity.sofdec || !identity.work ||
            !identity.truePictureBoundaries || !hasMovieProductionTime(identity) ||
            identity.compressedBegin >= identity.compressedEnd ||
            submission.frameFormat != D3D11_VIDEO_FRAME_FORMAT_PROGRESSIVE)
            throw std::invalid_argument(
                "Unjoined movie picture/player identity or unsupported field picture");
    }
    void initializeSlot(Slot& slot, ID3D11Device5* device5) {
        D3D11_TEXTURE2D_DESC texture{};
        texture.Width = width_;
        texture.Height = height_;
        texture.MipLevels = 1;
        texture.ArraySize = 1;
        texture.Format = DXGI_FORMAT_NV12;
        texture.SampleDesc.Count = 1;
        texture.Usage = D3D11_USAGE_DEFAULT;
        texture.BindFlags = D3D11_BIND_DECODER;
        texture.MiscFlags = D3D11_RESOURCE_MISC_SHARED_NTHANDLE | D3D11_RESOURCE_MISC_SHARED;
        check(decoderDevice_->CreateTexture2D(&texture, nullptr, &slot.nv12),
              "Create non-keyed hardware NV12 slot");
        ComPtr<IDXGIResource1> resource;
        check(slot.nv12.As(&resource), "Query shared NV12 resource");
        Vulkan::ExternalHandle memory;
        memory.memory_handle_type = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT;
        check(resource->CreateSharedHandle(nullptr,
                                           DXGI_SHARED_RESOURCE_READ | DXGI_SHARED_RESOURCE_WRITE,
                                           nullptr, &memory.handle),
              "Export NV12 handle");
        // Pinned Granite consumes a by-reference NT handle at its allocation
        // attempt. Initialization failure is fatal to this unenrolled candidate;
        // the required device fixture must audit the early failure handle path.
        Vulkan::ImageCreateInfo info{};
        info.width = width_;
        info.height = height_;
        info.format = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM;
        info.flags = VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
        info.usage = VK_IMAGE_USAGE_SAMPLED_BIT;
        info.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        info.misc =
            Vulkan::IMAGE_MISC_EXTERNAL_MEMORY_BIT | Vulkan::IMAGE_MISC_NO_DEFAULT_VIEWS_BIT;
        info.external = memory;
        {
            reo_movie_import::HandleTransaction receipt(memory.handle);
            slot.imported = gs_.create_image(info);
        }
        if (!slot.imported)
            throw std::runtime_error("Import NV12 on existing GS device");
        for (unsigned plane = 0; plane < 2; ++plane) {
            Vulkan::ImageViewCreateInfo view{};
            view.image = slot.imported.get();
            view.levels = 1;
            view.layers = 1;
            view.view_type = VK_IMAGE_VIEW_TYPE_2D;
            view.format = plane ? VK_FORMAT_R8G8_UNORM : VK_FORMAT_R8_UNORM;
            view.aspect = plane ? VK_IMAGE_ASPECT_PLANE_1_BIT : VK_IMAGE_ASPECT_PLANE_0_BIT;
            auto created = gs_.create_image_view(view);
            if (!created)
                throw std::runtime_error("Create native NV12 plane view");
            if (plane)
                slot.uv = std::move(created);
            else
                slot.y = std::move(created);
        }
        info = {};
        info.width = width_;
        info.height = height_;
        info.format = VK_FORMAT_R8G8B8A8_UINT;
        info.flags = VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT;
        info.usage = VK_IMAGE_USAGE_STORAGE_BIT | VK_IMAGE_USAGE_SAMPLED_BIT |
                     VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        info.initial_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        slot.rgba = gs_.create_image(info);
        if (!slot.rgba)
            throw std::runtime_error("Create exact integer CSC output");
        Vulkan::ImageViewCreateInfo unorm{};
        unorm.image = slot.rgba.get();
        unorm.format = VK_FORMAT_R8G8B8A8_UNORM;
        unorm.levels = 1;
        unorm.layers = 1;
        unorm.aspect = VK_IMAGE_ASPECT_COLOR_BIT;
        unorm.view_type = VK_IMAGE_VIEW_TYPE_2D;
        slot.unorm = gs_.create_image_view(unorm);
        if (!slot.unorm)
            throw std::runtime_error("Create movie compatibility UNORM view");
        check(device5->CreateFence(0, D3D11_FENCE_FLAG_SHARED, IID_PPV_ARGS(&slot.fence)),
              "Create real decode/export fence");
        slot.timeline = gs_.request_semaphore_external(
            VK_SEMAPHORE_TYPE_TIMELINE, VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT);
        if (!slot.timeline)
            throw std::runtime_error("Create GS importable movie timeline");
        Vulkan::ExternalHandle handle;
        handle.semaphore_handle_type = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT;
        check(slot.fence->CreateSharedHandle(nullptr, GENERIC_ALL, nullptr, &handle.handle),
              "Export real decoder fence");
        if (!slot.timeline->import_from_handle(handle)) {
            CloseHandle(handle.handle);
            throw std::runtime_error("Import decoder fence on GS device");
        }
    }

  public:
    SameOwnerMovieBridge(Vulkan::Device& activeGs, ID3D11Device* decoderDevice, uint64_t generation,
                         uint32_t width, uint32_t height, const std::vector<uint32_t>& exactCsc)
        : gs_(activeGs), decoderDevice_(decoderDevice), generation_(generation), width_(width),
          height_(height) {
        if (reo_movie_import::provider_version() != 1)
            throw std::runtime_error("Unsupported pinned import receipt provider");
        if (!decoderDevice || !generation || !width || !height || (width & 15) || (height & 15) ||
            width > 1920 || height > 1088)
            throw std::invalid_argument("Unmeasured/unsupported movie sequence geometry");
        const auto& features = gs_.get_device_features();
        if (!features.supports_external || !features.vk12_features.timelineSemaphore ||
            !features.vk11_props.deviceLUIDValid)
            throw std::runtime_error("Active GS lacks external timeline/LUID support");
        ComPtr<IDXGIDevice> dxgi;
        ComPtr<IDXGIAdapter> adapter;
        DXGI_ADAPTER_DESC desc{};
        check(decoderDevice_.As(&dxgi), "Query decoder DXGI device");
        check(dxgi->GetAdapter(&adapter), "Query decoder adapter");
        check(adapter->GetDesc(&desc), "Read decoder hardware LUID");
        if (std::memcmp(&desc.AdapterLuid, features.vk11_props.deviceLUID, VK_LUID_SIZE))
            throw std::invalid_argument("Movie decoder LUID differs from actual GS device");
        ComPtr<ID3D11Device5> device5;
        check(decoderDevice_.As(&device5), "Query actual decoder Device5");
        ComPtr<ID3D11DeviceContext> context;
        decoderDevice_->GetImmediateContext(&context);
        check(context.As(&immediate_), "Query actual decoder Context4");
        if (immediate_->GetType() != D3D11_DEVICE_CONTEXT_IMMEDIATE)
            throw std::runtime_error("Expected real immediate decoder context");
        check(decoder_.initialize(decoderDevice, width, height, 8),
              "Initialize full hardware MPEG2 VLD");
        if (exactCsc.size() < 5 || exactCsc.size() > 16384 || exactCsc[0] != 0x07230203)
            throw std::invalid_argument("Missing certified IPU CSC SPIR-V");
        std::vector<uint8_t> shaderBytes(exactCsc.size() * 4);
        std::memcpy(shaderBytes.data(), exactCsc.data(), shaderBytes.size());
        if (reo_gpu_movie_asset::sha256(shaderBytes) !=
            "cb5ed3a99141ff571222c2d46c55d2bd54134033fd5f131002c419c5562d17a8")
            throw std::invalid_argument(
                "Movie CSC binary differs from actually proved integer shader");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].sampled_image_mask = 3;
        layout.sets[0].fp_mask = 3;
        layout.sets[0].storage_image_mask = 4;
        layout.push_constant_size = 16;
        for (unsigned i = 0; i < 3; ++i)
            layout.sets[0].meta[i].array_size = 1;
        csc_ = gs_.request_program(exactCsc.data(), exactCsc.size() * 4, &layout);
        if (!csc_ || !csc_->get_pipeline_layout())
            throw std::runtime_error("Create same-device exact CSC pipeline");
        const auto& actual = csc_->get_pipeline_layout()->get_resource_layout();
        if (actual.descriptor_set_mask != 1 || actual.bindless_descriptor_set_mask ||
            actual.sets[0].sampled_image_mask != 3 || actual.sets[0].storage_image_mask != 4 ||
            actual.sets[0].fp_mask != 3 ||
            actual.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT ||
            actual.push_constant_range.size != 16 || actual.push_constant_range.offset ||
            actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Unexpected exact CSC resource interface");
        for (unsigned i = 0; i < 3; ++i)
            if (actual.sets[0].meta[i].array_size != 1 ||
                actual.stages_for_bindings[0][i] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Unexpected CSC binding/array stage");
        // Populate the actual Device driver cache before the first picture.
        // This empty owner command contains no image work or guessed frame.
        auto warm = gs_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        warm->set_program(csc_);
        Vulkan::DeferredPipelineCompile compilation{};
        warm->extract_pipeline_state(compilation);
        auto pipeline = csc_->get_pipeline(compilation.hash);
        if (pipeline.pipeline == VK_NULL_HANDLE)
            pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                &gs_, compilation, Vulkan::CommandBuffer::CompileMode::Sync);
        if (pipeline.pipeline == VK_NULL_HANDLE) {
            gs_.submit_discard(warm);
            throw std::runtime_error("Movie CSC same-device precompilation failed");
        }
        gs_.submit(warm);
        for (auto& slot : slots_) {
            slot = std::make_unique<Slot>();
            initializeSlot(*slot, device5.Get());
        }
    }
    SameOwnerMovieBridge(const SameOwnerMovieBridge&) = delete;
    ~SameOwnerMovieBridge() {
        if (!closed_)
            shutdown();
    }

    // Returns false for genuine output backpressure. No busy bit/completion is
    // modified. Input boundaries/PTS remain explicit caller authority.
    bool enqueue(const MoviePictureIdentity& identity, const PictureSubmission& submission,
                 uint32_t th0, uint32_t th1, MovieTextureTicket& ticket) {
        assertOpen();
        validateIdentity(identity, submission);
        if (identity.generation != generation_)
            throw std::invalid_argument("Stale movie generation");
        if (submission.picture.wPicWidthInMBminus1 != width_ / 16 - 1 ||
            submission.picture.wPicHeightInMBminus1 != height_ / 16 - 1 ||
            submission.picture.bPicStructure != 3 || submission.picture.bChromaFormat != 1)
            throw std::invalid_argument(
                "MPEG picture geometry/structure differs from actual sequence");
        const auto decoded = submission.picture.wDecodedPictureIndex;
        if (decoded >= surfaceGeneration_.size())
            throw std::invalid_argument("Decoder output outside resident surface pool");
        const auto validateReference = [&](uint16_t surface, uint64_t expected) {
            if (surface == 0xffff) {
                if (expected)
                    throw std::invalid_argument("Spurious MPEG reference generation");
                return;
            }
            if (surface >= surfaceGeneration_.size() || surface == decoded || !expected ||
                surfaceGeneration_[surface] != expected)
                throw std::invalid_argument("Missing/stale/overwritten MPEG reference surface");
        };
        validateReference(submission.picture.wForwardRefPictureIndex, identity.forwardGeneration);
        validateReference(submission.picture.wBackwardRefPictureIndex, identity.backwardGeneration);
        unsigned selected = unsigned(slots_.size());
        for (unsigned i = 0; i < slots_.size(); ++i) {
            auto& candidate = *slots_[i];
            if (candidate.state == OutputState::Free) {
                selected = i;
                break;
            }
        }
        if (selected == slots_.size())
            return false;
        auto& slot = *slots_[selected];
        if (surfaceSerial_ == std::numeric_limits<uint64_t>::max() ||
            slot.serial == std::numeric_limits<uint64_t>::max())
            throw std::overflow_error("Movie surface/ticket generation exhausted");
        // A slot-local timeline prevents a later D3D write from signaling past
        // an earlier Vulkan release. Separate slots may remain in flight.
        Vulkan::CommandBufferHandle pendingCommand;
        try {
            if (slot.released)
                check(immediate_->Wait(slot.fence.Get(), slot.released),
                      "Queue wait before shared NV12 reuse");
            check(decoder_.enqueueDecode(submission), "Submit actual full compressed MPEG picture");
            surfaceGeneration_[decoded] = ++surfaceSerial_;
            immediate_->CopySubresourceRegion(slot.nv12.Get(), 0, 0, 0, 0,
                                              decoder_.decoderSurfaceArray(), decoded, nullptr);
            slot.lastD3DReady = next(slot);
            check(immediate_->Signal(slot.fence.Get(), slot.lastD3DReady),
                  "Signal actual decode and NV12 copy");
            immediate_->Flush();
            auto wait = gs_.request_timeline_semaphore_as_binary(*slot.timeline, slot.lastD3DReady);
            if (!wait)
                throw std::runtime_error("Create true decode-ready timeline wait");
            // Allocate both views before any queue submission; failure does not
            // publish a guest completion or allow CPU decoding.
            slot.released = next(slot);
            auto signal = gs_.request_timeline_semaphore_as_binary(*slot.timeline, slot.released);
            if (!signal)
                throw std::runtime_error("Create true NV12 release timeline signal");
            pendingCommand = gs_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
            auto& cmd = pendingCommand;
            cmd->acquire_image_barrier(
                *slot.imported, VK_IMAGE_LAYOUT_GENERAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
                VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT, VK_ACCESS_2_SHADER_SAMPLED_READ_BIT,
                VK_QUEUE_FAMILY_EXTERNAL);
            cmd->image_barrier(*slot.rgba,
                               slot.rgbaInitialized ? VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
                                                    : VK_IMAGE_LAYOUT_UNDEFINED,
                               VK_IMAGE_LAYOUT_GENERAL, VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,
                               slot.rgbaInitialized ? VK_ACCESS_2_MEMORY_READ_BIT : 0,
                               VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd->set_program(csc_);
            cmd->set_texture(0, 0, *slot.y, Vulkan::StockSampler::NearestClamp);
            cmd->set_texture(0, 1, *slot.uv, Vulkan::StockSampler::NearestClamp);
            cmd->set_storage_texture(0, 2, slot.rgba->get_view());
            const uint32_t push[4]{width_, height_, th0, th1};
            cmd->push_constants(push, 0, sizeof(push));
            cmd->dispatch((width_ + 15) / 16, (height_ + 15) / 16, 1);
            cmd->image_barrier(
                *slot.rgba, VK_IMAGE_LAYOUT_GENERAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
                VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT, VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT,
                VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT, VK_ACCESS_2_MEMORY_READ_BIT);
            cmd->release_image_barrier(
                *slot.imported, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, VK_IMAGE_LAYOUT_GENERAL,
                VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT, VK_ACCESS_2_SHADER_SAMPLED_READ_BIT,
                VK_QUEUE_FAMILY_EXTERNAL);
            wait->signal_external();
            gs_.add_wait_semaphore(Vulkan::CommandBuffer::Type::Generic, std::move(wait),
                                   VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT, true);
            gs_.submit(cmd);
            gs_.submit_empty(Vulkan::CommandBuffer::Type::Generic, &slot.ready, signal.get());
            slot.identity = identity;
            slot.serial++;
            slot.state = OutputState::Produced;
            reo_gpu_present::gpuMovieFrames.fetch_add(1, std::memory_order_relaxed);
            slot.rgbaInitialized = true;
            ticket = {generation_, identity.picture, slot.serial, selected, identity.pts90k, true};
            return true;
        } catch (...) {
            if (pendingCommand)
                gs_.submit_discard(pendingCommand);
            poisoned_ = true;
            throw;
        }
    }
    uint64_t surfaceGeneration(unsigned surface) const {
        return surface < surfaceGeneration_.size() ? surfaceGeneration_[surface] : 0;
    }
    bool ready(const MovieTextureTicket& ticket) {
        assertOpen();
        auto& slot = match(ticket);
        return slot.ready && slot.ready->wait_timeout(0);
    }
    void bindOriginalPlayerTime(MovieTextureTicket& ticket, uint32_t referenceMetadata,
                                int64_t originalPts, bool absent = false) {
        assertOpen();
        auto& slot = match(ticket);
        if (slot.state != OutputState::Produced || !slot.ready || !slot.ready->wait_timeout(0))
            throw std::logic_error("Original timestamp preceded its real producer completion");
        bindOriginalMovieTime(slot.identity, ticket, referenceMetadata, originalPts, absent);
    }
    bool consumed(const MovieTextureTicket& ticket) {
        assertOpen();
        auto& slot = match(ticket);
        return slot.state == OutputState::Consumed && slot.consumed &&
               slot.consumed->wait_timeout(0);
    }
    // A caller must cache its actual DMA completion before this explicit
    // retirement frees the texture slot. enqueue must never independently
    // observe a fence and invalidate a caller's still-unacknowledged receipt.
    bool retireConsumed(const MovieTextureTicket& ticket) {
        assertOpen();
        auto& slot = match(ticket);
        if (slot.state != OutputState::Consumed || !slot.consumed ||
            !slot.consumed->wait_timeout(0))
            return false;
        slot.consumed.reset();
        slot.state = OutputState::Free;
        return true;
    }

    // An authentic original queue release may discard a produced frame without
    // displaying it. It is not an IMAGE receipt. Keep MPEG reference surfaces;
    // these slot-local NV12/RGBA copies retire only after their real work/reads.
    void releaseOriginalFrame(const MovieTextureTicket& ticket) {
        assertOpen();
        auto& slot = match(ticket);
        if (slot.state != OutputState::Produced ||
            (imageBatch_ && imageBatchTicket_.generation == ticket.generation &&
             imageBatchTicket_.picture == ticket.picture &&
             imageBatchTicket_.slotSerial == ticket.slotSerial))
            throw std::logic_error("Original frame release crossed an active/final IMAGE consumer");
        if (!slot.ready)
            throw std::logic_error("Original frame release lost its real producer fence");
        slot.ready->wait();
        if (slot.consumed)
            slot.consumed->wait();
        slot.consumed.reset();
        slot.ready.reset();
        slot.state = OutputState::Free;
    }

    // A source-joined original movie IMAGE replacement appends its GPU write to
    // the original GS VRAM destination here, in original FIFO order. The source
    // is the exact UINT image. ALL source reads must occur in this Generic
    // command, restoring SHADER_READ_ONLY layout before returning. It may
    // never download/reconstruct guest picture RAM. Absent that join, no live
    // consumer is installed. Binding a texture for future draws needs a longer
    // explicit lease and is not covered by this one-shot copy interface.
    // Existing GPU scanout then presents the original GS composition.
    void consume(const MovieTextureTicket& ticket,
                 const std::function<void(Vulkan::CommandBuffer&, const Vulkan::ImageView&,
                                          const MoviePictureIdentity&)>& record) {
        assertOpen();
        auto& slot = match(ticket);
        if (slot.state != OutputState::Produced || !record || !hasMovieConsumerTime(slot.identity))
            throw std::logic_error("Movie texture lacks real ordered consumer/player timestamp");
        auto cmd = gs_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        try {
            record(*cmd, slot.rgba->get_view(), slot.identity);
            gs_.submit(cmd, &slot.consumed);
            slot.state = OutputState::Consumed;
        } catch (...) {
            if (cmd)
                gs_.submit_discard(cmd);
            poisoned_ = true;
            throw;
        }
    }
    // Multiple genuine IMAGE/REF fragments can consume one original IPU
    // macroblock-ordered output. Every fragment receives its own actual fence;
    // the texture remains Produced until the caller proves complete source
    // coverage. The final fence owns all earlier Generic reads of this image.
    Vulkan::Fence
    consumePart(const MovieTextureTicket& ticket, bool final,
                const std::function<void(Vulkan::CommandBuffer&, const Vulkan::ImageView&,
                                         const MoviePictureIdentity&)>& record) {
        assertOpen();
        auto& slot = match(ticket);
        if (slot.state != OutputState::Produced || !record || !hasMovieConsumerTime(slot.identity))
            throw std::logic_error(
                "Movie fragment lacks retained original resident image/player timestamp");
        auto command = gs_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        Vulkan::Fence completion;
        try {
            record(*command, slot.rgba->get_view(), slot.identity);
            gs_.submit(command, &completion);
            slot.consumed = completion;
            if (final)
                slot.state = OutputState::Consumed;
            return completion;
        } catch (...) {
            if (command)
                gs_.submit_discard(command);
            poisoned_ = true;
            throw;
        }
    }
    // One authentic same-picture D2 chain span records to this retained Generic
    // command. Its caller proves no drawing/VRAM use can occur inside the span.
    // No submission or completion is inferred by an individual fragment.
    void beginConsumerBatch(const MovieTextureTicket& ticket) {
        assertOpen();
        auto& slot = match(ticket);
        if (imageBatch_ || slot.state != OutputState::Produced ||
            !hasMovieConsumerTime(slot.identity) || !slot.ready || !slot.ready->wait_timeout(0))
            throw std::logic_error("Movie batch lacks a completed timestamped producer");
        imageBatch_ = gs_.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        imageBatchTicket_ = ticket;
        imageBatchFinal_ = imageBatchRecorded_ = false;
    }
    void
    recordConsumerBatch(const MovieTextureTicket& ticket, bool final,
                        const std::function<void(Vulkan::CommandBuffer&, const Vulkan::ImageView&,
                                                 const MoviePictureIdentity&)>& record) {
        assertOpen();
        auto& slot = match(ticket);
        if (!imageBatch_ || imageBatchTicket_.generation != ticket.generation ||
            imageBatchTicket_.picture != ticket.picture ||
            imageBatchTicket_.slotSerial != ticket.slotSerial || imageBatchFinal_ ||
            slot.state != OutputState::Produced || !record || !hasMovieConsumerTime(slot.identity))
            throw std::logic_error("Movie batch fragment crossed its retained producer");
        try {
            record(*imageBatch_, slot.rgba->get_view(), slot.identity);
            imageBatchRecorded_ = true;
            imageBatchFinal_ = final;
        } catch (...) {
            if (imageBatch_)
                gs_.submit_discard(imageBatch_);
            poisoned_ = true;
            throw;
        }
    }
    Vulkan::Fence endConsumerBatch(const MovieTextureTicket& ticket) {
        assertOpen();
        auto& slot = match(ticket);
        if (!imageBatch_ || !imageBatchRecorded_ ||
            imageBatchTicket_.generation != ticket.generation ||
            imageBatchTicket_.picture != ticket.picture ||
            imageBatchTicket_.slotSerial != ticket.slotSerial ||
            slot.state != OutputState::Produced)
            throw std::logic_error("Movie batch cannot publish an absent/foreign command");
        Vulkan::Fence completion;
        try {
            gs_.submit(imageBatch_, &completion);
            if (!completion)
                throw std::runtime_error("Movie batch submit lacks its real fence");
            slot.consumed = completion;
            if (imageBatchFinal_)
                slot.state = OutputState::Consumed;
            imageBatchTicket_ = {};
            imageBatchFinal_ = imageBatchRecorded_ = false;
            return completion;
        } catch (...) {
            if (imageBatch_)
                gs_.submit_discard(imageBatch_);
            poisoned_ = true;
            throw;
        }
    }
    // STOP/RESET/owner teardown only. Scoped real fences retain references,
    // images and outputs; normal frames do not wait on CPU or call wait_idle.
    void shutdown() noexcept {
        if (closed_)
            return;
        if (imageBatch_)
            gs_.submit_discard(imageBatch_);
        imageBatchTicket_ = {};
        imageBatchFinal_ = imageBatchRecorded_ = false;
        // A failed transaction may have appended a real wait or command before
        // obtaining its normal receipt. Drain that queue scope with an actual
        // fence; this is STOP/error cleanup, never normal-frame completion.
        if (poisoned_) {
            Vulkan::Fence cleanup;
            gs_.submit_empty(Vulkan::CommandBuffer::Type::Generic, &cleanup);
            if (cleanup)
                cleanup->wait();
        }
        for (auto& owned : slots_)
            if (owned) {
                auto& slot = *owned;
                if (slot.consumed)
                    slot.consumed->wait();
                else if (slot.ready)
                    slot.ready->wait();
                // Even a partially failed DecoderEndFrame must retain all surfaces
                // until the immediate decoder queue has really retired.
                if (slot.fence && immediate_) {
                    if (slot.value == std::numeric_limits<uint64_t>::max())
                        std::terminate();
                    const auto retirement = ++slot.value;
                    const auto signal = immediate_->Signal(slot.fence.Get(), retirement);
                    immediate_->Flush();
                    if (FAILED(signal) && SUCCEEDED(decoderDevice_->GetDeviceRemovedReason()))
                        std::terminate();
                    if (SUCCEEDED(signal) && slot.fence->GetCompletedValue() < retirement) {
                        HANDLE event = CreateEventW(nullptr, FALSE, FALSE, nullptr);
                        if (!event || FAILED(slot.fence->SetEventOnCompletion(retirement, event)))
                            std::terminate();
                        const auto waited = WaitForSingleObject(event, INFINITE);
                        CloseHandle(event);
                        if (waited != WAIT_OBJECT_0)
                            std::terminate();
                    }
                }
                slot.consumed.reset();
                slot.ready.reset();
                slot.timeline.reset();
                slot.fence.Reset();
                slot.unorm.reset();
                slot.y.reset();
                slot.uv.reset();
                slot.rgba.reset();
                slot.imported.reset();
                slot.nv12.Reset();
            }
        closed_ = true;
    }
};
} // namespace reo_gpu_movie
