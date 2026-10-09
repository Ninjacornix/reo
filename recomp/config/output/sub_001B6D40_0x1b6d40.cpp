#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6D40
// Address: 0x1b6d40 - 0x1b6e90
void sub_001B6D40_0x1b6d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6D40_0x1b6d40");
#endif

    switch (ctx->pc) {
        case 0x1b6e18u: goto label_1b6e18;
        case 0x1b6e54u: goto label_1b6e54;
        case 0x1b6e60u: goto label_1b6e60;
        default: break;
    }

    ctx->pc = 0x1b6d40u;

    // 0x1b6d40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b6d40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b6d44: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b6d44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b6d48: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b6d48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b6d4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b6d4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b6d50: 0xafa4003c  sw          $a0, 0x3C($sp)
    ctx->pc = 0x1b6d50u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 4));
    // 0x1b6d54: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b6d54u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b6d58: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x1b6d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1b6d5c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1b6d5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b6d60: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6D60u;
    {
        const bool branch_taken_0x1b6d60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D60u;
            // 0x1b6d64: 0x2610aaf0  addiu       $s0, $s0, -0x5510 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d60) {
            ctx->pc = 0x1B6D70u;
            goto label_1b6d70;
        }
    }
    ctx->pc = 0x1B6D68u;
    // 0x1b6d68: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1B6D68u;
    {
        const bool branch_taken_0x1b6d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D68u;
            // 0x1b6d6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d68) {
            ctx->pc = 0x1B6E70u;
            goto label_1b6e70;
        }
    }
    ctx->pc = 0x1B6D70u;
label_1b6d70:
    // 0x1b6d70: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1b6d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1b6d74: 0x24110002  addiu       $s1, $zero, 0x2
    ctx->pc = 0x1b6d74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b6d78: 0x10510010  beq         $v0, $s1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B6D78u;
    {
        const bool branch_taken_0x1b6d78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x1B6D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D78u;
            // 0x1b6d7c: 0x2c610080  sltiu       $at, $v1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d78) {
            ctx->pc = 0x1B6DBCu;
            goto label_1b6dbc;
        }
    }
    ctx->pc = 0x1B6D80u;
    // 0x1b6d80: 0x2c620080  sltiu       $v0, $v1, 0x80
    ctx->pc = 0x1b6d80u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b6d84: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6D84u;
    {
        const bool branch_taken_0x1b6d84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D84u;
            // 0x1b6d88: 0x2c6200e0  sltiu       $v0, $v1, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d84) {
            ctx->pc = 0x1B6D98u;
            goto label_1b6d98;
        }
    }
    ctx->pc = 0x1B6D8Cu;
    // 0x1b6d8c: 0x2c6100c0  sltiu       $at, $v1, 0xC0
    ctx->pc = 0x1b6d8cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)192) ? 1 : 0);
    // 0x1b6d90: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6D90u;
    {
        const bool branch_taken_0x1b6d90 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6d90) {
            ctx->pc = 0x1B6DA8u;
            goto label_1b6da8;
        }
    }
    ctx->pc = 0x1B6D98u;
label_1b6d98:
    // 0x1b6d98: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6D98u;
    {
        const bool branch_taken_0x1b6d98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D98u;
            // 0x1b6d9c: 0x2c610100  sltiu       $at, $v1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d98) {
            ctx->pc = 0x1B6DB0u;
            goto label_1b6db0;
        }
    }
    ctx->pc = 0x1B6DA0u;
    // 0x1b6da0: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6DA0u;
    {
        const bool branch_taken_0x1b6da0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DA0u;
            // 0x1b6da4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6da0) {
            ctx->pc = 0x1B6DB4u;
            goto label_1b6db4;
        }
    }
    ctx->pc = 0x1B6DA8u;
label_1b6da8:
    // 0x1b6da8: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1B6DA8u;
    {
        const bool branch_taken_0x1b6da8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DA8u;
            // 0x1b6dac: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6da8) {
            ctx->pc = 0x1B6E70u;
            goto label_1b6e70;
        }
    }
    ctx->pc = 0x1B6DB0u;
label_1b6db0:
    // 0x1b6db0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b6db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b6db4:
    // 0x1b6db4: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1B6DB4u;
    {
        const bool branch_taken_0x1b6db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DB4u;
            // 0x1b6db8: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6db4) {
            ctx->pc = 0x1B6E74u;
            goto label_1b6e74;
        }
    }
    ctx->pc = 0x1B6DBCu;
