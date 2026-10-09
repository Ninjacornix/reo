#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139EA8
// Address: 0x139ea8 - 0x139fa8
void sub_00139EA8_0x139ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139EA8_0x139ea8");
#endif

    switch (ctx->pc) {
        case 0x139f24u: goto label_139f24;
        case 0x139f38u: goto label_139f38;
        case 0x139f40u: goto label_139f40;
        case 0x139f48u: goto label_139f48;
        case 0x139f50u: goto label_139f50;
        case 0x139f7cu: goto label_139f7c;
        default: break;
    }

    ctx->pc = 0x139ea8u;

    // 0x139ea8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x139ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x139eac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x139eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x139eb0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x139eb0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139eb4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x139eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x139eb8: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x139eb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139ebc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x139ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x139ec0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x139ec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x139ec4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x139ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x139ec8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x139ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x139ecc: 0x1600000c  bnez        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x139ECCu;
    {
        const bool branch_taken_0x139ecc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x139ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139ECCu;
            // 0x139ed0: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139ecc) {
            ctx->pc = 0x139F00u;
            goto label_139f00;
        }
    }
    ctx->pc = 0x139ED4u;
    // 0x139ed4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139ed4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139ed8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139ed8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139edc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x139edcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139ee0: 0x24a5cbe8  addiu       $a1, $a1, -0x3418
    ctx->pc = 0x139ee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953960));
    // 0x139ee4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x139ee4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139ee8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x139ee8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139eec: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x139eecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139ef0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x139ef0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x139ef4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x139ef4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x139ef8: 0x804e57e  j           func_1395F8
    ctx->pc = 0x139EF8u;
    ctx->pc = 0x139EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139EF8u;
            // 0x139efc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001395F8_0x1395f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x139F00u;
label_139f00:
    // 0x139f00: 0x92020002  lbu         $v0, 0x2($s0)
    ctx->pc = 0x139f00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x139f04: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x139f04u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x139f08: 0x5440001f  bnel        $v0, $zero, . + 4 + (0x1F << 2)
    ctx->pc = 0x139F08u;
    {
        const bool branch_taken_0x139f08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x139f08) {
            ctx->pc = 0x139F0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139F08u;
            // 0x139f0c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139F88u;
            goto label_139f88;
        }
    }
    ctx->pc = 0x139F10u;
    // 0x139f10: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x139f10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x139f14: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x139F14u;
    {
        const bool branch_taken_0x139f14 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x139F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139F14u;
            // 0x139f18: 0x3c110009  lui         $s1, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)9 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139f14) {
            ctx->pc = 0x139F24u;
            goto label_139f24;
        }
    }
    ctx->pc = 0x139F1Cu;
    // 0x139f1c: 0xc04de1a  jal         func_137868
    ctx->pc = 0x139F1Cu;
    SET_GPR_U32(ctx, 31, 0x139F24u);
    ctx->pc = 0x137868u;
    if (runtime->hasFunction(0x137868u)) {
        auto targetFn = runtime->lookupFunction(0x137868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F24u; }
        if (ctx->pc != 0x139F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137868_0x137868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F24u; }
        if (ctx->pc != 0x139F24u) { return; }
    }
    ctx->pc = 0x139F24u;
label_139f24:
    // 0x139f24: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x139f24u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x139f28: 0x3631ffff  ori         $s1, $s1, 0xFFFF
    ctx->pc = 0x139f28u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)65535);
    // 0x139f2c: 0x3c140022  lui         $s4, 0x22
    ctx->pc = 0x139f2cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)34 << 16));
    // 0x139f30: 0x3c150024  lui         $s5, 0x24
    ctx->pc = 0x139f30u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
    // 0x139f34: 0x0  nop
    ctx->pc = 0x139f34u;
    // NOP
label_139f38:
    // 0x139f38: 0xc04df60  jal         func_137D80
    ctx->pc = 0x139F38u;
    SET_GPR_U32(ctx, 31, 0x139F40u);
    ctx->pc = 0x137D80u;
    if (runtime->hasFunction(0x137D80u)) {
        auto targetFn = runtime->lookupFunction(0x137D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F40u; }
        if (ctx->pc != 0x139F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137D80_0x137d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F40u; }
        if (ctx->pc != 0x139F40u) { return; }
    }
    ctx->pc = 0x139F40u;
