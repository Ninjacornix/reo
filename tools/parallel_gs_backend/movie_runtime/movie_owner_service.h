#pragma once
#include "native_movie_owner.h"
#include "live_movie_producer.h"
#include "gs_interface.hpp"
#include "../resident_gs/resident_image_upload.hpp"
#include "thread_id.hpp"
#include <atomic>
#include <filesystem>
#include <fstream>
#include <thread>

namespace reo_gpu_movie {
// Constructed, called and destroyed on the existing real GS worker. Runtime's
// private FIFO stores only its Target marker and immutable CPU control jobs.
// Decoded images never leave the same Vulkan Device / matched decoder LUID.
class MovieOwnerServiceTarget final : public reo_movie_owner::Target {
    struct ThreadIndexScope {
        unsigned previous = Util::get_current_thread_index();
        ThreadIndexScope() {
            Util::register_thread_index(0);
        }
        ~ThreadIndexScope() {
            Util::register_thread_index(previous);
        }
    };
    Vulkan::Device& gs_;
    ParallelGS::GSInterface& renderer_;
    const uint64_t epoch_;
    std::atomic<bool> healthy_{true};
    ComPtr<ID3D11Device> decoder_;
    std::function<void(uint32_t)> imageConsumed_;
    std::vector<uint32_t> csc_;
    Vulkan::Program* upload_ = nullptr;
    std::shared_ptr<LiveMovieProducer> movie_;
    MovieSessionOwner owner_{};
    uint32_t inner_ = 0, width_ = 0, height_ = 0;
    std::optional<ParallelGS::ResidentImageBatch> imageBatch_;
    void ownerThread() const {
        requireHealthy();
        if (!reo_movie_owner::onActualOwnerThread())
            throw std::logic_error("Movie graphics operation is outside actual GS owner thread");
    }
    void movie(uint64_t generation) const {
        ownerThread();
        if (!movie_ || generation != owner_.generation)
            throw std::invalid_argument("Movie operation has no live same-device generation");
    }
    static void check(HRESULT status, const char* text) {
        if (FAILED(status))
            throw std::runtime_error(text);
    }
    static std::vector<uint32_t> shader(const std::filesystem::path& path) {
        std::ifstream input(path, std::ios::binary | std::ios::ate);
        if (!input)
            throw std::runtime_error("Missing certified native movie shader asset");
        const auto bytes = input.tellg();
        if (bytes < 20 || bytes > 65536 || (uint64_t(bytes) & 3))
            throw std::runtime_error("Native movie shader size");
        std::vector<uint32_t> result(size_t(bytes) / 4);
        input.seekg(0);
        input.read(reinterpret_cast<char*>(result.data()), bytes);
        if (!input || result[0] != 0x07230203)
            throw std::runtime_error("Native movie shader read/format");
        return result;
    }
    void initializePrograms() {
        if (upload_)
            return;
        // Source/build tree asset IO only. Both helpers independently hash the
        // exact certified shader bytes and validate their resource interfaces.
        const auto directory = std::filesystem::path(__FILE__).parent_path();
        csc_ = shader(directory / "assets/movie_ipu_csc_nv12.spv");
        upload_ = ParallelGS::create_resident_image_upload_program(
            gs_, shader(directory / "../resident_gs/shaders/resident_image_upload.spv"));
        if (!upload_)
            throw std::runtime_error("Create actual GS movie IMAGE upload program");
    }
    void initializeDecoder() {
        if (decoder_)
            return;
        const auto& features = gs_.get_device_features();
        if (!features.vk11_props.deviceLUIDValid)
            throw std::runtime_error("Actual GS device lacks a decoder adapter LUID");
        ComPtr<IDXGIFactory1> factory;
        check(CreateDXGIFactory1(IID_PPV_ARGS(&factory)), "Create native movie DXGI factory");
        ComPtr<IDXGIAdapter1> selected;
        for (UINT index = 0;; ++index) {
            ComPtr<IDXGIAdapter1> candidate;
            const auto status = factory->EnumAdapters1(index, &candidate);
            if (status == DXGI_ERROR_NOT_FOUND)
                break;
            check(status, "Enumerate native movie hardware adapter");
            DXGI_ADAPTER_DESC1 description{};
            check(candidate->GetDesc1(&description), "Read native decoder adapter LUID");
            if (!(description.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) &&
                !std::memcmp(&description.AdapterLuid, features.vk11_props.deviceLUID,
                             VK_LUID_SIZE)) {
                selected = candidate;
                break;
            }
        }
        if (!selected)
            throw std::runtime_error("No hardware MPEG decoder on actual GS adapter LUID");
        ComPtr<ID3D11DeviceContext> immediate;
        check(
            D3D11CreateDevice(selected.Get(), D3D_DRIVER_TYPE_UNKNOWN, nullptr,
                              D3D11_CREATE_DEVICE_VIDEO_SUPPORT | D3D11_CREATE_DEVICE_BGRA_SUPPORT,
                              nullptr, 0, D3D11_SDK_VERSION, &decoder_, nullptr, &immediate),
            "Create same-adapter native MPEG decoder");
    }

