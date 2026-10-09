#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3B90
// Address: 0x1d3b90 - 0x1d3dc0
void sub_001D3B90_0x1d3b90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3B90_0x1d3b90");
#endif

    switch (ctx->pc) {
        case 0x1d3c28u: goto label_1d3c28;
        case 0x1d3c3cu: goto label_1d3c3c;
        case 0x1d3c50u: goto label_1d3c50;
        case 0x1d3c68u: goto label_1d3c68;
        case 0x1d3c78u: goto label_1d3c78;
        case 0x1d3c90u: goto label_1d3c90;
        case 0x1d3cc4u: goto label_1d3cc4;
        case 0x1d3cd4u: goto label_1d3cd4;
        case 0x1d3d20u: goto label_1d3d20;
        case 0x1d3d2cu: goto label_1d3d2c;
        case 0x1d3d64u: goto label_1d3d64;
        case 0x1d3d6cu: goto label_1d3d6c;
        case 0x1d3d74u: goto label_1d3d74;
        case 0x1d3da4u: goto label_1d3da4;
        default: break;
    }

    ctx->pc = 0x1d3b90u;

    // 0x1d3b90: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d3b90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d3b94: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d3b94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3b98: 0x8074f70  j           func_1D3DC0
    ctx->pc = 0x1D3B98u;
    ctx->pc = 0x1D3B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B98u;
            // 0x1d3b9c: 0x24846658  addiu       $a0, $a0, 0x6658 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D3BA0u;
    // 0x1d3ba0: 0x8074ef8  j           func_1D3BE0
    ctx->pc = 0x1D3BA0u;
    ctx->pc = 0x1D3BA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3BA0u;
            // 0x1d3ba4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3BE0u;
    goto label_1d3be0;
    ctx->pc = 0x1D3BA8u;
    // 0x1d3ba8: 0x0  nop
    ctx->pc = 0x1d3ba8u;
    // NOP
    // 0x1d3bac: 0x0  nop
    ctx->pc = 0x1d3bacu;
    // NOP
    // 0x1d3bb0: 0x8074ef8  j           func_1D3BE0
    ctx->pc = 0x1D3BB0u;
    ctx->pc = 0x1D3BB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3BB0u;
            // 0x1d3bb4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3BE0u;
    goto label_1d3be0;
    ctx->pc = 0x1D3BB8u;
    // 0x1d3bb8: 0x0  nop
    ctx->pc = 0x1d3bb8u;
    // NOP
    // 0x1d3bbc: 0x0  nop
    ctx->pc = 0x1d3bbcu;
    // NOP
    // 0x1d3bc0: 0x8074ef8  j           func_1D3BE0
    ctx->pc = 0x1D3BC0u;
    ctx->pc = 0x1D3BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3BC0u;
            // 0x1d3bc4: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3BE0u;
    goto label_1d3be0;
    ctx->pc = 0x1D3BC8u;
    // 0x1d3bc8: 0x0  nop
    ctx->pc = 0x1d3bc8u;
    // NOP
    // 0x1d3bcc: 0x0  nop
    ctx->pc = 0x1d3bccu;
    // NOP
    // 0x1d3bd0: 0x8074ef8  j           func_1D3BE0
    ctx->pc = 0x1D3BD0u;
    ctx->pc = 0x1D3BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3BD0u;
            // 0x1d3bd4: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3BE0u;
    goto label_1d3be0;
    ctx->pc = 0x1D3BD8u;
    // 0x1d3bd8: 0x0  nop
    ctx->pc = 0x1d3bd8u;
    // NOP
    // 0x1d3bdc: 0x0  nop
    ctx->pc = 0x1d3bdcu;
    // NOP
