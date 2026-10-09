#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D9B8
// Address: 0x12d9b8 - 0x12da10
void sub_0012D9B8_0x12d9b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D9B8_0x12d9b8");
#endif

    switch (ctx->pc) {
        case 0x12d9d0u: goto label_12d9d0;
        default: break;
    }

    ctx->pc = 0x12d9b8u;

    // 0x12d9b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d9b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d9bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d9bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d9c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12d9c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d9c4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12d9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12d9c8: 0xc0493d2  jal         func_124F48
    ctx->pc = 0x12D9C8u;
    SET_GPR_U32(ctx, 31, 0x12D9D0u);
    ctx->pc = 0x12D9CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D9C8u;
            // 0x12d9cc: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F48u;
    if (runtime->hasFunction(0x124F48u)) {
        auto targetFn = runtime->lookupFunction(0x124F48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D9D0u; }
        if (ctx->pc != 0x12D9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124F48_0x124f48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D9D0u; }
        if (ctx->pc != 0x12D9D0u) { return; }
    }
    ctx->pc = 0x12D9D0u;
label_12d9d0:
    // 0x12d9d0: 0x5840000b  blezl       $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12D9D0u;
    {
        const bool branch_taken_0x12d9d0 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x12d9d0) {
            ctx->pc = 0x12D9D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D9D0u;
            // 0x12d9d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12DA00u;
            goto label_12da00;
        }
    }
    ctx->pc = 0x12D9D8u;
    // 0x12d9d8: 0x92020001  lbu         $v0, 0x1($s0)
    ctx->pc = 0x12d9d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x12d9dc: 0x2442fffe  addiu       $v0, $v0, -0x2
    ctx->pc = 0x12d9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
    // 0x12d9e0: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x12d9e0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x12d9e4: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x12D9E4u;
    {
        const bool branch_taken_0x12d9e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d9e4) {
            ctx->pc = 0x12D9E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D9E4u;
            // 0x12d9e8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12DA00u;
            goto label_12da00;
        }
    }
    ctx->pc = 0x12D9ECu;
    // 0x12d9ec: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x12d9ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12d9f0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12d9f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d9f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d9f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d9f8: 0x80493da  j           func_124F68
    ctx->pc = 0x12D9F8u;
    ctx->pc = 0x12D9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D9F8u;
            // 0x12d9fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F68u;
    if (runtime->hasFunction(0x124F68u)) {
        auto targetFn = runtime->lookupFunction(0x124F68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F68_0x124f68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12DA00u;
label_12da00:
    // 0x12da00: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12da00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12da04: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12da04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12da08: 0x3e00008  jr          $ra
    ctx->pc = 0x12DA08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA08u;
            // 0x12da0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D9D0u: goto label_12d9d0;
            case 0x12DA00u: goto label_12da00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DA10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
