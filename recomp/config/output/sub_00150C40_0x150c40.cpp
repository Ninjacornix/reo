#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150C40
// Address: 0x150c40 - 0x150e00
void sub_00150C40_0x150c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150C40_0x150c40");
#endif

    switch (ctx->pc) {
        case 0x150c68u: goto label_150c68;
        case 0x150c84u: goto label_150c84;
        case 0x150cfcu: goto label_150cfc;
        case 0x150d10u: goto label_150d10;
        case 0x150d20u: goto label_150d20;
        case 0x150d34u: goto label_150d34;
        case 0x150d48u: goto label_150d48;
        case 0x150d5cu: goto label_150d5c;
        case 0x150d80u: goto label_150d80;
        case 0x150d9cu: goto label_150d9c;
        case 0x150db4u: goto label_150db4;
        case 0x150dccu: goto label_150dcc;
        case 0x150dd4u: goto label_150dd4;
        default: break;
    }

    ctx->pc = 0x150c40u;

    // 0x150c40: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x150c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x150c44: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x150c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x150c48: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x150c48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150c4c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x150c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x150c50: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x150c50u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150c54: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x150c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x150c58: 0x27b30010  addiu       $s3, $sp, 0x10
    ctx->pc = 0x150c58u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x150c5c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x150c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x150c60: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x150C60u;
    {
        const bool branch_taken_0x150c60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150C60u;
            // 0x150c64: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150c60) {
            ctx->pc = 0x150DCCu;
            goto label_150dcc;
        }
    }
    ctx->pc = 0x150C68u;
label_150c68:
    // 0x150c68: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x150c68u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x150c6c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x150c6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150c70: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x150c70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x150c74: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x150c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x150c78: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x150c78u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x150c7c: 0x40f809  jalr        $v0
    ctx->pc = 0x150C7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150C84u);
        ctx->pc = 0x150C80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150C7Cu;
            // 0x150c80: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x150C84u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150C68u: goto label_150c68;
            case 0x150C84u: goto label_150c84;
            case 0x150CB8u: goto label_150cb8;
            case 0x150CE0u: goto label_150ce0;
            case 0x150CF0u: goto label_150cf0;
            case 0x150CFCu: goto label_150cfc;
            case 0x150D08u: goto label_150d08;
            case 0x150D10u: goto label_150d10;
            case 0x150D18u: goto label_150d18;
            case 0x150D20u: goto label_150d20;
            case 0x150D28u: goto label_150d28;
            case 0x150D34u: goto label_150d34;
            case 0x150D40u: goto label_150d40;
            case 0x150D48u: goto label_150d48;
            case 0x150D50u: goto label_150d50;
            case 0x150D5Cu: goto label_150d5c;
            case 0x150D60u: goto label_150d60;
            case 0x150D80u: goto label_150d80;
            case 0x150D88u: goto label_150d88;
            case 0x150D9Cu: goto label_150d9c;
            case 0x150DB4u: goto label_150db4;
            case 0x150DCCu: goto label_150dcc;
            case 0x150DD4u: goto label_150dd4;
            case 0x150DE4u: goto label_150de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150C84u; }
            if (ctx->pc != 0x150C84u) { return; }
        }
        }
    }
    ctx->pc = 0x150C84u;
label_150c84:
    // 0x150c84: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x150c84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x150c88: 0x12020027  beq         $s0, $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x150C88u;
    {
        const bool branch_taken_0x150c88 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x150C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150C88u;
            // 0x150c8c: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150c88) {
            ctx->pc = 0x150D28u;
            goto label_150d28;
        }
    }
    ctx->pc = 0x150C90u;
    // 0x150c90: 0x2e020011  sltiu       $v0, $s0, 0x11
    ctx->pc = 0x150c90u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)17) ? 1 : 0);
    // 0x150c94: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x150C94u;
    {
        const bool branch_taken_0x150c94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150C94u;
            // 0x150c98: 0x24020040  addiu       $v0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150c94) {
            ctx->pc = 0x150CB8u;
            goto label_150cb8;
        }
    }
    ctx->pc = 0x150C9Cu;
    // 0x150c9c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x150c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x150ca0: 0x1202002b  beq         $s0, $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x150CA0u;
    {
        const bool branch_taken_0x150ca0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x150CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CA0u;
            // 0x150ca4: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150ca0) {
            ctx->pc = 0x150D50u;
            goto label_150d50;
        }
    }
    ctx->pc = 0x150CA8u;
    // 0x150ca8: 0x12020025  beq         $s0, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x150CA8u;
    {
        const bool branch_taken_0x150ca8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x150CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CA8u;
            // 0x150cac: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150ca8) {
            ctx->pc = 0x150D40u;
            goto label_150d40;
        }
    }
    ctx->pc = 0x150CB0u;
    // 0x150cb0: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x150CB0u;
    {
        const bool branch_taken_0x150cb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x150cb0) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150CB8u;
