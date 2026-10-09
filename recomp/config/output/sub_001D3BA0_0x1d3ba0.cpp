#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3BA0
// Address: 0x1d3ba0 - 0x1d3ca0
void sub_001D3BA0_0x1d3ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3BA0_0x1d3ba0");
#endif

    switch (ctx->pc) {
        case 0x1d3c28u: goto label_1d3c28;
        case 0x1d3c3cu: goto label_1d3c3c;
        case 0x1d3c50u: goto label_1d3c50;
        case 0x1d3c68u: goto label_1d3c68;
        case 0x1d3c78u: goto label_1d3c78;
        case 0x1d3c90u: goto label_1d3c90;
        default: break;
    }

    ctx->pc = 0x1d3ba0u;

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
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3CA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
