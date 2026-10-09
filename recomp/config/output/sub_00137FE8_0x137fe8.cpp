#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137FE8
// Address: 0x137fe8 - 0x1380c8
void sub_00137FE8_0x137fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137FE8_0x137fe8");
#endif

    switch (ctx->pc) {
        case 0x137ffcu: goto label_137ffc;
        case 0x138004u: goto label_138004;
        case 0x138010u: goto label_138010;
        case 0x138050u: goto label_138050;
        case 0x138058u: goto label_138058;
        case 0x138068u: goto label_138068;
        case 0x138078u: goto label_138078;
        case 0x138088u: goto label_138088;
        case 0x13809cu: goto label_13809c;
        case 0x1380b0u: goto label_1380b0;
        default: break;
    }

    ctx->pc = 0x137fe8u;

    // 0x137fe8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137fe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137fec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137ff0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x137ff0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x137ff4: 0xc04e082  jal         func_138208
    ctx->pc = 0x137FF4u;
    SET_GPR_U32(ctx, 31, 0x137FFCu);
    ctx->pc = 0x137FF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137FF4u;
            // 0x137ff8: 0x24042300  addiu       $a0, $zero, 0x2300 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137FFCu; }
        if (ctx->pc != 0x137FFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137FFCu; }
        if (ctx->pc != 0x137FFCu) { return; }
    }
    ctx->pc = 0x137FFCu;
label_137ffc:
    // 0x137ffc: 0xc04035e  jal         func_100D78
    ctx->pc = 0x137FFCu;
    SET_GPR_U32(ctx, 31, 0x138004u);
    ctx->pc = 0x138000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137FFCu;
            // 0x138000: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138004u; }
        if (ctx->pc != 0x138004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138004u; }
        if (ctx->pc != 0x138004u) { return; }
    }
    ctx->pc = 0x138004u;
label_138004:
    // 0x138004: 0x24042301  addiu       $a0, $zero, 0x2301
    ctx->pc = 0x138004u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8961));
    // 0x138008: 0xc04e082  jal         func_138208
    ctx->pc = 0x138008u;
    SET_GPR_U32(ctx, 31, 0x138010u);
    ctx->pc = 0x13800Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138008u;
            // 0x13800c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138010u; }
        if (ctx->pc != 0x138010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138010u; }
        if (ctx->pc != 0x138010u) { return; }
    }
    ctx->pc = 0x138010u;
label_138010:
    // 0x138010: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x138010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138014: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x138014u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138018: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138018u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13801c: 0x3e00008  jr          $ra
    ctx->pc = 0x13801Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13801Cu;
            // 0x138020: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137FFCu: goto label_137ffc;
            case 0x138004u: goto label_138004;
            case 0x138010u: goto label_138010;
            case 0x138050u: goto label_138050;
            case 0x138058u: goto label_138058;
            case 0x138068u: goto label_138068;
            case 0x138078u: goto label_138078;
            case 0x138080u: goto label_138080;
            case 0x138088u: goto label_138088;
            case 0x13809Cu: goto label_13809c;
            case 0x1380A8u: goto label_1380a8;
            case 0x1380B0u: goto label_1380b0;
            case 0x1380B4u: goto label_1380b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138024u;
    // 0x138024: 0x0  nop
    ctx->pc = 0x138024u;
    // NOP
    // 0x138028: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x138028u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13802c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13802cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138030: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x138030u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x138034: 0x2450bb88  addiu       $s0, $v0, -0x4478
    ctx->pc = 0x138034u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949768));
    // 0x138038: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x138038u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x13803c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x13803cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x138040: 0x1464001b  bne         $v1, $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x138040u;
    {
        const bool branch_taken_0x138040 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x138044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138040u;
            // 0x138044: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138040) {
            ctx->pc = 0x1380B0u;
            goto label_1380b0;
        }
    }
    ctx->pc = 0x138048u;
    // 0x138048: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x138048u;
    SET_GPR_U32(ctx, 31, 0x138050u);
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138050u; }
        if (ctx->pc != 0x138050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138050u; }
        if (ctx->pc != 0x138050u) { return; }
    }
    ctx->pc = 0x138050u;
label_138050:
    // 0x138050: 0xc04e082  jal         func_138208
    ctx->pc = 0x138050u;
    SET_GPR_U32(ctx, 31, 0x138058u);
    ctx->pc = 0x138054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138050u;
            // 0x138054: 0x24042400  addiu       $a0, $zero, 0x2400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138058u; }
        if (ctx->pc != 0x138058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138058u; }
        if (ctx->pc != 0x138058u) { return; }
    }
    ctx->pc = 0x138058u;
