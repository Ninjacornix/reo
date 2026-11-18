#pragma once
#include "../audio_output/audio_output_owner.h"
#include <algorithm>
#include <array>
#include <mutex>
namespace reo::native::adxt_player::testing {
// No device is opened. This model implements attach/detach under the SAME
// mutex as every dispatch; false retains its resource for actual retry.
struct Provider final:audio_output::Provider {
    std::mutex mutex;audio_output::CallbackSlot* slot{};unsigned detaches{},stops{},unloads{},callbacks{};
    unsigned fail_detach{},fail_stop{},fail_unload{};bool sync_zero{},unloaded{};
    std::string_view source_sha256()const noexcept override{return audio_output::provider_source_sha256;}
    bool attach(audio_output::CallbackSlot& s)noexcept override{
        std::lock_guard lock(mutex);slot=&s;std::array<float,128> out{};
        const auto ran=slot->dispatch(out.data(),64);++callbacks;
        sync_zero=ran && std::all_of(out.begin(),out.end(),[](float f){return f==0;});return true;
    }
    bool detach()noexcept override{std::lock_guard lock(mutex);++detaches;if(fail_detach){--fail_detach;return false;}slot=nullptr;return true;}
    bool stop()noexcept override{std::lock_guard lock(mutex);++stops;if(fail_stop){--fail_stop;return false;}return true;}
    bool unload()noexcept override{std::lock_guard lock(mutex);++unloads;if(fail_unload){--fail_unload;return false;}unloaded=true;return true;}
    bool step(unsigned frames=64){std::lock_guard lock(mutex);std::array<float,1024> out{};
        if(!slot)return false;
        ++callbacks;return slot->dispatch(out.data(),frames);}
};
} // namespace reo::native::adxt_player::testing
