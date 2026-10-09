#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1270
// Address: 0x1a1270 - 0x1a1328
void sub_001A1270_0x1a1270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1270_0x1a1270");
#endif

    switch (ctx->pc) {
        case 0x1a12a0u: goto label_1a12a0;
        case 0x1a12b4u: goto label_1a12b4;
        case 0x1a12d4u: goto label_1a12d4;
        default: break;
    }

    ctx->pc = 0x1a1270u;

    // 0x1a1270: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a1270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a1274: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a1274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a1278: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a1278u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a127c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a127cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a1280: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a1280u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1284: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x1a1284u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1a1288: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x1a1288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a128c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a128cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a1290: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a1290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a1294: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a1294u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a1298: 0xc06856c  jal         func_1A15B0
    ctx->pc = 0x1A1298u;
    SET_GPR_U32(ctx, 31, 0x1A12A0u);
    ctx->pc = 0x1A129Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1298u;
            // 0x1a129c: 0x628024  and         $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A15B0u;
    if (runtime->hasFunction(0x1A15B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A15B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12A0u; }
        if (ctx->pc != 0x1A12A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A15B0_0x1a15b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12A0u; }
        if (ctx->pc != 0x1A12A0u) { return; }
    }
    ctx->pc = 0x1A12A0u;
label_1a12a0:
    // 0x1a12a0: 0x50082b  sltu        $at, $v0, $s0
    ctx->pc = 0x1a12a0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a12a4: 0x10200010  beqz        $at, . + 4 + (0x10 << 2)
    ctx->pc = 0x1A12A4u;
    {
        const bool branch_taken_0x1a12a4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A12A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A12A4u;
            // 0x1a12a8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a12a4) {
            ctx->pc = 0x1A12E8u;
            goto label_1a12e8;
        }
    }
    ctx->pc = 0x1A12ACu;
    // 0x1a12ac: 0xc0684fc  jal         func_1A13F0
    ctx->pc = 0x1A12ACu;
    SET_GPR_U32(ctx, 31, 0x1A12B4u);
    ctx->pc = 0x1A13F0u;
    if (runtime->hasFunction(0x1A13F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A13F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12B4u; }
        if (ctx->pc != 0x1A12B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A13F0_0x1a13f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12B4u; }
        if (ctx->pc != 0x1A12B4u) { return; }
    }
    ctx->pc = 0x1A12B4u;
label_1a12b4:
    // 0x1a12b4: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1a12b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1a12b8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1a12b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a12bc: 0x2443ffff  addiu       $v1, $v0, -0x1
    ctx->pc = 0x1a12bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a12c0: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1a12c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1a12c4: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a12c4u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a12c8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a12c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a12cc: 0xc06856c  jal         func_1A15B0
    ctx->pc = 0x1A12CCu;
    SET_GPR_U32(ctx, 31, 0x1A12D4u);
    ctx->pc = 0x1A12D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A12CCu;
            // 0x1a12d0: 0x628024  and         $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A15B0u;
    if (runtime->hasFunction(0x1A15B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A15B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12D4u; }
        if (ctx->pc != 0x1A12D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A15B0_0x1a15b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A12D4u; }
        if (ctx->pc != 0x1A12D4u) { return; }
    }
    ctx->pc = 0x1A12D4u;
label_1a12d4:
    // 0x1a12d4: 0x50082b  sltu        $at, $v0, $s0
    ctx->pc = 0x1a12d4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a12d8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A12D8u;
    {
        const bool branch_taken_0x1a12d8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a12d8) {
            ctx->pc = 0x1A12E8u;
            goto label_1a12e8;
        }
    }
    ctx->pc = 0x1A12E0u;
    // 0x1a12e0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A12E0u;
    {
        const bool branch_taken_0x1a12e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A12E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A12E0u;
            // 0x1a12e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a12e0) {
            ctx->pc = 0x1A1314u;
            goto label_1a1314;
        }
    }
    ctx->pc = 0x1A12E8u;
label_1a12e8:
    // 0x1a12e8: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1a12e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1a12ec: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A12ECu;
    {
        const bool branch_taken_0x1a12ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a12ec) {
            ctx->pc = 0x1A1308u;
            goto label_1a1308;
        }
    }
    ctx->pc = 0x1A12F4u;
    // 0x1a12f4: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1a12f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a12f8: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1a12f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a12fc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a12fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a1300: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A1300u;
    {
        const bool branch_taken_0x1a1300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1300u;
            // 0x1a1304: 0x501023  subu        $v0, $v0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1300) {
            ctx->pc = 0x1A1314u;
            goto label_1a1314;
        }
    }
    ctx->pc = 0x1A1308u;
label_1a1308:
    // 0x1a1308: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1a1308u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1a130c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1a130cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a1310: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1a1310u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_1a1314:
    // 0x1a1314: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a1314u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a1318: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a1318u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a131c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a131cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1320: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1320u;
            // 0x1a1324: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A12A0u: goto label_1a12a0;
            case 0x1A12B4u: goto label_1a12b4;
            case 0x1A12D4u: goto label_1a12d4;
            case 0x1A12E8u: goto label_1a12e8;
            case 0x1A1308u: goto label_1a1308;
            case 0x1A1314u: goto label_1a1314;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1328u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
