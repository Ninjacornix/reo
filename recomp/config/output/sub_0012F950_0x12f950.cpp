#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012F950
// Address: 0x12f950 - 0x12f9c0
void sub_0012F950_0x12f950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012F950_0x12f950");
#endif

    switch (ctx->pc) {
        case 0x12f96cu: goto label_12f96c;
        case 0x12f980u: goto label_12f980;
        case 0x12f994u: goto label_12f994;
        default: break;
    }

    ctx->pc = 0x12f950u;

    // 0x12f950: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12f950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12f954: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12f954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12f958: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12f958u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f95c: 0x12000012  beqz        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x12F95Cu;
    {
        const bool branch_taken_0x12f95c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F95Cu;
            // 0x12f960: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f95c) {
            ctx->pc = 0x12F9A8u;
            goto label_12f9a8;
        }
    }
    ctx->pc = 0x12F964u;
    // 0x12f964: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12F964u;
    SET_GPR_U32(ctx, 31, 0x12F96Cu);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F96Cu; }
        if (ctx->pc != 0x12F96Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F96Cu; }
        if (ctx->pc != 0x12F96Cu) { return; }
    }
    ctx->pc = 0x12F96Cu;
label_12f96c:
    // 0x12f96c: 0x8e020080  lw          $v0, 0x80($s0)
    ctx->pc = 0x12f96cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x12f970: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12F970u;
    {
        const bool branch_taken_0x12f970 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12F974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F970u;
            // 0x12f974: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f970) {
            ctx->pc = 0x12F980u;
            goto label_12f980;
        }
    }
    ctx->pc = 0x12F978u;
    // 0x12f978: 0xc04b8c8  jal         func_12E320
    ctx->pc = 0x12F978u;
    SET_GPR_U32(ctx, 31, 0x12F980u);
    ctx->pc = 0x12E320u;
    if (runtime->hasFunction(0x12E320u)) {
        auto targetFn = runtime->lookupFunction(0x12E320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F980u; }
        if (ctx->pc != 0x12F980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E320_0x12e320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F980u; }
        if (ctx->pc != 0x12F980u) { return; }
    }
    ctx->pc = 0x12F980u;
label_12f980:
    // 0x12f980: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x12f980u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x12f984: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x12F984u;
    {
        const bool branch_taken_0x12f984 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x12f984) {
            ctx->pc = 0x12F988u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12F984u;
            // 0x12f988: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12F998u;
            goto label_12f998;
        }
    }
    ctx->pc = 0x12F98Cu;
    // 0x12f98c: 0xc04b8c8  jal         func_12E320
    ctx->pc = 0x12F98Cu;
    SET_GPR_U32(ctx, 31, 0x12F994u);
    ctx->pc = 0x12E320u;
    if (runtime->hasFunction(0x12E320u)) {
        auto targetFn = runtime->lookupFunction(0x12E320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F994u; }
        if (ctx->pc != 0x12F994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E320_0x12e320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F994u; }
        if (ctx->pc != 0x12F994u) { return; }
    }
    ctx->pc = 0x12F994u;
label_12f994:
    // 0x12f994: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x12f994u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_12f998:
    // 0x12f998: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12f998u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12f99c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12f99cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12f9a0: 0x804993e  j           func_1264F8
    ctx->pc = 0x12F9A0u;
    ctx->pc = 0x12F9A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F9A0u;
            // 0x12f9a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12F9A8u;
label_12f9a8:
    // 0x12f9a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12f9a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12f9ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12f9acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12f9b0: 0x3e00008  jr          $ra
    ctx->pc = 0x12F9B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12F9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F9B0u;
            // 0x12f9b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F96Cu: goto label_12f96c;
            case 0x12F980u: goto label_12f980;
            case 0x12F994u: goto label_12f994;
            case 0x12F998u: goto label_12f998;
            case 0x12F9A8u: goto label_12f9a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12F9B8u;
    // 0x12f9b8: 0x3e00008  jr          $ra
    ctx->pc = 0x12F9B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12F9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F9B8u;
            // 0x12f9bc: 0x80820001  lb          $v0, 0x1($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F96Cu: goto label_12f96c;
            case 0x12F980u: goto label_12f980;
            case 0x12F994u: goto label_12f994;
            case 0x12F998u: goto label_12f998;
            case 0x12F9A8u: goto label_12f9a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12F9C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
