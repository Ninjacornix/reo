#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1AC0
// Address: 0x1a1ac0 - 0x1a1b60
void sub_001A1AC0_0x1a1ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1AC0_0x1a1ac0");
#endif

    ctx->pc = 0x1a1ac0u;

    // 0x1a1ac0: 0x10800022  beqz        $a0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1A1AC0u;
    {
        const bool branch_taken_0x1a1ac0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1AC0u;
            // 0x1a1ac4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1ac0) {
            ctx->pc = 0x1A1B4Cu;
            goto label_1a1b4c;
        }
    }
    ctx->pc = 0x1A1AC8u;
    // 0x1a1ac8: 0x4143c  dsll32      $v0, $a0, 16
    ctx->pc = 0x1a1ac8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1a1acc: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1a1accu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1a1ad0: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1AD0u;
    {
        const bool branch_taken_0x1a1ad0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A1AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1AD0u;
            // 0x1a1ad4: 0x51c3c  dsll32      $v1, $a1, 16 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1ad0) {
            ctx->pc = 0x1A1AE8u;
            goto label_1a1ae8;
        }
    }
    ctx->pc = 0x1A1AD8u;
    // 0x1a1ad8: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1a1ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1a1adc: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x1a1adcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a1ae0: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1a1ae0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1a1ae4: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1a1ae4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
label_1a1ae8:
    // 0x1a1ae8: 0x4143c  dsll32      $v0, $a0, 16
    ctx->pc = 0x1a1ae8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1a1aec: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1a1aecu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1a1af0: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1a1af0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1a1af4: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1a1af4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a1af8: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A1AF8u;
    {
        const bool branch_taken_0x1a1af8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a1af8) {
            ctx->pc = 0x1A1B04u;
            goto label_1a1b04;
        }
    }
    ctx->pc = 0x1A1B00u;
    // 0x1a1b00: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a1b00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a1b04:
    // 0x1a1b04: 0x1080000f  beqz        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x1A1B04u;
    {
        const bool branch_taken_0x1a1b04 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1B04u;
            // 0x1a1b08: 0x861018  mult        $v0, $a0, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1b04) {
            ctx->pc = 0x1A1B44u;
            goto label_1a1b44;
        }
    }
    ctx->pc = 0x1A1B0Cu;
    // 0x1a1b0c: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1a1b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a1b10: 0x41c3c  dsll32      $v1, $a0, 16
    ctx->pc = 0x1a1b10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1a1b14: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1a1b14u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1a1b18: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1a1b18u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a1b1c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a1b1cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a1b20: 0x0  nop
    ctx->pc = 0x1a1b20u;
    // NOP
    // 0x1a1b24: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1a1b24u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1a1b28: 0x46006002  mul.s       $f0, $f12, $f0
    ctx->pc = 0x1a1b28u;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[0]);
    // 0x1a1b2c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a1b2cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1a1b30: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x1a1b30u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1a1b34: 0x0  nop
    ctx->pc = 0x1a1b34u;
    // NOP
    // 0x1a1b38: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1a1b38u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1a1b3c: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1a1b3cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1a1b40: 0x861018  mult        $v0, $a0, $a2
    ctx->pc = 0x1a1b40u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
label_1a1b44:
    // 0x1a1b44: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1a1b44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1a1b48: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1a1b48u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
label_1a1b4c:
    // 0x1a1b4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1B4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1B4Cu;
            // 0x1a1b50: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1AE8u: goto label_1a1ae8;
            case 0x1A1B04u: goto label_1a1b04;
            case 0x1A1B44u: goto label_1a1b44;
            case 0x1A1B4Cu: goto label_1a1b4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1B54u;
    // 0x1a1b54: 0x0  nop
    ctx->pc = 0x1a1b54u;
    // NOP
    // 0x1a1b58: 0x0  nop
    ctx->pc = 0x1a1b58u;
    // NOP
    // 0x1a1b5c: 0x0  nop
    ctx->pc = 0x1a1b5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
