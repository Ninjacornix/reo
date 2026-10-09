#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD410
// Address: 0x1bd410 - 0x1bd690
void sub_001BD410_0x1bd410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD410_0x1bd410");
#endif

    switch (ctx->pc) {
        case 0x1bd448u: goto label_1bd448;
        case 0x1bd468u: goto label_1bd468;
        case 0x1bd498u: goto label_1bd498;
        case 0x1bd4b0u: goto label_1bd4b0;
        case 0x1bd4e8u: goto label_1bd4e8;
        case 0x1bd504u: goto label_1bd504;
        case 0x1bd534u: goto label_1bd534;
        case 0x1bd550u: goto label_1bd550;
        case 0x1bd578u: goto label_1bd578;
        case 0x1bd5c0u: goto label_1bd5c0;
        case 0x1bd5d0u: goto label_1bd5d0;
        case 0x1bd5e8u: goto label_1bd5e8;
        case 0x1bd5f0u: goto label_1bd5f0;
        default: break;
    }

    ctx->pc = 0x1bd410u;

    // 0x1bd410: 0x27bdfe50  addiu       $sp, $sp, -0x1B0
    ctx->pc = 0x1bd410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966864));
    // 0x1bd414: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bd414u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bd418: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1bd418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1bd41c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd41cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd420: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1bd420u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1bd424: 0x24844520  addiu       $a0, $a0, 0x4520
    ctx->pc = 0x1bd424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
    // 0x1bd428: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1bd428u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1bd42c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bd42cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd430: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1bd430u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1bd434: 0x24060340  addiu       $a2, $zero, 0x340
    ctx->pc = 0x1bd434u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 832));
    // 0x1bd438: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bd438u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bd43c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd43cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd440: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BD440u;
    SET_GPR_U32(ctx, 31, 0x1BD448u);
    ctx->pc = 0x1BD444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD440u;
            // 0x1bd444: 0xac204870  sw          $zero, 0x4870($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 18544), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD448u; }
        if (ctx->pc != 0x1BD448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD448u; }
        if (ctx->pc != 0x1BD448u) { return; }
    }
    ctx->pc = 0x1BD448u;
label_1bd448:
    // 0x1bd448: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd448u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd44c: 0x24054802  addiu       $a1, $zero, 0x4802
    ctx->pc = 0x1bd44cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18434));
    // 0x1bd450: 0x24840400  addiu       $a0, $a0, 0x400
    ctx->pc = 0x1bd450u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1024));
    // 0x1bd454: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd454u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd458: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd458u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd45c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd45cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd460: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD460u;
    SET_GPR_U32(ctx, 31, 0x1BD468u);
    ctx->pc = 0x1BD464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD460u;
            // 0x1bd464: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD468u; }
        if (ctx->pc != 0x1BD468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD468u; }
        if (ctx->pc != 0x1BD468u) { return; }
    }
    ctx->pc = 0x1BD468u;
label_1bd468:
    // 0x1bd468: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD468u;
    {
        const bool branch_taken_0x1bd468 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BD46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD468u;
            // 0x1bd46c: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd468) {
            ctx->pc = 0x1BD478u;
            goto label_1bd478;
        }
    }
    ctx->pc = 0x1BD470u;
    // 0x1bd470: 0x1000007e  b           . + 4 + (0x7E << 2)
    ctx->pc = 0x1BD470u;
    {
        const bool branch_taken_0x1bd470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD470u;
            // 0x1bd474: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd470) {
            ctx->pc = 0x1BD66Cu;
            goto label_1bd66c;
        }
    }
    ctx->pc = 0x1BD478u;
label_1bd478:
    // 0x1bd478: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd478u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd47c: 0x24054801  addiu       $a1, $zero, 0x4801
    ctx->pc = 0x1bd47cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18433));
    // 0x1bd480: 0x24840400  addiu       $a0, $a0, 0x400
    ctx->pc = 0x1bd480u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1024));
    // 0x1bd484: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd484u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd488: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd488u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd48c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd48cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd490: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD490u;
    SET_GPR_U32(ctx, 31, 0x1BD498u);
    ctx->pc = 0x1BD494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD490u;
            // 0x1bd494: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD498u; }
        if (ctx->pc != 0x1BD498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD498u; }
        if (ctx->pc != 0x1BD498u) { return; }
    }
    ctx->pc = 0x1BD498u;
