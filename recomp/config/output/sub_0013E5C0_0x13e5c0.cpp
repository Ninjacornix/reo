#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E5C0
// Address: 0x13e5c0 - 0x13ebd8
void sub_0013E5C0_0x13e5c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E5C0_0x13e5c0");
#endif

    switch (ctx->pc) {
        case 0x13e624u: goto label_13e624;
        case 0x13e674u: goto label_13e674;
        case 0x13e700u: goto label_13e700;
        case 0x13e714u: goto label_13e714;
        case 0x13e720u: goto label_13e720;
        case 0x13e728u: goto label_13e728;
        case 0x13e730u: goto label_13e730;
        case 0x13e738u: goto label_13e738;
        case 0x13e740u: goto label_13e740;
        case 0x13e7b8u: goto label_13e7b8;
        case 0x13e7fcu: goto label_13e7fc;
        case 0x13e810u: goto label_13e810;
        case 0x13e818u: goto label_13e818;
        case 0x13e82cu: goto label_13e82c;
        case 0x13e840u: goto label_13e840;
        case 0x13e854u: goto label_13e854;
        case 0x13e890u: goto label_13e890;
        case 0x13e8c8u: goto label_13e8c8;
        case 0x13e8dcu: goto label_13e8dc;
        case 0x13e900u: goto label_13e900;
        case 0x13e91cu: goto label_13e91c;
        case 0x13e938u: goto label_13e938;
        case 0x13e950u: goto label_13e950;
        case 0x13e964u: goto label_13e964;
        case 0x13e988u: goto label_13e988;
        case 0x13e99cu: goto label_13e99c;
        case 0x13e9d0u: goto label_13e9d0;
        case 0x13ea28u: goto label_13ea28;
        case 0x13ea68u: goto label_13ea68;
        case 0x13ea80u: goto label_13ea80;
        case 0x13eaf0u: goto label_13eaf0;
        case 0x13eb00u: goto label_13eb00;
        case 0x13eb34u: goto label_13eb34;
        case 0x13eb48u: goto label_13eb48;
        case 0x13eb58u: goto label_13eb58;
        case 0x13ebc0u: goto label_13ebc0;
        default: break;
    }

    ctx->pc = 0x13e5c0u;

label_13e5c0:
    // 0x13e5c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13e5c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13e5c4: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x13e5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x13e5c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13e5c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13e5cc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e5ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5d0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e5d0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5d4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e5d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13e5d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e5dc: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x13e5dcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e5e0: 0x804e518  j           func_139460
    ctx->pc = 0x13E5E0u;
    ctx->pc = 0x13E5E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E5E0u;
            // 0x13e5e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13E5E8u;
    // 0x13e5e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13e5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13e5ec: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13e5ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13e5f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e5f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e5f4: 0x24701468  addiu       $s0, $v1, 0x1468
    ctx->pc = 0x13e5f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 5224));
    // 0x13e5f8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13e5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e5fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13e5fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13e600: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x13e600u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e604: 0x10510008  beq         $v0, $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13E604u;
    {
        const bool branch_taken_0x13e604 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x13E608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E604u;
            // 0x13e608: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e604) {
            ctx->pc = 0x13E628u;
            goto label_13e628;
        }
    }
    ctx->pc = 0x13E60Cu;
    // 0x13e60c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x13e60cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x13e610: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e614: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e614u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e618: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e618u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e61c: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E61Cu;
    SET_GPR_U32(ctx, 31, 0x13E624u);
    ctx->pc = 0x13E620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E61Cu;
            // 0x13e620: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E624u; }
        if (ctx->pc != 0x13E624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E624u; }
        if (ctx->pc != 0x13E624u) { return; }
    }
    ctx->pc = 0x13E624u;
label_13e624:
    // 0x13e624: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x13e624u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
label_13e628:
    // 0x13e628: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e628u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e62c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e62cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e630: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e630u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e634: 0x3e00008  jr          $ra
    ctx->pc = 0x13E634u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E634u;
            // 0x13e638: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E63Cu;
    // 0x13e63c: 0x0  nop
    ctx->pc = 0x13e63cu;
    // NOP
    // 0x13e640: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13e640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13e644: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e644u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e648: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e64c: 0x24501468  addiu       $s0, $v0, 0x1468
    ctx->pc = 0x13e64cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 5224));
    // 0x13e650: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x13e650u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e654: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13E654u;
    {
        const bool branch_taken_0x13e654 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E654u;
            // 0x13e658: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e654) {
            ctx->pc = 0x13E678u;
            goto label_13e678;
        }
    }
    ctx->pc = 0x13E65Cu;
    // 0x13e65c: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x13e65cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13e660: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e664: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e664u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e668: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e668u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e66c: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E66Cu;
    SET_GPR_U32(ctx, 31, 0x13E674u);
    ctx->pc = 0x13E670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E66Cu;
            // 0x13e670: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E674u; }
        if (ctx->pc != 0x13E674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E674u; }
        if (ctx->pc != 0x13E674u) { return; }
    }
    ctx->pc = 0x13E674u;
label_13e674:
    // 0x13e674: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13e674u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_13e678:
    // 0x13e678: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e678u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e67c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13e67cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e680: 0x3e00008  jr          $ra
    ctx->pc = 0x13E680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E680u;
            // 0x13e684: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E688u;
    // 0x13e688: 0x8c820048  lw          $v0, 0x48($a0)
    ctx->pc = 0x13e688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x13e68c: 0x10450009  beq         $v0, $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x13E68Cu;
    {
        const bool branch_taken_0x13e68c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13E690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E68Cu;
            // 0x13e690: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e68c) {
            ctx->pc = 0x13E6B4u;
            goto label_13e6b4;
        }
    }
    ctx->pc = 0x13E694u;
    // 0x13e694: 0x8c431468  lw          $v1, 0x1468($v0)
    ctx->pc = 0x13e694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5224)));
    // 0x13e698: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13E698u;
    {
        const bool branch_taken_0x13e698 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E698u;
            // 0x13e69c: 0x51600  sll         $v0, $a1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e698) {
            ctx->pc = 0x13E6ACu;
            goto label_13e6ac;
        }
    }
    ctx->pc = 0x13E6A0u;
    // 0x13e6a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13e6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e6a4: 0x10a20003  beq         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13E6A4u;
    {
        const bool branch_taken_0x13e6a4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E6A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E6A4u;
            // 0x13e6a8: 0x51600  sll         $v0, $a1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e6a4) {
            ctx->pc = 0x13E6B4u;
            goto label_13e6b4;
        }
    }
    ctx->pc = 0x13E6ACu;
