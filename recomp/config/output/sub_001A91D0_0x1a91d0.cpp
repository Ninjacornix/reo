#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A91D0
// Address: 0x1a91d0 - 0x1a9400
void sub_001A91D0_0x1a91d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A91D0_0x1a91d0");
#endif

    switch (ctx->pc) {
        case 0x1a91e0u: goto label_1a91e0;
        case 0x1a91e8u: goto label_1a91e8;
        case 0x1a91f0u: goto label_1a91f0;
        case 0x1a91f8u: goto label_1a91f8;
        case 0x1a9200u: goto label_1a9200;
        case 0x1a9208u: goto label_1a9208;
        case 0x1a9218u: goto label_1a9218;
        case 0x1a9220u: goto label_1a9220;
        case 0x1a9248u: goto label_1a9248;
        case 0x1a9250u: goto label_1a9250;
        case 0x1a925cu: goto label_1a925c;
        case 0x1a9268u: goto label_1a9268;
        case 0x1a928cu: goto label_1a928c;
        case 0x1a9290u: goto label_1a9290;
        case 0x1a9298u: goto label_1a9298;
        case 0x1a92ccu: goto label_1a92cc;
        case 0x1a92f8u: goto label_1a92f8;
        case 0x1a9300u: goto label_1a9300;
        case 0x1a9320u: goto label_1a9320;
        case 0x1a9338u: goto label_1a9338;
        case 0x1a93a0u: goto label_1a93a0;
        case 0x1a93a8u: goto label_1a93a8;
        case 0x1a93b4u: goto label_1a93b4;
        case 0x1a93c0u: goto label_1a93c0;
        case 0x1a93c8u: goto label_1a93c8;
        case 0x1a93d0u: goto label_1a93d0;
        case 0x1a93dcu: goto label_1a93dc;
        case 0x1a93e8u: goto label_1a93e8;
        default: break;
    }

    ctx->pc = 0x1a91d0u;

    // 0x1a91d0: 0x27bdfd50  addiu       $sp, $sp, -0x2B0
    ctx->pc = 0x1a91d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966608));
    // 0x1a91d4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a91d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a91d8: 0xc0409fc  jal         func_1027F0
    ctx->pc = 0x1A91D8u;
    SET_GPR_U32(ctx, 31, 0x1A91E0u);
    ctx->pc = 0x1A91DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A91D8u;
            // 0x1a91dc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1027F0u;
    if (runtime->hasFunction(0x1027F0u)) {
        auto targetFn = runtime->lookupFunction(0x1027F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91E0u; }
        if (ctx->pc != 0x1A91E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001027F0_0x1027f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91E0u; }
        if (ctx->pc != 0x1A91E0u) { return; }
    }
    ctx->pc = 0x1A91E0u;
label_1a91e0:
    // 0x1a91e0: 0xc040ac8  jal         func_102B20
    ctx->pc = 0x1A91E0u;
    SET_GPR_U32(ctx, 31, 0x1A91E8u);
    ctx->pc = 0x102B20u;
    if (runtime->hasFunction(0x102B20u)) {
        auto targetFn = runtime->lookupFunction(0x102B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91E8u; }
        if (ctx->pc != 0x1A91E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102B20_0x102b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91E8u; }
        if (ctx->pc != 0x1A91E8u) { return; }
    }
    ctx->pc = 0x1A91E8u;
label_1a91e8:
    // 0x1a91e8: 0xc040786  jal         func_101E18
    ctx->pc = 0x1A91E8u;
    SET_GPR_U32(ctx, 31, 0x1A91F0u);
    ctx->pc = 0x101E18u;
    if (runtime->hasFunction(0x101E18u)) {
        auto targetFn = runtime->lookupFunction(0x101E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91F0u; }
        if (ctx->pc != 0x1A91F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101E18_0x101e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91F0u; }
        if (ctx->pc != 0x1A91F0u) { return; }
    }
    ctx->pc = 0x1A91F0u;
