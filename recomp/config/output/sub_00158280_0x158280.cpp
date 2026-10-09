#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158280
// Address: 0x158280 - 0x158318
void sub_00158280_0x158280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158280_0x158280");
#endif

    switch (ctx->pc) {
        case 0x1582b0u: goto label_1582b0;
        case 0x1582c0u: goto label_1582c0;
        case 0x1582f8u: goto label_1582f8;
        default: break;
    }

    ctx->pc = 0x158280u;

    // 0x158280: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x158280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x158284: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158288: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x158288u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15828c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15828cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158290: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x158290u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158294: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x158294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x158298: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x158298u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15829c: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15829Cu;
    {
        const bool branch_taken_0x15829c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1582A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15829Cu;
            // 0x1582a0: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15829c) {
            ctx->pc = 0x1582B8u;
            goto label_1582b8;
        }
    }
    ctx->pc = 0x1582A4u;
    // 0x1582a4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1582a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1582a8: 0xc0560c6  jal         func_158318
    ctx->pc = 0x1582A8u;
    SET_GPR_U32(ctx, 31, 0x1582B0u);
    ctx->pc = 0x1582ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1582A8u;
            // 0x1582ac: 0x8c44d870  lw          $a0, -0x2790($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957168)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158318u;
    if (runtime->hasFunction(0x158318u)) {
        auto targetFn = runtime->lookupFunction(0x158318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1582B0u; }
        if (ctx->pc != 0x1582B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158318_0x158318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1582B0u; }
        if (ctx->pc != 0x1582B0u) { return; }
    }
    ctx->pc = 0x1582B0u;
label_1582b0:
    // 0x1582b0: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1582B0u;
    {
        const bool branch_taken_0x1582b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1582B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1582B0u;
            // 0x1582b4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1582b0) {
            ctx->pc = 0x1582FCu;
            goto label_1582fc;
        }
    }
    ctx->pc = 0x1582B8u;
label_1582b8:
    // 0x1582b8: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x1582B8u;
    SET_GPR_U32(ctx, 31, 0x1582C0u);
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1582C0u; }
        if (ctx->pc != 0x1582C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1582C0u; }
        if (ctx->pc != 0x1582C0u) { return; }
    }
    ctx->pc = 0x1582C0u;
label_1582c0:
    // 0x1582c0: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x1582c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x1582c4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1582C4u;
    {
        const bool branch_taken_0x1582c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1582C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1582C4u;
            // 0x1582c8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1582c4) {
            ctx->pc = 0x1582E8u;
            goto label_1582e8;
        }
    }
    ctx->pc = 0x1582CCu;
    // 0x1582cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1582ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1582d0: 0x34a50101  ori         $a1, $a1, 0x101
    ctx->pc = 0x1582d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)257);
    // 0x1582d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1582d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1582d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1582d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1582dc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1582dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1582e0: 0x805607e  j           func_1581F8
    ctx->pc = 0x1582E0u;
    ctx->pc = 0x1582E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1582E0u;
            // 0x1582e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001581F8_0x1581f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1582E8u;
label_1582e8:
    // 0x1582e8: 0x26040004  addiu       $a0, $s0, 0x4
    ctx->pc = 0x1582e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1582ec: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1582ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1582f0: 0xc0560c6  jal         func_158318
    ctx->pc = 0x1582F0u;
    SET_GPR_U32(ctx, 31, 0x1582F8u);
    ctx->pc = 0x1582F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1582F0u;
            // 0x1582f4: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158318u;
    if (runtime->hasFunction(0x158318u)) {
        auto targetFn = runtime->lookupFunction(0x158318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1582F8u; }
        if (ctx->pc != 0x1582F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158318_0x158318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1582F8u; }
        if (ctx->pc != 0x1582F8u) { return; }
    }
    ctx->pc = 0x1582F8u;
label_1582f8:
    // 0x1582f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1582f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1582fc:
    // 0x1582fc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1582fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158300: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158300u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158304: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x158304u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x158308: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x158308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15830c: 0x3e00008  jr          $ra
    ctx->pc = 0x15830Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15830Cu;
            // 0x158310: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1582B0u: goto label_1582b0;
            case 0x1582B8u: goto label_1582b8;
            case 0x1582C0u: goto label_1582c0;
            case 0x1582E8u: goto label_1582e8;
            case 0x1582F8u: goto label_1582f8;
            case 0x1582FCu: goto label_1582fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158314u;
    // 0x158314: 0x0  nop
    ctx->pc = 0x158314u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
