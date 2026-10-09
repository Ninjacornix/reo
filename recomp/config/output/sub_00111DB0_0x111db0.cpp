#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111DB0
// Address: 0x111db0 - 0x112038
void sub_00111DB0_0x111db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111DB0_0x111db0");
#endif

    switch (ctx->pc) {
        case 0x111de8u: goto label_111de8;
        case 0x111df8u: goto label_111df8;
        case 0x111ed0u: goto label_111ed0;
        case 0x111ee0u: goto label_111ee0;
        case 0x111ef0u: goto label_111ef0;
        case 0x111f04u: goto label_111f04;
        case 0x111f78u: goto label_111f78;
        case 0x111fd0u: goto label_111fd0;
        case 0x11200cu: goto label_11200c;
        default: break;
    }

    ctx->pc = 0x111db0u;

    // 0x111db0: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x111db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x111db4: 0xffa40060  sd          $a0, 0x60($sp)
    ctx->pc = 0x111db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 4));
    // 0x111db8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x111db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x111dbc: 0xffa50068  sd          $a1, 0x68($sp)
    ctx->pc = 0x111dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 5));
    // 0x111dc0: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x111dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x111dc4: 0xffb10078  sd          $s1, 0x78($sp)
    ctx->pc = 0x111dc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 17));
    // 0x111dc8: 0xffb20080  sd          $s2, 0x80($sp)
    ctx->pc = 0x111dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 18));
    // 0x111dcc: 0xffb30088  sd          $s3, 0x88($sp)
    ctx->pc = 0x111dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 19));
    // 0x111dd0: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x111dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x111dd4: 0xffb50098  sd          $s5, 0x98($sp)
    ctx->pc = 0x111dd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 21));
    // 0x111dd8: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x111dd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x111ddc: 0xffbf00a8  sd          $ra, 0xA8($sp)
    ctx->pc = 0x111ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x111de0: 0xc044674  jal         func_1119D0
    ctx->pc = 0x111DE0u;
    SET_GPR_U32(ctx, 31, 0x111DE8u);
    ctx->pc = 0x111DE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111DE0u;
            // 0x111de4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111DE8u; }
        if (ctx->pc != 0x111DE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111DE8u; }
        if (ctx->pc != 0x111DE8u) { return; }
    }
    ctx->pc = 0x111DE8u;
label_111de8:
    // 0x111de8: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x111de8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x111dec: 0x27a40068  addiu       $a0, $sp, 0x68
    ctx->pc = 0x111decu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x111df0: 0xc044674  jal         func_1119D0
    ctx->pc = 0x111DF0u;
    SET_GPR_U32(ctx, 31, 0x111DF8u);
    ctx->pc = 0x111DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111DF0u;
            // 0x111df4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111DF8u; }
        if (ctx->pc != 0x111DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111DF8u; }
        if (ctx->pc != 0x111DF8u) { return; }
    }
    ctx->pc = 0x111DF8u;
label_111df8:
    // 0x111df8: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x111df8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x111dfc: 0x2c820002  sltiu       $v0, $a0, 0x2
    ctx->pc = 0x111dfcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x111e00: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x111E00u;
    {
        const bool branch_taken_0x111e00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E00u;
            // 0x111e04: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e00) {
            ctx->pc = 0x111E64u;
            goto label_111e64;
        }
    }
    ctx->pc = 0x111E08u;
    // 0x111e08: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x111e08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x111e0c: 0x2c620002  sltiu       $v0, $v1, 0x2
    ctx->pc = 0x111e0cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x111e10: 0x5440001e  bnel        $v0, $zero, . + 4 + (0x1E << 2)
    ctx->pc = 0x111E10u;
    {
        const bool branch_taken_0x111e10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111e10) {
            ctx->pc = 0x111E14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111E10u;
            // 0x111e14: 0x8fa30024  lw          $v1, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111E8Cu;
            goto label_111e8c;
        }
    }
    ctx->pc = 0x111E18u;
    // 0x111e18: 0x38820004  xori        $v0, $a0, 0x4
    ctx->pc = 0x111e18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)4);
    // 0x111e1c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x111E1Cu;
    {
        const bool branch_taken_0x111e1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E1Cu;
            // 0x111e20: 0x38620004  xori        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e1c) {
            ctx->pc = 0x111E38u;
            goto label_111e38;
        }
    }
    ctx->pc = 0x111E24u;
    // 0x111e24: 0x38620002  xori        $v0, $v1, 0x2
    ctx->pc = 0x111e24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x111e28: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x111E28u;
    {
        const bool branch_taken_0x111e28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111e28) {
            ctx->pc = 0x111E2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111E28u;
            // 0x111e2c: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111E64u;
            goto label_111e64;
        }
    }
    ctx->pc = 0x111E30u;
    // 0x111e30: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x111E30u;
    {
        const bool branch_taken_0x111e30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E30u;
            // 0x111e34: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e30) {
            ctx->pc = 0x111E4Cu;
            goto label_111e4c;
        }
    }
    ctx->pc = 0x111E38u;