label_1a91f0:
    // 0x1a91f0: 0xc0408d4  jal         func_102350
    ctx->pc = 0x1A91F0u;
    SET_GPR_U32(ctx, 31, 0x1A91F8u);
    ctx->pc = 0x102350u;
    if (runtime->hasFunction(0x102350u)) {
        auto targetFn = runtime->lookupFunction(0x102350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91F8u; }
        if (ctx->pc != 0x1A91F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102350_0x102350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91F8u; }
        if (ctx->pc != 0x1A91F8u) { return; }
    }
    ctx->pc = 0x1A91F8u;
label_1a91f8:
    // 0x1a91f8: 0xc0449c2  jal         func_112708
    ctx->pc = 0x1A91F8u;
    SET_GPR_U32(ctx, 31, 0x1A9200u);
    ctx->pc = 0x112708u;
    if (runtime->hasFunction(0x112708u)) {
        auto targetFn = runtime->lookupFunction(0x112708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9200u; }
        if (ctx->pc != 0x1A9200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112708_0x112708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9200u; }
        if (ctx->pc != 0x1A9200u) { return; }
    }
    ctx->pc = 0x1A9200u;
label_1a9200:
    // 0x1a9200: 0xc040c22  jal         func_103088
    ctx->pc = 0x1A9200u;
    SET_GPR_U32(ctx, 31, 0x1A9208u);
    ctx->pc = 0x1A9204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9200u;
            // 0x1a9204: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103088u;
    if (runtime->hasFunction(0x103088u)) {
        auto targetFn = runtime->lookupFunction(0x103088u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9208u; }
        if (ctx->pc != 0x1A9208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103088_0x103088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9208u; }
        if (ctx->pc != 0x1A9208u) { return; }
    }
    ctx->pc = 0x1A9208u;
label_1a9208:
    // 0x1a9208: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1a9208u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1a920c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a920cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9210: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1A9210u;
    SET_GPR_U32(ctx, 31, 0x1A9218u);
    ctx->pc = 0x1A9214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9210u;
            // 0x1a9214: 0x3c060004  lui         $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9218u; }
        if (ctx->pc != 0x1A9218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9218u; }
        if (ctx->pc != 0x1A9218u) { return; }
    }
    ctx->pc = 0x1A9218u;
label_1a9218:
    // 0x1a9218: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1a9218u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a921c: 0x101180  sll         $v0, $s0, 6
    ctx->pc = 0x1a921cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
label_1a9220:
    // 0x1a9220: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1a9220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9224: 0x24c3c  dsll32      $t1, $v0, 16
    ctx->pc = 0x1a9224u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1a9228: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a9228u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a922c: 0x94c3f  dsra32      $t1, $t1, 16
    ctx->pc = 0x1a922cu;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 16));
    // 0x1a9230: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1a9230u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a9234: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1a9234u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9238: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1a9238u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a923c: 0x240a0400  addiu       $t2, $zero, 0x400
    ctx->pc = 0x1a923cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1a9240: 0xc044de8  jal         func_1137A0
    ctx->pc = 0x1A9240u;
    SET_GPR_U32(ctx, 31, 0x1A9248u);
    ctx->pc = 0x1A9244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9240u;
            // 0x1a9244: 0x240b0040  addiu       $t3, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1137A0u;
    if (runtime->hasFunction(0x1137A0u)) {
        auto targetFn = runtime->lookupFunction(0x1137A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9248u; }
        if (ctx->pc != 0x1A9248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001137A0_0x1137a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9248u; }
        if (ctx->pc != 0x1A9248u) { return; }
    }
    ctx->pc = 0x1A9248u;
label_1a9248:
    // 0x1a9248: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1A9248u;
    SET_GPR_U32(ctx, 31, 0x1A9250u);
    ctx->pc = 0x1A924Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9248u;
            // 0x1a924c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9250u; }
        if (ctx->pc != 0x1A9250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9250u; }
        if (ctx->pc != 0x1A9250u) { return; }
    }
    ctx->pc = 0x1A9250u;
