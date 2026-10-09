#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136FE8
// Address: 0x136fe8 - 0x137310
void sub_00136FE8_0x136fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136FE8_0x136fe8");
#endif

    switch (ctx->pc) {
        case 0x137010u: goto label_137010;
        case 0x13701cu: goto label_13701c;
        case 0x13703cu: goto label_13703c;
        case 0x137090u: goto label_137090;
        case 0x1370c8u: goto label_1370c8;
        case 0x1370f0u: goto label_1370f0;
        case 0x137110u: goto label_137110;
        case 0x13716cu: goto label_13716c;
        case 0x13717cu: goto label_13717c;
        case 0x1371a0u: goto label_1371a0;
        case 0x1371c0u: goto label_1371c0;
        case 0x13721cu: goto label_13721c;
        case 0x137240u: goto label_137240;
        case 0x137264u: goto label_137264;
        case 0x137284u: goto label_137284;
        case 0x1372ccu: goto label_1372cc;
        case 0x1372f8u: goto label_1372f8;
        default: break;
    }

    ctx->pc = 0x136fe8u;

    // 0x136fe8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x136fe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x136fec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x136fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x136ff0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136ff0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ff4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x136ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x136ff8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x136ff8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ffc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x136ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x137000: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x137000u;
    {
        const bool branch_taken_0x137000 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x137004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137000u;
            // 0x137004: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137000) {
            ctx->pc = 0x137014u;
            goto label_137014;
        }
    }
    ctx->pc = 0x137008u;
    // 0x137008: 0xc04d61e  jal         func_135878
    ctx->pc = 0x137008u;
    SET_GPR_U32(ctx, 31, 0x137010u);
    ctx->pc = 0x135878u;
    if (runtime->hasFunction(0x135878u)) {
        auto targetFn = runtime->lookupFunction(0x135878u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137010u; }
        if (ctx->pc != 0x137010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135878_0x135878(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137010u; }
        if (ctx->pc != 0x137010u) { return; }
    }
    ctx->pc = 0x137010u;
label_137010:
    // 0x137010: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x137010u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_137014:
    // 0x137014: 0xc04dbe6  jal         func_136F98
    ctx->pc = 0x137014u;
    SET_GPR_U32(ctx, 31, 0x13701Cu);
    ctx->pc = 0x137018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137014u;
            // 0x137018: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x136F98u;
    if (runtime->hasFunction(0x136F98u)) {
        auto targetFn = runtime->lookupFunction(0x136F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13701Cu; }
        if (ctx->pc != 0x13701Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00136F98_0x136f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13701Cu; }
        if (ctx->pc != 0x13701Cu) { return; }
    }
    ctx->pc = 0x13701Cu;
label_13701c:
    // 0x13701c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x13701cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x137020: 0x24722278  addiu       $s2, $v1, 0x2278
    ctx->pc = 0x137020u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 8824));
    // 0x137024: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x137024u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137028: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x137028u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13702c: 0x1443000e  bne         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x13702Cu;
    {
        const bool branch_taken_0x13702c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x137030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13702Cu;
            // 0x137030: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13702c) {
            ctx->pc = 0x137068u;
            goto label_137068;
        }
    }
    ctx->pc = 0x137034u;
    // 0x137034: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x137034u;
    SET_GPR_U32(ctx, 31, 0x13703Cu);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13703Cu; }
        if (ctx->pc != 0x13703Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13703Cu; }
        if (ctx->pc != 0x13703Cu) { return; }
    }
    ctx->pc = 0x13703Cu;
label_13703c:
    // 0x13703c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13703cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x137040: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x137040u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137044: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137044u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137048: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x137048u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13704c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13704cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137050: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x137050u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137054: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x137054u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137058: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x137058u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13705c: 0x24a5c3d8  addiu       $a1, $a1, -0x3C28
    ctx->pc = 0x13705cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294951896));
    // 0x137060: 0x8042a0c  j           func_10A830
    ctx->pc = 0x137060u;
    ctx->pc = 0x137064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137060u;
            // 0x137064: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010A830_0x10a830(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x137068u;
label_137068:
    // 0x137068: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137068u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13706c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13706cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137070: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x137070u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137074: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x137074u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x137078: 0x3e00008  jr          $ra
    ctx->pc = 0x137078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13707Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137078u;
            // 0x13707c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137080u;
    // 0x137080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137084: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x137084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x137088: 0xc04d558  jal         func_135560
    ctx->pc = 0x137088u;
    SET_GPR_U32(ctx, 31, 0x137090u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137090u; }
        if (ctx->pc != 0x137090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137090u; }
        if (ctx->pc != 0x137090u) { return; }
    }
    ctx->pc = 0x137090u;
