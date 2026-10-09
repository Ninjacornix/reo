#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A5B0
// Address: 0x13a5b0 - 0x13a738
void sub_0013A5B0_0x13a5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A5B0_0x13a5b0");
#endif

    switch (ctx->pc) {
        case 0x13a600u: goto label_13a600;
        case 0x13a614u: goto label_13a614;
        case 0x13a634u: goto label_13a634;
        case 0x13a644u: goto label_13a644;
        case 0x13a64cu: goto label_13a64c;
        case 0x13a650u: goto label_13a650;
        case 0x13a658u: goto label_13a658;
        case 0x13a668u: goto label_13a668;
        case 0x13a670u: goto label_13a670;
        case 0x13a67cu: goto label_13a67c;
        case 0x13a698u: goto label_13a698;
        case 0x13a6b4u: goto label_13a6b4;
        case 0x13a6c8u: goto label_13a6c8;
        case 0x13a6dcu: goto label_13a6dc;
        case 0x13a6f0u: goto label_13a6f0;
        case 0x13a6f8u: goto label_13a6f8;
        case 0x13a700u: goto label_13a700;
        case 0x13a708u: goto label_13a708;
        case 0x13a718u: goto label_13a718;
        default: break;
    }

    ctx->pc = 0x13a5b0u;

    // 0x13a5b0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x13a5b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x13a5b4: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x13a5b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x13a5b8: 0xffb10058  sd          $s1, 0x58($sp)
    ctx->pc = 0x13a5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 17));
    // 0x13a5bc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13a5bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a5c0: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x13a5c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x13a5c4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13a5c4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a5c8: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x13a5c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x13a5cc: 0x27a20040  addiu       $v0, $sp, 0x40
    ctx->pc = 0x13a5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x13a5d0: 0xffb30068  sd          $s3, 0x68($sp)
    ctx->pc = 0x13a5d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 19));
    // 0x13a5d4: 0x2465cc80  addiu       $a1, $v1, -0x3380
    ctx->pc = 0x13a5d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 4294954112));
    // 0x13a5d8: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x13a5d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x13a5dc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x13a5dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a5e0: 0x8a230003  lwl         $v1, 0x3($s1)
    ctx->pc = 0x13a5e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x13a5e4: 0x9a230000  lwr         $v1, 0x0($s1)
    ctx->pc = 0x13a5e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x13a5e8: 0x82260004  lb          $a2, 0x4($s1)
    ctx->pc = 0x13a5e8u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13a5ec: 0xa8430003  swl         $v1, 0x3($v0)
    ctx->pc = 0x13a5ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x13a5f0: 0xb8430000  swr         $v1, 0x0($v0)
    ctx->pc = 0x13a5f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x13a5f4: 0xa0460004  sb          $a2, 0x4($v0)
    ctx->pc = 0x13a5f4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4), (uint8_t)GPR_U32(ctx, 6));
    // 0x13a5f8: 0xc042ab8  jal         func_10AAE0
    ctx->pc = 0x13A5F8u;
    SET_GPR_U32(ctx, 31, 0x13A600u);
    ctx->pc = 0x13A5FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A5F8u;
            // 0x13a5fc: 0xa3a00044  sb          $zero, 0x44($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 68), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AAE0u;
    if (runtime->hasFunction(0x10AAE0u)) {
        auto targetFn = runtime->lookupFunction(0x10AAE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A600u; }
        if (ctx->pc != 0x13A600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AAE0_0x10aae0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A600u; }
        if (ctx->pc != 0x13A600u) { return; }
    }
    ctx->pc = 0x13A600u;
label_13a600:
    // 0x13a600: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x13A600u;
    {
        const bool branch_taken_0x13a600 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13a600) {
            ctx->pc = 0x13A604u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13A600u;
            // 0x13a604: 0x3c130022  lui         $s3, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13A620u;
            goto label_13a620;
        }
    }
    ctx->pc = 0x13A608u;
    // 0x13a608: 0x26240004  addiu       $a0, $s1, 0x4
    ctx->pc = 0x13a608u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x13a60c: 0xc04f090  jal         func_13C240
    ctx->pc = 0x13A60Cu;
    SET_GPR_U32(ctx, 31, 0x13A614u);
    ctx->pc = 0x13A610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A60Cu;
            // 0x13a610: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C240u;
    if (runtime->hasFunction(0x13C240u)) {
        auto targetFn = runtime->lookupFunction(0x13C240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A614u; }
        if (ctx->pc != 0x13A614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C240_0x13c240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A614u; }
        if (ctx->pc != 0x13A614u) { return; }
    }
    ctx->pc = 0x13A614u;