label_1d3be0:
    // 0x1d3be0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d3be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d3be4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d3be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d3be8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d3be8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d3bec: 0x1082001a  beq         $a0, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1D3BECu;
    {
        const bool branch_taken_0x1d3bec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D3BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3BECu;
            // 0x1d3bf0: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3bec) {
            ctx->pc = 0x1D3C58u;
            goto label_1d3c58;
        }
    }
    ctx->pc = 0x1D3BF4u;
    // 0x1d3bf4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d3bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d3bf8: 0x10820012  beq         $a0, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D3BF8u;
    {
        const bool branch_taken_0x1d3bf8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D3BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3BF8u;
            // 0x1d3bfc: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3bf8) {
            ctx->pc = 0x1D3C44u;
            goto label_1d3c44;
        }
    }
    ctx->pc = 0x1D3C00u;
    // 0x1d3c00: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d3c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3c04: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D3C04u;
    {
        const bool branch_taken_0x1d3c04 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D3C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C04u;
            // 0x1d3c08: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3c04) {
            ctx->pc = 0x1D3C30u;
            goto label_1d3c30;
        }
    }
    ctx->pc = 0x1D3C0Cu;
    // 0x1d3c0c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D3C0Cu;
    {
        const bool branch_taken_0x1d3c0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C0Cu;
            // 0x1d3c10: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3c0c) {
            ctx->pc = 0x1D3C1Cu;
            goto label_1d3c1c;
        }
    }
    ctx->pc = 0x1D3C14u;
    // 0x1d3c14: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1D3C14u;
    {
        const bool branch_taken_0x1d3c14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C14u;
            // 0x1d3c18: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3c14) {
            ctx->pc = 0x1D3C70u;
            goto label_1d3c70;
        }
    }
    ctx->pc = 0x1D3C1Cu;
label_1d3c1c:
    // 0x1d3c1c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3c1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3c20: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3C20u;
    SET_GPR_U32(ctx, 31, 0x1D3C28u);
    ctx->pc = 0x1D3C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C20u;
            // 0x1d3c24: 0x24a56660  addiu       $a1, $a1, 0x6660 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C28u; }
        if (ctx->pc != 0x1D3C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C28u; }
        if (ctx->pc != 0x1D3C28u) { return; }
    }
    ctx->pc = 0x1D3C28u;
label_1d3c28:
    // 0x1d3c28: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D3C28u;
    {
        const bool branch_taken_0x1d3c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C28u;
            // 0x1d3c2c: 0x24102000  addiu       $s0, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3c28) {
            ctx->pc = 0x1D3C6Cu;
            goto label_1d3c6c;
        }
    }
    ctx->pc = 0x1D3C30u;
label_1d3c30:
    // 0x1d3c30: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3c30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3c34: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3C34u;
    SET_GPR_U32(ctx, 31, 0x1D3C3Cu);
    ctx->pc = 0x1D3C38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C34u;
            // 0x1d3c38: 0x24a56668  addiu       $a1, $a1, 0x6668 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C3Cu; }
        if (ctx->pc != 0x1D3C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C3Cu; }
        if (ctx->pc != 0x1D3C3Cu) { return; }
    }
    ctx->pc = 0x1D3C3Cu;
label_1d3c3c:
    // 0x1d3c3c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D3C3Cu;
    {
        const bool branch_taken_0x1d3c3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C3Cu;
            // 0x1d3c40: 0x24102500  addiu       $s0, $zero, 0x2500 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 9472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3c3c) {
            ctx->pc = 0x1D3C6Cu;
            goto label_1d3c6c;
        }
    }
    ctx->pc = 0x1D3C44u;
label_1d3c44:
    // 0x1d3c44: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3c48: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3C48u;
    SET_GPR_U32(ctx, 31, 0x1D3C50u);
    ctx->pc = 0x1D3C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C48u;
            // 0x1d3c4c: 0x24a56678  addiu       $a1, $a1, 0x6678 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26232));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C50u; }
        if (ctx->pc != 0x1D3C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C50u; }
        if (ctx->pc != 0x1D3C50u) { return; }
    }
    ctx->pc = 0x1D3C50u;