label_1a9250:
    // 0x1a9250: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1a9250u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9254: 0xc044e62  jal         func_113988
    ctx->pc = 0x1A9254u;
    SET_GPR_U32(ctx, 31, 0x1A925Cu);
    ctx->pc = 0x1A9258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9254u;
            // 0x1a9258: 0x3c050100  lui         $a1, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113988u;
    if (runtime->hasFunction(0x113988u)) {
        auto targetFn = runtime->lookupFunction(0x113988u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A925Cu; }
        if (ctx->pc != 0x1A925Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113988_0x113988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A925Cu; }
        if (ctx->pc != 0x1A925Cu) { return; }
    }
    ctx->pc = 0x1A925Cu;
label_1a925c:
    // 0x1a925c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a925cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9260: 0xc044d22  jal         func_113488
    ctx->pc = 0x1A9260u;
    SET_GPR_U32(ctx, 31, 0x1A9268u);
    ctx->pc = 0x1A9264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9260u;
            // 0x1a9264: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113488u;
    if (runtime->hasFunction(0x113488u)) {
        auto targetFn = runtime->lookupFunction(0x113488u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9268u; }
        if (ctx->pc != 0x1A9268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113488_0x113488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9268u; }
        if (ctx->pc != 0x1A9268u) { return; }
    }
    ctx->pc = 0x1A9268u;
label_1a9268:
    // 0x1a9268: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a9268u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1a926c: 0x2a020010  slti        $v0, $s0, 0x10
    ctx->pc = 0x1a926cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1a9270: 0x1440ffeb  bnez        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1A9270u;
    {
        const bool branch_taken_0x1a9270 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9270u;
            // 0x1a9274: 0x101180  sll         $v0, $s0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9270) {
            ctx->pc = 0x1A9220u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9220;
        }
    }
    ctx->pc = 0x1A9278u;
    // 0x1a9278: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a9278u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a927c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1a927cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9280: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1a9280u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a9284: 0xc04495a  jal         func_112568
    ctx->pc = 0x1A9284u;
    SET_GPR_U32(ctx, 31, 0x1A928Cu);
    ctx->pc = 0x1A9288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9284u;
            // 0x1a9288: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112568u;
    if (runtime->hasFunction(0x112568u)) {
        auto targetFn = runtime->lookupFunction(0x112568u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A928Cu; }
        if (ctx->pc != 0x1A928Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A928Cu; }
        if (ctx->pc != 0x1A928Cu) { return; }
    }
    ctx->pc = 0x1A928Cu;
label_1a928c:
    // 0x1a928c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1a928cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a9290:
    // 0x1a9290: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1A9290u;
    SET_GPR_U32(ctx, 31, 0x1A9298u);
    ctx->pc = 0x1A9294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9290u;
            // 0x1a9294: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9298u; }
        if (ctx->pc != 0x1A9298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9298u; }
        if (ctx->pc != 0x1A9298u) { return; }
    }
    ctx->pc = 0x1A9298u;
label_1a9298:
    // 0x1a9298: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a9298u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1a929c: 0x2a020014  slti        $v0, $s0, 0x14
    ctx->pc = 0x1a929cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1a92a0: 0x0  nop
    ctx->pc = 0x1a92a0u;
    // NOP
    // 0x1a92a4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A92A4u;
    {
        const bool branch_taken_0x1a92a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a92a4) {
            ctx->pc = 0x1A9290u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9290;
        }
    }
    ctx->pc = 0x1A92ACu;
    // 0x1a92ac: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1a92acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a92b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a92b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a92b4: 0x24060280  addiu       $a2, $zero, 0x280
    ctx->pc = 0x1a92b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1a92b8: 0x240701c0  addiu       $a3, $zero, 0x1C0
    ctx->pc = 0x1a92b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 448));
    // 0x1a92bc: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1a92bcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a92c0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1a92c0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a92c4: 0xc044c3e  jal         func_1130F8
    ctx->pc = 0x1A92C4u;
    SET_GPR_U32(ctx, 31, 0x1A92CCu);
    ctx->pc = 0x1A92C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A92C4u;
            // 0x1a92c8: 0x240a0001  addiu       $t2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1130F8u;
    if (runtime->hasFunction(0x1130F8u)) {
        auto targetFn = runtime->lookupFunction(0x1130F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A92CCu; }
        if (ctx->pc != 0x1A92CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001130F8_0x1130f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A92CCu; }
        if (ctx->pc != 0x1A92CCu) { return; }
    }
    ctx->pc = 0x1A92CCu;
