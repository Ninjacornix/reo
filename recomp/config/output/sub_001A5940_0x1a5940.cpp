#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5940
// Address: 0x1a5940 - 0x1a5a14
void sub_001A5940_0x1a5940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5940_0x1a5940");
#endif

    switch (ctx->pc) {
        case 0x1a5958u: goto label_1a5958;
        case 0x1a5980u: goto label_1a5980;
        case 0x1a59bcu: goto label_1a59bc;
        case 0x1a59d8u: goto label_1a59d8;
        case 0x1a59ecu: goto label_1a59ec;
        default: break;
    }

    ctx->pc = 0x1a5940u;

    // 0x1a5940: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a5940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a5944: 0xc0582d  daddu       $t3, $a2, $zero
    ctx->pc = 0x1a5944u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5948: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a5948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a594c: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x1a594cu;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5950: 0xc069630  jal         func_1A58C0
    ctx->pc = 0x1A5950u;
    SET_GPR_U32(ctx, 31, 0x1A5958u);
    ctx->pc = 0x1A5954u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5950u;
            // 0x1a5954: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A58C0u;
    if (runtime->hasFunction(0x1A58C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A58C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5958u; }
        if (ctx->pc != 0x1A5958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A58C0_0x1a58c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5958u; }
        if (ctx->pc != 0x1A5958u) { return; }
    }
    ctx->pc = 0x1A5958u;
label_1a5958:
    // 0x1a5958: 0x90460011  lbu         $a2, 0x11($v0)
    ctx->pc = 0x1a5958u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 17)));
    // 0x1a595c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1a595cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5960: 0x120402d  daddu       $t0, $t1, $zero
    ctx->pc = 0x1a5960u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5964: 0x28c10002  slti        $at, $a2, 0x2
    ctx->pc = 0x1a5964u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1a5968: 0x14200012  bnez        $at, . + 4 + (0x12 << 2)
    ctx->pc = 0x1A5968u;
    {
        const bool branch_taken_0x1a5968 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A596Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5968u;
            // 0x1a596c: 0x24050030  addiu       $a1, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5968) {
            ctx->pc = 0x1A59B4u;
            goto label_1a59b4;
        }
    }
    ctx->pc = 0x1A5970u;
    // 0x1a5970: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1a5970u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5974: 0x24c7ffff  addiu       $a3, $a2, -0x1
    ctx->pc = 0x1a5974u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1a5978: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A5978u;
    {
        const bool branch_taken_0x1a5978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A597Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5978u;
            // 0x1a597c: 0x25240030  addiu       $a0, $t1, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5978) {
            ctx->pc = 0x1A5994u;
            goto label_1a5994;
        }
    }
    ctx->pc = 0x1A5980u;
label_1a5980:
    // 0x1a5980: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1a5980u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a5984: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1a5984u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1a5988: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1a5988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1a598c: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1a598cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1a5990: 0xac430010  sw          $v1, 0x10($v0)
    ctx->pc = 0x1a5990u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 3));
label_1a5994:
    // 0x1a5994: 0x147102a  slt         $v0, $t2, $a3
    ctx->pc = 0x1a5994u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1a5998: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A5998u;
    {
        const bool branch_taken_0x1a5998 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A599Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5998u;
            // 0x1a599c: 0xa1080  sll         $v0, $t2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5998) {
            ctx->pc = 0x1A5980u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5980;
        }
    }
    ctx->pc = 0x1A59A0u;
    // 0x1a59a0: 0x28c10005  slti        $at, $a2, 0x5
    ctx->pc = 0x1a59a0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1a59a4: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A59A4u;
    {
        const bool branch_taken_0x1a59a4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A59A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A59A4u;
            // 0x1a59a8: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a59a4) {
            ctx->pc = 0x1A59B0u;
            goto label_1a59b0;
        }
    }
    ctx->pc = 0x1A59ACu;
    // 0x1a59ac: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1a59acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_1a59b0:
    // 0x1a59b0: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1a59b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1a59b4:
    // 0x1a59b4: 0xc069614  jal         func_1A5850
    ctx->pc = 0x1A59B4u;
    SET_GPR_U32(ctx, 31, 0x1A59BCu);
    ctx->pc = 0x1A59B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A59B4u;
            // 0x1a59b8: 0x180202d  daddu       $a0, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5850u;
    if (runtime->hasFunction(0x1A5850u)) {
        auto targetFn = runtime->lookupFunction(0x1A5850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A59BCu; }
        if (ctx->pc != 0x1A59BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5850_0x1a5850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A59BCu; }
        if (ctx->pc != 0x1A59BCu) { return; }
    }
    ctx->pc = 0x1A59BCu;
