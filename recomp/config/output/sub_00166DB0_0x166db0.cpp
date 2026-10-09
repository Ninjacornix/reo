#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166DB0
// Address: 0x166db0 - 0x166e68
void sub_00166DB0_0x166db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166DB0_0x166db0");
#endif

    switch (ctx->pc) {
        case 0x166e58u: goto label_166e58;
        default: break;
    }

    ctx->pc = 0x166db0u;

    // 0x166db0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x166db0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x166db4: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x166DB4u;
    {
        const bool branch_taken_0x166db4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x166DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166DB4u;
            // 0x166db8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166db4) {
            ctx->pc = 0x166DECu;
            goto label_166dec;
        }
    }
    ctx->pc = 0x166DBCu;
    // 0x166dbc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x166dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x166dc0: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x166DC0u;
    {
        const bool branch_taken_0x166dc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x166DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166DC0u;
            // 0x166dc4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166dc0) {
            ctx->pc = 0x166DECu;
            goto label_166dec;
        }
    }
    ctx->pc = 0x166DC8u;
    // 0x166dc8: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x166dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x166dcc: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x166DCCu;
    {
        const bool branch_taken_0x166dcc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x166DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166DCCu;
            // 0x166dd0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166dcc) {
            ctx->pc = 0x166DECu;
            goto label_166dec;
        }
    }
    ctx->pc = 0x166DD4u;
    // 0x166dd4: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x166dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x166dd8: 0x18600004  blez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x166DD8u;
    {
        const bool branch_taken_0x166dd8 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x166dd8) {
            ctx->pc = 0x166DECu;
            goto label_166dec;
        }
    }
    ctx->pc = 0x166DE0u;
    // 0x166de0: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x166de0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x166de4: 0x58600001  blezl       $v1, . + 4 + (0x1 << 2)
    ctx->pc = 0x166DE4u;
    {
        const bool branch_taken_0x166de4 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x166de4) {
            ctx->pc = 0x166DE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x166DE4u;
            // 0x166de8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x166DECu;
            goto label_166dec;
        }
    }
    ctx->pc = 0x166DECu;
label_166dec:
    // 0x166dec: 0x3e00008  jr          $ra
    ctx->pc = 0x166DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166DECu: goto label_166dec;
            case 0x166E48u: goto label_166e48;
            case 0x166E58u: goto label_166e58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166DF4u;
    // 0x166df4: 0x0  nop
    ctx->pc = 0x166df4u;
    // NOP
    // 0x166df8: 0x610c0  sll         $v0, $a2, 3
    ctx->pc = 0x166df8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x166dfc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166dfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x166e00: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x166e00u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x166e04: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166e08: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166e08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166e0c: 0x24831140  addiu       $v1, $a0, 0x1140
    ctx->pc = 0x166e0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x166e10: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x166e10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x166e14: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x166e14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x166e18: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166e18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166e1c: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x166e1cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e20: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x166e20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x166e24: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x166e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x166e28: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x166e28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e2c: 0x10470006  beq         $v0, $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x166E2Cu;
    {
        const bool branch_taken_0x166e2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 7));
        ctx->pc = 0x166E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166E2Cu;
            // 0x166e30: 0x24630010  addiu       $v1, $v1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166e2c) {
            ctx->pc = 0x166E48u;
            goto label_166e48;
        }
    }
    ctx->pc = 0x166E34u;
    // 0x166e34: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x166e34u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166e38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166e38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166e3c: 0x34a50409  ori         $a1, $a1, 0x409
    ctx->pc = 0x166e3cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1033);
    // 0x166e40: 0x805a704  j           func_169C10
    ctx->pc = 0x166E40u;
    ctx->pc = 0x166E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166E40u;
            // 0x166e44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166E48u;
label_166e48:
    // 0x166e48: 0x8d070004  lw          $a3, 0x4($t0)
    ctx->pc = 0x166e48u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x166e4c: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x166e4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e50: 0xc059b9a  jal         func_166E68
    ctx->pc = 0x166E50u;
    SET_GPR_U32(ctx, 31, 0x166E58u);
    ctx->pc = 0x166E54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166E50u;
            // 0x166e54: 0x7382b  sltu        $a3, $zero, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x166E68u;
    if (runtime->hasFunction(0x166E68u)) {
        auto targetFn = runtime->lookupFunction(0x166E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166E58u; }
        if (ctx->pc != 0x166E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166E68_0x166e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166E58u; }
        if (ctx->pc != 0x166E58u) { return; }
    }
    ctx->pc = 0x166E58u;
label_166e58:
    // 0x166e58: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166e58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166e5c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166e5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166e60: 0x3e00008  jr          $ra
    ctx->pc = 0x166E60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166E60u;
            // 0x166e64: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166DECu: goto label_166dec;
            case 0x166E48u: goto label_166e48;
            case 0x166E58u: goto label_166e58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166E68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
