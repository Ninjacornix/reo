#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B78A0
// Address: 0x1b78a0 - 0x1b7b00
void sub_001B78A0_0x1b78a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B78A0_0x1b78a0");
#endif

    switch (ctx->pc) {
        case 0x1b78f8u: goto label_1b78f8;
        case 0x1b7904u: goto label_1b7904;
        case 0x1b791cu: goto label_1b791c;
        case 0x1b792cu: goto label_1b792c;
        case 0x1b7938u: goto label_1b7938;
        case 0x1b7948u: goto label_1b7948;
        case 0x1b79c4u: goto label_1b79c4;
        case 0x1b79d4u: goto label_1b79d4;
        case 0x1b7a04u: goto label_1b7a04;
        case 0x1b7a18u: goto label_1b7a18;
        case 0x1b7ad4u: goto label_1b7ad4;
        case 0x1b7ae4u: goto label_1b7ae4;
        default: break;
    }

    ctx->pc = 0x1b78a0u;

label_1b78a0:
    // 0x1b78a0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1b78a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1b78a4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b78a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b78a8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b78a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b78ac: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b78acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b78b0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b78b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b78b4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b78b4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b78b8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b78b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b78bc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b78bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b78c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b78c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b78c4: 0x902343d6  lbu         $v1, 0x43D6($at)
    ctx->pc = 0x1b78c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17366)));
    // 0x1b78c8: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b78c8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b78cc: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B78CCu;
    {
        const bool branch_taken_0x1b78cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B78D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B78CCu;
            // 0x1b78d0: 0x2610aaf0  addiu       $s0, $s0, -0x5510 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b78cc) {
            ctx->pc = 0x1B78E4u;
            goto label_1b78e4;
        }
    }
    ctx->pc = 0x1B78D4u;
    // 0x1b78d4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b78d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b78d8: 0x902343ea  lbu         $v1, 0x43EA($at)
    ctx->pc = 0x1b78d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17386)));
    // 0x1b78dc: 0x10600059  beqz        $v1, . + 4 + (0x59 << 2)
    ctx->pc = 0x1B78DCu;
    {
        const bool branch_taken_0x1b78dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b78dc) {
            ctx->pc = 0x1B7A44u;
            goto label_1b7a44;
        }
    }
    ctx->pc = 0x1B78E4u;
label_1b78e4:
    // 0x1b78e4: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1b78e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b78e8: 0x10600015  beqz        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B78E8u;
    {
        const bool branch_taken_0x1b78e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B78ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B78E8u;
            // 0x1b78ec: 0x2404005f  addiu       $a0, $zero, 0x5F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b78e8) {
            ctx->pc = 0x1B7940u;
            goto label_1b7940;
        }
    }
    ctx->pc = 0x1B78F0u;
    // 0x1b78f0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B78F0u;
    SET_GPR_U32(ctx, 31, 0x1B78F8u);
    ctx->pc = 0x1B78F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B78F0u;
            // 0x1b78f4: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B78F8u; }
        if (ctx->pc != 0x1B78F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B78F8u; }
        if (ctx->pc != 0x1B78F8u) { return; }
    }
    ctx->pc = 0x1B78F8u;
label_1b78f8:
    // 0x1b78f8: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1b78f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1b78fc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B78FCu;
    SET_GPR_U32(ctx, 31, 0x1B7904u);
    ctx->pc = 0x1B7900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B78FCu;
            // 0x1b7900: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7904u; }
        if (ctx->pc != 0x1B7904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7904u; }
        if (ctx->pc != 0x1B7904u) { return; }
    }
    ctx->pc = 0x1B7904u;
