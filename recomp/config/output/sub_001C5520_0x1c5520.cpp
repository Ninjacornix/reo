#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5520
// Address: 0x1c5520 - 0x1c55c0
void sub_001C5520_0x1c5520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5520_0x1c5520");
#endif

    switch (ctx->pc) {
        case 0x1c554cu: goto label_1c554c;
        case 0x1c5568u: goto label_1c5568;
        case 0x1c5578u: goto label_1c5578;
        case 0x1c55b0u: goto label_1c55b0;
        default: break;
    }

    ctx->pc = 0x1c5520u;

    // 0x1c5520: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c5520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c5524: 0x3c010002  lui         $at, 0x2
    ctx->pc = 0x1c5524u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)2 << 16));
    // 0x1c5528: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c5528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c552c: 0x3421fbc0  ori         $at, $at, 0xFBC0
    ctx->pc = 0x1c552cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)64448);
    // 0x1c5530: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5530u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5534: 0x34068000  ori         $a2, $zero, 0x8000
    ctx->pc = 0x1c5534u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1c5538: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c5538u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c553c: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1c553cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1c5540: 0x2012821  addu        $a1, $s0, $at
    ctx->pc = 0x1c5540u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 1)));
    // 0x1c5544: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C5544u;
    SET_GPR_U32(ctx, 31, 0x1C554Cu);
    ctx->pc = 0x1C5548u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5544u;
            // 0x1c5548: 0x2484f080  addiu       $a0, $a0, -0xF80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C554Cu; }
        if (ctx->pc != 0x1C554Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C554Cu; }
        if (ctx->pc != 0x1C554Cu) { return; }
    }
    ctx->pc = 0x1C554Cu;
label_1c554c:
    // 0x1c554c: 0x3c010003  lui         $at, 0x3
    ctx->pc = 0x1c554cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)3 << 16));
    // 0x1c5550: 0x3c040037  lui         $a0, 0x37
    ctx->pc = 0x1c5550u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)55 << 16));
    // 0x1c5554: 0x34217bc0  ori         $at, $at, 0x7BC0
    ctx->pc = 0x1c5554u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)31680);
    // 0x1c5558: 0x2484f080  addiu       $a0, $a0, -0xF80
    ctx->pc = 0x1c5558u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963328));
    // 0x1c555c: 0x2012821  addu        $a1, $s0, $at
    ctx->pc = 0x1c555cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 1)));
    // 0x1c5560: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C5560u;
    SET_GPR_U32(ctx, 31, 0x1C5568u);
    ctx->pc = 0x1C5564u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5560u;
            // 0x1c5564: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5568u; }
        if (ctx->pc != 0x1C5568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5568u; }
        if (ctx->pc != 0x1C5568u) { return; }
    }
    ctx->pc = 0x1C5568u;
label_1c5568:
    // 0x1c5568: 0x3c050037  lui         $a1, 0x37
    ctx->pc = 0x1c5568u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)55 << 16));
    // 0x1c556c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1c556cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5570: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C5570u;
    {
        const bool branch_taken_0x1c5570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5570u;
            // 0x1c5574: 0x24a5f080  addiu       $a1, $a1, -0xF80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963328));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5570) {
            ctx->pc = 0x1C5588u;
            goto label_1c5588;
        }
    }
    ctx->pc = 0x1C5578u;
label_1c5578:
    // 0x1c5578: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x1c5578u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c557c: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C557Cu;
    {
        const bool branch_taken_0x1c557c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C557Cu;
            // 0x1c5580: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c557c) {
            ctx->pc = 0x1C559Cu;
            goto label_1c559c;
        }
    }
    ctx->pc = 0x1C5584u;
    // 0x1c5584: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1c5584u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1c5588:
    // 0x1c5588: 0x28830008  slti        $v1, $a0, 0x8
    ctx->pc = 0x1c5588u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1c558c: 0x0  nop
    ctx->pc = 0x1c558cu;
    // NOP
    // 0x1c5590: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C5590u;
    {
        const bool branch_taken_0x1c5590 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c5590) {
            ctx->pc = 0x1C5578u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5578;
        }
    }
    ctx->pc = 0x1C5598u;
    // 0x1c5598: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1c5598u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1c559c:
    // 0x1c559c: 0x10860004  beq         $a0, $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C559Cu;
    {
        const bool branch_taken_0x1c559c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        if (branch_taken_0x1c559c) {
            ctx->pc = 0x1C55B0u;
            goto label_1c55b0;
        }
    }
    ctx->pc = 0x1C55A4u;
    // 0x1c55a4: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1c55a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1c55a8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1C55A8u;
    SET_GPR_U32(ctx, 31, 0x1C55B0u);
    ctx->pc = 0x1C55ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C55A8u;
            // 0x1c55ac: 0x248465a8  addiu       $a0, $a0, 0x65A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C55B0u; }
        if (ctx->pc != 0x1C55B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C55B0u; }
        if (ctx->pc != 0x1C55B0u) { return; }
    }
    ctx->pc = 0x1C55B0u;
label_1c55b0:
    // 0x1c55b0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c55b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c55b4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c55b4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c55b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C55B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C55BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C55B8u;
            // 0x1c55bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C554Cu: goto label_1c554c;
            case 0x1C5568u: goto label_1c5568;
            case 0x1C5578u: goto label_1c5578;
            case 0x1C5588u: goto label_1c5588;
            case 0x1C559Cu: goto label_1c559c;
            case 0x1C55B0u: goto label_1c55b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C55C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
