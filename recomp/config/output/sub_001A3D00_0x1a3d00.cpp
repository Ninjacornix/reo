#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3D00
// Address: 0x1a3d00 - 0x1a3d90
void sub_001A3D00_0x1a3d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3D00_0x1a3d00");
#endif

    switch (ctx->pc) {
        case 0x1a3d1cu: goto label_1a3d1c;
        case 0x1a3d38u: goto label_1a3d38;
        default: break;
    }

    ctx->pc = 0x1a3d00u;

    // 0x1a3d00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3d04: 0xa0482d  daddu       $t1, $a1, $zero
    ctx->pc = 0x1a3d04u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3d08: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1a3d08u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3d0c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3d10: 0x3c05000c  lui         $a1, 0xC
    ctx->pc = 0x1a3d10u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)12 << 16));
    // 0x1a3d14: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3D14u;
    SET_GPR_U32(ctx, 31, 0x1A3D1Cu);
    ctx->pc = 0x1A3D18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3D14u;
            // 0x1a3d18: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3D1Cu; }
        if (ctx->pc != 0x1A3D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3D1Cu; }
        if (ctx->pc != 0x1A3D1Cu) { return; }
    }
    ctx->pc = 0x1A3D1Cu;
label_1a3d1c:
    // 0x1a3d1c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3D1Cu;
    {
        const bool branch_taken_0x1a3d1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3d1c) {
            ctx->pc = 0x1A3D2Cu;
            goto label_1a3d2c;
        }
    }
    ctx->pc = 0x1A3D24u;
    // 0x1a3d24: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1A3D24u;
    {
        const bool branch_taken_0x1a3d24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3D24u;
            // 0x1a3d28: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3d24) {
            ctx->pc = 0x1A3D78u;
            goto label_1a3d78;
        }
    }
    ctx->pc = 0x1A3D2Cu;
label_1a3d2c:
    // 0x1a3d2c: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a3d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1a3d30: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A3D30u;
    {
        const bool branch_taken_0x1a3d30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3D30u;
            // 0x1a3d34: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3d30) {
            ctx->pc = 0x1A3D4Cu;
            goto label_1a3d4c;
        }
    }
    ctx->pc = 0x1A3D38u;
label_1a3d38:
    // 0x1a3d38: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1a3d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a3d3c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a3d3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a3d40: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a3d40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a3d44: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1a3d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1a3d48: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a3d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1a3d4c:
    // 0x1a3d4c: 0x89182a  slt         $v1, $a0, $t1
    ctx->pc = 0x1a3d4cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1a3d50: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A3D50u;
    {
        const bool branch_taken_0x1a3d50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3d50) {
            ctx->pc = 0x1A3D38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3d38;
        }
    }
    ctx->pc = 0x1A3D58u;
    // 0x1a3d58: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1a3d58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a3d5c: 0x103182a  slt         $v1, $t0, $v1
    ctx->pc = 0x1a3d5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a3d60: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3D60u;
    {
        const bool branch_taken_0x1a3d60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3D60u;
            // 0x1a3d64: 0x818c0  sll         $v1, $t0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3d60) {
            ctx->pc = 0x1A3D70u;
            goto label_1a3d70;
        }
    }
    ctx->pc = 0x1A3D68u;
    // 0x1a3d68: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3D68u;
    {
        const bool branch_taken_0x1a3d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3D68u;
            // 0x1a3d6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3d68) {
            ctx->pc = 0x1A3D78u;
            goto label_1a3d78;
        }
    }
    ctx->pc = 0x1A3D70u;
label_1a3d70:
    // 0x1a3d70: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1a3d70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1a3d74: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a3d74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1a3d78:
    // 0x1a3d78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3d78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3d7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3D7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3D7Cu;
            // 0x1a3d80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3D1Cu: goto label_1a3d1c;
            case 0x1A3D2Cu: goto label_1a3d2c;
            case 0x1A3D38u: goto label_1a3d38;
            case 0x1A3D4Cu: goto label_1a3d4c;
            case 0x1A3D70u: goto label_1a3d70;
            case 0x1A3D78u: goto label_1a3d78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3D84u;
    // 0x1a3d84: 0x0  nop
    ctx->pc = 0x1a3d84u;
    // NOP
    // 0x1a3d88: 0x0  nop
    ctx->pc = 0x1a3d88u;
    // NOP
    // 0x1a3d8c: 0x0  nop
    ctx->pc = 0x1a3d8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