label_1b7904:
    // 0x1b7904: 0x8e0200a0  lw          $v0, 0xA0($s0)
    ctx->pc = 0x1b7904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 160)));
    // 0x1b7908: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B7908u;
    {
        const bool branch_taken_0x1b7908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B790Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7908u;
            // 0x1b790c: 0x2404006c  addiu       $a0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7908) {
            ctx->pc = 0x1B7924u;
            goto label_1b7924;
        }
    }
    ctx->pc = 0x1B7910u;
    // 0x1b7910: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b7910u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b7914: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B7914u;
    SET_GPR_U32(ctx, 31, 0x1B791Cu);
    ctx->pc = 0x1B7918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7914u;
            // 0x1b7918: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B791Cu; }
        if (ctx->pc != 0x1B791Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B791Cu; }
        if (ctx->pc != 0x1B791Cu) { return; }
    }
    ctx->pc = 0x1B791Cu;
label_1b791c:
    // 0x1b791c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B791Cu;
    {
        const bool branch_taken_0x1b791c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B791Cu;
            // 0x1b7920: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b791c) {
            ctx->pc = 0x1B7930u;
            goto label_1b7930;
        }
    }
    ctx->pc = 0x1B7924u;
label_1b7924:
    // 0x1b7924: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B7924u;
    SET_GPR_U32(ctx, 31, 0x1B792Cu);
    ctx->pc = 0x1B7928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7924u;
            // 0x1b7928: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B792Cu; }
        if (ctx->pc != 0x1B792Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B792Cu; }
        if (ctx->pc != 0x1B792Cu) { return; }
    }
    ctx->pc = 0x1B792Cu;
label_1b792c:
    // 0x1b792c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b792cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1b7930:
    // 0x1b7930: 0xc06d6b8  jal         func_1B5AE0
    ctx->pc = 0x1B7930u;
    SET_GPR_U32(ctx, 31, 0x1B7938u);
    ctx->pc = 0x1B5AE0u;
    if (runtime->hasFunction(0x1B5AE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B5AE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7938u; }
        if (ctx->pc != 0x1B7938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5AE0_0x1b5ae0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7938u; }
        if (ctx->pc != 0x1B7938u) { return; }
    }
    ctx->pc = 0x1B7938u;
label_1b7938:
    // 0x1b7938: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1B7938u;
    {
        const bool branch_taken_0x1b7938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B793Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7938u;
            // 0x1b793c: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7938) {
            ctx->pc = 0x1B7A48u;
            goto label_1b7a48;
        }
    }
    ctx->pc = 0x1B7940u;
label_1b7940:
    // 0x1b7940: 0x8e130070  lw          $s3, 0x70($s0)
    ctx->pc = 0x1b7940u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x1b7944: 0x8e12004c  lw          $s2, 0x4C($s0)
    ctx->pc = 0x1b7944u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
label_1b7948:
    // 0x1b7948: 0x92840000  lbu         $a0, 0x0($s4)
    ctx->pc = 0x1b7948u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1b794c: 0x1080003c  beqz        $a0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1B794Cu;
    {
        const bool branch_taken_0x1b794c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B794Cu;
            // 0x1b7950: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b794c) {
            ctx->pc = 0x1B7A40u;
            goto label_1b7a40;
        }
    }
    ctx->pc = 0x1B7954u;
    // 0x1b7954: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1b7954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b7958: 0x14830007  bne         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B7958u;
    {
        const bool branch_taken_0x1b7958 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B795Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7958u;
            // 0x1b795c: 0x2c830080  sltiu       $v1, $a0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7958) {
            ctx->pc = 0x1B7978u;
            goto label_1b7978;
        }
    }
    ctx->pc = 0x1B7960u;
    // 0x1b7960: 0xae130070  sw          $s3, 0x70($s0)
    ctx->pc = 0x1b7960u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 19));
    // 0x1b7964: 0x8e04006c  lw          $a0, 0x6C($s0)
    ctx->pc = 0x1b7964u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 108)));
    // 0x1b7968: 0x8e030074  lw          $v1, 0x74($s0)
    ctx->pc = 0x1b7968u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
    // 0x1b796c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b796cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b7970: 0x1000fff5  b           . + 4 + (-0xB << 2)
    ctx->pc = 0x1B7970u;
    {
        const bool branch_taken_0x1b7970 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7970u;
            // 0x1b7974: 0xae030074  sw          $v1, 0x74($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7970) {
            ctx->pc = 0x1B7948u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7948;
        }
    }
    ctx->pc = 0x1B7978u;
