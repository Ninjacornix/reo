#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169A00
// Address: 0x169a00 - 0x169a68
void sub_00169A00_0x169a00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169A00_0x169a00");
#endif

    switch (ctx->pc) {
        case 0x169a34u: goto label_169a34;
        case 0x169a3cu: goto label_169a3c;
        case 0x169a4cu: goto label_169a4c;
        case 0x169a54u: goto label_169a54;
        default: break;
    }

    ctx->pc = 0x169a00u;

    // 0x169a00: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x169a00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x169a04: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x169a04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x169a08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169a08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169a0c: 0x24631a10  addiu       $v1, $v1, 0x1A10
    ctx->pc = 0x169a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 6672));
    // 0x169a10: 0x24420790  addiu       $v0, $v0, 0x790
    ctx->pc = 0x169a10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1936));
    // 0x169a14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169a14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169a18: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x169a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x169a1c: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x169a1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x169a20: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x169a20u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x169a24: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x169a24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169a28: 0x24042b80  addiu       $a0, $zero, 0x2B80
    ctx->pc = 0x169a28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11136));
    // 0x169a2c: 0xc05a794  jal         func_169E50
    ctx->pc = 0x169A2Cu;
    SET_GPR_U32(ctx, 31, 0x169A34u);
    ctx->pc = 0x169A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169A2Cu;
            // 0x169a30: 0xaca4f1ac  sw          $a0, -0xE54($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4294963628), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E50u;
    if (runtime->hasFunction(0x169E50u)) {
        auto targetFn = runtime->lookupFunction(0x169E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A34u; }
        if (ctx->pc != 0x169A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E50_0x169e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A34u; }
        if (ctx->pc != 0x169A34u) { return; }
    }
    ctx->pc = 0x169A34u;
label_169a34:
    // 0x169a34: 0xc05a69a  jal         func_169A68
    ctx->pc = 0x169A34u;
    SET_GPR_U32(ctx, 31, 0x169A3Cu);
    ctx->pc = 0x169A38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169A34u;
            // 0x169a38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169A68u;
    if (runtime->hasFunction(0x169A68u)) {
        auto targetFn = runtime->lookupFunction(0x169A68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A3Cu; }
        if (ctx->pc != 0x169A3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169A68_0x169a68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A3Cu; }
        if (ctx->pc != 0x169A3Cu) { return; }
    }
    ctx->pc = 0x169A3Cu;
label_169a3c:
    // 0x169a3c: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x169A3Cu;
    {
        const bool branch_taken_0x169a3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x169a3c) {
            ctx->pc = 0x169A40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x169A3Cu;
            // 0x169a40: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x169A5Cu;
            goto label_169a5c;
        }
    }
    ctx->pc = 0x169A44u;
    // 0x169a44: 0xc05a7a0  jal         func_169E80
    ctx->pc = 0x169A44u;
    SET_GPR_U32(ctx, 31, 0x169A4Cu);
    ctx->pc = 0x169E80u;
    if (runtime->hasFunction(0x169E80u)) {
        auto targetFn = runtime->lookupFunction(0x169E80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A4Cu; }
        if (ctx->pc != 0x169A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E80_0x169e80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A4Cu; }
        if (ctx->pc != 0x169A4Cu) { return; }
    }
    ctx->pc = 0x169A4Cu;
label_169a4c:
    // 0x169a4c: 0xc05a7ae  jal         func_169EB8
    ctx->pc = 0x169A4Cu;
    SET_GPR_U32(ctx, 31, 0x169A54u);
    ctx->pc = 0x169EB8u;
    if (runtime->hasFunction(0x169EB8u)) {
        auto targetFn = runtime->lookupFunction(0x169EB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A54u; }
        if (ctx->pc != 0x169A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EB8_0x169eb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A54u; }
        if (ctx->pc != 0x169A54u) { return; }
    }
    ctx->pc = 0x169A54u;
label_169a54:
    // 0x169a54: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x169a54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169a58: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169a58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_169a5c:
    // 0x169a5c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x169a5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169a60: 0x3e00008  jr          $ra
    ctx->pc = 0x169A60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169A60u;
            // 0x169a64: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169A34u: goto label_169a34;
            case 0x169A3Cu: goto label_169a3c;
            case 0x169A4Cu: goto label_169a4c;
            case 0x169A54u: goto label_169a54;
            case 0x169A5Cu: goto label_169a5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169A68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
