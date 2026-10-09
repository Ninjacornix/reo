#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3930
// Address: 0x1a3930 - 0x1a39e0
void sub_001A3930_0x1a3930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3930_0x1a3930");
#endif

    switch (ctx->pc) {
        case 0x1a3948u: goto label_1a3948;
        case 0x1a3968u: goto label_1a3968;
        case 0x1a3980u: goto label_1a3980;
        case 0x1a39a8u: goto label_1a39a8;
        default: break;
    }

    ctx->pc = 0x1a3930u;

    // 0x1a3930: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3934: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x1a3934u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3938: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a393c: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1a393cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3940: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A3940u;
    SET_GPR_U32(ctx, 31, 0x1A3948u);
    ctx->pc = 0x1A3944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3940u;
            // 0x1a3944: 0x80582d  daddu       $t3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3948u; }
        if (ctx->pc != 0x1A3948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3948u; }
        if (ctx->pc != 0x1A3948u) { return; }
    }
    ctx->pc = 0x1A3948u;
label_1a3948:
    // 0x1a3948: 0x4a082a  slt         $at, $v0, $t2
    ctx->pc = 0x1a3948u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a394c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A394Cu;
    {
        const bool branch_taken_0x1a394c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A394Cu;
            // 0x1a3950: 0x160202d  daddu       $a0, $t3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a394c) {
            ctx->pc = 0x1A395Cu;
            goto label_1a395c;
        }
    }
    ctx->pc = 0x1A3954u;
    // 0x1a3954: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1A3954u;
    {
        const bool branch_taken_0x1a3954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3954u;
            // 0x1a3958: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3954) {
            ctx->pc = 0x1A39D0u;
            goto label_1a39d0;
        }
    }
    ctx->pc = 0x1A395Cu;
label_1a395c:
    // 0x1a395c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a395cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a3960: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3960u;
    SET_GPR_U32(ctx, 31, 0x1A3968u);
    ctx->pc = 0x1A3964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3960u;
            // 0x1a3964: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3968u; }
        if (ctx->pc != 0x1A3968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3968u; }
        if (ctx->pc != 0x1A3968u) { return; }
    }
    ctx->pc = 0x1A3968u;
label_1a3968:
    // 0x1a3968: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3968u;
    {
        const bool branch_taken_0x1a3968 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A396Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3968u;
            // 0x1a396c: 0x2444000c  addiu       $a0, $v0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3968) {
            ctx->pc = 0x1A3978u;
            goto label_1a3978;
        }
    }
    ctx->pc = 0x1A3970u;
    // 0x1a3970: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1A3970u;
    {
        const bool branch_taken_0x1a3970 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3970u;
            // 0x1a3974: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3970) {
            ctx->pc = 0x1A39D0u;
            goto label_1a39d0;
        }
    }
    ctx->pc = 0x1A3978u;
label_1a3978:
    // 0x1a3978: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3978u;
    {
        const bool branch_taken_0x1a3978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A397Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3978u;
            // 0x1a397c: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3978) {
            ctx->pc = 0x1A398Cu;
            goto label_1a398c;
        }
    }
    ctx->pc = 0x1A3980u;
label_1a3980:
    // 0x1a3980: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a3980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a3984: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a3984u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a3988: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3988u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a398c:
    // 0x1a398c: 0x6a102a  slt         $v0, $v1, $t2
    ctx->pc = 0x1a398cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1a3990: 0x0  nop
    ctx->pc = 0x1a3990u;
    // NOP
    // 0x1a3994: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A3994u;
    {
        const bool branch_taken_0x1a3994 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3994) {
            ctx->pc = 0x1A3980u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3980;
        }
    }
    ctx->pc = 0x1A399Cu;
    // 0x1a399c: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1a399cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a39a0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A39A0u;
    {
        const bool branch_taken_0x1a39a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A39A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A39A0u;
            // 0x1a39a4: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a39a0) {
            ctx->pc = 0x1A39C4u;
            goto label_1a39c4;
        }
    }
    ctx->pc = 0x1A39A8u;
label_1a39a8:
    // 0x1a39a8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a39a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a39ac: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a39acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a39b0: 0x2407c  dsll32      $t0, $v0, 1
    ctx->pc = 0x1a39b0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) << (32 + 1));
    // 0x1a39b4: 0x8407e  dsrl32      $t0, $t0, 1
    ctx->pc = 0x1a39b4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) >> (32 + 1));
    // 0x1a39b8: 0x81080  sll         $v0, $t0, 2
    ctx->pc = 0x1a39b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1a39bc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1a39bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1a39c0: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a39c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a39c4:
    // 0x1a39c4: 0x123082a  slt         $at, $t1, $v1
    ctx->pc = 0x1a39c4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a39c8: 0x1020fff7  beqz        $at, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A39C8u;
    {
        const bool branch_taken_0x1a39c8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A39CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A39C8u;
            // 0x1a39cc: 0x100102d  daddu       $v0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a39c8) {
            ctx->pc = 0x1A39A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a39a8;
        }
    }
    ctx->pc = 0x1A39D0u;
label_1a39d0:
    // 0x1a39d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a39d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a39d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A39D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A39D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A39D4u;
            // 0x1a39d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3948u: goto label_1a3948;
            case 0x1A395Cu: goto label_1a395c;
            case 0x1A3968u: goto label_1a3968;
            case 0x1A3978u: goto label_1a3978;
            case 0x1A3980u: goto label_1a3980;
            case 0x1A398Cu: goto label_1a398c;
            case 0x1A39A8u: goto label_1a39a8;
            case 0x1A39C4u: goto label_1a39c4;
            case 0x1A39D0u: goto label_1a39d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A39DCu;
    // 0x1a39dc: 0x0  nop
    ctx->pc = 0x1a39dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