label_1b7978:
    // 0x1b7978: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7978u;
    {
        const bool branch_taken_0x1b7978 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B797Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7978u;
            // 0x1b797c: 0x2c8100a0  sltiu       $at, $a0, 0xA0 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7978) {
            ctx->pc = 0x1B7988u;
            goto label_1b7988;
        }
    }
    ctx->pc = 0x1B7980u;
    // 0x1b7980: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B7980u;
    {
        const bool branch_taken_0x1b7980 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7980) {
            ctx->pc = 0x1B799Cu;
            goto label_1b799c;
        }
    }
    ctx->pc = 0x1B7988u;
label_1b7988:
    // 0x1b7988: 0x2c8300e0  sltiu       $v1, $a0, 0xE0
    ctx->pc = 0x1b7988u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
    // 0x1b798c: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B798Cu;
    {
        const bool branch_taken_0x1b798c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B798Cu;
            // 0x1b7990: 0x2c810100  sltiu       $at, $a0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b798c) {
            ctx->pc = 0x1B79B8u;
            goto label_1b79b8;
        }
    }
    ctx->pc = 0x1B7994u;
    // 0x1b7994: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B7994u;
    {
        const bool branch_taken_0x1b7994 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7994) {
            ctx->pc = 0x1B79B8u;
            goto label_1b79b8;
        }
    }
    ctx->pc = 0x1B799Cu;
label_1b799c:
    // 0x1b799c: 0x92830000  lbu         $v1, 0x0($s4)
    ctx->pc = 0x1b799cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1b79a0: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1B79A0u;
    {
        const bool branch_taken_0x1b79a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B79A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B79A0u;
            // 0x1b79a4: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b79a0) {
            ctx->pc = 0x1B7A40u;
            goto label_1b7a40;
        }
    }
    ctx->pc = 0x1B79A8u;
    // 0x1b79a8: 0x41200  sll         $v0, $a0, 8
    ctx->pc = 0x1b79a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1b79ac: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b79acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b79b0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B79B0u;
    {
        const bool branch_taken_0x1b79b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B79B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B79B0u;
            // 0x1b79b4: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b79b0) {
            ctx->pc = 0x1B79C8u;
            goto label_1b79c8;
        }
    }
    ctx->pc = 0x1B79B8u;
label_1b79b8:
    // 0x1b79b8: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1b79b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1b79bc: 0xc06d960  jal         func_1B6580
    ctx->pc = 0x1B79BCu;
    SET_GPR_U32(ctx, 31, 0x1B79C4u);
    ctx->pc = 0x1B79C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B79BCu;
            // 0x1b79c0: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6580u;
    if (runtime->hasFunction(0x1B6580u)) {
        auto targetFn = runtime->lookupFunction(0x1B6580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B79C4u; }
        if (ctx->pc != 0x1B79C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6580_0x1b6580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B79C4u; }
        if (ctx->pc != 0x1B79C4u) { return; }
    }
    ctx->pc = 0x1B79C4u;
label_1b79c4:
    // 0x1b79c4: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1b79c4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b79c8:
    // 0x1b79c8: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1b79c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1b79cc: 0xc06d93c  jal         func_1B64F0
    ctx->pc = 0x1B79CCu;
    SET_GPR_U32(ctx, 31, 0x1B79D4u);
    ctx->pc = 0x1B79D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B79CCu;
            // 0x1b79d0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B64F0u;
    if (runtime->hasFunction(0x1B64F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B64F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B79D4u; }
        if (ctx->pc != 0x1B79D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B64F0_0x1b64f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B79D4u; }
        if (ctx->pc != 0x1B79D4u) { return; }
    }
    ctx->pc = 0x1B79D4u;