label_150cb8:
    // 0x150cb8: 0x1202000d  beq         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x150CB8u;
    {
        const bool branch_taken_0x150cb8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x150CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CB8u;
            // 0x150cbc: 0x2e020041  sltiu       $v0, $s0, 0x41 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)65) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x150cb8) {
            ctx->pc = 0x150CF0u;
            goto label_150cf0;
        }
    }
    ctx->pc = 0x150CC0u;
    // 0x150cc0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x150CC0u;
    {
        const bool branch_taken_0x150cc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CC0u;
            // 0x150cc4: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150cc0) {
            ctx->pc = 0x150CE0u;
            goto label_150ce0;
        }
    }
    ctx->pc = 0x150CC8u;
    // 0x150cc8: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x150cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x150ccc: 0x12020012  beq         $s0, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x150CCCu;
    {
        const bool branch_taken_0x150ccc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x150CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CCCu;
            // 0x150cd0: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150ccc) {
            ctx->pc = 0x150D18u;
            goto label_150d18;
        }
    }
    ctx->pc = 0x150CD4u;
    // 0x150cd4: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x150CD4u;
    {
        const bool branch_taken_0x150cd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x150cd4) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150CDCu;
    // 0x150cdc: 0x0  nop
    ctx->pc = 0x150cdcu;
    // NOP
label_150ce0:
    // 0x150ce0: 0x12020009  beq         $s0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x150CE0u;
    {
        const bool branch_taken_0x150ce0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x150CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CE0u;
            // 0x150ce4: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150ce0) {
            ctx->pc = 0x150D08u;
            goto label_150d08;
        }
    }
    ctx->pc = 0x150CE8u;
    // 0x150ce8: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x150CE8u;
    {
        const bool branch_taken_0x150ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x150ce8) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150CF0u;
label_150cf0:
    // 0x150cf0: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x150cf0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150cf4: 0xc05444e  jal         func_151138
    ctx->pc = 0x150CF4u;
    SET_GPR_U32(ctx, 31, 0x150CFCu);
    ctx->pc = 0x150CF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150CF4u;
            // 0x150cf8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151138u;
    if (runtime->hasFunction(0x151138u)) {
        auto targetFn = runtime->lookupFunction(0x151138u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150CFCu; }
        if (ctx->pc != 0x150CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151138_0x151138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150CFCu; }
        if (ctx->pc != 0x150CFCu) { return; }
    }
    ctx->pc = 0x150CFCu;
