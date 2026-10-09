#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188C30
// Address: 0x188c30 - 0x188d08
void sub_00188C30_0x188c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188C30_0x188c30");
#endif

    switch (ctx->pc) {
        case 0x188c90u: goto label_188c90;
        case 0x188ce0u: goto label_188ce0;
        case 0x188cf4u: goto label_188cf4;
        default: break;
    }

    ctx->pc = 0x188c30u;

    // 0x188c30: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x188c30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x188c34: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x188c34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x188c38: 0x8c43fd38  lw          $v1, -0x2C8($v0)
    ctx->pc = 0x188c38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294966584)));
    // 0x188c3c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x188c3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x188c40: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188c40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x188c44: 0x1060002c  beqz        $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x188C44u;
    {
        const bool branch_taken_0x188c44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x188C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188C44u;
            // 0x188c48: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188c44) {
            ctx->pc = 0x188CF8u;
            goto label_188cf8;
        }
    }
    ctx->pc = 0x188C4Cu;
    // 0x188c4c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x188c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x188c50: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x188c50u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x188c54: 0x24f00c00  addiu       $s0, $a3, 0xC00
    ctx->pc = 0x188c54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
    // 0x188c58: 0x24880014  addiu       $t0, $a0, 0x14
    ctx->pc = 0x188c58u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
    // 0x188c5c: 0xace20c00  sw          $v0, 0xC00($a3)
    ctx->pc = 0x188c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 3072), GPR_U32(ctx, 2));
    // 0x188c60: 0x26090014  addiu       $t1, $s0, 0x14
    ctx->pc = 0x188c60u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x188c64: 0xae050028  sw          $a1, 0x28($s0)
    ctx->pc = 0x188c64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
    // 0x188c68: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x188c68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x188c6c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x188c6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188c70: 0xae06002c  sw          $a2, 0x2C($s0)
    ctx->pc = 0x188c70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 6));
    // 0x188c74: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x188c74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x188c78: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x188c78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x188c7c: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x188c7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x188c80: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x188c80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x188c84: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x188c84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x188c88: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x188c88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x188c8c: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x188c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_188c90:
    // 0x188c90: 0x1051021  addu        $v0, $t0, $a1
    ctx->pc = 0x188c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x188c94: 0x1252021  addu        $a0, $t1, $a1
    ctx->pc = 0x188c94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 5)));
    // 0x188c98: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x188c98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x188c9c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x188c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x188ca0: 0x28a20010  slti        $v0, $a1, 0x10
    ctx->pc = 0x188ca0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x188ca4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x188ca4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x188ca8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x188CA8u;
    {
        const bool branch_taken_0x188ca8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x188ca8) {
            ctx->pc = 0x188C90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188c90;
        }
    }
    ctx->pc = 0x188CB0u;
    // 0x188cb0: 0x24e70c00  addiu       $a3, $a3, 0xC00
    ctx->pc = 0x188cb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
    // 0x188cb4: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188cb4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188cb8: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x188cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x188cbc: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188cbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188cc0: 0x24840b88  addiu       $a0, $a0, 0xB88
    ctx->pc = 0x188cc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2952));
    // 0x188cc4: 0x34a51301  ori         $a1, $a1, 0x1301
    ctx->pc = 0x188cc4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4865);
    // 0x188cc8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188cc8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188ccc: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x188cccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188cd0: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x188cd0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188cd4: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x188cd4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188cd8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x188CD8u;
    SET_GPR_U32(ctx, 31, 0x188CE0u);
    ctx->pc = 0x188CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188CD8u;
            // 0x188cdc: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188CE0u; }
        if (ctx->pc != 0x188CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188CE0u; }
        if (ctx->pc != 0x188CE0u) { return; }
    }
    ctx->pc = 0x188CE0u;
label_188ce0:
    // 0x188ce0: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x188CE0u;
    {
        const bool branch_taken_0x188ce0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x188ce0) {
            ctx->pc = 0x188CE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x188CE0u;
            // 0x188ce4: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x188CF8u;
            goto label_188cf8;
        }
    }
    ctx->pc = 0x188CE8u;
    // 0x188ce8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x188cec: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x188CECu;
    SET_GPR_U32(ctx, 31, 0x188CF4u);
    ctx->pc = 0x188CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188CECu;
            // 0x188cf0: 0x24841920  addiu       $a0, $a0, 0x1920 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188CF4u; }
        if (ctx->pc != 0x188CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188CF4u; }
        if (ctx->pc != 0x188CF4u) { return; }
    }
    ctx->pc = 0x188CF4u;
label_188cf4:
    // 0x188cf4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x188cf4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_188cf8:
    // 0x188cf8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x188cf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188cfc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x188d00: 0x3e00008  jr          $ra
    ctx->pc = 0x188D00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188D00u;
            // 0x188d04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188C90u: goto label_188c90;
            case 0x188CE0u: goto label_188ce0;
            case 0x188CF4u: goto label_188cf4;
            case 0x188CF8u: goto label_188cf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188D08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
