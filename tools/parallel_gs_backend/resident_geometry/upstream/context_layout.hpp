#pragma once
#include "upstream_bank_abi.hpp"
#include <cstddef>
namespace reo_gpu_upstream_perspective {
inline constexpr uint32_t rByte = 0;
static_assert(offsetof(R5900Context, r) == rByte);
inline constexpr uint32_t pcByte = 512;
static_assert(offsetof(R5900Context, pc) == pcByte);
inline constexpr uint32_t vu0_vfByte = 576;
static_assert(offsetof(R5900Context, vu0_vf) == vu0_vfByte);
inline constexpr uint32_t viByte = 1088;
static_assert(offsetof(R5900Context, vi) == viByte);
inline constexpr uint32_t vu0_qByte = 1120;
static_assert(offsetof(R5900Context, vu0_q) == vu0_qByte);
inline constexpr uint32_t vu0_accByte = 1152;
static_assert(offsetof(R5900Context, vu0_acc) == vu0_accByte);
inline constexpr uint32_t in_delay_slotByte = 1372;
static_assert(offsetof(R5900Context, in_delay_slot) == in_delay_slotByte);
inline constexpr uint32_t branch_pcByte = 1376;
static_assert(offsetof(R5900Context, branch_pc) == branch_pcByte);
inline constexpr uint32_t fByte = 1508;
static_assert(offsetof(R5900Context, f) == fByte);
inline constexpr uint32_t fcr31Byte = 1636;
static_assert(offsetof(R5900Context, fcr31) == fcr31Byte);
static_assert(sizeof(R5900Context) == 1648);
} // namespace reo_gpu_upstream_perspective