label_150cfc:
    // 0x150cfc: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x150CFCu;
    {
        const bool branch_taken_0x150cfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150CFCu;
            // 0x150d00: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150cfc) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150D04u;
    // 0x150d04: 0x0  nop
    ctx->pc = 0x150d04u;
    // NOP
label_150d08:
    // 0x150d08: 0xc05461e  jal         func_151878
    ctx->pc = 0x150D08u;
    SET_GPR_U32(ctx, 31, 0x150D10u);
    ctx->pc = 0x150D0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150D08u;
            // 0x150d0c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151878u;
    if (runtime->hasFunction(0x151878u)) {
        auto targetFn = runtime->lookupFunction(0x151878u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D10u; }
        if (ctx->pc != 0x150D10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151878_0x151878(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D10u; }
        if (ctx->pc != 0x150D10u) { return; }
    }
    ctx->pc = 0x150D10u;
label_150d10:
    // 0x150d10: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x150D10u;
    {
        const bool branch_taken_0x150d10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D10u;
            // 0x150d14: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150d10) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150D18u;
label_150d18:
    // 0x150d18: 0xc05465c  jal         func_151970
    ctx->pc = 0x150D18u;
    SET_GPR_U32(ctx, 31, 0x150D20u);
    ctx->pc = 0x150D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150D18u;
            // 0x150d1c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151970u;
    if (runtime->hasFunction(0x151970u)) {
        auto targetFn = runtime->lookupFunction(0x151970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D20u; }
        if (ctx->pc != 0x150D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151970_0x151970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D20u; }
        if (ctx->pc != 0x150D20u) { return; }
    }
    ctx->pc = 0x150D20u;
label_150d20:
    // 0x150d20: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x150D20u;
    {
        const bool branch_taken_0x150d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D20u;
            // 0x150d24: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150d20) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150D28u;
label_150d28:
    // 0x150d28: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x150d28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150d2c: 0xc054730  jal         func_151CC0
    ctx->pc = 0x150D2Cu;
    SET_GPR_U32(ctx, 31, 0x150D34u);
    ctx->pc = 0x150D30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150D2Cu;
            // 0x150d30: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151CC0u;
    if (runtime->hasFunction(0x151CC0u)) {
        auto targetFn = runtime->lookupFunction(0x151CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D34u; }
        if (ctx->pc != 0x150D34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151CC0_0x151cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D34u; }
        if (ctx->pc != 0x150D34u) { return; }
    }
    ctx->pc = 0x150D34u;
label_150d34:
    // 0x150d34: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x150D34u;
    {
        const bool branch_taken_0x150d34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D34u;
            // 0x150d38: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150d34) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150D3Cu;
    // 0x150d3c: 0x0  nop
    ctx->pc = 0x150d3cu;
    // NOP
label_150d40:
    // 0x150d40: 0xc05531e  jal         func_154C78
    ctx->pc = 0x150D40u;
    SET_GPR_U32(ctx, 31, 0x150D48u);
    ctx->pc = 0x150D44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150D40u;
            // 0x150d44: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x154C78u;
    if (runtime->hasFunction(0x154C78u)) {
        auto targetFn = runtime->lookupFunction(0x154C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D48u; }
        if (ctx->pc != 0x150D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00154C78_0x154c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D48u; }
        if (ctx->pc != 0x150D48u) { return; }
    }
    ctx->pc = 0x150D48u;
label_150d48:
    // 0x150d48: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x150D48u;
    {
        const bool branch_taken_0x150d48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D48u;
            // 0x150d4c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150d48) {
            ctx->pc = 0x150D60u;
            goto label_150d60;
        }
    }
    ctx->pc = 0x150D50u;
label_150d50:
    // 0x150d50: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x150d50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150d54: 0xc05546a  jal         func_1551A8
    ctx->pc = 0x150D54u;
    SET_GPR_U32(ctx, 31, 0x150D5Cu);
    ctx->pc = 0x150D58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150D54u;
            // 0x150d58: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1551A8u;
    if (runtime->hasFunction(0x1551A8u)) {
        auto targetFn = runtime->lookupFunction(0x1551A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D5Cu; }
        if (ctx->pc != 0x150D5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001551A8_0x1551a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D5Cu; }
        if (ctx->pc != 0x150D5Cu) { return; }
    }
    ctx->pc = 0x150D5Cu;
label_150d5c:
    // 0x150d5c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x150d5cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_150d60:
    // 0x150d60: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x150D60u;
    {
        const bool branch_taken_0x150d60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x150D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D60u;
            // 0x150d64: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150d60) {
            ctx->pc = 0x150D88u;
            goto label_150d88;
        }
    }
    ctx->pc = 0x150D68u;
    // 0x150d68: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x150d68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x150d6c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x150d6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150d70: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x150d70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x150d74: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x150d74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x150d78: 0x40f809  jalr        $v0
    ctx->pc = 0x150D78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150D80u);
        ctx->pc = 0x150D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D78u;
            // 0x150d7c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x150D80u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150C68u: goto label_150c68;
            case 0x150C84u: goto label_150c84;
            case 0x150CB8u: goto label_150cb8;
            case 0x150CE0u: goto label_150ce0;
            case 0x150CF0u: goto label_150cf0;
            case 0x150CFCu: goto label_150cfc;
            case 0x150D08u: goto label_150d08;
            case 0x150D10u: goto label_150d10;
            case 0x150D18u: goto label_150d18;
            case 0x150D20u: goto label_150d20;
            case 0x150D28u: goto label_150d28;
            case 0x150D34u: goto label_150d34;
            case 0x150D40u: goto label_150d40;
            case 0x150D48u: goto label_150d48;
            case 0x150D50u: goto label_150d50;
            case 0x150D5Cu: goto label_150d5c;
            case 0x150D60u: goto label_150d60;
            case 0x150D80u: goto label_150d80;
            case 0x150D88u: goto label_150d88;
            case 0x150D9Cu: goto label_150d9c;
            case 0x150DB4u: goto label_150db4;
            case 0x150DCCu: goto label_150dcc;
            case 0x150DD4u: goto label_150dd4;
            case 0x150DE4u: goto label_150de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150D80u; }
            if (ctx->pc != 0x150D80u) { return; }
        }
        }
    }
    ctx->pc = 0x150D80u;