label_13e6ac:
    // 0x13e6ac: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x13e6acu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13e6b0: 0xac820048  sw          $v0, 0x48($a0)
    ctx->pc = 0x13e6b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 2));
label_13e6b4:
    // 0x13e6b4: 0x3e00008  jr          $ra
    ctx->pc = 0x13E6B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E6BCu;
    // 0x13e6bc: 0x0  nop
    ctx->pc = 0x13e6bcu;
    // NOP
    // 0x13e6c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13e6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13e6c4: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13e6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13e6c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e6cc: 0x2463146c  addiu       $v1, $v1, 0x146C
    ctx->pc = 0x13e6ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5228));
    // 0x13e6d0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13e6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13e6d4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13e6d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13e6d8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13e6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13e6dc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x13e6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x13e6e0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x13E6E0u;
    {
        const bool branch_taken_0x13e6e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E6E0u;
            // 0x13e6e4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e6e0) {
            ctx->pc = 0x13E758u;
            goto label_13e758;
        }
    }
    ctx->pc = 0x13E6E8u;
    // 0x13e6e8: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13e6e8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13e6ec: 0x3c110022  lui         $s1, 0x22
    ctx->pc = 0x13e6ecu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)34 << 16));
    // 0x13e6f0: 0x26101454  addiu       $s0, $s0, 0x1454
    ctx->pc = 0x13e6f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5204));
    // 0x13e6f4: 0x26313e80  addiu       $s1, $s1, 0x3E80
    ctx->pc = 0x13e6f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16000));
    // 0x13e6f8: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x13E6F8u;
    SET_GPR_U32(ctx, 31, 0x13E700u);
    ctx->pc = 0x13E6FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E6F8u;
            // 0x13e6fc: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E700u; }
        if (ctx->pc != 0x13E700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E700u; }
        if (ctx->pc != 0x13E700u) { return; }
    }
    ctx->pc = 0x13E700u;
label_13e700:
    // 0x13e700: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13e700u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13e704: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13e704u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13e708: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x13e708u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13e70c: 0xc04e444  jal         func_139110
    ctx->pc = 0x13E70Cu;
    SET_GPR_U32(ctx, 31, 0x13E714u);
    ctx->pc = 0x13E710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E70Cu;
            // 0x13e710: 0x26101474  addiu       $s0, $s0, 0x1474 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5236));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139110u;
    if (runtime->hasFunction(0x139110u)) {
        auto targetFn = runtime->lookupFunction(0x139110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E714u; }
        if (ctx->pc != 0x13E714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139110_0x139110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E714u; }
        if (ctx->pc != 0x13E714u) { return; }
    }
    ctx->pc = 0x13E714u;
label_13e714:
    // 0x13e714: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13e714u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13e718: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x13E718u;
    SET_GPR_U32(ctx, 31, 0x13E720u);
    ctx->pc = 0x13E71Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E718u;
            // 0x13e71c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E720u; }
        if (ctx->pc != 0x13E720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E720u; }
        if (ctx->pc != 0x13E720u) { return; }
    }
    ctx->pc = 0x13E720u;
label_13e720:
    // 0x13e720: 0xc04f790  jal         func_13DE40
    ctx->pc = 0x13E720u;
    SET_GPR_U32(ctx, 31, 0x13E728u);
    ctx->pc = 0x13E724u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E720u;
            // 0x13e724: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13DE40u;
    if (runtime->hasFunction(0x13DE40u)) {
        auto targetFn = runtime->lookupFunction(0x13DE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E728u; }
        if (ctx->pc != 0x13E728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DE40_0x13de40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E728u; }
        if (ctx->pc != 0x13E728u) { return; }
    }
    ctx->pc = 0x13E728u;
label_13e728:
    // 0x13e728: 0xc04f970  jal         func_13E5C0
    ctx->pc = 0x13E728u;
    SET_GPR_U32(ctx, 31, 0x13E730u);
    ctx->pc = 0x13E5C0u;
    goto label_13e5c0;
    ctx->pc = 0x13E730u;
label_13e730:
    // 0x13e730: 0xc04e4fa  jal         func_1393E8
    ctx->pc = 0x13E730u;
    SET_GPR_U32(ctx, 31, 0x13E738u);
    ctx->pc = 0x1393E8u;
    if (runtime->hasFunction(0x1393E8u)) {
        auto targetFn = runtime->lookupFunction(0x1393E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E738u; }
        if (ctx->pc != 0x13E738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001393E8_0x1393e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E738u; }
        if (ctx->pc != 0x13E738u) { return; }
    }
    ctx->pc = 0x13E738u;