label_111e38:
    // 0x111e38: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x111E38u;
    {
        const bool branch_taken_0x111e38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E38u;
            // 0x111e3c: 0x38820002  xori        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e38) {
            ctx->pc = 0x111E58u;
            goto label_111e58;
        }
    }
    ctx->pc = 0x111E40u;
    // 0x111e40: 0x54400012  bnel        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x111E40u;
    {
        const bool branch_taken_0x111e40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111e40) {
            ctx->pc = 0x111E44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111E40u;
            // 0x111e44: 0x8fa30024  lw          $v1, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111E8Cu;
            goto label_111e8c;
        }
    }
    ctx->pc = 0x111E48u;
    // 0x111e48: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x111e48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
label_111e4c:
    // 0x111e4c: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x111E4Cu;
    {
        const bool branch_taken_0x111e4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E4Cu;
            // 0x111e50: 0x244485a0  addiu       $a0, $v0, -0x7A60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e4c) {
            ctx->pc = 0x112004u;
            goto label_112004;
        }
    }
    ctx->pc = 0x111E54u;
    // 0x111e54: 0x0  nop
    ctx->pc = 0x111e54u;
    // NOP
label_111e58:
    // 0x111e58: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x111E58u;
    {
        const bool branch_taken_0x111e58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E58u;
            // 0x111e5c: 0x38620002  xori        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e58) {
            ctx->pc = 0x111E80u;
            goto label_111e80;
        }
    }
    ctx->pc = 0x111E60u;
    // 0x111e60: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x111e60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_111e64:
    // 0x111e64: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x111e64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111e68: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x111e68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x111e6c: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x111e6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x111e70: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x111e70u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x111e74: 0x10000063  b           . + 4 + (0x63 << 2)
    ctx->pc = 0x111E74u;
    {
        const bool branch_taken_0x111e74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E74u;
            // 0x111e78: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e74) {
            ctx->pc = 0x112004u;
            goto label_112004;
        }
    }
    ctx->pc = 0x111E7Cu;
    // 0x111e7c: 0x0  nop
    ctx->pc = 0x111e7cu;
    // NOP
label_111e80:
    // 0x111e80: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x111E80u;
    {
        const bool branch_taken_0x111e80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E80u;
            // 0x111e84: 0xdfb30010  ld          $s3, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e80) {
            ctx->pc = 0x111EA8u;
            goto label_111ea8;
        }
    }
    ctx->pc = 0x111E88u;
    // 0x111e88: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x111e88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_111e8c:
    // 0x111e8c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x111e8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111e90: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x111e90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x111e94: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x111e94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x111e98: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x111e98u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x111e9c: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x111E9Cu;
    {
        const bool branch_taken_0x111e9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111E9Cu;
            // 0x111ea0: 0xafa20024  sw          $v0, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111e9c) {
            ctx->pc = 0x112004u;
            goto label_112004;
        }
    }
    ctx->pc = 0x111EA4u;
    // 0x111ea4: 0x0  nop
    ctx->pc = 0x111ea4u;
    // NOP