label_1b79d4:
    // 0x1b79d4: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x1b79d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1b79d8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b79d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b79dc: 0xa3082b  sltu        $at, $a1, $v1
    ctx->pc = 0x1b79dcu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b79e0: 0x10200011  beqz        $at, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B79E0u;
    {
        const bool branch_taken_0x1b79e0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b79e0) {
            ctx->pc = 0x1B7A28u;
            goto label_1b7a28;
        }
    }
    ctx->pc = 0x1B79E8u;
    // 0x1b79e8: 0x8e040064  lw          $a0, 0x64($s0)
    ctx->pc = 0x1b79e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b79ec: 0x8e030060  lw          $v1, 0x60($s0)
    ctx->pc = 0x1b79ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1b79f0: 0x83082b  sltu        $at, $a0, $v1
    ctx->pc = 0x1b79f0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b79f4: 0x10200012  beqz        $at, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B79F4u;
    {
        const bool branch_taken_0x1b79f4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B79F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B79F4u;
            // 0x1b79f8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b79f4) {
            ctx->pc = 0x1B7A40u;
            goto label_1b7a40;
        }
    }
    ctx->pc = 0x1B79FCu;
    // 0x1b79fc: 0xc06d728  jal         func_1B5CA0
    ctx->pc = 0x1B79FCu;
    SET_GPR_U32(ctx, 31, 0x1B7A04u);
    ctx->pc = 0x1B5CA0u;
    if (runtime->hasFunction(0x1B5CA0u)) {
        auto targetFn = runtime->lookupFunction(0x1B5CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7A04u; }
        if (ctx->pc != 0x1B7A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5CA0_0x1b5ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7A04u; }
        if (ctx->pc != 0x1B7A04u) { return; }
    }
    ctx->pc = 0x1B7A04u;
label_1b7a04:
    // 0x1b7a04: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1b7a04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7a08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b7a08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7a0c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1b7a0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7a10: 0xc06dc74  jal         func_1B71D0
    ctx->pc = 0x1B7A10u;
    SET_GPR_U32(ctx, 31, 0x1B7A18u);
    ctx->pc = 0x1B7A14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7A10u;
            // 0x1b7a14: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B71D0u;
    if (runtime->hasFunction(0x1B71D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B71D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7A18u; }
        if (ctx->pc != 0x1B7A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B71D0_0x1b71d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7A18u; }
        if (ctx->pc != 0x1B7A18u) { return; }
    }
    ctx->pc = 0x1B7A18u;
label_1b7a18:
    // 0x1b7a18: 0x8e030064  lw          $v1, 0x64($s0)
    ctx->pc = 0x1b7a18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b7a1c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1b7a1cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7a20: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b7a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b7a24: 0xae030064  sw          $v1, 0x64($s0)
    ctx->pc = 0x1b7a24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 3));
label_1b7a28:
    // 0x1b7a28: 0x8e04006c  lw          $a0, 0x6C($s0)
    ctx->pc = 0x1b7a28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 108)));
    // 0x1b7a2c: 0x8e030070  lw          $v1, 0x70($s0)
    ctx->pc = 0x1b7a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x1b7a30: 0x2242006  srlv        $a0, $a0, $s1
    ctx->pc = 0x1b7a30u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 17) & 0x1F));
    // 0x1b7a34: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b7a34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b7a38: 0x1000ffc3  b           . + 4 + (-0x3D << 2)
    ctx->pc = 0x1B7A38u;
    {
        const bool branch_taken_0x1b7a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7A38u;
            // 0x1b7a3c: 0xae030070  sw          $v1, 0x70($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7a38) {
            ctx->pc = 0x1B7948u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7948;
        }
    }
    ctx->pc = 0x1B7A40u;
label_1b7a40:
    // 0x1b7a40: 0xae12004c  sw          $s2, 0x4C($s0)
    ctx->pc = 0x1b7a40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 18));
