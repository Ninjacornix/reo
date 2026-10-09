#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161D20
// Address: 0x161d20 - 0x162090
void sub_00161D20_0x161d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161D20_0x161d20");
#endif

    switch (ctx->pc) {
        case 0x161d34u: goto label_161d34;
        case 0x161d64u: goto label_161d64;
        case 0x161df0u: goto label_161df0;
        case 0x161e48u: goto label_161e48;
        case 0x161e5cu: goto label_161e5c;
        case 0x161e70u: goto label_161e70;
        case 0x161eb4u: goto label_161eb4;
        case 0x161f04u: goto label_161f04;
        case 0x161f18u: goto label_161f18;
        case 0x161f70u: goto label_161f70;
        case 0x161f84u: goto label_161f84;
        case 0x161fa8u: goto label_161fa8;
        case 0x161fb8u: goto label_161fb8;
        case 0x161fccu: goto label_161fcc;
        case 0x161fd8u: goto label_161fd8;
        case 0x162010u: goto label_162010;
        case 0x162024u: goto label_162024;
        case 0x162048u: goto label_162048;
        case 0x162058u: goto label_162058;
        case 0x16206cu: goto label_16206c;
        case 0x162078u: goto label_162078;
        default: break;
    }

    ctx->pc = 0x161d20u;

    // 0x161d20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161d24: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161d28: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161d2c: 0xc05862c  jal         func_1618B0
    ctx->pc = 0x161D2Cu;
    SET_GPR_U32(ctx, 31, 0x161D34u);
    ctx->pc = 0x161D30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161D2Cu;
            // 0x161d30: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1618B0u;
    if (runtime->hasFunction(0x1618B0u)) {
        auto targetFn = runtime->lookupFunction(0x1618B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D34u; }
        if (ctx->pc != 0x161D34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001618B0_0x1618b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D34u; }
        if (ctx->pc != 0x161D34u) { return; }
    }
    ctx->pc = 0x161D34u;
label_161d34:
    // 0x161d34: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x161d34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161d38: 0x54430003  bnel        $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x161D38u;
    {
        const bool branch_taken_0x161d38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x161d38) {
            ctx->pc = 0x161D3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161D38u;
            // 0x161d3c: 0x8e0300e8  lw          $v1, 0xE8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161D48u;
            goto label_161d48;
        }
    }
    ctx->pc = 0x161D40u;
    // 0x161d40: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x161D40u;
    {
        const bool branch_taken_0x161d40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161D40u;
            // 0x161d44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161d40) {
            ctx->pc = 0x161D70u;
            goto label_161d70;
        }
    }
    ctx->pc = 0x161D48u;
label_161d48:
    // 0x161d48: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x161D48u;
    {
        const bool branch_taken_0x161d48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x161D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161D48u;
            // 0x161d4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161d48) {
            ctx->pc = 0x161D70u;
            goto label_161d70;
        }
    }
    ctx->pc = 0x161D50u;
    // 0x161d50: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x161d50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x161d54: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x161d54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x161d58: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x161d58u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161d5c: 0xc05e244  jal         func_178910
    ctx->pc = 0x161D5Cu;
    SET_GPR_U32(ctx, 31, 0x161D64u);
    ctx->pc = 0x161D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161D5Cu;
            // 0x161d60: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178910u;
    if (runtime->hasFunction(0x178910u)) {
        auto targetFn = runtime->lookupFunction(0x178910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D64u; }
        if (ctx->pc != 0x161D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178910_0x178910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D64u; }
        if (ctx->pc != 0x161D64u) { return; }
    }
    ctx->pc = 0x161D64u;