label_1d3c50:
    // 0x1d3c50: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D3C50u;
    {
        const bool branch_taken_0x1d3c50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3C54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C50u;
            // 0x1d3c54: 0x24102500  addiu       $s0, $zero, 0x2500 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 9472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3c50) {
            ctx->pc = 0x1D3C6Cu;
            goto label_1d3c6c;
        }
    }
    ctx->pc = 0x1D3C58u;
label_1d3c58:
    // 0x1d3c58: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3c58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3c5c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3c5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3c60: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3C60u;
    SET_GPR_U32(ctx, 31, 0x1D3C68u);
    ctx->pc = 0x1D3C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C60u;
            // 0x1d3c64: 0x24a56680  addiu       $a1, $a1, 0x6680 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C68u; }
        if (ctx->pc != 0x1D3C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C68u; }
        if (ctx->pc != 0x1D3C68u) { return; }
    }
    ctx->pc = 0x1D3C68u;
label_1d3c68:
    // 0x1d3c68: 0x24102500  addiu       $s0, $zero, 0x2500
    ctx->pc = 0x1d3c68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 9472));
label_1d3c6c:
    // 0x1d3c6c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_1d3c70:
    // 0x1d3c70: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3C70u;
    SET_GPR_U32(ctx, 31, 0x1D3C78u);
    ctx->pc = 0x1D3C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C70u;
            // 0x1d3c74: 0x2405000c  addiu       $a1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C78u; }
        if (ctx->pc != 0x1D3C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C78u; }
        if (ctx->pc != 0x1D3C78u) { return; }
    }
    ctx->pc = 0x1D3C78u;
label_1d3c78:
    // 0x1d3c78: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d3c78u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3c7c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d3c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3c80: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d3c80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d3c84: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d3c84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3c88: 0xc06b3e0  jal         func_1ACF80
    ctx->pc = 0x1D3C88u;
    SET_GPR_U32(ctx, 31, 0x1D3C90u);
    ctx->pc = 0x1D3C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C88u;
            // 0x1d3c8c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF80u;
    if (runtime->hasFunction(0x1ACF80u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C90u; }
        if (ctx->pc != 0x1D3C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF80_0x1acf80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3C90u; }
        if (ctx->pc != 0x1D3C90u) { return; }
    }
    ctx->pc = 0x1D3C90u;
label_1d3c90:
    // 0x1d3c90: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d3c90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3c94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3c94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3c98: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3C98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3C98u;
            // 0x1d3c9c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3BE0u: goto label_1d3be0;
            case 0x1D3C1Cu: goto label_1d3c1c;
            case 0x1D3C28u: goto label_1d3c28;
            case 0x1D3C30u: goto label_1d3c30;
            case 0x1D3C3Cu: goto label_1d3c3c;
            case 0x1D3C44u: goto label_1d3c44;
            case 0x1D3C50u: goto label_1d3c50;
            case 0x1D3C58u: goto label_1d3c58;
            case 0x1D3C68u: goto label_1d3c68;
            case 0x1D3C6Cu: goto label_1d3c6c;
            case 0x1D3C70u: goto label_1d3c70;
            case 0x1D3C78u: goto label_1d3c78;
            case 0x1D3C90u: goto label_1d3c90;
            case 0x1D3CC4u: goto label_1d3cc4;
            case 0x1D3CD4u: goto label_1d3cd4;
            case 0x1D3D20u: goto label_1d3d20;
            case 0x1D3D2Cu: goto label_1d3d2c;
            case 0x1D3D64u: goto label_1d3d64;
            case 0x1D3D6Cu: goto label_1d3d6c;
            case 0x1D3D74u: goto label_1d3d74;
            case 0x1D3DA4u: goto label_1d3da4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3CA0u;
    // 0x1d3ca0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d3ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d3ca4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3ca4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3ca8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d3ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d3cac: 0x24a56688  addiu       $a1, $a1, 0x6688
    ctx->pc = 0x1d3cacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26248));
    // 0x1d3cb0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3cb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3cb4: 0x90860b98  lbu         $a2, 0xB98($a0)
    ctx->pc = 0x1d3cb4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2968)));
    // 0x1d3cb8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d3cb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3cbc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3CBCu;
    SET_GPR_U32(ctx, 31, 0x1D3CC4u);
    ctx->pc = 0x1D3CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CBCu;
            // 0x1d3cc0: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CC4u; }
        if (ctx->pc != 0x1D3CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CC4u; }
        if (ctx->pc != 0x1D3CC4u) { return; }
    }
    ctx->pc = 0x1D3CC4u;