label_1bd498:
    // 0x1bd498: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD498u;
    {
        const bool branch_taken_0x1bd498 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BD49Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD498u;
            // 0x1bd49c: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd498) {
            ctx->pc = 0x1BD4A8u;
            goto label_1bd4a8;
        }
    }
    ctx->pc = 0x1BD4A0u;
    // 0x1bd4a0: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1BD4A0u;
    {
        const bool branch_taken_0x1bd4a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd4a0) {
            ctx->pc = 0x1BD668u;
            goto label_1bd668;
        }
    }
    ctx->pc = 0x1BD4A8u;
label_1bd4a8:
    // 0x1bd4a8: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1BD4A8u;
    {
        const bool branch_taken_0x1bd4a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD4A8u;
            // 0x1bd4ac: 0x3c100004  lui         $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd4a8) {
            ctx->pc = 0x1BD51Cu;
            goto label_1bd51c;
        }
    }
    ctx->pc = 0x1BD4B0u;
label_1bd4b0:
    // 0x1bd4b0: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1bd4b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1bd4b4: 0x8c244870  lw          $a0, 0x4870($at)
    ctx->pc = 0x1bd4b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18544)));
    // 0x1bd4b8: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1bd4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1bd4bc: 0x24634520  addiu       $v1, $v1, 0x4520
    ctx->pc = 0x1bd4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17696));
    // 0x1bd4c0: 0x202102b  sltu        $v0, $s0, $v0
    ctx->pc = 0x1bd4c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1bd4c4: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x1bd4c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1bd4c8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd4c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd4cc: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BD4CCu;
    {
        const bool branch_taken_0x1bd4cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD4CCu;
            // 0x1bd4d0: 0xac70000c  sw          $s0, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd4cc) {
            ctx->pc = 0x1BD4F0u;
            goto label_1bd4f0;
        }
    }
    ctx->pc = 0x1BD4D4u;
    // 0x1bd4d4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bd4d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bd4d8: 0x24640010  addiu       $a0, $v1, 0x10
    ctx->pc = 0x1bd4d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1bd4dc: 0x103542  srl         $a2, $s0, 21
    ctx->pc = 0x1bd4dcu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 16), 21));
    // 0x1bd4e0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BD4E0u;
    SET_GPR_U32(ctx, 31, 0x1BD4E8u);
    ctx->pc = 0x1BD4E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD4E0u;
            // 0x1bd4e4: 0x24a50430  addiu       $a1, $a1, 0x430 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD4E8u; }
        if (ctx->pc != 0x1BD4E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD4E8u; }
        if (ctx->pc != 0x1BD4E8u) { return; }
    }
    ctx->pc = 0x1BD4E8u;
label_1bd4e8:
    // 0x1bd4e8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BD4E8u;
    {
        const bool branch_taken_0x1bd4e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd4e8) {
            ctx->pc = 0x1BD504u;
            goto label_1bd504;
        }
    }
    ctx->pc = 0x1BD4F0u;
label_1bd4f0:
    // 0x1bd4f0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bd4f0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bd4f4: 0x24640010  addiu       $a0, $v1, 0x10
    ctx->pc = 0x1bd4f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1bd4f8: 0x1032c2  srl         $a2, $s0, 11
    ctx->pc = 0x1bd4f8u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 16), 11));
    // 0x1bd4fc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BD4FCu;
    SET_GPR_U32(ctx, 31, 0x1BD504u);
    ctx->pc = 0x1BD500u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD4FCu;
            // 0x1bd500: 0x24a50438  addiu       $a1, $a1, 0x438 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD504u; }
        if (ctx->pc != 0x1BD504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD504u; }
        if (ctx->pc != 0x1BD504u) { return; }
    }
    ctx->pc = 0x1BD504u;
label_1bd504:
    // 0x1bd504: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd508: 0x108040  sll         $s0, $s0, 1
    ctx->pc = 0x1bd508u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1bd50c: 0x8c224870  lw          $v0, 0x4870($at)
    ctx->pc = 0x1bd50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18544)));
    // 0x1bd510: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bd510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bd514: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd514u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd518: 0xac224870  sw          $v0, 0x4870($at)
    ctx->pc = 0x1bd518u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 18544), GPR_U32(ctx, 2));