label_1a92cc:
    // 0x1a92cc: 0x97a300e0  lhu         $v1, 0xE0($sp)
    ctx->pc = 0x1a92ccu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1a92d0: 0x2404fe00  addiu       $a0, $zero, -0x200
    ctx->pc = 0x1a92d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966784));
    // 0x1a92d4: 0x97a200b8  lhu         $v0, 0xB8($sp)
    ctx->pc = 0x1a92d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x1a92d8: 0x6405008c  daddiu      $a1, $zero, 0x8C
    ctx->pc = 0x1a92d8u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)140);
    // 0x1a92dc: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1a92dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1a92e0: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x1a92e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1a92e4: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x1a92e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x1a92e8: 0xa7a300e0  sh          $v1, 0xE0($sp)
    ctx->pc = 0x1a92e8u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 224), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a92ec: 0x306301ff  andi        $v1, $v1, 0x1FF
    ctx->pc = 0x1a92ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)511);
    // 0x1a92f0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a92f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a92f4: 0xa7a200b8  sh          $v0, 0xB8($sp)
    ctx->pc = 0x1a92f4u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 184), (uint16_t)GPR_U32(ctx, 2));
label_1a92f8:
    // 0x1a92f8: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1A92F8u;
    SET_GPR_U32(ctx, 31, 0x1A9300u);
    ctx->pc = 0x1A92FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A92F8u;
            // 0x1a92fc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9300u; }
        if (ctx->pc != 0x1A9300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9300u; }
        if (ctx->pc != 0x1A9300u) { return; }
    }
    ctx->pc = 0x1A9300u;
label_1a9300:
    // 0x1a9300: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1a9300u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1a9304: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1a9304u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1a9308: 0x0  nop
    ctx->pc = 0x1a9308u;
    // NOP
    // 0x1a930c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A930Cu;
    {
        const bool branch_taken_0x1a930c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a930c) {
            ctx->pc = 0x1A92F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a92f8;
        }
    }
    ctx->pc = 0x1A9314u;
    // 0x1a9314: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a9314u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9318: 0xc044d22  jal         func_113488
    ctx->pc = 0x1A9318u;
    SET_GPR_U32(ctx, 31, 0x1A9320u);
    ctx->pc = 0x1A931Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9318u;
            // 0x1a931c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113488u;
    if (runtime->hasFunction(0x113488u)) {
        auto targetFn = runtime->lookupFunction(0x113488u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9320u; }
        if (ctx->pc != 0x1A9320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113488_0x113488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9320u; }
        if (ctx->pc != 0x1A9320u) { return; }
    }
    ctx->pc = 0x1A9320u;