label_138058:
    // 0x138058: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x138058u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13805c: 0x8e040030  lw          $a0, 0x30($s0)
    ctx->pc = 0x13805cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x138060: 0xc04e128  jal         func_1384A0
    ctx->pc = 0x138060u;
    SET_GPR_U32(ctx, 31, 0x138068u);
    ctx->pc = 0x138064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138060u;
            // 0x138064: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1384A0u;
    if (runtime->hasFunction(0x1384A0u)) {
        auto targetFn = runtime->lookupFunction(0x1384A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138068u; }
        if (ctx->pc != 0x138068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001384A0_0x1384a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138068u; }
        if (ctx->pc != 0x138068u) { return; }
    }
    ctx->pc = 0x138068u;
label_138068:
    // 0x138068: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x138068u;
    {
        const bool branch_taken_0x138068 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x13806Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138068u;
            // 0x13806c: 0x24042402  addiu       $a0, $zero, 0x2402 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9218));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138068) {
            ctx->pc = 0x138080u;
            goto label_138080;
        }
    }
    ctx->pc = 0x138070u;
    // 0x138070: 0xc04e082  jal         func_138208
    ctx->pc = 0x138070u;
    SET_GPR_U32(ctx, 31, 0x138078u);
    ctx->pc = 0x138074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138070u;
            // 0x138074: 0x24042401  addiu       $a0, $zero, 0x2401 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9217));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138078u; }
        if (ctx->pc != 0x138078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138078u; }
        if (ctx->pc != 0x138078u) { return; }
    }
    ctx->pc = 0x138078u;
label_138078:
    // 0x138078: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x138078u;
    {
        const bool branch_taken_0x138078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x138078) {
            ctx->pc = 0x1380A8u;
            goto label_1380a8;
        }
    }
    ctx->pc = 0x138080u;
label_138080:
    // 0x138080: 0xc04e082  jal         func_138208
    ctx->pc = 0x138080u;
    SET_GPR_U32(ctx, 31, 0x138088u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138088u; }
        if (ctx->pc != 0x138088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138088u; }
        if (ctx->pc != 0x138088u) { return; }
    }
    ctx->pc = 0x138088u;
label_138088:
    // 0x138088: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x138088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13808c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13808Cu;
    {
        const bool branch_taken_0x13808c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13808c) {
            ctx->pc = 0x1380A8u;
            goto label_1380a8;
        }
    }
    ctx->pc = 0x138094u;
    // 0x138094: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x138094u;
    SET_GPR_U32(ctx, 31, 0x13809Cu);
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13809Cu; }
        if (ctx->pc != 0x13809Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13809Cu; }
        if (ctx->pc != 0x13809Cu) { return; }
    }
    ctx->pc = 0x13809Cu;
label_13809c:
    // 0x13809c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x13809Cu;
    {
        const bool branch_taken_0x13809c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1380A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13809Cu;
            // 0x1380a0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13809c) {
            ctx->pc = 0x1380B4u;
            goto label_1380b4;
        }
    }
    ctx->pc = 0x1380A4u;
    // 0x1380a4: 0x0  nop
    ctx->pc = 0x1380a4u;
    // NOP
label_1380a8:
    // 0x1380a8: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x1380A8u;
    SET_GPR_U32(ctx, 31, 0x1380B0u);
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1380B0u; }
        if (ctx->pc != 0x1380B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1380B0u; }
        if (ctx->pc != 0x1380B0u) { return; }
    }
    ctx->pc = 0x1380B0u;
label_1380b0:
    // 0x1380b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1380b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1380b4:
    // 0x1380b4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1380b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1380b8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1380b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1380bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1380BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1380C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1380BCu;
            // 0x1380c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137FFCu: goto label_137ffc;
            case 0x138004u: goto label_138004;
            case 0x138010u: goto label_138010;
            case 0x138050u: goto label_138050;
            case 0x138058u: goto label_138058;
            case 0x138068u: goto label_138068;
            case 0x138078u: goto label_138078;
            case 0x138080u: goto label_138080;
            case 0x138088u: goto label_138088;
            case 0x13809Cu: goto label_13809c;
            case 0x1380A8u: goto label_1380a8;
            case 0x1380B0u: goto label_1380b0;
            case 0x1380B4u: goto label_1380b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1380C4u;
    // 0x1380c4: 0x0  nop
    ctx->pc = 0x1380c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
