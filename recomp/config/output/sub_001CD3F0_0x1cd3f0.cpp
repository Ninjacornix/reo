#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD3F0
// Address: 0x1cd3f0 - 0x1cd520
void sub_001CD3F0_0x1cd3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD3F0_0x1cd3f0");
#endif

    switch (ctx->pc) {
        case 0x1cd454u: goto label_1cd454;
        case 0x1cd484u: goto label_1cd484;
        case 0x1cd4c0u: goto label_1cd4c0;
        case 0x1cd4ecu: goto label_1cd4ec;
        case 0x1cd504u: goto label_1cd504;
        default: break;
    }

    ctx->pc = 0x1cd3f0u;

    // 0x1cd3f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd3f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd3f4: 0x30a28000  andi        $v0, $a1, 0x8000
    ctx->pc = 0x1cd3f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)32768);
    // 0x1cd3f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd3f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd3fc: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1cd3fcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd400: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd400u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd404: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1cd404u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd408: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1CD408u;
    {
        const bool branch_taken_0x1cd408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD40Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD408u;
            // 0x1cd40c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd408) {
            ctx->pc = 0x1CD48Cu;
            goto label_1cd48c;
        }
    }
    ctx->pc = 0x1CD410u;
    // 0x1cd410: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1cd410u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1cd414: 0x34427fff  ori         $v0, $v0, 0x7FFF
    ctx->pc = 0x1cd414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32767);
    // 0x1cd418: 0x1021024  and         $v0, $t0, $v0
    ctx->pc = 0x1cd418u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x1cd41c: 0x28410064  slti        $at, $v0, 0x64
    ctx->pc = 0x1cd41cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)100) ? 1 : 0);
    // 0x1cd420: 0x1020000e  beqz        $at, . + 4 + (0xE << 2)
    ctx->pc = 0x1CD420u;
    {
        const bool branch_taken_0x1cd420 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD420u;
            // 0x1cd424: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd420) {
            ctx->pc = 0x1CD45Cu;
            goto label_1cd45c;
        }
    }
    ctx->pc = 0x1CD428u;
    // 0x1cd428: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd428u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd42c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd42cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd430: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cd430u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1cd434: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd434u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd438: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd43c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd43cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd440: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd440u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd444: 0x31087fff  andi        $t0, $t0, 0x7FFF
    ctx->pc = 0x1cd444u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)32767);
    // 0x1cd448: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd448u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd44c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD44Cu;
    SET_GPR_U32(ctx, 31, 0x1CD454u);
    ctx->pc = 0x1CD450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD44Cu;
            // 0x1cd450: 0x24a55f80  addiu       $a1, $a1, 0x5F80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD454u; }
        if (ctx->pc != 0x1CD454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD454u; }
        if (ctx->pc != 0x1CD454u) { return; }
    }
    ctx->pc = 0x1CD454u;
label_1cd454:
    // 0x1cd454: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1CD454u;
    {
        const bool branch_taken_0x1cd454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd454) {
            ctx->pc = 0x1CD4ECu;
            goto label_1cd4ec;
        }
    }
    ctx->pc = 0x1CD45Cu;
label_1cd45c:
    // 0x1cd45c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd45cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd460: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cd460u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1cd464: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd464u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd468: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd46c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd46cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd470: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd470u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd474: 0x31087fff  andi        $t0, $t0, 0x7FFF
    ctx->pc = 0x1cd474u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)32767);
    // 0x1cd478: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd478u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd47c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD47Cu;
    SET_GPR_U32(ctx, 31, 0x1CD484u);
    ctx->pc = 0x1CD480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD47Cu;
            // 0x1cd480: 0x24a55f90  addiu       $a1, $a1, 0x5F90 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD484u; }
        if (ctx->pc != 0x1CD484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD484u; }
        if (ctx->pc != 0x1CD484u) { return; }
    }
    ctx->pc = 0x1CD484u;