label_1bd51c:
    // 0x1bd51c: 0x250082b  sltu        $at, $s2, $s0
    ctx->pc = 0x1bd51cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1bd520: 0x1020ffe3  beqz        $at, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1BD520u;
    {
        const bool branch_taken_0x1bd520 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD520u;
            // 0x1bd524: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd520) {
            ctx->pc = 0x1BD4B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd4b0;
        }
    }
    ctx->pc = 0x1BD528u;
    // 0x1bd528: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd528u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd52c: 0xc04689c  jal         func_11A270
    ctx->pc = 0x1BD52Cu;
    SET_GPR_U32(ctx, 31, 0x1BD534u);
    ctx->pc = 0x1BD530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD52Cu;
            // 0x1bd530: 0x24840400  addiu       $a0, $a0, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11A270u;
    if (runtime->hasFunction(0x11A270u)) {
        auto targetFn = runtime->lookupFunction(0x11A270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD534u; }
        if (ctx->pc != 0x1BD534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011A270_0x11a270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD534u; }
        if (ctx->pc != 0x1BD534u) { return; }
    }
    ctx->pc = 0x1BD534u;
label_1bd534:
    // 0x1bd534: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD534u;
    {
        const bool branch_taken_0x1bd534 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BD538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD534u;
            // 0x1bd538: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd534) {
            ctx->pc = 0x1BD544u;
            goto label_1bd544;
        }
    }
    ctx->pc = 0x1BD53Cu;
    // 0x1bd53c: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1BD53Cu;
    {
        const bool branch_taken_0x1bd53c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd53c) {
            ctx->pc = 0x1BD668u;
            goto label_1bd668;
        }
    }
    ctx->pc = 0x1BD544u;
label_1bd544:
    // 0x1bd544: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1bd544u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd548: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1BD548u;
    {
        const bool branch_taken_0x1bd548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD548u;
            // 0x1bd54c: 0x27b00068  addiu       $s0, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd548) {
            ctx->pc = 0x1BD5B4u;
            goto label_1bd5b4;
        }
    }
    ctx->pc = 0x1BD550u;
label_1bd550:
    // 0x1bd550: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bd550u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd554: 0x8fa20060  lw          $v0, 0x60($sp)
    ctx->pc = 0x1bd554u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1bd558: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1BD558u;
    {
        const bool branch_taken_0x1bd558 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD55Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD558u;
            // 0x1bd55c: 0x2238821  addu        $s1, $s1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd558) {
            ctx->pc = 0x1BD5B4u;
            goto label_1bd5b4;
        }
    }
    ctx->pc = 0x1BD560u;
    // 0x1bd560: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd564: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bd564u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bd568: 0x8c274870  lw          $a3, 0x4870($at)
    ctx->pc = 0x1bd568u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18544)));
    // 0x1bd56c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bd56cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd570: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1BD570u;
    {
        const bool branch_taken_0x1bd570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD570u;
            // 0x1bd574: 0x24844520  addiu       $a0, $a0, 0x4520 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd570) {
            ctx->pc = 0x1BD5A8u;
            goto label_1bd5a8;
        }
    }
    ctx->pc = 0x1BD578u;
label_1bd578:
    // 0x1bd578: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bd578u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd57c: 0x823021  addu        $a2, $a0, $v0
    ctx->pc = 0x1bd57cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1bd580: 0x8cc2000c  lw          $v0, 0xC($a2)
    ctx->pc = 0x1bd580u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1bd584: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BD584u;
    {
        const bool branch_taken_0x1bd584 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1bd584) {
            ctx->pc = 0x1BD5A4u;
            goto label_1bd5a4;
        }
    }
    ctx->pc = 0x1BD58Cu;
    // 0x1bd58c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1bd58cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1bd590: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bd590u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bd594: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x1bd594u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1bd598: 0x8cc20008  lw          $v0, 0x8($a2)
    ctx->pc = 0x1bd598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1bd59c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bd59cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bd5a0: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x1bd5a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