label_150d80:
    // 0x150d80: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x150D80u;
    {
        const bool branch_taken_0x150d80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x150D84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150D80u;
            // 0x150d84: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150d80) {
            ctx->pc = 0x150DE4u;
            goto label_150de4;
        }
    }
    ctx->pc = 0x150D88u;
label_150d88:
    // 0x150d88: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x150d88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150d8c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x150d8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150d90: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x150d90u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150d94: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x150D94u;
    SET_GPR_U32(ctx, 31, 0x150D9Cu);
    ctx->pc = 0x150D98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150D94u;
            // 0x150d98: 0x652823  subu        $a1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D9Cu; }
        if (ctx->pc != 0x150D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150D9Cu; }
        if (ctx->pc != 0x150D9Cu) { return; }
    }
    ctx->pc = 0x150D9Cu;
label_150d9c:
    // 0x150d9c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x150d9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x150da0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x150da0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150da4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x150da4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150da8: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x150da8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x150dac: 0x40f809  jalr        $v0
    ctx->pc = 0x150DACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150DB4u);
        ctx->pc = 0x150DB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150DACu;
            // 0x150db0: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x150DB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150C68u: goto label_150c68;
            case 0x150C84u: goto label_150c84;
            case 0x150CB8u: goto label_150cb8;
            case 0x150CE0u: goto label_150ce0;
            case 0x150CF0u: goto label_150cf0;
            case 0x150CFCu: goto label_150cfc;
            case 0x150D08u: goto label_150d08;
            case 0x150D10u: goto label_150d10;
            case 0x150D18u: goto label_150d18;
            case 0x150D20u: goto label_150d20;
            case 0x150D28u: goto label_150d28;
            case 0x150D34u: goto label_150d34;
            case 0x150D40u: goto label_150d40;
            case 0x150D48u: goto label_150d48;
            case 0x150D50u: goto label_150d50;
            case 0x150D5Cu: goto label_150d5c;
            case 0x150D60u: goto label_150d60;
            case 0x150D80u: goto label_150d80;
            case 0x150D88u: goto label_150d88;
            case 0x150D9Cu: goto label_150d9c;
            case 0x150DB4u: goto label_150db4;
            case 0x150DCCu: goto label_150dcc;
            case 0x150DD4u: goto label_150dd4;
            case 0x150DE4u: goto label_150de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150DB4u; }
            if (ctx->pc != 0x150DB4u) { return; }
        }
        }
    }
    ctx->pc = 0x150DB4u;
