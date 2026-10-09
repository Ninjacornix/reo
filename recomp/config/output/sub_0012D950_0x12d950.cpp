#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D950
// Address: 0x12d950 - 0x12da30
void sub_0012D950_0x12d950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D950_0x12d950");
#endif

    switch (ctx->pc) {
        case 0x12d970u: goto label_12d970;
        case 0x12d998u: goto label_12d998;
        case 0x12d9d0u: goto label_12d9d0;
        default: break;
    }

    ctx->pc = 0x12d950u;

    // 0x12d950: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12d950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12d954: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d958: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12d958u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d95c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12d95cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12d960: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12d960u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d964: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12d964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12d968: 0xc0493d2  jal         func_124F48
    ctx->pc = 0x12D968u;
    SET_GPR_U32(ctx, 31, 0x12D970u);
    ctx->pc = 0x12D96Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D968u;
            // 0x12d96c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F48u;
    if (runtime->hasFunction(0x124F48u)) {
        auto targetFn = runtime->lookupFunction(0x124F48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D970u; }
        if (ctx->pc != 0x12D970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124F48_0x124f48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D970u; }
        if (ctx->pc != 0x12D970u) { return; }
    }
    ctx->pc = 0x12D970u;
label_12d970:
    // 0x12d970: 0x1840000b  blez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12D970u;
    {
        const bool branch_taken_0x12d970 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x12D974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D970u;
            // 0x12d974: 0x2402ff80  addiu       $v0, $zero, -0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d970) {
            ctx->pc = 0x12D9A0u;
            goto label_12d9a0;
        }
    }
    ctx->pc = 0x12D978u;
    // 0x12d978: 0x92020001  lbu         $v0, 0x1($s0)
    ctx->pc = 0x12d978u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x12d97c: 0x2442fffe  addiu       $v0, $v0, -0x2
    ctx->pc = 0x12d97cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
    // 0x12d980: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x12d980u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x12d984: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x12D984u;
    {
        const bool branch_taken_0x12d984 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d984) {
            ctx->pc = 0x12D988u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D984u;
            // 0x12d988: 0x2402ff80  addiu       $v0, $zero, -0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D9A0u;
            goto label_12d9a0;
        }
    }
    ctx->pc = 0x12D98Cu;
    // 0x12d98c: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x12d98cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12d990: 0xc0493d6  jal         func_124F58
    ctx->pc = 0x12D990u;
    SET_GPR_U32(ctx, 31, 0x12D998u);
    ctx->pc = 0x12D994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D990u;
            // 0x12d994: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F58u;
    if (runtime->hasFunction(0x124F58u)) {
        auto targetFn = runtime->lookupFunction(0x124F58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D998u; }
        if (ctx->pc != 0x12D998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124F58_0x124f58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D998u; }
        if (ctx->pc != 0x12D998u) { return; }
    }
    ctx->pc = 0x12D998u;
label_12d998:
    // 0x12d998: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12D998u;
    {
        const bool branch_taken_0x12d998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D998u;
            // 0x12d99c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d998) {
            ctx->pc = 0x12D9A4u;
            goto label_12d9a4;
        }
    }
    ctx->pc = 0x12D9A0u;
label_12d9a0:
    // 0x12d9a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d9a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12d9a4:
    // 0x12d9a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12d9a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d9a8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12d9a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d9ac: 0x3e00008  jr          $ra
    ctx->pc = 0x12D9ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D9B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D9ACu;
            // 0x12d9b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D970u: goto label_12d970;
            case 0x12D998u: goto label_12d998;
            case 0x12D9A0u: goto label_12d9a0;
            case 0x12D9A4u: goto label_12d9a4;
            case 0x12D9D0u: goto label_12d9d0;
            case 0x12DA00u: goto label_12da00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D9B4u;
    // 0x12d9b4: 0x0  nop
    ctx->pc = 0x12d9b4u;
    // NOP
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
            case 0x12D970u: goto label_12d970;
            case 0x12D998u: goto label_12d998;
            case 0x12D9A0u: goto label_12d9a0;
            case 0x12D9A4u: goto label_12d9a4;
            case 0x12D9D0u: goto label_12d9d0;
            case 0x12DA00u: goto label_12da00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DA10u;
    // 0x12da10: 0x3e00008  jr          $ra
    ctx->pc = 0x12DA10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA10u;
            // 0x12da14: 0x8c820098  lw          $v0, 0x98($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 152)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D970u: goto label_12d970;
            case 0x12D998u: goto label_12d998;
            case 0x12D9A0u: goto label_12d9a0;
            case 0x12D9A4u: goto label_12d9a4;
            case 0x12D9D0u: goto label_12d9d0;
            case 0x12DA00u: goto label_12da00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DA18u;
    // 0x12da18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12da18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12da1c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12da1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12da20: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12da20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12da24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12da24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12da28: 0x80493a0  j           func_124E80
    ctx->pc = 0x12DA28u;
    ctx->pc = 0x12DA2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA28u;
            // 0x12da2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E80u;
    if (runtime->hasFunction(0x124E80u)) {
        auto targetFn = runtime->lookupFunction(0x124E80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124E80_0x124e80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12DA30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