label_1b6dbc:
    // 0x1b6dbc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6DBCu;
    {
        const bool branch_taken_0x1b6dbc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DBCu;
            // 0x1b6dc0: 0x2c6200c0  sltiu       $v0, $v1, 0xC0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)192) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6dbc) {
            ctx->pc = 0x1B6DCCu;
            goto label_1b6dcc;
        }
    }
    ctx->pc = 0x1B6DC4u;
    // 0x1b6dc4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B6DC4u;
    {
        const bool branch_taken_0x1b6dc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DC4u;
            // 0x1b6dc8: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6dc4) {
            ctx->pc = 0x1B6E0Cu;
            goto label_1b6e0c;
        }
    }
    ctx->pc = 0x1B6DCCu;
label_1b6dcc:
    // 0x1b6dcc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6DCCu;
    {
        const bool branch_taken_0x1b6dcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DCCu;
            // 0x1b6dd0: 0x2c6100e0  sltiu       $at, $v1, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6dcc) {
            ctx->pc = 0x1B6DE4u;
            goto label_1b6de4;
        }
    }
    ctx->pc = 0x1B6DD4u;
    // 0x1b6dd4: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6DD4u;
    {
        const bool branch_taken_0x1b6dd4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DD4u;
            // 0x1b6dd8: 0x2c6200e0  sltiu       $v0, $v1, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6dd4) {
            ctx->pc = 0x1B6DE8u;
            goto label_1b6de8;
        }
    }
    ctx->pc = 0x1B6DDCu;
    // 0x1b6ddc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B6DDCu;
    {
        const bool branch_taken_0x1b6ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DDCu;
            // 0x1b6de0: 0x27a4003c  addiu       $a0, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ddc) {
            ctx->pc = 0x1B6E10u;
            goto label_1b6e10;
        }
    }
    ctx->pc = 0x1B6DE4u;
label_1b6de4:
    // 0x1b6de4: 0x2c6200e0  sltiu       $v0, $v1, 0xE0
    ctx->pc = 0x1b6de4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
label_1b6de8:
    // 0x1b6de8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B6DE8u;
    {
        const bool branch_taken_0x1b6de8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DE8u;
            // 0x1b6dec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6de8) {
            ctx->pc = 0x1B6E04u;
            goto label_1b6e04;
        }
    }
    ctx->pc = 0x1B6DF0u;
    // 0x1b6df0: 0x2c6100f0  sltiu       $at, $v1, 0xF0
    ctx->pc = 0x1b6df0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)240) ? 1 : 0);
    // 0x1b6df4: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6DF4u;
    {
        const bool branch_taken_0x1b6df4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6DF4u;
            // 0x1b6df8: 0x24110003  addiu       $s1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6df4) {
            ctx->pc = 0x1B6E04u;
            goto label_1b6e04;
        }
    }
    ctx->pc = 0x1B6DFCu;
    // 0x1b6dfc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6DFCu;
    {
        const bool branch_taken_0x1b6dfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6dfc) {
            ctx->pc = 0x1B6E0Cu;
            goto label_1b6e0c;
        }
    }
    ctx->pc = 0x1B6E04u;
label_1b6e04:
    // 0x1b6e04: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1B6E04u;
    {
        const bool branch_taken_0x1b6e04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6e04) {
            ctx->pc = 0x1B6E70u;
            goto label_1b6e70;
        }
    }
    ctx->pc = 0x1B6E0Cu;
label_1b6e0c:
    // 0x1b6e0c: 0x27a4003c  addiu       $a0, $sp, 0x3C
    ctx->pc = 0x1b6e0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
label_1b6e10:
    // 0x1b6e10: 0xc06d9b0  jal         func_1B66C0
    ctx->pc = 0x1B6E10u;
    SET_GPR_U32(ctx, 31, 0x1B6E18u);
    ctx->pc = 0x1B66C0u;
    if (runtime->hasFunction(0x1B66C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B66C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6E18u; }
        if (ctx->pc != 0x1B6E18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B66C0_0x1b66c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6E18u; }
        if (ctx->pc != 0x1B6E18u) { return; }
    }
    ctx->pc = 0x1B6E18u;
label_1b6e18:
    // 0x1b6e18: 0x8e030094  lw          $v1, 0x94($s0)
    ctx->pc = 0x1b6e18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1b6e1c: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1B6E1Cu;
    {
        const bool branch_taken_0x1b6e1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E1Cu;
            // 0x1b6e20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6e1c) {
            ctx->pc = 0x1B6E4Cu;
            goto label_1b6e4c;
        }
    }
    ctx->pc = 0x1B6E24u;
    // 0x1b6e24: 0x2c410010  sltiu       $at, $v0, 0x10
    ctx->pc = 0x1b6e24u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b6e28: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6E28u;
    {
        const bool branch_taken_0x1b6e28 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E28u;
            // 0x1b6e2c: 0x2c410080  sltiu       $at, $v0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6e28) {
            ctx->pc = 0x1B6E38u;
            goto label_1b6e38;
        }
    }
    ctx->pc = 0x1B6E30u;
    // 0x1b6e30: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1B6E30u;
    {
        const bool branch_taken_0x1b6e30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E30u;
            // 0x1b6e34: 0x36220010  ori         $v0, $s1, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6e30) {
            ctx->pc = 0x1B6E70u;
            goto label_1b6e70;
        }
    }
    ctx->pc = 0x1B6E38u;