label_13e738:
    // 0x13e738: 0xc050506  jal         func_141418
    ctx->pc = 0x13E738u;
    SET_GPR_U32(ctx, 31, 0x13E740u);
    ctx->pc = 0x141418u;
    if (runtime->hasFunction(0x141418u)) {
        auto targetFn = runtime->lookupFunction(0x141418u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E740u; }
        if (ctx->pc != 0x13E740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141418_0x141418(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E740u; }
        if (ctx->pc != 0x13E740u) { return; }
    }
    ctx->pc = 0x13E740u;
label_13e740:
    // 0x13e740: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e740u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e744: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e744u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e748: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e748u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e74c: 0x80503b6  j           func_140ED8
    ctx->pc = 0x13E74Cu;
    ctx->pc = 0x13E750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E74Cu;
            // 0x13e750: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140ED8u;
    if (runtime->hasFunction(0x140ED8u)) {
        auto targetFn = runtime->lookupFunction(0x140ED8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00140ED8_0x140ed8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13E754u;
    // 0x13e754: 0x0  nop
    ctx->pc = 0x13e754u;
    // NOP
label_13e758:
    // 0x13e758: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e758u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e75c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e75cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e760: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e760u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e764: 0x3e00008  jr          $ra
    ctx->pc = 0x13E764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E764u;
            // 0x13e768: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E76Cu;
    // 0x13e76c: 0x0  nop
    ctx->pc = 0x13e76cu;
    // NOP
    // 0x13e770: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x13e770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x13e774: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e774u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e778: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x13e778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x13e77c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x13e77cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e780: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x13e780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x13e784: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13e784u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e788: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x13e788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x13e78c: 0x24533880  addiu       $s3, $v0, 0x3880
    ctx->pc = 0x13e78cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 14464));
    // 0x13e790: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x13e790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x13e794: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x13e794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x13e798: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x13e798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x13e79c: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x13e79cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x13e7a0: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x13e7a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x13e7a4: 0x82620000  lb          $v0, 0x0($s3)
    ctx->pc = 0x13e7a4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x13e7a8: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13E7A8u;
    {
        const bool branch_taken_0x13e7a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E7A8u;
            // 0x13e7ac: 0x80a82d  daddu       $s5, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e7a8) {
            ctx->pc = 0x13E7DCu;
            goto label_13e7dc;
        }
    }
    ctx->pc = 0x13E7B0u;
    // 0x13e7b0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13e7b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e7b4: 0x260182d  daddu       $v1, $s3, $zero
    ctx->pc = 0x13e7b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_13e7b8:
    // 0x13e7b8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x13e7b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13e7bc: 0x24840060  addiu       $a0, $a0, 0x60
    ctx->pc = 0x13e7bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 96));
    // 0x13e7c0: 0x2a220010  slti        $v0, $s1, 0x10
    ctx->pc = 0x13e7c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13e7c4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13E7C4u;
    {
        const bool branch_taken_0x13e7c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E7C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E7C4u;
            // 0x13e7c8: 0x24630060  addiu       $v1, $v1, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e7c4) {
            ctx->pc = 0x13E7DCu;
            goto label_13e7dc;
        }
    }
    ctx->pc = 0x13E7CCu;
    // 0x13e7cc: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x13e7ccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13e7d0: 0x0  nop
    ctx->pc = 0x13e7d0u;
    // NOP
    // 0x13e7d4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13E7D4u;
    {
        const bool branch_taken_0x13e7d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E7D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E7D4u;
            // 0x13e7d8: 0x60982d  daddu       $s3, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e7d4) {
            ctx->pc = 0x13E7B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e7b8;
        }
    }
    ctx->pc = 0x13E7DCu;
label_13e7dc:
    // 0x13e7dc: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x13e7dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13e7e0: 0x122300ad  beq         $s1, $v1, . + 4 + (0xAD << 2)
    ctx->pc = 0x13E7E0u;
    {
        const bool branch_taken_0x13e7e0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x13E7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E7E0u;
            // 0x13e7e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e7e0) {
            ctx->pc = 0x13EA98u;
            goto label_13ea98;
        }
    }
    ctx->pc = 0x13E7E8u;
    // 0x13e7e8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x13e7e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e7ec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e7ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e7f0: 0x24060060  addiu       $a2, $zero, 0x60
    ctx->pc = 0x13e7f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x13e7f4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13E7F4u;
    SET_GPR_U32(ctx, 31, 0x13E7FCu);
    ctx->pc = 0x13E7F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E7F4u;
            // 0x13e7f8: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E7FCu; }
        if (ctx->pc != 0x13E7FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E7FCu; }
        if (ctx->pc != 0x13E7FCu) { return; }
    }
    ctx->pc = 0x13E7FCu;
label_13e7fc:
    // 0x13e7fc: 0x1a40001e  blez        $s2, . + 4 + (0x1E << 2)
    ctx->pc = 0x13E7FCu;
    {
        const bool branch_taken_0x13e7fc = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13E800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E7FCu;
            // 0x13e800: 0xae720004  sw          $s2, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e7fc) {
            ctx->pc = 0x13E878u;
            goto label_13e878;
        }
    }
    ctx->pc = 0x13E804u;
    // 0x13e804: 0x26740008  addiu       $s4, $s3, 0x8
    ctx->pc = 0x13e804u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x13e808: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x13e808u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x13e80c: 0x280802d  daddu       $s0, $s4, $zero
    ctx->pc = 0x13e80cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_13e810:
    // 0x13e810: 0xc04f7c8  jal         func_13DF20
    ctx->pc = 0x13E810u;
    SET_GPR_U32(ctx, 31, 0x13E818u);
    ctx->pc = 0x13DF20u;
    if (runtime->hasFunction(0x13DF20u)) {
        auto targetFn = runtime->lookupFunction(0x13DF20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E818u; }
        if (ctx->pc != 0x13E818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DF20_0x13df20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E818u; }
        if (ctx->pc != 0x13E818u) { return; }
    }
    ctx->pc = 0x13E818u;