label_1b7a44:
    // 0x1b7a44: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b7a44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1b7a48:
    // 0x1b7a48: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b7a48u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b7a4c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b7a4cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b7a50: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b7a50u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b7a54: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b7a54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7a58: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7a58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7a5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7A5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7A5Cu;
            // 0x1b7a60: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B78A0u: goto label_1b78a0;
            case 0x1B78E4u: goto label_1b78e4;
            case 0x1B78F8u: goto label_1b78f8;
            case 0x1B7904u: goto label_1b7904;
            case 0x1B791Cu: goto label_1b791c;
            case 0x1B7924u: goto label_1b7924;
            case 0x1B792Cu: goto label_1b792c;
            case 0x1B7930u: goto label_1b7930;
            case 0x1B7938u: goto label_1b7938;
            case 0x1B7940u: goto label_1b7940;
            case 0x1B7948u: goto label_1b7948;
            case 0x1B7978u: goto label_1b7978;
            case 0x1B7988u: goto label_1b7988;
            case 0x1B799Cu: goto label_1b799c;
            case 0x1B79B8u: goto label_1b79b8;
            case 0x1B79C4u: goto label_1b79c4;
            case 0x1B79C8u: goto label_1b79c8;
            case 0x1B79D4u: goto label_1b79d4;
            case 0x1B7A04u: goto label_1b7a04;
            case 0x1B7A18u: goto label_1b7a18;
            case 0x1B7A28u: goto label_1b7a28;
            case 0x1B7A40u: goto label_1b7a40;
            case 0x1B7A44u: goto label_1b7a44;
            case 0x1B7A48u: goto label_1b7a48;
            case 0x1B7AB0u: goto label_1b7ab0;
            case 0x1B7ABCu: goto label_1b7abc;
            case 0x1B7AD4u: goto label_1b7ad4;
            case 0x1B7AE4u: goto label_1b7ae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7A64u;
    // 0x1b7a64: 0x0  nop
    ctx->pc = 0x1b7a64u;
    // NOP
    // 0x1b7a68: 0x0  nop
    ctx->pc = 0x1b7a68u;
    // NOP
    // 0x1b7a6c: 0x0  nop
    ctx->pc = 0x1b7a6cu;
    // NOP
    // 0x1b7a70: 0x27bdfd90  addiu       $sp, $sp, -0x270
    ctx->pc = 0x1b7a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966672));
    // 0x1b7a74: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b7a74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b7a78: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b7a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b7a7c: 0x28620008  slti        $v0, $v1, 0x8
    ctx->pc = 0x1b7a7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b7a80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7a80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7a84: 0xafa40228  sw          $a0, 0x228($sp)
    ctx->pc = 0x1b7a84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 552), GPR_U32(ctx, 4));
    // 0x1b7a88: 0xffa50238  sd          $a1, 0x238($sp)
    ctx->pc = 0x1b7a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 568), GPR_U64(ctx, 5));
    // 0x1b7a8c: 0xffa60240  sd          $a2, 0x240($sp)
    ctx->pc = 0x1b7a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 576), GPR_U64(ctx, 6));
    // 0x1b7a90: 0xffa70248  sd          $a3, 0x248($sp)
    ctx->pc = 0x1b7a90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 584), GPR_U64(ctx, 7));
    // 0x1b7a94: 0xffa80250  sd          $t0, 0x250($sp)
    ctx->pc = 0x1b7a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 592), GPR_U64(ctx, 8));
    // 0x1b7a98: 0xffa90258  sd          $t1, 0x258($sp)
    ctx->pc = 0x1b7a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 600), GPR_U64(ctx, 9));
    // 0x1b7a9c: 0xffaa0260  sd          $t2, 0x260($sp)
    ctx->pc = 0x1b7a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 10));
    // 0x1b7aa0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7AA0u;
    {
        const bool branch_taken_0x1b7aa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7AA0u;
            // 0x1b7aa4: 0xffab0268  sd          $t3, 0x268($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7aa0) {
            ctx->pc = 0x1B7AB0u;
            goto label_1b7ab0;
        }
    }
    ctx->pc = 0x1B7AA8u;
    // 0x1b7aa8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B7AA8u;
    {
        const bool branch_taken_0x1b7aa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7AA8u;
            // 0x1b7aac: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7aa8) {
            ctx->pc = 0x1B7ABCu;
            goto label_1b7abc;
        }
    }
    ctx->pc = 0x1B7AB0u;
