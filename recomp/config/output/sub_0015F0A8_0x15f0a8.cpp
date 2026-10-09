#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F0A8
// Address: 0x15f0a8 - 0x15f270
void sub_0015F0A8_0x15f0a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F0A8_0x15f0a8");
#endif

    switch (ctx->pc) {
        case 0x15f0d4u: goto label_15f0d4;
        case 0x15f174u: goto label_15f174;
        case 0x15f17cu: goto label_15f17c;
        case 0x15f188u: goto label_15f188;
        case 0x15f198u: goto label_15f198;
        case 0x15f1e4u: goto label_15f1e4;
        case 0x15f218u: goto label_15f218;
        case 0x15f22cu: goto label_15f22c;
        case 0x15f238u: goto label_15f238;
        case 0x15f250u: goto label_15f250;
        default: break;
    }

    ctx->pc = 0x15f0a8u;

    // 0x15f0a8: 0xac800080  sw          $zero, 0x80($a0)
    ctx->pc = 0x15f0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 128), GPR_U32(ctx, 0));
    // 0x15f0ac: 0x3e00008  jr          $ra
    ctx->pc = 0x15F0ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F0B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0ACu;
            // 0x15f0b0: 0xac80007c  sw          $zero, 0x7C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 124), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F0D4u: goto label_15f0d4;
            case 0x15F0F8u: goto label_15f0f8;
            case 0x15F120u: goto label_15f120;
            case 0x15F140u: goto label_15f140;
            case 0x15F174u: goto label_15f174;
            case 0x15F17Cu: goto label_15f17c;
            case 0x15F188u: goto label_15f188;
            case 0x15F198u: goto label_15f198;
            case 0x15F1E4u: goto label_15f1e4;
            case 0x15F210u: goto label_15f210;
            case 0x15F218u: goto label_15f218;
            case 0x15F22Cu: goto label_15f22c;
            case 0x15F238u: goto label_15f238;
            case 0x15F250u: goto label_15f250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F0B4u;
    // 0x15f0b4: 0x0  nop
    ctx->pc = 0x15f0b4u;
    // NOP
    // 0x15f0b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f0b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f0bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f0c0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15f0c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f0c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f0c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15f0c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15f0cc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F0CCu;
    SET_GPR_U32(ctx, 31, 0x15F0D4u);
    ctx->pc = 0x15F0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0CCu;
            // 0x15f0d0: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F0D4u; }
        if (ctx->pc != 0x15F0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F0D4u; }
        if (ctx->pc != 0x15F0D4u) { return; }
    }
    ctx->pc = 0x15F0D4u;
label_15f0d4:
    // 0x15f0d4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f0d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f0d8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15F0D8u;
    {
        const bool branch_taken_0x15f0d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F0DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0D8u;
            // 0x15f0dc: 0x2484f0c0  addiu       $a0, $a0, -0xF40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963392));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f0d8) {
            ctx->pc = 0x15F0F8u;
            goto label_15f0f8;
        }
    }
    ctx->pc = 0x15F0E0u;
    // 0x15f0e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f0e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f0e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f0e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f0e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f0e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f0ec: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F0ECu;
    ctx->pc = 0x15F0F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0ECu;
            // 0x15f0f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F0F4u;
    // 0x15f0f4: 0x0  nop
    ctx->pc = 0x15f0f4u;
    // NOP
label_15f0f8:
    // 0x15f0f8: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15F0F8u;
    {
        const bool branch_taken_0x15f0f8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0F8u;
            // 0x15f0fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f0f8) {
            ctx->pc = 0x15F120u;
            goto label_15f120;
        }
    }
    ctx->pc = 0x15F100u;
    // 0x15f100: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f100u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f104: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f104u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f108: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f108u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f10c: 0x2484f0f0  addiu       $a0, $a0, -0xF10
    ctx->pc = 0x15f10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963440));
    // 0x15f110: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f114: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F114u;
    ctx->pc = 0x15F118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F114u;
            // 0x15f118: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F11Cu;
    // 0x15f11c: 0x0  nop
    ctx->pc = 0x15f11cu;
    // NOP