label_13e818:
    // 0x13e818: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x13e818u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x13e81c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x13E81Cu;
    {
        const bool branch_taken_0x13e81c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E81Cu;
            // 0x13e820: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e81c) {
            ctx->pc = 0x13E868u;
            goto label_13e868;
        }
    }
    ctx->pc = 0x13E824u;
    // 0x13e824: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E824u;
    SET_GPR_U32(ctx, 31, 0x13E82Cu);
    ctx->pc = 0x13E828u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E824u;
            // 0x13e828: 0x26c4d7b0  addiu       $a0, $s6, -0x2850 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294956976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E82Cu; }
        if (ctx->pc != 0x13E82Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E82Cu; }
        if (ctx->pc != 0x13E82Cu) { return; }
    }
    ctx->pc = 0x13E82Cu;
label_13e82c:
    // 0x13e82c: 0x1a40009a  blez        $s2, . + 4 + (0x9A << 2)
    ctx->pc = 0x13E82Cu;
    {
        const bool branch_taken_0x13e82c = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13E830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E82Cu;
            // 0x13e830: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e82c) {
            ctx->pc = 0x13EA98u;
            goto label_13ea98;
        }
    }
    ctx->pc = 0x13E834u;
    // 0x13e834: 0x280882d  daddu       $s1, $s4, $zero
    ctx->pc = 0x13e834u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e838: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x13e838u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e83c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x13e83cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_13e840:
    // 0x13e840: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x13e840u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x13e844: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13E844u;
    {
        const bool branch_taken_0x13e844 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E844u;
            // 0x13e848: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e844) {
            ctx->pc = 0x13E854u;
            goto label_13e854;
        }
    }
    ctx->pc = 0x13E84Cu;
    // 0x13e84c: 0xc04f7e6  jal         func_13DF98
    ctx->pc = 0x13E84Cu;
    SET_GPR_U32(ctx, 31, 0x13E854u);
    ctx->pc = 0x13DF98u;
    if (runtime->hasFunction(0x13DF98u)) {
        auto targetFn = runtime->lookupFunction(0x13DF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E854u; }
        if (ctx->pc != 0x13E854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DF98_0x13df98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E854u; }
        if (ctx->pc != 0x13E854u) { return; }
    }
    ctx->pc = 0x13E854u;
label_13e854:
    // 0x13e854: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x13e854u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x13e858: 0x5600fff9  bnel        $s0, $zero, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13E858u;
    {
        const bool branch_taken_0x13e858 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x13e858) {
            ctx->pc = 0x13E85Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E858u;
            // 0x13e85c: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e840;
        }
    }
    ctx->pc = 0x13E860u;
    // 0x13e860: 0x1000008d  b           . + 4 + (0x8D << 2)
    ctx->pc = 0x13E860u;
    {
        const bool branch_taken_0x13e860 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E860u;
            // 0x13e864: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e860) {
            ctx->pc = 0x13EA98u;
            goto label_13ea98;
        }
    }
    ctx->pc = 0x13E868u;
label_13e868:
    // 0x13e868: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x13e868u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13e86c: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x13e86cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13e870: 0x1440ffe7  bnez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x13E870u;
    {
        const bool branch_taken_0x13e870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13e870) {
            ctx->pc = 0x13E810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e810;
        }
    }
    ctx->pc = 0x13E878u;
label_13e878:
    // 0x13e878: 0xafb20000  sw          $s2, 0x0($sp)
    ctx->pc = 0x13e878u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 18));
    // 0x13e87c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x13e87cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e880: 0x1a40000b  blez        $s2, . + 4 + (0xB << 2)
    ctx->pc = 0x13E880u;
    {
        const bool branch_taken_0x13e880 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13E884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E880u;
            // 0x13e884: 0xafa00004  sw          $zero, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e880) {
            ctx->pc = 0x13E8B0u;
            goto label_13e8b0;
        }
    }
    ctx->pc = 0x13E888u;
    // 0x13e888: 0x27a60008  addiu       $a2, $sp, 0x8
    ctx->pc = 0x13e888u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x13e88c: 0x26650008  addiu       $a1, $s3, 0x8
    ctx->pc = 0x13e88cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
label_13e890:
    // 0x13e890: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x13e890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e894: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x13e894u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x13e898: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x13e898u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13e89c: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x13e89cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x13e8a0: 0x232202a  slt         $a0, $s1, $s2
    ctx->pc = 0x13e8a0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13e8a4: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x13e8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x13e8a8: 0x1480fff9  bnez        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13E8A8u;
    {
        const bool branch_taken_0x13e8a8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E8ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E8A8u;
            // 0x13e8ac: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e8a8) {
            ctx->pc = 0x13E890u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e890;
        }
    }
    ctx->pc = 0x13E8B0u;
label_13e8b0:
    // 0x13e8b0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x13e8b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x13e8b4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13e8b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e8b8: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x13e8b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x13e8bc: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x13e8bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x13e8c0: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E8C0u;
    SET_GPR_U32(ctx, 31, 0x13E8C8u);
    ctx->pc = 0x13E8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E8C0u;
            // 0x13e8c4: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E8C8u; }
        if (ctx->pc != 0x13E8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E8C8u; }
        if (ctx->pc != 0x13E8C8u) { return; }
    }
    ctx->pc = 0x13E8C8u;
label_13e8c8:
    // 0x13e8c8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13E8C8u;
    {
        const bool branch_taken_0x13e8c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E8CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E8C8u;
            // 0x13e8cc: 0xae620020  sw          $v0, 0x20($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e8c8) {
            ctx->pc = 0x13E8E8u;
            goto label_13e8e8;
        }
    }
    ctx->pc = 0x13E8D0u;
    // 0x13e8d0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13e8d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13e8d4: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E8D4u;
    SET_GPR_U32(ctx, 31, 0x13E8DCu);
    ctx->pc = 0x13E8D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E8D4u;
            // 0x13e8d8: 0x2484d7d8  addiu       $a0, $a0, -0x2828 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957016));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E8DCu; }
        if (ctx->pc != 0x13E8DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E8DCu; }
        if (ctx->pc != 0x13E8DCu) { return; }
    }
    ctx->pc = 0x13E8DCu;
