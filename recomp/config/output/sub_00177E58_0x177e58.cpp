#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177E58
// Address: 0x177e58 - 0x177eb0
void sub_00177E58_0x177e58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177E58_0x177e58");
#endif

    switch (ctx->pc) {
        case 0x177e84u: goto label_177e84;
        case 0x177e90u: goto label_177e90;
        default: break;
    }

    ctx->pc = 0x177e58u;

    // 0x177e58: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x177e58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x177e5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177e60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x177e60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177e64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x177e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x177e68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x177e68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x177e6c: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x177e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x177e70: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x177E70u;
    {
        const bool branch_taken_0x177e70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x177E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177E70u;
            // 0x177e74: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177e70) {
            ctx->pc = 0x177E9Cu;
            goto label_177e9c;
        }
    }
    ctx->pc = 0x177E78u;
    // 0x177e78: 0xde250000  ld          $a1, 0x0($s1)
    ctx->pc = 0x177e78u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x177e7c: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x177E7Cu;
    SET_GPR_U32(ctx, 31, 0x177E84u);
    ctx->pc = 0x177E80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177E7Cu;
            // 0x177e80: 0xde040130  ld          $a0, 0x130($s0) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 304)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177E84u; }
        if (ctx->pc != 0x177E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177E84u; }
        if (ctx->pc != 0x177E84u) { return; }
    }
    ctx->pc = 0x177E84u;
label_177e84:
    // 0x177e84: 0xde250008  ld          $a1, 0x8($s1)
    ctx->pc = 0x177e84u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x177e88: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x177E88u;
    SET_GPR_U32(ctx, 31, 0x177E90u);
    ctx->pc = 0x177E8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177E88u;
            // 0x177e8c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177E90u; }
        if (ctx->pc != 0x177E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177E90u; }
        if (ctx->pc != 0x177E90u) { return; }
    }
    ctx->pc = 0x177E90u;
label_177e90:
    // 0x177e90: 0xde030128  ld          $v1, 0x128($s0)
    ctx->pc = 0x177e90u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x177e94: 0x62182d  daddu       $v1, $v1, $v0
    ctx->pc = 0x177e94u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 2));
    // 0x177e98: 0xfe030128  sd          $v1, 0x128($s0)
    ctx->pc = 0x177e98u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 296), GPR_U64(ctx, 3));
label_177e9c:
    // 0x177e9c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177e9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177ea0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177ea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177ea4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x177ea4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177ea8: 0x3e00008  jr          $ra
    ctx->pc = 0x177EA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177EA8u;
            // 0x177eac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177E84u: goto label_177e84;
            case 0x177E90u: goto label_177e90;
            case 0x177E9Cu: goto label_177e9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177EB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
