#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115EF0
// Address: 0x115ef0 - 0x116018
void sub_00115EF0_0x115ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115EF0_0x115ef0");
#endif

    switch (ctx->pc) {
        case 0x115ef8u: goto label_115ef8;
        case 0x115f70u: goto label_115f70;
        case 0x115ff8u: goto label_115ff8;
        default: break;
    }

    ctx->pc = 0x115ef0u;

label_115ef0:
    // 0x115ef0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x115ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x115ef4: 0x3463f130  ori         $v1, $v1, 0xF130
    ctx->pc = 0x115ef4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61744);
label_115ef8:
    // 0x115ef8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x115ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x115efc: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x115efcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x115f00: 0x0  nop
    ctx->pc = 0x115f00u;
    // NOP
    // 0x115f04: 0x0  nop
    ctx->pc = 0x115f04u;
    // NOP
    // 0x115f08: 0x0  nop
    ctx->pc = 0x115f08u;
    // NOP
    // 0x115f0c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x115F0Cu;
    {
        const bool branch_taken_0x115f0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x115f0c) {
            ctx->pc = 0x115EF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115ef8;
        }
    }
    ctx->pc = 0x115F14u;
    // 0x115f14: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x115f14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x115f18: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x115f18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115f1c: 0x3463f180  ori         $v1, $v1, 0xF180
    ctx->pc = 0x115f1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61824);
    // 0x115f20: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x115f20u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x115f24: 0x3e00008  jr          $ra
    ctx->pc = 0x115F24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115EF0u: goto label_115ef0;
            case 0x115EF8u: goto label_115ef8;
            case 0x115F70u: goto label_115f70;
            case 0x115F78u: goto label_115f78;
            case 0x115F7Cu: goto label_115f7c;
            case 0x115FB8u: goto label_115fb8;
            case 0x115FF8u: goto label_115ff8;
            case 0x116008u: goto label_116008;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115F2Cu;
    // 0x115f2c: 0x0  nop
    ctx->pc = 0x115f2cu;
    // NOP
    // 0x115f30: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x115f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x115f34: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115f38: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x115f38u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x115f3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115f3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115f40: 0x8e259d40  lw          $a1, -0x62C0($s1)
    ctx->pc = 0x115f40u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942016)));
    // 0x115f44: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x115f44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115f48: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x115f48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x115f4c: 0x28a2007e  slti        $v0, $a1, 0x7E
    ctx->pc = 0x115f4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)126) ? 1 : 0);
    // 0x115f50: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x115F50u;
    {
        const bool branch_taken_0x115f50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x115F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115F50u;
            // 0x115f54: 0xffb20020  sd          $s2, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115f50) {
            ctx->pc = 0x115F78u;
            goto label_115f78;
        }
    }
    ctx->pc = 0x115F58u;
    // 0x115f58: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x115f58u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x115f5c: 0xae209d40  sw          $zero, -0x62C0($s1)
    ctx->pc = 0x115f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294942016), GPR_U32(ctx, 0));
    // 0x115f60: 0x2642ae40  addiu       $v0, $s2, -0x51C0
    ctx->pc = 0x115f60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294946368));
    // 0x115f64: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x115f64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115f68: 0xc045660  jal         func_115980
    ctx->pc = 0x115F68u;
    SET_GPR_U32(ctx, 31, 0x115F70u);
    ctx->pc = 0x115F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115F68u;
            // 0x115f6c: 0xa040007f  sb          $zero, 0x7F($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 127), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115980u;
    if (runtime->hasFunction(0x115980u)) {
        auto targetFn = runtime->lookupFunction(0x115980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115F70u; }
        if (ctx->pc != 0x115F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115980_0x115980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115F70u; }
        if (ctx->pc != 0x115F70u) { return; }
    }
    ctx->pc = 0x115F70u;
label_115f70:
    // 0x115f70: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x115F70u;
    {
        const bool branch_taken_0x115f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115F70u;
            // 0x115f74: 0x8e259d40  lw          $a1, -0x62C0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942016)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115f70) {
            ctx->pc = 0x115F7Cu;
            goto label_115f7c;
        }
    }
    ctx->pc = 0x115F78u;
