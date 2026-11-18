#pragma once
namespace ps2_vblank_music_diag {
enum class Kind { AudioReport,PcmPush,Voice,SjxPoll,PcmRetire,SjxPublished };
template<class... T> void note(Kind,T...) {}
}