label_111ea8:
    // 0x111ea8: 0x3c15ffff  lui         $s5, 0xFFFF
    ctx->pc = 0x111ea8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)65535 << 16));
    // 0x111eac: 0x15a83e  dsrl32      $s5, $s5, 0
    ctx->pc = 0x111eacu;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) >> (32 + 0));
    // 0x111eb0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x111eb0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x111eb4: 0x2758024  and         $s0, $s3, $s5
    ctx->pc = 0x111eb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 19) & GPR_U64(ctx, 21));
    // 0x111eb8: 0x13983e  dsrl32      $s3, $s3, 0
    ctx->pc = 0x111eb8u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) >> (32 + 0));
    // 0x111ebc: 0x255b024  and         $s6, $s2, $s5
    ctx->pc = 0x111ebcu;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 18) & GPR_U64(ctx, 21));
    // 0x111ec0: 0x12903e  dsrl32      $s2, $s2, 0
    ctx->pc = 0x111ec0u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) >> (32 + 0));
    // 0x111ec4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x111ec4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ec8: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x111EC8u;
    SET_GPR_U32(ctx, 31, 0x111ED0u);
    ctx->pc = 0x111ECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111EC8u;
            // 0x111ecc: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111ED0u; }
        if (ctx->pc != 0x111ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111ED0u; }
        if (ctx->pc != 0x111ED0u) { return; }
    }
    ctx->pc = 0x111ED0u;
label_111ed0:
    // 0x111ed0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x111ed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ed4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x111ed4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ed8: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x111ED8u;
    SET_GPR_U32(ctx, 31, 0x111EE0u);
    ctx->pc = 0x111EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111ED8u;
            // 0x111edc: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111EE0u; }
        if (ctx->pc != 0x111EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111EE0u; }
        if (ctx->pc != 0x111EE0u) { return; }
    }
    ctx->pc = 0x111EE0u;
label_111ee0:
    // 0x111ee0: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x111ee0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ee4: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x111ee4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ee8: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x111EE8u;
    SET_GPR_U32(ctx, 31, 0x111EF0u);
    ctx->pc = 0x111EECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111EE8u;
            // 0x111eec: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111EF0u; }
        if (ctx->pc != 0x111EF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111EF0u; }
        if (ctx->pc != 0x111EF0u) { return; }
    }
    ctx->pc = 0x111EF0u;
label_111ef0:
    // 0x111ef0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x111ef0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ef4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x111ef4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111ef8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x111ef8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111efc: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x111EFCu;
    SET_GPR_U32(ctx, 31, 0x111F04u);
    ctx->pc = 0x111F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111EFCu;
            // 0x111f00: 0x230802d  daddu       $s0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111F04u; }
        if (ctx->pc != 0x111F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111F04u; }
        if (ctx->pc != 0x111F04u) { return; }
    }
    ctx->pc = 0x111F04u;