label_13e8dc:
    // 0x13e8dc: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x13E8DCu;
    {
        const bool branch_taken_0x13e8dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E8E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E8DCu;
            // 0x13e8e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e8dc) {
            ctx->pc = 0x13EA98u;
            goto label_13ea98;
        }
    }
    ctx->pc = 0x13E8E4u;
    // 0x13e8e4: 0x0  nop
    ctx->pc = 0x13e8e4u;
    // NOP
label_13e8e8:
    // 0x13e8e8: 0x1a400035  blez        $s2, . + 4 + (0x35 << 2)
    ctx->pc = 0x13E8E8u;
    {
        const bool branch_taken_0x13e8e8 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13E8ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E8E8u;
            // 0x13e8ec: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e8e8) {
            ctx->pc = 0x13E9C0u;
            goto label_13e9c0;
        }
    }
    ctx->pc = 0x13E8F0u;
    // 0x13e8f0: 0x26740008  addiu       $s4, $s3, 0x8
    ctx->pc = 0x13e8f0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x13e8f4: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x13e8f4u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x13e8f8: 0x26700010  addiu       $s0, $s3, 0x10
    ctx->pc = 0x13e8f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x13e8fc: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x13e8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_13e900:
    // 0x13e900: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x13e900u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13e904: 0x2821821  addu        $v1, $s4, $v0
    ctx->pc = 0x13e904u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x13e908: 0x551021  addu        $v0, $v0, $s5
    ctx->pc = 0x13e908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
    // 0x13e90c: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x13e90cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13e910: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x13e910u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13e914: 0xc04e2ae  jal         func_138AB8
    ctx->pc = 0x13E914u;
    SET_GPR_U32(ctx, 31, 0x13E91Cu);
    ctx->pc = 0x13E918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E914u;
            // 0x13e918: 0x8cc50008  lw          $a1, 0x8($a2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138AB8u;
    if (runtime->hasFunction(0x138AB8u)) {
        auto targetFn = runtime->lookupFunction(0x138AB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E91Cu; }
        if (ctx->pc != 0x13E91Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138AB8_0x138ab8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E91Cu; }
        if (ctx->pc != 0x13E91Cu) { return; }
    }
    ctx->pc = 0x13E91Cu;
label_13e91c:
    // 0x13e91c: 0x232182a  slt         $v1, $s1, $s2
    ctx->pc = 0x13e91cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13e920: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x13e920u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x13e924: 0x14400024  bnez        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x13E924u;
    {
        const bool branch_taken_0x13e924 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E924u;
            // 0x13e928: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e924) {
            ctx->pc = 0x13E9B8u;
            goto label_13e9b8;
        }
    }
    ctx->pc = 0x13E92Cu;
    // 0x13e92c: 0x26c4d800  addiu       $a0, $s6, -0x2800
    ctx->pc = 0x13e92cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294957056));
    // 0x13e930: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E930u;
    SET_GPR_U32(ctx, 31, 0x13E938u);
    ctx->pc = 0x13E934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E930u;
            // 0x13e934: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E938u; }
        if (ctx->pc != 0x13E938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E938u; }
        if (ctx->pc != 0x13E938u) { return; }
    }
    ctx->pc = 0x13E938u;
label_13e938:
    // 0x13e938: 0x1a400057  blez        $s2, . + 4 + (0x57 << 2)
    ctx->pc = 0x13E938u;
    {
        const bool branch_taken_0x13e938 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13E93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E938u;
            // 0x13e93c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e938) {
            ctx->pc = 0x13EA98u;
            goto label_13ea98;
        }
    }
    ctx->pc = 0x13E940u;
    // 0x13e940: 0x280882d  daddu       $s1, $s4, $zero
    ctx->pc = 0x13e940u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e944: 0x26700010  addiu       $s0, $s3, 0x10
    ctx->pc = 0x13e944u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x13e948: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13e948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e94c: 0x0  nop
    ctx->pc = 0x13e94cu;
    // NOP
label_13e950:
    // 0x13e950: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x13e950u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x13e954: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13E954u;
    {
        const bool branch_taken_0x13e954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E954u;
            // 0x13e958: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e954) {
            ctx->pc = 0x13E964u;
            goto label_13e964;
        }
    }
    ctx->pc = 0x13E95Cu;
    // 0x13e95c: 0xc04e2ea  jal         func_138BA8
    ctx->pc = 0x13E95Cu;
    SET_GPR_U32(ctx, 31, 0x13E964u);
    ctx->pc = 0x138BA8u;
    if (runtime->hasFunction(0x138BA8u)) {
        auto targetFn = runtime->lookupFunction(0x138BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E964u; }
        if (ctx->pc != 0x13E964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138BA8_0x138ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E964u; }
        if (ctx->pc != 0x13E964u) { return; }
    }
    ctx->pc = 0x13E964u;
label_13e964:
    // 0x13e964: 0x8e620020  lw          $v0, 0x20($s3)
    ctx->pc = 0x13e964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x13e968: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13E968u;
    {
        const bool branch_taken_0x13e968 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E968u;
            // 0x13e96c: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e968) {
            ctx->pc = 0x13E988u;
            goto label_13e988;
        }
    }
    ctx->pc = 0x13E970u;
    // 0x13e970: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13e970u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e974: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x13e974u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e978: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e978u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e97c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x13e97cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e980: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E980u;
    SET_GPR_U32(ctx, 31, 0x13E988u);
    ctx->pc = 0x13E984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E980u;
            // 0x13e984: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E988u; }
        if (ctx->pc != 0x13E988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E988u; }
        if (ctx->pc != 0x13E988u) { return; }
    }
    ctx->pc = 0x13E988u;
