#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA680
// Address: 0x1ba680 - 0x1ba718
void sub_001BA680_0x1ba680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA680_0x1ba680");
#endif

    switch (ctx->pc) {
        case 0x1ba6b8u: goto label_1ba6b8;
        case 0x1ba6dcu: goto label_1ba6dc;
        case 0x1ba708u: goto label_1ba708;
        default: break;
    }

    ctx->pc = 0x1ba680u;

    // 0x1ba680: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ba680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ba684: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba688: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ba688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ba68c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba68cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba690: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ba690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba694: 0x90840008  lbu         $a0, 0x8($a0)
    ctx->pc = 0x1ba694u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1ba698: 0x1083000e  beq         $a0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1BA698u;
    {
        const bool branch_taken_0x1ba698 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba698) {
            ctx->pc = 0x1BA6D4u;
            goto label_1ba6d4;
        }
    }
    ctx->pc = 0x1BA6A0u;
    // 0x1ba6a0: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA6A0u;
    {
        const bool branch_taken_0x1ba6a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba6a0) {
            ctx->pc = 0x1BA6B0u;
            goto label_1ba6b0;
        }
    }
    ctx->pc = 0x1BA6A8u;
    // 0x1ba6a8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BA6A8u;
    {
        const bool branch_taken_0x1ba6a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA6A8u;
            // 0x1ba6ac: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba6a8) {
            ctx->pc = 0x1BA70Cu;
            goto label_1ba70c;
        }
    }
    ctx->pc = 0x1BA6B0u;
label_1ba6b0:
    // 0x1ba6b0: 0xc06e9c8  jal         func_1BA720
    ctx->pc = 0x1BA6B0u;
    SET_GPR_U32(ctx, 31, 0x1BA6B8u);
    ctx->pc = 0x1BA720u;
    if (runtime->hasFunction(0x1BA720u)) {
        auto targetFn = runtime->lookupFunction(0x1BA720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6B8u; }
        if (ctx->pc != 0x1BA6B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA720_0x1ba720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6B8u; }
        if (ctx->pc != 0x1BA6B8u) { return; }
    }
    ctx->pc = 0x1BA6B8u;
label_1ba6b8:
    // 0x1ba6b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba6bc: 0xac20656c  sw          $zero, 0x656C($at)
    ctx->pc = 0x1ba6bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25964), GPR_U32(ctx, 0));
    // 0x1ba6c0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba6c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba6c4: 0xac206568  sw          $zero, 0x6568($at)
    ctx->pc = 0x1ba6c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25960), GPR_U32(ctx, 0));
    // 0x1ba6c8: 0x92020008  lbu         $v0, 0x8($s0)
    ctx->pc = 0x1ba6c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1ba6cc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ba6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ba6d0: 0xa2020008  sb          $v0, 0x8($s0)
    ctx->pc = 0x1ba6d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 2));
label_1ba6d4:
    // 0x1ba6d4: 0xc06e9d0  jal         func_1BA740
    ctx->pc = 0x1BA6D4u;
    SET_GPR_U32(ctx, 31, 0x1BA6DCu);
    ctx->pc = 0x1BA6D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA6D4u;
            // 0x1ba6d8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA740u;
    if (runtime->hasFunction(0x1BA740u)) {
        auto targetFn = runtime->lookupFunction(0x1BA740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6DCu; }
        if (ctx->pc != 0x1BA6DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA740_0x1ba740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6DCu; }
        if (ctx->pc != 0x1BA6DCu) { return; }
    }
    ctx->pc = 0x1BA6DCu;
label_1ba6dc:
    // 0x1ba6dc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba6dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba6e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba6e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba6e4: 0x90246571  lbu         $a0, 0x6571($at)
    ctx->pc = 0x1ba6e4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 25969)));
    // 0x1ba6e8: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA6E8u;
    {
        const bool branch_taken_0x1ba6e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba6e8) {
            ctx->pc = 0x1BA700u;
            goto label_1ba700;
        }
    }
    ctx->pc = 0x1BA6F0u;
    // 0x1ba6f0: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA6F0u;
    {
        const bool branch_taken_0x1ba6f0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba6f0) {
            ctx->pc = 0x1BA708u;
            goto label_1ba708;
        }
    }
    ctx->pc = 0x1BA6F8u;
    // 0x1ba6f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA6F8u;
    {
        const bool branch_taken_0x1ba6f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba6f8) {
            ctx->pc = 0x1BA708u;
            goto label_1ba708;
        }
    }
    ctx->pc = 0x1BA700u;
label_1ba700:
    // 0x1ba700: 0xc06ea48  jal         func_1BA920
    ctx->pc = 0x1BA700u;
    SET_GPR_U32(ctx, 31, 0x1BA708u);
    ctx->pc = 0x1BA704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA700u;
            // 0x1ba704: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA920u;
    if (runtime->hasFunction(0x1BA920u)) {
        auto targetFn = runtime->lookupFunction(0x1BA920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA708u; }
        if (ctx->pc != 0x1BA708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA920_0x1ba920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA708u; }
        if (ctx->pc != 0x1BA708u) { return; }
    }
    ctx->pc = 0x1BA708u;
label_1ba708:
    // 0x1ba708: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ba708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1ba70c:
    // 0x1ba70c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba70cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba710: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA710u;
            // 0x1ba714: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA6B0u: goto label_1ba6b0;
            case 0x1BA6B8u: goto label_1ba6b8;
            case 0x1BA6D4u: goto label_1ba6d4;
            case 0x1BA6DCu: goto label_1ba6dc;
            case 0x1BA700u: goto label_1ba700;
            case 0x1BA708u: goto label_1ba708;
            case 0x1BA70Cu: goto label_1ba70c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA718u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