label_1d3cc4:
    // 0x1d3cc4: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1d3cc4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1d3cc8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3cc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3ccc: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3CCCu;
    SET_GPR_U32(ctx, 31, 0x1D3CD4u);
    ctx->pc = 0x1D3CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CCCu;
            // 0x1d3cd0: 0x24450004  addiu       $a1, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CD4u; }
        if (ctx->pc != 0x1D3CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CD4u; }
        if (ctx->pc != 0x1D3CD4u) { return; }
    }
    ctx->pc = 0x1D3CD4u;
label_1d3cd4:
    // 0x1d3cd4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d3cd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3cd8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3cd8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3cdc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3CDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CDCu;
            // 0x1d3ce0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3BE0u: goto label_1d3be0;
            case 0x1D3C1Cu: goto label_1d3c1c;
            case 0x1D3C28u: goto label_1d3c28;
            case 0x1D3C30u: goto label_1d3c30;
            case 0x1D3C3Cu: goto label_1d3c3c;
            case 0x1D3C44u: goto label_1d3c44;
            case 0x1D3C50u: goto label_1d3c50;
            case 0x1D3C58u: goto label_1d3c58;
            case 0x1D3C68u: goto label_1d3c68;
            case 0x1D3C6Cu: goto label_1d3c6c;
            case 0x1D3C70u: goto label_1d3c70;
            case 0x1D3C78u: goto label_1d3c78;
            case 0x1D3C90u: goto label_1d3c90;
            case 0x1D3CC4u: goto label_1d3cc4;
            case 0x1D3CD4u: goto label_1d3cd4;
            case 0x1D3D20u: goto label_1d3d20;
            case 0x1D3D2Cu: goto label_1d3d2c;
            case 0x1D3D64u: goto label_1d3d64;
            case 0x1D3D6Cu: goto label_1d3d6c;
            case 0x1D3D74u: goto label_1d3d74;
            case 0x1D3DA4u: goto label_1d3da4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3CE4u;
    // 0x1d3ce4: 0x0  nop
    ctx->pc = 0x1d3ce4u;
    // NOP
    // 0x1d3ce8: 0x0  nop
    ctx->pc = 0x1d3ce8u;
    // NOP
    // 0x1d3cec: 0x0  nop
    ctx->pc = 0x1d3cecu;
    // NOP
    // 0x1d3cf0: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d3cf0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d3cf4: 0x2405000d  addiu       $a1, $zero, 0xD
    ctx->pc = 0x1d3cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d3cf8: 0x8074f70  j           func_1D3DC0
    ctx->pc = 0x1D3CF8u;
    ctx->pc = 0x1D3CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CF8u;
            // 0x1d3cfc: 0x24846698  addiu       $a0, $a0, 0x6698 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D3D00u;
    // 0x1d3d00: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d3d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d3d04: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3d04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3d08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d3d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d3d0c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3d0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3d10: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d3d10u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d3d14: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d3d14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d3d18: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3D18u;
    SET_GPR_U32(ctx, 31, 0x1D3D20u);
    ctx->pc = 0x1D3D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D18u;
            // 0x1d3d1c: 0x24a566a8  addiu       $a1, $a1, 0x66A8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D20u; }
        if (ctx->pc != 0x1D3D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D20u; }
        if (ctx->pc != 0x1D3D20u) { return; }
    }
    ctx->pc = 0x1D3D20u;