label_1b6e38:
    // 0x1b6e38: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6E38u;
    {
        const bool branch_taken_0x1b6e38 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6e38) {
            ctx->pc = 0x1B6E48u;
            goto label_1b6e48;
        }
    }
    ctx->pc = 0x1B6E40u;
    // 0x1b6e40: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B6E40u;
    {
        const bool branch_taken_0x1b6e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E40u;
            // 0x1b6e44: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6e40) {
            ctx->pc = 0x1B6E70u;
            goto label_1b6e70;
        }
    }
    ctx->pc = 0x1B6E48u;
label_1b6e48:
    // 0x1b6e48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b6e48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b6e4c:
    // 0x1b6e4c: 0xc06d9fc  jal         func_1B67F0
    ctx->pc = 0x1B6E4Cu;
    SET_GPR_U32(ctx, 31, 0x1B6E54u);
    ctx->pc = 0x1B6E50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E4Cu;
            // 0x1b6e50: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B67F0u;
    if (runtime->hasFunction(0x1B67F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B67F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6E54u; }
        if (ctx->pc != 0x1B6E54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B67F0_0x1b67f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6E54u; }
        if (ctx->pc != 0x1B6E54u) { return; }
    }
    ctx->pc = 0x1B6E54u;
label_1b6e54:
    // 0x1b6e54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b6e54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6e58: 0xc06da8c  jal         func_1B6A30
    ctx->pc = 0x1B6E58u;
    SET_GPR_U32(ctx, 31, 0x1B6E60u);
    ctx->pc = 0x1B6E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E58u;
            // 0x1b6e5c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6A30u;
    if (runtime->hasFunction(0x1B6A30u)) {
        auto targetFn = runtime->lookupFunction(0x1B6A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6E60u; }
        if (ctx->pc != 0x1B6E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6A30_0x1b6a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6E60u; }
        if (ctx->pc != 0x1B6E60u) { return; }
    }
    ctx->pc = 0x1B6E60u;
label_1b6e60:
    // 0x1b6e60: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B6E60u;
    {
        const bool branch_taken_0x1b6e60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6e60) {
            ctx->pc = 0x1B6E6Cu;
            goto label_1b6e6c;
        }
    }
    ctx->pc = 0x1B6E68u;
    // 0x1b6e68: 0x36310010  ori         $s1, $s1, 0x10
    ctx->pc = 0x1b6e68u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)16);
label_1b6e6c:
    // 0x1b6e6c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1b6e6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1b6e70:
    // 0x1b6e70: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b6e70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1b6e74:
    // 0x1b6e74: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b6e74u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b6e78: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b6e78u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b6e7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6E7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6E7Cu;
            // 0x1b6e80: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6D70u: goto label_1b6d70;
            case 0x1B6D98u: goto label_1b6d98;
            case 0x1B6DA8u: goto label_1b6da8;
            case 0x1B6DB0u: goto label_1b6db0;
            case 0x1B6DB4u: goto label_1b6db4;
            case 0x1B6DBCu: goto label_1b6dbc;
            case 0x1B6DCCu: goto label_1b6dcc;
            case 0x1B6DE4u: goto label_1b6de4;
            case 0x1B6DE8u: goto label_1b6de8;
            case 0x1B6E04u: goto label_1b6e04;
            case 0x1B6E0Cu: goto label_1b6e0c;
            case 0x1B6E10u: goto label_1b6e10;
            case 0x1B6E18u: goto label_1b6e18;
            case 0x1B6E38u: goto label_1b6e38;
            case 0x1B6E48u: goto label_1b6e48;
            case 0x1B6E4Cu: goto label_1b6e4c;
            case 0x1B6E54u: goto label_1b6e54;
            case 0x1B6E60u: goto label_1b6e60;
            case 0x1B6E6Cu: goto label_1b6e6c;
            case 0x1B6E70u: goto label_1b6e70;
            case 0x1B6E74u: goto label_1b6e74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6E84u;
    // 0x1b6e84: 0x0  nop
    ctx->pc = 0x1b6e84u;
    // NOP
    // 0x1b6e88: 0x0  nop
    ctx->pc = 0x1b6e88u;
    // NOP
    // 0x1b6e8c: 0x0  nop
    ctx->pc = 0x1b6e8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