label_1a9320:
    // 0x1a9320: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x1a9320u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x1a9324: 0x3c090023  lui         $t1, 0x23
    ctx->pc = 0x1a9324u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)35 << 16));
    // 0x1a9328: 0x250811d0  addiu       $t0, $t0, 0x11D0
    ctx->pc = 0x1a9328u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4560));
    // 0x1a932c: 0x25291210  addiu       $t1, $t1, 0x1210
    ctx->pc = 0x1a932cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4624));
    // 0x1a9330: 0x3c070100  lui         $a3, 0x100
    ctx->pc = 0x1a9330u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)256 << 16));
    // 0x1a9334: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a9334u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a9338:
    // 0x1a9338: 0x91250000  lbu         $a1, 0x0($t1)
    ctx->pc = 0x1a9338u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1a933c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a933cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a9340: 0x28c21000  slti        $v0, $a2, 0x1000
    ctx->pc = 0x1a9340u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4096) ? 1 : 0);
    // 0x1a9344: 0x51903  sra         $v1, $a1, 4
    ctx->pc = 0x1a9344u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 5), 4));
    // 0x1a9348: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1a9348u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1a934c: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1a934cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1a9350: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1a9350u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a9354: 0x30a3000f  andi        $v1, $a1, 0xF
    ctx->pc = 0x1a9354u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)15);
    // 0x1a9358: 0x1042021  addu        $a0, $t0, $a0
    ctx->pc = 0x1a9358u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
    // 0x1a935c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a935cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a9360: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1a9360u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a9364: 0x1031821  addu        $v1, $t0, $v1
    ctx->pc = 0x1a9364u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1a9368: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x1a9368u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1a936c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a936cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a9370: 0xace30004  sw          $v1, 0x4($a3)
    ctx->pc = 0x1a9370u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
    // 0x1a9374: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1A9374u;
    {
        const bool branch_taken_0x1a9374 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9374u;
            // 0x1a9378: 0x24e70008  addiu       $a3, $a3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9374) {
            ctx->pc = 0x1A9338u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9338;
        }
    }
    ctx->pc = 0x1A937Cu;
    // 0x1a937c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1a937cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9380: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a9380u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9384: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x1a9384u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a9388: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1a9388u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a938c: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1a938cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a9390: 0x24090190  addiu       $t1, $zero, 0x190
    ctx->pc = 0x1a9390u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
    // 0x1a9394: 0x240a0100  addiu       $t2, $zero, 0x100
    ctx->pc = 0x1a9394u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1a9398: 0xc044de8  jal         func_1137A0
    ctx->pc = 0x1A9398u;
    SET_GPR_U32(ctx, 31, 0x1A93A0u);
    ctx->pc = 0x1A939Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9398u;
            // 0x1a939c: 0x240b0020  addiu       $t3, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1137A0u;
    if (runtime->hasFunction(0x1137A0u)) {
        auto targetFn = runtime->lookupFunction(0x1137A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93A0u; }
        if (ctx->pc != 0x1A93A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001137A0_0x1137a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93A0u; }
        if (ctx->pc != 0x1A93A0u) { return; }
    }
    ctx->pc = 0x1A93A0u;
label_1a93a0:
    // 0x1a93a0: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1A93A0u;
    SET_GPR_U32(ctx, 31, 0x1A93A8u);
    ctx->pc = 0x1A93A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93A0u;
            // 0x1a93a4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93A8u; }
        if (ctx->pc != 0x1A93A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93A8u; }
        if (ctx->pc != 0x1A93A8u) { return; }
    }
    ctx->pc = 0x1A93A8u;
label_1a93a8:
    // 0x1a93a8: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1a93a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a93ac: 0xc044ce4  jal         func_113390
    ctx->pc = 0x1A93ACu;
    SET_GPR_U32(ctx, 31, 0x1A93B4u);
    ctx->pc = 0x1A93B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93ACu;
            // 0x1a93b0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113390u;
    if (runtime->hasFunction(0x113390u)) {
        auto targetFn = runtime->lookupFunction(0x113390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93B4u; }
        if (ctx->pc != 0x1A93B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113390_0x113390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93B4u; }
        if (ctx->pc != 0x1A93B4u) { return; }
    }
    ctx->pc = 0x1A93B4u;
label_1a93b4:
    // 0x1a93b4: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1a93b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a93b8: 0xc044e62  jal         func_113988
    ctx->pc = 0x1A93B8u;
    SET_GPR_U32(ctx, 31, 0x1A93C0u);
    ctx->pc = 0x1A93BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93B8u;
            // 0x1a93bc: 0x3c050100  lui         $a1, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113988u;
    if (runtime->hasFunction(0x113988u)) {
        auto targetFn = runtime->lookupFunction(0x113988u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93C0u; }
        if (ctx->pc != 0x1A93C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113988_0x113988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93C0u; }
        if (ctx->pc != 0x1A93C0u) { return; }
    }
    ctx->pc = 0x1A93C0u;