label_150db4:
    // 0x150db4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x150db4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x150db8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x150db8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150dbc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x150dbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x150dc0: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x150dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x150dc4: 0x40f809  jalr        $v0
    ctx->pc = 0x150DC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150DCCu);
        ctx->pc = 0x150DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150DC4u;
            // 0x150dc8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x150DCCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150C68u: goto label_150c68;
            case 0x150C84u: goto label_150c84;
            case 0x150CB8u: goto label_150cb8;
            case 0x150CE0u: goto label_150ce0;
            case 0x150CF0u: goto label_150cf0;
            case 0x150CFCu: goto label_150cfc;
            case 0x150D08u: goto label_150d08;
            case 0x150D10u: goto label_150d10;
            case 0x150D18u: goto label_150d18;
            case 0x150D20u: goto label_150d20;
            case 0x150D28u: goto label_150d28;
            case 0x150D34u: goto label_150d34;
            case 0x150D40u: goto label_150d40;
            case 0x150D48u: goto label_150d48;
            case 0x150D50u: goto label_150d50;
            case 0x150D5Cu: goto label_150d5c;
            case 0x150D60u: goto label_150d60;
            case 0x150D80u: goto label_150d80;
            case 0x150D88u: goto label_150d88;
            case 0x150D9Cu: goto label_150d9c;
            case 0x150DB4u: goto label_150db4;
            case 0x150DCCu: goto label_150dcc;
            case 0x150DD4u: goto label_150dd4;
            case 0x150DE4u: goto label_150de4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150DCCu; }
            if (ctx->pc != 0x150DCCu) { return; }
        }
        }
    }
    ctx->pc = 0x150DCCu;
label_150dcc:
    // 0x150dcc: 0xc056b7a  jal         func_15ADE8
    ctx->pc = 0x150DCCu;
    SET_GPR_U32(ctx, 31, 0x150DD4u);
    ctx->pc = 0x150DD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150DCCu;
            // 0x150dd0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15ADE8u;
    if (runtime->hasFunction(0x15ADE8u)) {
        auto targetFn = runtime->lookupFunction(0x15ADE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150DD4u; }
        if (ctx->pc != 0x150DD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015ADE8_0x15ade8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150DD4u; }
        if (ctx->pc != 0x150DD4u) { return; }
    }
    ctx->pc = 0x150DD4u;
label_150dd4:
    // 0x150dd4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x150dd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150dd8: 0x5600ffa3  bnel        $s0, $zero, . + 4 + (-0x5D << 2)
    ctx->pc = 0x150DD8u;
    {
        const bool branch_taken_0x150dd8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x150dd8) {
            ctx->pc = 0x150DDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x150DD8u;
            // 0x150ddc: 0x8e230000  lw          $v1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x150C68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150c68;
        }
    }
    ctx->pc = 0x150DE0u;
    // 0x150de0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x150de0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_150de4:
    // 0x150de4: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x150de4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x150de8: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x150de8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x150dec: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x150decu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x150df0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x150df0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x150df4: 0x3e00008  jr          $ra
    ctx->pc = 0x150DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150DF4u;
            // 0x150df8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150C68u: goto label_150c68;
            case 0x150C84u: goto label_150c84;
            case 0x150CB8u: goto label_150cb8;
            case 0x150CE0u: goto label_150ce0;
            case 0x150CF0u: goto label_150cf0;
            case 0x150CFCu: goto label_150cfc;
            case 0x150D08u: goto label_150d08;
            case 0x150D10u: goto label_150d10;
            case 0x150D18u: goto label_150d18;
            case 0x150D20u: goto label_150d20;
            case 0x150D28u: goto label_150d28;
            case 0x150D34u: goto label_150d34;
            case 0x150D40u: goto label_150d40;
            case 0x150D48u: goto label_150d48;
            case 0x150D50u: goto label_150d50;
            case 0x150D5Cu: goto label_150d5c;
            case 0x150D60u: goto label_150d60;
            case 0x150D80u: goto label_150d80;
            case 0x150D88u: goto label_150d88;
            case 0x150D9Cu: goto label_150d9c;
            case 0x150DB4u: goto label_150db4;
            case 0x150DCCu: goto label_150dcc;
            case 0x150DD4u: goto label_150dd4;
            case 0x150DE4u: goto label_150de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150DFCu;
    // 0x150dfc: 0x0  nop
    ctx->pc = 0x150dfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