label_111f04:
    // 0x111f04: 0x211882b  sltu        $s1, $s0, $s1
    ctx->pc = 0x111f04u;
    SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x111f08: 0x10303c  dsll32      $a2, $s0, 0
    ctx->pc = 0x111f08u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) << (32 + 0));
    // 0x111f0c: 0x10803e  dsrl32      $s0, $s0, 0
    ctx->pc = 0x111f0cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
    // 0x111f10: 0x286302d  daddu       $a2, $s4, $a2
    ctx->pc = 0x111f10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 6));
    // 0x111f14: 0x2158024  and         $s0, $s0, $s5
    ctx->pc = 0x111f14u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 21));
    // 0x111f18: 0x11883c  dsll32      $s1, $s1, 0
    ctx->pc = 0x111f18u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 0));
    // 0x111f1c: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x111f1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
    // 0x111f20: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x111f20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x111f24: 0xd4a02b  sltu        $s4, $a2, $s4
    ctx->pc = 0x111f24u;
    SET_GPR_U64(ctx, 20, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
    // 0x111f28: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x111f28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x111f2c: 0x8fa70028  lw          $a3, 0x28($sp)
    ctx->pc = 0x111f2cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x111f30: 0x234882d  daddu       $s1, $s1, $s4
    ctx->pc = 0x111f30u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 20));
    // 0x111f34: 0x8fa50024  lw          $a1, 0x24($sp)
    ctx->pc = 0x111f34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x111f38: 0x230882d  daddu       $s1, $s1, $s0
    ctx->pc = 0x111f38u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 16));
    // 0x111f3c: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x111f3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x111f40: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x111f40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111f44: 0x318fa  dsrl        $v1, $v1, 3
    ctx->pc = 0x111f44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 3);
    // 0x111f48: 0x451026  xor         $v0, $v0, $a1
    ctx->pc = 0x111f48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 5));
    // 0x111f4c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x111f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x111f50: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x111f50u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x111f54: 0x71182b  sltu        $v1, $v1, $s1
    ctx->pc = 0x111f54u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x111f58: 0xafa20044  sw          $v0, 0x44($sp)
    ctx->pc = 0x111f58u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 2));
    // 0x111f5c: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x111F5Cu;
    {
        const bool branch_taken_0x111f5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x111F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111F5Cu;
            // 0x111f60: 0xafa40048  sw          $a0, 0x48($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111f5c) {
            ctx->pc = 0x111FA4u;
            goto label_111fa4;
        }
    }
    ctx->pc = 0x111F64u;
    // 0x111f64: 0x34078000  ori         $a3, $zero, 0x8000
    ctx->pc = 0x111f64u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x111f68: 0x73c3c  dsll32      $a3, $a3, 16
    ctx->pc = 0x111f68u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 16));
    // 0x111f6c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x111f6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111f70: 0x528fa  dsrl        $a1, $a1, 3
    ctx->pc = 0x111f70u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> 3);
    // 0x111f74: 0x32220001  andi        $v0, $s1, 0x1
    ctx->pc = 0x111f74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
label_111f78:
    // 0x111f78: 0x11887a  dsrl        $s1, $s1, 1
    ctx->pc = 0x111f78u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) >> 1);
    // 0x111f7c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x111f7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x111f80: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x111f80u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x111f84: 0xb1182b  sltu        $v1, $a1, $s1
    ctx->pc = 0x111f84u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x111f88: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x111F88u;
    {
        const bool branch_taken_0x111f88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111F88u;
            // 0x111f8c: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111f88) {
            ctx->pc = 0x111F98u;
            goto label_111f98;
        }
    }
    ctx->pc = 0x111F90u;
    // 0x111f90: 0x6307a  dsrl        $a2, $a2, 1
    ctx->pc = 0x111f90u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> 1);
    // 0x111f94: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x111f94u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
label_111f98:
    // 0x111f98: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x111F98u;
    {
        const bool branch_taken_0x111f98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x111F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111F98u;
            // 0x111f9c: 0x32220001  andi        $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111f98) {
            ctx->pc = 0x111F78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_111f78;
        }
    }
    ctx->pc = 0x111FA0u;
    // 0x111fa0: 0xafa40048  sw          $a0, 0x48($sp)
    ctx->pc = 0x111fa0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 4));
label_111fa4:
    // 0x111fa4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x111fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111fa8: 0x2113a  dsrl        $v0, $v0, 4
    ctx->pc = 0x111fa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 4);
    // 0x111fac: 0x51102b  sltu        $v0, $v0, $s1
    ctx->pc = 0x111facu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x111fb0: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x111FB0u;
    {
        const bool branch_taken_0x111fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111FB0u;
            // 0x111fb4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111fb0) {
            ctx->pc = 0x111FF8u;
            goto label_111ff8;
        }
    }
    ctx->pc = 0x111FB8u;
    // 0x111fb8: 0x8fa40048  lw          $a0, 0x48($sp)
    ctx->pc = 0x111fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x111fbc: 0x34088000  ori         $t0, $zero, 0x8000
    ctx->pc = 0x111fbcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x111fc0: 0x8443c  dsll32      $t0, $t0, 16
    ctx->pc = 0x111fc0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << (32 + 16));
    // 0x111fc4: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x111fc4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x111fc8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x111fc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111fcc: 0x5293a  dsrl        $a1, $a1, 4
    ctx->pc = 0x111fccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> 4);
