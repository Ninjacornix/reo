#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C22C0
// Address: 0x1c22c0 - 0x1c2360
void sub_001C22C0_0x1c22c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C22C0_0x1c22c0");
#endif

    switch (ctx->pc) {
        case 0x1c22e0u: goto label_1c22e0;
        case 0x1c22e8u: goto label_1c22e8;
        case 0x1c2314u: goto label_1c2314;
        default: break;
    }

    ctx->pc = 0x1c22c0u;

    // 0x1c22c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c22c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c22c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c22c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c22c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c22c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c22cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c22ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c22d0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c22d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c22d4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c22d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c22d8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1C22D8u;
    {
        const bool branch_taken_0x1c22d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C22DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C22D8u;
            // 0x1c22dc: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c22d8) {
            ctx->pc = 0x1C2334u;
            goto label_1c2334;
        }
    }
    ctx->pc = 0x1C22E0u;
label_1c22e0:
    // 0x1c22e0: 0xc06db50  jal         func_1B6D40
    ctx->pc = 0x1C22E0u;
    SET_GPR_U32(ctx, 31, 0x1C22E8u);
    ctx->pc = 0x1C22E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C22E0u;
            // 0x1c22e4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6D40u;
    if (runtime->hasFunction(0x1B6D40u)) {
        auto targetFn = runtime->lookupFunction(0x1B6D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C22E8u; }
        if (ctx->pc != 0x1C22E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6D40_0x1b6d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C22E8u; }
        if (ctx->pc != 0x1C22E8u) { return; }
    }
    ctx->pc = 0x1C22E8u;
label_1c22e8:
    // 0x1c22e8: 0x30440003  andi        $a0, $v0, 0x3
    ctx->pc = 0x1c22e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1c22ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c22ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c22f0: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C22F0u;
    {
        const bool branch_taken_0x1c22f0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C22F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C22F0u;
            // 0x1c22f4: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c22f0) {
            ctx->pc = 0x1C230Cu;
            goto label_1c230c;
        }
    }
    ctx->pc = 0x1C22F8u;
    // 0x1c22f8: 0x324300ff  andi        $v1, $s2, 0xFF
    ctx->pc = 0x1c22f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1c22fc: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1c22fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1c2300: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C2300u;
    {
        const bool branch_taken_0x1c2300 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c2300) {
            ctx->pc = 0x1C2340u;
            goto label_1c2340;
        }
    }
    ctx->pc = 0x1C2308u;
    // 0x1c2308: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1c2308u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c230c:
    // 0x1c230c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C230Cu;
    {
        const bool branch_taken_0x1c230c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C230Cu;
            // 0x1c2310: 0x64102a  slt         $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c230c) {
            ctx->pc = 0x1C232Cu;
            goto label_1c232c;
        }
    }
    ctx->pc = 0x1C2314u;
label_1c2314:
    // 0x1c2314: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1c2314u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c2318: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c2318u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c231c: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1c231cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2320: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c2320u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1c2324: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1c2324u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1c2328: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x1c2328u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
label_1c232c:
    // 0x1c232c: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1C232Cu;
    {
        const bool branch_taken_0x1c232c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c232c) {
            ctx->pc = 0x1C2314u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c2314;
        }
    }
    ctx->pc = 0x1C2334u;
label_1c2334:
    // 0x1c2334: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1c2334u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c2338: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1C2338u;
    {
        const bool branch_taken_0x1c2338 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C233Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2338u;
            // 0x1c233c: 0x305200ff  andi        $s2, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2338) {
            ctx->pc = 0x1C22E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c22e0;
        }
    }
    ctx->pc = 0x1C2340u;
label_1c2340:
    // 0x1c2340: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1c2340u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c2344: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1c2344u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2348: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c2348u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c234c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c234cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c2350: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c2350u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c2354: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c2354u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c2358: 0x3e00008  jr          $ra
    ctx->pc = 0x1C2358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C235Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2358u;
            // 0x1c235c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C22E0u: goto label_1c22e0;
            case 0x1C22E8u: goto label_1c22e8;
            case 0x1C230Cu: goto label_1c230c;
            case 0x1C2314u: goto label_1c2314;
            case 0x1C232Cu: goto label_1c232c;
            case 0x1C2334u: goto label_1c2334;
            case 0x1C2340u: goto label_1c2340;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C2360u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