label_13e988:
    // 0x13e988: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x13e988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13e98c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13E98Cu;
    {
        const bool branch_taken_0x13e98c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E98Cu;
            // 0x13e990: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e98c) {
            ctx->pc = 0x13E99Cu;
            goto label_13e99c;
        }
    }
    ctx->pc = 0x13E994u;
    // 0x13e994: 0xc04f7e6  jal         func_13DF98
    ctx->pc = 0x13E994u;
    SET_GPR_U32(ctx, 31, 0x13E99Cu);
    ctx->pc = 0x13DF98u;
    if (runtime->hasFunction(0x13DF98u)) {
        auto targetFn = runtime->lookupFunction(0x13DF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E99Cu; }
        if (ctx->pc != 0x13E99Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DF98_0x13df98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E99Cu; }
        if (ctx->pc != 0x13E99Cu) { return; }
    }
    ctx->pc = 0x13E99Cu;
label_13e99c:
    // 0x13e99c: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x13e99cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x13e9a0: 0x2b2102a  slt         $v0, $s5, $s2
    ctx->pc = 0x13e9a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13e9a4: 0x5440ffea  bnel        $v0, $zero, . + 4 + (-0x16 << 2)
    ctx->pc = 0x13E9A4u;
    {
        const bool branch_taken_0x13e9a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13e9a4) {
            ctx->pc = 0x13E9A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E9A4u;
            // 0x13e9a8: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E950u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e950;
        }
    }
    ctx->pc = 0x13E9ACu;
    // 0x13e9ac: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x13E9ACu;
    {
        const bool branch_taken_0x13e9ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E9B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E9ACu;
            // 0x13e9b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e9ac) {
            ctx->pc = 0x13EA98u;
            goto label_13ea98;
        }
    }
    ctx->pc = 0x13E9B4u;
    // 0x13e9b4: 0x0  nop
    ctx->pc = 0x13e9b4u;
    // NOP
label_13e9b8:
    // 0x13e9b8: 0x1460ffd1  bnez        $v1, . + 4 + (-0x2F << 2)
    ctx->pc = 0x13E9B8u;
    {
        const bool branch_taken_0x13e9b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E9B8u;
            // 0x13e9bc: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e9b8) {
            ctx->pc = 0x13E900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e900;
        }
    }
    ctx->pc = 0x13E9C0u;
label_13e9c0:
    // 0x13e9c0: 0x1a40000a  blez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x13E9C0u;
    {
        const bool branch_taken_0x13e9c0 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13E9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E9C0u;
            // 0x13e9c4: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e9c0) {
            ctx->pc = 0x13E9ECu;
            goto label_13e9ec;
        }
    }
    ctx->pc = 0x13E9C8u;
    // 0x13e9c8: 0x26650018  addiu       $a1, $s3, 0x18
    ctx->pc = 0x13e9c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 24));
    // 0x13e9cc: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x13e9ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_13e9d0:
    // 0x13e9d0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13e9d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13e9d4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x13e9d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x13e9d8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x13e9d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13e9dc: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x13e9dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13e9e0: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x13e9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x13e9e4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13E9E4u;
    {
        const bool branch_taken_0x13e9e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E9E4u;
            // 0x13e9e8: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e9e4) {
            ctx->pc = 0x13E9D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e9d0;
        }
    }
    ctx->pc = 0x13E9ECu;
label_13e9ec:
    // 0x13e9ec: 0xa2600024  sb          $zero, 0x24($s3)
    ctx->pc = 0x13e9ecu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 36), (uint8_t)GPR_U32(ctx, 0));
    // 0x13e9f0: 0xa2600025  sb          $zero, 0x25($s3)
    ctx->pc = 0x13e9f0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 37), (uint8_t)GPR_U32(ctx, 0));
    // 0x13e9f4: 0xa2720026  sb          $s2, 0x26($s3)
    ctx->pc = 0x13e9f4u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 38), (uint8_t)GPR_U32(ctx, 18));
    // 0x13e9f8: 0xa2720027  sb          $s2, 0x27($s3)
    ctx->pc = 0x13e9f8u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 39), (uint8_t)GPR_U32(ctx, 18));
    // 0x13e9fc: 0xae600030  sw          $zero, 0x30($s3)
    ctx->pc = 0x13e9fcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 48), GPR_U32(ctx, 0));
    // 0x13ea00: 0xae600034  sw          $zero, 0x34($s3)
    ctx->pc = 0x13ea00u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 52), GPR_U32(ctx, 0));
    // 0x13ea04: 0xae600048  sw          $zero, 0x48($s3)
    ctx->pc = 0x13ea04u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 72), GPR_U32(ctx, 0));
    // 0x13ea08: 0xae60004c  sw          $zero, 0x4C($s3)
    ctx->pc = 0x13ea08u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 76), GPR_U32(ctx, 0));
    // 0x13ea0c: 0xa2600053  sb          $zero, 0x53($s3)
    ctx->pc = 0x13ea0cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 83), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ea10: 0x1a40000c  blez        $s2, . + 4 + (0xC << 2)
    ctx->pc = 0x13EA10u;
    {
        const bool branch_taken_0x13ea10 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13EA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EA10u;
            // 0x13ea14: 0xa2600052  sb          $zero, 0x52($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 82), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ea10) {
            ctx->pc = 0x13EA44u;
            goto label_13ea44;
        }
    }
    ctx->pc = 0x13EA18u;
    // 0x13ea18: 0x240882d  daddu       $s1, $s2, $zero
    ctx->pc = 0x13ea18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ea1c: 0x26630040  addiu       $v1, $s3, 0x40
    ctx->pc = 0x13ea1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x13ea20: 0x26620038  addiu       $v0, $s3, 0x38
    ctx->pc = 0x13ea20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 56));
    // 0x13ea24: 0x0  nop
    ctx->pc = 0x13ea24u;
    // NOP