label_137090:
    // 0x137090: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137090u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137094: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x137094u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x137098: 0x3e00008  jr          $ra
    ctx->pc = 0x137098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13709Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137098u;
            // 0x13709c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1370A0u;
    // 0x1370a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1370a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1370a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1370a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1370a8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1370a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1370acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1370b0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1370b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370b4: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1370B4u;
    {
        const bool branch_taken_0x1370b4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1370B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370B4u;
            // 0x1370b8: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1370b4) {
            ctx->pc = 0x1370D0u;
            goto label_1370d0;
        }
    }
    ctx->pc = 0x1370BCu;
    // 0x1370bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1370bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1370c0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1370C0u;
    SET_GPR_U32(ctx, 31, 0x1370C8u);
    ctx->pc = 0x1370C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1370C0u;
            // 0x1370c4: 0x2484c3e0  addiu       $a0, $a0, -0x3C20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1370C8u; }
        if (ctx->pc != 0x1370C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1370C8u; }
        if (ctx->pc != 0x1370C8u) { return; }
    }
    ctx->pc = 0x1370C8u;
label_1370c8:
    // 0x1370c8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1370C8u;
    {
        const bool branch_taken_0x1370c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1370CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370C8u;
            // 0x1370cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1370c8) {
            ctx->pc = 0x137124u;
            goto label_137124;
        }
    }
    ctx->pc = 0x1370D0u;
label_1370d0:
    // 0x1370d0: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1370d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1370d4: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1370d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1370d8: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1370D8u;
    {
        const bool branch_taken_0x1370d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1370DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370D8u;
            // 0x1370dc: 0x240500c8  addiu       $a1, $zero, 0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1370d8) {
            ctx->pc = 0x137120u;
            goto label_137120;
        }
    }
    ctx->pc = 0x1370E0u;
    // 0x1370e0: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1370e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1370e4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1370e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370e8: 0x40f809  jalr        $v0
    ctx->pc = 0x1370E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1370F0u);
        ctx->pc = 0x1370ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1370E8u;
            // 0x1370ec: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1370F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1370F0u; }
            if (ctx->pc != 0x1370F0u) { return; }
        }
        }
    }
    ctx->pc = 0x1370F0u;
label_1370f0:
    // 0x1370f0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1370f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1370f4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1370f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1370f8: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1370f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1370fc: 0x8c620060  lw          $v0, 0x60($v1)
    ctx->pc = 0x1370fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 96)));
    // 0x137100: 0x240500c9  addiu       $a1, $zero, 0xC9
    ctx->pc = 0x137100u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 201));
    // 0x137104: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x137104u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137108: 0x40f809  jalr        $v0
    ctx->pc = 0x137108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x137110u);
        ctx->pc = 0x13710Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137108u;
            // 0x13710c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x137110u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x137110u; }
            if (ctx->pc != 0x137110u) { return; }
        }
        }
    }
    ctx->pc = 0x137110u;
label_137110:
    // 0x137110: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x137110u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x137114: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x137114u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x137118: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x137118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x13711c: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x13711cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_137120:
    // 0x137120: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x137120u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_137124:
    // 0x137124: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137124u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137128: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x137128u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13712c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13712cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137130: 0x3e00008  jr          $ra
    ctx->pc = 0x137130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137130u;
            // 0x137134: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137138u;
    // 0x137138: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x137138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x13713c: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x13713cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x137140: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x137140u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137144: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x137144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x137148: 0x27b30130  addiu       $s3, $sp, 0x130
    ctx->pc = 0x137148u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13714c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13714cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137150: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x137150u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137154: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x137154u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137158: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x137158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x13715c: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x13715cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x137160: 0xffbf0280  sd          $ra, 0x280($sp)
    ctx->pc = 0x137160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 31));
    // 0x137164: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x137164u;
    SET_GPR_U32(ctx, 31, 0x13716Cu);
    ctx->pc = 0x137168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137164u;
            // 0x137168: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13716Cu; }
        if (ctx->pc != 0x13716Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13716Cu; }
        if (ctx->pc != 0x13716Cu) { return; }
    }
    ctx->pc = 0x13716Cu;
label_13716c:
    // 0x13716c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13716cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137170: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x137170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137174: 0xc04d622  jal         func_135888
    ctx->pc = 0x137174u;
    SET_GPR_U32(ctx, 31, 0x13717Cu);
    ctx->pc = 0x137178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137174u;
            // 0x137178: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13717Cu; }
        if (ctx->pc != 0x13717Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13717Cu; }
        if (ctx->pc != 0x13717Cu) { return; }
    }
    ctx->pc = 0x13717Cu;