label_1a59bc:
    // 0x1a59bc: 0x1224821  addu        $t1, $t1, $v0
    ctx->pc = 0x1a59bcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x1a59c0: 0x91020011  lbu         $v0, 0x11($t0)
    ctx->pc = 0x1a59c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 17)));
    // 0x1a59c4: 0x28410002  slti        $at, $v0, 0x2
    ctx->pc = 0x1a59c4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1a59c8: 0x1420000e  bnez        $at, . + 4 + (0xE << 2)
    ctx->pc = 0x1A59C8u;
    {
        const bool branch_taken_0x1a59c8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A59CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A59C8u;
            // 0x1a59cc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a59c8) {
            ctx->pc = 0x1A5A04u;
            goto label_1a5a04;
        }
    }
    ctx->pc = 0x1A59D0u;
    // 0x1a59d0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A59D0u;
    {
        const bool branch_taken_0x1a59d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A59D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A59D0u;
            // 0x1a59d4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a59d0) {
            ctx->pc = 0x1A59F4u;
            goto label_1a59f4;
        }
    }
    ctx->pc = 0x1A59D8u;
label_1a59d8:
    // 0x1a59d8: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1a59d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1a59dc: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1a59dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1a59e0: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1a59e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a59e4: 0xc069614  jal         func_1A5850
    ctx->pc = 0x1A59E4u;
    SET_GPR_U32(ctx, 31, 0x1A59ECu);
    ctx->pc = 0x1A59E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A59E4u;
            // 0x1a59e8: 0x180202d  daddu       $a0, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5850u;
    if (runtime->hasFunction(0x1A5850u)) {
        auto targetFn = runtime->lookupFunction(0x1A5850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A59ECu; }
        if (ctx->pc != 0x1A59ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5850_0x1a5850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A59ECu; }
        if (ctx->pc != 0x1A59ECu) { return; }
    }
    ctx->pc = 0x1A59ECu;
label_1a59ec:
    // 0x1a59ec: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x1a59ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a59f0: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a59f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1a59f4:
    // 0x1a59f4: 0xcb102a  slt         $v0, $a2, $t3
    ctx->pc = 0x1a59f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 11)) ? 1 : 0);
    // 0x1a59f8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A59F8u;
    {
        const bool branch_taken_0x1a59f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A59FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A59F8u;
            // 0x1a59fc: 0x61080  sll         $v0, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a59f8) {
            ctx->pc = 0x1A59D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a59d8;
        }
    }
    ctx->pc = 0x1A5A00u;
    // 0x1a5a00: 0x1274821  addu        $t1, $t1, $a3
    ctx->pc = 0x1a5a00u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
label_1a5a04:
    // 0x1a5a04: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a5a04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5a08: 0x120102d  daddu       $v0, $t1, $zero
    ctx->pc = 0x1a5a08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5a0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5A0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5A0Cu;
            // 0x1a5a10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5958u: goto label_1a5958;
            case 0x1A5980u: goto label_1a5980;
            case 0x1A5994u: goto label_1a5994;
            case 0x1A59B0u: goto label_1a59b0;
            case 0x1A59B4u: goto label_1a59b4;
            case 0x1A59BCu: goto label_1a59bc;
            case 0x1A59D8u: goto label_1a59d8;
            case 0x1A59ECu: goto label_1a59ec;
            case 0x1A59F4u: goto label_1a59f4;
            case 0x1A5A04u: goto label_1a5a04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5A14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