label_1b7ab0:
    // 0x1b7ab0: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1b7ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b7ab4: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1b7ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7ab8: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1b7ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1b7abc:
    // 0x1b7abc: 0x8fa50228  lw          $a1, 0x228($sp)
    ctx->pc = 0x1b7abcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 552)));
    // 0x1b7ac0: 0x27a20270  addiu       $v0, $sp, 0x270
    ctx->pc = 0x1b7ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
    // 0x1b7ac4: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x1b7ac4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b7ac8: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x1b7ac8u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7acc: 0xc043e20  jal         func_10F880
    ctx->pc = 0x1B7ACCu;
    SET_GPR_U32(ctx, 31, 0x1B7AD4u);
    ctx->pc = 0x1B7AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7ACCu;
            // 0x1b7ad0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7AD4u; }
        if (ctx->pc != 0x1B7AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7AD4u; }
        if (ctx->pc != 0x1B7AD4u) { return; }
    }
    ctx->pc = 0x1B7AD4u;
label_1b7ad4:
    // 0x1b7ad4: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1b7ad4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1b7ad8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1b7ad8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b7adc: 0xc06de28  jal         func_1B78A0
    ctx->pc = 0x1B7ADCu;
    SET_GPR_U32(ctx, 31, 0x1B7AE4u);
    ctx->pc = 0x1B7AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7ADCu;
            // 0x1b7ae0: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B78A0u;
    goto label_1b78a0;
    ctx->pc = 0x1B7AE4u;
label_1b7ae4:
    // 0x1b7ae4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b7ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7ae8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7ae8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7aec: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7AECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7AECu;
            // 0x1b7af0: 0x27bd0270  addiu       $sp, $sp, 0x270 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B78A0u: goto label_1b78a0;
            case 0x1B78E4u: goto label_1b78e4;
            case 0x1B78F8u: goto label_1b78f8;
            case 0x1B7904u: goto label_1b7904;
            case 0x1B791Cu: goto label_1b791c;
            case 0x1B7924u: goto label_1b7924;
            case 0x1B792Cu: goto label_1b792c;
            case 0x1B7930u: goto label_1b7930;
            case 0x1B7938u: goto label_1b7938;
            case 0x1B7940u: goto label_1b7940;
            case 0x1B7948u: goto label_1b7948;
            case 0x1B7978u: goto label_1b7978;
            case 0x1B7988u: goto label_1b7988;
            case 0x1B799Cu: goto label_1b799c;
            case 0x1B79B8u: goto label_1b79b8;
            case 0x1B79C4u: goto label_1b79c4;
            case 0x1B79C8u: goto label_1b79c8;
            case 0x1B79D4u: goto label_1b79d4;
            case 0x1B7A04u: goto label_1b7a04;
            case 0x1B7A18u: goto label_1b7a18;
            case 0x1B7A28u: goto label_1b7a28;
            case 0x1B7A40u: goto label_1b7a40;
            case 0x1B7A44u: goto label_1b7a44;
            case 0x1B7A48u: goto label_1b7a48;
            case 0x1B7AB0u: goto label_1b7ab0;
            case 0x1B7ABCu: goto label_1b7abc;
            case 0x1B7AD4u: goto label_1b7ad4;
            case 0x1B7AE4u: goto label_1b7ae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7AF4u;
    // 0x1b7af4: 0x0  nop
    ctx->pc = 0x1b7af4u;
    // NOP
    // 0x1b7af8: 0x0  nop
    ctx->pc = 0x1b7af8u;
    // NOP
    // 0x1b7afc: 0x0  nop
    ctx->pc = 0x1b7afcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