label_111fd0:
    // 0x111fd0: 0x118878  dsll        $s1, $s1, 1
    ctx->pc = 0x111fd0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << 1);
    // 0x111fd4: 0xc81824  and         $v1, $a2, $t0
    ctx->pc = 0x111fd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 8));
    // 0x111fd8: 0x2271025  or          $v0, $s1, $a3
    ctx->pc = 0x111fd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    // 0x111fdc: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x111fdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x111fe0: 0x43880b  movn        $s1, $v0, $v1
    ctx->pc = 0x111fe0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
    // 0x111fe4: 0xb1102b  sltu        $v0, $a1, $s1
    ctx->pc = 0x111fe4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x111fe8: 0x1040fff9  beqz        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x111FE8u;
    {
        const bool branch_taken_0x111fe8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111FE8u;
            // 0x111fec: 0x63078  dsll        $a2, $a2, 1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x111fe8) {
            ctx->pc = 0x111FD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_111fd0;
        }
    }
    ctx->pc = 0x111FF0u;
    // 0x111ff0: 0xafa40048  sw          $a0, 0x48($sp)
    ctx->pc = 0x111ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 4));
    // 0x111ff4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x111ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_111ff8:
    // 0x111ff8: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x111ff8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x111ffc: 0xafa20040  sw          $v0, 0x40($sp)
    ctx->pc = 0x111ffcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
    // 0x112000: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x112000u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
label_112004:
    // 0x112004: 0xc04463e  jal         func_1118F8
    ctx->pc = 0x112004u;
    SET_GPR_U32(ctx, 31, 0x11200Cu);
    ctx->pc = 0x1118F8u;
    if (runtime->hasFunction(0x1118F8u)) {
        auto targetFn = runtime->lookupFunction(0x1118F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11200Cu; }
        if (ctx->pc != 0x11200Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118F8_0x1118f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11200Cu; }
        if (ctx->pc != 0x11200Cu) { return; }
    }
    ctx->pc = 0x11200Cu;
label_11200c:
    // 0x11200c: 0xdfb00070  ld          $s0, 0x70($sp)
    ctx->pc = 0x11200cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x112010: 0xdfb10078  ld          $s1, 0x78($sp)
    ctx->pc = 0x112010u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x112014: 0xdfb20080  ld          $s2, 0x80($sp)
    ctx->pc = 0x112014u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x112018: 0xdfb30088  ld          $s3, 0x88($sp)
    ctx->pc = 0x112018u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x11201c: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x11201cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x112020: 0xdfb50098  ld          $s5, 0x98($sp)
    ctx->pc = 0x112020u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x112024: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x112024u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x112028: 0xdfbf00a8  ld          $ra, 0xA8($sp)
    ctx->pc = 0x112028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x11202c: 0x3e00008  jr          $ra
    ctx->pc = 0x11202Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11202Cu;
            // 0x112030: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111DE8u: goto label_111de8;
            case 0x111DF8u: goto label_111df8;
            case 0x111E38u: goto label_111e38;
            case 0x111E4Cu: goto label_111e4c;
            case 0x111E58u: goto label_111e58;
            case 0x111E64u: goto label_111e64;
            case 0x111E80u: goto label_111e80;
            case 0x111E8Cu: goto label_111e8c;
            case 0x111EA8u: goto label_111ea8;
            case 0x111ED0u: goto label_111ed0;
            case 0x111EE0u: goto label_111ee0;
            case 0x111EF0u: goto label_111ef0;
            case 0x111F04u: goto label_111f04;
            case 0x111F78u: goto label_111f78;
            case 0x111F98u: goto label_111f98;
            case 0x111FA4u: goto label_111fa4;
            case 0x111FD0u: goto label_111fd0;
            case 0x111FF8u: goto label_111ff8;
            case 0x112004u: goto label_112004;
            case 0x11200Cu: goto label_11200c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112034u;
    // 0x112034: 0x0  nop
    ctx->pc = 0x112034u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
