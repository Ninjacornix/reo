#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A6F90
// Address: 0x1a6f90 - 0x1a70c0
void sub_001A6F90_0x1a6f90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A6F90_0x1a6f90");
#endif

    switch (ctx->pc) {
        case 0x1a7080u: goto label_1a7080;
        case 0x1a70a0u: goto label_1a70a0;
        default: break;
    }

    ctx->pc = 0x1a6f90u;

    // 0x1a6f90: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1a6f90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a6f94: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6f94u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6f98: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1a6f98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a6f9c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a6f9cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a6fa0: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1a6fa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1a6fa4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1a6fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1a6fa8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a6fa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a6fac: 0x623821  addu        $a3, $v1, $v0
    ctx->pc = 0x1a6facu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a6fb0: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x1a6fb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1a6fb4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A6FB4u;
    {
        const bool branch_taken_0x1a6fb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6FB4u;
            // 0x1a6fb8: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6fb4) {
            ctx->pc = 0x1A6FC4u;
            goto label_1a6fc4;
        }
    }
    ctx->pc = 0x1A6FBCu;
    // 0x1a6fbc: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1A6FBCu;
    {
        const bool branch_taken_0x1a6fbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6FBCu;
            // 0x1a6fc0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6fbc) {
            ctx->pc = 0x1A7084u;
            goto label_1a7084;
        }
    }
    ctx->pc = 0x1A6FC4u;
label_1a6fc4:
    // 0x1a6fc4: 0x24630a24  addiu       $v1, $v1, 0xA24
    ctx->pc = 0x1a6fc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2596));
    // 0x1a6fc8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1a6fc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a6fcc: 0x14c0000e  bnez        $a2, . + 4 + (0xE << 2)
    ctx->pc = 0x1A6FCCu;
    {
        const bool branch_taken_0x1a6fcc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6FCCu;
            // 0x1a6fd0: 0xac660000  sw          $a2, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6fcc) {
            ctx->pc = 0x1A7008u;
            goto label_1a7008;
        }
    }
    ctx->pc = 0x1A6FD4u;
    // 0x1a6fd4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a6fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a6fd8: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A6FD8u;
    {
        const bool branch_taken_0x1a6fd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6FD8u;
            // 0x1a6fdc: 0xace30000  sw          $v1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6fd8) {
            ctx->pc = 0x1A6FF4u;
            goto label_1a6ff4;
        }
    }
    ctx->pc = 0x1A6FE0u;
    // 0x1a6fe0: 0xa3a3001f  sb          $v1, 0x1F($sp)
    ctx->pc = 0x1a6fe0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a6fe4: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1a6fe4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a6fe8: 0xa3a0001c  sb          $zero, 0x1C($sp)
    ctx->pc = 0x1a6fe8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 28), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6fec: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1A6FECu;
    {
        const bool branch_taken_0x1a6fec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6FECu;
            // 0x1a6ff0: 0xa3a0001d  sb          $zero, 0x1D($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 29), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6fec) {
            ctx->pc = 0x1A7060u;
            goto label_1a7060;
        }
    }
    ctx->pc = 0x1A6FF4u;
label_1a6ff4:
    // 0x1a6ff4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a6ff4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a6ff8: 0xa3a0001c  sb          $zero, 0x1C($sp)
    ctx->pc = 0x1a6ff8u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 28), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6ffc: 0xa3a3001f  sb          $v1, 0x1F($sp)
    ctx->pc = 0x1a6ffcu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a7000: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1A7000u;
    {
        const bool branch_taken_0x1a7000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7000u;
            // 0x1a7004: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7000) {
            ctx->pc = 0x1A7060u;
            goto label_1a7060;
        }
    }
    ctx->pc = 0x1A7008u;
label_1a7008:
    // 0x1a7008: 0x30a40007  andi        $a0, $a1, 0x7
    ctx->pc = 0x1a7008u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)7);
    // 0x1a700c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a700cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a7010: 0x42140  sll         $a0, $a0, 5
    ctx->pc = 0x1a7010u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1a7014: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x1a7014u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1a7018: 0x3484000f  ori         $a0, $a0, 0xF
    ctx->pc = 0x1a7018u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)15);
    // 0x1a701c: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1A701Cu;
    {
        const bool branch_taken_0x1a701c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A701Cu;
            // 0x1a7020: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a701c) {
            ctx->pc = 0x1A7050u;
            goto label_1a7050;
        }
    }
    ctx->pc = 0x1A7024u;
    // 0x1a7024: 0xa3a3001f  sb          $v1, 0x1F($sp)
    ctx->pc = 0x1a7024u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a7028: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1a7028u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1a702c: 0x30a3007f  andi        $v1, $a1, 0x7F
    ctx->pc = 0x1a702cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)127);
    // 0x1a7030: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1a7030u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a7034: 0x32040  sll         $a0, $v1, 1
    ctx->pc = 0x1a7034u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1a7038: 0x30a30080  andi        $v1, $a1, 0x80
    ctx->pc = 0x1a7038u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)128);
    // 0x1a703c: 0x34840001  ori         $a0, $a0, 0x1
    ctx->pc = 0x1a703cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1);
    // 0x1a7040: 0x319c3  sra         $v1, $v1, 7
    ctx->pc = 0x1a7040u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 7));
    // 0x1a7044: 0xa3a4001c  sb          $a0, 0x1C($sp)
    ctx->pc = 0x1a7044u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 28), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a7048: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A7048u;
    {
        const bool branch_taken_0x1a7048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A704Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7048u;
            // 0x1a704c: 0xa3a3001d  sb          $v1, 0x1D($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 29), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7048) {
            ctx->pc = 0x1A7060u;
            goto label_1a7060;
        }
    }
    ctx->pc = 0x1A7050u;