label_1cd484:
    // 0x1cd484: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CD484u;
    {
        const bool branch_taken_0x1cd484 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd484) {
            ctx->pc = 0x1CD4ECu;
            goto label_1cd4ec;
        }
    }
    ctx->pc = 0x1CD48Cu;
label_1cd48c:
    // 0x1cd48c: 0x29010064  slti        $at, $t0, 0x64
    ctx->pc = 0x1cd48cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)100) ? 1 : 0);
    // 0x1cd490: 0x1020000d  beqz        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CD490u;
    {
        const bool branch_taken_0x1cd490 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD490u;
            // 0x1cd494: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd490) {
            ctx->pc = 0x1CD4C8u;
            goto label_1cd4c8;
        }
    }
    ctx->pc = 0x1CD498u;
    // 0x1cd498: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd498u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd49c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd49cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd4a0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cd4a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1cd4a4: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd4a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd4ac: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd4acu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd4b0: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd4b0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd4b4: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd4b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd4b8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD4B8u;
    SET_GPR_U32(ctx, 31, 0x1CD4C0u);
    ctx->pc = 0x1CD4BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD4B8u;
            // 0x1cd4bc: 0x24a55fa8  addiu       $a1, $a1, 0x5FA8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24488));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD4C0u; }
        if (ctx->pc != 0x1CD4C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD4C0u; }
        if (ctx->pc != 0x1CD4C0u) { return; }
    }
    ctx->pc = 0x1CD4C0u;
label_1cd4c0:
    // 0x1cd4c0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CD4C0u;
    {
        const bool branch_taken_0x1cd4c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd4c0) {
            ctx->pc = 0x1CD4ECu;
            goto label_1cd4ec;
        }
    }
    ctx->pc = 0x1CD4C8u;
label_1cd4c8:
    // 0x1cd4c8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd4c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd4cc: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cd4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1cd4d0: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd4d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd4d4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd4d8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd4d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd4dc: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd4dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd4e0: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd4e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd4e4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD4E4u;
    SET_GPR_U32(ctx, 31, 0x1CD4ECu);
    ctx->pc = 0x1CD4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD4E4u;
            // 0x1cd4e8: 0x24a55fb8  addiu       $a1, $a1, 0x5FB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD4ECu; }
        if (ctx->pc != 0x1CD4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD4ECu; }
        if (ctx->pc != 0x1CD4ECu) { return; }
    }
    ctx->pc = 0x1CD4ECu;
label_1cd4ec:
    // 0x1cd4ec: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD4ECu;
    {
        const bool branch_taken_0x1cd4ec = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD4F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD4ECu;
            // 0x1cd4f0: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd4ec) {
            ctx->pc = 0x1CD504u;
            goto label_1cd504;
        }
    }
    ctx->pc = 0x1CD4F4u;
    // 0x1cd4f4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd4f8: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd4fc: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CD4FCu;
    SET_GPR_U32(ctx, 31, 0x1CD504u);
    ctx->pc = 0x1CD500u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD4FCu;
            // 0x1cd500: 0x24a55fa0  addiu       $a1, $a1, 0x5FA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD504u; }
        if (ctx->pc != 0x1CD504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD504u; }
        if (ctx->pc != 0x1CD504u) { return; }
    }
    ctx->pc = 0x1CD504u;
label_1cd504:
    // 0x1cd504: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd504u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd508: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cd508u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cd50c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd50cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd510: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x1cd510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x1cd514: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD514u;
            // 0x1cd518: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD454u: goto label_1cd454;
            case 0x1CD45Cu: goto label_1cd45c;
            case 0x1CD484u: goto label_1cd484;
            case 0x1CD48Cu: goto label_1cd48c;
            case 0x1CD4C0u: goto label_1cd4c0;
            case 0x1CD4C8u: goto label_1cd4c8;
            case 0x1CD4ECu: goto label_1cd4ec;
            case 0x1CD504u: goto label_1cd504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD51Cu;
    // 0x1cd51c: 0x0  nop
    ctx->pc = 0x1cd51cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