label_15f120:
    // 0x15f120: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f120u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f124: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15f124u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f128: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f128u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f12c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f12cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f130: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15f130u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f134: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x15f134u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15f138: 0x8057c50  j           func_15F140
    ctx->pc = 0x15F138u;
    ctx->pc = 0x15F13Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F138u;
            // 0x15f13c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F140u;
    goto label_15f140;
    ctx->pc = 0x15F140u;
label_15f140:
    // 0x15f140: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15f140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15f144: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f148: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f148u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f14c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f14cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f150: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f150u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f154: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f154u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f158: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x15f158u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f15c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15f15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15f160: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x15f160u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f164: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15f164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15f168: 0x8e02012c  lw          $v0, 0x12C($s0)
    ctx->pc = 0x15f168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
    // 0x15f16c: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F16Cu;
    SET_GPR_U32(ctx, 31, 0x15F174u);
    ctx->pc = 0x15F170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F16Cu;
            // 0x15f170: 0xae020128  sw          $v0, 0x128($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F174u; }
        if (ctx->pc != 0x15F174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F174u; }
        if (ctx->pc != 0x15F174u) { return; }
    }
    ctx->pc = 0x15F174u;
label_15f174:
    // 0x15f174: 0xc057bee  jal         func_15EFB8
    ctx->pc = 0x15F174u;
    SET_GPR_U32(ctx, 31, 0x15F17Cu);
    ctx->pc = 0x15F178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F174u;
            // 0x15f178: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EFB8u;
    if (runtime->hasFunction(0x15EFB8u)) {
        auto targetFn = runtime->lookupFunction(0x15EFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F17Cu; }
        if (ctx->pc != 0x15F17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EFB8_0x15efb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F17Cu; }
        if (ctx->pc != 0x15F17Cu) { return; }
    }
    ctx->pc = 0x15F17Cu;
label_15f17c:
    // 0x15f17c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f17cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f180: 0xc057db6  jal         func_15F6D8
    ctx->pc = 0x15F180u;
    SET_GPR_U32(ctx, 31, 0x15F188u);
    ctx->pc = 0x15F184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F180u;
            // 0x15f184: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F6D8u;
    if (runtime->hasFunction(0x15F6D8u)) {
        auto targetFn = runtime->lookupFunction(0x15F6D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F188u; }
        if (ctx->pc != 0x15F188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F6D8_0x15f6d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F188u; }
        if (ctx->pc != 0x15F188u) { return; }
    }
    ctx->pc = 0x15F188u;
label_15f188:
    // 0x15f188: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f188u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f18c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x15f18cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f190: 0xc057eaa  jal         func_15FAA8
    ctx->pc = 0x15F190u;
    SET_GPR_U32(ctx, 31, 0x15F198u);
    ctx->pc = 0x15F194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F190u;
            // 0x15f194: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FAA8u;
    if (runtime->hasFunction(0x15FAA8u)) {
        auto targetFn = runtime->lookupFunction(0x15FAA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F198u; }
        if (ctx->pc != 0x15F198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FAA8_0x15faa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F198u; }
        if (ctx->pc != 0x15F198u) { return; }
    }
    ctx->pc = 0x15F198u;
label_15f198:
    // 0x15f198: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f198u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f19c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x15f19cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1a0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15f1a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f1a4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x15f1a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f1a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f1ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f1acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f1b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f1b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f1b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15f1b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15f1b8: 0x8057eac  j           func_15FAB0
    ctx->pc = 0x15F1B8u;
    ctx->pc = 0x15F1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F1B8u;
            // 0x15f1bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FAB0u;
    {
        auto targetFn = runtime->lookupFunction(0x15FAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x15F1C0u;
    // 0x15f1c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f1c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f1c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f1c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f1c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f1ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f1d0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f1d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f1d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15f1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15f1dc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F1DCu;
    SET_GPR_U32(ctx, 31, 0x15F1E4u);
    ctx->pc = 0x15F1E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F1DCu;
            // 0x15f1e0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F1E4u; }
        if (ctx->pc != 0x15F1E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F1E4u; }
        if (ctx->pc != 0x15F1E4u) { return; }
    }
    ctx->pc = 0x15F1E4u;
label_15f1e4:
    // 0x15f1e4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15F1E4u;
    {
        const bool branch_taken_0x15f1e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F1E4u;
            // 0x15f1e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f1e4) {
            ctx->pc = 0x15F210u;
            goto label_15f210;
        }
    }
    ctx->pc = 0x15F1ECu;
    // 0x15f1ec: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f1ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f1f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f1f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f1f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f1f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f1f8: 0x2484f120  addiu       $a0, $a0, -0xEE0
    ctx->pc = 0x15f1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963488));
    // 0x15f1fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f1fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f200: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f204: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F204u;
    ctx->pc = 0x15F208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F204u;
            // 0x15f208: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F20Cu;
    // 0x15f20c: 0x0  nop
    ctx->pc = 0x15f20cu;
    // NOP