label_115f78:
    // 0x115f78: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x115f78u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
label_115f7c:
    // 0x115f7c: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x115f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x115f80: 0x1602000d  bne         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x115F80u;
    {
        const bool branch_taken_0x115f80 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x115F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115F80u;
            // 0x115f84: 0x2642ae40  addiu       $v0, $s2, -0x51C0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294946368));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115f80) {
            ctx->pc = 0x115FB8u;
            goto label_115fb8;
        }
    }
    ctx->pc = 0x115F88u;
    // 0x115f88: 0x2644ae40  addiu       $a0, $s2, -0x51C0
    ctx->pc = 0x115f88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 4294946368));
    // 0x115f8c: 0xae209d40  sw          $zero, -0x62C0($s1)
    ctx->pc = 0x115f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294942016), GPR_U32(ctx, 0));
    // 0x115f90: 0xa41021  addu        $v0, $a1, $a0
    ctx->pc = 0x115f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x115f94: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x115f94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x115f98: 0xa0500000  sb          $s0, 0x0($v0)
    ctx->pc = 0x115f98u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 16));
    // 0x115f9c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x115f9cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115fa0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x115fa0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115fa4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115fa8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115fa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115fac: 0xa0600001  sb          $zero, 0x1($v1)
    ctx->pc = 0x115facu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x115fb0: 0x8045660  j           func_115980
    ctx->pc = 0x115FB0u;
    ctx->pc = 0x115FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115FB0u;
            // 0x115fb4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115980u;
    if (runtime->hasFunction(0x115980u)) {
        auto targetFn = runtime->lookupFunction(0x115980u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00115980_0x115980(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x115FB8u;
label_115fb8:
    // 0x115fb8: 0x24a30001  addiu       $v1, $a1, 0x1
    ctx->pc = 0x115fb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x115fbc: 0xae239d40  sw          $v1, -0x62C0($s1)
    ctx->pc = 0x115fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294942016), GPR_U32(ctx, 3));
    // 0x115fc0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x115fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x115fc4: 0xa0500000  sb          $s0, 0x0($v0)
    ctx->pc = 0x115fc4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 16));
    // 0x115fc8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x115fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x115fcc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x115fccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115fd0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115fd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115fd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115fd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115fd8: 0x3e00008  jr          $ra
    ctx->pc = 0x115FD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115FD8u;
            // 0x115fdc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115EF0u: goto label_115ef0;
            case 0x115EF8u: goto label_115ef8;
            case 0x115F70u: goto label_115f70;
            case 0x115F78u: goto label_115f78;
            case 0x115F7Cu: goto label_115f7c;
            case 0x115FB8u: goto label_115fb8;
            case 0x115FF8u: goto label_115ff8;
            case 0x116008u: goto label_116008;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115FE0u;
    // 0x115fe0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x115fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x115fe4: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x115fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x115fe8: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x115FE8u;
    {
        const bool branch_taken_0x115fe8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x115FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115FE8u;
            // 0x115fec: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115fe8) {
            ctx->pc = 0x116008u;
            goto label_116008;
        }
    }
    ctx->pc = 0x115FF0u;
    // 0x115ff0: 0xc0457bc  jal         func_115EF0
    ctx->pc = 0x115FF0u;
    SET_GPR_U32(ctx, 31, 0x115FF8u);
    ctx->pc = 0x115FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115FF0u;
            // 0x115ff4: 0x2404000d  addiu       $a0, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115EF0u;
    goto label_115ef0;
    ctx->pc = 0x115FF8u;
label_115ff8:
    // 0x115ff8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x115ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115ffc: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x115ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x116000: 0x80457bc  j           func_115EF0
    ctx->pc = 0x116000u;
    ctx->pc = 0x116004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116000u;
            // 0x116004: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115EF0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_115ef0;
    ctx->pc = 0x116008u;
label_116008:
    // 0x116008: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x116008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11600c: 0x80457bc  j           func_115EF0
    ctx->pc = 0x11600Cu;
    ctx->pc = 0x116010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11600Cu;
            // 0x116010: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115EF0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_115ef0;
    ctx->pc = 0x116014u;
    // 0x116014: 0x0  nop
    ctx->pc = 0x116014u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