label_161d64:
    // 0x161d64: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x161d64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x161d68: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x161d68u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x161d6c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x161d6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_161d70:
    // 0x161d70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161d70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161d74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161d74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161d78: 0x3e00008  jr          $ra
    ctx->pc = 0x161D78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161D78u;
            // 0x161d7c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161D80u;
    // 0x161d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161d84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161d88: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x161d88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x161d8c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161d8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161d90: 0x805f4f8  j           func_17D3E0
    ctx->pc = 0x161D90u;
    ctx->pc = 0x161D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161D90u;
            // 0x161d94: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3E0u;
    if (runtime->hasFunction(0x17D3E0u)) {
        auto targetFn = runtime->lookupFunction(0x17D3E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D3E0_0x17d3e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161D98u;
    // 0x161d98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161d98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161d9c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x161d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x161da0: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x161da0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x161da4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x161da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161da8: 0x805f4fe  j           func_17D3F8
    ctx->pc = 0x161DA8u;
    ctx->pc = 0x161DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161DA8u;
            // 0x161dac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3F8u;
    if (runtime->hasFunction(0x17D3F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D3F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D3F8_0x17d3f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161DB0u;
    // 0x161db0: 0x24840100  addiu       $a0, $a0, 0x100
    ctx->pc = 0x161db0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
    // 0x161db4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x161db4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x161db8: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x161db8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x161dbc: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x161dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x161dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x161DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161DC0u;
            // 0x161dc4: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161DC8u;
    // 0x161dc8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x161dcc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x161dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x161dd0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x161dd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161dd4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x161dd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x161dd8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x161dd8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ddc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x161ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x161de0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161de0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161de4: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x161de4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x161de8: 0xc05f4e4  jal         func_17D390
    ctx->pc = 0x161DE8u;
    SET_GPR_U32(ctx, 31, 0x161DF0u);
    ctx->pc = 0x161DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161DE8u;
            // 0x161dec: 0x8c8400a8  lw          $a0, 0xA8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D390u;
    if (runtime->hasFunction(0x17D390u)) {
        auto targetFn = runtime->lookupFunction(0x17D390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161DF0u; }
        if (ctx->pc != 0x161DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D390_0x17d390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161DF0u; }
        if (ctx->pc != 0x161DF0u) { return; }
    }
    ctx->pc = 0x161DF0u;
label_161df0:
    // 0x161df0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x161df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161df4: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x161df4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x161df8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x161df8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x161dfc: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x161dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x161e00: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x161e00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161e04: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x161e04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161e08: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x161e08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x161e0c: 0x3e00008  jr          $ra
    ctx->pc = 0x161E0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161E0Cu;
            // 0x161e10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161E14u;
    // 0x161e14: 0x0  nop
    ctx->pc = 0x161e14u;
    // NOP
    // 0x161e18: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161e1c: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x161e20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161e20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e24: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161e28: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x161e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161e2c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x161e2cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e30: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x161e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161e34: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x161e34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e38: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x161e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x161e3c: 0xffbf00b8  sd          $ra, 0xB8($sp)
    ctx->pc = 0x161e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 31));
    // 0x161e40: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161E40u;
    SET_GPR_U32(ctx, 31, 0x161E48u);
    ctx->pc = 0x161E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161E40u;
            // 0x161e44: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E48u; }
        if (ctx->pc != 0x161E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E48u; }
        if (ctx->pc != 0x161E48u) { return; }
    }
    ctx->pc = 0x161E48u;
label_161e48:
    // 0x161e48: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161e48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161e4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e50: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161e50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e54: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x161E54u;
    SET_GPR_U32(ctx, 31, 0x161E5Cu);
    ctx->pc = 0x161E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161E54u;
            // 0x161e58: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E5Cu; }
        if (ctx->pc != 0x161E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E5Cu; }
        if (ctx->pc != 0x161E5Cu) { return; }
    }
    ctx->pc = 0x161E5Cu;
label_161e5c:
    // 0x161e5c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161e5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e60: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x161e60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e64: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x161e64u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e68: 0xc05f504  jal         func_17D410
    ctx->pc = 0x161E68u;
    SET_GPR_U32(ctx, 31, 0x161E70u);
    ctx->pc = 0x161E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161E68u;
            // 0x161e6c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D410u;
    if (runtime->hasFunction(0x17D410u)) {
        auto targetFn = runtime->lookupFunction(0x17D410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E70u; }
        if (ctx->pc != 0x161E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D410_0x17d410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161E70u; }
        if (ctx->pc != 0x161E70u) { return; }
    }
    ctx->pc = 0x161E70u;
label_161e70:
    // 0x161e70: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161e70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x161e74: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161e74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161e78: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161e78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161e7c: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161e7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161e80: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x161e80u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161e84: 0xdfbf00b8  ld          $ra, 0xB8($sp)
    ctx->pc = 0x161e84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x161e88: 0x3e00008  jr          $ra
    ctx->pc = 0x161E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161E88u;
            // 0x161e8c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161E90u;
    // 0x161e90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161e94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161e98: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x161e98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161e9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161ea0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x161ea0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ea4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x161ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x161ea8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x161ea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x161eac: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161EACu;
    SET_GPR_U32(ctx, 31, 0x161EB4u);
    ctx->pc = 0x161EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161EACu;
            // 0x161eb0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161EB4u; }
        if (ctx->pc != 0x161EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161EB4u; }
        if (ctx->pc != 0x161EB4u) { return; }
    }
    ctx->pc = 0x161EB4u;