label_13717c:
    // 0x13717c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13717cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137180: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x137180u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137184: 0x240500ca  addiu       $a1, $zero, 0xCA
    ctx->pc = 0x137184u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 202));
    // 0x137188: 0x8e420060  lw          $v0, 0x60($s2)
    ctx->pc = 0x137188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x13718c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x13718cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137190: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x137190u;
    {
        const bool branch_taken_0x137190 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x137194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137190u;
            // 0x137194: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137190) {
            ctx->pc = 0x1371CCu;
            goto label_1371cc;
        }
    }
    ctx->pc = 0x137198u;
    // 0x137198: 0x40f809  jalr        $v0
    ctx->pc = 0x137198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1371A0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1371A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1371A0u; }
            if (ctx->pc != 0x1371A0u) { return; }
        }
        }
    }
    ctx->pc = 0x1371A0u;
label_1371a0:
    // 0x1371a0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1371a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371a4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1371a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371a8: 0x8e420060  lw          $v0, 0x60($s2)
    ctx->pc = 0x1371a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 96)));
    // 0x1371ac: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1371acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371b0: 0x240500cb  addiu       $a1, $zero, 0xCB
    ctx->pc = 0x1371b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 203));
    // 0x1371b4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1371b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371b8: 0x40f809  jalr        $v0
    ctx->pc = 0x1371B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1371C0u);
        ctx->pc = 0x1371BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1371B8u;
            // 0x1371bc: 0x10803c  dsll32      $s0, $s0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1371C0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1371C0u; }
            if (ctx->pc != 0x1371C0u) { return; }
        }
        }
    }
    ctx->pc = 0x1371C0u;
label_1371c0:
    // 0x1371c0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1371c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1371c4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1371c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1371c8: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x1371c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_1371cc:
    // 0x1371cc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1371ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371d0: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x1371d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x1371d4: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x1371d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x1371d8: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x1371d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x1371dc: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x1371dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x1371e0: 0xdfbf0280  ld          $ra, 0x280($sp)
    ctx->pc = 0x1371e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x1371e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1371E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1371E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1371E4u;
            // 0x1371e8: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1371ECu;
    // 0x1371ec: 0x0  nop
    ctx->pc = 0x1371ecu;
    // NOP
    // 0x1371f0: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x1371f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x1371f4: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x1371f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x1371f8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1371f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1371fc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1371fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137200: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x137200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x137204: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x137204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x137208: 0xffb40280  sd          $s4, 0x280($sp)
    ctx->pc = 0x137208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 20));
    // 0x13720c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13720cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x137210: 0xffbf0288  sd          $ra, 0x288($sp)
    ctx->pc = 0x137210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 31));
    // 0x137214: 0xc04d558  jal         func_135560
    ctx->pc = 0x137214u;
    SET_GPR_U32(ctx, 31, 0x13721Cu);
    ctx->pc = 0x137218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137214u;
            // 0x137218: 0xa0a02d  daddu       $s4, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13721Cu; }
        if (ctx->pc != 0x13721Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13721Cu; }
        if (ctx->pc != 0x13721Cu) { return; }
    }
    ctx->pc = 0x13721Cu;
label_13721c:
    // 0x13721c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x13721cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137220: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x137220u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137224: 0x27b30130  addiu       $s3, $sp, 0x130
    ctx->pc = 0x137224u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x137228: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x137228u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13722c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x13722cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137230: 0x12200017  beqz        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x137230u;
    {
        const bool branch_taken_0x137230 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x137234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137230u;
            // 0x137234: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137230) {
            ctx->pc = 0x137290u;
            goto label_137290;
        }
    }
    ctx->pc = 0x137238u;
    // 0x137238: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x137238u;
    SET_GPR_U32(ctx, 31, 0x137240u);
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137240u; }
        if (ctx->pc != 0x137240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137240u; }
        if (ctx->pc != 0x137240u) { return; }
    }
    ctx->pc = 0x137240u;
label_137240:
    // 0x137240: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x137240u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137244: 0x8e230060  lw          $v1, 0x60($s1)
    ctx->pc = 0x137244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x137248: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x137248u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13724c: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x13724cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137250: 0x240500cc  addiu       $a1, $zero, 0xCC
    ctx->pc = 0x137250u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 204));
    // 0x137254: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x137254u;
    {
        const bool branch_taken_0x137254 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x137258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137254u;
            // 0x137258: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137254) {
            ctx->pc = 0x137290u;
            goto label_137290;
        }
    }
    ctx->pc = 0x13725Cu;
    // 0x13725c: 0x60f809  jalr        $v1
    ctx->pc = 0x13725Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x137264u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x137264u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x137264u; }
            if (ctx->pc != 0x137264u) { return; }
        }
        }
    }
    ctx->pc = 0x137264u;
