#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115D60
// Address: 0x115d60 - 0x115e30
void sub_00115D60_0x115d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115D60_0x115d60");
#endif

    switch (ctx->pc) {
        case 0x115d98u: goto label_115d98;
        case 0x115da8u: goto label_115da8;
        case 0x115de0u: goto label_115de0;
        default: break;
    }

    ctx->pc = 0x115d60u;

    // 0x115d60: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x115d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x115d64: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x115d64u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115d68: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x115d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x115d6c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x115d6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x115d70: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x115d70u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115d74: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x115d74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x115d78: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x115d78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115d7c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x115d7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x115d80: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115d80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115d84: 0x1a400021  blez        $s2, . + 4 + (0x21 << 2)
    ctx->pc = 0x115D84u;
    {
        const bool branch_taken_0x115d84 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x115D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115D84u;
            // 0x115d88: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115d84) {
            ctx->pc = 0x115E0Cu;
            goto label_115e0c;
        }
    }
    ctx->pc = 0x115D8Cu;
    // 0x115d8c: 0x3c130026  lui         $s3, 0x26
    ctx->pc = 0x115d8cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
    // 0x115d90: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x115d90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x115d94: 0x0  nop
    ctx->pc = 0x115d94u;
    // NOP
label_115d98:
    // 0x115d98: 0x24710001  addiu       $s1, $v1, 0x1
    ctx->pc = 0x115d98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x115d9c: 0x8c44aba8  lw          $a0, -0x5458($v0)
    ctx->pc = 0x115d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294945704)));
    // 0x115da0: 0x2838021  addu        $s0, $s4, $v1
    ctx->pc = 0x115da0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x115da4: 0x0  nop
    ctx->pc = 0x115da4u;
    // NOP
label_115da8:
    // 0x115da8: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x115da8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x115dac: 0x0  nop
    ctx->pc = 0x115dacu;
    // NOP
    // 0x115db0: 0x0  nop
    ctx->pc = 0x115db0u;
    // NOP
    // 0x115db4: 0x0  nop
    ctx->pc = 0x115db4u;
    // NOP
    // 0x115db8: 0x0  nop
    ctx->pc = 0x115db8u;
    // NOP
    // 0x115dbc: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x115DBCu;
    {
        const bool branch_taken_0x115dbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x115dbc) {
            ctx->pc = 0x115DA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115da8;
        }
    }
    ctx->pc = 0x115DC4u;
    // 0x115dc4: 0x2665ab90  addiu       $a1, $s3, -0x5470
    ctx->pc = 0x115dc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294945680));
    // 0x115dc8: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x115dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x115dcc: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x115dccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x115dd0: 0x90640000  lbu         $a0, 0x0($v1)
    ctx->pc = 0x115dd0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x115dd4: 0xa2040000  sb          $a0, 0x0($s0)
    ctx->pc = 0x115dd4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x115dd8: 0xc045684  jal         func_115A10
    ctx->pc = 0x115DD8u;
    SET_GPR_U32(ctx, 31, 0x115DE0u);
    ctx->pc = 0x115DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115DD8u;
            // 0x115ddc: 0x8ca40018  lw          $a0, 0x18($a1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115A10u;
    if (runtime->hasFunction(0x115A10u)) {
        auto targetFn = runtime->lookupFunction(0x115A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115DE0u; }
        if (ctx->pc != 0x115DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115A10_0x115a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115DE0u; }
        if (ctx->pc != 0x115DE0u) { return; }
    }
    ctx->pc = 0x115DE0u;
label_115de0:
    // 0x115de0: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x115de0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x115de4: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x115de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x115de8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115DE8u;
    {
        const bool branch_taken_0x115de8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x115DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115DE8u;
            // 0x115dec: 0x2402000d  addiu       $v0, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115de8) {
            ctx->pc = 0x115DF8u;
            goto label_115df8;
        }
    }
    ctx->pc = 0x115DF0u;
    // 0x115df0: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115DF0u;
    {
        const bool branch_taken_0x115df0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x115DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115DF0u;
            // 0x115df4: 0x220182d  daddu       $v1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115df0) {
            ctx->pc = 0x115E00u;
            goto label_115e00;
        }
    }
    ctx->pc = 0x115DF8u;
label_115df8:
    // 0x115df8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x115DF8u;
    {
        const bool branch_taken_0x115df8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115DF8u;
            // 0x115dfc: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115df8) {
            ctx->pc = 0x115E10u;
            goto label_115e10;
        }
    }
    ctx->pc = 0x115E00u;
label_115e00:
    // 0x115e00: 0x72102a  slt         $v0, $v1, $s2
    ctx->pc = 0x115e00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x115e04: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x115E04u;
    {
        const bool branch_taken_0x115e04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x115E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115E04u;
            // 0x115e08: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115e04) {
            ctx->pc = 0x115D98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115d98;
        }
    }
    ctx->pc = 0x115E0Cu;
label_115e0c:
    // 0x115e0c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x115e0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_115e10:
    // 0x115e10: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x115e10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x115e14: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x115e14u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x115e18: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x115e18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x115e1c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x115e1cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115e20: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115e20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115e24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115e24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115e28: 0x3e00008  jr          $ra
    ctx->pc = 0x115E28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115E28u;
            // 0x115e2c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115D98u: goto label_115d98;
            case 0x115DA8u: goto label_115da8;
            case 0x115DE0u: goto label_115de0;
            case 0x115DF8u: goto label_115df8;
            case 0x115E00u: goto label_115e00;
            case 0x115E0Cu: goto label_115e0c;
            case 0x115E10u: goto label_115e10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115E30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
