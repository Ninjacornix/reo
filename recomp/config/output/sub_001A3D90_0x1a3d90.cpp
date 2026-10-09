#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3D90
// Address: 0x1a3d90 - 0x1a3e90
void sub_001A3D90_0x1a3d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3D90_0x1a3d90");
#endif

    switch (ctx->pc) {
        case 0x1a3dbcu: goto label_1a3dbc;
        case 0x1a3dc8u: goto label_1a3dc8;
        case 0x1a3df8u: goto label_1a3df8;
        case 0x1a3e60u: goto label_1a3e60;
        case 0x1a3e70u: goto label_1a3e70;
        default: break;
    }

    ctx->pc = 0x1a3d90u;

    // 0x1a3d90: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a3d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a3d94: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a3d94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a3d98: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a3d98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a3d9c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a3d9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a3da0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1a3da0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3da4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1a3da4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3da8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a3da8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a3dac: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a3dacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3db0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a3db0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a3db4: 0xc068d64  jal         func_1A3590
    ctx->pc = 0x1A3DB4u;
    SET_GPR_U32(ctx, 31, 0x1A3DBCu);
    ctx->pc = 0x1A3DB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DB4u;
            // 0x1a3db8: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3590u;
    if (runtime->hasFunction(0x1A3590u)) {
        auto targetFn = runtime->lookupFunction(0x1A3590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3DBCu; }
        if (ctx->pc != 0x1A3DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3590_0x1a3590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3DBCu; }
        if (ctx->pc != 0x1A3DBCu) { return; }
    }
    ctx->pc = 0x1A3DBCu;
label_1a3dbc:
    // 0x1a3dbc: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a3dbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a3dc0: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3DC0u;
    SET_GPR_U32(ctx, 31, 0x1A3DC8u);
    ctx->pc = 0x1A3DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DC0u;
            // 0x1a3dc4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3DC8u; }
        if (ctx->pc != 0x1A3DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3DC8u; }
        if (ctx->pc != 0x1A3DC8u) { return; }
    }
    ctx->pc = 0x1A3DC8u;
label_1a3dc8:
    // 0x1a3dc8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3DC8u;
    {
        const bool branch_taken_0x1a3dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3dc8) {
            ctx->pc = 0x1A3DD8u;
            goto label_1a3dd8;
        }
    }
    ctx->pc = 0x1A3DD0u;
    // 0x1a3dd0: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1A3DD0u;
    {
        const bool branch_taken_0x1a3dd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DD0u;
            // 0x1a3dd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3dd0) {
            ctx->pc = 0x1A3E70u;
            goto label_1a3e70;
        }
    }
    ctx->pc = 0x1A3DD8u;
label_1a3dd8:
    // 0x1a3dd8: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1a3dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a3ddc: 0x222082b  sltu        $at, $s1, $v0
    ctx->pc = 0x1a3ddcu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1a3de0: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3DE0u;
    {
        const bool branch_taken_0x1a3de0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DE0u;
            // 0x1a3de4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3de0) {
            ctx->pc = 0x1A3DF0u;
            goto label_1a3df0;
        }
    }
    ctx->pc = 0x1A3DE8u;
    // 0x1a3de8: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1A3DE8u;
    {
        const bool branch_taken_0x1a3de8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DE8u;
            // 0x1a3dec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3de8) {
            ctx->pc = 0x1A3E70u;
            goto label_1a3e70;
        }
    }
    ctx->pc = 0x1A3DF0u;
label_1a3df0:
    // 0x1a3df0: 0xc068c84  jal         func_1A3210
    ctx->pc = 0x1A3DF0u;
    SET_GPR_U32(ctx, 31, 0x1A3DF8u);
    ctx->pc = 0x1A3DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DF0u;
            // 0x1a3df4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3210u;
    if (runtime->hasFunction(0x1A3210u)) {
        auto targetFn = runtime->lookupFunction(0x1A3210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3DF8u; }
        if (ctx->pc != 0x1A3DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3210_0x1a3210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3DF8u; }
        if (ctx->pc != 0x1A3DF8u) { return; }
    }
    ctx->pc = 0x1A3DF8u;
label_1a3df8:
    // 0x1a3df8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3DF8u;
    {
        const bool branch_taken_0x1a3df8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3DF8u;
            // 0x1a3dfc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3df8) {
            ctx->pc = 0x1A3E08u;
            goto label_1a3e08;
        }
    }
    ctx->pc = 0x1A3E00u;
    // 0x1a3e00: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1A3E00u;
    {
        const bool branch_taken_0x1a3e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E00u;
            // 0x1a3e04: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3e00) {
            ctx->pc = 0x1A3E70u;
            goto label_1a3e70;
        }
    }
    ctx->pc = 0x1A3E08u;
