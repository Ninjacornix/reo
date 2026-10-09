#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001982D0
// Address: 0x1982d0 - 0x198390
void sub_001982D0_0x1982d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001982D0_0x1982d0");
#endif

    switch (ctx->pc) {
        case 0x1982ecu: goto label_1982ec;
        case 0x198378u: goto label_198378;
        default: break;
    }

    ctx->pc = 0x1982d0u;

    // 0x1982d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1982d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1982d4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1982d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1982d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1982d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1982dc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1982dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1982e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1982e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1982e4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x1982E4u;
    SET_GPR_U32(ctx, 31, 0x1982ECu);
    ctx->pc = 0x1982E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1982E4u;
            // 0x1982e8: 0x24040030  addiu       $a0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1982ECu; }
        if (ctx->pc != 0x1982ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1982ECu; }
        if (ctx->pc != 0x1982ECu) { return; }
    }
    ctx->pc = 0x1982ECu;
label_1982ec:
    // 0x1982ec: 0x3403f000  ori         $v1, $zero, 0xF000
    ctx->pc = 0x1982ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)61440);
    // 0x1982f0: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x1982f0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x1982f4: 0x32c38  dsll        $a1, $v1, 16
    ctx->pc = 0x1982f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << 16);
    // 0x1982f8: 0x3c041300  lui         $a0, 0x1300
    ctx->pc = 0x1982f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4864 << 16));
    // 0x1982fc: 0x34a60002  ori         $a2, $a1, 0x2
    ctx->pc = 0x1982fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2);
    // 0x198300: 0x3c035100  lui         $v1, 0x5100
    ctx->pc = 0x198300u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20736 << 16));
    // 0x198304: 0x34650002  ori         $a1, $v1, 0x2
    ctx->pc = 0x198304u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    // 0x198308: 0xfc460000  sd          $a2, 0x0($v0)
    ctx->pc = 0x198308u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x19830c: 0xac440008  sw          $a0, 0x8($v0)
    ctx->pc = 0x19830cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
    // 0x198310: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x198310u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x198314: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x198314u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x198318: 0xac45000c  sw          $a1, 0xC($v0)
    ctx->pc = 0x198318u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 5));
    // 0x19831c: 0x34038001  ori         $v1, $zero, 0x8001
    ctx->pc = 0x19831cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x198320: 0x24e7f6f0  addiu       $a3, $a3, -0x910
    ctx->pc = 0x198320u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
    // 0x198324: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x198324u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x198328: 0xfc430010  sd          $v1, 0x10($v0)
    ctx->pc = 0x198328u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 3));
    // 0x19832c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x19832cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x198330: 0xfc440018  sd          $a0, 0x18($v0)
    ctx->pc = 0x198330u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
    // 0x198334: 0x101c02  srl         $v1, $s0, 16
    ctx->pc = 0x198334u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 16), 16));
    // 0x198338: 0x102202  srl         $a0, $s0, 8
    ctx->pc = 0x198338u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x19833c: 0x306600ff  andi        $a2, $v1, 0xFF
    ctx->pc = 0x19833cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x198340: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x198340u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x198344: 0x320300ff  andi        $v1, $s0, 0xFF
    ctx->pc = 0x198344u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x198348: 0x52a38  dsll        $a1, $a1, 8
    ctx->pc = 0x198348u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 8);
    // 0x19834c: 0x32438  dsll        $a0, $v1, 16
    ctx->pc = 0x19834cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 16);
    // 0x198350: 0xc53025  or          $a2, $a2, $a1
    ctx->pc = 0x198350u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x198354: 0x2403003d  addiu       $v1, $zero, 0x3D
    ctx->pc = 0x198354u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x198358: 0x863025  or          $a2, $a0, $a2
    ctx->pc = 0x198358u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x19835c: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x19835cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
    // 0x198360: 0xfc460020  sd          $a2, 0x20($v0)
    ctx->pc = 0x198360u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 6));
    // 0x198364: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x198364u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x198368: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x198368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19836c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x19836cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x198370: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x198370u;
    SET_GPR_U32(ctx, 31, 0x198378u);
    ctx->pc = 0x198374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x198370u;
            // 0x198374: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x198378u; }
        if (ctx->pc != 0x198378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x198378u; }
        if (ctx->pc != 0x198378u) { return; }
    }
    ctx->pc = 0x198378u;
label_198378:
    // 0x198378: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x198378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19837c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19837cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x198380: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x198380u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x198384: 0x3e00008  jr          $ra
    ctx->pc = 0x198384u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198384u;
            // 0x198388: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1982ECu: goto label_1982ec;
            case 0x198378u: goto label_198378;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19838Cu;
    // 0x19838c: 0x0  nop
    ctx->pc = 0x19838cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