label_1bd5a4:
    // 0x1bd5a4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1bd5a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1bd5a8:
    // 0x1bd5a8: 0xa7102b  sltu        $v0, $a1, $a3
    ctx->pc = 0x1bd5a8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1bd5ac: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1BD5ACu;
    {
        const bool branch_taken_0x1bd5ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD5ACu;
            // 0x1bd5b0: 0x51140  sll         $v0, $a1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd5ac) {
            ctx->pc = 0x1BD578u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd578;
        }
    }
    ctx->pc = 0x1BD5B4u;
label_1bd5b4:
    // 0x1bd5b4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1bd5b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd5b8: 0xc046928  jal         func_11A4A0
    ctx->pc = 0x1BD5B8u;
    SET_GPR_U32(ctx, 31, 0x1BD5C0u);
    ctx->pc = 0x1BD5BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD5B8u;
            // 0x1bd5bc: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11A4A0u;
    if (runtime->hasFunction(0x11A4A0u)) {
        auto targetFn = runtime->lookupFunction(0x11A4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD5C0u; }
        if (ctx->pc != 0x1BD5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011A4A0_0x11a4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD5C0u; }
        if (ctx->pc != 0x1BD5C0u) { return; }
    }
    ctx->pc = 0x1BD5C0u;
label_1bd5c0:
    // 0x1bd5c0: 0x1c40ffe3  bgtz        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1BD5C0u;
    {
        const bool branch_taken_0x1bd5c0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1BD5C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD5C0u;
            // 0x1bd5c4: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd5c0) {
            ctx->pc = 0x1BD550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd550;
        }
    }
    ctx->pc = 0x1BD5C8u;
    // 0x1bd5c8: 0xc0468ce  jal         func_11A338
    ctx->pc = 0x1BD5C8u;
    SET_GPR_U32(ctx, 31, 0x1BD5D0u);
    ctx->pc = 0x11A338u;
    if (runtime->hasFunction(0x11A338u)) {
        auto targetFn = runtime->lookupFunction(0x11A338u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD5D0u; }
        if (ctx->pc != 0x1BD5D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011A338_0x11a338(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD5D0u; }
        if (ctx->pc != 0x1BD5D0u) { return; }
    }
    ctx->pc = 0x1BD5D0u;
label_1bd5d0:
    // 0x1bd5d0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd5d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd5d4: 0x8c224870  lw          $v0, 0x4870($at)
    ctx->pc = 0x1bd5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18544)));
    // 0x1bd5d8: 0x2446ffff  addiu       $a2, $v0, -0x1
    ctx->pc = 0x1bd5d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bd5dc: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1bd5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1bd5e0: 0x24634520  addiu       $v1, $v1, 0x4520
    ctx->pc = 0x1bd5e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17696));
    // 0x1bd5e4: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1bd5e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1bd5e8:
    // 0x1bd5e8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1BD5E8u;
    {
        const bool branch_taken_0x1bd5e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD5ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD5E8u;
            // 0x1bd5ec: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd5e8) {
            ctx->pc = 0x1BD644u;
            goto label_1bd644;
        }
    }
    ctx->pc = 0x1BD5F0u;
label_1bd5f0:
    // 0x1bd5f0: 0x224001b  divu        $zero, $s1, $a0
    ctx->pc = 0x1bd5f0u;
    { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 17) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,17); } }
    // 0x1bd5f4: 0x0  nop
    ctx->pc = 0x1bd5f4u;
    // NOP
    // 0x1bd5f8: 0x0  nop
    ctx->pc = 0x1bd5f8u;
    // NOP
    // 0x1bd5fc: 0x1010  mfhi        $v0
    ctx->pc = 0x1bd5fcu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1bd600: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BD600u;
    {
        const bool branch_taken_0x1bd600 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD600u;
            // 0x1bd604: 0x2241021  addu        $v0, $s1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd600) {
            ctx->pc = 0x1BD63Cu;
            goto label_1bd63c;
        }
    }
    ctx->pc = 0x1BD608u;
    // 0x1bd608: 0x53082b  sltu        $at, $v0, $s3
    ctx->pc = 0x1bd608u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x1bd60c: 0x1020000b  beqz        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1BD60Cu;
    {
        const bool branch_taken_0x1bd60c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd60c) {
            ctx->pc = 0x1BD63Cu;
            goto label_1bd63c;
        }
    }
    ctx->pc = 0x1BD614u;
    // 0x1bd614: 0x51140  sll         $v0, $a1, 5
    ctx->pc = 0x1bd614u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 5));
    // 0x1bd618: 0x2248821  addu        $s1, $s1, $a0
    ctx->pc = 0x1bd618u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x1bd61c: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1bd61cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1bd620: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1bd620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1bd624: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bd624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bd628: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1bd628u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1bd62c: 0x8ca20008  lw          $v0, 0x8($a1)
    ctx->pc = 0x1bd62cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1bd630: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bd630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bd634: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BD634u;
    {
        const bool branch_taken_0x1bd634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD634u;
            // 0x1bd638: 0xaca20008  sw          $v0, 0x8($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd634) {
            ctx->pc = 0x1BD654u;
            goto label_1bd654;
        }
    }
    ctx->pc = 0x1BD63Cu;