label_1d3d20:
    // 0x1d3d20: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d3d20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d3d24: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3D24u;
    SET_GPR_U32(ctx, 31, 0x1D3D2Cu);
    ctx->pc = 0x1D3D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D24u;
            // 0x1d3d28: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D2Cu; }
        if (ctx->pc != 0x1D3D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D2Cu; }
        if (ctx->pc != 0x1D3D2Cu) { return; }
    }
    ctx->pc = 0x1D3D2Cu;
label_1d3d2c:
    // 0x1d3d2c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d3d2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3d30: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3D30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D30u;
            // 0x1d3d34: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3BE0u: goto label_1d3be0;
            case 0x1D3C1Cu: goto label_1d3c1c;
            case 0x1D3C28u: goto label_1d3c28;
            case 0x1D3C30u: goto label_1d3c30;
            case 0x1D3C3Cu: goto label_1d3c3c;
            case 0x1D3C44u: goto label_1d3c44;
            case 0x1D3C50u: goto label_1d3c50;
            case 0x1D3C58u: goto label_1d3c58;
            case 0x1D3C68u: goto label_1d3c68;
            case 0x1D3C6Cu: goto label_1d3c6c;
            case 0x1D3C70u: goto label_1d3c70;
            case 0x1D3C78u: goto label_1d3c78;
            case 0x1D3C90u: goto label_1d3c90;
            case 0x1D3CC4u: goto label_1d3cc4;
            case 0x1D3CD4u: goto label_1d3cd4;
            case 0x1D3D20u: goto label_1d3d20;
            case 0x1D3D2Cu: goto label_1d3d2c;
            case 0x1D3D64u: goto label_1d3d64;
            case 0x1D3D6Cu: goto label_1d3d6c;
            case 0x1D3D74u: goto label_1d3d74;
            case 0x1D3DA4u: goto label_1d3da4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3D38u;
    // 0x1d3d38: 0x0  nop
    ctx->pc = 0x1d3d38u;
    // NOP
    // 0x1d3d3c: 0x0  nop
    ctx->pc = 0x1d3d3cu;
    // NOP
    // 0x1d3d40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d3d40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d3d44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3d48: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3d4c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3d4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3d50: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3d50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3d54: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3d54u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3d58: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d3d58u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3d5c: 0xc06b3a8  jal         func_1ACEA0
    ctx->pc = 0x1D3D5Cu;
    SET_GPR_U32(ctx, 31, 0x1D3D64u);
    ctx->pc = 0x1D3D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D5Cu;
            // 0x1d3d60: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACEA0u;
    if (runtime->hasFunction(0x1ACEA0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D64u; }
        if (ctx->pc != 0x1D3D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACEA0_0x1acea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D64u; }
        if (ctx->pc != 0x1D3D64u) { return; }
    }
    ctx->pc = 0x1D3D64u;
label_1d3d64:
    // 0x1d3d64: 0xc06e0d8  jal         func_1B8360
    ctx->pc = 0x1D3D64u;
    SET_GPR_U32(ctx, 31, 0x1D3D6Cu);
    ctx->pc = 0x1B8360u;
    if (runtime->hasFunction(0x1B8360u)) {
        auto targetFn = runtime->lookupFunction(0x1B8360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D6Cu; }
        if (ctx->pc != 0x1D3D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8360_0x1b8360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D6Cu; }
        if (ctx->pc != 0x1D3D6Cu) { return; }
    }
    ctx->pc = 0x1D3D6Cu;