label_161eb4:
    // 0x161eb4: 0x3a100001  xori        $s0, $s0, 0x1
    ctx->pc = 0x161eb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) ^ (uint64_t)(uint16_t)1);
    // 0x161eb8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161eb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161ebc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x161ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ec0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161ec4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x161ec4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161ec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161ecc: 0x2e070001  sltiu       $a3, $s0, 0x1
    ctx->pc = 0x161eccu;
    SET_GPR_U64(ctx, 7, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x161ed0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161ed0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161ed4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161ed4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ed8: 0x805f50c  j           func_17D430
    ctx->pc = 0x161ED8u;
    ctx->pc = 0x161EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161ED8u;
            // 0x161edc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D430u;
    if (runtime->hasFunction(0x17D430u)) {
        auto targetFn = runtime->lookupFunction(0x17D430u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D430_0x17d430(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161EE0u;
    // 0x161ee0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x161ee4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x161ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x161ee8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x161ee8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161eec: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x161eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x161ef0: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x161ef0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ef4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x161ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x161ef8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x161ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x161efc: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161EFCu;
    SET_GPR_U32(ctx, 31, 0x161F04u);
    ctx->pc = 0x161F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161EFCu;
            // 0x161f00: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F04u; }
        if (ctx->pc != 0x161F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F04u; }
        if (ctx->pc != 0x161F04u) { return; }
    }
    ctx->pc = 0x161F04u;
label_161f04:
    // 0x161f04: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161f04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161f08: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161f08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161f0c: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x161f0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x161f10: 0xc05f512  jal         func_17D448
    ctx->pc = 0x161F10u;
    SET_GPR_U32(ctx, 31, 0x161F18u);
    ctx->pc = 0x161F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161F10u;
            // 0x161f14: 0x27a70008  addiu       $a3, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D448u;
    if (runtime->hasFunction(0x17D448u)) {
        auto targetFn = runtime->lookupFunction(0x17D448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F18u; }
        if (ctx->pc != 0x161F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D448_0x17d448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F18u; }
        if (ctx->pc != 0x161F18u) { return; }
    }
    ctx->pc = 0x161F18u;
label_161f18:
    // 0x161f18: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x161f18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161f1c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x161f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161f20: 0x38430001  xori        $v1, $v0, 0x1
    ctx->pc = 0x161f20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x161f24: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x161f24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x161f28: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x161f28u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x161f2c: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x161f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0x161f30: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x161f30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x161f34: 0xae450000  sw          $a1, 0x0($s2)
    ctx->pc = 0x161f34u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 5));
    // 0x161f38: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x161f38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161f3c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x161f3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161f40: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x161f40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x161f44: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x161f44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x161f48: 0x3e00008  jr          $ra
    ctx->pc = 0x161F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161F48u;
            // 0x161f4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161F50u;
    // 0x161f50: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x161f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x161f54: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161f54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161f58: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161f58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161f5c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x161f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161f60: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161f60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x161f64: 0xffbf00a8  sd          $ra, 0xA8($sp)
    ctx->pc = 0x161f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x161f68: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161F68u;
    SET_GPR_U32(ctx, 31, 0x161F70u);
    ctx->pc = 0x161F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161F68u;
            // 0x161f6c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F70u; }
        if (ctx->pc != 0x161F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F70u; }
        if (ctx->pc != 0x161F70u) { return; }
    }
    ctx->pc = 0x161F70u;
label_161f70:
    // 0x161f70: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161f70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161f74: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161F74u;
    {
        const bool branch_taken_0x161f74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161F74u;
            // 0x161f78: 0x2484ff08  addiu       $a0, $a0, -0xF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161f74) {
            ctx->pc = 0x161F90u;
            goto label_161f90;
        }
    }
    ctx->pc = 0x161F7Cu;
    // 0x161f7c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161F7Cu;
    SET_GPR_U32(ctx, 31, 0x161F84u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F84u; }
        if (ctx->pc != 0x161F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F84u; }
        if (ctx->pc != 0x161F84u) { return; }
    }
    ctx->pc = 0x161F84u;
