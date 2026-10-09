#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182A10
// Address: 0x182a10 - 0x182a98
void sub_00182A10_0x182a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182A10_0x182a10");
#endif

    switch (ctx->pc) {
        case 0x182a64u: goto label_182a64;
        default: break;
    }

    ctx->pc = 0x182a10u;

    // 0x182a10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x182a14: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x182a14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x182a18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182a1c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x182a1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182a20: 0x2024018  mult        $t0, $s0, $v0
    ctx->pc = 0x182a20u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x182a24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x182a24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x182a28: 0x3c110028  lui         $s1, 0x28
    ctx->pc = 0x182a28u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)40 << 16));
    // 0x182a2c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x182a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x182a30: 0x26255b48  addiu       $a1, $s1, 0x5B48
    ctx->pc = 0x182a30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 23368));
    // 0x182a34: 0x1051021  addu        $v0, $t0, $a1
    ctx->pc = 0x182a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x182a38: 0x8c460800  lw          $a2, 0x800($v0)
    ctx->pc = 0x182a38u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2048)));
    // 0x182a3c: 0x18c0000b  blez        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x182A3Cu;
    {
        const bool branch_taken_0x182a3c = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x182A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182A3Cu;
            // 0x182a40: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182a3c) {
            ctx->pc = 0x182A6Cu;
            goto label_182a6c;
        }
    }
    ctx->pc = 0x182A44u;
    // 0x182a44: 0x8c630894  lw          $v1, 0x894($v1)
    ctx->pc = 0x182a44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2196)));
    // 0x182a48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x182a48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182a4c: 0x54620008  bnel        $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x182A4Cu;
    {
        const bool branch_taken_0x182a4c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x182a4c) {
            ctx->pc = 0x182A50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182A4Cu;
            // 0x182a50: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182A70u;
            goto label_182a70;
        }
    }
    ctx->pc = 0x182A54u;
    // 0x182a54: 0x24a50400  addiu       $a1, $a1, 0x400
    ctx->pc = 0x182a54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1024));
    // 0x182a58: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x182a58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182a5c: 0xc061baa  jal         func_186EA8
    ctx->pc = 0x182A5Cu;
    SET_GPR_U32(ctx, 31, 0x182A64u);
    ctx->pc = 0x182A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182A5Cu;
            // 0x182a60: 0x1052821  addu        $a1, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EA8u;
    if (runtime->hasFunction(0x186EA8u)) {
        auto targetFn = runtime->lookupFunction(0x186EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182A64u; }
        if (ctx->pc != 0x182A64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EA8_0x186ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182A64u; }
        if (ctx->pc != 0x182A64u) { return; }
    }
    ctx->pc = 0x182A64u;
label_182a64:
    // 0x182a64: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x182A64u;
    {
        const bool branch_taken_0x182a64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x182a64) {
            ctx->pc = 0x182A68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182A64u;
            // 0x182a68: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182A88u;
            goto label_182a88;
        }
    }
    ctx->pc = 0x182A6Cu;
label_182a6c:
    // 0x182a6c: 0x24030898  addiu       $v1, $zero, 0x898
    ctx->pc = 0x182a6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
label_182a70:
    // 0x182a70: 0x26245b48  addiu       $a0, $s1, 0x5B48
    ctx->pc = 0x182a70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 23368));
    // 0x182a74: 0x2031818  mult        $v1, $s0, $v1
    ctx->pc = 0x182a74u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x182a78: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x182a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182a7c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x182a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x182a80: 0xac600894  sw          $zero, 0x894($v1)
    ctx->pc = 0x182a80u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 2196), GPR_U32(ctx, 0));
    // 0x182a84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182a84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_182a88:
    // 0x182a88: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x182a88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182a8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182a8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182a90: 0x3e00008  jr          $ra
    ctx->pc = 0x182A90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182A90u;
            // 0x182a94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182A64u: goto label_182a64;
            case 0x182A6Cu: goto label_182a6c;
            case 0x182A70u: goto label_182a70;
            case 0x182A88u: goto label_182a88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182A98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