label_13a614:
    // 0x13a614: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x13A614u;
    {
        const bool branch_taken_0x13a614 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A614u;
            // 0x13a618: 0xdfb00050  ld          $s0, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a614) {
            ctx->pc = 0x13A720u;
            goto label_13a720;
        }
    }
    ctx->pc = 0x13A61Cu;
    // 0x13a61c: 0x0  nop
    ctx->pc = 0x13a61cu;
    // NOP
label_13a620:
    // 0x13a620: 0x24060080  addiu       $a2, $zero, 0x80
    ctx->pc = 0x13a620u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x13a624: 0x2670d9f8  addiu       $s0, $s3, -0x2608
    ctx->pc = 0x13a624u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294957560));
    // 0x13a628: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13a628u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a62c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13A62Cu;
    SET_GPR_U32(ctx, 31, 0x13A634u);
    ctx->pc = 0x13A630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A62Cu;
            // 0x13a630: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A634u; }
        if (ctx->pc != 0x13A634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A634u; }
        if (ctx->pc != 0x13A634u) { return; }
    }
    ctx->pc = 0x13A634u;
label_13a634:
    // 0x13a634: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13a634u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a638: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x13a638u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a63c: 0xc04e892  jal         func_13A248
    ctx->pc = 0x13A63Cu;
    SET_GPR_U32(ctx, 31, 0x13A644u);
    ctx->pc = 0x13A640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A63Cu;
            // 0x13a640: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A248u;
    if (runtime->hasFunction(0x13A248u)) {
        auto targetFn = runtime->lookupFunction(0x13A248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A644u; }
        if (ctx->pc != 0x13A644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A248_0x13a248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A644u; }
        if (ctx->pc != 0x13A644u) { return; }
    }
    ctx->pc = 0x13A644u;
label_13a644:
    // 0x13a644: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A644u;
    SET_GPR_U32(ctx, 31, 0x13A64Cu);
    ctx->pc = 0x13A648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A644u;
            // 0x13a648: 0x34049000  ori         $a0, $zero, 0x9000 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36864);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A64Cu; }
        if (ctx->pc != 0x13A64Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A64Cu; }
        if (ctx->pc != 0x13A64Cu) { return; }
    }
    ctx->pc = 0x13A64Cu;
label_13a64c:
    // 0x13a64c: 0x0  nop
    ctx->pc = 0x13a64cu;
    // NOP
label_13a650:
    // 0x13a650: 0xc04035e  jal         func_100D78
    ctx->pc = 0x13A650u;
    SET_GPR_U32(ctx, 31, 0x13A658u);
    ctx->pc = 0x13A654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A650u;
            // 0x13a654: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A658u; }
        if (ctx->pc != 0x13A658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A658u; }
        if (ctx->pc != 0x13A658u) { return; }
    }
    ctx->pc = 0x13A658u;
label_13a658:
    // 0x13a658: 0x1050fffd  beq         $v0, $s0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x13A658u;
    {
        const bool branch_taken_0x13a658 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        if (branch_taken_0x13a658) {
            ctx->pc = 0x13A650u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13a650;
        }
    }
    ctx->pc = 0x13A660u;
    // 0x13a660: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A660u;
    SET_GPR_U32(ctx, 31, 0x13A668u);
    ctx->pc = 0x13A664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A660u;
            // 0x13a664: 0x34049001  ori         $a0, $zero, 0x9001 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36865);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A668u; }
        if (ctx->pc != 0x13A668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A668u; }
        if (ctx->pc != 0x13A668u) { return; }
    }
    ctx->pc = 0x13A668u;
label_13a668:
    // 0x13a668: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A668u;
    SET_GPR_U32(ctx, 31, 0x13A670u);
    ctx->pc = 0x13A66Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A668u;
            // 0x13a66c: 0x34049100  ori         $a0, $zero, 0x9100 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37120);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A670u; }
        if (ctx->pc != 0x13A670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A670u; }
        if (ctx->pc != 0x13A670u) { return; }
    }
    ctx->pc = 0x13A670u;