label_1a93c0:
    // 0x1a93c0: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x1A93C0u;
    SET_GPR_U32(ctx, 31, 0x1A93C8u);
    ctx->pc = 0x1A93C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93C0u;
            // 0x1a93c4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93C8u; }
        if (ctx->pc != 0x1A93C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93C8u; }
        if (ctx->pc != 0x1A93C8u) { return; }
    }
    ctx->pc = 0x1A93C8u;
label_1a93c8:
    // 0x1a93c8: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1A93C8u;
    SET_GPR_U32(ctx, 31, 0x1A93D0u);
    ctx->pc = 0x1A93CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93C8u;
            // 0x1a93cc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93D0u; }
        if (ctx->pc != 0x1A93D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93D0u; }
        if (ctx->pc != 0x1A93D0u) { return; }
    }
    ctx->pc = 0x1A93D0u;
label_1a93d0:
    // 0x1a93d0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a93d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a93d4: 0xc044d22  jal         func_113488
    ctx->pc = 0x1A93D4u;
    SET_GPR_U32(ctx, 31, 0x1A93DCu);
    ctx->pc = 0x1A93D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93D4u;
            // 0x1a93d8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113488u;
    if (runtime->hasFunction(0x113488u)) {
        auto targetFn = runtime->lookupFunction(0x113488u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93DCu; }
        if (ctx->pc != 0x1A93DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113488_0x113488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93DCu; }
        if (ctx->pc != 0x1A93DCu) { return; }
    }
    ctx->pc = 0x1A93DCu;
label_1a93dc:
    // 0x1a93dc: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1a93dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a93e0: 0xc044ce4  jal         func_113390
    ctx->pc = 0x1A93E0u;
    SET_GPR_U32(ctx, 31, 0x1A93E8u);
    ctx->pc = 0x1A93E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93E0u;
            // 0x1a93e4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113390u;
    if (runtime->hasFunction(0x113390u)) {
        auto targetFn = runtime->lookupFunction(0x113390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93E8u; }
        if (ctx->pc != 0x1A93E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113390_0x113390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93E8u; }
        if (ctx->pc != 0x1A93E8u) { return; }
    }
    ctx->pc = 0x1A93E8u;
label_1a93e8:
    // 0x1a93e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a93e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a93ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a93ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a93f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A93F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A93F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A93F0u;
            // 0x1a93f4: 0x27bd02b0  addiu       $sp, $sp, 0x2B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 688));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A91E0u: goto label_1a91e0;
            case 0x1A91E8u: goto label_1a91e8;
            case 0x1A91F0u: goto label_1a91f0;
            case 0x1A91F8u: goto label_1a91f8;
            case 0x1A9200u: goto label_1a9200;
            case 0x1A9208u: goto label_1a9208;
            case 0x1A9218u: goto label_1a9218;
            case 0x1A9220u: goto label_1a9220;
            case 0x1A9248u: goto label_1a9248;
            case 0x1A9250u: goto label_1a9250;
            case 0x1A925Cu: goto label_1a925c;
            case 0x1A9268u: goto label_1a9268;
            case 0x1A928Cu: goto label_1a928c;
            case 0x1A9290u: goto label_1a9290;
            case 0x1A9298u: goto label_1a9298;
            case 0x1A92CCu: goto label_1a92cc;
            case 0x1A92F8u: goto label_1a92f8;
            case 0x1A9300u: goto label_1a9300;
            case 0x1A9320u: goto label_1a9320;
            case 0x1A9338u: goto label_1a9338;
            case 0x1A93A0u: goto label_1a93a0;
            case 0x1A93A8u: goto label_1a93a8;
            case 0x1A93B4u: goto label_1a93b4;
            case 0x1A93C0u: goto label_1a93c0;
            case 0x1A93C8u: goto label_1a93c8;
            case 0x1A93D0u: goto label_1a93d0;
            case 0x1A93DCu: goto label_1a93dc;
            case 0x1A93E8u: goto label_1a93e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A93F8u;
    // 0x1a93f8: 0x0  nop
    ctx->pc = 0x1a93f8u;
    // NOP
    // 0x1a93fc: 0x0  nop
    ctx->pc = 0x1a93fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
