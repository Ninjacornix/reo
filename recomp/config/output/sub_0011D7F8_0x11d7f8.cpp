#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D7F8
// Address: 0x11d7f8 - 0x11d8f8
void sub_0011D7F8_0x11d7f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D7F8_0x11d7f8");
#endif

    switch (ctx->pc) {
        case 0x11d838u: goto label_11d838;
        case 0x11d844u: goto label_11d844;
        case 0x11d854u: goto label_11d854;
        case 0x11d868u: goto label_11d868;
        case 0x11d880u: goto label_11d880;
        case 0x11d894u: goto label_11d894;
        case 0x11d8b0u: goto label_11d8b0;
        default: break;
    }

    ctx->pc = 0x11d7f8u;

    // 0x11d7f8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x11d7f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x11d7fc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11d7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11d800: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x11d800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x11d804: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11d804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11d808: 0x3c150012  lui         $s5, 0x12
    ctx->pc = 0x11d808u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)18 << 16));
    // 0x11d80c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11d80cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11d810: 0x3c140012  lui         $s4, 0x12
    ctx->pc = 0x11d810u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)18 << 16));
    // 0x11d814: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11d814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11d818: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11d818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11d81c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11d81cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11d820: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x11d820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11d824: 0x2450a460  addiu       $s0, $v0, -0x5BA0
    ctx->pc = 0x11d824u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943840));
    // 0x11d828: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x11d828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x11d82c: 0x8c44a460  lw          $a0, -0x5BA0($v0)
    ctx->pc = 0x11d82cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943840)));
    // 0x11d830: 0xc04763e  jal         func_11D8F8
    ctx->pc = 0x11D830u;
    SET_GPR_U32(ctx, 31, 0x11D838u);
    ctx->pc = 0x11D834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D830u;
            // 0x11d834: 0x8e050004  lw          $a1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D8F8u;
    if (runtime->hasFunction(0x11D8F8u)) {
        auto targetFn = runtime->lookupFunction(0x11D8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D838u; }
        if (ctx->pc != 0x11D838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D8F8_0x11d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D838u; }
        if (ctx->pc != 0x11D838u) { return; }
    }
    ctx->pc = 0x11D838u;
label_11d838:
    // 0x11d838: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x11d838u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11d83c: 0xc04763e  jal         func_11D8F8
    ctx->pc = 0x11D83Cu;
    SET_GPR_U32(ctx, 31, 0x11D844u);
    ctx->pc = 0x11D840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D83Cu;
            // 0x11d840: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D8F8u;
    if (runtime->hasFunction(0x11D8F8u)) {
        auto targetFn = runtime->lookupFunction(0x11D8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D844u; }
        if (ctx->pc != 0x11D844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D8F8_0x11d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D844u; }
        if (ctx->pc != 0x11D844u) { return; }
    }
    ctx->pc = 0x11D844u;
label_11d844:
    // 0x11d844: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11d844u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x11d848: 0x3c058008  lui         $a1, 0x8008
    ctx->pc = 0x11d848u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32776 << 16));
    // 0x11d84c: 0xc0475ec  jal         func_11D7B0
    ctx->pc = 0x11D84Cu;
    SET_GPR_U32(ctx, 31, 0x11D854u);
    ctx->pc = 0x11D850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D84Cu;
            // 0x11d850: 0x26a6d770  addiu       $a2, $s5, -0x2890 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), 4294956912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D7B0u;
    if (runtime->hasFunction(0x11D7B0u)) {
        auto targetFn = runtime->lookupFunction(0x11D7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D854u; }
        if (ctx->pc != 0x11D854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D854u; }
        if (ctx->pc != 0x11D854u) { return; }
    }
    ctx->pc = 0x11D854u;
label_11d854:
    // 0x11d854: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x11d854u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d858: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11d858u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x11d85c: 0x3c058008  lui         $a1, 0x8008
    ctx->pc = 0x11d85cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32776 << 16));
    // 0x11d860: 0xc0475ec  jal         func_11D7B0
    ctx->pc = 0x11D860u;
    SET_GPR_U32(ctx, 31, 0x11D868u);
    ctx->pc = 0x11D864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D860u;
            // 0x11d864: 0x2686d738  addiu       $a2, $s4, -0x28C8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D7B0u;
    if (runtime->hasFunction(0x11D7B0u)) {
        auto targetFn = runtime->lookupFunction(0x11D7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D868u; }
        if (ctx->pc != 0x11D868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D868u; }
        if (ctx->pc != 0x11D868u) { return; }
    }
    ctx->pc = 0x11D868u;
label_11d868:
    // 0x11d868: 0x2671fdf4  addiu       $s1, $s3, -0x20C
    ctx->pc = 0x11d868u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966772));
    // 0x11d86c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11d86cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d870: 0x2650fe98  addiu       $s0, $s2, -0x168
    ctx->pc = 0x11d870u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294966936));
    // 0x11d874: 0x12300014  beq         $s1, $s0, . + 4 + (0x14 << 2)
    ctx->pc = 0x11D874u;
    {
        const bool branch_taken_0x11d874 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 16));
        ctx->pc = 0x11D878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D874u;
            // 0x11d878: 0x3c160021  lui         $s6, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d874) {
            ctx->pc = 0x11D8C8u;
            goto label_11d8c8;
        }
    }
    ctx->pc = 0x11D87Cu;
    // 0x11d87c: 0x230102b  sltu        $v0, $s1, $s0
    ctx->pc = 0x11d87cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