label_1a7050:
    // 0x1a7050: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a7050u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a7054: 0xa3a4001c  sb          $a0, 0x1C($sp)
    ctx->pc = 0x1a7054u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 28), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a7058: 0xa3a3001f  sb          $v1, 0x1F($sp)
    ctx->pc = 0x1a7058u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a705c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1a705cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a7060:
    // 0x1a7060: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a7060u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a7064: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1a7064u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a7068: 0x24630a16  addiu       $v1, $v1, 0xA16
    ctx->pc = 0x1a7068u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2582));
    // 0x1a706c: 0x27a6001f  addiu       $a2, $sp, 0x1F
    ctx->pc = 0x1a706cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x1a7070: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a7070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a7074: 0x90440000  lbu         $a0, 0x0($v0)
    ctx->pc = 0x1a7074u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a7078: 0xc062620  jal         func_189880
    ctx->pc = 0x1A7078u;
    SET_GPR_U32(ctx, 31, 0x1A7080u);
    ctx->pc = 0x1A707Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7078u;
            // 0x1a707c: 0x27a8001c  addiu       $t0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189880u;
    if (runtime->hasFunction(0x189880u)) {
        auto targetFn = runtime->lookupFunction(0x189880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7080u; }
        if (ctx->pc != 0x1A7080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189880_0x189880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7080u; }
        if (ctx->pc != 0x1A7080u) { return; }
    }
    ctx->pc = 0x1A7080u;
label_1a7080:
    // 0x1a7080: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a7080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a7084:
    // 0x1a7084: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7088: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A708Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7088u;
            // 0x1a708c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A6FC4u: goto label_1a6fc4;
            case 0x1A6FF4u: goto label_1a6ff4;
            case 0x1A7008u: goto label_1a7008;
            case 0x1A7050u: goto label_1a7050;
            case 0x1A7060u: goto label_1a7060;
            case 0x1A7080u: goto label_1a7080;
            case 0x1A7084u: goto label_1a7084;
            case 0x1A70A0u: goto label_1a70a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7090u;
    // 0x1a7090: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7094: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7098: 0xc045534  jal         func_1154D0
    ctx->pc = 0x1A7098u;
    SET_GPR_U32(ctx, 31, 0x1A70A0u);
    ctx->pc = 0x1A709Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7098u;
            // 0x1a709c: 0xc0202d  daddu       $a0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1154D0u;
    if (runtime->hasFunction(0x1154D0u)) {
        auto targetFn = runtime->lookupFunction(0x1154D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70A0u; }
        if (ctx->pc != 0x1A70A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001154D0_0x1154d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70A0u; }
        if (ctx->pc != 0x1A70A0u) { return; }
    }
    ctx->pc = 0x1A70A0u;
label_1a70a0:
    // 0x1a70a0: 0xf  sync
    ctx->pc = 0x1a70a0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1a70a4: 0x42000038  ei
    ctx->pc = 0x1a70a4u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1a70a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a70a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a70ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1A70ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A70B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70ACu;
            // 0x1a70b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A6FC4u: goto label_1a6fc4;
            case 0x1A6FF4u: goto label_1a6ff4;
            case 0x1A7008u: goto label_1a7008;
            case 0x1A7050u: goto label_1a7050;
            case 0x1A7060u: goto label_1a7060;
            case 0x1A7080u: goto label_1a7080;
            case 0x1A7084u: goto label_1a7084;
            case 0x1A70A0u: goto label_1a70a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A70B4u;
    // 0x1a70b4: 0x0  nop
    ctx->pc = 0x1a70b4u;
    // NOP
    // 0x1a70b8: 0x0  nop
    ctx->pc = 0x1a70b8u;
    // NOP
    // 0x1a70bc: 0x0  nop
    ctx->pc = 0x1a70bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