label_161f84:
    // 0x161f84: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x161F84u;
    {
        const bool branch_taken_0x161f84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161F84u;
            // 0x161f88: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161f84) {
            ctx->pc = 0x161FDCu;
            goto label_161fdc;
        }
    }
    ctx->pc = 0x161F8Cu;
    // 0x161f8c: 0x0  nop
    ctx->pc = 0x161f8cu;
    // NOP
label_161f90:
    // 0x161f90: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x161f90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x161f94: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161F94u;
    {
        const bool branch_taken_0x161f94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161f94) {
            ctx->pc = 0x161FB0u;
            goto label_161fb0;
        }
    }
    ctx->pc = 0x161F9Cu;
    // 0x161f9c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161fa0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161FA0u;
    SET_GPR_U32(ctx, 31, 0x161FA8u);
    ctx->pc = 0x161FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FA0u;
            // 0x161fa4: 0x2484ff38  addiu       $a0, $a0, -0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FA8u; }
        if (ctx->pc != 0x161FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FA8u; }
        if (ctx->pc != 0x161FA8u) { return; }
    }
    ctx->pc = 0x161FA8u;
label_161fa8:
    // 0x161fa8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x161FA8u;
    {
        const bool branch_taken_0x161fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161FA8u;
            // 0x161fac: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161fa8) {
            ctx->pc = 0x161FDCu;
            goto label_161fdc;
        }
    }
    ctx->pc = 0x161FB0u;
label_161fb0:
    // 0x161fb0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161FB0u;
    SET_GPR_U32(ctx, 31, 0x161FB8u);
    ctx->pc = 0x161FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FB0u;
            // 0x161fb4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FB8u; }
        if (ctx->pc != 0x161FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FB8u; }
        if (ctx->pc != 0x161FB8u) { return; }
    }
    ctx->pc = 0x161FB8u;
label_161fb8:
    // 0x161fb8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161fb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fbc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161fbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fc0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161fc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fc4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x161FC4u;
    SET_GPR_U32(ctx, 31, 0x161FCCu);
    ctx->pc = 0x161FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FC4u;
            // 0x161fc8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FCCu; }
        if (ctx->pc != 0x161FCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FCCu; }
        if (ctx->pc != 0x161FCCu) { return; }
    }
    ctx->pc = 0x161FCCu;
label_161fcc:
    // 0x161fcc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161fccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fd0: 0xc05f250  jal         func_17C940
    ctx->pc = 0x161FD0u;
    SET_GPR_U32(ctx, 31, 0x161FD8u);
    ctx->pc = 0x161FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FD0u;
            // 0x161fd4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C940u;
    if (runtime->hasFunction(0x17C940u)) {
        auto targetFn = runtime->lookupFunction(0x17C940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FD8u; }
        if (ctx->pc != 0x161FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C940_0x17c940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FD8u; }
        if (ctx->pc != 0x161FD8u) { return; }
    }
    ctx->pc = 0x161FD8u;
label_161fd8:
    // 0x161fd8: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161fd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161fdc:
    // 0x161fdc: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161fdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161fe0: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161fe0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161fe4: 0xdfbf00a8  ld          $ra, 0xA8($sp)
    ctx->pc = 0x161fe4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161fe8: 0x3e00008  jr          $ra
    ctx->pc = 0x161FE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161FE8u;
            // 0x161fec: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161FF0u;
    // 0x161ff0: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x161ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x161ff4: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161ff8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161ff8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ffc: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x161ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x162000: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x162000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x162004: 0xffbf00a8  sd          $ra, 0xA8($sp)
    ctx->pc = 0x162004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x162008: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162008u;
    SET_GPR_U32(ctx, 31, 0x162010u);
    ctx->pc = 0x16200Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162008u;
            // 0x16200c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162010u; }
        if (ctx->pc != 0x162010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162010u; }
        if (ctx->pc != 0x162010u) { return; }
    }
    ctx->pc = 0x162010u;
label_162010:
    // 0x162010: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162010u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162014: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162014u;
    {
        const bool branch_taken_0x162014 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162014u;
            // 0x162018: 0x2484ff68  addiu       $a0, $a0, -0x98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162014) {
            ctx->pc = 0x162030u;
            goto label_162030;
        }
    }
    ctx->pc = 0x16201Cu;
    // 0x16201c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16201Cu;
    SET_GPR_U32(ctx, 31, 0x162024u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162024u; }
        if (ctx->pc != 0x162024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162024u; }
        if (ctx->pc != 0x162024u) { return; }
    }
    ctx->pc = 0x162024u;