  public:
    MovieOwnerServiceTarget(Vulkan::Device& gs, ParallelGS::GSInterface& renderer, uint64_t epoch,
                            std::function<void(uint32_t)> imageConsumed = {})
        : gs_(gs), renderer_(renderer), epoch_(epoch), imageConsumed_(std::move(imageConsumed)) {
        if (!epoch)
            throw std::invalid_argument("Movie owner needs actual GS epoch");
    }
    ~MovieOwnerServiceTarget() override {
        stop();
    }
    uint64_t epoch() const noexcept override {
        return epoch_;
    }
    const void* deviceIdentity() const noexcept override {
        return &gs_;
    }
    void requireHealthy() const override {
        if (!healthy_.load(std::memory_order_acquire))
            throw std::runtime_error("Actual GS movie owner service failed");
    }
    void runControl(const std::function<void(reo_movie_owner::Target&)>& call) override {
        ownerThread();
        ThreadIndexScope index;
        if (!call)
            throw std::invalid_argument("Missing native movie owner control");
        call(*this);
    }
    void stop() noexcept override {
        ThreadIndexScope index;
        healthy_.store(false, std::memory_order_release);
        imageBatch_.reset();
        if (movie_) {
            movie_->cancel();
            movie_.reset();
        }
        decoder_.Reset();
        csc_.clear();
        upload_ = nullptr;
        owner_ = {};
        inner_ = width_ = height_ = 0;
    }
    // Returns only a stable CPU compressed-input endpoint. Its numerical and
    // resident-image methods below remain restricted to this exact GS thread.
    LiveMovieProducer* open(MovieSessionOwner owner, uint32_t inner, uint32_t width,
                            uint32_t height) {
        ownerThread();
        if (movie_) {
            if (owner.generation == owner_.generation && owner.sofdec == owner_.sofdec &&
                owner.work == owner_.work && inner == inner_ && width == width_ &&
                height == height_)
                return movie_.get();
            throw std::logic_error("Native movie generation must retire before replacement");
        }
        try {
            initializePrograms();
            initializeDecoder();
            auto value = std::make_shared<LiveMovieProducer>(owner, inner, gs_, decoder_.Get(),
                                                             width, height, csc_);
            owner_ = owner;
            inner_ = inner;
            width_ = width;
            height_ = height;
            movie_ = std::move(value);
            return movie_.get();
        } catch (...) {
            healthy_.store(false, std::memory_order_release);
            throw;
        }
    }
    std::shared_ptr<LiveMovieProducer> openShared(MovieSessionOwner owner, uint32_t inner,
                                                  uint32_t width, uint32_t height) {
        open(owner, inner, width, height);
        return movie_;
    }
    bool decode(const OriginalDecodeEvent& event, uint32_t th0, uint32_t th1,
                NativeDecodeCompletion& completion) {
        movie(event.generation);
        return movie_->decode(event, th0, th1, completion);
    }
    void acknowledgeDecode(const NativeDecodeCompletion& completion) {
        movie(completion.generation);
        movie_->acknowledgeDecode(completion);
    }
    bool output(const OriginalOutputEvent& event, NativeOutputBinding& binding) {
        movie(event.generation);
        return movie_->output(event, binding);
    }
    bool upload(const NativeOutputBinding& binding, const MovieUpload& original,
                const ParallelGS::CopyDescriptor& transfer, MovieDmaReceipt& receipt,
                bool batched = false) {
        movie(binding.generation);
        if (batched != bool(imageBatch_))
            throw std::logic_error("Native IMAGE prefix batch lifetime changed");
        if (original.gifPath == 3 && !imageConsumed_)
            throw std::runtime_error("Native IMAGE lacks actual backend GIF observer");
        if (transfer.bitbltbuf.desc.DBP != original.dbp ||
            transfer.bitbltbuf.desc.DBW != original.dbw ||
            transfer.bitbltbuf.desc.DPSM != original.dpsm ||
            transfer.trxpos.desc.DSAX != original.x || transfer.trxpos.desc.DSAY != original.y ||
            transfer.trxreg.desc.RRW != original.width ||
            transfer.trxreg.desc.RRH != original.height || transfer.trxdir.desc.XDIR != 0 ||
            transfer.trxpos.desc.DIR != 0)
            throw std::invalid_argument(
                "Literal original movie BITBLT/TRX control differs from resident IMAGE request");
        ParallelGS::ResidentImagePayload payload{
            original.sourceByteOffset, original.sourceBytes,
            original.sourceLayout == 2 ? ParallelGS::ResidentImageLayout::Macroblock16ColumnRgba32
                                       : ParallelGS::ResidentImageLayout::Macroblock16Rgba32};
        payload.gifPath = original.gifPath;
        return movie_->upload(
            binding, original,
            [&](Vulkan::CommandBuffer& command, const Vulkan::ImageView& image,
                const MovieUpload&) {
                if (batched)
                    renderer_.record_resident_image_upload(command, image, upload_, transfer,
                                                           payload, *imageBatch_);
                else
                    renderer_.record_resident_image_upload(command, image, upload_, transfer,
                                                           payload);
                if (original.gifPath == 3)
                    imageConsumed_(original.sourceBytes);
            },
            receipt, batched);
    }
    void releaseOriginalFrame(const NativeOutputBinding& binding) {
        movie(binding.generation);
        if (imageBatch_)
            throw std::logic_error("Original release interrupted an active GS image batch");
        movie_->releaseOriginalFrame(binding);
    }
    bool uploadComplete(const MovieDmaReceipt& receipt) {
        movie(receipt.generation);
        return movie_->uploadComplete(receipt);
    }
    void waitUploadComplete(const MovieDmaReceipt& receipt) {
        movie(receipt.generation);
        movie_->waitUploadComplete(receipt);
    }
    bool uploadImageSource(const NativeOutputBinding& binding, MovieUpload original,
                           MovieDmaReceipt& receipt, bool batched = false) {
        movie(binding.generation);
        const auto& registers = renderer_.resident_command_register_state();
        ParallelGS::CopyDescriptor transfer{};
        transfer.bitbltbuf = registers.bitbltbuf;
        transfer.trxpos = registers.trxpos;
        transfer.trxreg = registers.trxreg;
        transfer.trxdir = registers.trxdir;
        original.dbp = transfer.bitbltbuf.desc.DBP;
        original.dbw = transfer.bitbltbuf.desc.DBW;
        original.dpsm = transfer.bitbltbuf.desc.DPSM;
        original.x = transfer.trxpos.desc.DSAX;
        original.y = transfer.trxpos.desc.DSAY;
        original.width = transfer.trxreg.desc.RRW;
        original.height = transfer.trxreg.desc.RRH;
        return upload(binding, original, transfer, receipt, batched);
    }
    void beginImageBatch(const NativeOutputBinding& binding) {
        movie(binding.generation);
        if (imageBatch_)
            throw std::logic_error("Native IMAGE batch reentered");
        imageBatch_.emplace(renderer_.begin_resident_image_batch());
        try {
            movie_->beginUploadBatch(binding);
        } catch (...) {
            imageBatch_.reset();
            throw;
        }
    }
    std::vector<MovieDmaReceipt> endImageBatch(const NativeOutputBinding& binding) {
        movie(binding.generation);
        if (!imageBatch_)
            throw std::logic_error("Native IMAGE batch lost its real GS prefix token");
        try {
            renderer_.finish_resident_image_batch(*imageBatch_);
            auto receipts = movie_->endUploadBatch(binding);
            imageBatch_.reset();
            return receipts;
        } catch (...) {
            imageBatch_.reset();
            throw;
        }
    }
    // Runtime detaches compressed callbacks before enqueuing this real FIFO
    // cancellation. Bridge shutdown waits actual submitted decoder/GS work.
    void close(uint64_t generation) {
        movie(generation);
        imageBatch_.reset();
        movie_->cancel();
        movie_.reset();
        owner_ = {};
        inner_ = width_ = height_ = 0;
    }
};
} // namespace reo_gpu_movie