label_139f40:
    // 0x139f40: 0xc04e5e6  jal         func_139798
    ctx->pc = 0x139F40u;
    SET_GPR_U32(ctx, 31, 0x139F48u);
    ctx->pc = 0x139798u;
    if (runtime->hasFunction(0x139798u)) {
        auto targetFn = runtime->lookupFunction(0x139798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F48u; }
        if (ctx->pc != 0x139F48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139798_0x139798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F48u; }
        if (ctx->pc != 0x139F48u) { return; }
    }
    ctx->pc = 0x139F48u;
label_139f48:
    // 0x139f48: 0xc04e7ea  jal         func_139FA8
    ctx->pc = 0x139F48u;
    SET_GPR_U32(ctx, 31, 0x139F50u);
    ctx->pc = 0x139F4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139F48u;
            // 0x139f4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139FA8u;
    if (runtime->hasFunction(0x139FA8u)) {
        auto targetFn = runtime->lookupFunction(0x139FA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F50u; }
        if (ctx->pc != 0x139F50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139FA8_0x139fa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F50u; }
        if (ctx->pc != 0x139F50u) { return; }
    }
    ctx->pc = 0x139F50u;
label_139f50:
    // 0x139f50: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x139f50u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x139f54: 0x5473000a  bnel        $v1, $s3, . + 4 + (0xA << 2)
    ctx->pc = 0x139F54u;
    {
        const bool branch_taken_0x139f54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        if (branch_taken_0x139f54) {
            ctx->pc = 0x139F58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139F54u;
            // 0x139f58: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139F80u;
            goto label_139f80;
        }
    }
    ctx->pc = 0x139F5Cu;
    // 0x139f5c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x139f5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x139f60: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x139f60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x139f64: 0x1040fff4  beqz        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x139F64u;
    {
        const bool branch_taken_0x139f64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x139F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139F64u;
            // 0x139f68: 0x8e82d8e8  lw          $v0, -0x2718($s4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294957288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139f64) {
            ctx->pc = 0x139F38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139f38;
        }
    }
    ctx->pc = 0x139F6Cu;
    // 0x139f6c: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x139F6Cu;
    {
        const bool branch_taken_0x139f6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x139f6c) {
            ctx->pc = 0x139F70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139F6Cu;
            // 0x139f70: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139F80u;
            goto label_139f80;
        }
    }
    ctx->pc = 0x139F74u;
    // 0x139f74: 0xc045a12  jal         func_116848
    ctx->pc = 0x139F74u;
    SET_GPR_U32(ctx, 31, 0x139F7Cu);
    ctx->pc = 0x139F78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139F74u;
            // 0x139f78: 0x26a4cc48  addiu       $a0, $s5, -0x33B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294954056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F7Cu; }
        if (ctx->pc != 0x139F7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139F7Cu; }
        if (ctx->pc != 0x139F7Cu) { return; }
    }
    ctx->pc = 0x139F7Cu;
label_139f7c:
    // 0x139f7c: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x139f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
label_139f80:
    // 0x139f80: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x139f80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x139f84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139f84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_139f88:
    // 0x139f88: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x139f88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139f8c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x139f8cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139f90: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x139f90u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139f94: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x139f94u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139f98: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x139f98u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x139f9c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x139f9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x139fa0: 0x3e00008  jr          $ra
    ctx->pc = 0x139FA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139FA0u;
            // 0x139fa4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139F00u: goto label_139f00;
            case 0x139F24u: goto label_139f24;
            case 0x139F38u: goto label_139f38;
            case 0x139F40u: goto label_139f40;
            case 0x139F48u: goto label_139f48;
            case 0x139F50u: goto label_139f50;
            case 0x139F7Cu: goto label_139f7c;
            case 0x139F80u: goto label_139f80;
            case 0x139F88u: goto label_139f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139FA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