label_13ea28:
    // 0x13ea28: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13ea28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x13ea2c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x13ea2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x13ea30: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x13ea30u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x13ea34: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x13ea34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x13ea38: 0x0  nop
    ctx->pc = 0x13ea38u;
    // NOP
    // 0x13ea3c: 0x1620fffa  bnez        $s1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13EA3Cu;
    {
        const bool branch_taken_0x13ea3c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13EA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EA3Cu;
            // 0x13ea40: 0x24420004  addiu       $v0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ea3c) {
            ctx->pc = 0x13EA28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ea28;
        }
    }
    ctx->pc = 0x13EA44u;
label_13ea44:
    // 0x13ea44: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x13ea44u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13ea48: 0xa2600050  sb          $zero, 0x50($s3)
    ctx->pc = 0x13ea48u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 80), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ea4c: 0xa2710051  sb          $s1, 0x51($s3)
    ctx->pc = 0x13ea4cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 81), (uint8_t)GPR_U32(ctx, 17));
    // 0x13ea50: 0xae600054  sw          $zero, 0x54($s3)
    ctx->pc = 0x13ea50u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 84), GPR_U32(ctx, 0));
    // 0x13ea54: 0x8ea40000  lw          $a0, 0x0($s5)
    ctx->pc = 0x13ea54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x13ea58: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ea58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ea5c: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ea5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ea60: 0x40f809  jalr        $v0
    ctx->pc = 0x13EA60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EA68u);
        ctx->pc = 0x13EA64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EA60u;
            // 0x13ea64: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EA68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EA68u; }
            if (ctx->pc != 0x13EA68u) { return; }
        }
        }
    }
    ctx->pc = 0x13EA68u;
label_13ea68:
    // 0x13ea68: 0x8ea40000  lw          $a0, 0x0($s5)
    ctx->pc = 0x13ea68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x13ea6c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13ea6cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ea70: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ea70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ea74: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ea74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ea78: 0x40f809  jalr        $v0
    ctx->pc = 0x13EA78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EA80u);
        ctx->pc = 0x13EA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EA78u;
            // 0x13ea7c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EA80u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EA80u; }
            if (ctx->pc != 0x13EA80u) { return; }
        }
        }
    }
    ctx->pc = 0x13EA80u;
label_13ea80:
    // 0x13ea80: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x13ea80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x13ea84: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x13ea84u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13ea88: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x13ea88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ea8c: 0xae700058  sw          $s0, 0x58($s3)
    ctx->pc = 0x13ea8cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 88), GPR_U32(ctx, 16));
    // 0x13ea90: 0xae63005c  sw          $v1, 0x5C($s3)
    ctx->pc = 0x13ea90u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 92), GPR_U32(ctx, 3));
    // 0x13ea94: 0xa2710000  sb          $s1, 0x0($s3)
    ctx->pc = 0x13ea94u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 17));
label_13ea98:
    // 0x13ea98: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x13ea98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ea9c: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x13ea9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13eaa0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x13eaa0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13eaa4: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x13eaa4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13eaa8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x13eaa8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13eaac: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x13eaacu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13eab0: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x13eab0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13eab4: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x13eab4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x13eab8: 0x3e00008  jr          $ra
    ctx->pc = 0x13EAB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EAB8u;
            // 0x13eabc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EAC0u;
    // 0x13eac0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13eac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13eac4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13eac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13eac8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13eac8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eacc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13eaccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13ead0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13ead0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13ead4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13ead4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13ead8: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13ead8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13eadc: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x13EADCu;
    {
        const bool branch_taken_0x13eadc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x13EAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EADCu;
            // 0x13eae0: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eadc) {
            ctx->pc = 0x13EB14u;
            goto label_13eb14;
        }
    }
    ctx->pc = 0x13EAE4u;
    // 0x13eae4: 0x26300010  addiu       $s0, $s1, 0x10
    ctx->pc = 0x13eae4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x13eae8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13eae8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13eaec: 0x0  nop
    ctx->pc = 0x13eaecu;
    // NOP
label_13eaf0:
    // 0x13eaf0: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13EAF0u;
    {
        const bool branch_taken_0x13eaf0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13EAF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EAF0u;
            // 0x13eaf4: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eaf0) {
            ctx->pc = 0x13EB04u;
            goto label_13eb04;
        }
    }
    ctx->pc = 0x13EAF8u;
    // 0x13eaf8: 0xc04e2ea  jal         func_138BA8
    ctx->pc = 0x13EAF8u;
    SET_GPR_U32(ctx, 31, 0x13EB00u);
    ctx->pc = 0x138BA8u;
    if (runtime->hasFunction(0x138BA8u)) {
        auto targetFn = runtime->lookupFunction(0x138BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB00u; }
        if (ctx->pc != 0x13EB00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138BA8_0x138ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB00u; }
        if (ctx->pc != 0x13EB00u) { return; }
    }
    ctx->pc = 0x13EB00u;
label_13eb00:
    // 0x13eb00: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13eb00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_13eb04:
    // 0x13eb04: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13eb04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13eb08: 0x243102a  slt         $v0, $s2, $v1
    ctx->pc = 0x13eb08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x13eb0c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13EB0Cu;
    {
        const bool branch_taken_0x13eb0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13eb0c) {
            ctx->pc = 0x13EB10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB0Cu;
            // 0x13eb10: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EAF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13eaf0;
        }
    }
    ctx->pc = 0x13EB14u;
label_13eb14:
    // 0x13eb14: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x13eb14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13eb18: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x13eb18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x13eb1c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13eb1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eb20: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x13eb20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13eb24: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13eb24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eb28: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x13eb28u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eb2c: 0xc04e518  jal         func_139460
    ctx->pc = 0x13EB2Cu;
    SET_GPR_U32(ctx, 31, 0x13EB34u);
    ctx->pc = 0x13EB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB2Cu;
            // 0x13eb30: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB34u; }
        if (ctx->pc != 0x13EB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB34u; }
        if (ctx->pc != 0x13EB34u) { return; }
    }
    ctx->pc = 0x13EB34u;
