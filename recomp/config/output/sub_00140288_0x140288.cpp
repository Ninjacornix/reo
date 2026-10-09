#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140288
// Address: 0x140288 - 0x1402fc
void sub_00140288_0x140288(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140288_0x140288");
#endif

    switch (ctx->pc) {
        case 0x1402b0u: goto label_1402b0;
        case 0x1402d0u: goto label_1402d0;
        default: break;
    }

    ctx->pc = 0x140288u;

    // 0x140288: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14028c: 0x2ca20004  sltiu       $v0, $a1, 0x4
    ctx->pc = 0x14028cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x140290: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140290u;
    {
        const bool branch_taken_0x140290 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x140294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140290u;
            // 0x140294: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140290) {
            ctx->pc = 0x1402B8u;
            goto label_1402b8;
        }
    }
    ctx->pc = 0x140298u;
    // 0x140298: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x140298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x14029c: 0x50400014  beql        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x14029Cu;
    {
        const bool branch_taken_0x14029c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14029c) {
            ctx->pc = 0x1402A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14029Cu;
            // 0x1402a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1402F0u;
            goto label_1402f0;
        }
    }
    ctx->pc = 0x1402A4u;
    // 0x1402a4: 0x8c84002c  lw          $a0, 0x2C($a0)
    ctx->pc = 0x1402a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1402a8: 0x40f809  jalr        $v0
    ctx->pc = 0x1402A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1402B0u);
        ctx->pc = 0x1402ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402A8u;
            // 0x1402ac: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1402B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1402B0u; }
            if (ctx->pc != 0x1402B0u) { return; }
        }
        }
    }
    ctx->pc = 0x1402B0u;
label_1402b0:
    // 0x1402b0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1402B0u;
    {
        const bool branch_taken_0x1402b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1402B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402B0u;
            // 0x1402b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1402b0) {
            ctx->pc = 0x1402F0u;
            goto label_1402f0;
        }
    }
    ctx->pc = 0x1402B8u;
label_1402b8:
    // 0x1402b8: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1402b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1402bc: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1402bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1402c0: 0x8c440018  lw          $a0, 0x18($v0)
    ctx->pc = 0x1402c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1402c4: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1402C4u;
    {
        const bool branch_taken_0x1402c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1402C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402C4u;
            // 0x1402c8: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1402c4) {
            ctx->pc = 0x1402ECu;
            goto label_1402ec;
        }
    }
    ctx->pc = 0x1402CCu;
    // 0x1402cc: 0x0  nop
    ctx->pc = 0x1402ccu;
    // NOP
label_1402d0:
    // 0x1402d0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x1402d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1402d4: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1402d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1402d8: 0x0  nop
    ctx->pc = 0x1402d8u;
    // NOP
    // 0x1402dc: 0x0  nop
    ctx->pc = 0x1402dcu;
    // NOP
    // 0x1402e0: 0x0  nop
    ctx->pc = 0x1402e0u;
    // NOP
    // 0x1402e4: 0x1480fffa  bnez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1402E4u;
    {
        const bool branch_taken_0x1402e4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1402E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402E4u;
            // 0x1402e8: 0x621821  addu        $v1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1402e4) {
            ctx->pc = 0x1402D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1402d0;
        }
    }
    ctx->pc = 0x1402ECu;
label_1402ec:
    // 0x1402ec: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1402ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_1402f0:
    // 0x1402f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1402f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1402f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1402F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1402F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1402F4u;
            // 0x1402f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1402B0u: goto label_1402b0;
            case 0x1402B8u: goto label_1402b8;
            case 0x1402D0u: goto label_1402d0;
            case 0x1402ECu: goto label_1402ec;
            case 0x1402F0u: goto label_1402f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1402FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