label_15f210:
    // 0x15f210: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F210u;
    SET_GPR_U32(ctx, 31, 0x15F218u);
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F218u; }
        if (ctx->pc != 0x15F218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F218u; }
        if (ctx->pc != 0x15F218u) { return; }
    }
    ctx->pc = 0x15F218u;
label_15f218:
    // 0x15f218: 0x8e04014c  lw          $a0, 0x14C($s0)
    ctx->pc = 0x15f218u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 332)));
    // 0x15f21c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x15f21cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15f220: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x15f220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x15f224: 0x40f809  jalr        $v0
    ctx->pc = 0x15F224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15F22Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15F22Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F0D4u: goto label_15f0d4;
            case 0x15F0F8u: goto label_15f0f8;
            case 0x15F120u: goto label_15f120;
            case 0x15F140u: goto label_15f140;
            case 0x15F174u: goto label_15f174;
            case 0x15F17Cu: goto label_15f17c;
            case 0x15F188u: goto label_15f188;
            case 0x15F198u: goto label_15f198;
            case 0x15F1E4u: goto label_15f1e4;
            case 0x15F210u: goto label_15f210;
            case 0x15F218u: goto label_15f218;
            case 0x15F22Cu: goto label_15f22c;
            case 0x15F238u: goto label_15f238;
            case 0x15F250u: goto label_15f250;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15F22Cu; }
            if (ctx->pc != 0x15F22Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15F22Cu;
label_15f22c:
    // 0x15f22c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15f22cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f230: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x15F230u;
    SET_GPR_U32(ctx, 31, 0x15F238u);
    ctx->pc = 0x15F234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F230u;
            // 0x15f234: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F238u; }
        if (ctx->pc != 0x15F238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F238u; }
        if (ctx->pc != 0x15F238u) { return; }
    }
    ctx->pc = 0x15F238u;
label_15f238:
    // 0x15f238: 0xae110150  sw          $s1, 0x150($s0)
    ctx->pc = 0x15f238u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 336), GPR_U32(ctx, 17));
    // 0x15f23c: 0xae020128  sw          $v0, 0x128($s0)
    ctx->pc = 0x15f23cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
    // 0x15f240: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f240u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f244: 0xae120154  sw          $s2, 0x154($s0)
    ctx->pc = 0x15f244u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 340), GPR_U32(ctx, 18));
    // 0x15f248: 0xc057bee  jal         func_15EFB8
    ctx->pc = 0x15F248u;
    SET_GPR_U32(ctx, 31, 0x15F250u);
    ctx->pc = 0x15F24Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F248u;
            // 0x15f24c: 0xae02014c  sw          $v0, 0x14C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 332), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EFB8u;
    if (runtime->hasFunction(0x15EFB8u)) {
        auto targetFn = runtime->lookupFunction(0x15EFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F250u; }
        if (ctx->pc != 0x15F250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EFB8_0x15efb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F250u; }
        if (ctx->pc != 0x15F250u) { return; }
    }
    ctx->pc = 0x15F250u;
label_15f250:
    // 0x15f250: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f250u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f254: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f254u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f258: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f258u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f25c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f25cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f260: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15f260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f264: 0x8056fea  j           func_15BFA8
    ctx->pc = 0x15F264u;
    ctx->pc = 0x15F268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F264u;
            // 0x15f268: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BFA8u;
    if (runtime->hasFunction(0x15BFA8u)) {
        auto targetFn = runtime->lookupFunction(0x15BFA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BFA8_0x15bfa8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F26Cu;
    // 0x15f26c: 0x0  nop
    ctx->pc = 0x15f26cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