label_1a3e08:
    // 0x1a3e08: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1a3e08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a3e0c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1a3e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a3e10: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1A3E10u;
    {
        const bool branch_taken_0x1a3e10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A3E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E10u;
            // 0x1a3e14: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3e10) {
            ctx->pc = 0x1A3E58u;
            goto label_1a3e58;
        }
    }
    ctx->pc = 0x1A3E18u;
    // 0x1a3e18: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1a3e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a3e1c: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1A3E1Cu;
    {
        const bool branch_taken_0x1a3e1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A3E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E1Cu;
            // 0x1a3e20: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3e1c) {
            ctx->pc = 0x1A3E50u;
            goto label_1a3e50;
        }
    }
    ctx->pc = 0x1A3E24u;
    // 0x1a3e24: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1a3e24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1a3e28: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A3E28u;
    {
        const bool branch_taken_0x1a3e28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A3E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E28u;
            // 0x1a3e2c: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3e28) {
            ctx->pc = 0x1A3E4Cu;
            goto label_1a3e4c;
        }
    }
    ctx->pc = 0x1A3E30u;
    // 0x1a3e30: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A3E30u;
    {
        const bool branch_taken_0x1a3e30 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a3e30) {
            ctx->pc = 0x1A3E4Cu;
            goto label_1a3e4c;
        }
    }
    ctx->pc = 0x1A3E38u;
    // 0x1a3e38: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1a3e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a3e3c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3E3Cu;
    {
        const bool branch_taken_0x1a3e3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a3e3c) {
            ctx->pc = 0x1A3E4Cu;
            goto label_1a3e4c;
        }
    }
    ctx->pc = 0x1A3E44u;
    // 0x1a3e44: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A3E44u;
    {
        const bool branch_taken_0x1a3e44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E44u;
            // 0x1a3e48: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3e44) {
            ctx->pc = 0x1A3E70u;
            goto label_1a3e70;
        }
    }
    ctx->pc = 0x1A3E4Cu;
label_1a3e4c:
    // 0x1a3e4c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a3e4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a3e50:
    // 0x1a3e50: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A3E50u;
    {
        const bool branch_taken_0x1a3e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E50u;
            // 0x1a3e54: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3e50) {
            ctx->pc = 0x1A3E74u;
            goto label_1a3e74;
        }
    }
    ctx->pc = 0x1A3E58u;
label_1a3e58:
    // 0x1a3e58: 0xc068d2c  jal         func_1A34B0
    ctx->pc = 0x1A3E58u;
    SET_GPR_U32(ctx, 31, 0x1A3E60u);
    ctx->pc = 0x1A3E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E58u;
            // 0x1a3e5c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A34B0u;
    if (runtime->hasFunction(0x1A34B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A34B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3E60u; }
        if (ctx->pc != 0x1A3E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A34B0_0x1a34b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3E60u; }
        if (ctx->pc != 0x1A3E60u) { return; }
    }
    ctx->pc = 0x1A3E60u;
label_1a3e60:
    // 0x1a3e60: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a3e60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3e64: 0xa6620020  sh          $v0, 0x20($s3)
    ctx->pc = 0x1a3e64u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 32), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a3e68: 0xc068fa4  jal         func_1A3E90
    ctx->pc = 0x1A3E68u;
    SET_GPR_U32(ctx, 31, 0x1A3E70u);
    ctx->pc = 0x1A3E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E68u;
            // 0x1a3e6c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3E90u;
    if (runtime->hasFunction(0x1A3E90u)) {
        auto targetFn = runtime->lookupFunction(0x1A3E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3E70u; }
        if (ctx->pc != 0x1A3E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3E90_0x1a3e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3E70u; }
        if (ctx->pc != 0x1A3E70u) { return; }
    }
    ctx->pc = 0x1A3E70u;
label_1a3e70:
    // 0x1a3e70: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a3e70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1a3e74:
    // 0x1a3e74: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a3e74u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a3e78: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a3e78u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a3e7c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a3e7cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a3e80: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a3e80u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3e84: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3E84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3E84u;
            // 0x1a3e88: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3DBCu: goto label_1a3dbc;
            case 0x1A3DC8u: goto label_1a3dc8;
            case 0x1A3DD8u: goto label_1a3dd8;
            case 0x1A3DF0u: goto label_1a3df0;
            case 0x1A3DF8u: goto label_1a3df8;
            case 0x1A3E08u: goto label_1a3e08;
            case 0x1A3E4Cu: goto label_1a3e4c;
            case 0x1A3E50u: goto label_1a3e50;
            case 0x1A3E58u: goto label_1a3e58;
            case 0x1A3E60u: goto label_1a3e60;
            case 0x1A3E70u: goto label_1a3e70;
            case 0x1A3E74u: goto label_1a3e74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3E8Cu;
    // 0x1a3e8c: 0x0  nop
    ctx->pc = 0x1a3e8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