label_137264:
    // 0x137264: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x137264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137268: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x137268u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13726c: 0x8e220060  lw          $v0, 0x60($s1)
    ctx->pc = 0x13726cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 96)));
    // 0x137270: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x137270u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137274: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x137274u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137278: 0x240500cd  addiu       $a1, $zero, 0xCD
    ctx->pc = 0x137278u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 205));
    // 0x13727c: 0x40f809  jalr        $v0
    ctx->pc = 0x13727Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x137284u);
        ctx->pc = 0x137280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13727Cu;
            // 0x137280: 0x10803c  dsll32      $s0, $s0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x137284u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x137284u; }
            if (ctx->pc != 0x137284u) { return; }
        }
        }
    }
    ctx->pc = 0x137284u;
label_137284:
    // 0x137284: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x137284u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x137288: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x137288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x13728c: 0x202102d  daddu       $v0, $s0, $v0
    ctx->pc = 0x13728cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_137290:
    // 0x137290: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x137290u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x137294: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x137294u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x137298: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x137298u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13729c: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x13729cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x1372a0: 0xdfb40280  ld          $s4, 0x280($sp)
    ctx->pc = 0x1372a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x1372a4: 0xdfbf0288  ld          $ra, 0x288($sp)
    ctx->pc = 0x1372a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x1372a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1372A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1372ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372A8u;
            // 0x1372ac: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1372B0u;
    // 0x1372b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1372b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1372b4: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1372b4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1372b8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1372B8u;
    {
        const bool branch_taken_0x1372b8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1372BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372B8u;
            // 0x1372bc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1372b8) {
            ctx->pc = 0x1372D8u;
            goto label_1372d8;
        }
    }
    ctx->pc = 0x1372C0u;
    // 0x1372c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1372c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1372c4: 0xc04d480  jal         func_135200
    ctx->pc = 0x1372C4u;
    SET_GPR_U32(ctx, 31, 0x1372CCu);
    ctx->pc = 0x1372C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1372C4u;
            // 0x1372c8: 0x2484c400  addiu       $a0, $a0, -0x3C00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1372CCu; }
        if (ctx->pc != 0x1372CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1372CCu; }
        if (ctx->pc != 0x1372CCu) { return; }
    }
    ctx->pc = 0x1372CCu;
label_1372cc:
    // 0x1372cc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1372CCu;
    {
        const bool branch_taken_0x1372cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1372D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372CCu;
            // 0x1372d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1372cc) {
            ctx->pc = 0x137300u;
            goto label_137300;
        }
    }
    ctx->pc = 0x1372D4u;
    // 0x1372d4: 0x0  nop
    ctx->pc = 0x1372d4u;
    // NOP
label_1372d8:
    // 0x1372d8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1372d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1372dc: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1372dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1372e0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1372E0u;
    {
        const bool branch_taken_0x1372e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1372E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372E0u;
            // 0x1372e4: 0x2405012b  addiu       $a1, $zero, 0x12B (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 299));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1372e0) {
            ctx->pc = 0x1372FCu;
            goto label_1372fc;
        }
    }
    ctx->pc = 0x1372E8u;
    // 0x1372e8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1372e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1372ec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1372ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1372f0: 0x40f809  jalr        $v0
    ctx->pc = 0x1372F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1372F8u);
        ctx->pc = 0x1372F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1372F0u;
            // 0x1372f4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1372F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1372F8u; }
            if (ctx->pc != 0x1372F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1372F8u;
label_1372f8:
    // 0x1372f8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1372f8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1372fc:
    // 0x1372fc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1372fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_137300:
    // 0x137300: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137300u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137304: 0x3e00008  jr          $ra
    ctx->pc = 0x137304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137304u;
            // 0x137308: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137010u: goto label_137010;
            case 0x137014u: goto label_137014;
            case 0x13701Cu: goto label_13701c;
            case 0x13703Cu: goto label_13703c;
            case 0x137068u: goto label_137068;
            case 0x137090u: goto label_137090;
            case 0x1370C8u: goto label_1370c8;
            case 0x1370D0u: goto label_1370d0;
            case 0x1370F0u: goto label_1370f0;
            case 0x137110u: goto label_137110;
            case 0x137120u: goto label_137120;
            case 0x137124u: goto label_137124;
            case 0x13716Cu: goto label_13716c;
            case 0x13717Cu: goto label_13717c;
            case 0x1371A0u: goto label_1371a0;
            case 0x1371C0u: goto label_1371c0;
            case 0x1371CCu: goto label_1371cc;
            case 0x13721Cu: goto label_13721c;
            case 0x137240u: goto label_137240;
            case 0x137264u: goto label_137264;
            case 0x137284u: goto label_137284;
            case 0x137290u: goto label_137290;
            case 0x1372CCu: goto label_1372cc;
            case 0x1372D8u: goto label_1372d8;
            case 0x1372F8u: goto label_1372f8;
            case 0x1372FCu: goto label_1372fc;
            case 0x137300u: goto label_137300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13730Cu;
    // 0x13730c: 0x0  nop
    ctx->pc = 0x13730cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