label_1d3d6c:
    // 0x1d3d6c: 0xc06e0e0  jal         func_1B8380
    ctx->pc = 0x1D3D6Cu;
    SET_GPR_U32(ctx, 31, 0x1D3D74u);
    ctx->pc = 0x1D3D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D6Cu;
            // 0x1d3d70: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8380u;
    if (runtime->hasFunction(0x1B8380u)) {
        auto targetFn = runtime->lookupFunction(0x1B8380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D74u; }
        if (ctx->pc != 0x1D3D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8380_0x1b8380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D74u; }
        if (ctx->pc != 0x1D3D74u) { return; }
    }
    ctx->pc = 0x1D3D74u;
label_1d3d74:
    // 0x1d3d74: 0x2182b  sltu        $v1, $zero, $v0
    ctx->pc = 0x1d3d74u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d3d78: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1d3d78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1d3d7c: 0x0  nop
    ctx->pc = 0x1d3d7cu;
    // NOP
    // 0x1d3d80: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D3D80u;
    {
        const bool branch_taken_0x1d3d80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d3d80) {
            ctx->pc = 0x1D3D6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3d6c;
        }
    }
    ctx->pc = 0x1D3D88u;
    // 0x1d3d88: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D3D88u;
    {
        const bool branch_taken_0x1d3d88 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1D3D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D88u;
            // 0x1d3d8c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3d88) {
            ctx->pc = 0x1D3DA4u;
            goto label_1d3da4;
        }
    }
    ctx->pc = 0x1D3D90u;
    // 0x1d3d90: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d3d90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3d94: 0x8c22440c  lw          $v0, 0x440C($at)
    ctx->pc = 0x1d3d94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3d98: 0x2406000c  addiu       $a2, $zero, 0xC
    ctx->pc = 0x1d3d98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d3d9c: 0xc06b454  jal         func_1AD150
    ctx->pc = 0x1D3D9Cu;
    SET_GPR_U32(ctx, 31, 0x1D3DA4u);
    ctx->pc = 0x1D3DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D9Cu;
            // 0x1d3da0: 0x24454000  addiu       $a1, $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 16384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD150u;
    if (runtime->hasFunction(0x1AD150u)) {
        auto targetFn = runtime->lookupFunction(0x1AD150u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3DA4u; }
        if (ctx->pc != 0x1D3DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD150_0x1ad150(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3DA4u; }
        if (ctx->pc != 0x1D3DA4u) { return; }
    }
    ctx->pc = 0x1D3DA4u;
label_1d3da4:
    // 0x1d3da4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d3da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3da8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3da8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3dac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3dacu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3db0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3DB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3DB0u;
            // 0x1d3db4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3BE0u: goto label_1d3be0;
            case 0x1D3C1Cu: goto label_1d3c1c;
            case 0x1D3C28u: goto label_1d3c28;
            case 0x1D3C30u: goto label_1d3c30;
            case 0x1D3C3Cu: goto label_1d3c3c;
            case 0x1D3C44u: goto label_1d3c44;
            case 0x1D3C50u: goto label_1d3c50;
            case 0x1D3C58u: goto label_1d3c58;
            case 0x1D3C68u: goto label_1d3c68;
            case 0x1D3C6Cu: goto label_1d3c6c;
            case 0x1D3C70u: goto label_1d3c70;
            case 0x1D3C78u: goto label_1d3c78;
            case 0x1D3C90u: goto label_1d3c90;
            case 0x1D3CC4u: goto label_1d3cc4;
            case 0x1D3CD4u: goto label_1d3cd4;
            case 0x1D3D20u: goto label_1d3d20;
            case 0x1D3D2Cu: goto label_1d3d2c;
            case 0x1D3D64u: goto label_1d3d64;
            case 0x1D3D6Cu: goto label_1d3d6c;
            case 0x1D3D74u: goto label_1d3d74;
            case 0x1D3DA4u: goto label_1d3da4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3DB8u;
    // 0x1d3db8: 0x0  nop
    ctx->pc = 0x1d3db8u;
    // NOP
    // 0x1d3dbc: 0x0  nop
    ctx->pc = 0x1d3dbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
