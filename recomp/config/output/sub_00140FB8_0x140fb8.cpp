#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140FB8
// Address: 0x140fb8 - 0x1410c8
void sub_00140FB8_0x140fb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140FB8_0x140fb8");
#endif

    switch (ctx->pc) {
        case 0x140ff8u: goto label_140ff8;
        case 0x141000u: goto label_141000;
        case 0x141020u: goto label_141020;
        case 0x141074u: goto label_141074;
        case 0x141098u: goto label_141098;
        default: break;
    }

    ctx->pc = 0x140fb8u;

    // 0x140fb8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x140fb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x140fbc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x140fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x140fc0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x140fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x140fc4: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x140fc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140fc8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x140fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x140fcc: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x140fccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140fd0: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x140fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x140fd4: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x140fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x140fd8: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x140fd8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140fdc: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x140fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x140fe0: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x140fe0u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140fe4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x140fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x140fe8: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x140fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x140fec: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x140fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x140ff0: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140FF0u;
    SET_GPR_U32(ctx, 31, 0x140FF8u);
    ctx->pc = 0x140FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140FF0u;
            // 0x140ff4: 0x26d50010  addiu       $s5, $s6, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140FF8u; }
        if (ctx->pc != 0x140FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140FF8u; }
        if (ctx->pc != 0x140FF8u) { return; }
    }
    ctx->pc = 0x140FF8u;
label_140ff8:
    // 0x140ff8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x140ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x140ffc: 0x24519a90  addiu       $s1, $v0, -0x6570
    ctx->pc = 0x140ffcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941328));
label_141000:
    // 0x141000: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x141000u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x141004: 0x5457001f  bnel        $v0, $s7, . + 4 + (0x1F << 2)
    ctx->pc = 0x141004u;
    {
        const bool branch_taken_0x141004 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 23));
        if (branch_taken_0x141004) {
            ctx->pc = 0x141008u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141004u;
            // 0x141008: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141084u;
            goto label_141084;
        }
    }
    ctx->pc = 0x14100Cu;
    // 0x14100c: 0x121100  sll         $v0, $s2, 4
    ctx->pc = 0x14100cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x141010: 0x24140080  addiu       $s4, $zero, 0x80
    ctx->pc = 0x141010u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x141014: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x141014u;
    {
        const bool branch_taken_0x141014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x141018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141014u;
            // 0x141018: 0x558021  addu        $s0, $v0, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141014) {
            ctx->pc = 0x141050u;
            goto label_141050;
        }
    }
    ctx->pc = 0x14101Cu;
    // 0x14101c: 0x0  nop
    ctx->pc = 0x14101cu;
    // NOP
label_141020:
    // 0x141020: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x141020u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x141024: 0x9222000c  lbu         $v0, 0xC($s1)
    ctx->pc = 0x141024u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x141028: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x141028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x14102c: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x14102cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x141030: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x141030u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x141034: 0x96220002  lhu         $v0, 0x2($s1)
    ctx->pc = 0x141034u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x141038: 0x6ba30007  ldl         $v1, 0x7($sp)
    ctx->pc = 0x141038u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x14103c: 0x6fa30000  ldr         $v1, 0x0($sp)
    ctx->pc = 0x14103cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x141040: 0xb203000f  sdl         $v1, 0xF($s0)
    ctx->pc = 0x141040u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x141044: 0xb6030008  sdr         $v1, 0x8($s0)
    ctx->pc = 0x141044u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x141048: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x141048u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14104c: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x14104cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_141050:
    // 0x141050: 0x1254000f  beq         $s2, $s4, . + 4 + (0xF << 2)
    ctx->pc = 0x141050u;
    {
        const bool branch_taken_0x141050 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 20));
        ctx->pc = 0x141054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141050u;
            // 0x141054: 0x3c067fff  lui         $a2, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141050) {
            ctx->pc = 0x141090u;
            goto label_141090;
        }
    }
    ctx->pc = 0x141058u;
    // 0x141058: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x141058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x14105c: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x14105cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x141060: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x141060u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x141064: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141064u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141068: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x141068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x14106c: 0x40f809  jalr        $v0
    ctx->pc = 0x14106Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141074u);
        ctx->pc = 0x141070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14106Cu;
            // 0x141070: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141074u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141074u; }
            if (ctx->pc != 0x141074u) { return; }
        }
        }
    }
    ctx->pc = 0x141074u;
label_141074:
    // 0x141074: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x141074u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x141078: 0x5460ffe9  bnel        $v1, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x141078u;
    {
        const bool branch_taken_0x141078 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x141078) {
            ctx->pc = 0x14107Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141078u;
            // 0x14107c: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141020u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141020;
        }
    }
    ctx->pc = 0x141080u;
    // 0x141080: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x141080u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_141084:
    // 0x141084: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x141084u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x141088: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0x141088u;
    {
        const bool branch_taken_0x141088 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141088u;
            // 0x14108c: 0x26310014  addiu       $s1, $s1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141088) {
            ctx->pc = 0x141000u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141000;
        }
    }
    ctx->pc = 0x141090u;
label_141090:
    // 0x141090: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x141090u;
    SET_GPR_U32(ctx, 31, 0x141098u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141098u; }
        if (ctx->pc != 0x141098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141098u; }
        if (ctx->pc != 0x141098u) { return; }
    }
    ctx->pc = 0x141098u;
label_141098:
    // 0x141098: 0xaed20000  sw          $s2, 0x0($s6)
    ctx->pc = 0x141098u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 18));
    // 0x14109c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14109cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1410a0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1410a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1410a4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1410a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1410a8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1410a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1410ac: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1410acu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1410b0: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1410b0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1410b4: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x1410b4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1410b8: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x1410b8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1410bc: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1410bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1410c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1410C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1410C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1410C0u;
            // 0x1410c4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1410C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