label_1bd63c:
    // 0x1bd63c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1bd63cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1bd640: 0x42042  srl         $a0, $a0, 1
    ctx->pc = 0x1bd640u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
label_1bd644:
    // 0x1bd644: 0x3c010004  lui         $at, 0x4
    ctx->pc = 0x1bd644u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
    // 0x1bd648: 0x81082b  sltu        $at, $a0, $at
    ctx->pc = 0x1bd648u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 1)) ? 1 : 0);
    // 0x1bd64c: 0x1020ffe8  beqz        $at, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1BD64Cu;
    {
        const bool branch_taken_0x1bd64c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd64c) {
            ctx->pc = 0x1BD5F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd5f0;
        }
    }
    ctx->pc = 0x1BD654u;
label_1bd654:
    // 0x1bd654: 0x3c010004  lui         $at, 0x4
    ctx->pc = 0x1bd654u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
    // 0x1bd658: 0x81082b  sltu        $at, $a0, $at
    ctx->pc = 0x1bd658u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 1)) ? 1 : 0);
    // 0x1bd65c: 0x1020ffe2  beqz        $at, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1BD65Cu;
    {
        const bool branch_taken_0x1bd65c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD65Cu;
            // 0x1bd660: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd65c) {
            ctx->pc = 0x1BD5E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd5e8;
        }
    }
    ctx->pc = 0x1BD664u;
    // 0x1bd664: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1bd664u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1bd668:
    // 0x1bd668: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1bd668u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1bd66c:
    // 0x1bd66c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1bd66cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1bd670: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1bd670u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1bd674: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1bd674u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bd678: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bd678u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bd67c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd67cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd680: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD680u;
            // 0x1bd684: 0x27bd01b0  addiu       $sp, $sp, 0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 432));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD448u: goto label_1bd448;
            case 0x1BD468u: goto label_1bd468;
            case 0x1BD478u: goto label_1bd478;
            case 0x1BD498u: goto label_1bd498;
            case 0x1BD4A8u: goto label_1bd4a8;
            case 0x1BD4B0u: goto label_1bd4b0;
            case 0x1BD4E8u: goto label_1bd4e8;
            case 0x1BD4F0u: goto label_1bd4f0;
            case 0x1BD504u: goto label_1bd504;
            case 0x1BD51Cu: goto label_1bd51c;
            case 0x1BD534u: goto label_1bd534;
            case 0x1BD544u: goto label_1bd544;
            case 0x1BD550u: goto label_1bd550;
            case 0x1BD578u: goto label_1bd578;
            case 0x1BD5A4u: goto label_1bd5a4;
            case 0x1BD5A8u: goto label_1bd5a8;
            case 0x1BD5B4u: goto label_1bd5b4;
            case 0x1BD5C0u: goto label_1bd5c0;
            case 0x1BD5D0u: goto label_1bd5d0;
            case 0x1BD5E8u: goto label_1bd5e8;
            case 0x1BD5F0u: goto label_1bd5f0;
            case 0x1BD63Cu: goto label_1bd63c;
            case 0x1BD644u: goto label_1bd644;
            case 0x1BD654u: goto label_1bd654;
            case 0x1BD668u: goto label_1bd668;
            case 0x1BD66Cu: goto label_1bd66c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD688u;
    // 0x1bd688: 0x0  nop
    ctx->pc = 0x1bd688u;
    // NOP
    // 0x1bd68c: 0x0  nop
    ctx->pc = 0x1bd68cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