label_162024:
    // 0x162024: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x162024u;
    {
        const bool branch_taken_0x162024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162024u;
            // 0x162028: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162024) {
            ctx->pc = 0x16207Cu;
            goto label_16207c;
        }
    }
    ctx->pc = 0x16202Cu;
    // 0x16202c: 0x0  nop
    ctx->pc = 0x16202cu;
    // NOP
label_162030:
    // 0x162030: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x162030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x162034: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162034u;
    {
        const bool branch_taken_0x162034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x162034) {
            ctx->pc = 0x162050u;
            goto label_162050;
        }
    }
    ctx->pc = 0x16203Cu;
    // 0x16203c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16203cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162040: 0xc058dd4  jal         func_163750
    ctx->pc = 0x162040u;
    SET_GPR_U32(ctx, 31, 0x162048u);
    ctx->pc = 0x162044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162040u;
            // 0x162044: 0x2484ff98  addiu       $a0, $a0, -0x68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162048u; }
        if (ctx->pc != 0x162048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162048u; }
        if (ctx->pc != 0x162048u) { return; }
    }
    ctx->pc = 0x162048u;
label_162048:
    // 0x162048: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x162048u;
    {
        const bool branch_taken_0x162048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16204Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162048u;
            // 0x16204c: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162048) {
            ctx->pc = 0x16207Cu;
            goto label_16207c;
        }
    }
    ctx->pc = 0x162050u;
label_162050:
    // 0x162050: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x162050u;
    SET_GPR_U32(ctx, 31, 0x162058u);
    ctx->pc = 0x162054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162050u;
            // 0x162054: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162058u; }
        if (ctx->pc != 0x162058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162058u; }
        if (ctx->pc != 0x162058u) { return; }
    }
    ctx->pc = 0x162058u;
label_162058:
    // 0x162058: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x162058u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16205c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16205cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162060: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x162060u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162064: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x162064u;
    SET_GPR_U32(ctx, 31, 0x16206Cu);
    ctx->pc = 0x162068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162064u;
            // 0x162068: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16206Cu; }
        if (ctx->pc != 0x16206Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16206Cu; }
        if (ctx->pc != 0x16206Cu) { return; }
    }
    ctx->pc = 0x16206Cu;
label_16206c:
    // 0x16206c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16206cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162070: 0xc05f26a  jal         func_17C9A8
    ctx->pc = 0x162070u;
    SET_GPR_U32(ctx, 31, 0x162078u);
    ctx->pc = 0x162074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162070u;
            // 0x162074: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C9A8u;
    if (runtime->hasFunction(0x17C9A8u)) {
        auto targetFn = runtime->lookupFunction(0x17C9A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162078u; }
        if (ctx->pc != 0x162078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C9A8_0x17c9a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162078u; }
        if (ctx->pc != 0x162078u) { return; }
    }
    ctx->pc = 0x162078u;
label_162078:
    // 0x162078: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x162078u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_16207c:
    // 0x16207c: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x16207cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x162080: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x162080u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x162084: 0xdfbf00a8  ld          $ra, 0xA8($sp)
    ctx->pc = 0x162084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x162088: 0x3e00008  jr          $ra
    ctx->pc = 0x162088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16208Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162088u;
            // 0x16208c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161D34u: goto label_161d34;
            case 0x161D48u: goto label_161d48;
            case 0x161D64u: goto label_161d64;
            case 0x161D70u: goto label_161d70;
            case 0x161DF0u: goto label_161df0;
            case 0x161E48u: goto label_161e48;
            case 0x161E5Cu: goto label_161e5c;
            case 0x161E70u: goto label_161e70;
            case 0x161EB4u: goto label_161eb4;
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            case 0x162010u: goto label_162010;
            case 0x162024u: goto label_162024;
            case 0x162030u: goto label_162030;
            case 0x162048u: goto label_162048;
            case 0x162050u: goto label_162050;
            case 0x162058u: goto label_162058;
            case 0x16206Cu: goto label_16206c;
            case 0x162078u: goto label_162078;
            case 0x16207Cu: goto label_16207c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162090u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