label_11d880:
    // 0x11d880: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11D880u;
    {
        const bool branch_taken_0x11d880 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D880u;
            // 0x11d884: 0x26640004  addiu       $a0, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d880) {
            ctx->pc = 0x11D8A0u;
            goto label_11d8a0;
        }
    }
    ctx->pc = 0x11D888u;
    // 0x11d888: 0x3c058008  lui         $a1, 0x8008
    ctx->pc = 0x11d888u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32776 << 16));
    // 0x11d88c: 0xc0475ec  jal         func_11D7B0
    ctx->pc = 0x11D88Cu;
    SET_GPR_U32(ctx, 31, 0x11D894u);
    ctx->pc = 0x11D890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D88Cu;
            // 0x11d890: 0x26a6d770  addiu       $a2, $s5, -0x2890 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), 4294956912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D7B0u;
    if (runtime->hasFunction(0x11D7B0u)) {
        auto targetFn = runtime->lookupFunction(0x11D7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D894u; }
        if (ctx->pc != 0x11D894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D894u; }
        if (ctx->pc != 0x11D894u) { return; }
    }
    ctx->pc = 0x11D894u;
label_11d894:
    // 0x11d894: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x11d894u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d898: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x11D898u;
    {
        const bool branch_taken_0x11d898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D89Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D898u;
            // 0x11d89c: 0x2671fdf4  addiu       $s1, $s3, -0x20C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 4294966772));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d898) {
            ctx->pc = 0x11D8B8u;
            goto label_11d8b8;
        }
    }
    ctx->pc = 0x11D8A0u;
label_11d8a0:
    // 0x11d8a0: 0x26440004  addiu       $a0, $s2, 0x4
    ctx->pc = 0x11d8a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x11d8a4: 0x3c058008  lui         $a1, 0x8008
    ctx->pc = 0x11d8a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32776 << 16));
    // 0x11d8a8: 0xc0475ec  jal         func_11D7B0
    ctx->pc = 0x11D8A8u;
    SET_GPR_U32(ctx, 31, 0x11D8B0u);
    ctx->pc = 0x11D8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D8A8u;
            // 0x11d8ac: 0x2686d738  addiu       $a2, $s4, -0x28C8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D7B0u;
    if (runtime->hasFunction(0x11D7B0u)) {
        auto targetFn = runtime->lookupFunction(0x11D7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D8B0u; }
        if (ctx->pc != 0x11D8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D7B0_0x11d7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D8B0u; }
        if (ctx->pc != 0x11D8B0u) { return; }
    }
    ctx->pc = 0x11D8B0u;
label_11d8b0:
    // 0x11d8b0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11d8b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d8b4: 0x2650fe98  addiu       $s0, $s2, -0x168
    ctx->pc = 0x11d8b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294966936));
label_11d8b8:
    // 0x11d8b8: 0x1630fff1  bne         $s1, $s0, . + 4 + (-0xF << 2)
    ctx->pc = 0x11D8B8u;
    {
        const bool branch_taken_0x11d8b8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        ctx->pc = 0x11D8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D8B8u;
            // 0x11d8bc: 0x230102b  sltu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d8b8) {
            ctx->pc = 0x11D880u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d880;
        }
    }
    ctx->pc = 0x11D8C0u;
    // 0x11d8c0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11D8C0u;
    {
        const bool branch_taken_0x11d8c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D8C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D8C0u;
            // 0x11d8c4: 0xaed1a458  sw          $s1, -0x5BA8($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 4294943832), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d8c0) {
            ctx->pc = 0x11D8CCu;
            goto label_11d8cc;
        }
    }
    ctx->pc = 0x11D8C8u;
label_11d8c8:
    // 0x11d8c8: 0xaed1a458  sw          $s1, -0x5BA8($s6)
    ctx->pc = 0x11d8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 4294943832), GPR_U32(ctx, 17));
label_11d8cc:
    // 0x11d8cc: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x11d8ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11d8d0: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x11d8d0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11d8d4: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x11d8d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11d8d8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11d8d8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11d8dc: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11d8dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11d8e0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11d8e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11d8e4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11d8e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11d8e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11d8e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d8ec: 0x3e00008  jr          $ra
    ctx->pc = 0x11D8ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D8F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D8ECu;
            // 0x11d8f0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D838u: goto label_11d838;
            case 0x11D844u: goto label_11d844;
            case 0x11D854u: goto label_11d854;
            case 0x11D868u: goto label_11d868;
            case 0x11D880u: goto label_11d880;
            case 0x11D894u: goto label_11d894;
            case 0x11D8A0u: goto label_11d8a0;
            case 0x11D8B0u: goto label_11d8b0;
            case 0x11D8B8u: goto label_11d8b8;
            case 0x11D8C8u: goto label_11d8c8;
            case 0x11D8CCu: goto label_11d8cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D8F4u;
    // 0x11d8f4: 0x0  nop
    ctx->pc = 0x11d8f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
