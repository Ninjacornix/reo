#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159820
// Address: 0x159820 - 0x1598c8
void sub_00159820_0x159820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159820_0x159820");
#endif

    switch (ctx->pc) {
        case 0x159854u: goto label_159854;
        case 0x15987cu: goto label_15987c;
        case 0x159890u: goto label_159890;
        default: break;
    }

    ctx->pc = 0x159820u;

    // 0x159820: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x159820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x159824: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x159824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159828: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x159828u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15982c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15982cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x159830: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x159830u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159834: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x159834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x159838: 0x8e230354  lw          $v1, 0x354($s1)
    ctx->pc = 0x159838u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 852)));
    // 0x15983c: 0x1460001c  bnez        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x15983Cu;
    {
        const bool branch_taken_0x15983c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x159840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15983Cu;
            // 0x159840: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15983c) {
            ctx->pc = 0x1598B0u;
            goto label_1598b0;
        }
    }
    ctx->pc = 0x159844u;
    // 0x159844: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x159844u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x159848: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x159848u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x15984c: 0xc0561d4  jal         func_158750
    ctx->pc = 0x15984Cu;
    SET_GPR_U32(ctx, 31, 0x159854u);
    ctx->pc = 0x159850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15984Cu;
            // 0x159850: 0x8e050004  lw          $a1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159854u; }
        if (ctx->pc != 0x159854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159854u; }
        if (ctx->pc != 0x159854u) { return; }
    }
    ctx->pc = 0x159854u;
label_159854:
    // 0x159854: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x159854u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159858: 0x10600014  beqz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x159858u;
    {
        const bool branch_taken_0x159858 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15985Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159858u;
            // 0x15985c: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159858) {
            ctx->pc = 0x1598ACu;
            goto label_1598ac;
        }
    }
    ctx->pc = 0x159860u;
    // 0x159860: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x159860u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x159864: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x159864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x159868: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x159868u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15986c: 0x652823  subu        $a1, $v1, $a1
    ctx->pc = 0x15986cu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x159870: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x159870u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x159874: 0xc0561d4  jal         func_158750
    ctx->pc = 0x159874u;
    SET_GPR_U32(ctx, 31, 0x15987Cu);
    ctx->pc = 0x159878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159874u;
            // 0x159878: 0x452823  subu        $a1, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15987Cu; }
        if (ctx->pc != 0x15987Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15987Cu; }
        if (ctx->pc != 0x15987Cu) { return; }
    }
    ctx->pc = 0x15987Cu;
label_15987c:
    // 0x15987c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x15987cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159880: 0x5060000b  beql        $v1, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x159880u;
    {
        const bool branch_taken_0x159880 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x159880) {
            ctx->pc = 0x159884u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x159880u;
            // 0x159884: 0x8e220354  lw          $v0, 0x354($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 852)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1598B0u;
            goto label_1598b0;
        }
    }
    ctx->pc = 0x159888u;
    // 0x159888: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x159888u;
    SET_GPR_U32(ctx, 31, 0x159890u);
    ctx->pc = 0x15988Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159888u;
            // 0x15988c: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159890u; }
        if (ctx->pc != 0x159890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159890u; }
        if (ctx->pc != 0x159890u) { return; }
    }
    ctx->pc = 0x159890u;
label_159890:
    // 0x159890: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x159890u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159894: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x159894u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x159898: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x159898u;
    {
        const bool branch_taken_0x159898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15989Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159898u;
            // 0x15989c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159898) {
            ctx->pc = 0x1598A8u;
            goto label_1598a8;
        }
    }
    ctx->pc = 0x1598A0u;
    // 0x1598a0: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1598A0u;
    {
        const bool branch_taken_0x1598a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1598A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1598A0u;
            // 0x1598a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1598a0) {
            ctx->pc = 0x1598ACu;
            goto label_1598ac;
        }
    }
    ctx->pc = 0x1598A8u;
label_1598a8:
    // 0x1598a8: 0xae220354  sw          $v0, 0x354($s1)
    ctx->pc = 0x1598a8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 852), GPR_U32(ctx, 2));
label_1598ac:
    // 0x1598ac: 0x8e220354  lw          $v0, 0x354($s1)
    ctx->pc = 0x1598acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 852)));
label_1598b0:
    // 0x1598b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1598b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1598b4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1598b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1598b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1598b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1598bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1598BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1598C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1598BCu;
            // 0x1598c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159854u: goto label_159854;
            case 0x15987Cu: goto label_15987c;
            case 0x159890u: goto label_159890;
            case 0x1598A8u: goto label_1598a8;
            case 0x1598ACu: goto label_1598ac;
            case 0x1598B0u: goto label_1598b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1598C4u;
    // 0x1598c4: 0x0  nop
    ctx->pc = 0x1598c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