label_13a670:
    // 0x13a670: 0x2665d9f8  addiu       $a1, $s3, -0x2608
    ctx->pc = 0x13a670u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294957560));
    // 0x13a674: 0xc04e58a  jal         func_139628
    ctx->pc = 0x13A674u;
    SET_GPR_U32(ctx, 31, 0x13A67Cu);
    ctx->pc = 0x13A678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A674u;
            // 0x13a678: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139628u;
    if (runtime->hasFunction(0x139628u)) {
        auto targetFn = runtime->lookupFunction(0x139628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A67Cu; }
        if (ctx->pc != 0x13A67Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139628_0x139628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A67Cu; }
        if (ctx->pc != 0x13A67Cu) { return; }
    }
    ctx->pc = 0x13A67Cu;
label_13a67c:
    // 0x13a67c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13A67Cu;
    {
        const bool branch_taken_0x13a67c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13a67c) {
            ctx->pc = 0x13A690u;
            goto label_13a690;
        }
    }
    ctx->pc = 0x13A684u;
    // 0x13a684: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x13A684u;
    {
        const bool branch_taken_0x13a684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A684u;
            // 0x13a688: 0x34049101  ori         $a0, $zero, 0x9101 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37121);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a684) {
            ctx->pc = 0x13A6D4u;
            goto label_13a6d4;
        }
    }
    ctx->pc = 0x13A68Cu;
    // 0x13a68c: 0x0  nop
    ctx->pc = 0x13a68cu;
    // NOP
label_13a690:
    // 0x13a690: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A690u;
    SET_GPR_U32(ctx, 31, 0x13A698u);
    ctx->pc = 0x13A694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A690u;
            // 0x13a694: 0x34049102  ori         $a0, $zero, 0x9102 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37122);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A698u; }
        if (ctx->pc != 0x13A698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A698u; }
        if (ctx->pc != 0x13A698u) { return; }
    }
    ctx->pc = 0x13A698u;
label_13a698:
    // 0x13a698: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13a698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13a69c: 0x34049200  ori         $a0, $zero, 0x9200
    ctx->pc = 0x13a69cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37376);
    // 0x13a6a0: 0xa3a20031  sb          $v0, 0x31($sp)
    ctx->pc = 0x13a6a0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 49), (uint8_t)GPR_U32(ctx, 2));
    // 0x13a6a4: 0xa3a00030  sb          $zero, 0x30($sp)
    ctx->pc = 0x13a6a4u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 48), (uint8_t)GPR_U32(ctx, 0));
    // 0x13a6a8: 0xa3a00032  sb          $zero, 0x32($sp)
    ctx->pc = 0x13a6a8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 50), (uint8_t)GPR_U32(ctx, 0));
    // 0x13a6ac: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A6ACu;
    SET_GPR_U32(ctx, 31, 0x13A6B4u);
    ctx->pc = 0x13A6B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A6ACu;
            // 0x13a6b0: 0xa3a00033  sb          $zero, 0x33($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 51), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6B4u; }
        if (ctx->pc != 0x13A6B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6B4u; }
        if (ctx->pc != 0x13A6B4u) { return; }
    }
    ctx->pc = 0x13A6B4u;
label_13a6b4:
    // 0x13a6b4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x13a6b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a6b8: 0x27a70030  addiu       $a3, $sp, 0x30
    ctx->pc = 0x13a6b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x13a6bc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x13a6bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a6c0: 0xc0405e2  jal         func_101788
    ctx->pc = 0x13A6C0u;
    SET_GPR_U32(ctx, 31, 0x13A6C8u);
    ctx->pc = 0x13A6C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A6C0u;
            // 0x13a6c4: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101788u;
    if (runtime->hasFunction(0x101788u)) {
        auto targetFn = runtime->lookupFunction(0x101788u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6C8u; }
        if (ctx->pc != 0x13A6C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101788_0x101788(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6C8u; }
        if (ctx->pc != 0x13A6C8u) { return; }
    }
    ctx->pc = 0x13A6C8u;
label_13a6c8:
    // 0x13a6c8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13A6C8u;
    {
        const bool branch_taken_0x13a6c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13a6c8) {
            ctx->pc = 0x13A6E8u;
            goto label_13a6e8;
        }
    }
    ctx->pc = 0x13A6D0u;
    // 0x13a6d0: 0x34049201  ori         $a0, $zero, 0x9201
    ctx->pc = 0x13a6d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37377);
label_13a6d4:
    // 0x13a6d4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A6D4u;
    SET_GPR_U32(ctx, 31, 0x13A6DCu);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6DCu; }
        if (ctx->pc != 0x13A6DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6DCu; }
        if (ctx->pc != 0x13A6DCu) { return; }
    }
    ctx->pc = 0x13A6DCu;