label_13eb34:
    // 0x13eb34: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13eb34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13eb38: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x13EB38u;
    {
        const bool branch_taken_0x13eb38 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x13EB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB38u;
            // 0x13eb3c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eb38) {
            ctx->pc = 0x13EB6Cu;
            goto label_13eb6c;
        }
    }
    ctx->pc = 0x13EB40u;
    // 0x13eb40: 0x26300008  addiu       $s0, $s1, 0x8
    ctx->pc = 0x13eb40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x13eb44: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13eb44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13eb48:
    // 0x13eb48: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13EB48u;
    {
        const bool branch_taken_0x13eb48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13EB4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB48u;
            // 0x13eb4c: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eb48) {
            ctx->pc = 0x13EB5Cu;
            goto label_13eb5c;
        }
    }
    ctx->pc = 0x13EB50u;
    // 0x13eb50: 0xc04f7e6  jal         func_13DF98
    ctx->pc = 0x13EB50u;
    SET_GPR_U32(ctx, 31, 0x13EB58u);
    ctx->pc = 0x13DF98u;
    if (runtime->hasFunction(0x13DF98u)) {
        auto targetFn = runtime->lookupFunction(0x13DF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB58u; }
        if (ctx->pc != 0x13EB58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DF98_0x13df98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB58u; }
        if (ctx->pc != 0x13EB58u) { return; }
    }
    ctx->pc = 0x13EB58u;
label_13eb58:
    // 0x13eb58: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13eb58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_13eb5c:
    // 0x13eb5c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13eb5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13eb60: 0x243102a  slt         $v0, $s2, $v1
    ctx->pc = 0x13eb60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x13eb64: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13EB64u;
    {
        const bool branch_taken_0x13eb64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13eb64) {
            ctx->pc = 0x13EB68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB64u;
            // 0x13eb68: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EB48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13eb48;
        }
    }
    ctx->pc = 0x13EB6Cu;
label_13eb6c:
    // 0x13eb6c: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x13eb6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13eb70: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13eb70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13eb74: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13eb74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13eb78: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13eb78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13eb7c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13eb7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13eb80: 0x3e00008  jr          $ra
    ctx->pc = 0x13EB80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB80u;
            // 0x13eb84: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E5C0u: goto label_13e5c0;
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            case 0x13E6ACu: goto label_13e6ac;
            case 0x13E6B4u: goto label_13e6b4;
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            case 0x13E7B8u: goto label_13e7b8;
            case 0x13E7DCu: goto label_13e7dc;
            case 0x13E7FCu: goto label_13e7fc;
            case 0x13E810u: goto label_13e810;
            case 0x13E818u: goto label_13e818;
            case 0x13E82Cu: goto label_13e82c;
            case 0x13E840u: goto label_13e840;
            case 0x13E854u: goto label_13e854;
            case 0x13E868u: goto label_13e868;
            case 0x13E878u: goto label_13e878;
            case 0x13E890u: goto label_13e890;
            case 0x13E8B0u: goto label_13e8b0;
            case 0x13E8C8u: goto label_13e8c8;
            case 0x13E8DCu: goto label_13e8dc;
            case 0x13E8E8u: goto label_13e8e8;
            case 0x13E900u: goto label_13e900;
            case 0x13E91Cu: goto label_13e91c;
            case 0x13E938u: goto label_13e938;
            case 0x13E950u: goto label_13e950;
            case 0x13E964u: goto label_13e964;
            case 0x13E988u: goto label_13e988;
            case 0x13E99Cu: goto label_13e99c;
            case 0x13E9B8u: goto label_13e9b8;
            case 0x13E9C0u: goto label_13e9c0;
            case 0x13E9D0u: goto label_13e9d0;
            case 0x13E9ECu: goto label_13e9ec;
            case 0x13EA28u: goto label_13ea28;
            case 0x13EA44u: goto label_13ea44;
            case 0x13EA68u: goto label_13ea68;
            case 0x13EA80u: goto label_13ea80;
            case 0x13EA98u: goto label_13ea98;
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            case 0x13EBC0u: goto label_13ebc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EB88u;
    // 0x13eb88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13eb88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13eb8c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13eb8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13eb90: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13eb90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13eb94: 0x2484d828  addiu       $a0, $a0, -0x27D8
    ctx->pc = 0x13eb94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957096));
    // 0x13eb98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13eb98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13eb9c: 0x8045a12  j           func_116848
    ctx->pc = 0x13EB9Cu;
    ctx->pc = 0x13EBA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB9Cu;
            // 0x13eba0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EBA4u;
    // 0x13eba4: 0x0  nop
    ctx->pc = 0x13eba4u;
    // NOP
    // 0x13eba8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13eba8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ebac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ebacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebb0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13ebb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ebb4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x13ebb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x13ebb8: 0xc04faf6  jal         func_13EBD8
    ctx->pc = 0x13EBB8u;
    SET_GPR_U32(ctx, 31, 0x13EBC0u);
    ctx->pc = 0x13EBBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EBB8u;
            // 0x13ebbc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EBD8u;
    if (runtime->hasFunction(0x13EBD8u)) {
        auto targetFn = runtime->lookupFunction(0x13EBD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EBC0u; }
        if (ctx->pc != 0x13EBC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EBD8_0x13ebd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EBC0u; }
        if (ctx->pc != 0x13EBC0u) { return; }
    }
    ctx->pc = 0x13EBC0u;
label_13ebc0:
    // 0x13ebc0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13ebc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ebc4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13ebc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ebc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ebcc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ebccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebd0: 0x804fb14  j           func_13EC50
    ctx->pc = 0x13EBD0u;
    ctx->pc = 0x13EBD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EBD0u;
            // 0x13ebd4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EC50u;
    if (runtime->hasFunction(0x13EC50u)) {
        auto targetFn = runtime->lookupFunction(0x13EC50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EC50_0x13ec50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EBD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