label_13a6dc:
    // 0x13a6dc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x13A6DCu;
    {
        const bool branch_taken_0x13a6dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A6DCu;
            // 0x13a6e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a6dc) {
            ctx->pc = 0x13A71Cu;
            goto label_13a71c;
        }
    }
    ctx->pc = 0x13A6E4u;
    // 0x13a6e4: 0x0  nop
    ctx->pc = 0x13a6e4u;
    // NOP
label_13a6e8:
    // 0x13a6e8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A6E8u;
    SET_GPR_U32(ctx, 31, 0x13A6F0u);
    ctx->pc = 0x13A6ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A6E8u;
            // 0x13a6ec: 0x34049202  ori         $a0, $zero, 0x9202 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37378);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6F0u; }
        if (ctx->pc != 0x13A6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6F0u; }
        if (ctx->pc != 0x13A6F0u) { return; }
    }
    ctx->pc = 0x13A6F0u;
label_13a6f0:
    // 0x13a6f0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A6F0u;
    SET_GPR_U32(ctx, 31, 0x13A6F8u);
    ctx->pc = 0x13A6F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A6F0u;
            // 0x13a6f4: 0x34049300  ori         $a0, $zero, 0x9300 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37632);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6F8u; }
        if (ctx->pc != 0x13A6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A6F8u; }
        if (ctx->pc != 0x13A6F8u) { return; }
    }
    ctx->pc = 0x13A6F8u;
label_13a6f8:
    // 0x13a6f8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x13a6f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13a6fc: 0x0  nop
    ctx->pc = 0x13a6fcu;
    // NOP
label_13a700:
    // 0x13a700: 0xc04035e  jal         func_100D78
    ctx->pc = 0x13A700u;
    SET_GPR_U32(ctx, 31, 0x13A708u);
    ctx->pc = 0x13A704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A700u;
            // 0x13a704: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A708u; }
        if (ctx->pc != 0x13A708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A708u; }
        if (ctx->pc != 0x13A708u) { return; }
    }
    ctx->pc = 0x13A708u;
label_13a708:
    // 0x13a708: 0x1050fffd  beq         $v0, $s0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x13A708u;
    {
        const bool branch_taken_0x13a708 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        if (branch_taken_0x13a708) {
            ctx->pc = 0x13A700u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13a700;
        }
    }
    ctx->pc = 0x13A710u;
    // 0x13a710: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A710u;
    SET_GPR_U32(ctx, 31, 0x13A718u);
    ctx->pc = 0x13A714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A710u;
            // 0x13a714: 0x34049301  ori         $a0, $zero, 0x9301 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37633);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A718u; }
        if (ctx->pc != 0x13A718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A718u; }
        if (ctx->pc != 0x13A718u) { return; }
    }
    ctx->pc = 0x13A718u;
label_13a718:
    // 0x13a718: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13a718u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13a71c:
    // 0x13a71c: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x13a71cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_13a720:
    // 0x13a720: 0xdfb10058  ld          $s1, 0x58($sp)
    ctx->pc = 0x13a720u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x13a724: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x13a724u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x13a728: 0xdfb30068  ld          $s3, 0x68($sp)
    ctx->pc = 0x13a728u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x13a72c: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x13a72cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x13a730: 0x3e00008  jr          $ra
    ctx->pc = 0x13A730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A730u;
            // 0x13a734: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A600u: goto label_13a600;
            case 0x13A614u: goto label_13a614;
            case 0x13A620u: goto label_13a620;
            case 0x13A634u: goto label_13a634;
            case 0x13A644u: goto label_13a644;
            case 0x13A64Cu: goto label_13a64c;
            case 0x13A650u: goto label_13a650;
            case 0x13A658u: goto label_13a658;
            case 0x13A668u: goto label_13a668;
            case 0x13A670u: goto label_13a670;
            case 0x13A67Cu: goto label_13a67c;
            case 0x13A690u: goto label_13a690;
            case 0x13A698u: goto label_13a698;
            case 0x13A6B4u: goto label_13a6b4;
            case 0x13A6C8u: goto label_13a6c8;
            case 0x13A6D4u: goto label_13a6d4;
            case 0x13A6DCu: goto label_13a6dc;
            case 0x13A6E8u: goto label_13a6e8;
            case 0x13A6F0u: goto label_13a6f0;
            case 0x13A6F8u: goto label_13a6f8;
            case 0x13A700u: goto label_13a700;
            case 0x13A708u: goto label_13a708;
            case 0x13A718u: goto label_13a718;
            case 0x13A71Cu: goto label_13a71c;
            case 0x13A720u: goto label_13a720;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A738u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
